

![](_assets/image-20231212180543496.jpeg)


# 基础知识


## 非线性规划问题的一般形式


![](_assets/OR%20Slides-9%202023_page-0004.jpg)

### 局部最优与全局最优

![](_assets/OR%20Slides-9%202023_page-0005.jpg)

![](_assets/OR%20Slides-9%202023_page-0006.jpg)

![](_assets/image-20231212180656115.jpeg)



![](_assets/OR%20Slides-9%202023_page-0007.jpg)

![](_assets/OR%20Slides-9%202023_page-0008.jpg)

## 为什么研究凸优化问题

![](_assets/OR%20Slides-9%202023_page-0009.jpg)



## 函数的凹凸性


### Recap: 矩阵求导

>之后链接到矩阵求导的笔记部分

![](_assets/OR%20Slides-9%202023_page-0010.jpg)

![](_assets/OR%20Slides-9%202023_page-0011.jpg)


![](_assets/OR%20Slides-9%202023_page-0013.jpg)

![](_assets/OR%20Slides-9%202023_page-0014.jpg)

![](_assets/OR%20Slides-9%202023_page-0015.jpg)

![](_assets/OR%20Slides-9%202023_page-0016.jpg)

![](_assets/image-20231212181155016.jpeg)

![](_assets/image-20231212181200415.jpeg)

![](_assets/image-20231212181211144.jpeg)


### 多元凸函数

![](_assets/image-20231212181238198.jpeg)

![](_assets/image-20231212181250069.jpeg)

----

![](_assets/image-20231212181405673.jpeg)

---

**多元凸函数的判别**

![](_assets/image-20231212181507627.jpeg)

![](_assets/image-20231212181510402.jpeg)

### 可导凸函数的充要条件

![](_assets/image-20231212182040870.jpeg)

![](_assets/image-20231212182050012.jpeg)

![](_assets/image-20231212182055091.jpeg)

![](_assets/image-20231212182252301.jpeg)

![](_assets/image-20231212182256319.jpeg)

![](_assets/image-20231212182300794.jpeg)

![](_assets/image-20231212182304000.jpeg)



---

根据凸函数的定义来判断一个函数是否为凸函数往往比较困难，**这里分别通过一阶条件和二阶条件判断凸函数。**

![](_assets/image-20231203195328188.png)

![](_assets/image-20231203200724965.png)

![](_assets/image-20231203200815678.png)





### 凸性对优化问题的基本作用: 局部最优也是全局最优

![](_assets/image-20231212182345520.jpeg)

![](_assets/image-20231212182412971.jpeg)


### 典型凸函数与非凸函数

![](_assets/OR%20Slides-9%202023_page-0031.jpg)

![](_assets/OR%20Slides-9%202023_page-0032.jpg)

![](_assets/OR%20Slides-9%202023_page-0033.jpg)

![](_assets/OR%20Slides-9%202023_page-0034.jpg)





# 一维搜索


## 可行下降迭代方法



![](_assets/image-20231212182603547.jpeg)

![](_assets/image-20231212182622429.jpeg)

![](_assets/image-20231212182703310.jpeg)

>可行域 $\Omega$ 是黑色实线扩起来的那些, 在上半部分.

![](_assets/image-20231212182816591.jpeg)

![](_assets/image-20231212182855986.jpeg)


## 一维精确搜索


![](_assets/image-20231212183205428.jpeg)

![](_assets/image-20231212183312271.jpeg)

![](_assets/image-20231212183315081.jpeg)


### 精确搜索的基本途径

![](_assets/image-20231212183426828.jpeg)

![](_assets/image-20231212183431462.jpeg)


### 0.618 法


![](_assets/image-20231212183719269.jpeg)

![](_assets/image-20231212183722784.jpeg)

>这里绿色的并不是在减小区间, 而是让这一次计算取的点可以在下一次计算中被用到.

![](_assets/image-20231212183727077.jpeg)

![](_assets/image-20231212183729818.jpeg)

![](_assets/image-20231212183733036.jpeg)

----

>[36 一维搜索与求根 | 统计计算](https://www.math.pku.edu.cn/teachers/lidf/docs/statcomp/html/_statcompbook/opt-1d.html)

![](_assets/image-20240114105220984.png)

![](_assets/image-20240114105315274.png)


### Fibonacci 法


![](_assets/image-20231212183743440.jpeg)

![](_assets/image-20231212183745737.jpeg)

![](_assets/image-20231212183748637.jpeg)

![](_assets/image-20231212183752161.jpeg)

![](_assets/image-20231212183755424.jpeg)

![](_assets/image-20231212183759698.jpeg)

![](_assets/image-20231212183802831.jpeg)


### 利用导数的精确搜索法

![](_assets/image-20231212183815115.jpeg)

![](_assets/image-20231212183817539.jpeg)

## 非精确搜索

![](_assets/image-20231212184155297.jpeg)

![](_assets/image-20231212184158121.jpeg)

![](_assets/image-20231212184200714.jpeg)




# 无约束优化


## 无约束优化的最优性条件


![](_assets/6%20非线性规划2_page-0003.jpg)

![](_assets/6%20非线性规划2_page-0004.jpg)

![](_assets/6%20非线性规划2_page-0005.jpg)

## 下降方向法

![](_assets/6%20非线性规划2_page-0007.jpg)

![](_assets/6%20非线性规划2_page-0008.jpg)

![](_assets/6%20非线性规划2_page-0009.jpg)

## 梯度下降法

![](_assets/6%20非线性规划2_page-0011.jpg)

![](_assets/6%20非线性规划2_page-0012.jpg)

![](_assets/6%20非线性规划2_page-0013.jpg)

![](_assets/6%20非线性规划2_page-0014.jpg)

### 负梯度方向的缺陷

![](_assets/6%20非线性规划2_page-0016.jpg)

![](_assets/6%20非线性规划2_page-0017.jpg)

![](_assets/6%20非线性规划2_page-0018.jpg)

### 改进梯度下降法的思路

![](_assets/6%20非线性规划2_page-0019.jpg)

![](_assets/6%20非线性规划2_page-0020.jpg)

### 利用梯度方向生成其它下降方向

![](_assets/6%20非线性规划2_page-0022.jpg)

![](_assets/6%20非线性规划2_page-0023.jpg)

![](_assets/6%20非线性规划2_page-0024.jpg)

## 牛顿方向 (广义牛顿法)

![](_assets/6%20非线性规划2_page-0026.jpg)

![](_assets/6%20非线性规划2_page-0027.jpg)

![](_assets/6%20非线性规划2_page-0028.jpg)

![](_assets/6%20非线性规划2_page-0029.jpg)

### 牛顿方向的缺陷

![](_assets/6%20非线性规划2_page-0031.jpg)

![](_assets/6%20非线性规划2_page-0032.jpg)

![](_assets/6%20非线性规划2_page-0033.jpg)

## 最速下降方向

![](_assets/6%20非线性规划2_page-0035.jpg)

![](_assets/6%20非线性规划2_page-0036.jpg)

![](_assets/6%20非线性规划2_page-0037.jpg)

![](_assets/6%20非线性规划2_page-0038.jpg)

![](_assets/6%20非线性规划2_page-0039.jpg)

## 共轭梯度方向

![](_assets/6%20非线性规划2_page-0041.jpg)

![](_assets/6%20非线性规划2_page-0042.jpg)

![](_assets/6%20非线性规划2_page-0043.jpg)

![](_assets/6%20非线性规划2_page-0044.jpg)

>这里相当于是已经知道最优解的位置, 然后求导凑出来的.

![](_assets/6%20非线性规划2_page-0045.jpg)

> $\alpha_0 \vec{p}_k^T A \vec{p}_0+\alpha_1 \vec{p}_k^T A \vec{p}_1+\cdots+\alpha_{n-1} \vec{p}_k^T A \vec{p}_{n-1}$ 中, 除了 $\alpha_k \vec{p}_k^T A \vec{p}_k$ 这一项, 其他都由于共轭方向的性质是 0.

![](_assets/6%20非线性规划2_page-0046.jpg)

![](_assets/6%20非线性规划2_page-0047.jpg)

### F-R 共轭梯度法

![](_assets/6%20非线性规划2_page-0049.jpg)

![](_assets/6%20非线性规划2_page-0050.jpg)

#### 参数 $\alpha$ 的计算

![](_assets/6%20非线性规划2_page-0052.jpg)

![](_assets/6%20非线性规划2_page-0053.jpg)

#### 示例

![](_assets/6%20非线性规划2_page-0055.jpg)

![](_assets/6%20非线性规划2_page-0056.jpg)

### 共轭方向与一维最优解的梯度的正交性


![](_assets/6%20非线性规划2_page-0058.jpg)

![](_assets/6%20非线性规划2_page-0059.jpg)

![](_assets/6%20非线性规划2_page-0060.jpg)

### 共轭方向二次函数有限终止性

![](_assets/6%20非线性规划2_page-0062.jpg)

![](_assets/6%20非线性规划2_page-0063.jpg)

![](_assets/6%20非线性规划2_page-0064.jpg)

### 共轭方向的生成

![](_assets/6%20非线性规划2_page-0066.jpg)

![](_assets/6%20非线性规划2_page-0067.jpg)

![](_assets/6%20非线性规划2_page-0068.jpg)

![](_assets/6%20非线性规划2_page-0069.jpg)

![](_assets/6%20非线性规划2_page-0070.jpg)

![](_assets/6%20非线性规划2_page-0071.jpg)

### 三种共轭梯度法

![](_assets/6%20非线性规划2_page-0073.jpg)

![](_assets/6%20非线性规划2_page-0074.jpg)

![](_assets/6%20非线性规划2_page-0075.jpg)

![](_assets/6%20非线性规划2_page-0076.jpg)

![](_assets/6%20非线性规划2_page-0077.jpg)

![](_assets/6%20非线性规划2_page-0078.jpg)



# 约束优化


## 约束优化问题最优性条件

![](_assets/7%20非线性规划3_page-0003.jpg)

![](_assets/7%20非线性规划3_page-0004.jpg)

![](_assets/7%20非线性规划3_page-0005.jpg)

## 包含不等式约束的最优解的 K-T 条件

![](_assets/7%20非线性规划3_page-0006.jpg)

### 不等式约束的分类

![](_assets/7%20非线性规划3_page-0008.jpg)

![](_assets/7%20非线性规划3_page-0009.jpg)

![](_assets/7%20非线性规划3_page-0010.jpg)

### 线性不等式约束下的 KT 条件

![](_assets/7%20非线性规划3_page-0012.jpg)

>看上边的 PPT, 构造可行方向时不考虑不起作用约束, 只考虑可行约束.

![](_assets/7%20非线性规划3_page-0013.jpg)

![](_assets/7%20非线性规划3_page-0014.jpg)

>这里和无约束优化那里思路类似, 在求解线性不等式约束下的可行下降方向.

![](_assets/7%20非线性规划3_page-0015.jpg)

![](_assets/7%20非线性规划3_page-0016.jpg)

![](_assets/7%20非线性规划3_page-0017.jpg)

![](_assets/7%20非线性规划3_page-0018.jpg)

### 线性等式约束处理方式

![](_assets/7%20非线性规划3_page-0020.jpg)

![](_assets/7%20非线性规划3_page-0021.jpg)

### 不等式约束优化问题局部最优解的必要条件

![](_assets/7%20非线性规划3_page-0022.jpg)

![](_assets/7%20非线性规划3_page-0023.jpg)

![](_assets/7%20非线性规划3_page-0024.jpg)

![](_assets/7%20非线性规划3_page-0025.jpg)

![](_assets/7%20非线性规划3_page-0026.jpg)

![](_assets/7%20非线性规划3_page-0027.jpg)

![](_assets/7%20非线性规划3_page-0028.jpg)

![](_assets/7%20非线性规划3_page-0029.jpg)

![](_assets/7%20非线性规划3_page-0030.jpg)

![](_assets/7%20非线性规划3_page-0031.jpg)

![](_assets/7%20非线性规划3_page-0032.jpg)

![](_assets/7%20非线性规划3_page-0033.jpg)

![](_assets/7%20非线性规划3_page-0034.jpg)

### 小结

![](_assets/7%20非线性规划3_page-0035.jpg)

## 简约梯度法


![](_assets/7%20非线性规划3_page-0037.jpg)

![](_assets/7%20非线性规划3_page-0038.jpg)

>通过这种方式简化了梯度的计算

![](_assets/7%20非线性规划3_page-0039.jpg)

![](_assets/7%20非线性规划3_page-0040.jpg)

![](_assets/7%20非线性规划3_page-0041.jpg)

![](_assets/7%20非线性规划3_page-0042.jpg)


## Karush-Kuhn-Tucker 定理

![](_assets/7%20非线性规划3_page-0044.jpg)

![](_assets/7%20非线性规划3_page-0046.jpg)

>注意这里互补松弛条件针对的是不等式约束的函数值, 对应上边提到的起作用的约束和不起作用的约束.

![](_assets/image-20240114165602186.png)

-----

![](_assets/image-20240114165903699.png)

![](_assets/image-20240114165939725.png)

![](_assets/image-20240114170004898.png)

![](_assets/image-20240114170025343.png)

![](_assets/image-20240114170115868.png)

![](_assets/image-20240114170234068.png)

----

![](_assets/image-20240114170344774.png)

---

KKT 条件的应用条件

![](_assets/image-20240114170419041.png)

![](_assets/image-20240114170427411.png)

![](_assets/image-20240114170439601.png)

![](_assets/image-20240114170450826.png)









### 转化为无约束问题的方法


![](_assets/7%20非线性规划3_page-0048.jpg)

### 障碍函数法 (内点法)

![](_assets/7%20非线性规划3_page-0050.jpg)

### KKT 定理的构造性证明


![](_assets/7%20非线性规划3_page-0052.jpg)

![](_assets/7%20非线性规划3_page-0053.jpg)

![](_assets/7%20非线性规划3_page-0054.jpg)

![](_assets/7%20非线性规划3_page-0055.jpg)

![](_assets/7%20非线性规划3_page-0056.jpg)

![](_assets/7%20非线性规划3_page-0057.jpg)

![](_assets/7%20非线性规划3_page-0058.jpg)

![](_assets/7%20非线性规划3_page-0059.jpg)

![](_assets/7%20非线性规划3_page-0060.jpg)

![](_assets/7%20非线性规划3_page-0061.jpg)

![](_assets/7%20非线性规划3_page-0062.jpg)

### 求 KT 解的一般性方法


![](_assets/7%20非线性规划3_page-0064.jpg)

![](_assets/7%20非线性规划3_page-0065.jpg)

![](_assets/7%20非线性规划3_page-0066.jpg)

### 凸优化问题 KT 解的性质

![](_assets/7%20非线性规划3_page-0068.jpg)

![](_assets/7%20非线性规划3_page-0069.jpg)

![](_assets/7%20非线性规划3_page-0070.jpg)

![](_assets/7%20非线性规划3_page-0071.jpg)

## 拉格朗日对偶


![](_assets/7%20非线性规划3_page-0073.jpg)

![](_assets/7%20非线性规划3_page-0074.jpg)

![](_assets/7%20非线性规划3_page-0075.jpg)

![](_assets/7%20非线性规划3_page-0076.jpg)

----

![](_assets/image-20240114170523913.png)

---

>拉格朗日乘子法与对偶问题 - Richard Lee的文章 - 知乎 https://zhuanlan.zhihu.com/p/114574438

拉格朗日乘子法 (Lagrange multipliers) 是一种寻找多元函数在一组约束下的极值的方法。通过引入拉格朗日乘子, 可将有 $d$ 个变量与 $k$ 个约束条件的最优化问题转化为具有 $d+k$ 个变量的无约束优化问题求解。

![](_assets/image-20240114174800311.png)

![](_assets/image-20240114174814485.png)

![](_assets/image-20240114174828863.png)

![](_assets/image-20240114174845514.png)

![](_assets/image-20240114174900024.png)

![](_assets/image-20240114174913996.png)

![](_assets/image-20240114175140905.png)

![](_assets/image-20240114175259340.png)

![](_assets/image-20240114175314150.png)








# 优化算法




















