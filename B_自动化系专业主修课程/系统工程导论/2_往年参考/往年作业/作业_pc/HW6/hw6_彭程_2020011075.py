import scipy.io as io
import numpy as np
import matplotlib.pyplot as plt
import queue


def k_means(k, data, epsilon):
    """
        K-means
        input:
            -k:分类个数
            -data:待分类数据
            -epsilon:
        output:
            -classified:分类标签
    """

    N = data.shape[0]

    # 首先随机取k个点作为中心
    central_points_index = np.random.choice(N, k)
    central_points = data[central_points_index]
    new_central_points = np.zeros((k,2))

    # 循环操作直至变化足够小
    while True:
        # 将每个点归入最近点的类
        classified = np.zeros(N)  # 每个点的分类标签
        for i in range(N):
            distance = np.zeros(k)
            for j in range(k):
                distance[j] = np.sqrt(np.sum((data[i].reshape(1, 2) - central_points[j]) ** 2, axis=1))
            index = np.argmin(distance)
            classified[i] = index

        # 选取新的中心点
        for j in range(k):
            label = np.where(classified==j)[0].tolist()
            new_central_points[j] = np.sum(data[label],axis=0)/len(label)

        # 计算变化量
        diff = np.sqrt(np.sum((central_points - new_central_points) ** 2))
        central_points = np.copy(new_central_points)
        if diff <= epsilon:
            break

    return classified, central_points

def pic_draw(data, label,k,center,name):
    """
        聚类绘图
        input:
            -data:待分类数据
            -label:分类标签
            -k: 分类数
            -center:中心点位置
    """
    color_dict = {0: 'red', 1: 'yellow', 2: 'blue', 3: 'green', 4: 'purple', 5: '#ff69b4', 6: '#daa520',
                  7: 'cyan', 8: 'magenta', 9: '#faebd7', 10: '#2e8b57', 11: '#eeefff', 12: '#da70d6',
                  13: '#ff7f50', 14: '#cd853f', 15: '#bc8f8f', 16: '#5f9ea0'}
    for i in range(k):
        plt.scatter(data[np.where(label == i), 0], data[np.where(label == i), 1], c=color_dict[i], marker='*')
        plt.scatter(center[i][0], center[i][1], s=100, color='black', marker='*')
    plt.title('K-means, K=%d' % k)
    plt.savefig("{}.jpg".format(name))
    plt.show()

    return
def DBSCAN(data, eps, MinPots,name):
    """
    DBSCAN
    input:
        -data: 数据
        -eps: 邻域点与核心点距离
        -MinPots: 核心点邻域点个数
        -name:存储图片的名称
    """
    N = data.shape[0]

    # 聚类：随机选核心点，把他邻域都划进去，然后在他的邻域里找核心点，邻域也划进去

    visited = np.zeros(N)# 访问过了之后变成1
    corepoints = [] # 核心点列表
    is_core = np.zeros(N) # 一个数据点是否是核心点
    label = -np.ones(N).astype('int')# 点标签，-1表示噪音点

    for n in range(N): # 找到所有的核心点
        NeighborPts = []
        for i in range(N):
            if np.sqrt(np.sum((data[i] - data[n]) **2))<= eps:
                NeighborPts.append(i)
        if len(NeighborPts)>= MinPots+1: # 说明是核心点
            corepoints.append(n)
            is_core[n]=1

    print("ok")
    # 把核心点分好类
    k=0
    q=[]
    while len(corepoints) != 0:
        q.append(corepoints[0])
        corepoints.pop(0)
        label[q[0]] = k
        visited[q[0]] = 1
        while len(q) != 0:
            for i in range(N):
                if np.sqrt(np.sum((data[i] - data[q[0]]) **2) )<= eps:
                    if visited[i]==0 and is_core[i]:
                        q.append(i)
                        corepoints.remove(i)
                        label[i] = k
                        visited[i] = 1
                    elif visited[i]==0:
                        label[i] = k
                        visited[i] = 1
            q.pop(0)
        k+=1
        print(k)
    # 把标签都打好了

    # plot
    color_dict = {0: 'red', 1: 'yellow', 2: 'blue', 3: 'green', 4: 'purple', 5: '#ff69b4', 6: '#daa520',
                  7: 'cyan', 8: 'magenta', 9: '#faebd7', 10: '#2e8b57', 11: '#eeefff', 12: '#da70d6',
                  13: '#ff7f50', 14: '#cd853f', 15: '#bc8f8f', 16: '#5f9ea0'}
    for i in range(k):
        plt.scatter(data[np.where(label == i), 0], data[np.where(label == i), 1], c=color_dict[i], marker='*')
    plt.title('DBSCAN eps = %.4f MinPts = %d' % (eps, MinPots))
    plt.savefig("{}.jpg".format(name))
    plt.show()
    return


def expandCluster(data, P, NeighberPts, C, eps, MinPts, label, unvisited):

    return label, unvisited


def regionsearch(data, P, eps):
    """
        寻找邻域点队列
        input:
            -data: 数据
            -eps: 邻域点与核心点距离
            -P: 核心点
    """
    N = data.shape[0]
    NeighborPts = []
    for i in range(N):
        if np.linalg.norm(data[i] - data[P]) <= eps:
            NeighborPts.append(i)
    return NeighborPts


if __name__ == '__main__':
    data = io.loadmat('data.mat')
    data1, data2, data3 = data['data1'], data['data2'], data['data3']

    '''
        绘制原始图像
    '''
    # x=data1[:,0]
    # y=data1[:,1]
    # plt.scatter(x,y)
    # plt.show()
    #
    # x=data2[:,0]
    # y=data2[:,1]
    # plt.scatter(x,y)
    # plt.show()
    #
    # x=data3[:,0]
    # y=data3[:,1]
    # plt.scatter(x,y)
    # plt.show()

    '''
        绘制3个数据集的kmeans聚类结果
    '''
    # label1, center1 = k_means(2, data1, 1e-6)
    # pic_draw(data1,label1,2,center1,"no1")
    #
    # label2, center2 = k_means(3, data2, 1e-6)
    # pic_draw(data2,label2,3,center2,"no2")
    #
    # label3, center3 = k_means(3, data3, 1e-6)
    # pic_draw(data3,label3,3,center3,"no3")

    '''
      对于data2，增加k，选择一个合适的k
    '''
    # N = data2.shape[0]
    # num = 9
    # dist = np.zeros(num + 1)
    # for k in range(1, num + 1):
    #     label, central_points = k_means(k, data2, 1e-6)
    #     pic_draw(data2, label, k, central_points, "k={}".format(k))
    #     for i in range(N):
    #         dist[k] += np.sqrt(np.sum((data2[i] - central_points[int(label[i])]) ** 2))
    # plt.plot(np.arange(1, num + 1), dist[1:],marker='.')
    # plt.title('The Elbow Method using Distortion')
    # plt.xlabel('Values of K')
    # plt.ylabel('Distortion')
    # plt.show()

    '''
          绘制data2不同初始点下的kmeans聚类结果
      '''

    # label2, center2 = k_means(4, data2, 1e-6)
    # pic_draw(data2,label2,4,center2,"no2-1")
    #
    # label2, center2 = k_means(4, data2, 1e-6)
    # pic_draw(data2,label2,4,center2,"no2-2")
    #
    # label2, center2 = k_means(4, data2, 1e-6)
    # pic_draw(data2,label2,4,center2,"no2-3")

    '''
          绘制data1不同初始点下的kmeans聚类结果
      '''

    label1, center1 = k_means(5, data1, 1e-6)
    pic_draw(data1,label1,5,center1,"no1-1")

    label1, center1 = k_means(5, data1, 1e-6)
    pic_draw(data1,label1,5,center1,"no1-2")

    label1, center1 = k_means(5, data1, 1e-6)
    pic_draw(data1,label1,5,center1,"no1-3")


    '''
      DBSCAN实现，但是跑的非常慢
    '''
    # DBSCAN(data1, 0.05, 5,"data1")
    # DBSCAN(data2, 0.4, 10,"data2")
    # DBSCAN(data3, 0.3, 20,"data3")
    #
    # DBSCAN(data3, 0.01, 20,"data3-0.01")
    # DBSCAN(data3, 0.1, 20,"data3-0.1")
    # DBSCAN(data3, 0.2, 20,"data3-0.2")
    # DBSCAN(data3, 0.3, 20,"data3-0.3")
    # DBSCAN(data3, 0.4, 20,"data3-0.4")
    # DBSCAN(data3, 0.5, 20, "data3-0.5")
    #
    # DBSCAN(data3, 0.3, 5,"data3-5")
    # DBSCAN(data3, 0.3, 10,"data3-10")
    # DBSCAN(data3, 0.3, 20,"data3-20")
    # DBSCAN(data3, 0.3, 30,"data3-30")
    # DBSCAN(data3, 0.3, 40,"data3-40")
    # DBSCAN(data3, 0.3, 50, "data3-50")

