## 组合逻辑电路

根据逻辑功能的不同特点，可以将数字电路分成两大类，一类称为组合逻辑电路(Combinational Logic Circuit,简称组合电路)，另一类称为时序逻辑电路（Sequential Logic Circuit，简称时序电路）

在组合逻辑电路中，任意时刻的输入出仅取决于该时刻的输入，与电路原状态无关。因而电路中也不能包含存储单元。

![image-20211030194641345](Combinational%20Logic.assets/image-20211030194641345.png)

We can use the Boolean expression as a recipe for constructing a circuit implementation using combinational logic gates.

![img](Combinational%20Logic.assets/Slide04.png)

![img](Combinational%20Logic.assets/Slide05.png)

The propagation delay for a sum-of-products circuit looks pretty short: the longest path from inputs to outputs includes an inverter, an AND gate and an OR gate. Can we really implement any Boolean equation in a circuit with a tPD of three gate delays?

Actually not, since building ANDs and ORs with many inputs will require additional layers of components, which will increase the propagation delay. We’ll learn about this in the next section.

The good news is that we now have straightforward techniques for converting a truth table to its corresponding sum-of-products Boolean equation, and for building a circuit that implements that equation.

![img](Combinational%20Logic.assets/Slide06.png)

Which approach is best: chains or trees? First we have to decide what we mean by “best.” When designing circuits, we’re interested in cost, which depends on the number of components, and performance, which we characterize by the propagation delay of the circuit.

Both strategies require the same number of components since the total number of pair-wise ANDs is the same in both cases. So it’s a tie when considering costs. Now consider propagation delay.

The chain circuit in the middle has a $t_{PD}$ of 3 gate delays, and we can see that the $t_{PD}$ for an N-input chain will be N-1 gate delays. The propagation delay of chains grows linearly with the number of inputs.

The tree circuit on the bottom has a $t_{PD}$  of 2 gates, smaller than the chain. The propagation delay of trees grows logarithmically with the number of inputs. Specifically, the propagation delay of tree circuits built using 2-input gates grows as log2(N). When N is large, tree circuits can have dramatically better propagation delay than chain circuits.

组合逻辑电路的设计方法

1. 逻辑抽象
   - 分析因果关系，确定输入输出变量
   - 定义逻辑状态的含义
   - 列出真值表
2. 写出函数式
3. 选定器件类型
4. 根据所选器件
   - 对逻辑式化简（用门）
   - 变换（用MSI）
   - 进行相应的描述（PLD）
5. 画出逻辑电路图，或下载到PLD
6. 工艺设计

### 编码器

编码器：将输入的每个高、低电平信号变成一个对应的二进制代码。分为普通编码器与优先编码器。

普通编码器：任何时刻只允许输入一个需要编码的电平信号

以三位二进制编码器为例：

![image-20211031020052520](Combinational%20Logic.assets/image-20211031020052520.png)

![tmp18A8](Combinational%20Logic.assets/tmp18A8.png)

优先编码器：

![image-20211031021427435](Combinational%20Logic.assets/image-20211031021427435.png)

![image-20211031021530162](Combinational%20Logic.assets/image-20211031021530162.png)

![image-20211031021546867](Combinational%20Logic.assets/image-20211031021546867.png)

> 注意：表中出现了三种$Y_{2}^{\prime} Y_{1}^{\prime} Y_{0}^{\prime}=111$的情况，而这些情况可以通过$Y_{\mathrm{s}}^{\prime}$ 和 $Y_{\mathrm{Ex}}^{\prime}$的不同状态加以区分。
>
> 而如果不加$Y_{\mathrm{s}}^{\prime}$ 和 $Y_{\mathrm{Ex}}^{\prime}$的话，会出现输出位数不够的情况。

为什么输入端用低电极表示输入信号？

因为数字电路最早出现的是TTL，而TTL输入悬空的时候从真值表看起来是高电平，所以用低电平表示输入信号。此外，这样也可以降低本级电路的功耗。

> $Y_{\mathrm{s}}^{\prime}$ 选通信号，在调试电路的时候非常有用。

![image-20211031023131181](Combinational%20Logic.assets/image-20211031023131181.png)

可以用控制端来扩展功能：比如，用两片8线-3线优先编码器，改装成16线-4线优先编码器，其中$A_{15}^{\prime}$的优先权最高。

两个芯片内部的后三位已经将优先级管理得很好了，唯一需要处理的就是级联问题。

![image-20211031024722141](Combinational%20Logic.assets/image-20211031024722141.png)

> 这里：
>
> 1. 第一片为高优先权
> 2. 只有（1）无编码输入时，（2）才允许工作
> 3. 第（1）片$\boldsymbol{Y}_{E X}^{\prime}=0$时表示对$A_{15}^{\prime} \sim A_{8}^{\prime}$的编码
> 4. 低3位输入应是两片的输出的“与”

![image-20211031024920956](Combinational%20Logic.assets/image-20211031024920956.png)

这只是一种编码方式，但是编码方式还有很多。

![image-20211031105816380](Combinational%20Logic.assets/image-20211031105816380.png)

![image-20211031105944353](Combinational%20Logic.assets/image-20211031105944353.png)

### 译码器

译码器（decoder）的逻辑功能是将每个输入的二进制代码译成对应的输出高、低电平信号或另外一个代码，因此译码是编码的反操作。

![image-20211031110348336](Combinational%20Logic.assets/image-20211031110348336.png)

![image-20211031110425810](Combinational%20Logic.assets/image-20211031110425810.png)

> 注意这个阵列，可编程阵列最早的思路就源于此：先把线都摆好，然后移动二极管，就可以实现各种逻辑运算。

![image-20211031110458337](Combinational%20Logic.assets/image-20211031110458337.png)

设计电路第一步：拿到想要的真值表，拿到真值表后要写逻辑式，但是在写逻辑式前要仔细思考真值表全不全，因为如果真值表不全的话真值表与逻辑式就没有唯一对应性了。

用二极管与门阵列构成的译码器虽然比较简单,但也存在两个严重的缺点。其一是电路的输入电阻较低而输出电阻较高,其二是输出的高,低电平信号发生偏移(偏离输入信号的高﹑低电平)。因此,通常只在一些大规模集成电路内部采用这种结构,而在一些中规模集成电路译码器中多半采用三极管集成门电路结构。


![image-20211031111128421](Combinational%20Logic.assets/image-20211031111128421.png)

联系前面的三态门总线结构。为了使每一时刻只有一个EN起作用，则需要将译码器的输出端接给这些EN，则天然地符合要求。

![image-20211031111558512](Combinational%20Logic.assets/image-20211031111558512.png)

> 这个芯片产生低电平输出，
>
> 但是是原信号输入（取反再取反）

![image-20211031111710377](Combinational%20Logic.assets/image-20211031111710377.png)

![image-20211031111845727](Combinational%20Logic.assets/image-20211031111845727.png)

> 在门电路地图形符号中，有时为了强调低电平有效，可以在输入端处加上小圆圈，同时在信号名称上加上非号。这个小圆圈代表了输入端的一个反相器。

利用附加控制端进行扩展：

例：用74HC138（3线-8线译码器）扩展成4线-16线译码器

![image-20211031112728895](Combinational%20Logic.assets/image-20211031112728895.png)

![image-20211031112751279](Combinational%20Logic.assets/image-20211031112751279.png)

二-十进制译码器

![image-20211031112948487](Combinational%20Logic.assets/image-20211031112948487.png)

> 二进码十进数（英语：Binary-Coded Decimal，简称BCD，中国大陆称BCD码或二-十进制编码）是一种十进制数字编码的形式。在这种编码下，每个十进制数字用一串单独的二进制比特来存储与表示。常见的有以4位表示1个十进制数字，称为压缩的BCD码（compressed or packed）；或者以8位表示1个十进制数字，称为未压缩的BCD码（uncompressed or zoned）。
>
> 这种编码技术，最常用于会计系统的设计里，因为会计制度经常需要对很长的数字做准确的计算。相对于一般的浮点式记数法，采用BCD码，既可保存数值的精确度，又可使电脑免除作浮点运算所耗费的时间。此外，对于其他需要高精确度的计算，BCD编码亦很常用。
>
> BCD码的主要优点是在机器格式与人可读的格式之间转换容易，以及十进制数值的高精度表示。BCD码的主要缺点是增加了实现算术运算的电路的复杂度，以及存储效率低。

![image-20211031112934799](Combinational%20Logic.assets/image-20211031112934799.png)

**用译码器设计组合逻辑电路**

基本原理：3位二进制译码器给出3变量的全部最小项；n位二进制译码器给出n变量的全部最小项；

而对于任何函数，将n位二进制译码输出的最小项组合起来，可获得任何形式的输入变量不大于n的组合函数。

![image-20211031113408872](Combinational%20Logic.assets/image-20211031113408872.png)

所有的最小项之和，也可以用摩根定理表示为取反后的与非（因为3-8译码器输出给的是低电平）。

用译码器表示逻辑函数，在扇出系数允许的情况下，输出可以反复使用。

如果负载超过扇出系数怎么办？可以用树的方式，一分为n然后带负载。

> 注意tree和chain的方式！用tree更好，这里还考虑到了时序中的概念。

本章我们看到的芯片内部图，基本上从输入到输出经过的门是一样的，即使不一样也要加上反相器。这样的设计一是可以使信号质量更高，此外也考虑到了时序的问题。

### 显示译码器

**七段字符显示译码器**

为了能以十进制数码直观地显示数字系统的运行数据,目前广泛使用了七段字符显示器,或称为七段数码管。这种字符显示器由七段可发光的线段拼合而成。常见的七段字符显示器有半导体数码管和液晶显示器两种。

发光二极管使用的材料与普通的硅二极管和锗二极管不同,有磷砷化镓﹑磷化镓、砷化镓等几种,而且半导体中的杂质浓度很高。当外加正向电压时,大量的电子和空穴在扩散过程中复合,其中一部分电子从导带跃迁到价带,把多余的能量以光的形式释放出来,便发出一定波长的可见光。

![image-20211031114638874](Combinational%20Logic.assets/image-20211031114638874.png)

在BS201等一些数码管中还在右下角增设了一个小数点，形成了所谓八段数码管。八段发光二极管的阴极是做在一起的，属于共阴极类型。为了增加使用的灵活性，同一规格的数码管一般都有共阴极和共阳极两种类型可供选用。

半导体数码管不仅具有工作电压低、体积小、寿命长、可靠性高等优点，而且响应时间短，亮度也比较高。它的缺点是工作电流比较大，每一段的工作电流在10mA左右。

另一种常用的七段字符显示器是液晶显示器（Liquid Crystal Display，简称LCD）。液晶是一种既具有液体的流动性又具有光学特性的有机化合物，它的透明度和呈现的颜色受外加电场的影响，利用这一特点便可做成字符显示器。

在没有外加电场的情况下，液晶分子按一定取向整齐地排列着。这时液晶为透明状态，射入的光线大部分由反射电极反射回来，显示器呈白色。在电极上加上电压以后，液晶分子因电离而产生正离子，这些正离子在电场作用下运动并碰撞其他液晶分子，破坏了液晶分子的整齐排列，使液晶呈现混浊状态。这时射入的光线散射后仅有少量反射回来，故显示器呈暗灰色。这种现象称作动态散射效应。外加电场消失后，液晶又恢复到整齐排列的状态。如果将七段透明的电极排列成8字形，那么只要选择不同的电极组合并加以正电压，便能显示出各种字符来。

![image-20211031122824259](Combinational%20Logic.assets/image-20211031122824259.png)

为了使离子撞击液晶分子的过程不断进行,通常在液晶显示器的两个电极上加以数十至数 百周的交变电压对交变电压的控制可以用异或门实现。v1是外加的固定频率的对称方波电压。当 $A=0$ 时, LCD 两端的电压 $v_{\mathrm{L}}=0$, 显示器不工作, 呈白色; 当 $A=1$ 时, $v_{L}$ 为幅度等于两倍 $v_{1}$ 的对称方波, 显示器工作, 呈暗灰色。各点电压的波形示于图 4.4.12 (b) 中.

![image-20211031123016986](Combinational%20Logic.assets/image-20211031123016986.png)

液晶显示器的最大优点是功耗极小，工作电压也很低，但是由于它本身不会发光，仅仅靠反射外界光线显示字形，所以亮度很差。此外，它的响应速度较低，这就限制了它在快速系统中的应用。

BCD-七段显示译码器

![image-20211031123554864](Combinational%20Logic.assets/image-20211031123554864.png)

![image-20211031123647393](Combinational%20Logic.assets/image-20211031123647393.png)

![tmpCF3A](Combinational%20Logic.assets/tmpCF3A.png)

![image-20211031123733814](Combinational%20Logic.assets/image-20211031123733814.png)

![image-20211031123749773](Combinational%20Logic.assets/image-20211031123749773.png)

![image-20211031123832322](Combinational%20Logic.assets/image-20211031123832322.png)

![image-20211031123924481](Combinational%20Logic.assets/image-20211031123924481.png)

![image-20211031123958467](Combinational%20Logic.assets/image-20211031123958467.png)

![image-20211031124124370](Combinational%20Logic.assets/image-20211031124124370.png)

还有其他显示译码器，如ＭＣ１４５４７

这个的思路是如果出现１０－１５，就不输出，而不是像之前的那样显示乱码。

![image-20211031125202167](Combinational%20Logic.assets/image-20211031125202167.png)

这个译码电路与之前的译码电路可以完全一样。

### 数据选择器

数据选择器在数字电路中像一个单刀多掷的开关。

在数字信号的传输过程中,有时需要从一组输入数据中选出某一个来,这时就要用到一种称为数据选择器(Data Selector)或多路开关( Multiplexer , MUX)的逻辑电路。数据选择器是一种常用模块,最小的是二选一数据选择器。其逻辑图形符号如下图所示。该符号表示通过SEL确定Y从A和B中选哪一个数据,真值表如下表

![image-20211031125616524](Combinational%20Logic.assets/image-20211031125616524.png)

![image-20211031125628728](Combinational%20Logic.assets/image-20211031125628728.png)

所以，可以用下图进行实现。

![tmp2C86](Combinational%20Logic.assets/tmp2C86.png)

分析双4选1数据选择器：

![image-20211031125833209](Combinational%20Logic.assets/image-20211031125833209.png)

> 这个TG模块是CMOS传输门，一个PMOS和一个NMOS并联，也就是模拟开关。
>
> ![tmpE9EB](Combinational%20Logic.assets/tmpE9EB-16364336561546.png)

![image-20211031125840006](Combinational%20Logic.assets/image-20211031125840006.png)

4选1选择器是指从4个输入数据中选出一个送到输出端，双4选1包含两个完全相同的4选1数据选择器，两个数据选择器有公共的地址输入端，而数据输入端和输出端是各自独立的。通过给定不同的地址代码（即A1、A0的状态），即可从4个输入数据中选出所要的一个，并送至输出端Y。而S1、S2是附加控制端，用于控制电路工作状态和扩展功能。

![image-20211031130209968](Combinational%20Logic.assets/image-20211031130209968.png)

如果用二选一数据选择器组装成四选一数据选择器的话，则需要3个二选一数据选择器（低位的各自负责，有两个二选一，高位的再来一个负责，一共有三个）。从上边的74HC153也能看出是三个二选一选择器。

![image-20211031131452673](Combinational%20Logic.assets/image-20211031131452673.png)

用数据选择器设计组合电路：数据选择器中含有地址线的所有最小项，且用最小项之和表示，也就是说它可以实现任何两变量的逻辑函数。因为要取某一个最小项只需要将数据接高电平或者是低电平，就可以提供两变量所有最小项之和的形式。但是这样太浪费了。但如果从输入端引入另外一个变量的话，比如两变量的数据选择器，就可以实现三变量的四个最小项（因为两变量那个等式一共有四项），就可以实现任意的三变量的逻辑函数。即：具有n位地址输入的数据选择器，至少可产生输入变量不大于n+1的组合函数。

> 如果把A1、A0视为两个输入逻辑变量，同时把D0、D1、D2和D3取为第三个输入逻辑变量A2的不同状态(即A2、/A2、1或0)，便可产生所需要的任何一种三变量A2、A1、A0的组合逻辑函数。可见，利用具有n位地址输入的数据选择器可以产生任何一种输入变量数不大于n +1的组合逻辑函数。
>
> 为什么足够表示n+1？可以从卡诺图入手分析。看不能化简的最大输入。

用译码器和数据选择器表示逻辑函数有什么区别？

译码器的输出端可以反复使用，产生多种输出函数；但是数据选择器只能产生一个输出函数。

例：

![image-20211031133048798](Combinational%20Logic.assets/image-20211031133048798.png)

![img](Combinational%20Logic.assets/Slide23.png)

Why are MUXes interesting? One answer is that they provide a very elegant and general way of implementing a logic function. Consider the 8-to-1 MUX shown on the right. The 3 inputs — A, B, and CIN — are used as the three select signals for the MUX. Think of the three inputs as forming a 3-bit binary number. For example, when they’re all 0, the MUX will select data input 0, and when they’re all 1, the MUX will select data input 7, and so on.

How does make it easy to implement the logic function shown in the truth table? Well, we’ll wire up the data inputs of the MUX to the constant values shown in the output column in the truth table. The values on the A, B and CIN inputs will cause the MUX to select the appropriate constant on the data inputs as the value for the COUT output.

If later on we change the truth table, we don’t have to redesign some complicated sum-of-products circuit, we simply have to change the constants on the data inputs. Think of the MUX as a table-lookup device that can be reprogrammed to implement, in this case, any three-input equation. This sort of circuit can be used to create various forms of programmable logic, where the functionality of the integrated circuit isn’t determined at the time of manufacture, but is set during a programming step performed by the user at some later time. Modern programmable logic circuits can be programmed to replace millions of logic gates. Very handy for prototyping digital systems before committing to the expense of a custom integrated circuit implementation.

![image-20211109112109449](Combinational%20Logic.assets/image-20211109112109449.png)

### 加法器

**一位加法器**

半加器：

![image-20211031141005489](Combinational%20Logic.assets/image-20211031141005489.png)

全加器：

![image-20211031141036547](Combinational%20Logic.assets/image-20211031141036547.png)

![image-20211031141058866](Combinational%20Logic.assets/image-20211031141058866.png)

**多位加法器**

串行进位加法器：

只要依次将低位全加器的进位输出端CO接到高位全加器的进位输入端CI，就可以构成多位加法器了。显然，每一位的相加结果都必须等到第一位的进位产生以后才能建立起来，因此将这种结构的电路称为串行进位加法器（或称为行波进位加法器）

![image-20211031141855087](Combinational%20Logic.assets/image-20211031141855087.png)

这种加法器的最大缺点是运算速度慢。在最不利的情况下,做一次加法运算需要经过4个全加器的传输延迟时间(从输入加数到输出状态稳定建立起来所需要的时间)才能得到稳定可靠的运算结果。但考虑到串行进位加法器的电路结构比较简单,因而在对运算速度要求不高的设备中,这种加法器仍不失为一种可取的电路。

怎么加速？为了提高运算速度，必须设法减小由于进位信号逐级传递所耗费的时间m不使用代入定理，使用一个庞大的电路，自己算：

![image-20211031142211089](Combinational%20Logic.assets/image-20211031142211089.png)

采用这种结构形式的加法器称为超前进位加法器（Carry Look-ahead），也称为快速进位（Fast Carry）加法器。

### 数值比较器

在一些数字系统（如数字计算机）当中经常要求比较两个数值的大小，为完成这一功能设计的各种逻辑电路统称为数值比较器。

**1位数值比较器**

首先讨论两个1位二进制数A和B相比较的情况，这时有三种可能。

1. $A>B$ ( 即 $A=\mathbf{1} 、 B=\mathbf{0}$ ), 则 $A B^{\prime}=\mathbf{1}$, 故可以用 $A B^{\prime}$ 作为 $A>B$ 的输出信号 $Y_{(A>B)}$
2. $A<B($ 即 $A=\mathbf{0} 、 B=\mathbf{1})$, 则 $A^{\prime} B=\mathbf{1}$, 故可以用 $A^{\prime} B$ 作为 $A<B$ 的输出信号 $Y_{(A<B)}$
3. $A=B$, 则 $A \odot B=1$, 故可以用 $A \odot B$ 作为 $A=B$ 的输出信号 $Y_{(A=B)}$

![image-20211109094423721](Combinational%20Logic.assets/image-20211109094423721.png)

**多位数值比较器**

原理：从高位比起，只有高位相等，才比较下一位。

$\begin{aligned} Y_{(A>B)}=& A_{3} B_{3}^{\prime}+\left(A_{3} \odot B_{3}\right) A_{2} B_{2}^{\prime}+\left(A_{3} \odot B_{3}\right)\left(A_{2} \odot B_{2}\right) A_{1} B_{1}^{\prime} \\ &+\left(A_{3} \odot B_{3}\right)\left(A_{2} \odot B_{2}\right)\left(A_{1} \odot B_{1}\right) A_{0} B_{0}^{\prime} \\ &+\left(A_{3} \odot B_{3}\right)\left(A_{2} \odot B_{2}\right)\left(A_{1} \odot B_{1}\right)\left(A_{0} \odot B_{0}\right) I_{(A>B)} \end{aligned}$

$\begin{aligned} Y_{(A<B)}=& A_{3}^{\prime} B_{3}+\left(A_{3} \odot B_{3}\right) A_{2}^{\prime} B_{2}+\left(A_{3} \odot B_{3}\right)\left(A_{2} \odot B_{2}\right) A_{1}^{\prime} B_{1} \\ &+\left(A_{3} \odot B_{3}\right)\left(A_{2} \odot B_{2}\right)\left(A_{1} \odot B_{1}\right) A_{0}^{\prime} B_{0} \\ &+\left(A_{3} \odot B_{3}\right)\left(A_{2} \odot B_{2}\right)\left(A_{1} \odot B_{1}\right)\left(A_{0} \odot B_{0}\right) I_{(A<B)} \end{aligned}$

$Y_{(A=B)}=\left(A_{3} \odot B_{3}\right)\left(A_{2} \odot B_{2}\right)\left(A_{1} \odot B_{1}\right)\left(A_{0} \odot B_{0}\right) I_{(A=B)}$

或者也可以先搭好两个电路，之后$Y_{(A>B)}=\left(Y_{(A<B)}+Y_{(A=B)}\right)^{\prime}$

$I_{(A>B)} 、 I_{(A<B)}$ 和 $I_{(A=B)}$ 是来自低位的比较结果，当相比较的两数都只有4位，没有来自低位的比较结果时，应该令$I_{(A>B)}=I_{(A<B)}=0, I_{(A=B)}=1$

数值比较器74HC85的逻辑图：

![image-20211109101239775](Combinational%20Logic.assets/image-20211109101239775.png)

![image-20211109101650142](Combinational%20Logic.assets/image-20211109101650142.png)

![image-20211109111939225](Combinational%20Logic.assets/image-20211109111939225.png)

### Read-only Memory

![img](Combinational%20Logic.assets/Slide25.png)

 Where MUXes are good for implementing truth tables with one output column, read-only memories are good for implementing truth tables with many output columns.

One of the key components in a read-only memory is the decoder which has K select inputs and $2^{K}$ data outputs. Only one of the data outputs will be 1 (or HIGH) at any given time, which one is determined by the value on the select inputs. The Jth output will be 1 when the select lines are set to the binary representation of J.

![img](Combinational%20Logic.assets/Slide26.png)

The three inputs to the function (A, B, and CI) are connected to the select lines of a 3-to-8 decoder. The 8 outputs of the decoder run horizontally in the schematic diagram and each is labeled with the input values for which that output will be HIGH. So when the inputs are 000, the top decoder output will be HIGH and all the other decoder outputs LOW. When the inputs are 001 — *i.e.*, when A and B are 0 and CI is 1 — the second decoder output will be HIGH. And so on.

![img](Combinational%20Logic.assets/Slide27.png)

So how do we use all this circuitry to implement the function described by the truth table? For any particular combination of input values, exactly one of the decoder outputs will be HIGH, all the others will be low. Think of the decoder outputs as indicating which row of the truth table has been selected by the input values. All of the pulldown switches controlled by the HIGH decoder output will be turned ON, forcing the vertical column to which they connect LOW.

By changing the locations of the pulldown switches, this read-only memory can be programmed to implement any 3-input, 2-output function.

> 以上的电路其实是一个用ROM实现全加器的过程，通过这个过程我们可以发现，用类似的ROM电路可以实现任意的逻辑函数，进而实现可编程器件。

If the ROM has N inputs and M outputs, then the switch matrix will have $2^{N}$rows and M output columns, corresponding exactly to the size of the truth table.

### 组合逻辑中的竞争-冒险现象

As the inputs to the ROM change, various decoder outputs will turn off and on, but at slightly different times. As the decoder lines cycle, the output values may change several times until the final configuration of the pulldown switches is stable. So ROMs are not lenient and the outputs may show the glitchy behavior discussed earlier.

> "glitch" 毛刺状的信号

对毛刺状信号的讨论如下：

![img](Combinational%20Logic.assets/Slide21.png)

本质上是因为各信号到输出经过的“门数”不同而造成的信号传播延迟。

从卡诺图的角度来分析，当在卡诺图中发现两个圆相切的时候，在电路中一定会出现竞争-冒险现象。因为这两个圈只有一个信号发生变化，而在电路实现中一定会隔着一个反相器，这时就会凑出竞争冒险。

所以，再接入一个AB的信号，因为或门是lenient，所以当AB为1时输出不随着C的变化而变化。所以，数学逻辑式上的最简并不一定代表着电路中的“最优”

![image-20211109110935393](Combinational%20Logic.assets/image-20211109110935393.png)

> Output guaranteed to be valid when **all** inputs have been valid for at least $ t_{P D}$, and outputs may become invalid no earlier than $ t_{C D}$ after an input changes.

![image-20211109111239401](Combinational%20Logic.assets/image-20211109111239401.png)

以CMOS为例，在上图的延迟时间造成的影响中，从物理实现上分析，由于A为1决定了Z就是1，故不会因为B的变化而导致出现中间无法确定的信号，Z一直是0。从这个角度上来讲，把CMOS输出门叫做Lenient（宽容的） combinational device，因为它具有更好的容差特性。

讨论竞争-冒险现象是因为之前的分析与设计都是在输入、输出处于稳定的逻辑电平下进行的。为了保证系统工作的可靠性，有必要再观察一下当输入信号逻辑电平发生变化的瞬间电路的工作情况。

![image-20211109113206199](Combinational%20Logic.assets/image-20211109113206199.png)

应当指出，有竞争现象时不一定都会产生尖峰脉冲，例如，在与门电路中，如果在 $B$ 上升到 $V_{\mathrm{IL}(\max )}$ 之前 $A$ 已经降到了 $V_{\mathrm{IL}(\max )}$ 以下 (如图中虚线所示)，这时输出端不会产生尖峰脉冲。同理，在或门电路中，若A下降到$V_{IH(\min )}$以前B已经上升到$V_{IH(\min )}$以上（如图中虚线所示），输出端也不会有尖峰脉冲产生。

> 只有一个变化中：格雷码。格雷码在任何时刻保证只有一个信号发生改变，所以最大程度地规避了竞争冒险。

如果与门和或门是复杂数字系统中的两个门电路, 而且 $A 、 B$ 又是经过不同的传输途径到达的,那么在设计时往往难于准确知道 $A 、 B$ 到达次序的先后, 以及它们在上升时间和下降时间上的细微差异。因此,我们只能说只要存在竞争现象,输出就有可能出现违背稳态下逻辑关系的尖峰脉冲。由于竞争而在电路输出端可能产生尖峰脉冲的现象就称为竞争-冒险。

![image-20211109113546042](Combinational%20Logic.assets/image-20211109113546042.png)

**如何检查竞争-冒险现象？**

![image-20211109113700625](Combinational%20Logic.assets/image-20211109113700625.png)

> 因为A和$A^{\prime}$肯定差着一个反相器，所以经过的时间不一样，而这两个信号接入同一个门的输入中，就会出现可能两个输入同时变化的情况。

这种方法虽然简单,但局限性太大,因为多数情况下输人变量都有两个以上同时改变状态的可能性。如果输入变量的数目又很多,就更难于从逻辑函数式上简单地找出所有产生竞争——冒险现象的情况了。现在也有用计算机软件模拟电路的方法判断竞争-冒险现象，但是，只有最终实践检查的结果才是最终的结论。

**消除竞争冒险现象的方法**

![image-20211109115637695](Combinational%20Logic.assets/image-20211109115637695.png)

![image-20211109115715623](Combinational%20Logic.assets/image-20211109115715623.png)

> 即把$Y= A + A^{\prime}$时的逻辑条件作为一个逻辑输入接入到电路中，既可以消除这时的竞争冒险现象。

将上述三种方法比较一下不难看出,接滤波电容的方法简单易行,但输出电压的波形随之变坏。因此,只适用于对输出波形的前、后沿无严格要求的场合。引入选通脉冲的方法也比较简单,而且不需要增加电路元件。但使用这种方法时必须设法得到一个与输入信号同步的选通脉 冲,对这个脉冲的宽度和作用的时间均有严格的要求。至于修改逻辑设计的方法,倘能运用得 当, 有时可以收到令人满意的效果。例如,在图 4. $9.6$ 所示的电路中,如果门 $G_{5}$ 在电路中本来就 已存在, 那么只需增加一根连线,把它的输出引到门 $G_{4}$ 的一个输人端就行了, 既不必增加门电路，又不给电路的工作带来任何不利的影响。然而，这样有利的条件并不是任何时候都存在，而且这种方法能够解决的问题也是有限的。

### 电路设计

1. ![image-20211031112948487](Combinational%20Logic.assets/image-20211031112948487.png)

   ![image-20211111124424044](Combinational%20Logic.assets/image-20211111124424044.png)

   > 这里是利用了二-十进制译码器拒绝补码的功能，引入约束项进行化简。

2. ![image-20211111124922557](Combinational%20Logic.assets/image-20211111124922557.png)

   > 3-8-译码器：可以表示出所有的极小项，因而可以构成所有的逻辑表达式。

3. ![image-20211111125058276](Combinational%20Logic.assets/image-20211111125058276.png)

   ![image-20211111125109858](Combinational%20Logic.assets/image-20211111125109858.png)

   > 背后的本质原因：二-十进制加法器不能表示大于9的数字，之后还要再加上6才可以。

4. ![image-20211111125235868](Combinational%20Logic.assets/image-20211111125235868.png)

   只有余3循环码可以摆脱竞争-冒险现象。

   > 这类题首先要看输出，看输出端和哪几个输入端有关联。
   >
   > 其次要看这些编码的变化情况，1.5.1表相邻之间变化时，保证输出端都不会发生竞争冒险现象。

