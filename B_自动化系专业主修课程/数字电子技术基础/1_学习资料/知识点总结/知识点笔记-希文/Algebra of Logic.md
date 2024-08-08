## 逻辑代数

George Boole introduced binary variables and the three fundamental logic operations: AND, OR, and NOT.

Despite existence of relays and introduction of vacuum tube in 1906, digital electronics did not emerge for thirty years! Claude Shannon notices similarities between Boolean algebra and electronic telephone switches.

![image-20211031164349542](Algebra%20of%20Logic.assets/image-20211031164349542.png)

![image-20211031164408406](Algebra%20of%20Logic.assets/image-20211031164408406.png)

![image-20211031164451390](Algebra%20of%20Logic.assets/image-20211031164451390.png)

![image-20211031164555045](Algebra%20of%20Logic.assets/image-20211031164555045.png)

> 与直或弯！
>
> 读图时要注意，遇到圈就取反。

![image-20211031164823598](Algebra%20of%20Logic.assets/image-20211031164823598.png)

![image-20211031164853573](Algebra%20of%20Logic.assets/image-20211031164853573.png)

> 异或：取值相同就是0，取值不同就是1
>
> 可以用MOSFET来实现异或，也可以用基本的门电路组合而成。

![image-20211031165704340](Algebra%20of%20Logic.assets/image-20211031165704340.png)

对于公式17的证明：

可以使用真值表法，列出所有可能，然后得证。
$$
\begin{aligned}
\text { 右 } &=(A+B)(A+C) \\
&=A+A B+A C+B C \\
&=A(1+B+C)+B C \\
&=A+B C=左
\end{aligned}
$$
德摩根定理：与、或之间德相互转换。
$$
\begin{aligned}
&(A B)^{\prime}=A^{\prime}+B^{\prime} \\
&(A+B)^{\prime}=A^{\prime} B^{\prime}
\end{aligned}
$$
![image-20211031165908037](Algebra%20of%20Logic.assets/image-20211031165908037.png)

![image-20211031170006549](Algebra%20of%20Logic.assets/image-20211031170006549.png)

### 逻辑代数的基本定理

代入定理：在任何一个包含A的逻辑等式中，若以另外一个逻辑式代入式中A的位置，则等式依然成立。

代入定理是电路封装与层次化的理论依据。

![image-20211031170215116](Algebra%20of%20Logic.assets/image-20211031170215116.png)

反演定理：

![image-20211031170255115](Algebra%20of%20Logic.assets/image-20211031170255115.png)

对偶定理：

![image-20211031170402091](Algebra%20of%20Logic.assets/image-20211031170402091.png)

> 注意要区分对偶定理和反演定理！
>
> 对偶定理并不是使用德摩根定律来证明的，而是有更深层的内涵！

### 逻辑函数及其表示方法

![image-20211031171837770](Algebra%20of%20Logic.assets/image-20211031171837770.png)

真值表：

![image-20211031171925667](Algebra%20of%20Logic.assets/image-20211031171925667.png)

> 注意：真值表的输出没有相关性！

波形图：

![image-20211031172011914](Algebra%20of%20Logic.assets/image-20211031172011914.png)

![image-20211031172035970](Algebra%20of%20Logic.assets/image-20211031172035970.png)



**真值表到逻辑函数式的转换方法**

![image-20211031172300138](Algebra%20of%20Logic.assets/image-20211031172300138.png)

> 真值表的输出没有相关性！

![image-20211031174801321](Algebra%20of%20Logic.assets/image-20211031174801321.png)

![image-20211031174925304](Algebra%20of%20Logic.assets/image-20211031174925304.png)

### 逻辑函数的两种标准形式

两种标准形式，即最小项之和与最大项之积，这是对真值表的直接描述。对于n变量函数，有$2^n$个最小、最大项。

![image-20211031175319185](Algebra%20of%20Logic.assets/image-20211031175319185.png)

![image-20211031175339695](Algebra%20of%20Logic.assets/image-20211031175339695.png)

逻辑函数最小项之和的形式：

![image-20211031175459696](Algebra%20of%20Logic.assets/image-20211031175459696.png)

即利用$A+A^{\prime} = 1$的基本公式，补齐即可。

最大项：

![image-20211031175659145](Algebra%20of%20Logic.assets/image-20211031175659145.png)

> 注意：最大项是要为0，最小项是要为1。可以这样记忆：最大项为“0”比较困难，而最小项为“1”要更困难一些。

最大项对应的最小项：摩根定理

![image-20211031180450911](Algebra%20of%20Logic.assets/image-20211031180450911.png)

![image-20211031180614287](Algebra%20of%20Logic.assets/image-20211031180614287.png)

![image-20211031180517215](Algebra%20of%20Logic.assets/image-20211031180517215.png)

### 逻辑函数的化简

简化不一定是最好的，只是一个“trade off”——没有最好的，只有最合适的。

卡诺图化简法：

![image-20211031181554367](Algebra%20of%20Logic.assets/image-20211031181554367.png)

![image-20211031181615936](Algebra%20of%20Logic.assets/image-20211031181615936.png)

把真值表图形化：为了保证几何位置相邻的最小项在逻辑上也具有相邻性，这些数码不能按自然二进制数从小到大地顺序排列，而必须按图中地方式排列，以确保相邻的两个最小项仅有一个变量是不同的。

> 在几何位置上应当将卡诺图看成是上下、左右闭合的图形

如何理解卡诺图的形式？

1. 反正最高不会超过五到六阶，记住就好了。
2. 多引入一个变量：
   1. 原来的做一个镜像
   2. 在前面添0、添1

卡诺图的排布唯一吗？不唯一！在这种卡诺图的构建方式中，镜像的是低位。

> 同理，格雷码也不是唯一的。

<img src="Algebra%20of%20Logic.assets/image-20211031182022528.png" alt="image-20211031182022528" style="zoom:200%;" />

![image-20211031182148366](Algebra%20of%20Logic.assets/image-20211031182148366.png)

卡诺图化简的原则：

- 化简后的乘积项应包含函数式的所有最小项，即覆盖图中所有的1
- 乘积项的数目最少，即圈成的矩形最少
- 每个乘积项因子最少，即圈成的矩形最大。
- 元素不怕重复与重叠，但是要确保每个圈都要有新的“1”

> 每画下一个圈的时候都要想想这个圈能不能更大一些！

![image-20211031182957838](Algebra%20of%20Logic.assets/image-20211031182957838.png)

![image-20211031183024573](Algebra%20of%20Logic.assets/image-20211031183024573.png)

### 具有无关项的逻辑函数及其化简

约束项：在逻辑函数中，对输入变量取值的限制，在这些取值下为1的最小项称为约束项。

任意项：在输入变量某些取值下，函数值为1或为0不影响逻辑电路的功能，在这些取值下为1的最小项称为任意项。

逻辑函数中的无关项：约束项和任意项可以写入函数式，也可不包含在函数式中，因此统称为无关项。

![image-20211031184421332](Algebra%20of%20Logic.assets/image-20211031184421332.png)

![image-20211031184458932](Algebra%20of%20Logic.assets/image-20211031184458932.png)

![image-20211031184556140](Algebra%20of%20Logic.assets/image-20211031184556140.png)

> 注意：推导出逻辑化简式之后，原来的无关项已经区分不出来了。故搭建好的电路应在原有的物理条件的约束下应用。

![image-20211031184814612](Algebra%20of%20Logic.assets/image-20211031184814612.png)

多输出逻辑函数的化简：

![image-20211031185043582](Algebra%20of%20Logic.assets/image-20211031185043582.png)

![image-20211031185056541](Algebra%20of%20Logic.assets/image-20211031185056541.png)

**逻辑函数形式的变化**

![image-20211031185229734](Algebra%20of%20Logic.assets/image-20211031185229734.png)

> 用与非门也可以构成反相器！

核心：把+ 或者X 用德摩根定理消掉。
