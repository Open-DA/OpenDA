数理逻辑（ Mathematical Logic ) 是研究演绎推理的一门学科; 它的主要研究内容是 推理, 特别着重于推理过程是否正确; 它不是研究某个特定的语句是否正确, 而是 着重于语句之间的关系。它的主要研究方法是采用数学的方法来研究数学推理、数学性质和数学基础；而所谓数学方法就是引进一套符号体系的方法，所以数理逻辑又叫符号逻辑。

> 人工智能中的符号主义(symbolicism)，又称为逻辑主义、心理学派或计算机学派，其原理主要为物理符号系统(即符号操作系统)假设和有限合理性原理。 符号主义学派认为人工智能源于数理逻辑。数理逻辑从19世纪末起得以迅速发展，到20世纪30年代开始用于描述智能行为。计算机出现后，又在计算机上实现了逻辑演绎系统。其有代表性的成果为启发式程序LT逻辑理论家，它证明了38条数学定理，表明了可以应用计算机研究人的思维过程，模拟人类智能活动。正是这些符号主义者，早在1956年首先采用“人工智能”这个术语。后来又发展了启发式算法>专家系统>知识工程理论与技术，并在20世纪80年代取得很大发展。符号主义曾长期一枝独秀，为人工智能的发展作出重要贡献，尤其是专家系统的成功开发与应用，为人工智能走向工程应用和实现理论联系实际具有特别重要的意义。在人工智能的其他学派出现之后，符号主义仍然是人工智能的主流派别。这个学派的代表人物有纽厄尔(Newell)、西蒙(Simon)和尼尔逊(Nilsson)等。



## 命题逻辑

### 命题

命题是陈述外界发生事情的陈述句，命题是或为真或为假的陈述句。

非真即假，不可兼（$T/F$）

| 语句               | 算不算命题 |
| ------------------ | ---------- |
| 哥德巴赫猜想       | 算         |
| 悖论（我正在说谎） | 不算       |
| 昨天很冷           | 不算       |

> 这是形式主义的观点，而还有其它观点，如直觉主义逻辑，多值逻辑等。

命题的抽象化：

- 以p、q、r等表示命题
- 以1表示真，0表示假

则命题就抽象为：取值为0或1的p等符号。

### 复合命题

复合命题 = 简单命题 + 联结词

复合命题的真假完全由构成它的简单命题的真假所决定。

| 联结词 | 符号              |
| ------ | ----------------- |
| 否定   | $\lnot$           |
| 合取   | $\land$           |
| 析取   | $\lor$            |
| 异或   | $\overline{\lor}$ |
| 蕴涵   | $\rightarrow$     |
| 等价   | $\leftrightarrow$ |

> - 否定：非p
>
> - 合取：与，p而且q。“两个合起来看都要成立才成立”，所以叫合取。
>
> - 析取：或，p或者q。“析，分开，分散”，即“判断成立时分开看”，所以是或。
>
> - 蕴含：p蕴含q，如果p，则q。  $p\rightarrow q$假当且仅当p真而q假。
>   
>   （形象记忆：p≤q）
>   $$
>   \begin{array}{|c|c|c|}
>   \hline p & q & p \rightarrow q \\
>   \hline 0 & 0 & 1 \\
>   \hline 0 & 1 & 1 \\
>   \hline 1 & 0 & 0 \\
>   \hline 1 & 1 & 1 \\
>   \hline
>   \end{array}
>   $$
>   理解表中前两行：从一个错误的前提可以推出一切事情。
>   
>   表示p蕴含q（ $p\rightarrow q$）的术语：
>   
>   - p为q的充分条件
>   - q为p的必要条件
>   - 若p，则q
>   - 因为p，所以q
>   - 只要p，则q
>   - p（每）当q
>   - p仅当q（补全：仅当q的时候，才有可能p）
>   - 只有q才p
>   - 除非q才p **除非=只有**
>   - 除非q，否则非p：$\neg \mathbf{q} \rightarrow \neg \mathbf{p} \Leftrightarrow \mathbf{p} \rightarrow \mathbf{q}$
>   - ![A蕴涵B](Mathematical%20Logic.assets/Venn_A_subset_B.png)
>   
> - 等价：当且仅当。$\mathbf{p \leftrightarrow q}$ 真当且仅当p、q同时为真或同时为假。（形象记忆：p等于q）

一些对应的真值：

| $P$  | $Q$  | $P \land Q$ | $P \lor Q$ | $P \rightarrow Q$ | $P \leftrightarrow Q$ |
| ---- | ---- | ----------- | ---------- | ----------------- | --------------------- |
| $F$  | $F$  | $F$         | $F$        | $T$               | $T$                   |
| $F$  | $T$  | $F$         | $T$        | $T$               | $F$                   |
| $T$  | $F$  | $F$         | $T$        | $F$               | $F$                   |
| $T$  | $T$  | $T$         | $T$        | $T$               | $T$                   |

**命题符号化**

所谓命题符号化，就是用命题公式的符号串来表示给定的命题。

命题符号化的方法：

1. 明确给定命题的含义。
2. 对复合命题，找联结词，分解出各个原子命题。
3. 设原子命题符号，并用逻辑联结词联结原子命题符号，构成给定命题的符号表达式。

例：

- 如果我下班早，就去商店看看，除非我很累。

  p代表“我很累”，q代表“我下班早”，r代表“我去商店看看”

  $(\neg \mathbf{P}) \rightarrow(\mathbf{q} \rightarrow \mathbf{r})$

  还可表示为：$((\neg P) \wedge q)) \rightarrow r$

- 李四是自动化系的学生，他住在620A或620B

  p代表“李四是自动化系的学生”，q代表“李四住620A”，r代表“李四住620B”

  $\mathbf{p} \wedge((q \vee r) \wedge(\neg(q \wedge r)))$

  $p \wedge((q \wedge(\neg r)) \vee((\neg q) \wedge r))$

  自然语言中的“或”有两种用法如：1.张三或李四考了90分。2.第一节课上数学课或者上英语课。差异在于：当构成它们的简单命题都真时，前者为真，后者为假。称前者为相容或 $\vee$ , 后者为相异或 $(\overline{\vee})$

![image-20220103110100497](Mathematical%20Logic.assets/image-20220103110100497.png)

### 命题公式

命题常量（命题常元）：一个特定的命题，真值确定。

命题变量（命题变元）：用大写英文字母表示任何命题，称这些字母为命题变元。一个任意的、没有赋予具体内容的命题，真值可变。对命题变元作指派(给命题变元一个解释)：将一个常值命题赋予命题变元的过程，或者是直接赋给命题变元真值 $T$ 或 $F$ 的过程。

**命题公式（也称命题形式、合式公式）的定义：**命题公式是由命题变元和联结词按一下规则组成的符号串：

- 单个命题变元是个合式公式。

  ——此时称为原子命题公式

- 若 $A$ 是合式公式，则( $\lnot A$) 是合式公式。

- 若 $A$ 和 $B$ 是合式公式，则 $(A \land B)$，$(A \lor B)$，$(A \rightarrow B)$ 和 $(A \leftrightarrow B)$ 都是合式公式。

- 当且仅当有限次地应用2、3所得到的含有命题变元、联结词和括号的符号串是合式公式。

> 注意：
>
> - 上述是归纳定义，而不是循环定义。1是奠基，2、3是循环步骤
> - 公式中可以出现0、1, 可看成 $(\mathrm{p} \wedge(\neg \mathrm{p}))$ 与 $(\mathrm{p} \vee(\neg \mathrm{p}))$ 的缩写。
> - 相同联结词可以省略括号：$(p \vee q) \vee r$ 可以写成 $p \vee q \vee r$。析取合取等价可以省略，蕴含不行。
> - 优先级：运算次序优先级：$\lnot , \land , \lor , \rightarrow , \leftrightarrow$

### 赋值（解释、指派）

命题公式的值由它中命题变元的值完全确定。

设 $\alpha$ 为一个命题公式, $\alpha$ 中出现的所有命题变元都在 $p_{1}, p_{2}, \ldots, p_{n}$ 中, 对序列 $p_{1}, p_{2}, \ldots, p_{\mathrm{n}}$ 指 定的的任一真假值序列 $t_{1}, t_{2}, \ldots, t_{\mathrm{n}}$, 称为 $\alpha$ 的关于 $p_{1}, p_{2}, \ldots, p_{n}$ 的一个赋值 (assignment) , 其中 $t_{\mathrm{i}}=0$ 或1, $i \in N, 1 \leq i \leq n$.

- 若 $p_{1}, p_{2}, \ldots, p_{n}$ 的一个赋值使 $\alpha$ 为真，则 称此赋值为 $\alpha$ 的一个成真赋值。
- 若 $p_{1}, p_{2}, \ldots, p_{n}$ 的一个赋值使 $\alpha$ 为假，则 称此赋值为 $\alpha$ 的一个成假赋值。

### 真值表

命题公式在所有可能的赋值下所取值列成的表称为真值表。

$\mathrm{p} \rightarrow(\mathrm{q} \rightarrow \mathrm{r}) 、(\mathrm{p} \rightarrow \mathrm{q}) \rightarrow \mathrm{r}$ 的真值表：
$$
\begin{array}{|c|c|c|c|c|}
\hline \mathrm{p} & \mathrm{q} & \mathrm{r} & \mathrm{p} \rightarrow(\mathrm{q} \rightarrow \mathrm{r}) & (\mathrm{p} \rightarrow \mathrm{q}) \rightarrow \mathrm{r} \\
\hline 0 & 0 & 0 & 1 & 0 \\
\hline 1 & 0 & 0 & 1 & 1 \\
\hline 0 & 1 & 0 & 1 & 0 \\
\hline 0 & 0 & 1 & 1 & 1 \\
\hline 1 & 1 & 0 & 0 & 0 \\
\hline 1 & 0 & 1 & 1 & 1 \\
\hline 0 & 1 & 1 & 1 & 1 \\
\hline 1 & 1 & 1 & 1 & 1 \\
\hline
\end{array}
$$
$(\neg \mathrm{p}) \vee \mathrm{q} 、 \mathrm{p} \rightarrow \mathrm{q}$ 的真值表:
$$
\begin{array}{|c|c|c|c|}
\hline \mathrm{p} & \mathrm{q} & (\neg \mathrm{p}) \vee \mathrm{q} & \mathrm{p} \rightarrow \mathrm{q} \\
\hline 0 & 0 & 1 & 1 \\
\hline 0 & 1 & 1 & 1 \\
\hline 1 & 0 & 0 & 0 \\
\hline 1 & 1 & 1 & 1 \\
\hline
\end{array}
$$
**发现这两个真值表完全一样！**所以这两者完全等价。今后在运算中，由于蕴含的性质特别少，所以先把它换成$(\neg \mathrm{p}) \vee \mathrm{q}$。

### 命题公式的类型

- 命题公式$\alpha$称为重言式 (或永真式), 如果 $\alpha$ 关于其中出现的命题变元的所有赋值均为成真赋值.另一种说法：不论对 $P_1,\cdots,P_n$ 做任何指派，一个命题公式都是真（假），就称为重言式（矛盾式）。
- 命题公式 $\alpha$ 称为矛盾式 (永假式), 如果 $\alpha$ 对于其中出现的命题变元的所有赋值均为成假赋值.
- 一个命题公式 $\alpha$ 称为可满足式, 如果 $\alpha$ 对于其中出现的命题变元的某个赋值为成真赋值.

**若 $A$ 是永真式，则 $A$ 的置换式也是永真式。**

置换式：用合式公式代替 $P_i$ 得到的新的命题公式。

**与哑元的无关性：**

设命题公式 $\alpha$ 中出现的命题变元都在 $p_{1}, p_{2}, \ldots, p_{n}$ 中, $p_{n+1}, \ldots, p_{n+m}$ 是另外m 个不在 $\alpha$ 中出现的命题变元。

对于 $p_{1}, p_{2}, \ldots, p_{n}, p_{n+1}, \ldots$, $\mathrm{p}_{\mathrm{n}+\mathrm{m}}$ 的任意两个赋值: $\quad \alpha$ 取值与哑元取值无关。

### 等值式

不论对 $P_1,\cdots,P_n$ 做任何指派，若在所有可能的$2^{n}$个赋值下，两个命题公式 $A$ 和 $B$ 真值总是相同，那么称 $A$ 和 $B$ 是逻辑等价，记为 $A=B$ 或者 $A \Leftrightarrow B$。

等价定理：$A \Leftrightarrow B$ 当且仅当 $A \leftrightarrow B$ 为永真式。

$\Leftrightarrow$ 与$\leftrightarrow$ 的区别:

- $\leftrightarrow$ 是一种逻辑连接词，公式$A\leftrightarrow B$ 是命题公式，其中$\leftrightarrow$ 是一种逻辑运算，$A\leftrightarrow B$的结果仍是一个命题公式。
- $\Leftrightarrow$则是描述了两个公式A与B之间的一种逻辑等价关系，$A \Leftrightarrow B$表示”命题公式A等价于命题公式B“，$A \Leftrightarrow B$的结果不是命题公式。
- 计算机无法判断A、B是否逻辑等价，但是可以判断$A\leftrightarrow B$是否为永真式。

$\Leftrightarrow$ 的性质：

- 自反性： $A \Leftrightarrow A$ 
- 对称性： 若$A \Leftrightarrow B$ ，则$B \Leftrightarrow A$
- 传递性：若$A \Leftrightarrow B$，$B \Leftrightarrow C$，则$A \Leftrightarrow C$

如何判断两个公式是否等值？可以采用真值表法，将所有可能的赋值列出来，判断结果是否相等。

![image-20211108120822025](Mathematical%20Logic.assets/image-20211108120822025.png)

常用等值式

- 交换式：$A \vee B \Leftrightarrow B \vee A, A \wedge B \Leftrightarrow B \wedge A, A \leftrightarrow B \Leftrightarrow B \leftrightarrow A$

- 结合律：

  $(A \vee B) \vee C \Leftrightarrow A \vee(B \vee C)$

  $(A \wedge B) \wedge C \Leftrightarrow A \wedge(B \wedge C)$

  $(A \leftrightarrow B) \leftrightarrow C \Leftrightarrow A \leftrightarrow(B \leftrightarrow C)$

  蕴含连接词不具有结合律，如上。而对于一个$p \rightarrow q \rightarrow r$这样的式子，在人看来比较习惯于左结合，但是计算机却更倾向于右结合（例如，a=b=3，计算机是先执行b=3的），所以对于$p \rightarrow q \rightarrow r$的真实含义比较众说纷纭，还是把括号加上比较好。

- 分配律：

  $A \vee(B \wedge C) \Leftrightarrow(A \vee B) \wedge(A \vee C)$

  $A \wedge(B \vee C) \Leftrightarrow(A \wedge B) \vee(A \wedge C)$

  $A \rightarrow(B \rightarrow C) \Leftrightarrow(A \rightarrow B) \rightarrow(A \rightarrow C)$  蕴含是有分配律的。

  但是等价是没有分配律的。

  > 蕴含有分配律没有结合律，等价有结合律没有分配律。

  

- 否定律：

  双重否定律：$\neg \neg A \Leftrightarrow A$

  德摩根律：$\neg(A \vee B) \Leftrightarrow \neg A \wedge \neg B$，$\neg(A \wedge B) \Leftrightarrow \neg A \vee \neg B$

- 幂等律：$A \Leftrightarrow A \vee A, \quad A \Leftrightarrow A \wedge A$

- 蕴含等值式：$A \rightarrow B \Leftrightarrow \neg A \vee B$

- 假言易位：$A \rightarrow B \Leftrightarrow \neg B \rightarrow \neg A$ （逆否命题）

- 归谬律：$(A \rightarrow B) \wedge(A \rightarrow \neg B) \Leftrightarrow \rightarrow A$ （由一个前提推出了两个矛盾的结论，则说明假设是错的，即反证法）

- 吸收律：$A \vee(A \wedge B) \Leftrightarrow A, \quad A \wedge(A \vee B) \Leftrightarrow A$

- 等价等值式：$A \leftrightarrow B \Leftrightarrow(A \rightarrow B) \wedge(B \rightarrow A)$

- 等价否定等值式：$A \leftrightarrow B \Leftrightarrow \neg A \leftrightarrow \neg B$

- $A \rightarrow(B \rightarrow C) \Leftrightarrow(A \wedge B) \rightarrow C \Leftrightarrow B \rightarrow(A \rightarrow C)$

- $\begin{aligned} A \leftrightarrow B & \Leftrightarrow(A \wedge B) \vee(\neg A \wedge \neg B) \\ & \Leftrightarrow(\neg A \vee B) \wedge(A \vee \neg B) \end{aligned}$

- $(A \rightarrow C) \wedge(B \rightarrow C) \Leftrightarrow(A \vee B) \rightarrow C$

**置换定律：等价的置换还等价**

用等值演算法可以验证两个公式等值，但一般情况下，不能用等值演算法直接验证两个公式不等值。可以采用观察法，只要给出一个赋值使得这两个命题公式的真值不同，就表明它们不等值。当两个公式比较复杂，一时看不出使它们一个成真另一个成假的赋值时，可以先通过等值演算将它们化成容易观察真值的情况。

### 重言蕴含式

若 $A \rightarrow B$ 是个永真式，则称 $A$ 永真蕴涵 $B$，记作 $A \Rightarrow B$。

证明 $1$：假设前件为真，推出后件为真。

证明 $2$：假设后件为假，推出前件为假。

重要的重言蕴含式：

$P \land Q \Rightarrow P,P \land Q \Rightarrow Q$

$P,Q \Rightarrow P \land Q$

$\lnot P \land (P \lor Q) \Rightarrow Q$

$P \land (P \rightarrow Q) \Rightarrow Q$

$\lnot Q \land (P \rightarrow Q) \Rightarrow \lnot P$

$(P \rightarrow Q) \land (Q \rightarrow R) \Rightarrow P \rightarrow R$

性质：自反性、传递性、反对称性等

### 范式

只含有 $\lnot,\lor,\land$。

为什么需要范式？因为多个命题公式等值而形式不同。所以我们需要一个唯一且标准的逻辑表达式。

五个联结词，使用哪些联结词来定义范式？ $\lnot,\lor,\land$是完备的联结词集合，且$\lnot,\lor,\land$具有较多较好的性质。

文字：命题变元及其否定的统称。

合取式与析取式

- 合取式：用 $\land$ 联结命题变元或变元的否定构成的式子。

- 析取式：用 $\lor$ 联结命题变元或变元的否定构成的式子。

定理：一个简单析取式是重言式当且仅当它同时含某个命题变元和它的否定

定理：一个简单合取式是矛盾式当且仅当它同时包含某个命题变元和它的否定 

析取范式与合取范式：

- 析取范式：公式 $A$ 如果写为如下形式：$A_1 \lor A_2 \lor \cdots \lor A_n(n \ge 1)$ 其中每个 $A_i$ 是合取式，称之为 $A$ 的析取范式。

- 合取范式：公式 $A$ 如果写为如下形式：$A_1 \land A_2 \land \cdots \land A_n(n \ge 1)$ 其中每个 $A_i$ 是析取式，称之为 $A$ 的合取范式。

析取范式与合取范式的求法：

范式定理：任一命题公式都存在与之等值的析取范式和合取范式。

求法：

1. 先用相应公式去掉 $\rightarrow$ 和 $\leftrightarrow$

   $A \rightarrow B \Leftrightarrow \neg A \vee B$

   $\begin{aligned} A \leftrightarrow B & \Leftrightarrow(\neg A \vee B) \wedge(A \vee \neg B) \\ & \Leftrightarrow(A \wedge B) \vee(\neg A \wedge \neg B) \end{aligned}$

   上边那个公式多用于求合取范式，下面那个公式多用于求析取范式

2. 用德-摩根定律将 $\lnot$ 后移到命题变元之前

   $\neg \neg A \Leftrightarrow A$

   $\neg(A \vee B) \Leftrightarrow \neg A \wedge \neg B$

   $\neg(A \wedge B) \Leftrightarrow \wedge A \vee \neg B$

3. 用分配律、结合律、幂等律等公式进行整理，使之成为所要求的形式。

   $A \vee(B \wedge C) \Leftrightarrow(A \vee B) \wedge(A \vee C)$

   $A \wedge(B \vee C) \Leftrightarrow(A \wedge B) \vee(A \wedge C)$

注意，公式的析取范式与合取范式不唯一。所以需要主范式，使范式具有唯一性。



极小项：在一个有 $n$ 个命题变元的合取式中，每个变元或该变元的否定必出现且仅出现一次，称这个合取式为小项。

每一组指派有且只有一个极小项为 $T$。

析取范式 $A_1 \lor A_2 \lor \cdots \lor A_n$ 其中每个 $A_i$ 均为极小项，称之为**主析取范式**。



极大项：在一个有 $n$ 个命题变元的析取式中，每个变元或该变元的否定必出现且仅出现一次，称这个析取式为极大项。

每一组指派有且只有一个极大项为 $F$。

合取范式 $A_1 \land A_2 \land \cdots \land A_n$ 其中每个 $A_i$ 均为极大项，称之为**主合取范式。**

#### 求法

1. 列真值表
   1. 定理：在真值表中，一个公式的真值为 $T$ 的指派所对应的小项的析取，即为此公式的主析取范式。
   2. 定理：在真值表中，一个公式的真值为 $F$ 的指派所对应的大项的合取，即为此公式的主合取范式。
2. 公式的等价变换
   1. 先写出对应的析（合）取范式
   2. 补全缺少的变元，用永真（假）式联结
   3. 用分配律等公式加以整理

应用：

![image-20211108164558962](Mathematical%20Logic.assets/image-20211108164558962.png)

![image-20211108164611872](Mathematical%20Logic.assets/image-20211108164611872.png)

主析取范式与主合取范式的用途：

- 求公式的成真赋值和成假赋值
- 判断公式的类型
  - 公式A为重言式当且仅当A的主析取范式含全部$2^{n}$个极小项
  - 公式A为矛盾式当且仅当A的主析取范式不含任何极小项，此时，记A的主析取范式为0
  - A为可满足式当且仅当A的主析取范式中至少含一个极小项

![image-20220103114336815](Mathematical%20Logic.assets/image-20220103114336815.png)

n个命题变项的主析取范式（主合取范式）共有多少个？n个命题变项共可产生$2^{n}$个极小项（极大项），因而共可产生$\mathrm{C}_{2^{n}}^{0}+\mathrm{C}_{2^{n}}^{1}+\cdots+\mathrm{C}_{2^{n}}^{2^{n}}=2^{2 n}$个不同的主析取范式（主合取范式）。这与之前对真值表个数的讨论情况是一样的。

在要求将公式化为极小项、极大项的形式时，最后一步要按升序以m的形式排列！

### 联结词的完备集

什么是联结词？

- 联接词确定了复合命题构造方式
- 复合命题建立了真假值对应方式。

$\{0,1\}$ 上的 $n$ 元函数$f:\{0,1\}^{n} \longrightarrow\{0,1\}$，就称为一个n元真值函数（布尔函数）。因此，每个联结词C确定了一个真值函数$f_C$,每个真值函数也确定了一个联结词。

$n$ 元真值函数共有 $2^{2^{n}}$ 个

- 每一个命题公式对应一个真值函数
- 每一个真值函数对应无穷多个命题公式

![image-20211116011754106](Mathematical%20Logic.assets/image-20211116011754106.png)

用 $c_{1}, c_{2}, \ldots c_{k}$ 表示 $c\left(\right.$ 或 $\left.f_{c}\right)$ = 仅用 $\mathrm{c}_{1}, \mathrm{c}_{2}, \ldots \mathrm{c}_{\mathrm{k}}$ 可以构造一个命 题 $\alpha$ 与由 $c\left(\right.$ 或 $\left.f_{c}\right)$ 构造的命题等价 = 存在一个由 $\mathrm{c}_{1}, \mathrm{c}_{2}, \ldots \mathrm{c}_{\mathrm{k}}$ 构造的命题 $\alpha$, 使 $\alpha$ 在任意赋值 $<t_{1}, t_{2}, \ldots, t_{\mathrm{n}}>$ 下的值恰为 $\mathrm{f}_{\mathrm{c}}\left(t_{1}, t_{2}, \ldots t_{\mathrm{n}}\right)\left(\mathrm{f}\left(\mathrm{t}_{1}, \mathrm{t}_{2}, \ldots t_{\mathrm{n}}\right)\right)$

![image-20211116013827818](Mathematical%20Logic.assets/image-20211116013827818.png)

证明：$\{\neg, \vee, \wedge, \rightarrow\}$ 是联结词的一个完全集

只要证：对任 $k$ 元真值函数 $f$ ，存在仅使用 $\{\neg, \vee, \wedge, \rightarrow\}$ 中 联结词构造的 $k$ 元命题公式 $\alpha$ ，使得 $\alpha$ 在任意赋值 $<t_{1}, t_{2}, \ldots t_{k}>$ 下的值即为 $f\left(t_{1}, t_{2}, \ldots t_{k}\right)$。

对k归纳证明：

$\mathrm{k}=1$ 时，一元真值函数有四个 $\mathrm{f}_{1} 、 \mathrm{f}_{2} 、 \mathrm{f}_{3} 、 \mathrm{f}_{4}$ :

$\mathrm{f}_{1}: 0 \longrightarrow 0, \quad 1 \longrightarrow 0$
$\mathrm{f}_{2}: 0 \longrightarrow 1, \quad 1 \longrightarrow 1$
$\mathrm{f}_{3}: 0 \longrightarrow 0, \quad 1 \longrightarrow 1$
$\mathrm{f}_{4}: 0 \longrightarrow 1, \quad 1 \longrightarrow 0$

分别可以用 $\mathbf{p} \wedge(\neg \mathbf{p}) 、 \mathbf{p} \vee(\neg \mathbf{p}) 、 \mathbf{p}$ 和 $\neg \mathbf{p}$ 表示。此时命题成立。

设 $k<n$ 时命题成立, 下证 $k=n$ 时命题也成立

1. 设 $f\left(x_{1}, x_{2}, \ldots, x_{n}\right)$ 是一个 $n$ 元真值函数

   定义如下两个 $n-1$ 元真值函数 $f^{\prime} 、 f^{\prime \prime}:$
   $$
   \begin{aligned}
   &\mathrm{f}^{\prime}\left(\mathrm{x}_{2}, \mathrm{x}_{3}, \ldots, \mathrm{x}_{\mathrm{n}}\right)=\mathrm{f}\left(0, \mathrm{x}_{2}, \mathrm{x}_{3}, \ldots, \mathrm{x}_{\mathrm{n}}\right) \\
   &\mathrm{f}^{\prime \prime}\left(\mathrm{x}_{2}, \mathrm{x}_{3}, \ldots, \mathrm{x}_{\mathrm{n}}\right)=\mathrm{f}\left(1, \mathrm{x}_{2}, \mathrm{x}_{3}, \ldots, \mathrm{x}_{\mathrm{n}}\right)
   \end{aligned}
   $$
   $f\left(t_{1}, \cdots, t_{n}\right)= \begin{cases}f^{\prime}\left(t_{2}, \cdots, t_{n}\right) & t_{1}=0 \\ f^{\prime \prime}\left(t_{2}, \cdots, t_{n}\right) & t_{1}=1\end{cases}$

   由归纳假设, $f^{\prime}$ 和 $f$ "都可由仅由 $\{\neg, \vee, \wedge, \rightarrow\}$ 中 联结词所构造的 $n-1$ 元命题公式 $\alpha_{1} 、 \alpha_{2}$ 表示。设 $\alpha_{1}$ 、 $\alpha_{2}$ 中所含的命题变元设为 $\mathrm{p}_{2}, \mathrm{p}_{3}, \ldots, \mathrm{p}_{n}$.

2. $\mathrm{f}$ 可由 $\left(\neg \mathrm{p}_{1} \rightarrow \alpha_{1}\right) \wedge\left(\mathrm{p}_{1} \rightarrow \alpha_{2}\right)$ 表示

   当 $t_{1}=0$ 时,
   $$
   \begin{aligned}
   &\left(\neg p_{1} \rightarrow \alpha_{1}\right) \wedge\left(p_{1} \rightarrow \alpha_{2}\right) \text { 在 }<0, t_{2}, \ldots, t_{n}>\text { 下的值 } \\
   =& \alpha_{1} \text { 在 }<0, t_{2}, \ldots, t_{n}>\text { 下的值 } \\
   =& \alpha_{1} \text { 在 }<t_{2}, \ldots, t_{n}>\text { 下的值 } \\
   =& f^{\prime}\left(t_{2}, t_{3}, \ldots, t_{n}\right) \\
   =& f\left(0, t_{2}, t_{3}, \ldots, t_{n}\right) \\
   =& f\left(t_{1}, t_{2}, t_{3}, \ldots, t_{n}\right)
   \end{aligned}
   $$

   > 第一步怎么推出来的？分类讨论$p_1$为0还是为1，这个式子最后为：
   > $$
   > \begin{cases}\alpha_{1} & P_{1}=0 \\ \alpha_{2} & P_{1}=1\end{cases}
   > $$

   命题成立。

   同理可证, 当 $t_{1}=1$ 时命题也成立。



证明：$\{\neg, \rightarrow\}$是完备的

- $\alpha \vee \beta$ 可由 $(\neg \alpha) \rightarrow \beta$ 表示。
- $\alpha \wedge \beta$ 可由 $\neg(\alpha \rightarrow(\neg \beta))$ 表示

证明：$\{\neg, \vee\}$是完备的

- $\alpha \rightarrow \beta$ 可由 $(\neg \alpha) \vee \beta$ 表示
- $\alpha \wedge \beta$ 可由 $\neg((\neg \alpha) \vee(\neg \beta))$ 表示

证明：$\{\neg, \wedge\}$是完备的

- $\alpha \rightarrow \beta$ 可由 $\neg(\alpha \wedge(\neg \beta))$ 表示
- $\alpha \vee \beta$ 可由 $\neg((\neg \alpha) \wedge(\neg \beta))$ 表示

证明：$\{\vee, \wedge, \rightarrow, \leftrightarrow\}$ 不是联结词的完全集

- 总取0值的真值函数（矛盾式）不能由只含此集合中的联结词的命题形式来表示。因为这样的命题形式在其中的命题变元都取1时也取值1，而不为0。

在$\{\neg, \vee, \wedge, \rightarrow, \leftrightarrow\}$的子集中：

- $\{\neg, \vee, \wedge, \rightarrow, \leftrightarrow\}$ 是联结词的完备集
- 5个4元素子集中只有 $\{\vee, \wedge, \rightarrow, \leftrightarrow\}$ 不是联结 词的完备集。
- 3元素子集中, 只要含$\neg$就完备。所以10个3元素子集，4个不完备，6个完备。
- 2元素子集中，$\{\neg, \rightarrow\} 、\{\neg, \quad \vee\}, \quad\{\neg, \wedge\}$是完备的
- $\{\neg, \quad \leftrightarrow\}$是不完备的。观察这两者的真值表，在所有的情况中，成真赋值与成假赋值都是对半分的。所以从组合的角度来讲，这两者组成的逻辑表达式的真值表成真赋值与成假赋值也都是对半分的，不能构成其他联结词。

因为完备性，所以每一种真值表（真值函数）都可以用完备集里的符号表示出来：

![image-20220103124332268](Mathematical%20Logic.assets/image-20220103124332268.png)

![image-20220103124401853](Mathematical%20Logic.assets/image-20220103124401853.png)

**与非联结词与或非联结词**

与非式：$p \uparrow q \Leftrightarrow \neg(p \wedge q)$, $\uparrow$称作与非联结词

或非式：$p \downarrow q \Leftrightarrow \neg(p \vee q), \downarrow$ 称作或非联结词

$p \uparrow q$ 为假当且仅当 $p, q$ 同时为真

$p \downarrow q$ 为真当且仅当 $p, q$ 同时为假

可以证明，$\{\uparrow\}$与$\{\downarrow\}$都是联结词完备集，证明可以用$\{\neg, \vee\}$与$\{\neg, \wedge\}$完备进行转化。在实际运算中，如果要把公式化简成$\{\uparrow\}$与$\{\downarrow\}$表示的形式，一个比较难于想到的地方是要用 $q \uparrow q$来表示非q。

极小完备的联结词集合：对于一个完备的联结词集合A，从A中任意删去一个连接词后，得到一个新的联结词集合A1。若至少有一个公式不等价于仅包含A1中联结词所表示的任一公式，则称A为极小完备的联结词集合。

$\{\neg, \wedge\},\{\neg, \vee\},\{\neg, \rightarrow\},\{\neg, \nrightarrow\},\{\uparrow\},\{\downarrow\}$均为极小完备的联结词集合，而实际应用中常使用$\{\neg, \wedge, \vee\}$

## 推理

### 推理

推理是逻辑的研究对象：从前提出发推出结论的思维过程。

推理是由一组前提$\alpha_{1}, \alpha_{2}, \ldots, \alpha_{n}$推出结论$\beta$的过程。

直观上，正确的推理应该保证：如果前提正确，则结论也应该正确。

设 $\alpha_{1}, \alpha_{2}, \ldots, \alpha_{n}, \beta$ 都是命题公式，如果对$\alpha_{1}, \alpha_{2}, \ldots, \alpha_{n}, \beta$ 中出现的命题变元的任一赋值，若$\alpha_{1} \wedge \alpha_{2} \wedge \cdots \wedge \alpha_{n}$为假，或若$\alpha_{1} \wedge \alpha_{2} \wedge \cdots \wedge \alpha_{n}$为真时$\beta$亦为真，则称推理“ $\alpha_{1}, \alpha_{2}, \ldots, \alpha_{n}$ 推出 $\beta $”是有效的；否则，则称推理“ $\alpha_{1}, \alpha_{2}, \ldots, \alpha_{n}$ 推出 $\beta $”是无效的或不合理的。

> 注意这里与日常逻辑不同的一点是，前提为假时也是有效的。

在验证一个推理是否有效时，需检验在前提为真的时候结果是否为真，如判断$\alpha \rightarrow \beta 、 \alpha$ 推出 $\beta$ 是否有效时，需验证当前提均为真时结果是否为真。

![image-20220103134826703](Mathematical%20Logic.assets/image-20220103134826703.png)

当前提较多，验证起来较复杂时，可以 反过来验证，看看能否找到使前提为真且结论为假的赋值。

![image-20220103140025695](Mathematical%20Logic.assets/image-20220103140025695.png)

推理形式有效的充要条件：推理形式 “ $\alpha_{1}, \alpha_{2}, \ldots, \alpha_{n}$ 推出 $\beta$ ” 有效的充要条件是命题形式 $\left(\alpha_{1} \wedge \alpha_{2} \wedge \ldots \wedge \alpha_{n}\right) \rightarrow \beta$ 是重言式, 或 $\left(\alpha_{1} \wedge \alpha_{2} \wedge \cdots \wedge \alpha_{n}\right) \wedge \neg \beta$ 为矛盾式。因而，推理形式的有效性与命题公式的永真性可以互相化约。

逻辑蕴含的符号表达：前提: $\alpha_{1}, \alpha_{2}, \cdots, \alpha_{n}$ 结论: $\beta$ 推理正确记为 $\alpha_{1} \wedge \alpha_{2} \wedge \cdots \wedge \alpha_{n} \Rightarrow \beta$

- 若 $A \Rightarrow B, \mathrm{~A}$ 为重言式, 则 $\mathrm{B}$ 也是重言式。
- 若 $A \Rightarrow B, B \Rightarrow A$ 同时成立, 必有 $A \Leftrightarrow B$ 。
- 若 $A \Rightarrow B, B \Rightarrow C$, 则 $A \Rightarrow C$ 。
- 若 $A \Rightarrow B, A \Rightarrow C$, 则 $A \Rightarrow B \wedge C$ 。
- 若 $A \Rightarrow C, B \Rightarrow C$, 则 $A \vee B \Rightarrow C$ 。

推理定律：

- 附加律：$A \Rightarrow(A \vee B)$

- 化简律：$(A \wedge B) \Rightarrow A, \quad(A \wedge B) \Rightarrow B$

- 假言推理：$(A \rightarrow B) \wedge A \Rightarrow B$

- 拒取式：$(\mathrm{A} \rightarrow \mathrm{B}) \wedge \neg \mathrm{B} \Rightarrow \neg \mathrm{A}$

- 析取三段论：$(A \vee B) \wedge \neg A \Rightarrow B$；$(A \vee B) \wedge \neg B \Rightarrow A$

- 假言三段论：$(\mathrm{A} \rightarrow \mathrm{B}) \wedge(\mathrm{B} \rightarrow \mathrm{C}) \Rightarrow(\mathrm{A} \rightarrow \mathrm{C})$

- 等价三段论：$(A \leftrightarrow B) \wedge(B \leftrightarrow C) \Rightarrow(A \leftrightarrow C)$

- 构造性两难：$(A \rightarrow B) \wedge(C \rightarrow D) \wedge(A \vee C) \Rightarrow(B \vee D)$

- 构造性两难（特殊形式）：$(A \rightarrow B) \wedge(\neg A \rightarrow B) \Rightarrow B$

- 破坏性两难：$(A \rightarrow B) \wedge(C \rightarrow D) \wedge(\neg B \vee \neg D) \Rightarrow(\neg A \vee \neg C)$

- $\neg \mathrm{A} \Rightarrow(\mathrm{A} \rightarrow \mathrm{B})$, $\mathrm{B} \Rightarrow(\mathrm{A} \rightarrow \mathrm{B})$

- $\neg(\mathrm{A} \rightarrow \mathrm{B}) \Rightarrow \mathrm{A}$, $\neg(A \rightarrow B) \Rightarrow \neg B$

- $(\mathrm{B} \rightarrow \mathrm{C}) \Rightarrow(\mathrm{A} \rightarrow \mathrm{B}) \rightarrow(\mathrm{A} \rightarrow \mathrm{C})$

  $(\mathrm{B} \rightarrow \mathrm{C}) \Rightarrow(\mathrm{A} \vee \mathrm{B}) \rightarrow(A \vee C)$

  
  
  
  
  

![image-20220103143154433](Mathematical%20Logic.assets/image-20220103143154433.png)



### 推理演算

自然推理系统P中的推理规则：

- 前提引入规则：在证明的任何步骤都可以引入前提
- 结论引入规则：在证明的任何步骤所得到的结论都可以作为后继证明的前提
- 置换规则：在证明的任何步骤，命题公式的子公式都可以用等值的公式置换
- 由推理定律和结论引入规则所导出的推理规则
  - 假言推理规则：A蕴含B，A为真，故B为真
  - 附加规则：A为真，则A析取B为真
  - 化简规则：A合取B为真，则A为真
  - 拒取式规则：A蕴含B，B为假，则A为假
  - 假言三段论规则：A蕴含B，B蕴含C，则A蕴含C.
  - 析取三段论规则：A析取B为真，B为假，则A为真
  - 构造性二难推理规则：A蕴含B，C蕴含D，A析取C为真，则B析取D为真
  - 破坏性二难推理规则：A蕴含B，C蕴含D，非B析取非D为真，则非A析取非C为真
  - 合取引入规则：A为真，B为真，则A合取B为真

![image-20220103163604161](Mathematical%20Logic.assets/image-20220103163604161.png)

附加前提证明法：特征：结论带蕴含式时可以利用附加前提证明法。

> 欲证结论是析取式的时候也可以，因为析取式可以等价地转换为蕴含式。

欲证明：前提：$A_{1}, A_{2}, \ldots, A_{k}$ 结论：$C \rightarrow B$

等价地证明：前提：$A_{1}, A_{2}, \ldots, A_{k}, C$，结论：B

![image-20220103164248712](Mathematical%20Logic.assets/image-20220103164248712.png)

归谬法（反证法）：

欲证明：前提 $A_{1}, A_{2}, \ldots, A_{k}$ 结论：B。可以将$\neg B$加入前提，若推出矛盾，则得证推理正确。 在具体的证明中，这个“矛盾”一般是以$R \wedge \neg R$的形式出现的。

![image-20220103165028809](Mathematical%20Logic.assets/image-20220103165028809.png)

对于命题逻辑而言，任何一个问题的推理，都可以采取三种推理方法中的任何一种来证明。一般而言，对于结论是蕴含式或析取式的，大多数可以采取带附加前提的证明法。

事实上，经常要有将析取转换为蕴含的意识！

![image-20220103171712016](Mathematical%20Logic.assets/image-20220103171712016.png)

消解证明法：

消解证明法需要使用到归结规则:

前提：$ A \vee B$ , $ \neg A \vee C$, 结论：$B \vee C $

证明归结规则需要证明$(A \vee B) \wedge(\neg A \vee C) \rightarrow(B \vee C)$为真，进行逻辑化简即可。

将规则中的析取换成蕴含，发现这其实就是一个两难问题。消解证明法的本质其实是一个反证法，是要证明$\left(\alpha_{1} \wedge \alpha_{2} \wedge \cdots \wedge \alpha_{n}\right) \wedge \neg \beta$ 为矛盾式。

- 将每一个前提化成等值的合取范式，设所有合取范式的全部简单析取式为$A_{1}, A_{2}, \ldots, A_{t}$
- 将结论的否定化成等值的合取范式$B_{1} \wedge B_{2} \wedge \ldots \wedge B_{s}$，其中每个$B_{j}$是简单析取式
- 以 $A_{1}, A_{2}, \ldots, A_{t}$ 和 $B_{1}, B_{2}, \ldots, B_{s}$ 为前提，使用归结规则推出 0

![image-20220103170400078](Mathematical%20Logic.assets/image-20220103170400078.png)

![image-20220104072250358](Mathematical%20Logic.assets/image-20220104072250358.png)

## 一阶逻辑

命题逻辑能够解决的问题是有局限性的，只能进行命题间关系的推理，无法解决与命题的结构和成分有关的推理问题。

### 命题符号化

个体：将可以独立存在的客体（具体事物或抽象概念）称为个体或个体词，并用a、b、c......表示个体常元（表示具体事物的个体词），用x、y、z表示个体变元（表示抽象事物的个体词）。将个体变元的取值范围称为个体域，个体域可以是有穷或无穷集合。宇宙间一切事物组成的个体域为全总个体域。

谓词：将表示个体性质或彼此之间关系的词称为谓词，常用F、G、H表示谓词常元（表示具体性质或关系）或谓词变元（表示抽象的或泛指的性质或关系）。

n元谓词$P(x_1, x_2, ....,x_n)$：含n个个体变项的谓词，是定义在个体域上，值域为{0，1}的n元函数

- 一元谓词：表示事物的性质
- 多元谓词：表示事物之间的关系
- 0元谓词：不含个体变项的谓词，即命题常项或命题变项

![image-20220103175624402](Mathematical%20Logic.assets/image-20220103175624402.png)

量词：表示数量的词为量词

全称量词是自然语言中的“所有的”、“一切的”、“任意的”等的统称，用符号$\forall$表示。用$\forall x$表示个体域里的所有x；用$\forall x F(x)$表示个体域里所有x都有性质F。

存在量词是自然语言中的“有一个”、“至少有一个”、“存在着”等的统称，用符号$ \exists$ 表示，用$ \exists x$表示存在个体域里的x，用 $ \exists x F(x)$表示在个体域内存在x具有性质F。

![image-20220103180434606](Mathematical%20Logic.assets/image-20220103180434606.png)

同一命题在不同个体域中符号化形式可能不同，真假值也可能不同：

![image-20220103180724735](Mathematical%20Logic.assets/image-20220103180724735.png)

![image-20220103180754918](Mathematical%20Logic.assets/image-20220103180754918.png)

任取后一定是蕴含，存在后一定是合取。

举例：将命题“男人都比女人跑得快”符号化：

令F(x):x是男人，G(y):y是女人，H(x,y):x比y跑得快

命题符号化为：$\forall \mathrm{x}(\mathrm{F}(\mathrm{x}) \rightarrow \forall \mathrm{y}(\mathrm{G}(\mathrm{y}) \rightarrow \mathrm{H}(\mathrm{x}, \mathrm{y})))$

等值形式为：$\forall x \forall y(F(x) \wedge G(y) \rightarrow H(x, y))$

举例：每个实数都存在比它大的另外的实数

设个体域为实数集，L(x,y)：x小于y，则命题可符号化为$\forall x(\exists y(L(x, y)))$，注意到这个命题与$\exists y \forall x L(x, y)$不等价，所以**多个量词出现时，不能随意交换顺序。**

设个体域为全总个体域，R(x)：x是实数，L(x,y)：x小于y，则命题可符号化为$\forall x(R(x) \rightarrow \exists y(R(y) \wedge L(x, y)))$

设P(x,y)为二元谓词

- $(\forall x)(\forall y) P(x, y) \Leftrightarrow(\forall x)((\forall y) P(x, y)) \Leftrightarrow (\forall y)(\forall x) P(x, y)$

  对一切x和一切y都有关系P

- $(\forall x)(\exists y) P(x, y),(\forall x)(\exists y)$ 不可交换

  对一切x，都存在一个具有关系P

- $(\exists x)(\forall y) P(x, y)$

  存在一个x，对于任意y都有关系P

- $(\exists x)(\exists y) P(x, y) \Leftrightarrow(\exists x)((\exists y) P(x, y)) \Leftrightarrow \exists y)(\exists x) P(x, y)$

  有一个x，有一个y有关系P

![image-20220103183512620](Mathematical%20Logic.assets/image-20220103183512620.png)

![image-20220103184302112](Mathematical%20Logic.assets/image-20220103184302112.png)

### 一阶逻辑公式

当个体域名称集合D给出时，n元函数符号$f(x 1, x 2, \ldots, x n)$可以是$\mathrm{D}^{n} \rightarrow \mathrm{D}$的任意一个函数

项：

- 个体常元和个体变元是项
- 若$\varphi\left(x_{1}, x_{2}, \ldots, x_{n}\right)$是任意的n元函数，$t_{1}, t_{2}, \ldots, t_{n}$是任意的n个项，则$\varphi\left(t_{1}, t_{2}, \ldots, t_{n}\right)$是项
- 所有的项都是有限次使用前两步得到的，“项”相当于“复合个体”

原子公式：设设 $R\left(x_{1}, x_{2}, \ldots, x_{n}\right)$是任意的n元谓词，$t_{1}, t_{2}, \ldots, t_{n}$是任意的n个项，则称$R\left(t_{1}, t_{2}, \ldots, t_{n}\right)$是原子公式

![image-20220103191257105](Mathematical%20Logic.assets/image-20220103191257105.png)

![image-20220103191712141](Mathematical%20Logic.assets/image-20220103191712141.png)

项的作用是描述“复合个体”，相当于词组，不表达完整的判断；公式的作用是描述命题，代表完整的句子，表达判断。一般用小写英文字母表示函数，用大写英文字母表示公式，如$f\left(t_{1}, \ldots, t_{n}\right)$ 表示函数f作用到个体 $t_{1}, \ldots, t_{n}$ 得到的复合个体,$F\left(t_{1}, \ldots, t_{n}\right)$ 表示个体 $t_{1}, \ldots, t_{n}$ 是否具有性质 $\mathrm{F}$.

辖域：在公式 $\forall x A$ 和 $\exists x A$ 中, 称 $x$ 为指导变元, $A$ 为相应量词的辖域。

量词辖域的确定方法：

- 若量词后有括号，则括号内的子公式就是该量词的辖域
- 若量词后无括号，则与量词邻接的子公式为该量词的辖域

![image-20220103192351505](Mathematical%20Logic.assets/image-20220103192351505.png)

约束出现与自由出现：在 $\forall x$ 和 $\exists x$ 的辖域中, $x$ 的所有出现称为约束出现，A中不是约束出现的其他变元称为自由出现

![image-20220103192511834](Mathematical%20Logic.assets/image-20220103192511834.png)

约束变元与自由变元：设个体变元x在公式$\alpha$中出现：

- 若x在$\alpha$中的所有出现均为约束出现，则称x为$\alpha$的约束变元
- 若x不是$\alpha$的约束变元，则称x为$\alpha$的自由变元

 $\mathrm{x}$ 是 $\alpha$ 的自由变元 $\leftrightarrow \mathrm{x}$ 在 $\alpha$ 中有某处出现是自由出现

在一个公式中，某一个变元的出现既可以是自由的，又可以是约束的，为了研究方便而不致引起混淆，对于表示不同意思的个体变元，我们总是以不同的变量符号来表示之。

- 约束变元的换名规则：将量词中出现的指导变元及其辖域中此变元的所有**约束出现**都用新的个体变元取代。新变元一定要有别于改名辖域中的所有其它变元。

- 自由变元的换名规则：将公式中出现该自由变元的每一处自由出现都用新的个体变元替换。新变元不允许在原公式中以任何约束形式出现。

  

闭式：设A是任意的公式，若A中不含自由出现的个体变元，则称A为封闭的公式，简称闭式。要将含r个自由出现的个体变元的公式变成闭式，至少需要加上r个量词。

![image-20220103195327767](Mathematical%20Logic.assets/image-20220103195327767.png)

赋值仅仅针对自由出现的个体变元！如果一个个体变元是约束出现的，那么赋值对它不起作用！

![image-20220103195842241](Mathematical%20Logic.assets/image-20220103195842241.png)

一阶逻辑公式和命题公式一样，也可以分成：

- 永真式（逻辑有效式）：无成假解释和赋值
- 矛盾式（永假式）：无成真解释和赋值
- 可满足式：至少有一个成真解释和赋值

![image-20220103200933980](Mathematical%20Logic.assets/image-20220103200933980.png)

定理：重言式的代换实例都是永真式，矛盾式的代换实例都是矛盾式

![image-20220103201037954](Mathematical%20Logic.assets/image-20220103201037954.png)

注意：$F(y) \rightarrow \exists x F(x)$是永真式，$F(c) \rightarrow \exists x F(x)$也是永真式

### 一阶逻辑等值式

等值式：

以命题举例：

![image-20220103201753891](Mathematical%20Logic.assets/image-20220103201753891.png)

上面命题的(1)和(2)要么同为真，要么同为假，因而是等值的。定义：若 $A \leftrightarrow B$ 是永真式, 则称 $A$ 与 $B$ 是等值的，记作$A \Leftrightarrow B$, 并称 $A \Leftrightarrow B$ 为等值式

命题逻辑中基本等值式的代换实例：

![image-20220103202244396](Mathematical%20Logic.assets/image-20220103202244396.png)

量词否定等值式：

设A(x)是含x自由出现的公式：

- $\neg \forall x A(x) \Leftrightarrow \exists x \neg A(x)$
- $\neg \exists x A(x) \Leftrightarrow \forall x \neg A(x)$

![image-20220103202611651](Mathematical%20Logic.assets/image-20220103202611651.png)

量词辖域收缩与扩张等值式：

设A(x)是含x自由出现的公式，B中不含x的出现

- $\forall x(A(x) \vee B) \Leftrightarrow \forall x A(x) \vee B$
- $\forall x(A(x) \wedge B) \Leftrightarrow \forall x A(x) \wedge B$
- $\exists x(A(x) \vee B) \Leftrightarrow \exists x A(x) \vee B$
- $\exists x(A(x) \wedge B) \Leftrightarrow \exists x A(x) \wedge B$
- $\forall x(A(x) \rightarrow B) \Leftrightarrow \exists x A(x) \rightarrow B$
- $\forall x(B \rightarrow A(x)) \Leftrightarrow B \rightarrow \forall x A(x)$
- $\exists x(A(x) \rightarrow B) \Leftrightarrow \forall x A(x) \rightarrow B$
- $\exists x(B \rightarrow A(x)) \Leftrightarrow B \rightarrow \exists x A(x)$

![image-20220103203017828](Mathematical%20Logic.assets/image-20220103203017828.png)

![image-20220103203131495](Mathematical%20Logic.assets/image-20220103203131495.png)

 量词分配等值式：

设A(x)、B(x)是含x自由出现的公式

- $\forall x(A(x) \wedge B(x)) \Leftrightarrow \forall x A(x) \wedge \forall x B(x)$
- $\exists x(A(x) \vee B(x)) \Leftrightarrow \exists x A(x) \vee \exists x B(x)$

**注意 $\forall$ 对 $\vee$, $\exists$ 对 $\wedge$不具有分配律！**

置换规则：设 $\Phi(A)$ 是含公式 $A$ 的公式, $\Phi(B)$ 是用公式 $B$取代 $\Phi(A)$ 中的所有 $A$ 得到的公式, 若 $A \Leftrightarrow B$, 则$\Phi(A) \Leftrightarrow \Phi(B)$

换名规则：将公式 $A$ 中某量词的指导变元及其在辖域内的所有约束出现改成该量词辖域内末曾出现的某个个体变项, 其余部分不变, 记所得公式为 $A^{\prime}$, 则 $A^{\prime} \Leftrightarrow A$

![image-20220103204902185](Mathematical%20Logic.assets/image-20220103204902185.png)

变元易名后的分配律：

- $\forall x \forall y(A(x) \vee B(y)) \Leftrightarrow \forall x A(x) \vee \forall x B(x)$
- $\exists x \exists y(A(x) \wedge B(y)) \Leftrightarrow \exists x A(x) \wedge \exists x B(x)$

![image-20220103205106387](Mathematical%20Logic.assets/image-20220103205106387.png)

### 前束范式

在命题逻辑里，每一公式都有与之等值的范式。而对于谓词逻辑的公式来说，也有范式，其中前束范式与原公式是等值的，而其它范式与原公式只有较弱的关系。

设A为一个一阶逻辑公式，若A具有$Q_{1} x_{1} Q_{2} x_{2} \ldots Q_{k} x_{k} B$的形式，则称A为前束范式，其中$Q_{i}$ 为 $\forall$ 或 $\exists, 1 \leq i \leq k$，B称为公式A的母式（基式），B中不再含量词。

![image-20220103210048178](Mathematical%20Logic.assets/image-20220103210048178.png)

一阶逻辑中的任何公式都存在与之等值的前束范式，但其前束范式并不唯一。

设G是任一公式，通过下述步骤可将其转化为与之等价的前束范式：

- 消去公式中包含的联结词 $\rightarrow, \leftrightarrow$
- 反复使用德摩根率将$\neg$内移
- 使用分配等值式将量词左移
- 使用变元易名分配等值式将变元易名

![image-20220103210929322](Mathematical%20Logic.assets/image-20220103210929322.png)

![image-20220103211139015](Mathematical%20Logic.assets/image-20220103211139015.png)

将公式化成前束范式的过程中，第一步应先看看怎么换名能简化后续步骤！

![image-20220103211511133](Mathematical%20Logic.assets/image-20220103211511133.png)

![image-20220103211542027](Mathematical%20Logic.assets/image-20220103211542027.png)

### 一阶逻辑推理理论

谓词逻辑的推理：在一阶逻辑中，从前提$A_{1}, A_{2}, \cdots, A_{k}$推出结论B是正确的（有效的），若$A_{1} \wedge A_{2} \wedge \cdots A_{k} \rightarrow B$为永真式，记作$A_{1} \wedge A_{2} \wedge \cdots A_{k} \Rightarrow B$，否则称推理不正确。

![image-20220103230933961](Mathematical%20Logic.assets/image-20220103230933961.png)

常用的推理定律：

- $\forall x A(x) \Rightarrow \exists x A(x)$
- $\forall x A(x) \vee \forall x B(x) \Rightarrow \forall x(A(x) \vee B(x))$
- $\exists x(A(x) \wedge B(x)) \Rightarrow \exists x A(x) \wedge \exists x B(x)$
- $\forall x(A(x) \rightarrow B(x)) \Rightarrow \forall x A(x) \rightarrow \forall x B(x)$
- $\forall x(A(x) \rightarrow B(x)) \Rightarrow \exists x A(x) \rightarrow \exists x B(x)$
- $\forall x(A(x) \leftrightarrow B(x)) \Rightarrow \forall x A(x) \leftrightarrow \forall x B(x)$
- $\forall x(A(x) \leftrightarrow B(x)) \Rightarrow \exists x A(x) \leftrightarrow \exists x B(x)$

![image-20220103232226829](Mathematical%20Logic.assets/image-20220103232226829.png)

>  “有些个体不满足A”：指的是前面那部分整个为假！

- $\exists x \forall y A(x, y) \Rightarrow \forall y \exists x A(x, y)$
- $\forall y \forall x A(x, y) \Leftrightarrow \forall x \forall y A(x, y) \Rightarrow \exists y \forall x A(x, y)$
- $\forall x \forall y A(x, y) \Leftrightarrow \forall y \forall x A(x, y) \Rightarrow \exists x \forall y A(x, y)$
- $\exists y \forall x A(x, y) \Rightarrow \forall x \exists y A(x, y)$
- $\forall x \exists y A(x, y) \Rightarrow \exists y \exists x A(x, y) \Leftrightarrow \exists x \exists y A(x, y)$
- $\exists x \forall y A(x, y) \Rightarrow \exists x \exists y A(x, y) \Leftrightarrow \exists y \exists x A(x, y)$

![image-20220103232504527](Mathematical%20Logic.assets/image-20220103232504527.png)

推理规则：

量词的消去、引入规则：设x,y为个体变元符号，c为个体常量符号，y不在A(x)中约束出现 (A中 x不出现在 $\forall y, \exists y$ 的辖域内)

> 这个“不在A(x)中约束存在”说的其实就是在换名时不要换原来就有的!

- 全称量词消去规则：$(\forall x) A(x) \Rightarrow A(y),(\forall x) A(x) \Rightarrow A(c)$。

  若所有个体都有性质A，则任一个个体y必具备性质A

- 全称量词引入规则：$A(y) \Rightarrow(\forall x) A(x)$

  若任一个体y（自由变元）都有性质A，则所有个体必具备性质A

  限制：z不在A(y)中约束出现

- 存在量词消去规则：$(\exists x) A(x) \Rightarrow A(c)$。若一个个体有性质A，则必有某个个体有性质A。

  限制：$(\exists x) A(x)$中没有自由变元，且不含有c

- 存在量词引入规则：$A(c) \Rightarrow(\exists x) P(x)$

  若有个个体常元c具有性质A，则$(\exists x) P(x)$ 为真

  限制：x不出现在A(c)中

![image-20220103234624023](Mathematical%20Logic.assets/image-20220103234624023.png)

![image-20220103234723692](Mathematical%20Logic.assets/image-20220103234723692.png)

![image-20220103235148890](Mathematical%20Logic.assets/image-20220103235148890.png)

![image-20220103235202971](Mathematical%20Logic.assets/image-20220103235202971.png)

谓词演算的推理方法：

- 推导过程中可以引用命题演算中的前提引入规则和结论引入规则
- 如果结论是以蕴含形式（或析取形式）给出，我们可以使用附加前提证明法
- 如需消去量词，可以引用全称量词消去规则和存在量词消去规则
- 当所要求的结论可能被定量时，此时可引用全称量词引入规则和存在量词引入规则将其量词加入
- 在推导过程中，对消去量词的公式或公式中不含量词的子公式，可以引用命题演算中的基本等价公式和基本蕴含公式
- 在推导过程中，对含有量词的公式可以引用谓词中的基本等价公式和基本蕴含公式。

![image-20220104001342426](Mathematical%20Logic.assets/image-20220104001342426.png)

这个推理思路是对的，但是写法有问题！在假言推理中，必须要求变量的对应，而2中是命题变元，而4则是命题常元，显然无法对应。解决方法：在全称量词消去时，直接写成$H(s) \rightarrow M(s)$的形式

![image-20220104001720375](Mathematical%20Logic.assets/image-20220104001720375.png)

这个写法有问题，因为4中的a不一定就是2中的a，应当这样写：

![image-20220104001749423](Mathematical%20Logic.assets/image-20220104001749423.png)

> 如果有一个存在，一个任取，一定要先消存在，再消任取!

![image-20220104002223448](Mathematical%20Logic.assets/image-20220104002223448.png)

注意：个体变元加量词，前面可以加全称量词；个体常元只能加存在量词。

在用全称量词消去规则和存在量词消去规则消去量词、用全称量词引入规则和存在量词引入规则添加量词时，此量词必须位于整个公式的最前端，并且它的辖域为其后的整个公式。

![image-20220104003114485](Mathematical%20Logic.assets/image-20220104003114485.png)

结论明显矛盾，且从第一步开始就错了！消去全称量词的时候要求量词处于公式最左边，然而此时最左边是$\neg$，故不能消去。

![image-20220104003243594](Mathematical%20Logic.assets/image-20220104003243594.png)

![image-20220104003728351](Mathematical%20Logic.assets/image-20220104003728351.png)

![image-20220104003735806](Mathematical%20Logic.assets/image-20220104003735806.png)

> 第9步的蕴含分配律值得注意！

