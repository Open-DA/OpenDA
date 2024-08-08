//
//  AVX.cpp
//
//  Created by 彭程 on 2022/4/24

#include <mmintrin.h>   //mmx, 4个64位寄存器
#include <xmmintrin.h>  //sse, 8个128位寄存器
#include <emmintrin.h>  //sse2, 8个128位寄存器
#include <pmmintrin.h>  //sse3, 8个128位寄存器
#include <smmintrin.h>  //sse4.1, 8个128位寄存器
#include <nmmintrin.h>  //sse4.2, 8个128位寄存器
#include <immintrin.h>  // avx, 16个256位寄存器
#include<iostream>
#include<time.h>
#include <cstdlib>
using namespace std;

#define VecLen 1000000

struct Face{
    unsigned long long Lines[3];
};

struct Line{
    unsigned long long Vectors[2];
};

struct Vector{
    float V[4];
};//m_v[150000];

//最普通的矩阵乘法，逐位相乘再加起来
void VectorTrans_normal(Vector VecSet [], float TransMatirx[4][4], unsigned int SetLen){
  for(unsigned int i =0; i < SetLen;i++){
    int v[4];
    for(int j=0;j<4;j++){
      v[j]=VecSet[i].V[0]*TransMatirx[0][j]+VecSet[i].V[1]*TransMatirx[1][j]+VecSet[i].V[2]*TransMatirx[2][j]+VecSet[i].V[3]*TransMatirx[3][j];
    }
    for(int j=0;j<4;j++){
      VecSet[i].V[j]=v[j];
    }
  }
  return;
}

//pro1版本，只利用AVX将四个浮点数一起相乘
void VectorTrans_pro1(Vector VecSet [], float TransMatirx[4][4], unsigned int SetLen){
    for(unsigned int i=0;i<SetLen;i++){
      __m128 a,c[4];
      a = _mm_set_ps(VecSet[i].V[0], VecSet[i].V[1], VecSet[i].V[2], VecSet[i].V[3]);
      for(int j=0;j<4;j++){
        __m128  b;
        b =  _mm_set_ps(TransMatirx[0][j], TransMatirx[1][j], TransMatirx[2][j], TransMatirx[3][j]);
        c[j] = _mm_mul_ps(a, b);
      }
      for(int j=0;j<4;j++){
        VecSet[i].V[j]=c[j][0]+c[j][1]+c[j][2]+c[j][3];
      }
    }
    return;
}

//pro2版本，利用AVX将四个浮点数一起相乘,同时4个并行
void VectorTrans_pro2(Vector VecSet [], float TransMatirx[4][4], unsigned int SetLen){
    for(unsigned int i=0;i<SetLen;i++){
      __m128 a,b[4],c[4];
      a = _mm_set_ps(VecSet[i].V[0], VecSet[i].V[1], VecSet[i].V[2], VecSet[i].V[3]);

      b[0]=_mm_set_ps(TransMatirx[0][0], TransMatirx[1][0], TransMatirx[2][0], TransMatirx[3][0]);
      b[1]=_mm_set_ps(TransMatirx[0][1], TransMatirx[1][1], TransMatirx[2][1], TransMatirx[3][1]);
      b[2]=_mm_set_ps(TransMatirx[0][2], TransMatirx[1][2], TransMatirx[2][2], TransMatirx[3][2]);
      b[3]=_mm_set_ps(TransMatirx[0][3], TransMatirx[1][3], TransMatirx[2][3], TransMatirx[3][3]);

      c[0] = _mm_mul_ps(a, b[0]);
      c[1] = _mm_mul_ps(a, b[1]);
      c[2] = _mm_mul_ps(a, b[2]);
      c[3] = _mm_mul_ps(a, b[3]);

      VecSet[i].V[0]=c[0][0]+c[0][1]+c[0][2]+c[0][3];
      VecSet[i].V[1]=c[1][0]+c[1][1]+c[1][2]+c[1][3];
      VecSet[i].V[2]=c[2][0]+c[2][1]+c[2][2]+c[2][3];
      VecSet[i].V[3]=c[3][0]+c[3][1]+c[3][2]+c[3][3];
      
    }
    return;
}

//pro3版本，利用AVX将四个浮点数一起相乘,同时将四组浮点数一起相加减少加法运算,同时4个并行
void VectorTrans_pro3(Vector VecSet [], float TransMatirx[4][4], unsigned int SetLen){
    for(unsigned int i=0;i<SetLen;i++){
      __m128 a[4],b[4],c[4];

      //先把vector的每一个值拓展成1×4的向量
      a[0] = _mm_set_ps(VecSet[i].V[0], VecSet[i].V[0], VecSet[i].V[0], VecSet[i].V[0]);
      a[1] = _mm_set_ps(VecSet[i].V[1], VecSet[i].V[1], VecSet[i].V[1], VecSet[i].V[1]);
      a[2] = _mm_set_ps(VecSet[i].V[2], VecSet[i].V[2], VecSet[i].V[2], VecSet[i].V[2]);
      a[3] = _mm_set_ps(VecSet[i].V[3], VecSet[i].V[3], VecSet[i].V[3], VecSet[i].V[3]);

      //把矩阵的每一排提取出来
      b[0]=_mm_load_ps(TransMatirx[0]);
      b[1]=_mm_load_ps(TransMatirx[1]);
      b[2]=_mm_load_ps(TransMatirx[2]);
      b[3]=_mm_load_ps(TransMatirx[3]);

      //把拓展向量和矩阵的每一排相乘
      b[0] = _mm_mul_ps(a[0], b[0]);
      b[1] = _mm_mul_ps(a[1], b[1]);
      b[2] = _mm_mul_ps(a[2], b[2]);
      b[3] = _mm_mul_ps(a[3], b[3]);

      //把上面四组数加起来放在b[0]
      b[0] = _mm_add_ps(b[0], b[1]);
      b[2] = _mm_mul_ps(b[2], b[3]);
      b[0] = _mm_add_ps(b[0], b[2]);

      //得出结果
      VecSet[i].V[0]=b[0][0];
      VecSet[i].V[1]=b[0][1];
      VecSet[i].V[2]=b[0][2];
      VecSet[i].V[3]=b[0][3];
    }
    return;
}

//pro4版本，利用AVX将四个浮点数一起相乘，并且同时算四个vector的结果
void VectorTrans_pro4(Vector VecSet [], float TransMatirx[4][4], unsigned int SetLen){
  unsigned int i;
    for(i=0;i<SetLen-4;i+=4){
      __m128 a[4],b[4],c[4][4];
      a[0] = _mm_load_ps(VecSet[i].V);
      a[1] = _mm_load_ps(VecSet[i+1].V);
      a[2] = _mm_load_ps(VecSet[i+2].V);
      a[3] = _mm_load_ps(VecSet[i+3].V);

      b[0] = _mm_set_ps(TransMatirx[0][0], TransMatirx[1][0], TransMatirx[2][0], TransMatirx[3][0]);
      b[1] = _mm_set_ps(TransMatirx[0][1], TransMatirx[1][1], TransMatirx[2][1], TransMatirx[3][1]);
      b[2] = _mm_set_ps(TransMatirx[0][2], TransMatirx[1][2], TransMatirx[2][2], TransMatirx[3][2]);
      b[3] = _mm_set_ps(TransMatirx[0][3], TransMatirx[1][3], TransMatirx[2][3], TransMatirx[3][3]);

      c[0][0] = _mm_mul_ps(a[0], b[0]);
      c[0][1] = _mm_mul_ps(a[0], b[1]);
      c[0][2] = _mm_mul_ps(a[0], b[2]);
      c[0][3] = _mm_mul_ps(a[0], b[3]);

      c[1][0] = _mm_mul_ps(a[1], b[0]);
      c[1][1] = _mm_mul_ps(a[1], b[1]);
      c[1][2] = _mm_mul_ps(a[1], b[2]);
      c[1][3] = _mm_mul_ps(a[1], b[3]);

      c[2][0] = _mm_mul_ps(a[2], b[0]);
      c[2][1] = _mm_mul_ps(a[2], b[1]);
      c[2][2] = _mm_mul_ps(a[2], b[2]);
      c[2][3] = _mm_mul_ps(a[2], b[3]);

      c[3][0] = _mm_mul_ps(a[3], b[0]);
      c[3][1] = _mm_mul_ps(a[3], b[1]);
      c[3][2] = _mm_mul_ps(a[3], b[2]);
      c[3][3] = _mm_mul_ps(a[3], b[3]);

      VecSet[i].V[0]=c[0][0][0]+c[0][0][1]+c[0][0][2]+c[0][0][3];
      VecSet[i].V[1]=c[0][1][0]+c[0][1][1]+c[0][1][2]+c[0][1][3];
      VecSet[i].V[2]=c[0][2][0]+c[0][2][1]+c[0][2][2]+c[0][2][3];
      VecSet[i].V[3]=c[0][3][0]+c[0][3][1]+c[0][3][2]+c[0][3][3];

      VecSet[i+1].V[0]=c[1][0][0]+c[1][0][1]+c[1][0][2]+c[1][0][3];
      VecSet[i+1].V[1]=c[1][1][0]+c[1][1][1]+c[1][1][2]+c[1][1][3];
      VecSet[i+1].V[2]=c[1][2][0]+c[1][2][1]+c[1][2][2]+c[1][2][3];
      VecSet[i+1].V[3]=c[1][3][0]+c[1][3][1]+c[1][3][2]+c[1][3][3];

      VecSet[i+2].V[0]=c[2][0][0]+c[2][0][1]+c[2][0][2]+c[3][0][3];
      VecSet[i+2].V[1]=c[2][1][0]+c[2][1][1]+c[2][1][2]+c[3][1][3];
      VecSet[i+2].V[2]=c[2][2][0]+c[2][2][1]+c[2][2][2]+c[3][2][3];
      VecSet[i+2].V[3]=c[2][3][0]+c[2][3][1]+c[2][3][2]+c[3][3][3];

      VecSet[i+3].V[0]=c[3][0][0]+c[3][0][1]+c[3][0][2]+c[3][0][3];
      VecSet[i+3].V[1]=c[3][1][0]+c[3][1][1]+c[3][1][2]+c[3][1][3];
      VecSet[i+3].V[2]=c[3][2][0]+c[3][2][1]+c[3][2][2]+c[3][2][3];
      VecSet[i+3].V[3]=c[3][3][0]+c[3][3][1]+c[3][3][2]+c[3][3][3];
      
    }
    for(;i<SetLen;i++){
       __m128 a,b[4],c[4];
      a = _mm_set_ps(VecSet[i].V[0], VecSet[i].V[1], VecSet[i].V[2], VecSet[i].V[3]);

      b[0]=_mm_set_ps(TransMatirx[0][0], TransMatirx[1][0], TransMatirx[2][0], TransMatirx[3][0]);
      b[1]=_mm_set_ps(TransMatirx[0][1], TransMatirx[1][1], TransMatirx[2][1], TransMatirx[3][1]);
      b[2]=_mm_set_ps(TransMatirx[0][2], TransMatirx[1][2], TransMatirx[2][2], TransMatirx[3][2]);
      b[3]=_mm_set_ps(TransMatirx[0][3], TransMatirx[1][3], TransMatirx[2][3], TransMatirx[3][3]);

      c[0] = _mm_mul_ps(a, b[0]);
      c[1] = _mm_mul_ps(a, b[1]);
      c[2] = _mm_mul_ps(a, b[2]);
      c[3] = _mm_mul_ps(a, b[3]);

      VecSet[i].V[0]=c[0][0]+c[0][1]+c[0][2]+c[0][3];
      VecSet[i].V[1]=c[1][0]+c[1][1]+c[1][2]+c[1][3];
      VecSet[i].V[2]=c[2][0]+c[2][1]+c[2][2]+c[2][3];
      VecSet[i].V[3]=c[3][0]+c[3][1]+c[3][2]+c[3][3];
      
    }
    return;
}

//pro5版本，尝试20×20展开
void VectorTrans_pro5(Vector VecSet [], float TransMatirx[4][4], unsigned int SetLen){
  unsigned int i;
    for(i=0;i<SetLen-5;i+=5){
      __m128 a[5],b[4],c[5][4];
      a[0] = _mm_load_ps(VecSet[i].V);
      a[1] = _mm_load_ps(VecSet[i+1].V);
      a[2] = _mm_load_ps(VecSet[i+2].V);
      a[3] = _mm_load_ps(VecSet[i+3].V);
      a[4] = _mm_load_ps(VecSet[i+4].V);

      b[0] = _mm_set_ps(TransMatirx[0][0], TransMatirx[1][0], TransMatirx[2][0], TransMatirx[3][0]);
      b[1] = _mm_set_ps(TransMatirx[0][1], TransMatirx[1][1], TransMatirx[2][1], TransMatirx[3][1]);
      b[2] = _mm_set_ps(TransMatirx[0][2], TransMatirx[1][2], TransMatirx[2][2], TransMatirx[3][2]);
      b[3] = _mm_set_ps(TransMatirx[0][3], TransMatirx[1][3], TransMatirx[2][3], TransMatirx[3][3]);

      c[0][0] = _mm_mul_ps(a[0], b[0]);
      c[0][1] = _mm_mul_ps(a[0], b[1]);
      c[0][2] = _mm_mul_ps(a[0], b[2]);
      c[0][3] = _mm_mul_ps(a[0], b[3]);

      c[1][0] = _mm_mul_ps(a[1], b[0]);
      c[1][1] = _mm_mul_ps(a[1], b[1]);
      c[1][2] = _mm_mul_ps(a[1], b[2]);
      c[1][3] = _mm_mul_ps(a[1], b[3]);

      c[2][0] = _mm_mul_ps(a[2], b[0]);
      c[2][1] = _mm_mul_ps(a[2], b[1]);
      c[2][2] = _mm_mul_ps(a[2], b[2]);
      c[2][3] = _mm_mul_ps(a[2], b[3]);

      c[3][0] = _mm_mul_ps(a[3], b[0]);
      c[3][1] = _mm_mul_ps(a[3], b[1]);
      c[3][2] = _mm_mul_ps(a[3], b[2]);
      c[3][3] = _mm_mul_ps(a[3], b[3]);

      c[4][0] = _mm_mul_ps(a[4], b[0]);
      c[4][1] = _mm_mul_ps(a[4], b[1]);
      c[4][2] = _mm_mul_ps(a[4], b[2]);
      c[4][3] = _mm_mul_ps(a[4], b[3]);

      VecSet[i].V[0]=c[0][0][0]+c[0][0][1]+c[0][0][2]+c[0][0][3];
      VecSet[i].V[1]=c[0][1][0]+c[0][1][1]+c[0][1][2]+c[0][1][3];
      VecSet[i].V[2]=c[0][2][0]+c[0][2][1]+c[0][2][2]+c[0][2][3];
      VecSet[i].V[3]=c[0][3][0]+c[0][3][1]+c[0][3][2]+c[0][3][3];

      VecSet[i+1].V[0]=c[1][0][0]+c[1][0][1]+c[1][0][2]+c[1][0][3];
      VecSet[i+1].V[1]=c[1][1][0]+c[1][1][1]+c[1][1][2]+c[1][1][3];
      VecSet[i+1].V[2]=c[1][2][0]+c[1][2][1]+c[1][2][2]+c[1][2][3];
      VecSet[i+1].V[3]=c[1][3][0]+c[1][3][1]+c[1][3][2]+c[1][3][3];

      VecSet[i+2].V[0]=c[2][0][0]+c[2][0][1]+c[2][0][2]+c[3][0][3];
      VecSet[i+2].V[1]=c[2][1][0]+c[2][1][1]+c[2][1][2]+c[3][1][3];
      VecSet[i+2].V[2]=c[2][2][0]+c[2][2][1]+c[2][2][2]+c[3][2][3];
      VecSet[i+2].V[3]=c[2][3][0]+c[2][3][1]+c[2][3][2]+c[3][3][3];

      VecSet[i+3].V[0]=c[3][0][0]+c[3][0][1]+c[3][0][2]+c[3][0][3];
      VecSet[i+3].V[1]=c[3][1][0]+c[3][1][1]+c[3][1][2]+c[3][1][3];
      VecSet[i+3].V[2]=c[3][2][0]+c[3][2][1]+c[3][2][2]+c[3][2][3];
      VecSet[i+3].V[3]=c[3][3][0]+c[3][3][1]+c[3][3][2]+c[3][3][3];

      VecSet[i+4].V[0]=c[4][0][0]+c[4][0][1]+c[4][0][2]+c[4][0][3];
      VecSet[i+4].V[1]=c[4][1][0]+c[4][1][1]+c[4][1][2]+c[4][1][3];
      VecSet[i+4].V[2]=c[4][2][0]+c[4][2][1]+c[4][2][2]+c[4][2][3];
      VecSet[i+4].V[3]=c[4][3][0]+c[4][3][1]+c[4][3][2]+c[4][3][3];
      
    }
    for(;i<SetLen;i++){
       __m128 a,b[4],c[4];
      a = _mm_set_ps(VecSet[i].V[0], VecSet[i].V[1], VecSet[i].V[2], VecSet[i].V[3]);

      b[0]=_mm_set_ps(TransMatirx[0][0], TransMatirx[1][0], TransMatirx[2][0], TransMatirx[3][0]);
      b[1]=_mm_set_ps(TransMatirx[0][1], TransMatirx[1][1], TransMatirx[2][1], TransMatirx[3][1]);
      b[2]=_mm_set_ps(TransMatirx[0][2], TransMatirx[1][2], TransMatirx[2][2], TransMatirx[3][2]);
      b[3]=_mm_set_ps(TransMatirx[0][3], TransMatirx[1][3], TransMatirx[2][3], TransMatirx[3][3]);

      c[0] = _mm_mul_ps(a, b[0]);
      c[1] = _mm_mul_ps(a, b[1]);
      c[2] = _mm_mul_ps(a, b[2]);
      c[3] = _mm_mul_ps(a, b[3]);

      VecSet[i].V[0]=c[0][0]+c[0][1]+c[0][2]+c[0][3];
      VecSet[i].V[1]=c[1][0]+c[1][1]+c[1][2]+c[1][3];
      VecSet[i].V[2]=c[2][0]+c[2][1]+c[2][2]+c[2][3];
      VecSet[i].V[3]=c[3][0]+c[3][1]+c[3][2]+c[3][3];      
    }
    return;
}


Vector m_v[VecLen];

int main() {
  for(int i=0;i<VecLen;i++){
    m_v[i].V[0]=rand()%1000000;
    m_v[i].V[1]=rand()%1000000;
    m_v[i].V[2]=rand()%1000000;
    m_v[i].V[3]=rand()%1000000;
  }//随意的设定了一组vector

  float TransMatirx[4][4];
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      TransMatirx[i][j]=rand()%10000;
    }
  }//随意设定了一个4×4矩阵

  clock_t startTime,endTime;

  //normal版本测试
  startTime=clock();
  for(int i=0;i<100;i++){
    VectorTrans_normal(m_v,TransMatirx,VecLen);
  }
  endTime=clock();
  cout<<"Total Time-normal:"<<(double)(endTime-startTime)/CLOCKS_PER_SEC<<"s"<<endl;

  //Pro1版本测试
  startTime=clock();
    for(int i=0;i<100;i++){
    VectorTrans_pro1(m_v,TransMatirx,VecLen);
  }
  endTime=clock();
  cout<<"Total Time-pro1:"<<(double)(endTime-startTime)/CLOCKS_PER_SEC<<"s"<<endl;

  //Pro2版本测试
  startTime=clock();
  for(int i=0;i<100;i++){
    VectorTrans_pro2(m_v,TransMatirx,VecLen);
  }
  endTime=clock();
  cout<<"Total Time-pro2:"<<(double)(endTime-startTime)/CLOCKS_PER_SEC<<"s"<<endl;

  //Pro3版本测试
  startTime=clock();
  for(int i=0;i<100;i++){
    VectorTrans_pro3(m_v,TransMatirx,VecLen);
  }
  endTime=clock();
  cout<<"Total Time-pro3:"<<(double)(endTime-startTime)/CLOCKS_PER_SEC<<"s"<<endl;

  //Pro4版本测试
  startTime=clock();
  for(int i=0;i<100;i++){
    VectorTrans_pro4(m_v,TransMatirx,VecLen);
  }
  endTime=clock();
  cout<<"Total Time-pro4:"<<(double)(endTime-startTime)/CLOCKS_PER_SEC<<"s"<<endl;

  //Pro5版本测试
  startTime=clock();
  for(int i=0;i<100;i++){
    VectorTrans_pro5(m_v,TransMatirx,VecLen);
  }
  endTime=clock();
  cout<<"Total Time-pro5:"<<(double)(endTime-startTime)/CLOCKS_PER_SEC<<"s"<<endl;

  return 0;
  
  /*
  实验结果（不优化）：
  Total Time-normal:2.857s
  Total Time-pro1:2.865s
  Total Time-pro2:1.846s
  Total Time-pro3:2.626s
  Total Time-pro4:0.885s
  Total Time-pro5:0.854s

  如果开了优化：
  实验结果（-O3）：
  Total Time-normal:0.143s
  Total Time-pro1:0.339s
  Total Time-pro2:0.608s
  Total Time-pro3:0.347s
  Total Time-pro4:0.296s
  Total Time-pro5:0.279s

  说明目前阶段优化水平远高于我:(
  */

}
