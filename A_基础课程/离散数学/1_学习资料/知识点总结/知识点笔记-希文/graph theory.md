# 图论基本概念

图论中的图是指某类具体离散事物集合和该集合中的每对事物间以某种方式相联系的数学模型。这里的图指的是拓扑图，其基本元素为顶点和边。

### 集合基本概念

$x \in A(x$ 属于 $A): x$ 是 $A$ 的元素

$x \notin A(x$ 不属于 $A$ ): $x$ 不是 $A$ 的元素

包含(子集) $\quad A \subseteq B \Leftrightarrow \forall x(x \in A \rightarrow x \in B)$

### 无向图

无序积：
$$
A \& B = \{(a,b) | a \in A \land b \in B\}
$$

- 允许 a = b
- $(a, b)=(b, a)$。因而$A \& B=B \& A$

无序积：把两个集合并列到一起。

**定义 1**：一个无向图 $G$ 定义为一个二元组 $\langle V,E \rangle$，记作 $G = \langle V,E \rangle$，其中：

1. $V$ 是一个非空集合，称为 $G$ 的**顶点集**，它的元素称为**顶点**。

2. $E \subseteq V \& V$，称为 $G$ 的**边集**，其元素称为**边**，$V \& V$ 中的元素可以在 $E$ 中出现不止一次。

   > 边集中可以出现自环，也可以出现多重边。通过这样表示：$E=\{(a, a),(a, b),(a, b),(b, c),(c, d),(b, d)\}$

### 有向图

卡氏积（笛卡尔积）

设 $A,B$ 是两个非空集合，记：
$$
A \times B = \{\langle a,b \rangle | a \in A \land b \in B\} \\
$$
- $\langle\boldsymbol{a}, \boldsymbol{b}\rangle \neq\langle\boldsymbol{b}, \boldsymbol{a}\rangle$ 既然是有序的，所以谁写在前面谁写在后面是不一样的！
- 允许a = b
- $\boldsymbol{A} \times \boldsymbol{B} \neq \boldsymbol{B} \times \boldsymbol{A}$, 除非 $\boldsymbol{A}=\boldsymbol{B} \vee \boldsymbol{A}=\emptyset \vee \boldsymbol{B}=\emptyset$

**定义 2**：一个有向图 $D$ 定义为一个二元组 $\langle V,E \rangle$，记作 $D = \langle V,E \rangle$，其中：

1. $V$ 是一个非空集合，称为 $D$ 的**顶点集**
2. $E \subseteq V \times V$，称为 $G$ 的**边集**，其元素称为**边**，$V \times V$ 中的元素可以在 $E$ 中出现不止一次。(即边集也是多重集)
3. 有向边 $\langle U, V\rangle$，其中U是起点，V是终点；起点写在前面，终点写在后面；

### 图的性质

**定义3**：没有任何边的图称为**空图**，边数是零的图是零图，只有一个点的图称为**平凡图**（即一阶零图）。

> 在图的定义中规定顶点集V为非空集，但在图的运算中可能产生顶点集为空集的运算结果，为此规定顶点集为空集的图为空图

**定义 4**：图中顶点的个数称为**图的阶**，若 $|V(G)| = n$，则称 $G$ 为 $n$ 阶图；连接两个相同顶点的边的条数称为**边的重数**，这些边称为**平行边或多重边**。

标定图：顶点或边带标记的图

非标定图：顶点和边不带标记的图

底图（基图）:有向图去掉边的方向后得到的无向图

**邻接点**：与一边关联的两个结点。

**邻接边**：关联同一个点的两条边。

**环**：只关联一个结点的边。（环的定义与有向、无向无关）

**简单图**：没有环以及没有重数大于 $1$ 的边的图。

**孤立点**：不与任何点邻接的点。

**平行边**：

- 端点相同的两条无向边是平行边
- 起点与终点相同的两条有向边是平行边。注意：**一定要求方向一致**

邻域: $N_{G}(v)=\{u \in V(G) \mid(u, v) \in E(G) \wedge u \neq v\}$

闭邻域: $\overline{\mathrm{N}_{\mathrm{G}}(\mathrm{v})}=\mathrm{N}_{\mathrm{G}}(\mathrm{v}) \cup\{\mathrm{v}\}$

> 注意：上边有一条横杠，所以是闭的！

关联集: $\mathrm{I}_{\mathrm{G}}(\mathbf{v})=\{\mathrm{e} \mid \mathrm{e}$ 与 $\mathbf{v}$ 关联 $\}$

> 这里的关联集说的是边！

后继: $\Gamma_{\mathrm{D}}^{+}(\mathbf{v})=\{\mathrm{u} \in \mathrm{V}(\mathrm{D}) \mid<\mathrm{v}, \mathrm{u}>\in \mathrm{E}(\mathrm{D}) \wedge \mathrm{u} \neq \mathrm{V}\}$

前驱: $\Gamma_{\mathrm{D}}^-(\mathbf{v})=\{\mathrm{u} \in \mathrm{V}(\mathrm{D}) \mid<\mathrm{u}, \mathrm{v}>\in \mathrm{E}(\mathrm{D}) \wedge \mathrm{u} \neq \mathbf{v}\}$

而有向图的邻域、闭邻域就是前驱、后继的并

### 度

无向图结点 $v$ 的度：$G$ 是无向图，$v \in V(G)$，结点 $v$ 所关联边数，称之为结点 $v$ 的**度**，记作 $d(v)$，环对度贡献为 $2$。

而有向图出度、入度要分开说：

出度$\mathbf{d}_{\mathrm{D}}{ }^{+}(\mathbf{v})=$ 与 $\mathbf{v}$ 关联的**出边**的次数之和

入度: $d_{D}^-(v)=$ 与 $v$ 关联的**入边**的次数之和

有向图中某顶点的度是出度、入度之和。

**奇点**：度为奇数的点。

**偶点**：度为偶数的点。

令 $G = \langle V,E \rangle$ 是无向图，$V = \{v_1,v_2,\cdots,v_n\}$，则称 $(d(v_1),d(v_2),\cdots,d(v_n))$ 为图 $G$ 的**结点度序列**。

> 在度数列的表示中，度数列的顺序不重要

**最大度**：$\Delta(G) = \max \{d(v) | v \in G\}$

**最小度**：$\delta(G) = \min \{d(v) | v \in G\}$

> 还有类似的最大出度、最小出度、最大入度、最小入度之类的区别；

**相关定理**

**定理 1**（握手定理、图论基本定理）：每个无向图所有结点度总和等于边数的 $2$ 倍，即：
$$
\sum_{v \in V} d(v) = 2 |E|
$$
**定理 2**（握手定理推论）：每个无向图中，奇数度的结点必为偶数个。

**定理3**（有向图中的定理）：

设 $\mathrm{D}=<\mathrm{V}, \mathrm{E}>$ 是有向图, $\mathrm{V}=\left\{\mathrm{v}_{1}, \mathrm{v}_{2}, \ldots, \mathrm{v}_{\mathrm{n}}\right\}$, $|E|=m$, 则
$$
\begin{gathered}
d^{+}\left(v_{1}\right)+d^{+}\left(v_{2}\right)+\ldots+d^{+}\left(v_{n}\right) \\
=d^{-}\left(v_{1}\right)+d^{-}\left(v_{2}\right)+\ldots+d^{-}\left(v_{n}\right)=m 
\end{gathered}
$$

> 翻译一下：每一条边都有起点、终点；

### 简单图、正则图、完全图、竞赛图、彼得森图

简单图：既无环也无平行边的图。$0 \leq \Delta(\mathbf{G}) \leq \mathbf{n}-1$

$k$-正则图:一个无向简单图 $G$ 中，如果 $\Delta(G) = \delta(G) = k$，则称 $G$ 为 $k$-正则图。

> 即所有顶点的度都是k

![image-20211026081618239](graph%20theory.assets/image-20211026081618239.png)

完全图：$G$ 是个简单图，如果每对不同结点之间，都有边相连，则称 $G$ 是个**无向完全图**。如果 $G$ 有 $n$ 个结点，记为 $K_n$。

**定理**：完全图 $K_n$ 有边数 $\dfrac{n(n – 1)}{2}$。

![image-20211024181856875](graph%20theory.assets/image-20211024181856875.png)

竞赛图：竞赛图是通过在无向完全图中为每个边缘分配方向而获得的有向图。 竞赛图的基图是完全图

![image-20211024182026992](graph%20theory.assets/image-20211024182026992.png)

彼得森图：

![图1](graph%20theory.assets/format,f_auto.png)

Petersen图的顶点可以如此分为三个部分，使各个部分中的点互不相连。因此，Petersen图是三部图。

彼得森图有10个顶点、15条边（5+5+5），是3-正则图。

### r部图

$\mathbf{G}=\left\langle\mathrm{V}, \mathrm{E}\rangle, \mathrm{V}=\mathrm{V}_{1} \cup \mathrm{V}_{2} \cup \ldots \cup \mathrm{V}_{\mathrm{r}}\right.$,$\mathbf{V}_{i} \cap \mathbf{V}_{\mathrm{j}}=\varnothing(\mathrm{i} \neq \mathrm{j})$,$E \subseteq_{i \neq j} \cup\left(V_{i} \& V_{j}\right)$

> 即：子集内部无边，所有的边都在子集间。

也记作 $\mathbf{G}=<\mathbf{V}_{1}, \mathbf{v}_{2}, \ldots, \mathbf{V}_{\mathrm{r}} ; \mathrm{E}>$.

![image-20211024182842422](graph%20theory.assets/image-20211024182842422.png)

二部图（偶图）

二部图: $\mathrm{G}=<\mathrm{V}_{1}, \mathrm{~V}_{2} ; \mathrm{E}>$ 也称为偶图

![image-20211024182922800](graph%20theory.assets/image-20211024182922800.png)

完全r部图：

![image-20211024182954902](graph%20theory.assets/image-20211024182954902.png)

### 超立方体

![image-20211024183011197](graph%20theory.assets/image-20211024183011197.png)

在超算中GPU寻址中，有时会应用到超立方体的知识。

### 可图化

可图化是一个相当简单的条件——又不是“可简单图化”！

可图化的充要条件：

非负整数列 $\mathrm{d}=\left(d_{1}, \mathrm{~d}_{2}, \ldots, \mathrm{d}_{\mathrm{n}}\right)$ 可图化 $\leftrightarrow$ $\mathrm{d}_{1}+\mathrm{d}_{2}+\ldots+\mathrm{d}_{\mathrm{n}} \equiv 0(\bmod 2)$

证明：

- ( $\Rightarrow$ ) 握手定理
- $(\Leftarrow)$ 由构造法入手证明，奇数度点两两之间连一边（偶数个奇数度结点），剩余度用环来实现

![image-20211026081536768](graph%20theory.assets/image-20211026081536768.png)

### 可简单图化

设非负整数列 $\mathrm{d}=\left(\mathrm{d}_{1}, \mathrm{~d}_{2}, \ldots, \mathrm{d}_{\mathrm{n}}\right)$, 若存在简单图G, 使 得G的度数列是 $\mathrm{d}$, 则称 $\mathrm{d}$ 为可简单图化的。

例：

- $\mathrm{d}=(5,3,3,2,1)$ 不可简单图化，因为最大度=n。
- $\mathrm{d}=(4,4,3,2,1)$ 不可简单图化



可简单图化充要条件（Havel定理）

设非负整数列 $d=\left(\mathrm{d}_{1}, \mathrm{~d}_{2}, \ldots, \mathrm{d}_{\mathrm{n}}\right)$ 满足:
$$
\begin{gathered}
\mathrm{d}_{1}+\mathrm{d}_{2}+\ldots+\mathrm{d}_{\mathrm{n}} \equiv 0(\bmod 2) \\
\mathrm{n}-1 \geq \mathrm{d}_{1} \geq \mathrm{d}_{2} \geq \ldots \geq \mathrm{d}_{\mathrm{n}}>0,
\end{gathered}
$$
则 $\mathbf{d}$ 可简单图化 $\Leftrightarrow$
$$
d^{\prime}=\left(d_{2}-1, d_{3}-1, \ldots, d_{d 1+1}-1, d_{d 1+2}, \ldots, d_{n}\right)
$$
可简单图化。
> 注意是度数列的前d1个减1

例: $\mathrm{d}=(4,4,3,3,2, \mathbf{2}), \mathrm{d}^{\prime}=(3,2,2,1, 2)$

> 下一步要将$d^{\prime}$的1和2换一下再继续减1！（因为要保证度数列降序排布。

![image-20211024175611729](graph%20theory.assets/image-20211024175611729.png)

证明：

- 若d'可简单图化，我们只需把原图中的最大度点和d'中度最大的d1个点连边即可，易得此图必为简单图
- 若d可简单图化，设得到的简单图为G。分两种情况考虑:
  - 若G中存在边(V1,V2),(V1,V3),…,(V1,V(d1+1))，则把这些边除去得简单图G’，于是d’可简单图化为G’
  - 若存在点Vi,Vj使得i＜j, (V1,Vi)不在G中，但(V1,Vj)在G中。这时，因为di≥dj，必存在k使得(Vi, Vk)在G中但(Vj,Vk)不在G中。这时我们可以令GG=G-{(Vi,Vk),(V1,Vj)}+{(Vk,Vj),(V1,Vi)}。GG的度序列仍为d，我们又回到了上一种情况。

> 注意，在这个证明过程中：
>
> - Vk排序在哪里并不重要，即对k的大小并没有要求
> - 实质上是借用Vk这个点把相同的度序列换了一下，通过构造的方式，把Vk换给了V1

### 图的同构

设 $G = \langle V,E \rangle$ 和 $G’ = \langle V’,E’ \rangle$ 是图，如果存在双射 $f : V \to V’$ 且任何 $e = (v_i,v_j) \in E$，有 $e’ = (f(v_i),f(v_j)) \in E’$，并且边 $e$ 与 $e’$ 的重数相同。

则称 $G$ 与 $G’$ 同构，记作 $G \stackrel{\backsim}{=} G’$。

同构的图，其图论性质完全一样

在小型图中，运用NAUTY算法检验图是否同构。

有向图的同构：设 $D = \langle V,E \rangle$ 和 $D’ = \langle V’,E’ \rangle$ 是图，如果存在双射 $f : V \to V’$ 且任何 $e = <v_i,v_j> \in D$，有 $e’ = <f(v_i),f(v_j)> \in D’$，并且边 $e$ 与 $e’$ 的重数相同，则称两个有向图同构。

**两个图同构的必要条件**：

1. 结点个数相等。
2. 边数相等。
3. 度数相同的结点数相等。
4. 对应的结点的度数相等。

![image-20211024181159365](graph%20theory.assets/image-20211024181159365.png)
$$
\mathbf{G}_{1} \cong \mathrm{G}_{3}, \quad \mathbf{G}_{1} \neq \mathrm{G}_{2}
$$

>  第一个同构：把G1里边的三角形拿出来翻出去即可；
>
> 第二个同构：通过回路判断

![image-20211024181626187](graph%20theory.assets/image-20211024181626187.png)

**有向图判断图是否同构的时候一定要注意检查边的方向！**

### 子图

**定义 1**：称图 $H$ 为图 $G$ 的子图，如果 $V(H) \subseteq V(G)$，$E(H) \subseteq E(G)$，且 $H$ 中边的重数不能超过 $G$ 中对应边的重数。

**定义2**：真子图(proper subgraph):
$$
\mathbf{G}^{\prime} \subset \mathbf{G} \Leftrightarrow \mathbf{G}^{\prime} \subseteq \mathbf{G} \wedge\left(\mathbf{V}^{\prime} \subset \mathbf{V} \vee \mathbf{E}^{\prime} \subset \mathrm{E}\right)
$$

> 即，要么顶点少了，要么边少了

**定义 3**：设 $G = \langle V,E \rangle$，一个满足 $H = \langle V,E_1 \rangle$，$E_1 \subseteq E$ 的子图称为 $G$ 的生成子图。

> 点集完全一样。

**定义 4**：设 $V’$ 是图 $G$ 的顶点集 $V$ 的一个非空子集，以 $V’$ 作为顶点集，以两端点均在 $V’$ 的边的全体为边集的子图，称为由 $V’$ 导出的 $G$ 的子图，记为 $G[V’]$，称其为 $G$ 的导出子图。

**定义 5**：设 $E’$ 是图 $G$ 的边集 $E$ 的一个非空子集，以 $E’$ 为边集，以 $E’$ 中边的全体端点为顶点集组成的子图称为由 $E’$ 导出的子图，记为 $G[E’]$。

![image-20211024183807411](graph%20theory.assets/image-20211024183807411.png)

**注**：$G$、空图均为 $G$ 的子图，而且是非空子图，称为平凡子图。其中，$G$ 为 $G$ 的点导出子图。

### 补图

**定义 1**：设 $G$ 是简单图，$H$ 是一个以 $V(G)$ 为顶点集的图，且两个顶点在 $H$ 中邻接当且仅当它们则在 $G$ 中不邻接，则称 $H$ 是 $G$ 的**补图**，记作 $H = \overline{G}$。



**定义 2**：由 $G$ 的所有结点和为使 $G$ 称为完全图，所需要添加的那些边组成的图，称之为 $G$ 的补图。

$$
G= < V, E>,\bar{G}=< V, E\left(K_{n}\right)-E>
$$
自补图（self-complement graph):
$$
\mathbf{G} \cong \overline{\mathbf{G}}
$$
![image-20211024184307064](graph%20theory.assets/image-20211024184307064.png)

### 拉姆齐定理

拉姆齐定理的通俗表述：6个人中至少存在3人相互认识或者相互不认识

![image-20211024193622169](graph%20theory.assets/image-20211024193622169.png)

### 典型例题

对于一般情况，给定正整数n和m，$m \leqslant \frac{n(n-1)}{2}$，构造所有非同构的n阶m条边的无向（有向）简单图仍是目前还没有解决的难题。

而如果遇到画出所有非同构的无向简单图的问题，应该首先从度数列入手指引分配，并利用握手定理找出度数之和，并利用最大度小于等于n-1的关系进行分析。

![image-20211024195158188](graph%20theory.assets/image-20211024195158188.png)

![image-20211024195209765](graph%20theory.assets/image-20211024195209765.png)



### 图的运算

![tmpAB19](graph%20theory.assets/tmpAB19.png)

![tmpDE01](graph%20theory.assets/tmpDE01.png)

![tmp29E0](graph%20theory.assets/tmp29E0.png)

![tmpADF6](graph%20theory.assets/tmpADF6.png)

![tmp8211](graph%20theory.assets/tmp8211.png)

![tmp2670](graph%20theory.assets/tmp2670.png)



![image-20211025164837930](graph%20theory.assets/image-20211025164837930.png)



# 图的连通

### 路与回路

**定义方式一**

**路（walk）**

给定图 $G = \langle V,E \rangle$，设 $v_0,v_1,\cdots,v_k \in V,e_1,e_2,\cdots,e_k \in E$，其中 $e_i$ 是关联 $v_{i – 1}$ 和 $v_i$ 的边，则称结点和边的交叉序列 $v_0e_1v_1\cdots e_kv_k$ 是连接 $v_0$ 和 $v_k$ 的**路**。

$v_0$ 是此路的**起点**，$v_k$ 是此路的**终点**。路中含有的边数 $k$ 称之为**路的长度**。

如果 $G$ 是个简单图，则路可以只用结点序列表示。

**回路**

如果一条路的起点和终点是同一个结点，则称此路是一个**回路**。

**迹（chain）和闭迹**

如果一条路中，所有边都不同，则称此路为**迹**。

如果一条回路中，所有边都不同，则称此回路为**闭迹**。

 **通路（path）和圈（cycle）**

如果一条路中，所有结点都不同，则称此路为**通路**。

如果一条回路中，除起点和终点外，其余结点都不同，则称此回路为**圈**。

圈的表示：画出的长度为l的圈

- 如果是非标定的, 则在同构意义下是唯一的
- 如果是标定的(指定起点,终点), 则是 $l$ 个不同的圈。在标定图中，圈表示成顶点和边的标记序列，只要两个标记序列不同，就认为这两个圈不同，称这两个圈在定义意义下不同

![image-20211025165830116](graph%20theory.assets/image-20211025165830116.png)

长度为奇数的圈称作奇圈。

**定义方式二**

初级通路（路径）：**没有重复顶点**、没有重复边的通路

初级回路（圈）：没有重复顶点、没有重复边的回路

简单通路：没有重复边的通路

简单回路：**没有重复边**的回路

复杂通路：有 重复边的通路

复杂回路：有重复边的回路



定理：在n阶(有向或无向)图G中,若从不同顶点${v}_{\mathrm{i}}$ 到 $v_{\mathrm{j}}$ 有通路, 则从 $v_i$ 到 $v_j$ 有长度小于等于 $\mathrm{n}-1$ 的通路

推论：

在n阶图G中,若从不同顶点${v}_{\mathrm{i}}$ 到 $v_{\mathrm{j}}$ 有通路, 则从 $v_i$ 到 $v_j$ 有长度小于等于 $\mathrm{n}-1$ 的路径（初级通路）

![tmp6DAE](graph%20theory.assets/tmp6DAE.png)

定理：在n阶图G中，若有从顶点$V_i$到自身的回路，则有从$V_i$到自身长度小于等于n的回路

推论：在n阶图G中，若有从顶点$V_i$到自身的简单回路，则有从$V_i$到自身长度小于等于n的圈（初级回路）

**极大路径**

在无向简单图中，路径的两个端点不与路径本身以外的顶点相邻，这样的路径称为**极大**路径

在有向图中，路径起点的前驱，终点的后继，都在路径本身上。

> 可以理解为这句话表达的是：起点没有其它的前驱，终点没有其它的后继。

**扩大路径法（极大路径的产生）**

任何一条路径，只要不是极大路径，则至少有一个端点与路径本身以外的顶点相邻,则路径还可以扩大,直到变成极大路径为止。  

例：设G是$n(n \geq 3)$阶无向简单图，$\delta(G) \geq 2$。证明G中有长度$\geq \delta(\mathrm{G})+1$的圈。

> $\delta(G) \geq 2$是个很重要的条件！举反例的时候可以用！

证明：

$\forall \mathbf{v}_{0} \in \mathbf{V}(\mathbf{G}), \delta(\mathbf{G}) \geq \mathbf{2} \Rightarrow \exists \mathbf{v}_{1} \in \mathbf{N}_{\mathrm{G}}\left(\mathbf{v}_{0}\right)$，

对$\Gamma_{0}=\mathrm{v}_{0} \mathrm{v}_{1}$采取扩大路径法，得到极大路径：$\Gamma=\mathbf{v}_{0} \mathbf{v}_{1} \ldots \mathbf{v}_{\mathbf{k}}$

$\mathrm{d}\left(\mathbf{v}_{\mathrm{k}}\right) \geq \delta(\mathbf{G}) \Rightarrow \mathbf{k} \geq \delta(\mathbf{G})$

> 构造出一条路径，路径长度大于等于图的最小度。

$\mathbf{d}\left(\mathbf{v}_{0}\right) \geq \delta(\mathbf{G}) \Rightarrow \exists \mathbf{v}_{i} \in \mathbf{N}_{G}\left(\mathbf{v}_{0}\right), \delta(\mathbf{G}) \leq \mathbf{i} \leq \mathbf{k}$

于是 $\mathbf{v}_{0} \mathbf{v}_{1} \ldots \mathbf{v}_{\mathrm{i}} \mathbf{v}_{0}$ 是长度 $\geq \delta$ (G)+1的圈.

> $\delta(G)$是最小度
>
> $\mathbf{N}_{\mathrm{G}}$表示的是某个顶点的邻域

有向图版本：

![image-20211025172058987](graph%20theory.assets/image-20211025172058987.png)

![image-20211025172126427](graph%20theory.assets/image-20211025172126427.png)

### 距离

**定义**

设 $u$，$v$ 是 $G$ 中任意两点，若 $u$，$v$ 连通，则 $G$ 中最短的 $u – v$ 通路的长定义为 $u$ 和 $v$ 之间的距离，记为$d_G(u,v)$，简记 $d(u,v)$。若 $u$，$v$ 不连通，则定义 $d(u,v) = \infty$。

短程线（测地线）：u、v之间长度最短的通路

直径：$\mathrm{d}(\mathrm{G})=\max \left\{\mathrm{d}_{\mathrm{G}}(\mathrm{u}, \mathrm{v}) \mid \mathrm{u}, \mathrm{v} \in \mathrm{V}(\mathrm{G})\right\}$
$$
d\left(K_{n}\right)=1(n \geq 2), d\left(N_{1}\right)=0, d\left(N_{n}\right)=\infty(n \geq 2)
$$
**性质**

1. 非负性：$\mathrm{d}(\mathrm{u}, \mathrm{v}) \geq \mathbf{0}$,

   $\mathrm{d}(\mathrm{u}, \mathrm{v})=0 \Leftrightarrow \mathrm{u}=\mathrm{v}$

2. $d(u,v) = d(v,u)$；

3. 三角不等式：$\mathrm{d}(\mathrm{u}, \mathrm{v})+\mathrm{d}(\mathrm{v}, \mathrm{w}) \geq \mathrm{d}(\mathrm{u}, \mathrm{w})$

任何函数只要满足上述三条性质，就可以当作距离函数使用。



### 图的连通性

#### 无向图的连通性

**两点之间连通**

如果结点 $u$ 和 $v$ 之间存在一条路，则称 $u$ 和 $v$ 连通。记为u~v

**规定**：对任何结点 $u$，$u$ 和 $u$ 连通。



结点间的连通关系是一个**等价关系**。

- 自反：u~u
- 对称: $\mathrm{u} \sim \mathrm{v} \Rightarrow \mathrm{v} \sim \mathrm{u}$
- 传递: $\mathrm{u} \sim \mathrm{v} \wedge \mathrm{v} \sim \mathrm{w} \Rightarrow \mathrm{u} \sim \mathrm{w}$



**连通分支**

设 $G = \langle V,E \rangle $ 是无向图，$R$ 是 $V$ 上连通关系，设 $R$ 对 $V$ 的商集中有等价类 $V_1,V_2,\cdots,V_n$，这 $n$ 个等价类构成的 $n$ 个子图分别记作 $G[V_1],G[V_2],\cdots,G[V_n]$，并称它们为 $G$ 的**连通分支**。并用 $p(G)$ 表示 $G$ 中**连通分支数**。

如果图 $G$ 只有一个连通分支（$p(G) = 1$），则称 $G$ 是**连通图**。

**定理**：图 $G = \langle V,E \rangle$ 是连通的，当且仅当对 $V$ 的任何划分 $V_1,V_2$，恒存在一条边，使得它的端点分别属于 $V_1$，$V_2$。

在所有n阶无向图中，n阶零图是连通分支最多的:$p(N_n) = n$



**定理：**$\mathbf{G}$ 是二部图 $\Leftrightarrow \mathbf{G}$ 中无奇圈

证明：

（$\Rightarrow$） 设 $\mathbf{G}=\left(\mathbf{V}_{1}, \mathbf{V}_{2} ; \mathbf{E}\right)$,

设 $\mathbf{C}=\mathbf{v}_{1} \mathbf{v}_{2} \ldots \mathbf{v}_{l-1} \mathbf{v}_{l} \mathbf{v}_{1}$ 是 $\mathbf{G}$ 中的任意圈, 设 $\mathbf{v}_{1} \in \mathbf{V}_{1}$, 则$\mathbf{v}_{3}, \mathbf{v}_{5}, \ldots, \mathbf{v}_{l-1} \in \mathbf{V}_{1}$，$\mathbf{v}_{2}, \mathbf{v}_{4}, \ldots, \mathbf{v}_{l} \in \mathbf{V}_{2}$，于是 $l=|\mathbf{C}|$ 是偶数, $\mathrm{C}$ 是偶圈。

$(\Leftarrow)$ 设 $G$ 连通(否则对每个连通分支进行讨论)

设 $v \in V(G)$, 令
$$
\mathbf{V}_{1}=\{\mathbf{u} \in \mathbf{V}(\mathbf{G}) \mid \mathbf{d}(\mathbf{u}, \mathbf{v}) \text { 为偶数 }\}
$$

$$
\mathbf{V}_{2}=\{\mathbf{u} \in \mathbf{V}(\mathbf{G}) \mid \mathbf{d}(\mathbf{u}, \mathbf{v}) \text { 为奇数 }\}
$$

则 $\mathbf{V}_{1} \cup \mathbf{V}_{2}=\mathbf{V}(\mathbf{G}), \mathbf{V}_{1} \cap \mathbf{V}_{2}=\varnothing$.

下证 $\mathbf{E}(\mathbf{G}) \subseteq \mathbf{V}_{1} \boldsymbol{\&} \mathbf{V}_{2} .$

> 即可以构造出一个二部图

反证法：若存在 $\mathbf{e}=\left(\mathbf{v}_{\mathbf{x}}, \mathbf{v}_{\mathbf{y}}\right), \mathbf{v}_{\mathbf{x}}, \mathbf{v}_{\mathbf{y}} \in \mathbf{V}_{1}$, 设 $\Gamma_{\mathrm{vx}}$ 和 $\Gamma_{\mathrm{vy}}$ 是 $\mathbf{v}$ 到 $\mathbf{v}_{\mathbf{x}}$和$\mathbf{v}_{\mathbf{y}}$的短程线。$\left|\Gamma_{v \mathrm{x}}\right|$ 和 $\mid \Gamma_{\mathrm{v} y}$ |都是偶数。设 $\mathbf{v}_{\mathbf{z}}$ 是 $\Gamma_{v \mathbf{x}}$ 与 $\Gamma_{v y}$的最后一个公共点，若 $\mathbf{v}_{\mathbf{z}} \in \mathbf{V}_{1}$, 则 $\left|\Gamma_{\mathrm{zx}}\right|$ 和 $\left|\Gamma_{\mathrm{zy}}\right|$ 都是偶数；若 $v_{z} \in V_{2}$, 则 $\left|\Gamma_{zx}\right|$ 和 $\left|\Gamma_{zy}\right|$ 都是奇数。于是$\Gamma_{\mathbf{zx}} \cup\left(\mathbf{v}_{\mathbf{x}}, \mathbf{v}_{\mathbf{y}}\right) \cup \Gamma_{\mathbf{z y}}$ 是 $\mathbf{G}$中奇圈，矛盾！

> 即用反证法证明不存在组内连线。



定理：若无向图G是连通的, 则G的边数 $m \geq n-1$

证明：对n使用数学归纳法

$\mathbf{G}=N_{1}: n=1, m=0 .$

设 $n \leq \mathbf{k}$ 时命题成立,下证 $n=k+1$ 时也成立.

$\forall \mathbf{v} \in \mathbf{V}(\mathbf{G})$, 设 $\mathbf{p}(\mathbf{G}-\mathbf{v})=\mathbf{s}$, 则 $\mathbf{d}_{\mathrm{G}}(\mathbf{v}) \geq \mathbf{s} .$

对G-v的连通分支 $G_{1}, G_{2}, \ldots, G_{s}$ 使用归纳假设,设$\left|\mathrm{V}\left(\mathrm{G}_{\mathrm{i}}\right)\right|=\mathrm{n}_{\mathrm{i}},\left|\mathrm{E}\left(\mathrm{G}_{\mathrm{i}}\right)\right|=\mathrm{m}_{\mathrm{i}}$, 则：

$\begin{aligned} \mathbf{m} &=\mathrm{m}_{1}+\mathrm{m}_{2}+\ldots+\mathrm{m}_{\mathrm{s}}+\mathrm{d}_{\mathrm{G}}(\mathrm{v}) \\ & \geq\left(\mathrm{n}_{1}-1\right)+\left(\mathrm{n}_{2}-1\right)+\ldots+\left(\mathrm{n}_{\mathrm{s}}-1\right)+\mathrm{s} \\ &=\mathrm{n}_{1}+\mathrm{n}_{2}+\ldots+\mathrm{n}_{\mathrm{s}}=\mathrm{n}-1 . \end{aligned}$

![image-20211025231345259](graph%20theory.assets/image-20211025231345259.png)

> 注：这个定理只是单方向的，并不是充分必要条件，反过来未必成立！
>
> ![image-20211026081918848](graph%20theory.assets/image-20211026081918848.png)

#### 有向图的连通性

**结点间的可达性**

$G = \langle u,v \rangle$ 是有向图，$u,v \in V$，如果从 $u$ 到 $v$ 有一条路，则称从 $u$ 到 $v$ **可到达**。

**结点间的距离**

如果 $u$ 可达 $v$，可能从 $u$ 到 $v$ 有多条路，其中最短的路的长度，称之为从 $u$ 到 $v$ 的**距离**，记作 $d\langle u,v \rangle$。

**距离的性质**

1. $d\langle u,v \rangle \ge 0$
2. $d\langle u,u \rangle = 0$（规定）
3. $d\langle u,v \rangle + d\langle v,w \rangle \ge d\langle u,w \rangle$
4. 如果从 $u$ 到 $v$ 不可达，则 $d\langle u,v \rangle = \infty$
5. 如 $u,v$ 互相可达，$d\langle u,v \rangle$ 不一定等于 $d\langle v,u \rangle$

 **图的直径**

$G$ 是个有向图，定义：
$$
D = \max_{u,v \in V} \{d\langle u,v \rangle\}
$$
为图 $G$ 的**直径**。



**（双向）可达**

有向图 $\mathrm{D}=<\mathrm{V}, \mathrm{E}>, \mathrm{u} \rightarrow \mathrm{v} \Leftrightarrow$ 从u到v有(有向)通路

规定u $\rightarrow \mathrm{u}$, 可达关系是自反, 传递的

有向图 $\mathrm{D}=\langle\mathrm{V}, \mathrm{E} \rangle, \mathrm{u} \leftrightarrow \mathrm{v} \Leftrightarrow \mathbf{u} \rightarrow \mathrm{v} \wedge \mathbf{v} \rightarrow \mathrm{u}$

- 双向可达关系是等价关系

- 其等价类的导出子图称为强连通分支

  ![image-20211025232036399](graph%20theory.assets/image-20211025232036399.png)

  

**强连通、单侧连通和弱连通**

在简单有向图 $G$ 中，如果任何两个结点间相互可达，则称 $G$ 是**强连通**。

如果任何一对结点间，至少有一个结点到另一个结点可达，则称 $G$ 是**单侧连通**。

如果将 $G$ 看成无向图后（即把有向边看成无向边）是连通的，则称 $G$ 是**弱连通**。



定理：**有向图强连通$\Leftrightarrow$D中有回路过每个顶点至少一次**

说明：不一定有简单回路，反例如下：

![image-20211025232453158](graph%20theory.assets/image-20211025232453158.png)

![image-20211025232507501](graph%20theory.assets/image-20211025232507501.png)



定理：**有向图D单向连通 $\Leftrightarrow$ D中有通路过每个顶点至少一次**

说明：不一定有简单通路，反例如下：

![image-20211025232625163](graph%20theory.assets/image-20211025232625163.png)

推论：若有向图D单向连通，但不是强连通，则至少加**一**条边D就会转换为强连通

证明：将充要条件中的通路转换为回路，即加一条边即可。

**定理：竞赛图一定有初级通路（路径）过每个顶点恰好一次（单向连通）**

证明：首先找一条通路。对于不在这条已知通路外的点，由于是竞赛图，所以它和每个点都有边相连。如果所有边方向都是指向这个点的，那么就把这个点安排到这条通路的末尾；否则，至少通路上有相邻两个点，和外部那个点之间边的方向一条是指向那个点一条是那个点发出来的，这样就可以把外部点安排到相邻两个点中间。这样这条通路便可以扩充，包含整个图。



**连通分支**

- 强连通分支：极大强连通子图

  > 走到不能再走为止

- 单向连通分支：极大单向连通子图

- 弱连通分支：极大弱连通子图

![image-20211025234328218](graph%20theory.assets/image-20211025234328218.png)

![image-20211025234418464](graph%20theory.assets/image-20211025234418464.png)

> 注意：连通分支前面记得标G[]

- 在有向图 $G=<V, E>$ 中, 它的每一个结点位于且仅位于一个强（弱）连通分支中。
- 在有向图 $G=<V, E>$ 中, 它的每一个结点至少位于一个单向连通分支中
- 在有向图G $=<V, E> $中, 它的每一条边至多在一个强连通分支中; 至少在一个单向连 通分支中; 在且仅在一个弱连通分支中。

应用：过河问题

一个人带着一只狼、一只羊、一棵白菜要过河, 小 船一次只能容下一个人和一样动植物。人不在场的 时候, 狼要吃掉羊、羊要吃掉白菜。问应当如何渡河?

![image-20211025234801097](graph%20theory.assets/image-20211025234801097.png)

> 思路：找到所有可能的状态，把问题定义好，再找通路。



#### 连通图连通性的强弱

$G$ 中删去点 $v$：把 $v$ 以及与 $v$ 关联的边删去。

$G$ 中删去边 $e$：仅需把该边删去。

破坏连通性：

- $p\left(G-V^{\prime}\right)>p(G)$
- $p\left(G-E^{\prime}\right)>p(G)$

> p(G)表示的是连通分支数，这里的意思是连通分支数增加！

**割集**

**点割集与割点**

$\mathbf{G}=\left\langle\mathrm{V}, \mathrm{E} \rangle, \varnothing \neq \mathrm{V}^{\prime} \subset \mathrm{V}\right.$,

1. $\mathbf{p}\left(\mathbf{G}-\mathrm{V}^{\prime}\right)>\mathbf{p}(\mathbf{G})$

2. $\forall \mathrm{V}^{\prime \prime} \subset \mathrm{V}^{\prime}, \mathrm{p}\left(\mathrm{G}-\mathrm{V}^{\prime}\right)=\mathrm{p}(\mathrm{G})$

   > 第二条即为极小性条件，即：必须删去全部点才能增加连通分支数。注意到数学表达式中那里是真子集，而不只是简单的子集。

如果点割集 $V_1$ 中只有一个结点，则称此结点为**割点**。

**割点的充分必要条件：**

无向连通图G中顶点 $v$ 是割点
$\Leftrightarrow$ 可把 $V(G)-\{v\}$划分成$V_{1}$ 与 $V_{2}$, 使得从 $V_{1}$ 中任意顶点 u到 $V_{2}$ 中任意顶点 $w$ 的路径都要经过v. 

![image-20211025235432368](graph%20theory.assets/image-20211025235432368.png)

推论：无向连通图G中顶点v是割点$\Leftrightarrow$ 存在与v不同的顶点 $u$ 和 $w$, 使得从顶点u到w的路径 都要经过v. 

![image-20211026081717488](graph%20theory.assets/image-20211026081717488.png)

**边割集与割边（桥）**

令 $G = \langle V,E \rangle$ 是连通无向图，边的集合 $E_1 \subseteq E$，如果删去 $E_1$ 中所有边后，$G$ 变得不连通了，则称 $E_1$ 是 $G$ 的一个**边割集**。

如果边割集 $E_1$ 中只有一条边，则称此边为**割边**，也称之为**桥**。



引理：设 $E^{\prime}$ 是边割集,则 $\mathbf{p}\left(\mathrm{G}-\mathrm{E}^{\prime}\right)=\mathbf{p}(\mathrm{G})+1$.

> 注意是+1！这个性质很重要！

证：如果 $p\left(G-E^{\prime}\right)>p(G)+1$,则 $E^{\prime}$ 不是边割集, 因为不满足定义中的极小性

> 点割集没有这个性质！



**桥的特性**

1. 连通图 $G$ 的边 $e$ 是割边当且仅当存在 $G$ 的两点 $u$ 和$v$，使得任意一条 $u – v$ 路过 $e$。

   

2. 连通图 $G$ 的边 $e$ 是割边的充要条件是 $e$ 不在 $G$ 的任一圈上。



**扇形割集**

$E^{\prime}$ 为扇形割集: 边割集 $E^{\prime} \subseteq v$ 的关联集 $I_{G}(\mathbf{v})$

- $\mathrm{I}_{G}(\mathbf{v})$ 不一定是边割集(不一定极小)

- $\mathrm{I}_{G}(\mathbf{v})$ 是边割集 $\Leftrightarrow \mathbf{v}$ 不是割点

  这个“不是”的原因正是因为不满足极小性条件！

  ![image-20211026000234603](graph%20theory.assets/image-20211026000234603.png)

  

  

![image-20211026000314643](graph%20theory.assets/image-20211026000314643.png)

 **点连通度**

若 $G$ 是无向连通非完全图，定义：

$\kappa (G) = \min \{|V_1| | |V_1| \text{ 是 } G \text{ 的点割集}\}$ 为 $G$ 的**点连通度**。

**注 1**：点连通度表示使 $G$ 不连通至少要删去的结点数。

**注 2**：具有割点图的点连通度 $\kappa(G) = 1$，不连通图的点连通度为 $0$，$\kappa (K_n) = n – 1$。

规定：平凡图 $N_{1}$ 连通, 但 $\left.\kappa\left(N_{1}\right)=\kappa\left(K_{1}\right)=0\right)$



**边连通度**

若 $G$ 是无向连通图，定义：

$\lambda (G) = \min \{ |E_1| | E_1 \text{ 是 } G \text{ 的边割集}\}$ 为 $G$ 的**边连通度**。

**注**：如果 $G$ 不连通，$\lambda (G) = 0$，对平凡图，$\lambda (G) = 0,\lambda(K_n) = n – 1$。



引理：设E'是**非完全连通图** $G$ 的最小边割集,$\mathbf{G}-\mathbf{E}$ '的两个连通分支是 $\mathbf{G}_{1}, \mathbf{G}_{2}$，则存在 $u \in V\left(\mathbf{G}_{1}\right), \mathbf{v} \in \mathbf{V}\left(\mathbf{G}_{2}\right)$, 使得 $(\mathrm{u}, v) \notin \mathbf{E}(\mathrm{G})$.

> 这里说的是这两个点之间原本就没有边！去掉E’之后肯定没有！

证明：反证法

否则$\lambda(\mathrm{G})=\left|\mathrm{E}^{\prime}\right|=\left|\mathrm{V}\left(\mathrm{G}_{1}\right)\right| \times\left|\mathrm{V}\left(\mathrm{G}_{2}\right)\right|$$\geq\left|V\left(G_{1}\right)\right|+\left|V\left(G_{2}\right)\right|-1=n-1$,与G是非完全图矛盾！

> $a \geq 1 \wedge b \geq 1 \Rightarrow(a-1)(b-1) \geq 0$$\Leftrightarrow a b-a-b+1 \geq 0 \Leftrightarrow a b \geq a+b-1$



**定义**：如果 $\kappa(G) \ge h$，则称 $G$ 是 $h-$ 连通的；如果 $\lambda (G) \ge f$，则称 $G$ 是 $f-$ 边连通的。

**结论 1**：$n$ 阶完全图是 $(n – 1) – $ 连通的。

**结论 2**：若 $h_1 > h_2$，则 $h_1 -$ 连通图 $G$ 是 $h_2 -$ 连通的；若 $f_1 > f_2$，则 $f_1 -$ 边连通图 $G$ 是 $f_2 -$ 边连通的。

**定理 1**：设图 $G$ 是 $h -$ 连通的，则 $G$ 的每个顶点的度均 $\ge h$。

**定理 2**：设图 $G$ 是 $h -$ 连通的，$v$ 是 $G$ 中的一 个顶点，则 $G – v$ 是 $(h – 1) -$ 连通的。

例：彼得森图: $\kappa=3, \lambda=3$

我们也可以发现，对3-正则图G，$\kappa(\mathbf{G})=\lambda(\mathbf{G})$





**Whitney定理**：$G$ 是无向图，则 $\kappa(G) \le \lambda(G) \le \delta(G)$。

推论：$k$-连通图一定是k-边连通图

证明：不妨设G是3阶以上连通非完全简单图（否则可以直接验证结论成立）

第一部分：$\lambda \leq \delta$

![image-20211026003049835](graph%20theory.assets/image-20211026003049835.png)

> 即找到最小度那里特殊的点

第二部分：$\kappa \leq \lambda$

![image-20211026003500021](graph%20theory.assets/image-20211026003500021.png)

![image-20211026003509572](graph%20theory.assets/image-20211026003509572.png)

![image-20211026003609264](graph%20theory.assets/image-20211026003609264.png)

# 图的矩阵表示



**邻接矩阵**

设 $\mathrm{D}=<\mathrm{V}, \mathrm{E}>$ 是有向图, $\mathrm{V}=\left\{\mathrm{v}_{1}, \mathrm{v}_{2}, \ldots, \mathrm{v}_{\mathrm{n}}\right\}$，

邻接矩阵（adjacency matrix）：$A(D)=\left[a_{i j}\right]_{n \times n}$，$\mathrm{a}_{\mathrm{ij}}=$ 从 $\mathrm{v}_{\mathrm{i}}$ 到 $\mathrm{v}_{\mathrm{j}}$ 的长度为 1 的边数/通路数

![image-20211026005935939](graph%20theory.assets/image-20211026005935939.png)

> 行为起点，列为终点。

**性质**：

1. 每行和为出度: $\sum_{\mathrm{j}=1}^{\mathrm{n}} \mathrm{a}_{\mathrm{ij}}=\mathrm{d}^{+}\left(\mathbf{v}_{\mathrm{i}}\right)$

2. 每列和为入度: $\Sigma_{\mathrm{i}=1}^{\mathrm{n}} \mathrm{a}_{\mathrm{ij}}=\mathrm{d}^{-}\left(\mathrm{v}_{\mathrm{j}}\right)$

3. 握手定理: $\sum_{\mathrm{i}=1}^{\mathrm{n}} \sum_{\mathrm{j}=1}^{\mathrm{n}} \mathrm{a}_{\mathrm{ij}}=\sum_{\mathrm{i}=1}^{\mathrm{n}} \mathrm{d}^{-}\left(\mathrm{v}_{\mathrm{j}}\right)=\sum_{\mathrm{i}=1}^{\mathrm{n}} \mathrm{d}^{+}\left(\mathbf{v}_{\mathrm{j}}\right)=\mathrm{m}$

   > 注意是m而不是2m！有一出一入的关系！

4. 环个数: $\sum_{\mathrm{i}=1}^{\mathrm{n}} \mathrm{a}_{\mathrm{ii}}$

**定理**：设 $G = \langle V,E \rangle$ 是简单图，令 $V=\{v_1,v_2,\cdots,v_n\}$，$G$ 的邻接矩阵 $(A(G))^k$ 中的第 $i$ 行第 $j$ 列元素${a_{ij}}^k=m$，表示在图 $G$ 中从 $v_i$ 到 $v_j$ 长度为 $k$ 的路有 $m$ 条。

证明：从定义入手

$A^{2}=A \cdot A$

$a_{i j}^{(2)}=\Sigma_{k} a_{i k} a_{k j}$，所以是从$a_{i} \rightarrow a_{k}$，再从$a_{k} \rightarrow a_{j}$

设$A(D)=A=\left[a_{i j}\right]_{n \times n}, A^{r}=A^{r-1} \bullet A,(r \geq 2)$，$B_{r}=A+A^{2}+\ldots+A^{r}=\left[b^{(r)}_{i j}\right]_{n \times n}$

则：

- $ \mathrm{a}^{(r)}{\mathrm{ij}}=$ 从 $\mathrm{v}_{\mathrm{i}}$ 到 $v_{\mathrm{j}}$ 长度为r的通路总数
- $\Sigma_{\mathrm{i}=1}^{\mathrm{n}} \Sigma_{\mathrm{j}=1}^{\mathrm{n}} \mathrm{a}^{(r)}{\mathrm{ij}}=$ 长度为 $r$ 的通路总数
- $\sum_{{ }{n}=1} a^{(r)}_{i i}=$ 长度为r的回路总数
- $b^{(r)}_{i j}=$ 从 $v_{i}$ 到 $v_{j}$ 长度 $\leq r$ 的通路总数
- $\sum_{\mathrm{i}=1}^{\mathrm{n}} \sum_{\mathrm{j}=1}^{\mathrm{n}} \mathbf{b}^{(\mathrm{r})} \mathrm{ij}=$ 长度 $\leq \mathrm{r}$ 的通路总数
- $\sum_{{ }{n}=1} b^{(r)}_{\mathrm{ii}}=$ 长度 $\leq \mathrm{r}$ 的回路总数

更为严谨的证明可以仿照上边的“从定义入手”，运用数学归纳法即可得。

**无向图邻接矩阵**：

设 $G=<V, E>$ 是无向简单图, $V=\left\{v_{1}, v_{2}, \ldots, v_{n}\right\}$，邻接矩阵（adjacency matrix）：$A(G)=\left[a_{i j}\right]_{n \times n}$,$\mathrm{a}_{\mathrm{ii}}=0$，$a_{i j}=\left\{\begin{array}{l}1, v_{i} 与 v_{j} \text { 相邻, } i \neq j \\ 0, v_{i} \text { 与 } v_{j} \text { 不相邻 }\end{array}\right.$

> 无向图邻接矩阵是一个对称矩阵

![image-20211026013900698](graph%20theory.assets/image-20211026013900698.png)

性质：

- 每行(列)和为顶点度: $\sum_{\mathrm{i}=1}^{\mathrm{n}} \mathrm{a}_{\mathrm{ij}}=\mathrm{d}\left(\mathrm{v}_{\mathrm{j}}\right)$
- 握手定理: $\sum_{\mathrm{i}=1}^{\mathrm{n}} \sum_{\mathrm{j}=1}^{\mathrm{n}} \mathrm{a}_{\mathrm{ij}}=\Sigma_{\mathrm{i}=1}^{\mathrm{n}} \mathrm{d}\left(\mathbf{v}_{\mathrm{j}}\right)=2 \mathrm{~m}$

设$A(D)=A=\left[a_{i j}\right]_{n \times n}, A^{r}=A^{r-1} \bullet A,(r \geq 2)$，$B_{r}=A+A^{2}+\ldots+A^{r}=\left[b^{(r)}_{i j}\right]_{n \times n}$

- $\mathbf{a}^{(r)}_{\mathrm{i} \mathrm{j}}=$ 从 $\mathbf{v}_{\mathrm{i}}$ 到 $\mathrm{v}_{\mathrm{j}}$ 长度为r的通路总数且$\sum_{\mathrm{i}=1}^{\mathrm{n}} \mathrm{a}^{(r)}{\mathrm{ii}}=$ 长度为 $r$ 的回路总数

- $\mathrm{a}^{(2)}{ }_{\mathrm{ii}}=\mathrm{d}\left(\mathrm{v}_{\mathrm{i}}\right)$

  因为$d\left(v_{i}\right)=\Sigma_{i} a_{i j}=\sum a_{i j} \cdot a_{j i}=a^{2} i i$

  中间那一步是为什么呢？

  因为

  1. $a_{i j}=a_{j i}$
  2. 矩阵元素要么是0，要么是1，而0乘0还是0，1乘1还是1

**可达性矩阵**

设 $G = \langle V,E \rangle$ 是个简单图，$V = \{v_1,\cdots,v_n\}$，一个 $n$ 阶矩阵 $P = (p_{ij})$ 称为 $G$ 的可达矩阵，其中：

$$
p_{ij} =
\left\{
\begin{array}{cc}
1 & v_i \text{ 到 } v_j \text{ 可达} \\
0 & \text{否则}
\end{array}
\right.
$$
**性质**：

- 主对角线元素都是1：$\forall v_{\mathrm{i}} \in \mathbf{V}$，从$v_i$可达$v_i$

- 强连通图：所有元素都是1

- 伪对角阵：对角块是连通分支的可达矩阵

  ![image-20211026013148900](graph%20theory.assets/image-20211026013148900.png)

- $\forall \mathbf{i} \neq \mathbf{j}, \mathbf{p}_{\mathrm{ij}}=1 \Leftrightarrow \mathbf{b}^{(\mathrm{n}-1)}_{\mathrm{ij}}>0$

  之前的定理：两点之间若有通路，则通路长度一定小于等于n-1；

![image-20211026013316734](graph%20theory.assets/image-20211026013316734.png)

无向图可达矩阵与有向图类似，区别：无向图可达矩阵一定都是对称的！

**求法**：

设 $|V(G)| = n$，记 $A^{(k)}$ 为将 $A^k$ 中非零元素改写为 $1$ 得到的 $01$ 矩阵。

则 $P = A \lor A^{(2)} \lor \cdots \lor A^{(n-1)} \lor I$。

可以用矩阵乘法求得 $A^{(k)}$，或者使用求传递闭包的 Warshall 算法。

这里， $\boldsymbol{A}^{\boldsymbol{i}}$ 表示做矩阵布尔乘法的i次幂, I为单位阵。

**关联矩阵（能表示重边，但不能表示环）**

1. 无向图的完全关联矩阵

   设 $G = \langle V,E \rangle$ 是个无向图，$V = \{v_1,v_2,\cdots v_n\}$。$E = \{e_1,e_2,\cdots,e_m\}$。

   一个 $n \times m$ 阶矩阵 $M = (m_{ij})$ 称为 $G$ 的**完全关联矩阵**，其中：
   $$
   m_{ij} =
   \left\{
   \begin{array}{cc}
   1 & v_i \text{ 与 } e_j \text{ 关联} \\
   0 & \text{否则}
   \end{array}
   \right.
   $$
   ![image-20211026005311590](graph%20theory.assets/image-20211026005311590.png)

   可以看出性质：

   1. 每列只有两个 $1$。
   2. 每行 $1$ 的个数为对应结点的度数。
   3. 如果两列相同，则说明对应的两条边是平行边。
   4. $\sum_{\mathrm{i}=1}^{\mathrm{n}} \Sigma_{\mathrm{j}=1}^{\mathrm{m}} \mathrm{m}_{\mathrm{ij}}=2 \mathrm{~m}$

2. 有向图的完全关联矩阵

   设 $G = \langle V,E \rangle$ 是个有向图，$V = \{v_1,v_2,\cdots v_n\}$。$E = \{e_1,e_2,\cdots,e_m\}$。

   一个 $n \times m$ 阶矩阵 $M = (m_{ij})$ 称为 $G$ 的**完全关联矩阵**，其中：
   $$
   m_{ij} =
   \left\{
   \begin{array}{cc}
   1 & v_i \text{ 是 } e_j \text{ 的起点} \\
   -1 & v_i \text{ 是 } e_j \text{ 的终点} \\
   0 & v_i \text{ 与 } e_j \text{ 不关联}
   \end{array}
   \right.
   $$
   ![image-20211026005542219](graph%20theory.assets/image-20211026005542219.png)

   可以看出性质：
   
   1. 每列只有一个 $1$ 和 $-1$。
   2. 每行中 $1$ 的个数为对应结点的出度，$-1$ 个数为对应结点的入度。
   3. $\sum_{\mathrm{i}=1}^{\mathrm{n}} \Sigma^{\mathrm{m}}_{\mathrm{j}=1} \mathrm{~m}_{\mathrm{ij}}=0$



思考：有向简单图的单向连通性与弱连通性如何通过A（邻接）、P（可达）矩阵来判断？

- 单向：若$P \lor P^T$全为1，则单向连通。即：要么有i到j的通路，要么有j到i的通路
- 弱连通：$A^{\prime}=A \lor A^{\top}$. $A^{\prime}$ 即为其对应的基图，判断其连通性即可。



**带权图的最短路问题**

带权图（赋权图）

设 $G = \langle V,E,W \rangle$ 是个图，如果 $G$ 的每条边 $e$ 上都标有实数 $w(e) \in W$，称这个数为边 $e$ 的**权**，称此图为**赋权图**。

**规定**：$u,v \in V$，边 $(u,v)$ 的权记为 $w(u,v)$：

1. $w(u,u) = 0$；
2. 如果 $u,v$ 之间无边相连，$w(u,v) = \infty$。

**带权图的路的权**：设 $P$ 是 $G$ 中一条路，定义路 $P$ 的权为：
$$
w(P) = \sum_{e \in P} w(e)
$$

**最短路问题**

在赋权图中求一条从给定的一点 $u$（始点）到另一点 $v$（终点）的路 $P$，使 $P$ 是所有 $u – v$ 路中权最小的，称 $P$ 为从 $u$ 到 $v$ 的**最短路**。

**带权图的两点间距离**

结点 $u$ 与 $v$ 之间的最短路的长称为**结点 $u$ 与 $v$ 之间的距离**，记作 $d(u,v)$。

如果 $G$ 是有向带权图，称为结点 $u$ 到 $v$ 的距离,记作 $d\langle u,v \rangle$。

# 欧拉图、哈密顿图与二部图

### 欧拉图

**欧拉迹（欧拉通路）**

在无孤立结点的图 $G$ 中，如果存在一条路，它经过图中每条边一次且仅一次，称此路为**欧拉迹**。

有欧拉通路的图称为半欧拉图

**欧拉回路**

在无孤立结点的图 $G$ 中，若存在一条回路，它经过图中每条边一次且仅一次，称此回路为**欧拉回路**。

称此图为**欧拉图**，或 **E 图**（Euler）。

> 定义平凡图为欧拉图

> 如果仅用边来描述，欧拉通路和欧拉回路就是图中所有边的一种全排列。

![image-20211026081738616](graph%20theory.assets/image-20211026081738616.png)

**无向欧拉图的充分必要条件**

**定理**：一个非空连通图（可以是多重图）是欧拉图当且仅当它不含奇数度的点。

**证明**：![image-20211026063510196](graph%20theory.assets/image-20211026063510196.png)

还可以推导出一个结论：G中所有顶点都是偶数度$\Leftrightarrow$G是若干个边不交的圈的并

证明：

$\Rightarrow$：若删除任意1个圈上的边,则所有顶点的度还是偶数, 但是不一定连通了. 对每个连通分支重复进行

$\Leftarrow$：可以证明有欧拉回路。有公共点但边不交的简单回路，总可以拼接成欧拉回路：在交点处，走完第一个回路后再走第二个回路。

**推论**：一个连通图 $G$ 有欧拉迹当且仅当 $G$ 最多有两个奇点。（无向半欧拉图的充分必要条件）

**证明**：前推后显然，后推前考虑将两个奇点之间连一条边，即可获得一条欧拉回路，再去掉这条边即得欧拉迹。

**注**：欧拉路与欧拉回路问题，也称一笔画问题。

**定理 2**：一个有向图 $D$ 具有欧拉迹，当且仅当 $D$ 是连通的，且除了两个顶点外，其余顶点的入度均等于出度。这两个特殊的顶点中一个顶点的入度比出度大 $1$，另一个顶点的入度比出度小 $1$。

**求欧拉回路算法**

**Fleury算法（避桥法）**

- 从任意一点开始，沿着没有走过的边向前走。
- 在每个顶点，优先选择剩下的**非桥边**，除非只有唯一一条边
- 直到得到欧拉回路或者宣布失败。

定理：设G是无向欧拉图，则Fleury算法终止时得到的简单通路是欧拉回路。

**逐步插入回路算法**

- 每次求出一个简单回路
- 然后回溯到上一个有边没有被遍历到的顶点
- 把新求出的回路插入到老回路，合并成一个更大的回路
- 直到得到欧拉回路或者宣告失败。

例题：

甲、乙两只蚂蚁分别位于图的结点A、B 处, 并设图中的边长度相等。甲、乙进行比赛： 从它们所在的结点出发, 走过图中所有边 最后到达结点C处。如果它们的速度相同， 问谁先到目的地C点?

![tmp3B0B](graph%20theory.assets/tmp3B0B.png)

应该是B先到达。分析节点度数，B到C走的是欧拉通路，但A到C肯定要走重复的边。

### 哈密顿图

哈密顿问题：用一个十二面体代表地球，用它的二十个顶点分别代表世界上的二十个城市。要求沿十二面体的棱，走过每个城市一次且仅仅一次，最后回到出发点。

设 $G = \langle V,E \rangle$ 是个无向有限图。

**哈密顿路**：通过 $G$ 中每个结点恰好一次的路。（经过图中所有顶点的**初级**通路）

**哈密顿回路（H 圈）**：通过 $G$ 中每个结点恰好一次的路。

**半哈密顿图**:有哈密顿通路的图

**哈密顿图（H 图）**：具有哈密顿回路（H 全）的图。

设 $G$ 是多重图，$G’$ 是去掉 $G$ 中的多重边和环后得到的图，显然若 $G’$ 是 H 图，则 $G$ 也是 H 图，因此，只需讨论简单图。

> 定义平凡图为哈密顿图

> 如果仅用点来描述，哈密顿通路就是图中所有结点的一种全排列；

**哈密顿图的判定**

**定理1（必要条件）**：设 $G=<V, E>$ 是无向哈密顿图, 则对 $V$ 的任意非空真子集 $V_{1}$ 有 $p\left(\mathrm{G}-\mathrm{V}_{1}\right) \leq\left|\mathrm{V}_{1}\right|$

证明：

设C是G中任意哈密顿回路，当$V_1$中顶点在C中都不相邻时，$p\left(C-V_{1}\right)=\left|V_{1}\right|$ 最大。

若 $\mathbf{V}_{1}$ 中顶点相邻, $p\left(\mathrm{C}-\mathrm{v}_{1}\right)<\left|\mathrm{V}_{1}\right|$ ,$ \mathrm{C}$ 是G的生成子图,所以 $p\left(\mathrm{G}-\mathbf{V}_{1}\right) \leq \mathbf{P}\left(\mathrm{C}-\mathrm{V}_{1}\right) \leq\left|\mathrm{V}_{1}\right|$

> 相当于$v_1$作为分割点把它们全分开了。（若只考虑欧拉回路那个圈的话，中间有弦的话不过是更小了而已。
>
> ![image-20211026065527244](graph%20theory.assets/image-20211026065527244.png)

> p（G）：G的连通分支数

推论：设 $G=<V, E>$ 是无向半哈密顿图,则对 $V$ 的任意非空真子集 $V_{1}$ 有
$$
\mathbf{p}\left(\mathbf{G}-\mathbf{V}_{1}\right) \leq\left|\mathbf{V}_{1}\right|+1
$$
![image-20211026065640224](graph%20theory.assets/image-20211026065640224.png)



判断是否是哈密顿图：寻找子集 $V_{1}$ 使得 $p\left(G-V_{1}\right)>\left|V_{1}\right|$。尝试的过程就是一个“删点”的过程，而删点的时候先要删度数更高的。

![image-20211026065750223](graph%20theory.assets/image-20211026065750223.png)

![image-20211026065801618](graph%20theory.assets/image-20211026065801618.png)

非充分条件的反例：

![image-20211026065821149](graph%20theory.assets/image-20211026065821149.png)

**定理（充分条件）**：$G$ 是至少有 $3$ 个点的完全图，则 $G$ 是 $H$ 图。

**定理(充分条件)** ：$G$ 是简单图，且 $n \ge 2$，若对 $G$ 中任一对不相邻点 $u,v$，都有 $d(u) + d(v) \ge n-1$ . 则 $G$ 是半哈密顿图。

只需证明：

1. G连通

   $\forall u, \forall v \quad(\mathbf{u}, \mathbf{v}) \notin \mathbf{E} \rightarrow \exists \mathbf{w}((\mathbf{u}, \mathbf{w}) \in \mathrm{E} \wedge(\mathbf{w}, \mathbf{v}) \in \mathbb{E})$

   > 去掉u、v两个点，还剩下n-2个点。而度数和大于等于n-1，故至少一点与u、v均相连。

   

2. 由极大路径可得圈

   设极大路径 $\Gamma=\mathrm{v}_{0} \mathrm{v}_{1} \ldots \mathrm{v}_{\mathrm{k}}, \mathrm{k} \leq \mathrm{n}-\mathbf{2} .$ 若 $\left(\mathrm{v}_{0}, \mathrm{v}_{\mathrm{k}}\right) \notin \mathrm{E}$, 则$\exists i\left(1 \leq i \leq k-1 \wedge\left(v_{i}, v_{k}\right) \in E \wedge\left(v_{0}, v_{i+1}\right) \in E\right)$，否则$\mathrm{d}\left(\mathrm{v}_{0}\right)+\mathrm{d}\left(\mathrm{v}_{\mathrm{k}}\right)\leq \mathrm{d}\left(v_{0}\right)+k-1-\left(d\left(v_{0}\right)-1\right)=k \leq n-2 \mid$（矛盾）。于是得圈 $C=v_{0} \ldots v_{i} v_{k} v_{k-1} \ldots v_{i+1} v_{0}$。

   ![image-20211026070501220](graph%20theory.assets/image-20211026070501220.png)

   > 若$v_0$、$v_k$相连，则直接可得。
   >
   > 而$v_0$、$v_k$确定的极大路径，只与路径上的点相邻。路径上除了$v_0$、$v_k$还有k-1个点。使用反证法，假设与$v_0$相连的点和与$v_k$相连的点均不相邻。极限情况：极大路径中与$v_0$、$v_k$相连的点分别聚在两侧，可得如上不等式。

   

3. 由圈可得更长路径

   ![image-20211026070720204](graph%20theory.assets/image-20211026070720204.png)

   

推论1（无向哈密顿图的充分条件一）：设 $G$ 是 $n(\geq 3)$ 阶无向简单图,若对G中任意不相邻的顶点u与v有：$\mathrm{d}(\mathrm{u})+\mathrm{d}(\mathrm{v}) \geq \mathrm{n}$，则G是哈密顿图。

证明：由上述定理，G连通且有哈密顿通路$\Gamma=v_{0} v_{1} \ldots v_{n-1}$。

若$\left(v_{0}, v_{n-1}\right) \in E$，则可得哈密顿回路

若$\left(v_{0}, v_{n-1}\right) \in E$，则证明与上述定理中“由极大路径可得圈”证明类似。

故存在哈密顿回路。

**推论2（无向哈密顿图的充分条件之二）**：设G是 $n(\geq 3)$ 阶无向简单图,若对G中任意顶点u有$\mathbf{d}(\mathrm{u}) \geq \mathrm{n} / 2$，则G是哈密顿图。

定理：设u,v是无向n阶简单图G中两个不相邻顶点且 $\mathrm{d}(\mathrm{u})+\mathrm{d}(\mathrm{v}) \geq \mathrm{n}$, 则G是哈密顿图 $\Leftrightarrow$ $\mathbf{G} \cup(\mathbf{u}, \mathbf{v})$ 是哈密顿图.

> 这个和前述定理不同，这里的u、v不是任意的。且反向条件用的较多。

![image-20211026072003312](graph%20theory.assets/image-20211026072003312.png)

![image-20211026081945298](graph%20theory.assets/image-20211026081945298.png)

**有向半哈密顿图的充分条件**：设D是n $(\geq 2$ )阶竞赛图, 则D是半哈密顿图.

推论：设D是n阶有向图，若D含n阶竞赛图作为子图，则D是半哈密顿图。

证明：对n作归纳法。

当n=2时，D的基图为 $K_{2}$, 结论成立

设n=k时结论成立，验证n=k+1的情况。设 $V(D)=\left\{v_{1}, v_{2}, \ldots, v_{k}, v_{k+1}\right\}$，令 $D_{1}=D-v_{k+1}$, 易知D $_{1}$ 为 $k$ 阶竞赛图，由归纳假设可知, $D_{1}$存在哈密顿通路, 设 $\Gamma_{1}=v_{1}^{\prime} v_{2}^{\prime} \cdots v^{\prime} \ldots$ 为其中一条。下面证明$v_{\mathrm{k}+1}$ 可扩到 $\Gamma_{1}$ 中去.

若存在 $v_r^{\prime}(1 \leq r \leq k)$, 有$ < v_{i}^{\prime}, v_{k+1} >\in E(D), i=1,2, \ldots, r-1, \quad.$ 而 $<v_{k+1}, v_{r}^{\prime}>\in E(D)$,则 $\Gamma=v^{\prime}{ }_{1} v_{2}^{\prime} \ldots v_{r-1}^{\prime} v_{k+1} v_{r}^{\prime} \ldots v_{k}^{\prime}$ 为 $D$中哈密顿通路。

否则，$i \in\{1,2, \ldots, k\}$, 均有 $<v_{i}^{\prime}, v_{k+1}>\in E(D)$，则则 $\Gamma=\Gamma^{\prime} + <v^{\prime}, v_{k+1}>$ 为 D中哈密顿通路。

**有向哈密顿图的充分条件**：强连通的竞赛图是哈密顿图。

证明：

n=1时，平凡图是哈密顿图。n=2时，不可能强连通。下面设$n \geq 3$，只需证明：

1. D中存在长度为3的圈

   ![image-20211026073111452](graph%20theory.assets/image-20211026073111452.png)

   

2. D中存在长度为k的圈 $\Rightarrow$ D中存在长度为k+1的圈

   ![image-20211026073231511](graph%20theory.assets/image-20211026073231511.png)

   

# 树



一个连通无回路的无向图 $T$，称之为树。

**树叶**：度数为 $1$ 的结点，称为树叶。

**分支结点**：度数大于 $1$ 的结点。

**森林**：一个无向图的每个连通分支都是树，把这个图叫做森林。

> 平凡树：平凡图：无树叶、无分支点



**与树定义等价的几个命题：**设$\mathrm{T}=<\mathrm{V}, \mathrm{E}>$ 是 $\mathrm{n}$ 阶 $\mathrm{m}$ 边无向图,则

1. $T$ 是无回路的连通图。
2. $T$ 无环且每对结点之间有一条且仅有一条道路。
3. $T$ 是连通的，且每条边都是割边。
4. $T$ 是连通的且 $m = n – 1$。
5. $T$ 无回路且 $m = n – 1$。
6. T极大无回：$T$ 无回路但在任一对不相邻的顶点间添加一条新边 $e$，则 $T + e$ 包含唯一的圈。
7. T极小连通：连通且所有边是桥。

证明：

![image-20211026073835481](graph%20theory.assets/image-20211026073835481.png)

![image-20211026073843974](graph%20theory.assets/image-20211026073843974.png)

![image-20211026073858291](graph%20theory.assets/image-20211026073858291.png)

**树的特点**

在结点给定的无向图中，

- 树是边数最多的无回路图（极大无回）
- 树是边数最少的连通图（极小连通）

由此可知, 在无向图G (n阶m条边)中

- 若m $<n-1$, 则 $G$ 是不连通的
- 若 $m>n-1$ ，则G 必含回路

**定理 **：每一非平凡树至少有两片树叶。

证明：设T有x个树叶，则$2 m=2(n-1)=2 n-2=\sum d(v)$$=\Sigma_{\mathbf{v} \text { 是树叶 }} \mathbf{d}(\mathbf{v})+\Sigma_{\mathbf{v} \text { 是分支点 }} \mathbf{d}(\mathbf{v})$$\geq x+2(n-x)=2 n-x$，

所以$\mathbf{x} \geq \mathbf{2}$

![image-20211026082027123](graph%20theory.assets/image-20211026082027123.png)

**非同构无向树的枚举**



![image-20211026074454374](graph%20theory.assets/image-20211026074454374.png)

作图的时候应先列举出度数列。



**星**

星：$\mathrm{S}_{\mathrm{n}}=\mathrm{K}_{1, \mathrm{n}-1}$

> 这里的k表示完全r部图

![image-20211026074850649](graph%20theory.assets/image-20211026074850649.png)

**生成树**：如果图 $G$ 的生成子图是树，则称此树为 $G$ 的生成树。

**树枝**：共n-1条

**弦**：图 $G$ 中，不在其生成树里的边，称作**弦**。所有弦的集合，称为该生成树的**余树**。共m-n+1条

**定理**：连通图 $G$ 至少有一棵生成树。

证明：用破圈法证明

推论：G是 $n$ 阶m边无向连通图 $\Rightarrow m \geq n-1$

推论：T是n阶m边无向连通图G的生成树 $\Rightarrow$$|E(\bar{T})|=m-n+1 .$

推论：T是无向连通图G的生成树, C是G中的圈 $\Rightarrow|E(\bar{T})| \cap|E(C)| \neq \varnothing$

证明：![image-20211026075547422](graph%20theory.assets/image-20211026075547422.png)

定理：设T是连通图G的生成树, $\mathbf{S}$ 是G中的割集, 则E( $\mathbf{T}) \cap \mathbf{S} \neq \varnothing$.

证明：![image-20211026075637977](graph%20theory.assets/image-20211026075637977.png)

![image-20211026075708940](graph%20theory.assets/image-20211026075708940.png)

![image-20211026075733128](graph%20theory.assets/image-20211026075733128.png)



设e为无向连通图G中一边：

- 若e在G的任何生成树中，则e是桥
- 若e不在G的任何生成树中，则e是环

**定理：**设G是连通图, T是G的生成树, $\mathrm{e}$ 是T的弦,则 $T \cup e$中存在由弦e和其他树枝组成的圈, 并且不同的弦对应不同的圈.

证明：设 $\mathrm{e}=(\mathrm{u}, \mathrm{v})$, 设 $\mathrm{P}(\mathrm{u}, \mathrm{v})$ 是 $\mathrm{u}$ 与 $\mathrm{v}$ 之间在T中的唯一路径, 则 $\mathrm{P}(\mathrm{u}, \mathrm{v}) \cup \mathbf{e}$ 是由弦 $\mathrm{e}$ 和其他树枝组成的圈.设 $e_{1}, e_{2}$ 是不同的弦,对应的圈是 $C_{e 1}, C_{e 2}$，则$\mathrm{e}_{1} \in \mathrm{E}\left(\mathrm{C}_{\mathrm{e} 1}\right)-\mathrm{E}\left(\mathrm{C}_{\mathrm{e} 2}\right), \mathrm{e}_{2} \in \mathrm{E}\left(\mathrm{C}_{\mathrm{e} 2}\right)-\mathrm{E}\left(\mathrm{C}_{\mathrm{e} 1}\right)$, 所以 $\mathrm{C}_{\mathrm{e} 1} \neq$
$\mathrm{C}_{\mathrm{e} 2}$

**定理（破圈法）**：设G是无向连通图, $G^{\prime} \subseteq \mathbf{G}, \mathbf{G}^{\prime}$ 无圈, 则G中存在 生成树T, $\mathbf{G}^{\prime} \subseteq \mathrm{T} \subseteq \mathbf{G}$.

证明：把圈一个个拆掉就成树了！

**基本回路**

设G是n阶m边无向连通图, T是G的生成树,$\overline{\mathrm{T}}=\left\{\mathrm{e}_{1}^{\prime}, \mathrm{e}_{2}^{\prime}, \ldots, \mathrm{e}_{\mathrm{m}-\mathrm{n}+1}^{\prime}\right\}$

- 基本回路：$T\cup e_r^{\prime}$中的唯一回路 $C_{r}$
- 基本回路系统：$\left\{C_{1}, C_{2}, \ldots, C_{m-n+1}\right\}$
- 圈秩$\xi(G): \xi(G)=m-n+1$

![image-20211026080953981](graph%20theory.assets/image-20211026080953981.png)

定理：设G是连通图，T是G的生成树，e是T的树枝，则G中存在由树枝e和其他弦组成的割集，并且不同树枝对应不同的割集。

![image-20211026081136391](graph%20theory.assets/image-20211026081136391.png)

**基本割集**

![image-20211026081202337](graph%20theory.assets/image-20211026081202337.png)

![image-20211026081249759](graph%20theory.assets/image-20211026081249759.png)

![image-20211026081300898](graph%20theory.assets/image-20211026081300898.png)







# 待整理



#### 中国邮递员问题

一个邮递员送信，每次要走遍他负责投递范围内的街道，然后再回到邮局。问他应该按怎样的路线走，使所走的路程最短？

如果用点表示交叉路口，用点之间的连线表示对应的街道，每条线上对应一个实数，它是相应街道的长度。原问题变成一个图论问题。

**中国邮递员问题**：在赋以非负权的连通图 $G$ 上，求一条最小权环游。

**环游**：经过一个图 $G$ 的每条边至少一次的闭回路。

**求解**：

若 $G$ 中每个点的度为偶数，$G$ 为欧拉图，则 $G$ 中的欧拉回路是最优环游。

若 $G$ 不是欧拉图，则 $G$ 的任何环游，包括 $G$ 的最优环游，通过某些边将超过一次。

则问题变为：给出一个连通图 $G$。

1. 求 $E_1 \subseteq E$ 满足条件：在 $G$ 中重复 $E_1$ 中每条边，使得到的图 $G^*$ 是欧拉图（称这样的 $E_1$ 为可行集）。并且使 $E_1$ 的权尽可能小（称这样的可行集 $E_1$ 为最优集）。
2. 求 $G^*$ 的欧拉回路.。

**定理**：$L$ 是无向连通图 $G$ 最佳邮路（最优环游）的充要条件是：

1. $G$ 的每条路最多重复一次。
2. 在 $G$ 的任意一个回路上，重复边长度之和不超过该回路长度的一半。

**特例**：若 $G$ 恰好含两个奇点，则只需要重复此二奇点之间的最短路即可。













![122](graph%20theory.assets/122-163505366772827.png)

**引理 1**：设 $u,v$ 是 $G$ 的一对不相邻点，$d(u)+d(v) \ge n$。若 $G + uv$ 是 H 图 $\Leftrightarrow G$ 是 H 图。

![123](graph%20theory.assets/123-163505366772829.png)

**定理 3**：$G$ 是 H 图 $\Leftrightarrow C(G)$ 是 H 图。

**定理 4**：若 $C(G)=K_n \Leftrightarrow G$ 是 H 图。

**定理 5**：$G$ 是简单图，且 $n \ge 3, \delta \ge \frac{n}{2}$，则 $G$ 是 H 图。

**定理 6**：$G$ 是简单图，且 $n \ge 2$，若对 $G$ 中任一对不相邻点 $u,v$，都有 $d(u) + d(v) \ge n – 1$，则 $G$ 有 H 路。

![124](graph%20theory.assets/124-163505366772831.png)

利用此定理可得定理 2 另一种证明：

![125](graph%20theory.assets/125-163505366772833.png)

**定理 7（必要条件）**：若图 $G = \langle V,E \rangle$ 有 H 圈，则对 $V$ 的任何非空子集 $S$，均有 $W(G – S) \le |S|$，其中 $W(G – S)$ 是从 $G$ 中删去 $S$ 中所有结点及与这些结点关联的边所得到的子图的连通分支数。

![126](graph%20theory.assets/126-163505366772835.png)

**定理 8**：若 $G$ 是 Hamilton 圈 $\Rightarrow G$ 是 $2-$ 连通。

#### 旅行商问题

H 圈问题不涉及边的长度，但是在许多实际问题中，每条边都可以有它的权。

**旅行商问题（TSP）**：一个商人欲到 $n$ 个城市推销商品，每两个城市 $i$ 和 $j$ 之间的距离为 $d_{ij}$，如何选择一条道路使得商人每个城市走一遍后回到起点，且所走路径最短。

**图论语言**：给定一个赋正权的完全图，求具有总长最短的 H 圈。

这个问题是 NPC 问题，一种好的精确求解法是分支与界法。

### 二部图

#### 二部图

令 $G = \langle V,E \rangle$ 是无向图，如果可以将 $V$ 划分成两个子集 $V_1,V_2$，使得任何边 $(v_i,v_j) \in E$，$v_i \in V_1,v_j \in V_2$，则称 $G$ 是**二部图**，也称**二分图**，称 $V_1,V_2$ 是 $G$ 的互补的顶点子集。

#### 完全二部图

令 $G = \langle V,E \rangle$ 是以 $V_1,V_2$ 为互补的顶点子集的二部图，如果 $V_1$ 中的每个节点都与 $V_2$ 中每个结点相邻接，则称 $G$ 是完全二部图。如果 $|V_1| = m,|V_2| = n$，则 $G$ 记作 $K_{m,n}$。

#### 二部图的判定

**定理**：$G = \langle V,E \rangle$ 是二部图，当且仅当它的所有回路的长度都是偶数。

![127](graph%20theory.assets/127-163505366772837.png)

# 树和平面图









#### 赋权图的最小生成树

一棵生成树中的所有边的权之和称为**该生成树的权**。

具有最小权的生成树，称为**最小生成树**。

#### 求最小生成树算法——Kruskal 算法（贪婪、贪心）

![129](graph%20theory.assets/129.png)

**正确性证明**：

![130](https://wzf2000.top/wordpress/wp-content/uploads/------------/------------------/130.png)

### 根树及其应用

#### 有向树

如果 $G$ 是个有向图，且若不考虑边的方向时（即看成无向图时），是一棵树，则称 $G$ 是有向树。

#### 根树

如果一棵有向树，恰有一个结点的入度为$0$，其余所有结点的入度均为 $1$，则称此树为根树。

**树根**：入度为 $0$ 的结点。

**叶**：出度为 $0$ 的结点。

**分支结点（内结点）**：出度不为 $0$ 的结点。

**父结点与子结点**：如果 $\langle v_i,v_j \rangle$ 是根树中的一条边，则称 $v_i$ 是 $v_j$ 的**父结点**，$v_j$ 是 $v_i$ 的**子结点**。

**祖先结点与后裔结点**：在根树中，如果从 $v_i$ 到 $v_j$ 有路，则称 $v_i$ 是 $v_j$ 的**祖先结点**，$v_j$ 是 $v_i$ 的**后裔结点**。

**根树结点的层次**：从根结点到某个结点的路径的长度，称为该结点的**层次**。同一层次的结点称为**兄弟结点**。

**树高**：从树根到各个叶结点的路径中，最长路径的长度，称为**该树的高度（树高）**。

#### $m$ 叉树与完全 $m$ 叉树

**$m$ 叉树**：在根树中，如果每个结点的出度最大是 $m$，则称此树是 $m$ 叉树。

**完全 $m$ 叉树**：在根树中，如果每个结点的出度都是 $m$ 或者等于 $0$，则称此树是完全 $m$ 叉树。

**正则 $m$ 叉树**：在完全 $m$ 叉树中，如果所有树叶的层次相同，则称之为正则 $m$ 叉树。

**定理**：$T$ 是棵完全 $m$ 叉树，有 $t$ 个叶结点，$i$ 个分支结点, 则 $(m – 1)i = t – 1$。

#### $m$ 叉有序树转化为二叉树

方法是：

1. 每个结点保留左儿子结点，剪掉右边其分支。被剪掉的结点如下处理（重新嫁接）。
2. 同一个层次的结点，从左到右依次画出（被剪掉的结点嫁接到它的哥哥结点上）。

![131](https://wzf2000.top/wordpress/wp-content/uploads/2019/12/------------/------------------/131.png)

### 最优树（哈夫曼树）

#### 带权二叉树的定义

设有一组权值：$w_1, w_2, w_3,\cdots , w_m$，不仿设 $w_1 \le w_2 \le w_3 \le \cdots \le w_m$，设有一棵二叉树有 $m$ 片叶子，分别带有权值 $w_1, w_2, w_3, \cdots, w_m$，称此树为**带权二叉树**。

#### 带权树 $T$ 的权 $W(T)$

$$
W(T) = \sum_{i = 1}^m w_i L(w_i)
$$

其中 $L(w_i)$ 是标有权 $w_i$ 的叶结点的从根到该叶结点的路长。

#### 最优树

带权树中，权数最少的二叉树。

#### 画最优树的算法——哈夫曼算法

1. 先将权按照升序排序,设为 $w_1 \le w_2 \le w_3 \le \cdots \le w_m$。
2. 以 $w_1$ 和 $w_2$ 为儿子结点，构造它们的父结点，且其权为 $w_1 + w_2$，并从权的序列中去掉 $w_1$ 和 $w_2$。
3. $w_1 + w_2$ 再与其余权一起排序，再从此队列中取出前面两个权值为儿子结点，同 2 的方法构造它们的父结点。
4. 依此类推，直至最后，即得到最优树。

#### 前缀码（哈夫曼编码）

**问题的提出**：数据通讯时，需要将信息编码，即用二进制符号串表示信息。

**前缀码定义**：一个符号的编码不是另一个符号编码的前缀。

**前缀码的设计**：每棵二叉树一一对应一组前缀码。

## 平面图

### 平面图

#### 定义

设 $G$ 是无向图，如果能将 $G$ 的所有结点和边都画在一个平面上，且使得任何两条边除了端点外没有其它交点，则称 $G$ 是个**平面图**。

画出的没有边交叉出现的图，称为 $G$ 的**平图**。

一个图表面上是个非平面图，如果通过改变边的位置就变成平面图，称此图是**可平面化的**。

#### 定理

**Jordon 曲线**：一条连续的，自身不相交的，起点和终点相重合的曲线。

平面图的圈中各条边的并集构成一条 Jordon 曲线。

设 $J$ 是平面上的一条 Jordon 曲线，平面的剩下部分被分成两个不相交的开集，称为 $J$ 的内部和外部，分别记为 $\mathrm{int} J$ 和 $\mathrm{ext} J$，并且用 $\mathrm{Int} J$ 和 $\mathrm{Ext} J$ 表示它们的闭包。显然 $\mathrm{Int} J \cap \mathrm{Ext} J = J$。

**Jordon 曲线定理**：连接 $\mathrm{int} J$ 的点和 $\mathrm{ext} J$ 的点的任何连线必在某点和 $J$ 相交。

### 对偶图

#### 平面图的面、边界及面的度数

设 $G$ 是个平面图，图中边围成的区域，其内部不含有结点，也不含有边，称这样区域为 $G$ 的一个**面**。

**面的边界**：围成一个面 $f$ 的所有边构成的回路，称之为这个 **$f$ 面的边界**。

此回路中的边数，称之为面 $f$ 的**度数**，记作 $d(f)$。

$F(G)$：平面图 $G$ 中**面的集合**。

$r(G) = |F(G)|$，**面的个数**。

#### 对偶图的定义

给定平面图 $G = \langle V,E \rangle$，可以定义另一个图 $G^* = \langle V^*,E^* \rangle$，如下：

1. 对于 $G$ 中的每个面 $f$，都有 $G^*$ 的点 $f^*$ 与之对应。
2. 对于 $G$ 中的每条边 $e$，都有 $G*$ 的边 $e^*$ 与之对应。
3. $G^*$ 中的点 $f^*$ 与 $g^*$ 被边 $e^*$ 相连 $\Leftrightarrow G$ 中的面 $f$ 和 $g$ 被 $e$ 分隔。

图 $G^*$ 称为图 $G$ 的**对偶图**。

#### 对偶图的性质

1. $G^*$ 是唯一的，且 $G^*$ 是连通的。
2. $G^*$ 是平面图。
3. 若 $G$ 是平面连通图，则 $(G^*)^* = G$。
4. $m(G^*) = m(G),n(G^*) = r(G)$。

$d(v^*) = d(f)$。

**定理**：若 $G$ 是平面图，则：
$$
\sum_{f \in F} d(f) = 2m
$$
**证明**：即等于其对偶图边数。

#### 欧拉公式——关于点，边和面的数目的简单公式

$G$ 是个连通的平面图，设 $n,m,r$ 分别表示 $G$ 中结点数、边数、面数，则有 $n – m + r = 2$。

![132](https://wzf2000.top/wordpress/wp-content/uploads/------------/------------------/132.png)

**推广**：对任意 $p(p \ge 1)$ 个连通分支的平面图 $G$ ，有 $n – m + r = p + 1$。

**推论**：对任意平面图，有 $n – m + r \ge 2$。

#### 由欧拉公式得到的推论

**推论 1**：若 $G$ 是 $n\ge 3$ 的简单（连通）平面图，则 $m \le 3n – 6$。

**推论 2**：若 $G$ 是简单连通平面图，则 $\delta \le 5$。

**推论 3**：$K_{3,3}$ 是非平面图。

![133](graph%20theory.assets/133.png)

### 五色定理和四色定理

#### 相关名词

**地图**：没有桥的连通平面图。

**地图着色**：在平面或球面上的地图，为使相邻两个国家（或地区）便于区分，必须对这两个国家（或地区）着以不同的颜色，那么一个具体的区域图至少要用多少种颜色才够呢？

**四色猜想**：每个平面图是四面可着色的。

#### 顶点着色

图 $G$（可以是任意的图）的正常着色（简称着色）：

- $k$ 顶点着色：$k$ 种颜色对图 $G$ 的顶点的一个分配。
- $k$ 顶点着色是正常的（或 $k$ 顶点可着色），简称 $k-$ 可着色：若 $G$ 中任意两个相邻的顶点都分配到不同的颜 色。
- 对 $G$ 着色时，需要的最少颜色数，称为 $G$ 的着色数，记作 $x(G)$。

#### 结论

- $G$ 是 $k-$ 可着色的，相当于把 $G$ 的顶点分成 $k$ 个独立集的一个分类 $(V_1, V_2, \cdots, V_k)$。
- $G$ 是 $k-$ 色的 $\Leftrightarrow G$ 的简单图是 $k-$ 色的。
- 一个简单图的 $x(G) = 1 \Leftrightarrow G$ 是空图。
- 一个简单图的 $x(G) = 2 \Leftrightarrow G$ 是二部图。
- $G$ 是完全图 $K_n$，则 $x(G) = n$。
- $G = K_n-e$，则 $x(G) = n – 1$。
- $G = C_n$，则当 $n$ 为偶数时，$x(G) = 2$；当 $n$ 为奇数时，$x(G) = 3$。

#### 对G着色方法（介绍韦尔奇.鲍威尔法）

具体步骤：

1. 将图中所有点按度数大小递减排列（此排列可能不唯一，因为可能有些结点的度数相同）。
2. 用第一种颜色对第一个点（度数最大的点）着色，并且按排列顺序对与前面着色点不相邻的每个点着上同样的颜色。
3. 用第二种颜色对尚未着色的点重复步骤。
4. 用第三种颜色继续这种做法，直到所有的点全部着上色为止。

#### 着色数相关的一个定理

**定理**：对任意图 $G$ ，有 $x(G) \le \Delta + 1$，其中 $\Delta$ 为 $G$ 中顶点的最大度。

![134](https://wzf2000.top/wordpress/wp-content/uploads/------------/------------------/134.png)

#### 五色定理

每个平面图都是 $5$ 顶点可着色的。

![135](https://wzf2000.top/wordpress/wp-content/uploads/------------/------------------/135.png)

![136](https://wzf2000.top/wordpress/wp-content/uploads/------------/------------------/136.png)

#### 面着色

**$k$ 面着色**：$k$ 种颜色给平面图 $G$ 的所有面的一个分配。

**正常的面着色**：若被一条边分隔的两个面分配以不同的颜色。

**$k$ 面可着色**：若 $G$ 有一个正常的 $k$ 面着色。

面色数 $x^*(G) =$ 使 $G$ 是 $k$ 面可着色的最小 $k$ 值，显然 $x^*(G) = x(G^*)$。

可以证明：每个平面图都是 $k$ 顶点可着色的 $\Leftrightarrow$ 每个平面图都是 $k$ 面可着色的。

**四色定理**：每个平面图是 $4$ 面可着色的。

#### 与四色定理相关结论

**定理 1**：如果平面图 $G$ 有哈密顿圈，则四色猜想成立。

![137](https://wzf2000.top/wordpress/wp-content/uploads/------------/------------------/137.png)

**定理 2**：连通平面图 $G$ 的面可 $2-$ 着色当且仅当 $G$ 中存在欧拉回路。

![138](https://wzf2000.top/wordpress/wp-content/uploads/------------/------------------/138.png)

#### 图的外可平面性（平面图的判断问题）

下面要介绍两个判定一个图是平面图的充分且必要条件，即 Kuratowski （库拉托斯基）定理。

在此之前先介绍两个**新运算**——插入或消去 $2$ 度点。

![139](https://wzf2000.top/wordpress/wp-content/uploads/------------/------------------/139.png)

**定义 1**：如果两个图 $G_1$ 和 $G_2$ 同构，或经过反复插入或消去 $2$ 度顶点后同构，则称 $G_1$ 和 $G_2$ 同胚。

**定义 2**：图 $G$ 中相邻顶点 $u, v$ 之间的初等收缩由下面方法给出：删除边 $(u, v)$，用新的顶点 $w$ 取代 $u, v$，使 $w$ 关联和 $u,v$ 关联的一切边（除 $(u, v)$ 外）。

**库拉图斯基定理**：一个图是平面图，当且仅当它不包含同胚于 $K_{3,3}$ 或 $K_5$ 的子图。

**另一种叙述形式**：一个图是平面图，当且仅当它没有可以收缩到 $K_{3,3}$ 或 $K_5$ 的子图。