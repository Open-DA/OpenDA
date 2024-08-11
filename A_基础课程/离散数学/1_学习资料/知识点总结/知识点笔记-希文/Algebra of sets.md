### 基本定义

**集合**

是一些确定的、可以区分的事物汇集在一起组成的一个整体。用大写的英文字母表示。

**元素**

集合中的每个事物，称之为元素。用小写英文字母表示 $\in$ 表示元素与集合的属于关系。

**有限集合与无限集合**

**有限集合**：元素是有限个的集合。

如果A是有限集合，用 $|A|$ 表示 $A$ 中元素个数。

**无限集合**：元素是无限个的集合

### 集合的表示方法

**列举法（外延表示法）**

将集合中的元素一一列出，元素之间用逗号分开，写在花括号内。

**描述法（谓词法）**

用句子（或谓词公式）描述元素的属性。

$A=\{x|P(x)\}$，其中 $P(x)$ 是谓词公式，如果论域内个体 $a$ 使得 $P(a)$ 为真，则 $a \in A$，否则 $a \not \in A $。

**特别说明**

1. 集合中的元素间次序是无关紧要的，但是必须是可以区分的。
2. 集合中的元素是各不相同的
3. 常用的几个集合符号的约定：
   1. 自然数集合 $\mathbb{N} = \{0,1,2,3,……\}$。
   2. 整数集合 $\mathbb{Z}$,其中包括正整数与负整数。
   3. 实数集合 $\mathbb{R}$。
   4. 有理数集合 $\mathbb{Q}$。
   5. 复数集合$\mathbb{C}$
4. 集合中的元素也可以是集合。
5. 对一个集合来说，任一事物或者是它的元素或者不是它的元素，二者必居其一而不可兼而有之，且结论是确定的。

### 集合间的关系

#### 被包含关系（子集）

$A$、$B$ 是集合，如果 $A$ 中元素都是 $B$ 中元素，则称 $B$ 包含 $A$，$A$ 包含于 $B$， 也称 $A$ 是 $B$ 的子集。

记作 $A \subseteq B$。

**谓词定义**：$A \subseteq B \Leftrightarrow \forall x (x \in A \rightarrow x \in B)$

**性质**：

1. 自反性，$A \subseteq A$
2. 传递性，$A \subseteq B,B \subseteq C$，则 $A \subseteq C$
3. 反对称性，$A \subseteq B,B \subseteq A$，则 $A = B$
4. $A \subseteq B \Rightarrow(A \cup C) \subseteq(B \cup C)$
5. $A \subseteq B \Rightarrow(A \cap C) \subseteq(B \cap C)$
6. $(A \subseteq B) \wedge(C \subseteq D) \Rightarrow(A \cup C) \subseteq(B \cup D)$
7. $(\mathbf{A} \subseteq \boldsymbol{B}) \wedge(\boldsymbol{C} \subseteq \boldsymbol{D}) \Rightarrow(\boldsymbol{A} \cap \boldsymbol{C}) \subseteq(\boldsymbol{B} \cap \boldsymbol{D})$

![image-20211130020252013](Algebra%20of%20sets.assets/image-20211130020252013.png)

![image-20211130020335352](Algebra%20of%20sets.assets/image-20211130020335352.png)

若B不是A的子集，则记做$B \nsubseteq A$



#### 相等关系

$A$、$B$ 是集合，如果它们的元素完全相同，则称 $A$ 与 $B$ 相等。

记作 $A = B$。

**谓词定义**：$A = B \Leftrightarrow \forall x (x \in A \leftrightarrow x \in B)$

**定理**：$A = B$ 当且仅当 $A \subseteq B$ 且 $B \subseteq A$

**性质**：

1. 自反性，$A = A$
2. 传递性，$A = B,B = C$，则 $A = C$
3. 对称性，$A = B$，则 $B = A$

#### 真被包含关系（真子集）

$A$、$B$ 是集合，如果 $A\subseteq B$ 且 $A \not = B$，则称 $B$ 真包含 $A$，$A$真包含于 $B$，也称 $A$ 是 $B$ 的真子集。

记作 $A \subset B$。

**谓词定义**：

**性质**：

对任何集合 $A$、$B$、$C$，如果有 $A \subset B$ 且 $B \subset C$ ，则 $A \subset C$。

### 特殊集合

**全集：$E$**

包含所讨论的所有集合的集合，称之为全集，记作 $E$。

**性质**：对于任何集合 $A$，都有 $A \subseteq E$。

全集是相对的，视具体情况而定，因此不唯一。

**空集：$\varnothing$**

不含任何元素的集合，称之为空集，记作 $\varnothing$。

**性质**：

1. 对于如何集合 $A$，都有 $\varnothing \subseteq A$。 因为 $\forall x (x \in \varnothing \rightarrow x \in A)$为永真式，所以 $\varnothing \subseteq A$。

2. 空集是唯一的。

   证明：设$\varnothing_{1}$ 与 $\varnothing_{2}$ 都是空集，则$\varnothing_{1} \subseteq \varnothing_{2} \wedge \varnothing_{2} \subseteq \varnothing_{1}$，所以 $\varnothing_{1}=\varnothing_{2}$

   

**集合的幂集**

$A$ 是集合，由 $A$ 的所有子集构成的集 合，称之为 $A$ 的幂集。记作 $P(A)$ 或 $2^A$。

$P(A) = \{B | B \subseteq A\}$

**结论**：

对任意集合 $A$，因为 $\varnothing \subseteq A$，$A \subseteq A$，所以有 $\varnothing \in P(A), A \in P(A)$ 。

**集合的元素个数：**

规定: $\varnothing$ 为 0 元集, 含1个元素的集合为单元集或1元集, 含 2 个元素的集合为 2 元集, ......, 含 $n$ 个元素的集合为 $n$ 元集 $(n \geq 1)$ 。

设集合 $A$ 的元素个数 $|A|=n$, 则 $|P(A)|=2^{n}$

性质：

1. $A \subseteq B \Leftrightarrow P(A) \subseteq P(B)$

2. $A=B \Leftrightarrow P(A)=P(B)$

3. $\mathrm{P}(\mathrm{A}) \in \mathrm{P}(\mathrm{B}) \Rightarrow \mathrm{A} \in \mathrm{B}$

   证明：$\mathrm{P}(\mathrm{A}) \in \mathrm{P}(\mathrm{B}) \Leftrightarrow P(A) \subseteq B$

   则：$ \forall x \in P(A) \Rightarrow x \in \mathrm{B}$

   故：$ \forall x \subseteq A \Rightarrow x \in \mathrm{B}$

   故：$\mathrm{A} \in \mathrm{B}$

4. $P(A) \cap P(B)=P(A \cap B)$

5. $\mathrm{P}(\mathrm{A}) \cup \mathrm{P}(\mathrm{B}) \subseteq \mathrm{P}(\mathrm{A} \cup \mathrm{B})$

6. $\mathrm{P}(\mathrm{A}-\mathrm{B}) \subseteq(\mathrm{P}(\mathrm{A})-\mathrm{P}(\mathrm{B})) \cup\{\varnothing\}$

![image-20211130020555967](Algebra%20of%20sets.assets/image-20211130020555967.png)

![image-20211130020654968](Algebra%20of%20sets.assets/image-20211130020654968.png)

### 集合的运算

#### 交运算 $\cap$

$A$、$B$ 是集合，由既属于 $A$，也属于 $B$ 的元素构成的集合，称之为 $A$ 与 $B$ 的交集，记作 $A \cap B$。

**谓词定义**：

$A \cap B = \{x | x \in A \land x \in B\}$

$x \in A \cap B \Leftrightarrow x \in A \land x \in B$

**性质**：

1. 幂等律，$A \cap A = A$
2. 交换律，$A \cap B = B \cap A$
3. 结合律，$(A \cap B) \cap C = A \cap (B \cap C)$
4. 同一律，$A \cap E = A$
5. 零律，$A \cap \varnothing = \varnothing$
6. $A \subseteq B \Leftrightarrow A \cap B = A$

#### 广义交集

设集合 $A$ 中的元素都为集合且 $A$ 非空, 称由 $A$ 中全体元素的公共元素组成的集合为 $A$ 的广义交, 记作 $\cap A $

$\cap A=\{x \mid \forall z(z \in A \rightarrow x \in z)\}$

设 $A=\{\{1,2,3\},\{1, a, b\},\{1,6,7\}\}$, 则 $\cap A=\{1\}$

注意：当 $A=\varnothing$ 时, $\cap \varnothing$ 无意义

#### 并运算 $\cup$

$A$、$B$ 是集合，由或属于 $A$，或属于 $B$ 的元素构成的集合，称之为 $A$ 与 $B$ 的并集，记作 $A \cup B$。

**谓词定义**：

$A \cup B = \{x | x \in A \lor x \in B\}$

$x \in A \cup B \Leftrightarrow x \in A \lor x \in B$

**性质**：

1. 幂等律，$A \cup A = A$

2. 交换律，$A \cup B = B \cup A$

3. 结合律，$(A \cup B) \cup C = A \cup (B \cup C)$

4. 同一律，$A \cup \varnothing = A$

5. 零律，$A \cup E = E$

6. 分配率，$A \cap (B \cup C) = (A \cap B) \cup (A \cap C),A \cup (B \cap C) = (A \cup B) \cap (A \cup C)$

   > 这个分配律在之前布尔代数中也有体现。将交理解为乘，并理解为加即可。

7. 吸收律，$A \cup (A \cap B) = A,A \cap (A \cup B) = A$

8. $A \subseteq B \Leftrightarrow A \cup B = B$

9. $A \subseteq B \Rightarrow A \cup C \subseteq B \cup C,A \cap C \subseteq B \cap C$

10. $A \subseteq B \land C \subseteq D \Rightarrow A \cup C \subseteq B \cup D,A \cap C \subseteq B \cap D$

试证明分配律：

![image-20211130015231072](Algebra%20of%20sets.assets/image-20211130015231072.png)

#### 不相交

设 $A, B$ 为二集合, 若 $A \cap B=\varnothing$, 则称 $A$ 和 $B$ 是不交的。

#### 广义并集

设集合A中的元素都为集合（集族），称由A中全体元素的元素组成的集合为A的广义并，记作$\cup A$ （“大并A”）

$\cup A=\{x \mid \exists z(x \in z \wedge z \in A)\}$

设 $A=\{\{a, b\},\{c, d\},\{d, e, f\}\}$, 则 $\cup A=\{a, b, c, d, e, f\}$.

若 $A=\left\{A_{1}, A_{2}, \cdots, A_{n}\right\}$, 则 $\cup A=A_{1} \cup A_{2} \cup \cdots \cup A_{n}$

#### 差运算 $-$ （相对补集）

$A$、$B$ 是集合，由属于 $A$，而不属于 $B$的元素构成的集合，称之为 $A$ 与 $B$ 的差集，或 $B$ 对 $A$ 的相对补集，记作 $A-B$。

也称B对A的相对补集。

**谓词定义**：

$A – B = \{x | x \in A \land x \not \in B\}$

$x \in A – B \Leftrightarrow x \in A \land x \not \in B$

**性质**：

1. $A – \varnothing = A$

2. $\varnothing – A = \varnothing$

3. $A – A = \varnothing$

4. $A – B \subseteq A$

5. $A \subseteq B \Leftrightarrow A – B =\varnothing$

6. $A – B = A \Leftrightarrow A \cap B =\varnothing$

7. $\mathbf{A} \cap(\mathbf{B}-\mathbf{C})=(\mathbf{A} \cap \mathbf{B})-\mathbf{C}$

8. $E-(A \cup B)=(E-A) \cap(E-B)$

9. $E-(A \cap B)=(E-A) \cup(E-B)$

   > 后两条为德摩根律

#### 绝对补集 $\sim$

$A$ 是集合,由不属于 $A$ 的元素构成的集合，称之为 $A$ 的绝对补集，记作 $\sim A$。实际上 $\sim A = E – A$。

**谓词定义**：

$\sim A = E – A = \{x | x \in E \land x \not \in A\} = \{x | x\not \in A\}$

$x \in \sim A \Leftrightarrow x \not \in A$

**性质**：

1. $\sim E = \varnothing$
2. $\sim \varnothing = E$
3. $\sim (\sim A) = A$
4. $A \cap \sim A = \varnothing$
5. $A \cup \sim A = E$
6. $A – B = A \cap \sim B$
7. $\sim (A \cap B) = \sim A \cup \sim B$
8. $\sim (A \cup B) = \sim A \cap \sim B$

#### 对称差 $\oplus$

$A$、$B$ 是集合,由属于 $A$ 而不属于 $B$，或者属于 $B$ 而不属于 $A$ 的元素构成的集合，称之为 $A$ 与 $B$ 的对称差，记作 $A \oplus B$。

**谓词定义**：

$A \oplus B = (A – B) \cup (B – A) = \{x | (x \in A \land x \not \in B) \lor (x \in B \land x \not \in A)\}$

$A \oplus B = (A \cup B) – (A \cap B)$

**性质**：

1. 交换律，$A \oplus B = B \oplus A$
2. 结合律，$(A \oplus B) \oplus C = A \oplus (B \oplus C)$
3. 分配律：$A \cap(B \oplus C)=(A \cap B) \oplus(A \cap C)$
4. 同一律，$A \oplus \varnothing = A$
5. $A \oplus A = \varnothing$

证明分配律：

![image-20211130015524899](Algebra%20of%20sets.assets/image-20211130015524899.png)

将运算全部转换为与或非运算！

### 集合运算的优先级

第一类运算（一元运算）：绝对补、幂集、广义交、广义并等。

第一类运算按照从右向左的顺序运算。

第二类运算（二元运算）：初级并、初级交、相对补、对称差等。

第二类运算按照括号决定的顺序运算，多个括号并排或没有括号的部分按照从左向右的顺序运算。第一类运算优先于第二类运算。

例：

给定 $A=\{\{a\},\{a, b\}\}$, 求 $U \cup A, \cap \cap A, \cap \cup A \cup(\cup \cup A-\cup \cap A)$

解：

$\cup A=\{a, b\}, \cap A=\{a\}$

$\cup \cup A=a \cup b, \cap \cap A=a$

$ \cap \cup A=a \cap b, \cup \cap A=a$

$\cap \cup A \cup(\cup \cup A-\cup \cap A)$
$=(a \cap b) \cup((a \cup b)-a)$
$=(a \cap b) \cup(b-a)=b$

### 容斥原理

设 $A_{1}, A_{2}, \ldots, A_{n}$ 为 $n$ 个集合, 则
$$
\begin{aligned}
\left|\bigcup_{i=1}^{n} A_{i}\right|=& \sum_{i=1}^{n}\left|A_{i}\right|-\sum_{i<j}\left|A_{i} \cap A_{j}\right| \\
&+\sum_{i<j<k}\left|A_{i} \cap A_{j} \cap A_{k}\right|-\cdots+(-1)^{n-1}\left|A_{1} \cap A_{2} \cap \cdots \cap A_{n}\right|
\end{aligned}
$$
![image-20211130014643279](Algebra%20of%20sets.assets/image-20211130014643279.png)



### 有序对与笛卡尔积

#### 有序对与有序 $n$ 元组

由两个对象 $x$、$y$ 按照一定顺序组成的序列称为有序二元组，也称之为序偶，记作 $\langle x,y \rangle$；称 $x$、$y$ 分别为序偶 $\langle x,y \rangle$ 的第一，第二元素。

注意，序偶 $\langle x,y \rangle$ 与集合 $\{x,y\}$不同：

- 序偶 $\langle x,y \rangle$：元素 $x$ 和 $y$ 有次序；

- 集合 $\{x,y\}$：元素 $x$ 和 $y$ 的次序是无关紧要的。

> 有序对的概念在图论中就有介绍，有起点、有终点，两个点不是一样的。

也可以引入集族的概念来定义笛卡尔积：$\langle a, b\rangle=\{\{a\},\{a, b\}\}$。集族这个概念就是为了强调有序对中的元素是有顺序的。

![image-20211206224913418](Algebra%20of%20sets.assets/image-20211206224913418.png)

> 其中需要注意到的观点是集合中元素是互异的，所以需要讨论一下x是否是a。

![image-20211206225744153](Algebra%20of%20sets.assets/image-20211206225744153.png)

> 其实就是用集合语言描述了广义交与广义并。

设 $\langle x,y \rangle$，$\langle u,v \rangle$ 是两个序偶，如果 $x = u$ 和 $y = v$，则称 $\langle x,y \rangle$ 和 $\langle u,v \rangle$ 相等， 记作 $\langle x,y \rangle = \langle u,v \rangle$。

![image-20211206231914750](Algebra%20of%20sets.assets/image-20211206231914750.png)

有序三元组：$\langle a, b, c\rangle=\langle\langle a, b\rangle, c\rangle$

有序 $n$ 元组是一个序偶，其第一个元素本身是个有序 $n-1$ 元组。且可 以简记成 $\langle x_1 , x_2 ,\cdots, x_{n-1}, x_n \rangle$。

$\langle x_1, x_2 ,\cdots, x_n \rangle = \langle y_1, y_2 ,\cdots, y_n \rangle \Leftrightarrow (x_1 = y_1) \land ( x_2 = y_2) \land \cdots \land ( x_n = y_n)$

例：n维空间坐标；n维向量。 

#### 集合的笛卡尔积

设 $A$、$B$ 是集合，由 $A$ 的元素为第一元素，$B$ 的元素为第二元素组成序偶的集合，称为 $A$ 和 $B$ 的笛卡尔积，记作 $A \times B$，即 $A \times B=\{\langle x,y \rangle | x \in A \land y \in B\}$

笛卡尔积是一种集合的运算。

**性质**：

1. 如果 $A$、$B$ 都是有限集，且 $|A| = m, |B| = n$， 则 $|A \times B | = mn$.

2. $A \times \varnothing = \varnothing \times B = \varnothing$

3. 非交换：$ \mathbf{A} \times \mathbf{B} \neq \mathbf{B} \times \mathbf{A}$。(除非 $A=B \vee A=\varnothing \vee B=\varnothing$ )

4. 非结合：$(A \times B) \times C \neq A \times(B \times C)$。

    (除非 $A=\varnothing \vee B=\varnothing \vee C=\varnothing$ )

5. $A \times B=\varnothing \Leftrightarrow A=\varnothing \vee B=\varnothing$ 

3. 分配律：
   1. $A \times (B \cup C) = (A \times B) \cup (A \times C)$
   2. $A\times (B \cap C) = (A \times B) \cap (A \times C)$
   3. $(A \cup B) \times C = (A \times C) \cup (B \times C)$
   4. $(A \cap B) \times C = (A \times C) \cap (B \times C)$
   
7. 若 $C \not = \varnothing$，$A \subseteq B \Leftrightarrow (A \times C \subseteq B \times C) \Leftrightarrow (C \times A \subseteq C \times B)$

8. 设 $A$、$B$、$C$、$D$ 为非空集合，则 $A\times B \subseteq C \times D \Leftrightarrow A \subseteq C \land B\subseteq D$

   这个定理还可以这样表述：$A \subseteq C \wedge B \subseteq D \Rightarrow A \times B \subseteq C \times D$，并且当 $(A=B=\varnothing) \vee(A \neq \varnothing \wedge B \neq \varnothing)$ 时,$A \times B \subseteq C \times D \Rightarrow A \subseteq C \wedge B \subseteq D$。一个空、一个非空就推不出来。

卡氏积分配律的证明：

- $A \times(B \cup C)=(A \times B) \cup(A \times C) .$
证明: $\forall<x, y>,\langle x, y>\in A \times(B \cup C)$
$\Leftrightarrow x \in A \wedge y \in(B \cup C) \Leftrightarrow x \in A \wedge(y \in B \vee y \in C)$
$\Leftrightarrow(x \in A \wedge y \in B) \vee(x \in A \wedge y \in C)$
$\Leftrightarrow(<x, y>\in A \times B) \vee(<x, y>\in A \times C)$
$\Leftrightarrow\langle x, y\rangle \in(A \times B) \cup(A \times C)$
$\therefore A \times(B \cup C)=(A \times B) \cup(A \times C) . \quad $

卡氏积图示：

![image-20211206235746669](Algebra%20of%20sets.assets/image-20211206235746669.png)

n维卡氏积：$A_{1} \times A_{2} \times \ldots \times A_{n}=\left\{<x_{1}, x_{2}, \ldots, x_{n}> | x_{1} \in A_{1} \wedge x_{2} \in A_{2} \wedge \ldots \wedge x_{n} \in A_{n}\right\}.$


n维卡氏积性质与2维卡氏积类似：

- 非交换
- 非结合
- 分配律

判断题中常见的问题是对于空集的讨论：

![image-20211221180614019](Algebra%20of%20sets.assets/image-20211221180614019.png)

### 关系及其表示法

#### 关系

n元关系：其元素全是有序n元组的集合。

2元关系：元素全是有序对的集合。二元关系简称为关系。

任何序偶的集合，都称之为一个二元关系。此外，空集也是一个二元关系。

设F是二元关系，则：$\langle x, y\rangle \in F \Leftrightarrow x$ 与 $y$ 具有 $F$ 关系 $\Leftrightarrow x F y$

对比：

- $x F y$ (中缀(infix)记号)。常用中缀记号。
- $F(x, y)$, Fxy (前缀(prefix)记号)
- $\langle x, y\rangle \in F, x y F \quad$ (后缀(suffix)记号)
- 例如：$2<15 \Leftrightarrow<(2,15) \Leftrightarrow<2,15>\in<.$

$xRy$ 表示有关系 $R$。

$x \not R y$ 表示无关系 $R$。

设 $A$、$B$ 是集合，如果 $R \subseteq A \times B$，则称 $R$ 是一 个从 $A$ 到 $B$ 的二元关系。

A到B的二元关系：$\mathbf{A} \times \mathbf{B}$的任意子集（含空集），R是A到B的二元关系$\Leftrightarrow \mathbf{R} \subseteq \mathbf{A} \times \mathbf{B} \Leftrightarrow \mathbf{R} \in \mathbf{P}(\mathbf{A} \times \mathbf{B})$。若$|A|=m,|B|=n$, 则 $|A \times B|=m n$, 故$|P(A \times B)|=2^{m n}$，即A到B不同的二元关系共有$2^{\mathrm{mn}}$个。

![image-20211219213303239](Algebra%20of%20sets.assets/image-20211219213303239.png) 

如果 $R\subseteq A \times A$，则称 $R$ 是 $A$ 上的二元关系。

#### 一些特殊的关系

设A是任意集合，则可以定义A上的：

- 空关系: Ø
- 恒等关系: $I_{A}=\{\langle x, x\rangle \mid x \in A\}$
- 全域关系：$E_{A}=A \times A=\{\langle x, y\rangle \mid x \in A \wedge y \in A\}$。全域关系其实就是A与A的笛卡尔积。
- 整除关系：设 $A \subseteq Z^{+}$, 则可以定义 $A$ 上的整除关系：$D_{A}=\{\langle x, y\rangle|x \in A \wedge y \in A \wedge x| y\}$ 。如果x能被y整除，我们就说x与y具有整除关系。
- 设 $A \subseteq R$, 则可以定义 $A$ 上的小于等于关系，小于关系，大于等于关系，大于关系。记$L_{A}$ 为 $A$ 上的小于等于关系
- 设 $A$ 为任意集合, 则可以定义 $P(A)$ 上的包含关系，真包含关系。

#### 关系的定义域与值域

**定义域**：设 $R \subseteq A \times B$，称集合 $\rm{dom} R = \{x | \exists y (\langle x,y \rangle \in R)\}$ 为 $R$ 的定义域。

**值域**：设 $R \subseteq A \times B$，称集合 $\rm{ran} R = \{y | \exists x (\langle x,y \rangle \in R)\}$ 为 $R$ 的值域。

**关系的域**：$\rm{fid} R = \rm{dom} R \cup \rm{ran} R$

**结论**：$\rm{dom} R \subseteq A,\rm{ran} R \subseteq B$

![image-20211220201232661](Algebra%20of%20sets.assets/image-20211220201232661.png)

#### 关系的另两种表示法

1. 有向图法：

   $R \subseteq A \times B$（$A$、$B$ 非空、有限），用两组小圆圈（称为结点）分别表示 $A$ 和 $B$ 的元素，当 $\langle x,y \rangle \in R$ 时，从 $x$ 到 $y$ 引一条有向弧（边）（由 $x$ 指向 $y$）。这样得到的图形称为 $R$ 的关系图。 如 $R \subseteq A \times A$，即 $R$ 是集合 $A$ 中关系时，用一组小圆圈表示 $A$ 中的元素，若 $\langle x,x \rangle \in R$，则从 $x$ 到 $x$ 画一条有向环（自回路）。

   - 当A中元素标定次序后，对于$R \subseteq A \times A$，则$G(R)$ 与 $R$ 的集合表达式可唯一互相确定，R的集合表达式,关系矩阵,关系图三者均可唯一 互相确定。
   - 对于 $R \subseteq A \times B$，$|A|=n,|B|=m$,关系矩阵 $M(R)$ 是 $n \times m$ 阶，G(R)中边都是从A中元素指向B中元素

2. 矩阵表示法：

   非空有限集合之间的关系也可以用矩阵来表示，这种表示法便于用计算机来处理关系。

   设 $A=\{a_1, a_2, \cdots , a_m\}$，$B=\{b_1, b_2, \cdots, b_n\}$ 是个有限集，$R \subseteq A \times B$，定义 $R$ 的 $m \times n$ 阶矩阵 $M_R=(r_{ij})_{m\times n}$，其中：

   $$
   r_{ij}=
   \left\lbrace
   \begin{array}{cc}
   1 & \langle a_i,b_j \rangle \in R\\
   0 & \langle a_i,b_j \rangle \not \in R
   \end{array}
   \right.
   (1 \le i \le m,1 \le j \le n)
   $$
   称 $M_R$ 为关系 $R$ 的关系矩阵。

### 关系的运算

由于关系是以有序对为元素的特殊集合，所以可对其进行集合的所有基本运算，如交、并、补等。

设 $R, S$ 为集合 $A$ 到 $B$ 的两个关系, 则:

- $R \cup S=\{<x, y>\mid x R y \vee x S y\}$

- $R \cap S=\{\langle x, y\rangle \mid x R y \wedge x S y\}$

- $R-S=\{\langle x, y\rangle \mid x R y \cap x \not S y\}$

- $\sim R=A \times B-R$

  > 这里是因为$\boldsymbol{A} \times \boldsymbol{B}$ 是相对于 $\mathrm{R}$ 的全集

逆运算：对任何集合F、G，可以定义逆（inverse）：$\mathrm{F}^{-1}=\{\langle\mathrm{x}, \mathrm{y}\rangle \mid \mathrm{yFx}\}$，若F为集合A到集合B的一个关系，则 $F^{-1}$ 及$\sim \mathrm{F}$ 均为关系:

- $\sim \boldsymbol{F}=\boldsymbol{A} \times \boldsymbol{B}-\boldsymbol{F} \subseteq \boldsymbol{A} \times \boldsymbol{B}$
- $F^{-1} \subseteq B \times A$

合成（复合）运算：FoG $=\{<x, y>\mid \exists z(x F z \wedge z G y)\}$

- 顺序合成（右合成），也是课本所使用的定义：FoG $=\{<x, y>\mid \exists z(x F z \wedge z G y)\}$
- 逆序合成（左合成）：FoG $=\{\langle x, y\rangle \mid \exists z(x G z \wedge z F y)\}$
- ![image-20211220203112696](Algebra%20of%20sets.assets/image-20211220203112696.png)

![image-20211220203205297](Algebra%20of%20sets.assets/image-20211220203205297.png)

![image-20211220203621625](Algebra%20of%20sets.assets/image-20211220203621625.png)

也可以用关系矩阵求关系的运算：

- $M\left(R^{-1}\right)=(M(R))^{\top}$

- $M\left(R_{1} \circ R_{2}\right)=M\left(R_{1}\right) \bullet M\left(R_{2}\right)$

  注意：•表示矩阵的 “逻辑乘”，加法用 $\vee$, 乘法用 $\wedge$。逻辑乘保证了运算之后矩阵的元素还是只有0和1.

如果把二元关系看成一种作用，则$\langle x, y\rangle \in R$可以解释为x通过R的作用变到y，那么右复合$F \circ G$与左复合$F \circ G$都表示两个作用的连续发生。

**限制、像：**

对于二元关系F和集合A，可以定义：

- 限制（restriction）：$\mathrm{F} \upharpoonright \mathrm{A}=\{\langle\mathrm{x}, \mathrm{y}\rangle \mid \mathrm{xFy} \wedge \mathrm{x} \in \mathrm{A}\} \subseteq \mathrm{F}$。是原来关系的一个子集，即把定义域缩小了。

- 像（image）：$\mathrm{F}[\mathrm{A}]=\operatorname{ran}(\mathrm{F} \upharpoonright \mathrm{A}) \subseteq \operatorname{ran} \mathrm{F}$

  $\mathrm{F}[\mathrm{A}]=\{\mathrm{y} \| \exists \mathrm{x}(\mathrm{x} \in \mathrm{A} \wedge \mathrm{xFy})\}$

  

![image-20211220215044161](Algebra%20of%20sets.assets/image-20211220215044161.png)

![image-20211220215316163](Algebra%20of%20sets.assets/image-20211220215316163.png)

关系运算的顺序：

- 逆运算优先于其他运算
- 关系运算（逆、合成、限制、像）优先于集合运算（交并补、相对补、对称差等）
- 没有规定优先权的运算以括号决定运算顺序

基本运算的性质：设F是任意的关系，则：

- $\left(F^{-1}\right)^{-1}=F$

  > 任取 $\langle x, y\rangle$, 由逆的定义有$\langle x, y\rangle \in\left(F^{-1}\right)^{-1} \Leftrightarrow\langle y, x\rangle \in F^{-1} \Leftrightarrow\langle x, y\rangle \in F$所以有所以有 $\left(F^{-1}\right)^{-1}=F$

- $\operatorname{dom} F^{-1}=\operatorname{ran} F, \operatorname{ran} F^{-1}=\operatorname{dom} F$

  任取 $x, x \in \operatorname{dom} F^{-1} \Leftrightarrow \exists {y}\left(\langle x, y\rangle \in {F}^{-1}\right) \Leftrightarrow \exists y(<y, x>\in F) \Leftrightarrow x \in \operatorname{ran} F$，所以有$\operatorname{dom} F^{-1}=\operatorname{ran} F$

![image-20211220221317610](Algebra%20of%20sets.assets/image-20211220221317610.png)

![image-20211220221757573](Algebra%20of%20sets.assets/image-20211220221757573.png)

![image-20211220221945359](Algebra%20of%20sets.assets/image-20211220221945359.png)



设F、G、H为任意的关系，则有：

- $F \circ(G \cup H)=F \circ G \cup F \circ H$

- $(\boldsymbol{G} \cup \boldsymbol{H}) \circ \boldsymbol{F}=\boldsymbol{G} \circ \boldsymbol{F} \cup \boldsymbol{H} \circ \boldsymbol{F}$

- $F \circ(G \cap H) \subseteq F \circ G \cap F \circ H$

  > $\boldsymbol{F} \circ \boldsymbol{G} \cap \boldsymbol{F} \circ \boldsymbol{H} \subseteq \boldsymbol{F} \circ(\boldsymbol{G} \cap \boldsymbol{H})$不一定成立可以用反证法来证明。当$A=\{1,2,3\}, B=\{1,2\}, C=\{2,3\}, A$ 到 $B$ 的关系$\mathrm{F}=\{<2,2>,<2,1>\}, \mathrm{B}$ 到 $\mathrm{C}$ 的关系 $\mathrm{G}=\{<1,2>,<2,3>\}$,$\mathrm{H}=\{\langle 2,2\rangle,\langle 1,3\rangle\}$，由于$G \cap H$是空集，所以两者不相等

- $(\boldsymbol{G} \cap \boldsymbol{H}) \circ \boldsymbol{F} \subseteq \boldsymbol{G} \circ \boldsymbol{F} \cap \boldsymbol{H} \circ \boldsymbol{F}$

上述结论对有限个关系的并和交也成立。

设F为任意的关系，A、B为集合，则：

- $\boldsymbol{F} \upharpoonright (\boldsymbol{A} \cup \boldsymbol{B})=\boldsymbol{F} \upharpoonright \boldsymbol{A} \cup \boldsymbol{F} \upharpoonright\boldsymbol{B}$
- $\boldsymbol{F}[\boldsymbol{A} \cup \boldsymbol{B}]=\boldsymbol{F}[\boldsymbol{A}] \cup \boldsymbol{F}[\boldsymbol{B}]$
- $\boldsymbol{F} \upharpoonright(\boldsymbol{A} \cap \boldsymbol{B})=\boldsymbol{F} \upharpoonright\boldsymbol{A} \cap \boldsymbol{F} \upharpoonright \boldsymbol{B}$
- $F[A \cap B] \subseteq F[A] \cap F[B]$
- $F[A]-F[B] \subseteq F[A-B]$



**幂运算：**

设 $R$ 为 $A$ 上的关系, $n$ 为自然数, 则 $R$ 的 $n$ 次幂是：

1. $R^{0}=\{\langle x, x\rangle \mid x \in A\}=I_{A}$
2. $R^{n+1}=R^{n} \circ R$

注意：对于A上的任何关系$R_{1}$ 和 $R_{2}$ 都有 $R_{1}{ }^{0}=R_{2}{ }^{0}= I_A$，对于A上的任何关系$R$ 都有 $R^{1}=R$。对于集合表示的关系R，计算$R^{n}$ 就是 $n$ 个 $R$ 合成。

![image-20211220223630016](Algebra%20of%20sets.assets/image-20211220223630016-16400109921421.png)

![image-20211220223729779](Algebra%20of%20sets.assets/image-20211220223729779.png)

![image-20211220224503472](Algebra%20of%20sets.assets/image-20211220224503472.png)

> 因为自然数是无穷的，而$2^{n^{2}}$是有限的，因为抽屉原理，所以必有相等

设R是A上的关系，$m, n \in \mathrm{N}$, 则

- $R^{m} \circ R^{n}=R^{m+n}$
- $\left(R^{m}\right)^{n}=R^{m n}$

> 证明可以用归纳法，也可以用矩阵的方法去证明

![image-20211220224944528](Algebra%20of%20sets.assets/image-20211220224944528.png)

![image-20211221182439857](Algebra%20of%20sets.assets/image-20211221182439857.png)

### 关系的性质（某集合上的关系）

#### 自反与反自反

若$\mathrm{R} \subseteq \mathrm{A} \times \mathrm{A}$，则$R$ 是自反的 $\Leftrightarrow \forall x(x \in A \rightarrow x R x) \Leftrightarrow(\forall x \in A) x R x$。比如非空集合上的恒等关系、全域关系，正整数集合上的整除关系，小于等于关系，集合幂集上的包含关系和相等关系等。

$R$ 是非自反的 $\Leftrightarrow \exists x(x \in A \wedge \neg x R x)$

$\mathrm{R}$ 是自反的$\Leftrightarrow I_{A} \subseteq R$$\Leftrightarrow R^{-1}$ 是自反的$\Leftrightarrow M(R)$ 主对角线上的元素全为 1$\Leftrightarrow G(R)$ 的每个顶点处均有环

反自反性：

若$\mathbf{R} \subseteq \mathbf{A} \times \mathbf{A}$，则$R$ 是反自反的 $\Leftrightarrow \forall x(x \in A \rightarrow \neg x R x) \Leftrightarrow$ $(\forall x \in A) \neg x R x$，如非空集合上的空关系，自然数集合上的小于关系，集合的幂集上的真包含关系。

$\mathrm{R}$ 是反自反的
$\Leftrightarrow I_{A} \cap R=\varnothing$
$\Leftrightarrow \mathrm{R}^{-1}$ 是反自反的
$\Leftrightarrow M(R)$ 主对角线上的元素全为 0
$\Leftrightarrow G(R)$ 的每个顶点处均无环. 

![image-20211220231008046](Algebra%20of%20sets.assets/image-20211220231008046.png)

#### 对称性与反对称性

若$\mathbf{R} \subseteq \mathbf{A} \times \mathbf{A}$，则$R$ 是对称的 $\Leftrightarrow$$\forall x \forall y(x \in A \wedge y \in A \wedge x R y \rightarrow y R x)$$\Leftrightarrow(\forall x \in A)(\forall y \in A)[x R y \rightarrow y R x]$，如非空集合上的全域关系（对称、非反对称）、恒等关系。

$R$ 是非对称的 $\Leftrightarrow$$\exists x \exists y(x \in A \wedge y \in A \wedge x R y \wedge \neg y R x)$

![image-20211220231508084](Algebra%20of%20sets.assets/image-20211220231508084.png)

每个点上有没有环、是不是所有点上都有环无所谓，我们更关注的是两个不同的点之间的连线。

$\mathrm{R}$ 是对称的
$\Leftrightarrow \mathrm{R}^{-1}=\mathrm{R}$
$\Leftrightarrow \mathrm{R}^{-1}$ 是对称的
$\Leftrightarrow \mathrm{M}(\mathrm{R})$ 是对称的
$\Leftrightarrow \mathrm{G}(\mathrm{R})$ 的任何两个顶点之间若有边, 则必有两条方向相反的有向边. 

**反对称性**

若$\mathbf{R} \subseteq \mathbf{A} \times \mathbf{A}$，则$R$ 是反对称的 $\Leftrightarrow$$\forall x \forall y(x \in A \wedge y \in A \wedge x R y \wedge y R x \rightarrow x=y)$$\Leftrightarrow(\forall x \in A)(\forall y \in A)[x R y \wedge y R x \rightarrow x=y]$,如非空集合上的恒等关系、空关系、正整数集合上的整除关系、小于等于关系等。

> 即两个不同的点之间要有边的话只可能有一种方向的边。

![image-20211220232359079](Algebra%20of%20sets.assets/image-20211220232359079.png)

R是反对称的$\Leftrightarrow R^{-1} \cap R \subseteq I_{A}$$\Leftrightarrow \mathrm{R}^{-1}$ 是反对称的$\Leftrightarrow$ 在 $M(R)$ 中, $\forall i \forall j\left(i \neq j \wedge r_{i j}=1 \rightarrow r_{j j}=0\right)$$\Leftrightarrow$ 在 $G(R)$ 中, $\forall a_{i} \forall a_{j}(i \neq j)$, 若有有向边 $<a_{i}, a_{j}>$, 则 必没有 $<\mathrm{a}_{\mathrm{j}}, \mathrm{a}_{\mathrm{i}}>$. 

![image-20211220232826731](Algebra%20of%20sets.assets/image-20211220232826731.png)

#### 传递性

若$\mathbf{R} \subseteq \mathbf{A} \times \mathbf{A}$，则$\mathrm{R}$ 是传递的 $\Leftrightarrow$
$\forall x \forall y \forall z(x \in A \wedge y \in A \wedge z \in A \wedge x R y \wedge y R z \rightarrow x R z)$
$\Leftrightarrow(\forall x \in A)(\forall y \in A)(\forall z \in A)[x R y \wedge y R z \rightarrow x R z]$

若R非传递$\Leftrightarrow \exists x \exists y \exists z(x \in A \wedge y \in A \wedge z \in A \wedge x R y \wedge y R z \wedge \neg x R z)$

![image-20211220233204230](Algebra%20of%20sets.assets/image-20211220233204230.png)

$\mathrm{R}$ 是传递的$\Leftrightarrow R o R \subseteq R \Leftrightarrow R^{-1}$ 是传递的$\Leftrightarrow \forall i \forall j, M(R o R)(i, j) \leq M(R)(i, j)$$\Leftrightarrow$ 在 $G(R)$ 中, $\forall a_{i} \forall a_{j} \forall a_{k}$, 若有有向边 $<a_{i}, a_{j}>$ 和 $<\mathrm{a}_{\mathrm{i}}, \mathrm{a}_{\mathrm{k}}>$, 则必有有向边 $<\mathrm{a}_{\mathrm{i}}, \mathrm{a}_{\mathrm{k}}>$.

在自然数集上：

- 整除关系$D=\{<x, y>|x \in N \wedge y \in N \wedge x| y\} $反对称, 传递 ，不自反的原因是因为0整除0无定义
- $I_{N}=\{\langle x, y\rangle \mid x \in N \wedge y \in N \wedge x=y\}$ 自反, 对称, 反对称,传递
- $E_{N}=\{<x, y>\mid x \in N \wedge y \in N\}=N \times N$ 自反, 对称,传递.

![image-20211221182946642](Algebra%20of%20sets.assets/image-20211221182946642.png)

![image-20211221174116889](Algebra%20of%20sets.assets/image-20211221174116889.png) 

![image-20211221174724423](Algebra%20of%20sets.assets/image-20211221174724423.png)

![image-20211221174734363](Algebra%20of%20sets.assets/image-20211221174734363.png)

![image-20211221174742693](Algebra%20of%20sets.assets/image-20211221174742693.png)

![image-20211221174744479](Algebra%20of%20sets.assets/image-20211221174744479.png)

![image-20211221174754667](Algebra%20of%20sets.assets/image-20211221174754667.png)

![image-20211221174803902](Algebra%20of%20sets.assets/image-20211221174803902.png)

![image-20211221174810377](Algebra%20of%20sets.assets/image-20211221174810377.png)

![image-20211221174817470](Algebra%20of%20sets.assets/image-20211221174817470.png)

> 注意最后一步是单向箭头，而不是双向箭头，因为传递的定义要求两步能到达的一定可以一步到达，而一步到达的不一定可以拆成两步可达！

### 关系的闭包

关系闭包：增加**最少**元素使其具备所需性质

自反闭包r(R)：

- $R \subseteq r(R)$。即原有的关系应当继续保留
- $r(R)$ 是自反的，即要满足自反的性质
- $\forall \mathrm{S}\left(\left(R \subseteq \mathrm{S} \wedge \mathrm{S}自反\right) \rightarrow \mathrm{r}(\mathrm{R}) \subseteq \mathrm{S}\right)$

![image-20220104020157578](Algebra%20of%20sets.assets/image-20220104020157578.png)

> 从图上看很简单，给没有环的地方加个环即可

对称闭包s(R)：

- $R \subseteq s(R)$
- $s(R)$ 是对称的
- $\forall \mathrm{S}((\mathrm{R} \subseteq \mathrm{S} \wedge \mathrm{S}$ 对称 $) \rightarrow \mathrm{s}(\mathrm{R}) \subseteq \mathrm{S})$

传递闭包t(R):

- $\mathrm{R} \subseteq t(\mathrm{R})$
- $t(R)$ 是传递的
- $\forall s((R \subseteq S \wedge S 传 递) \rightarrow t(R) \subseteq S)$

定理：设$ R\subseteq A \times A$ 且 $A \neq \varnothing$，则

- $R$ 自反 $\Leftrightarrow r(R)=R$;
- $R$ 对称 $\Leftrightarrow s(R)=R$
- $R$ 传递 $\Leftrightarrow t(R)=R$

定理：设$\mathrm{R}_{1} \subseteq \mathrm{R}_{2} \subseteq \mathrm{A} \times \mathrm{A}$ 且 $\mathrm{A} \neq \boldsymbol{\varnothing}$, 则

- $r\left(R_{1}\right) \subseteq r\left(R_{2}\right)$
- $s\left(R_{1}\right) \subseteq s\left(R_{2}\right)$
- $t\left(R_{1}\right) \subseteq t\left(R_{2}\right)$

证明：由 $R_{1} \subseteq R_{2}$ 和 $R_{2} \subseteq r\left(R_{2}\right)$, 有 $R_{1} \subseteq r\left(R_{2}\right)$ 。又$r\left(R_{2}\right)$ 是自反的, 根据定义, 必有 $r\left(R_{1}\right) \subseteq r\left(R_{2}\right)$。

定理：设$R_{1}, R_{2} \subseteq A \times A$ 且 $A \neq \varnothing$，则

- $r\left(R_{1} \cup R_{2}\right)=r\left(R_{1}\right) \cup r\left(R_{2}\right)$
- $s\left(R_{1} \cup R_{2}\right)=s\left(R_{1}\right) \cup s\left(R_{2}\right)$
- $t\left(R_{1} \cup R_{2}\right) \supseteq t\left(R_{1}\right) \cup t\left(R_{2}\right)$

![image-20220104021645699](Algebra%20of%20sets.assets/image-20220104021645699.png)

闭包的求法：设 $R \subseteq A \times A$ 且 $A \neq \varnothing$, 则

- $r(R)=R \cup I_{A}$
- $s(R)=R \cup R^{-1}$
- $t(R)=R \cup R^{2} \cup R^{3} \cup...$

![image-20220104022855019](Algebra%20of%20sets.assets/image-20220104022855019.png)

![image-20220104022903456](Algebra%20of%20sets.assets/image-20220104022903456.png)

![image-20220104022910855](Algebra%20of%20sets.assets/image-20220104022910855.png)

![image-20220104024006114](Algebra%20of%20sets.assets/image-20220104024006114.png)

![image-20220104024256924](Algebra%20of%20sets.assets/image-20220104024256924.png)

![image-20220104024305124](Algebra%20of%20sets.assets/image-20220104024305124.png)

定理：设 $R \subseteq A \times A$ 且 $A \neq \varnothing$, 则

- $r s(R)=s r(R)$
- $r t(R)=\operatorname{tr}(R)$
- $s t(R) \subseteq \operatorname{ts}(R)$

![image-20220104025058547](Algebra%20of%20sets.assets/image-20220104025058547.png)

### 等价关系与划分

设 $\mathrm{A} \neq \boldsymbol{\varnothing}$ 且 $\mathrm{R} \subseteq \mathrm{A} \times \mathrm{A}$，若R是自反、对称、传递的，则说R是等价关系。

![image-20220104030227042](Algebra%20of%20sets.assets/image-20220104030227042.png)

定义：设R是$A \neq \varnothing$上等价关系，$\forall \mathbf{x} \in \mathbf{A}$，则x关于R的等价类是$[x]_{R}=\{y \mid y \in A \wedge x R y\}$，简称为x的等价类，简记为$[x]$。

![image-20220104030715618](Algebra%20of%20sets.assets/image-20220104030715618.png)

等价关系其实就是一个分类。

定理：设R是$A \neq \varnothing$ 上等价关系, 则 $\forall x, y \in A$,

- $[x]_{R} \neq \varnothing$
- $x R y \Rightarrow[x]_{R}=[y]_{R}$
- $\neg x R y \Rightarrow[x]_{R} \cap[y]_{R}=\varnothing$
- $\cup\left\{[x]_{R} \mid x \in A\right\}=A$

![image-20220104031039991](Algebra%20of%20sets.assets/image-20220104031039991.png)

商集：设R是$A \neq \varnothing$上等价关系，A关于R的商集（简称A的商集）是$A / R=\left\{[x]_{R} \mid x \in A\right\}$。

> 商集是集合的集合！

显然，$\cup A / R=A$。

![image-20220104032723367](Algebra%20of%20sets.assets/image-20220104032723367.png)

空关系不是等价关系，因为它非自反。

划分：定义$A \neq \varnothing$ 的一个划分是  $\mathscr{A}\subseteq P(A)$ 满足

- $\varnothing \notin \mathscr{A}$
- $\forall x, y(x, y \in \mathscr{A} \wedge x \neq y \Rightarrow x \cap y=\varnothing)$
- $\cup \mathscr{A}=\mathrm{A}$

$\mathscr{A}$中元素称为划分块（block）。

![image-20220104034748029](Algebra%20of%20sets.assets/image-20220104034748029.png)

![image-20220104034909134](Algebra%20of%20sets.assets/image-20220104034909134.png)

Stirling子集数：把n个不同球放到k个相同盒子里，要求无空盒，不同放法的总和$\left\{\begin{array}{l}n \\ k\end{array}\right\}$称作Sirling子集数。

![image-20220104035201625](Algebra%20of%20sets.assets/image-20220104035201625.png)

### 序关系

偏序关系：设 $\mathrm{A} \neq \boldsymbol{\varnothing}$ 且 $\mathrm{R} \subseteq \mathrm{A} \times \mathrm{A}$，若R是自反、反对称、传递的，则称R是A上的偏序关系。常用$\preccurlyeq$表示偏序关系，读作“小于等于”。

定义：设$\preccurlyeq$是A上偏序关系，则称$<A, \preccurlyeq >$为偏序集。

![image-20220104035931599](Algebra%20of%20sets.assets/image-20220104035931599.png)

设$<A, \preccurlyeq >$是偏序集，$x, y \in A$

- 若$ x \preccurlyeq y \vee y \preccurlyeq x$, 则称x与y可比
- 若x小于等于y且不相等，则说x严格小于y，即$x \leqslant y \wedge x \neq y \Leftrightarrow x<y$
- 若x严格小于y，且不存在z，使得x严格小于z、z严格小于y，则称y覆盖x，即$x<y \wedge \neg \exists z(z \in A \wedge x \prec z<y)$

> $\forall x, y \in A$, 下述几种情况发生其一且仅发生其一:$x<y, y<x, x=y, x$ 与 $y$ 不是可比的

哈斯图：设$<A, \preccurlyeq >$是偏序集，$x, y \in A$

- 用顶点表示A中元素
- 当且仅当y覆盖x时，y在x上方，在x与y之间画无向边

![image-20220104041127044](Algebra%20of%20sets.assets/image-20220104041127044.png)

![image-20220104041145261](Algebra%20of%20sets.assets/image-20220104041145261.png)

全序关系（线序关系）：设$<A, \preccurlyeq >$是偏序集，若A中任意元素x，y都可比，则称$ \preccurlyeq$为A上的全序关系（线性关系），称$<A, \preccurlyeq >$为全序集（线序集）

充要条件：哈斯图是一条“直线”

拟序关系：设 $A \neq \varnothing ， R \subseteq A \times A$，若R是反自反、传递的，则称R为A上的拟序关系，常用$\prec$表示拟序关系，称$\langle A, \prec\rangle$为拟序集。

> 反自反性与传递性蕴含反对称性！证明可以用$x<y \wedge y<x \Rightarrow x \prec x$推出矛盾可得。

偏序关系去掉恒等关系就是拟序关系，拟序关系并上恒等关系就是偏序关系。

**偏序关系中的特殊关系**

设$<A, \preccurlyeq >$是偏序集，$B \subseteq A, y \in B$

- y是B的最大元：$\forall x(x \in B \rightarrow x \leqslant y)$
- y是B的最小元：$\forall x(x \in B \rightarrow y \leqslant x)$

![image-20220104051826021](Algebra%20of%20sets.assets/image-20220104051826021.png)

> 最大元、最小元要求可比。
>
> 最大元、最小元不一定存在，如果存在，一定唯一。

设$<A, \preccurlyeq >$是偏序集，$B \subseteq A, y \in B$

- y是B的极大元：$\forall x(x \in B \wedge y \leqslant x \rightarrow x=y)$
- y是B的极小元：$\forall x(x \in B \wedge x \leqslant y \rightarrow x=y)$

> 极大元的意思是，这个元素不比这个集合里的其它元素小。

极大元、极小元与最大元、最小元的区别是，最大元、最小元要求与所有元素都可比，而极大元、极小元没有这个限制。

![image-20220104052657332](Algebra%20of%20sets.assets/image-20220104052657332.png)

有穷集B：

- 最小元不一定存在，若存在一定唯一
- 极小元一定存在，可能有多个，若唯一，则为最小元

设$<A, \preccurlyeq >$是偏序集，$B \subseteq A, y \in A$

- y是B的上界：$\forall x(x \in B \rightarrow x \leqslant y)$
- y是B的下界：$\forall x(x \in B \rightarrow y \leqslant x)$

和最大元、最小元的区别是，y不是从B里找，而是从A里找。

![image-20220104053251261](Algebra%20of%20sets.assets/image-20220104053251261.png)

> 和微积分一样，上界和下界都有可能有很多点！

上确界：上界中的最小元；

下确界：下界中的最大元；

![image-20220104054207549](Algebra%20of%20sets.assets/image-20220104054207549.png)

设$<A, \leqslant>$为偏序集，$B \subseteq A$

- B是A中的链：$\forall x \forall y(x \in B \wedge y \in B \rightarrow x$ 与 $y$ 可比 $)$
- B是A中的反链：$\forall x \forall y(x \in B \wedge y \in B \wedge x \neq y \rightarrow x$ 与 $y$ 不可比 $)$
- $|B|$ 称为(反)链的长度

![image-20220104054635353](Algebra%20of%20sets.assets/image-20220104054635353.png)

## 函数

函数、映射：单值的二元关系

单值：$\forall x \in d o m F, \forall y, z \in \operatorname{ranF}$，$x F y \wedge x F z \rightarrow y=z$

![image-20220104055243870](Algebra%20of%20sets.assets/image-20220104055243870.png)

函数的记号：$F(x)=y \Leftrightarrow<x, y>\in F \Leftrightarrow x F y$

$\varnothing$ 是空函数

偏函数（部分函数）：

- 设F是函数
- A到B的偏函数：domF $\subseteq A \wedge \operatorname{ranF} \subseteq B$
- A称作F的前域，B称作F的后域
- 从A到B的偏函数F记作$F:A \nrightarrow B $
- A到B的全体偏函数记作：$\mathrm{A} \nrightarrow \mathrm{B}=\{\mathrm{F} \mid \mathrm{F}: \mathrm{A} \nrightarrow \mathrm{B}\}$
- 显然 $A \rightarrow B \subseteq P(A \times B)$

​	

全函数：

- domF=A
- 全函数记作 $F: A \rightarrow B$
- A到B的全体全函数记为：$\mathrm{B}^{\mathrm{A}}=\mathrm{A} \rightarrow \mathrm{B}=\{\mathrm{F} \mid \mathrm{F}: \mathrm{A} \rightarrow \mathrm{B}\}$
- $\left|B^{A}\right|=|B|^{|A|}$
- 当 $A=\varnothing$ 时， $B^{A}=\{\varnothing\}$
- 当 $A \neq \varnothing \wedge B=\varnothing$ 时，$B^{A}=A \rightarrow B=\varnothing$

**在作业与考试中讨论的函数都是全函数**

设$\mathrm{F}: \mathrm{A} \rightarrow \mathrm{B}$：

- 单射：F是单根的。任取$y \in \operatorname{ran} F$，存在唯一的$x \in$ domF满足$f(x)=y$
- 满射：ranF=B
- 双射：一一对应：既是单射又是满射

单射、满射、双射个数：

- 设 $|A|=n,|B|=m$
- $n<m$ 时, $A \rightarrow B$ 中无满射、无双射、单射个数为$m(m-1) \ldots(m-n+1)$
- $n>m$ 时, $A \rightarrow B$中无单射，无双射，满射个数为$m !\left\{\begin{array}{l}n \\ m\end{array}\right\}$
- $n=m$ 时, $A \rightarrow B$中双射个数为$n !$

例：判断下面函数是否为单射，满射，双射的：

- $f: \mathrm{Z}^{+} \rightarrow \mathrm{R}, f(x)=\ln x, \mathrm{Z}^{+}$为正整数集。首先它是单射，其次由于定义域是正整数集，所以它不是满射

构造A到B的双射函数：

![image-20220104062451677](Algebra%20of%20sets.assets/image-20220104062451677.png)

> 这道题的关键是要想明白B代表的含义！

常数函数：$\mathrm{f}: \mathrm{A} \rightarrow \mathrm{B}, \exists \mathrm{b} \in \mathrm{B}, \forall \mathrm{x} \in \mathrm{A}, \mathrm{f}(\mathrm{x})=\mathrm{b}$

恒等函数：$\mathrm{I}_{\mathrm{A}}: \mathrm{A} \rightarrow \mathrm{A}, \mathrm{I}_{\mathrm{A}}(\mathrm{x})=\mathrm{x}$

特征函数：$\chi_{A}: E \rightarrow\{0,1\}, \chi_{A}(x)=1 \Leftrightarrow x \in A$

当 $\varnothing \subset A \subset E$ 时， $\chi_{A}$ 是满射

自然映射：

- 设R为A上等价关系

- 自然映射，典型映射：$\mathrm{f}: \mathrm{A} \rightarrow \mathrm{A} / \mathrm{R}, \mathrm{f}(\mathrm{x})=[\mathrm{x}]_{\mathrm{R}}$

  也就是把元素映射到它的等价类上

- 自然映射是满射

- 当 $R=I_{A}$ 时, $f$ 是单射

![image-20220104063511368](Algebra%20of%20sets.assets/image-20220104063511368.png)

定理：设 $\mathrm{f}: \mathrm{A} \rightarrow \mathrm{B}, \mathrm{g}: \mathrm{B} \rightarrow \mathrm{C}$ ，则f o g:A $\rightarrow$ C, f o g $(x)=g(f(x))$

> 之前我们证明了关系复合还是关系，但是这里要证明的是函数复合了仍是一个函数

证明思路：

- fog单值 (即fog是函数)
- dom fog $=\mathrm{A}$, ran fog $\subseteq \mathrm{C}$
- $f o g(x)=g(f(x))$

![image-20220104063814773](Algebra%20of%20sets.assets/image-20220104063814773.png)

![image-20220104063907257](Algebra%20of%20sets.assets/image-20220104063907257.png)

![image-20220104063956250](Algebra%20of%20sets.assets/image-20220104063956250.png)

设 $\mathrm{f}: \mathrm{A} \rightarrow \mathrm{B}, \mathrm{g}: \mathrm{B} \rightarrow \mathrm{C}$, 则

- 若 fog 为满射, 则 $\mathrm{g}$ 是满射
- 若 $f \circ g$ 为单射, 则 $f$ 是单射
- 若 fog 为双射, 则 $f$ 是单射, $g$ 是满射

![image-20220104064507220](Algebra%20of%20sets.assets/image-20220104064507220.png)

反函数：设$f: A \rightarrow B$, 且 $f$ 为双射，则$f^{-1}: B \rightarrow A$, 且 $f^{-1}$ 也为双射。若$f: A \rightarrow B$ 为双射, 则 $f^{-1}: B \rightarrow A$ 称为 $f$的反函数。
