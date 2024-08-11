### 半导体

本征半导体：纯净、晶体，如硅、锗。两种载流子参与导电，导电性很差，并随着温度升高而增强。在绝对零度时不导电。

> 半导体材料对温度敏感！

杂质半导体主要靠多数载流子导电，掺入杂质越多，多子浓度越高，导电性越强，从而实现导电性可控。掺杂浓度越高，对外电阻越小。

一块半导体晶体一侧掺杂成P型半导体，另一侧掺杂成N型半导体，中间二者相连的接触面称为PN结（英语：p-n junction）。PN结是电子技术中许多器件，例如半导体二极管、双极性晶体管的物质基础。

将PN结封装、引出两个电极，就构成了二极管。

PN结、势垒区、耗尽层意义类似。

![img](CMOS%20Technology.assets/300px-PN_Junction_Open_Circuited_zh_hans.svg.png)

N型半导体:掺入少量杂质磷元素（或锑元素）的硅晶体（或锗晶体）中，由于半导体原子（如硅原子）被杂质原子取代，磷原子外层的五个外层电子的其中四个与周围的半导体原子形成共价键，多出的一个电子几乎不受束缚，较为容易地成为自由电子。于是，N型半导体就成为了含自由电子浓度较高的半导体，其导电性主要是因为自由电子导电。

P型半导体：掺入少量杂质硼元素（或铟元素）的硅晶体（或锗晶体）中，由于半导体原子（如硅原子）被杂质原子取代，硼原子外层的三个外层电子与周围的半导体原子形成共价键的时候，会产生一个“空穴”，这个空穴可能吸引束缚电子来“填充”，使得硼原子成为带负电的离子。这样，这类半导体由于含有较高浓度的“空穴”（“相当于”正电荷），成为能够导电的物质。

> N is for negative, for electrons are more. P is for positive.

电子与空穴的运动：

- 漂移运动：上面叙述的两种半导体在外加电场的情况下，会作定向运动。这种运动称为电子与空穴（统称“载流子”）的“漂移运动”，并产生“漂移电流”。

  两种载流子的浓度越大，所产生的漂移电流越大。

- 扩散运动：由于某些外部条件而使半导体内部的载流子存在浓度梯度的时候，将产生扩散运动，即载流子由浓度高的位置向浓度低的位置运动。

采用一些特殊的工艺，可以将上述的P型半导体和N型半导体紧密地结合在一起。在二者的接触面的位置形成一个PN结。

P型、N型半导体由于分别含有较高浓度的“空穴”和自由电子，存在浓度梯度，所以二者之间将产生扩散运动。即：

- 自由电子由N型半导体向P型半导体的方向扩散
- 空穴由P型半导体向N型半导体的方向扩散

载流子经过扩散的过程后，扩散的自由电子和空穴相互结合，使得原有的N型半导体的自由电子浓度减少，同时原有P型半导体的空穴浓度也减少。**在两种半导体中间位置形成一个由N型半导体指向P型半导体的电场，称为“内电场”。**

#### 内建电势

PN结在没有外加电压情况下，跨结形成了电势差导致了平衡状态。该电势差称为内建电势（built-in potential）$V_{bi}$

PN结的n区的电子向p区扩散，留下了正电荷在n区。类似地，p型空穴从p区向n区扩散，留下了负电荷在p区。进入了p区的电子与空穴复合，进入了n区的空穴与电子复合。其效果是扩散到对方的多数载流子（自由电子与空穴）都耗尽了，结区只剩下不可移动的带电离子，失去了电中性变为带电，形成了耗尽层（space charge region）。

![img](CMOS%20Technology.assets/550px-Pn-junction-equilibrium.png)

> 上图为零偏置热平衡下的PN结。电子与空穴的浓度分别用蓝线、红线表示。灰色区域是电中性。亮红色是正电区域，亮蓝色区域是负电性。底部显示电场。静电力作用于电子与空穴，以及其扩散取向。

耗尽区的电场与电子与空穴的扩散过程相反，阻碍进一步扩散。

![img](CMOS%20Technology.assets/550px-Pn-junction-equilibrium-graphs.png)

耗尽层的多数载流子已经全部耗尽，留下的电荷密度等于净掺杂水平。当平衡达到时，电荷密度近似显示为阶梯函数，耗尽层与中立区的边界相当陡峭。（见上图的Q(x)图）。耗尽层在PN结两侧有相同量的电荷，因此它向较少掺杂的一侧延展更远（图A与图B的n端）。

> 即上图例子中P侧、N侧的掺杂浓度不一样。

#### 正向偏置

若施加在P区的电压高于N区的电压，称为正向偏置（forward bias）。

在正向偏置电压的外电场作用下，**N区的电子与P区的空穴被推向PN结**。这降低了耗尽区的耗尽宽度。这降低了PN结的电势差（即内在电场）。随着正向电压的增加，耗尽区最终变得足够薄以至于内电场不足以反作用抑制多数载流子跨PN结的扩散运动，因而降低了PN结的电阻。跨过PN结注入p区的电子将扩散到附近的电中性区。所以PN结附近的电中性区的少数载流子的**扩散量**确定了二极管的正向电流。

> 这里的扩散量是指从对方扩散过来的。

仅有多数载流子能够在半导体材料中长距离移动。因此，注入P区的电子不能继续移动更远，而是很快与空穴复合。少数载流子在注入中性区后移动的平均距离称为扩散长度（diffusion length），一般来说仅有微米等级。

虽然跨过p-n结的电子在p-区只能穿透短距离，但正向电流不被打断，因为空穴（p-区的多数载流子）在外电场驱动下在向相反方向移动。从p-区跨越PN结注入n-区的空穴也具有类似性质。

正向偏置下，跨PN结的电流强度取决于多数载流子的密度，这一密度随正向偏置电压的大小成指数增加。这使得二极管可以导通正向大电流。

#### 反向偏置

若施加在N区的电压高于P区的电压，这种状态称为PN结反向偏置（reverse bias）。由于p区连接电源负极，多数载流子(空穴)被外电场拉向负极，因而耗尽层变厚。n区也发生类似变化。并且随反向偏置电压的增加，耗尽层的厚度增加。从而，多数载流子扩散过PN结的势垒增大，PN结的电阻变大，宏观看二极管成为绝缘体。

反向偏置时形成**极其微弱的漂移电流**，电流由N区流向P区，并且这个电流不随反向电压的增大而变化，称为“反向饱和电流”（reverse saturation current）。**这是因为反向电流是由少数载流子跨PN结形成的，因此其“饱和”值取决于少数载流子的掺杂密度。**由于反向饱和电流很小，PN结处于截止状态，所以外加反向电压时，PN结相当于断路。

当加在PN结上的反向电压超过一定数值时，PN结的电阻突然减小，反向电流急剧增大，这种现象称为击穿。电击击穿分为雪崩击穿和齐纳击穿且都是可逆的。发生热击穿后，PN结不再具有单向导电性，导致二极管发生不可恢复的损坏。利用齐纳击穿制作的稳压二极管，称为齐纳二极管。

> 雪崩击穿要与金属原子外自由运动的电子有关。当反向电压逐渐增大时，反向饱和电流不变。但是当反向电压达到一定值时，PN结将被击穿。在PN结中加反向电压，如果反向电压过大，位于PN结中的载流子会拥有很大的动能，足以和中性粒子碰撞使中性粒子分离出价电子而产生空穴-电子对。这样会导致PN结反向电流的急剧增大，发生PN结的击穿，因为被弹出的价电子又可能和其他中性粒子碰撞产生链式反应，类似于雪崩，这样的反向击穿方式成为雪崩击穿（Avalanche breakdown）。掺杂浓度越低所需电场越强。当掺杂浓度非常高时，在PN结两端加入弱电场就会使中性粒子中的价电子脱离原子的束缚，从而成为载流子。导致PN结的击穿。这样的击穿被称作齐纳击穿（Zener breakdown）。掺杂浓度越高所需要的电场越弱。一般小于6V的电压引起的是齐纳击穿，大于6V的引起的是雪崩击穿。

#### 伏安特性

PN结的最大特性为单向导电性，反映到伏安特性曲线如右图。当正向电压达到一定值时，PN结将产生正向偏置，PN结被导通（图中蓝色部分）；当反向电压在一定范围内时，PN结产生微弱的反向饱和电流（图中绿色部分）；当反向电压超过一定值时，PN结被击穿（图中黄色部分）。

![img](CMOS%20Technology.assets/300px-P-n_junction_characteristics.svg.png)
$$
i=I_{\mathrm{S}}\left(\mathrm{e}^{\frac{q u}{k T}}-1\right)=I_{\mathrm{S}}\left(\mathrm{e}^{\frac{u}{U_{T}}}-1\right)
$$
其中q是电子的电量，k是玻尔兹曼常数，T是热力学温度。

$I_S$为反向饱和电流，和二极管的工艺、材料、尺寸有关；对于每只二极管来说为一个定值。

$U_T$为温度的电压当量。

常温下$U_T = 26mV$

随着温度的升高，在电流不变的情况下二极管压降减小，反向饱和电流增大；即正向特性左移，反向特性下移。

常用的数据：常温下硅二极管的导通电压为0.7V。

#### 电容效应

外加电场可以改变中间、两边的电荷分布，因而对外等效为电容。

在PN结（两种半导体的交界处) 会因为外加电压 产生一定电荷积累，即结电容 $\left(C_{j}\right)$ 效应。根据 成因分为 "势垒电容" $\quad\left(C_{b}\right)$ 和 “扩散电容" （$C_{d}$ ）。结电容满足:
$$
C_{j}=C_{b}+C_{d}
$$
当外加电压的时候，“耗尽层”的厚度发生变化，将会引起其电荷量的变化。从而产生等效的电容效应，即“势垒电容”$C_b$。它与PN结面积、耗尽层宽度、半导体介电常数和外加电压都有关系。

当外加电压变化时，扩散区（参见上文所述扩散运动）内电荷的积累和释放过程将产生等效于电容的充放电过程，故等效于一个“扩散电容”$C_d$

二极管正向偏置时，扩散电容远大于势垒电容 Cj≈CD ;而反向偏置时，扩散电容可以忽略，势垒电容起主要作用，Cj≈CB 。

![img](CMOS%20Technology.assets/7920678-077860aa416216c18bc5a2e04f1da316.jpeg)

### 二极管与非门

将伏安特性折线化：

![tmp4FCC](CMOS%20Technology.assets/tmp4FCC.png)

第二种在近似分析中最常用。

二极管的动态电流波形：

![tmp79B2](CMOS%20Technology.assets/tmp79B2.png)

如果给二极管加上一个方波，由于二极管的电容效应，其波形如上图。由于外加电压由反向突然变为正向时，要等到PN结内部建立起足够的电荷梯度后才开始有扩散电流形成，因而正向导通电流的建立要稍微滞后一点。档外加电压突然由正向变为反向时，由于PN结内尚有一定数量的存储电荷，所以有较大的瞬态反向电流流过。随着存储电荷的消散，反向电流迅速衰减并趋近于稳态时的反向饱和电流。瞬态反向电流的大小和持续时间的长短取决于正向导通时电流的大小,反向电压和外电路电阻的阻值,而且与二极管本身的特性有关。

> 当电压由正向突然变成反向时，在理想情况下，二极管将立刻转为截止，电路中应只有很小的反向电流。但实际情况是，二极管并不立刻截止，而是先由正向的IF变到一个很大的反向电流$I_R=V_R／R_L$，这个电流维持一段时间$t_S$后才开始逐渐下降，再经过$t_t$后 ，下降到一个很小的数值0.1IR，这时二极管才进入反向截止状态，如下图所示。
>
> ![img](CMOS%20Technology.assets/o4YBAF6GiduAVIuOAAP-0np4ZFg183.png)
>
> 通常把二极管从正向导通转为反向截止所经过的转换过程称为反向恢复过程。其中$t_S$称为存储时间，$t_t$称为渡越时间，$t_{re}=t_s+t_t$称为反向恢复时间。 由于反向恢复时间的存在，使二极管的开关速度受到限制。
>
> 产生上述现象的原因是由于二极管外加正向电压$V_F$时，载流子不断扩散而存储的结果。当外加正向电压时Ｐ区空穴向Ｎ区扩散，Ｎ区电子向Ｐ区扩散，这样，不仅使势垒区（耗尽区）变窄，而且使载流子有相当数量的存储，在Ｐ区内存储了电子，而在Ｎ区内存储了空穴 ，它们都是非平衡少数载流子。
>
> 空穴由Ｐ区扩散到Ｎ区后，并不是立即与Ｎ区中的电子复合而消失，而是在一定的路程$L_P$（扩散长度）内，一方面继续扩散，一方面与电子复合消失，这样就会在$L_P$范围内存储一定数量的空穴，并建立起一定空穴浓度分布，靠近结边缘的浓度最大，离结越远，浓度越小 。正向电流越大，存储的空穴数目越多，浓度分布的梯度也越大。电子扩散到Ｐ区的情况也类似。
>
> 当输入电压突然由正向变为反向时，Ｐ区存储的电子和Ｎ区存储的空穴不会马上消失，但它们将通过下列两个途径逐渐减少：① 在反向电场作用下，Ｐ区电子被拉回Ｎ区，Ｎ区空穴被拉回Ｐ区，形成反向漂移电流IR②与多数载流子复合。

反向电流持续的时间用反向恢复时间$t_{re}$来定量描述。是$t_{re}$指反向电流从它的峰值衰减到峰值的十分之一所经过的时间。由于$t_{re}$的数值很小,在几纳秒以内,所以用普通的示波器不容易看到反向电流的瞬态波形。

二极管开关：

![tmp9066](CMOS%20Technology.assets/tmp9066.png)

- 输入：高电平：$V_{I H}=V_{c c}$；低电平：$V_{I L}=0$

- 输出：

  - $V_{I}=V_{I H}$时，$D$ 截止, $V_{O}=V_{O H}=V_{C C}$

  - $V_{I}=V_{I L}$时，D导通, $V_{O}=V_{O L}=0.7 \mathrm{~V}$。

    > 这个0.7是因为这里约定二极管的导通电压是0.7V

二极管与门：

![tmpFC8B](CMOS%20Technology.assets/tmpFC8B.png)

设 $V_{c c}=5 V$；加到 $A, B$ 的 $V_{\mathrm{IH}}=3 \mathrm{~V}$， $V_{\mathrm{IL}}=0 \mathrm{~V}$ ；二极管导通时 $V_{\mathrm{DF}}=0.7 \mathrm{~V}$
$$
\begin{array}{cc|l}
A & B & Y \\
\hline 0 V & 0 V & 0.7 V \\
\hline 0 V & 3 V & 0.7 V \\
\hline 3 V &  0 V  & 0.7 V \\
\hline 3 V & 3 V & 3.7 V \\
\hline
\end{array}
$$
规定3V以上为1，0.7V以下为0
$$
\begin{array}{cc|l}
A & B & Y \\
\hline 0 & 0 & 0 \\
\hline 0 &1 &0 \\
\hline1 &  0 & 0 \\
\hline 1 &1 & 1 \\
\hline
\end{array}
$$
这种与门电路虽然很简单,但是存在着严重的缺点。首先,输出的高、低电平数值和输入的高﹑低电平数值不相等,相差一个二极管的导通压降。如果把这个门的输出作为下一级门的输入信号,将发生信号高、低电平的偏移。其次,当输出端对地接上负载电阻时,负载电阻的改变有时会影响输出的高电平。因此,这种二极管与门电路仅用作集成电路内部的逻辑单元,而不用在集成电路的输出端直接去驱动负载电路。


二极管或门：

![tmpD8EA](CMOS%20Technology.assets/tmpD8EA.png)

设 $V_{c c}=5 V$；加到 $A, B$ 的 $V_{\mathrm{IH}}=3 \mathrm{~V}$， $V_{\mathrm{IL}}=0 \mathrm{~V}$ ；二极管导通时 $V_{\mathrm{DF}}=0.7 \mathrm{~V}$

同样分析后会发现，须规定2.3V以上为1，0V以下为0，才能构成二极管或门的真值表。

二极管构成的门电路的缺点：

- 电平有偏移
- 整个电路中低电平、高电平标准不一样
- 带负载能力差（理想电压源内阻为0，带负载能力最强；而二极管门中这么多电阻，所以带负载能力很弱，即：当输出端对地接上负载电阻时,负载电阻的改变有时会影响输出的高电平

### MOSFET

![img](CMOS%20Technology.assets/Slide03.png)

> $\mathrm{I}_{\mathrm{DS}} \propto \mathrm{W} / \mathrm{L}$可以直接从几何上直观理解。Typically, IC designers make the length as short as possible — when a news article refers to a 14nm process, the 14nm refers to the smallest allowable value for the channel length. And designers choose the channel width to set the desired amount of current flow. The channel width chosen to set the current flow to the desired value.

The substrate upon which the IC is built is a thin wafer of silicon crystal which has had impurities added to make it conductive. In this case the impurity was an acceptor atom like Boron, and we characterize the doped silicon as a p-type semiconductor. The IC will include an electrical contact to the p-type substrate, called the *bulk* terminal, so we can control its voltage.

> 这里的说的是bulk部分，即基底那里是P型的。

When want to provide electrical insulation between conducting materials, we’ll use a layer of silicon dioxide (SiO2). Normally the thickness of the insulator isn’t terribly important, except for when it’s used to isolate the gate of the transistor (shown here in red) from the substrate. The insulating layer in that region is very thin so that the electrical field from charges on the gate conductor can easily affect the substrate.

The gate terminal of the transistor is a conductor, in this case, polycrystalline silicon.（多晶硅） The gate, the thin oxide insulating layer, and the p-type substrate form a capacitor, where changing the voltage on the gate will cause electrical changes in the p-type substrate directly under the gate. In early manufacturing processes the gate terminal was made of metal, and the term *metal-oxide-semiconductor* (MOS) is referring to this particular structure.

After the gate terminal is in place, donor atoms such as Phosphorous are implanted into the p-type substrate in two rectangular regions on either side of the gate. This changes those regions to an n-type semiconductor, which become the final two terminals of the MOSFET, called the source and the drain. **Note that source and drain are usually physically identical and are distinguished by the role they play during the operation of the device**.Our convention is to call the diffusion terminal with the highest voltage potential the *drain* and the other lower-potential terminal the *source*. With this labeling if any current is flowing through the MOSFET switch, it will flow from drain to source.

此外，由于不希望PN结中出现漏电电流，故会将bulk与source连在一起，使其等电势。这是因为电流由drain流向source，drain高电平，source低电平，连在一起后，source与bulk等电势因而无电流；drain与bulk构成了反向PN结，因而无电流。（也有一种接法是将衬底接到系统的最低电位上去）

![tmp2990](CMOS%20Technology.assets/tmp2990.png)

![img](CMOS%20Technology.assets/Slide04.png)

> 注意：“+”不代表极性；“+”越多代表掺杂浓度越高；

When the MOSFET is manufactured, it's designed to have a particular threshold voltage, $V_{\mathrm{TH}}$, which tells us when the switch goes from nonconducting/OFF/OPEN to conducting/ON/CLOSED. For the n-channel MOSFET shown here, we'd expect $V_{\mathrm{TH}}$ to be around $0.5 \mathrm{~V}$ in a modern process.

Now, as $V_{\mathrm{GS}}$ gets larger, positive charges accumulate on the gate conductor and generate an electrical field which attracts the electrons in the atoms in the substrate. For a while that attractive force gets larger without much happening, but when it reaches the MOSFET's threshold voltage, the field is strong enough to pull the substrate electrons from the valence band into the conduction band, and the newly mobile electrons will move towards the gate conductor, collecting just under the thin oxide that serves the gate capacitor's insulator.

When enough electrons accumulate, the type of the semiconductor changes from p-type to n-type(因为此时自由电子成为多子) and there’s now a channel of n-type material forming a conducting path between the source and drain terminals. This layer of n-type material is called an inversion layer, since its type has been inverted from the original p-type material.

When $V_{\mathrm{DS}}$ is larger than $V_{\mathrm{GS}}$, which is shown in the bottom figures. A large $V_{\mathrm{DS}}$ changes the geometry of the electrical fields in the channel and the inversion layer pinches off at the end of the channel near the drain. But with a large $V_{\mathrm{DS}}$, the electrons will tunnel across the pinch-off point to reach the conducting inversion layer still present next to the source terminal.Instead $I_{\mathrm{DS}}$ is approximately constant and the curve becomes a horizontal line. We say that the MOSFET has reached saturation where $I_{\mathrm{DS}}$ has reached some maximum value.

夹断之后，继续增大$V_{\mathrm{DS}}$，夹断点向source方向移动。尽管夹断点在移动，但是沟道区（source到夹断点到电压降保持不变，仍等于$V_{GS}-V_{TH}$。因此，$V_{DS}$多余部分电压全部降到夹断区上，在夹断区内形成较强的电场。这时电子沿沟道从source流向夹断区，当电子到达夹断区边缘时，受夹断区强电场的影响，会很快地漂移到drain.

![img](CMOS%20Technology.assets/Slide05.png)

Notice that the saturated part of the $I_{\mathrm{DS}}$ curve isn't quite flat and $I_{\mathrm{DS}}$ continues to increase slightly as $V_{\mathrm{DS}}$ gets larger. This effect is called channellength modulation and reflects the fact that the increase in channel pinch-off isn't exactly matched by the increase current induced by the larger $V_{\mathrm{DS}}$.

特性曲线：

- 截止区

- 可变电阻区。在这个区域里，当$V_{GS}$一定时, $i_{\text {D }}$ 与 $v_{\mathrm{DS}}$ 之比近似地等于一个常数, 具有类似于线性电阻的性质。等效电阻的大小和 $v_{GS}$ 的数值有关。在 $v_{DS} \approx 0$ 时, MOS 导通电阻 $R_{\mathrm{ON}}$ 和 $v_{GS}$ 的关系由下式给出
  $$
  \left.R_{ON}\right|_{v_{\mathrm{DS}}=0}=\frac{1}{2 K\left(V_{GS}-V_{GS(th)}\right)}
  $$
  上式表明,在$ V_{GS} \gg V_{GS(th)}$ 的情况下, $R_{ON}$ 近似地与 $  V_{GS}$成反比。为了得到较小的导通电阻,应. 取尽可能大的$ V_{GS}$值。

- 恒流区：恒流区里漏极电流$i_D$的大小基本上由 $V_{GS}$ 决定,$V_{DS}$ 的变化对 $i_{D}$ 的影响很小。 $i_{\mathrm{D}}$ 与 $V_{GS}$ 的关系由下式给出
  $$
  i_{\mathrm{D}}=I_{DS}\left(\frac{v_{\mathrm{GS}}}{V_{\mathrm{DS}(\mathrm{th})}}-1\right)^{2}
  $$
  其中 $I_{\mathrm{DS}}$ 是 $V_{G S}=2 V_{GS(\mathrm{th})}$ 时的 $i_{\mathrm{D}}$ 值。

  在$ V_{GS} \gg V_{GS(th)}$ 的情况下,$i_{\mathrm{D}}$近似地与$v_{GS}^{2}$成正比。表示两者关系的曲线称为MOS管的转移特性曲线。

  ![tmp5614](CMOS%20Technology.assets/tmp5614.png)

#### MOESFET开关电路

![img](CMOS%20Technology.assets/Slide06.png)

> 注意P沟道的符号上有一个圈，而圈代表取反。

![tmp818C](CMOS%20Technology.assets/tmp818C.png)

> 注意P沟道的bulk是连接到高电平的。把N沟道的所有全部反过来就成为P沟道了！source极现在成了电压最高的。

![img](CMOS%20Technology.assets/Slide07.png)

You may be wondering why we can’t use NFETs in pullup circuits or PFETs in pulldown circuits. You’ll get to explore the answer to this question in one of the lab assignments. Meanwhile, the short answer is that the signaling node will experience degraded signaling levels and we’ll loose the noise margins we’ve worked so hard to create!

此外还有耗尽型MOS管

耗尽型与增强型MOS管的区别主要在于耗尽型MOS管在G端（Gate）不加电压时有导电沟道存在，而增强型MOS管只有在开启后，才会出现导电沟道；两者的控制方式也不一样，耗尽型MOS管的VGS（栅极电压）可以用正、零、负电压控制导通，而增强型MOS管必须使得VGS>VGS（th）（栅极阈值电压）才行。

由于耗尽型N沟道MOS管在SiO2绝缘层中掺有大量的Na+或K+正离子（制造P沟道耗尽型MOS管时掺入负离子），当VGS=0时，这些正离子产生的电场能在P型衬底中感应出足够的电子，形成N型导电沟道；当VGS>0时，将产生较大的ID（漏极电流）；如果使VGS<0，则它将削弱正离子所形成的电场，使N沟道变窄，从而使ID减小。

这些特性使得耗尽型MOS管在实际应用中，当设备开机时可能会误触发MOS管，导致整机失效；不易被控制，使得其应用极少。

因此，日常我们看到的NMOS、PMOS多为增强型MOS管；其中，PMOS可以很方便地用作高端驱动。不过PMOS由于存在导通电阻大、价格贵、替换种类少等问题，在高端驱动中，通常还是使用NMOS替代，这也是市面上无论是应用还是产品种类，增强型NMOS管最为常见的重要原因，尤其在开关电源和马达驱动的应用中，一般都用NMOS管。

### CMOS

之前介绍过获得高、低电平的基本开关电路

![tmp8CE](CMOS%20Technology.assets/tmp8CE.png)

> 左侧单开关电路的主要缺点是功耗比较大。而右侧的电路功耗极小。

![tmp8AB7](CMOS%20Technology.assets/tmp8AB7.png)

![tmp681C](CMOS%20Technology.assets/tmp681C.png)

#### CMOS反相器

##### 传输特性

**电流传输特性**

可以使用图解法（假设没有后续负载，只有一条回路）

![tmp9F71](CMOS%20Technology.assets/tmp9F71.png)

整理，得到：

![tmp10F9](CMOS%20Technology.assets/tmp10F9.png)

使用这类器件时不应使之长期工作在电流传输特性的BC段，以防止器件因功耗过大而损坏。

> 数字电路的功耗在变化时耗电功率更大。

**电压传输特性**

可以在实验室中测出

> 注意在实验室中测量的时候应该用锯齿波或者三角波(因为想看从0到$V_{DD}$的变化 )。而且不能有负信号（所以要加偏置）。而且信号变化的频率不能太快（因为要看稳态的特性）

![img](CMOS%20Technology.assets/Slide08.png)

![tmpE3F4](CMOS%20Technology.assets/tmpE3F4.png)

如果$T_1$与$T_2$的参数完全对称，则$v_{1}=\frac{1}{2} V_{\mathrm{DD}}$时两管的导通内阻相等；$v_{o}=\frac{1}{2} V_{\mathrm{DD}}$,即工作于电压传输特性转折区的中点；我们将电压传输特性转折区中点所对应的输入电压称为反相器的阈值电压(threshold voltage)，用$V_{TH}$表示。因此，CMOS反相器的阈值电压为$V_{\mathrm{TH}} \approx \frac{1}{2} V_{\mathrm{DD}}$。

**噪声容限**

![tmp3AB9](CMOS%20Technology.assets/tmp3AB9.png)

在CMOS门电路中，当负载为另外的门电路的情况下（负载电流几乎等于零，相当于空载情况），规定$V_{\text {OH(min })}=V_{\mathrm{DD}}-0.1 \mathrm{~V}, V_{\mathrm{OL}(\max )}=V_{\mathrm{SS}}+0.1 \mathrm{~V}$。$V_{s s}$表示N沟道MOS管的源极电位。在这个源极接地（电源公共端）的情况下，$V_{O L(\max )}=0.1 \mathrm{~V}$。

测试结果表明，在输出高、低电平的变化不大于限定的$10 \% V_{DD}$的情况下，输入信号高、低电平允许的变化量约为$30 \% V_{DD}$.因此得到$V_{\mathrm{NH}}=V_{\mathrm{NL}} \approx 30 \% V_{\mathrm{DD}}$。可见CMOS电路的噪声容限大小是和$V_{DD}$有关的。$V_{DD}$越高，噪声容限越大。

> 可以通过提高$V_{DD}$来提高噪声容限，但实践中一般不这么干。

![tmp371](CMOS%20Technology.assets/tmp371.png)

![tmp19D8](CMOS%20Technology.assets/tmp19D8.png)

##### 静态输入\输出特性

**输入特性**

输入特性是指从反相器输入端看进去的输入电压与输入电流的关系

因为 MOS 管的栅极和衬底之间的绝缘介质非常薄(约 $1000埃$ ), 极易被击穿(耐压约 $100 \mathrm{~V}$ ),所以必须采取保护措施,防止因接触到带静电电荷物体时发生静电放电而损坏。

![tmpD338](CMOS%20Technology.assets/tmpD338.png)

![tmp2FFA](CMOS%20Technology.assets/tmp2FFA.png)

![tmpEFB5](CMOS%20Technology.assets/tmpEFB5.png)

![tmp6F22](CMOS%20Technology.assets/tmp6F22.png)

> 注意特性曲线，在工作区域，电流为0，因而功耗为0.这也是“数字电路工作稳态时功耗接近于0”。

> 问：若输入信号为-1V时，测出来应该是什么？
>
> 根据上面的曲线，看起来应该是-0.7V，可是剩下的0.3V去哪里了呢？
>
> 类似问题：把一个干电池用导线短路，两端电压是多少？
>
> 原因：不存在理想电压源或者说理想信号源，都是有内阻的！

**输出特性**

从反相器输出端看进去的输出电压和输出电流的关系，称为输出特性。

**低电平输出特性**

当输出为低电平，即$v_{o}=V_{OL}$时，反相器的P沟道截止，N沟道导通，工作状态如下：

![tmpE08A](CMOS%20Technology.assets/tmpE08A.png)

对比反相器结构：

![tmpBCCD](CMOS%20Technology.assets/tmpBCCD.png)

负载电流$I_{OL}$从负载电路注入$T_2$,输出电平随 $I_{OL}$ 增加而提高。

因为这时的 $V_{OL}$ 就是 $V_{DS_2}$ $ I_{OL}$ 就是 $i_{\mathrm{D} 2}$,所以$V_{OL}$与$I_{OL}$的关系曲线实际上也就是$T_{2}$管的漏极特性曲线。

由于 $T_{2}$ 的导通内阻与 $v_{GS_2}$ 的大小有关,$v_{GS_2}$越大导通内阻越小，所以同样的 $I_{OL}$ 值下 $V_{\mathrm{DD}}$ 越高，$T_{2}$导通时的 $v_{GS_2}$越大， $V_{OL}$也越低。

> 注意这一点：在相同工艺尺寸下，电源电压越高，反相器的输出内阻越低；

![tmp1C84](CMOS%20Technology.assets/tmp1C84.png)

![tmp4C40](CMOS%20Technology.assets/tmp4C40.png)

**高电平输出特性**

P沟道导通而N沟道截止。

![tmp109B](CMOS%20Technology.assets/tmp109B.png)

此时负载电流是从门电路的输出端流入的，与规定的负载方向相反，与规定的负载方向相反，在输出特性曲线中显现为负值。

![tmp49C8](CMOS%20Technology.assets/tmp49C8.png)

![tmp7EF2](CMOS%20Technology.assets/tmp7EF2.png)

以上分析说明，反相器输出的高、低电平是与负载电流的大小有关的。在查阅器件手册时，一定注意这些数据是在什么负载电流下得出的。

##### 动态特性

动态特性讨论的是电路状态转换过程中表现出来的性质。

**传输延迟时间$t_{\mathrm{PHL}}, t_{\mathrm{PLH}}$**

由于MOS管的电极之间以及电极与衬底之间都存在寄生电容,尤其在反相器的输出端更不可避免地存在着负载电容(当负载为下一级反相器时,下一级反相器的输入电容和接线电容就构成了这一级的负载电容),当输入信号发生跳变时,输出电压的变化必然滞后于输入电压的变化。我们把输出电压变化落后于输入电压变化的时间称为传输延迟时间,并且将输出由高电平跳变为低电平时的传输延迟时间记做$t_{\mathrm{PHL}}$，将输出由低电平跳变为高电平时的传输延迟时间记做$t_{\mathrm{PLH}}$。

传输延迟时间的原因：$C_{I}$ 和 $C_{L}$ 充放电。因为$R_{ON}$ 较大，所以$C_{L}$ 充放电影响也较大。

> 前级电路提供R，后级电路提供C；
>
> 而电容并联是相加的；
>
> 所以有时候接了很多负载之后，一工作起来延迟时间就会变得很大。

在CMOS电路中，$t_{\mathrm{PHL}}$和$t_{\mathrm{PLH}}$是以输入和输出波形对应边上等于最大幅度$50 \%$的两点间时间间隔来定义的。由于CMOS电路的$t_{\mathrm{PHL}}$和$t_{\mathrm{PLH}}$通常是相等的，所以也经常以平均传输延迟时间$t_{\mathrm{pd}}$来表示$t_{\mathrm{PHL}}$和$t_{\mathrm{PLH}}$。

![tmp63C8](CMOS%20Technology.assets/tmp63C8.png)

$t_{P H L}, t_{P L H}$ 受 $C_{L}, V_{D D}$ 影响：

![tmp10E3](CMOS%20Technology.assets/tmp10E3.png)
$$
V(t)=V(\infty)+\left[V\left(0_{+}\right)-V(\infty)\right] e^{-\frac{t}{\tau}}
$$

$$
\begin{aligned}
&t=R C \ln \frac{V_{(\infty)}-V_{(0)}}{V_{\infty}-V_{(t)}}=R C \ln \frac{V_{(\infty)}-V_{\mathrm{OL}}}{V_{(\infty)}-V_{(t)}} \\
&=R C \ln \frac{V_{\mathrm{D} D}-V_{(0)}}{V_{\mathrm{DD}}-V_{\mathrm{TH}}} \approx R C \ln 2
\end{aligned}
$$

而：$R=\rho \frac{l}{A}$，$C=Q / V=\varepsilon A / d$

Dennard Scaling:

Dennard缩放比例定律是基于1974年Robert H. Dennard参与完成的一篇论文而提出的一个定律。 

Dennard缩放比例定律（Dennard scaling）表明，**随着晶体管变得越来越小，它们的功率密度保持不变，因此功率的使用与面积成比例；电压和电流的规模与长度成比例。**

Dennard发现，晶体管的尺寸在每一代技术中都缩小了30% (0.7倍) ，因此它们的面积减少了50% 。这意味着电路减少了30% (0.7倍)的延迟，因此增加了约40% (1.4倍)的工作频率。最后，为了保持电场恒定，电压降低了30% ，能量降低了65% ，功率降低了50% 。因此，在每一代技术中，晶体管密度增加一倍，电路速度提高40% ，功耗(晶体管数量增加一倍)保持不变。

结合“摩尔定律”晶体管的数量大约每两年翻一番，这意味着**效能功耗比**（每消耗一瓦功率，计算机可提供的计算速率）以同样的速度增长，大约每两年翻一番。这种趋势被称为库米定律（Koomey's law）。库米最初提出的倍增速率是1.57年(比摩尔定律的倍增周期稍快) ，但最近的估计表明这一速度正在放缓。

![tmp3560](CMOS%20Technology.assets/tmp3560.png)

![tmpFE10](CMOS%20Technology.assets/tmpFE10.png)

**交流噪声容限**

如上所述,由于负载电容和MOS管寄生电容的存在,输入信号状态变化时必须有足够的变化幅度和作用时间才能使输出改变状态。当输入信号为窄脉冲,而且脉冲宽度接近于门电路传输延迟时间的情况下,为使输出状态改变,所需要的脉冲信号幅度将远大于直流输入信号的幅度。因此,反相器对这类窄脉冲的噪声容限——交流噪声容限远高于前面所讲过的直流噪声容限。而且,传输延迟时间越长,交流噪声容限也越大。

由于传输延迟时间与电源电压和负载电容有关，所以交流噪声容限也受电源电压和负载电容的影响。

![tmp1D67](CMOS%20Technology.assets/tmp1D67.png)

图中以$V_{NA}$表示交流噪声容限，以$t_w$表示噪声电压的持续时间。

**动态功耗**

总功耗=动态功耗$P_D$ + 静态功耗$P_S$

静态功耗极小，与动态功耗相比可以忽略。

![tmp383B](CMOS%20Technology.assets/tmp383B.png)

> 电路中不仅有输入保护二极管，还存在着寄生二极管。这些二极管的反向漏电流比$T_1$或$T_2$截止时的漏电流要大得多，它们构成了电源静态电流的主要成分，图中标出了这些漏电流的流通路径。因为这些二极管都是PN结型的,它们的反相电流受温度影响比较大,所以CMOS反相器的静态功耗也随温度的改变而变化。静态功耗通常是以指定电源电压下的静态漏电流的形式给出。

动态功耗：当CMOS反相器从一种稳定工作状态突然转变到另一种稳定状态的过程中，将产生附加的功耗，我们称之为动态功耗。动态功耗由两部分组成，一部分是对负载电容充、放电所消耗的功率$P_{\mathrm{C}}$，另一部分是由于两个MOS管T1和T2短时间内同时导通所消耗的瞬时导通功率$P_{\mathrm{T}}$。

用 $C_{\mathrm{L}}$ 表示接到反相器输出端的所有电容,其中包括下一级门电路的输入电容,接线电容,还可能有其他负载电路的电容等。

![tmp3F32](CMOS%20Technology.assets/tmp3F32.png)

当输入电压由高电平跳变为低电平时, $\mathrm{T}_{1}$ 导通、 $\mathrm{T}_{2}$ 截止, $V_{\mathrm{DD}}$ 经 $\mathrm{T}_{1}$ 向 $C_{\mathrm{L}}$ 充电, 产生充电电流 $i_{\mathrm{p}}$ 而当输入电压由低电平跳变为高电平时, $\mathrm{T}_{2}$ 导通 $\mathrm{T}_{1}$ 截止, $C_{L}$ 通过 $\mathrm{T}_{2}$ 放电, 产生放电电流$i_N$.

![tmp7E99](CMOS%20Technology.assets/tmp7E99.png)

可以写出两电流产生的平均功耗：
$$
P_{c}=\frac{1}{T}\left[\int_{0}^{T / 2} i_{N} v_{O} \mathrm{~d} t+\int_{T / 2}^{T} i_{\mathrm{p}}\left(V_{\mathrm{DD}}-v_{O}\right) \mathrm{d} t\right]
$$
而其中：
$$
i_{\mathrm{N}}=-C_{\mathrm{L}} \frac{\mathrm{d} v_{O}}{\mathrm{~d} t}
$$

$$
i_{\mathrm{p}}=C_{\mathrm{L}} \frac{\mathrm{d} v_{O}}{\mathrm{~d} t}=-C_{\mathrm{L}} \frac{\mathrm{d}\left(V_{\mathrm{DD}}-v_{\mathrm{O}}\right)}{\mathrm{d} t}
$$

故得到：
$$
\begin{aligned}
P_{\mathrm{C}} &=\frac{1}{T}\left[C_{\mathrm{L}} \int_{v_{\mathrm{DD}}}^{0}-v_{O} \mathrm{~d} v_{O}+C_{\mathrm{L}} \int_{v_{\mathrm{DD}}}^{0}-\left(V_{\mathrm{DD}}-v_{O}\right) \mathrm{d}\left(V_{\mathrm{DD}}-v_{O}\right)\right] \\
&=\frac{C_{\mathrm{L}}}{T}\left[\frac{1}{2} V_{\mathrm{DD}}^{2}+\frac{1}{2} V_{\mathrm{Do}}^{2}\right] \\
&=C_{\mathrm{L}} f V_{\mathrm{DD}}^{2}
\end{aligned}
$$
式中 $f=\frac{1}{T}$ 为输人信号的重复频率

**导通功耗$P_T$：**

![tmp9391](CMOS%20Technology.assets/tmp9391.png)

瞬时导通功耗$P_T$和电源电压 $V_{\mathrm{DD}}$，输入信号 $v_{1}$ 的重复频率 $f$以及电路内部参数有关。
$$
P_{\mathrm{T}}=C_{\mathrm{PD}} f V_{\mathrm{DD}}^{2}
$$
$C_{\mathrm{PD}}$称为功耗电容，它的具体数值由器件制造商给出，它并不是一个实际的电容，而仅仅是用来计算空载(没有外接负载) 瞬时导通功耗的等效参数，且只有在输入信号的上升时间和下降时间小于器件手册中规定的最大值时，它的参数才是有效的。
$$
\begin{aligned}
P_{\mathrm{D}} &=P_{\mathrm{C}}+P_{\mathrm{T}} \\
&=\left(C_{\mathrm{L}}+C_{\mathrm{PD}}\right) f V_{\mathrm{DD}}^{2}
\end{aligned}
$$
![tmp38D2](CMOS%20Technology.assets/tmp38D2.png)

**CMOS Timing Specifications**

![img](CMOS%20Technology.assets/Slide14.png)

![img](CMOS%20Technology.assets/Slide15.png)

$t_{PD}$ is an upper bound on the delay associated with *any* input transition.From the designer’s point of view, we can rely on this upper bound for each component of a larger digital system and use it to calculate the system’s $t_{PD}$ without having to repeat all the manufacturer’s measurements. If our goal is to minimize the propagation delay of our system, then we’ll want to keep the capacitances and resistances as small as possible. There’s an interesting tension here: to make the effective resistance of a MOSFET switch smaller, we would increase its width. But that would add additional capacitance to the switch’s gate terminal, slowing down transitions on the input node that connects to the gate! It’s a fun optimization problem to figure out transistor sizing that minimizes the overall propagation delay.

![img](CMOS%20Technology.assets/Slide16.png)

By the way, manufacturers often use the term “minimum propagation delay” to refer to a device’s contamination delay. That terminology is a bit confusing, but now you know what it is they’re trying to tell you.

![img](CMOS%20Technology.assets/Slide18-163513027863514.png)

> Acyclic: 无环的

此外还有一点：即使改变输入，使输出由0变为0（或者由1变为1），在$t_{CD}$和$t_{PD}$之间输出的值还是不可预测的。

![img](CMOS%20Technology.assets/Slide20.png)

When does lenience matter? We’ll need lenient components when building memory components, a topic we’ll get to in a couple of lectures.

#### 其他类型的CMOS门电路

![img](CMOS%20Technology.assets/Slide09.png)

> 这个就是代入定理的应用。再复杂的逻辑都可以层次化为上拉与下压两个电路的互补。

If the circuits are incorrectly designed so that they are not complementary and could both be conducting for an extended period of time, there’s a path between $V_{DD}$ and GND and large amounts of short circuit current will flow, a very bad idea. Since our simple switch model won’t let us determine the output voltage in this case, we’ll call this output value X or unknown. 

Another possibility with a non-complementary pullup and pulldown is that neither is conducting and the output node has no connection to either power supply voltage. At this point, the output node is electrically floating and whatever charge is stored by the nodal capacitance will stay there, at least for a while. This is a form of memory and we’ll come back to this in a couple of lectures.

no connection还有另外一种应用：即在电路中有物理连接却没有信号传递，允许了电路的层次化模块化的设计。

![img](CMOS%20Technology.assets/Slide10.png)

![tmp55F3](CMOS%20Technology.assets/tmp55F3.png)

![img](CMOS%20Technology.assets/Slide12.png)

> 如何判断下拉和上拉结构？对应N管的是下拉，对应P管的是上拉，不会混在一起的！即：原变量对应的是N管，属于pulldown；而反变量对应的是P管，属于pullup.

> 如果逻辑式并不是这样的整齐，即反变量和原变量混在一起了怎么办？没有办法，前边加反相器！

Using more complicated series/parallel networks of switches, we can build devices that implement more complex logic functions.

CMOS工艺中没有同相器、与、或，而是有反相器、与非、或非，这是因为"CMOS gates are naturally inverting"。原理：CMOS工艺把N管放在了下拉的位置。Any NFET switches controlled by the rising input will go from OFF to ON. This may enable one or more paths between the gate’s output and GND. And PFET switches controlled by the rising input will go from ON to OFF. This may disable one or more paths between the gate’s output and $V_{DD}$. So if the gate’s output changes as the result of the rising input, it must be because some pulldown path was enabled and some pullup path was disabled. In other words, any change in the output voltage due to a rising input must be a falling transition from 1 to 0.

> 正是因为CMOS工艺对N管来说天然是反向的，所以才有直接用$F^{\prime}$表示下拉的方法！

> N管为什么是反的？因为物理约束，N管的源极与栅极的电位高低关系。

> 问：为表示$F^{\prime}=A B+B C D$，至少用几个NMOS管，至少用几个PMOS管？
>
> 首先要了解，逻辑式最简并不代表着电路最简，也并不代表着用的逻辑管越少！如$F=AB+BC$,电路反而没有$F=(A+C)B$简单！

> 练习:不考虑缓冲级，用最少的MOS管，实现：
> $$
> F_{1}=A^{\prime} B^{\prime}+B^{\prime} D^{\prime}+C^{\prime} D^{\prime}+B D^{\prime}
> $$
> 和：
> $$
> F^{\prime}{ }_{2}=A B+C D+B D
> $$


与非门：

![tmp95EE](CMOS%20Technology.assets/tmp95EE.png)

或非门：

![tmpC396](CMOS%20Technology.assets/tmpC396.png)

与非门、或非门和反相器又可组成与门、或门、与或非门、异或门等。

以上门电路的结构虽然简单，但是也有着严重的缺点。以与非门为例，首先，它的输出电阻$R_O$受输入端状态的影响。假定每个MOS管的导通内阻均为$R_{ON}$,截止内阻$R_{OFF} \approx \infty$

则：

若 $A=B=1$, 则 $R_{o}=R_{ON2}+R_{ON4}=2 R_{ON}$;

若 $A=B=0$, 则 $R_{o}=R_{ON1} / / R_{ON 3}=\frac{1}{2} R_{\mathrm{ON}}$;

若 $A=1, B=0$, 则 $R_{o}=R_{ON3}=R_{ON }$;

若 $A=0, B=1$, 则 $R_{o}=R_{ON1}=R_{ON}$

可见，输入状态的不同可以使输出电阻相差4倍之多。

> 比较与非门和简单的反相器，如果它们作为电压源，哪一个输出的电压质量更高？
>
> 应该是与非门。首先，它输出电压高(因为底下两个管串联)；其次，它的内阻小（因为上边是内阻，两个管并联）

其次，输出的高低电平受输入端数目的影响。输入端数目越多，串联的驱动管数目也越多，输出的低电平$V_{OL}$也越高。当输入全部为低电平时，输入端越多负载管并联的数目越多，输出高电平$V_{OH}$也越高。

此外输出端工作状态不同时对电压传输特性也有一定影响。

为了克服这些缺点,在实际生产的 CMOS 电路中均采用带缓冲级的结构, 就是在门电路的每个输入端、输出端各增设一级反相器。加进的这些具有标准参数的反相器称为缓冲器。

![tmpB9C3](CMOS%20Technology.assets/tmpB9C3.png)

**漏极开路的门电路（OD路）**

在CMOS电路中,为了满足输出电平变换,吸收大负载电流以及实现线与连接等需要,有时将输出级电路结构改为一个漏极开路输出的MOS管,构成漏极开路输出(Open-Drain Output)门电路,简称OD门。

其来源是这样的：

![tmp3CC1](CMOS%20Technology.assets/tmp3CC1.png)

如果普通的这样接线的话，如果一个上拉一个下拉，即一个输出“1”一个输出“0”，就会形成短路：

![tmpDA3A](CMOS%20Technology.assets/tmpDA3A.png)

所以做了这样的改装：

![tmpAF6D](CMOS%20Technology.assets/tmpAF6D.png)

![tmp6377](CMOS%20Technology.assets/tmp6377.png)
$$
\begin{aligned}
Y &=Y_{1} \cdot Y_{2} \\
&=(A B)^{\prime}(C D)^{\prime}=(A B+C D)^{\prime}
\end{aligned}
$$
这样就将两个OD输出与非门接成了一个与或非电路。线与的逻辑符号是画在线与连接点处的与门轮廓。

> 看到OD门的符号，就要想到自己要外接一个电源并选定电阻了！

![tmp5C14](CMOS%20Technology.assets/tmp5C14.png)

**传输门**

利用P沟道MOS管和N沟道MOS管的互补性可以接成CMOS传输门。CMOS传输门如同CMOS反相器一样，也是构成各种逻辑电路的一种基本单元电路。

![tmpE9EB](CMOS%20Technology.assets/tmpE9EB.png)

![tmp13D5](CMOS%20Technology.assets/tmp13D5.png)

设控制信号$C$和$C^{\prime}$的高低电平分别是$V_{DD}$和0V，那么当$C=0, C^{\prime}=1$时，只要输入信号的变化范围不超过$0 \sim V_{DD}$，则$T_1$和$T_2$同时截止，输入和输出之间呈高阻态$\left(>10^{9} \Omega\right)$，传输门截止。反之,若 $C=1, C^{\prime}=\mathbf{0}$, 而且在 $R_{\mathrm{L}}$ 远大于 $\mathrm{T}_{1}, \mathrm{~T}_{2}$ 的导通电阻的情况下, 则当 $0<v_{1}<V_{\mathrm{DD}}-V_{GS(\mathrm{th}) \mathrm{N}}$ 时 $\mathrm{T}_{1}$ 将导通。而当 $\left|V_{GS(\mathrm{th}) \mathrm{P}}\right|<v_{1}<V_{DD}$ 时 $\mathrm{T}_{2}$ 导通。因此, $v_{1}$ 在 $0 \sim V_{\mathrm{DD}}$ 之间变化时, $\mathrm{T}_{1}$ 和 $\mathrm{T}_{2}$ 至少有一个是导通的,使 $v_{1}$ 与 $v_{0}$ 两端之间呈低阻态 $($ 小于 $1 \mathrm{k} \Omega$ ), 传输门导通。

> 注意：由于要求负载电阻非常大，所以这个模拟开关带负载能力弱。后端负载要求是一个小负载（即电流小）。如果后端是CMOS门电路，则电流是0，正好可以适用。

由于$T_1$、$T_2$管的结构形式是对称的，即漏极和源极可以互易使用，因而CMOS传输门属于双向器件，它的输入端和输出端也可以互易使用。

利用CMOS传输门和CMOS反相器可以组合成各种复杂的逻辑电路，如异或门、数据选择器、寄存器、计数器等。

![tmp512D](CMOS%20Technology.assets/tmp512D.png)

> A信号是为了控制传输门、B信号才是要被传输的信号

传输门的另一个重要用途是作模拟开关，用来传输连续变化的模拟电压信号。这一点是无法用一般的逻辑门实现的。模拟开关的基本电路是由CMOS传输门和一个CMOS反相器组成的。和CMOS传输门一样，它也是双向器件。

![tmp1B7E](CMOS%20Technology.assets/tmp1B7E.png)

![tmp612E](CMOS%20Technology.assets/tmp612E.png)

假定接在输出端的电阻为$R_{L}$，双向模拟开关的导通内阻为$R_{TG}$。当C=0（低电平）时开关截止，$v_{o}=0$。当C=1（高电平）时，$v_{o}=\frac{R_{\mathrm{L}}}{R_{\mathrm{L}}+R_{\mathrm{TG}}} v_{i}$。

我们将$V_o$和$V_i$的比值定义为电压传输系数$K_{TG}$，即：
$$
K_{\mathrm{TG}}=\frac{v_{0}}{v_{1}}=\frac{R_{\mathrm{L}}}{R_{\mathrm{L}}+R_{\mathrm{TG}}}
$$
![tmp7B5F](CMOS%20Technology.assets/tmp7B5F.png)

**三态输出的CMOS门电路**

三态输出门电路的输出除了有高、低电平两个状态以外，还有第三个状态——高阻态。下图是三态输出反相器的电路结构图，因为这种电路结构总是接在集成电路的输出端，所以也将这种电路称为输出缓冲器（Output Buffer）

![tmpB1CF](CMOS%20Technology.assets/tmpB1CF.png)

![tmpD4E8](CMOS%20Technology.assets/tmpD4E8.png)

EN：enable信号

三态输出反相器的逻辑符号如上。反相器符号内的三角形记号表示三态输出结构, $E N^{\prime}$ 输入端处的小圆圈表示 $E N^{\prime}$ 为低电平有效信号, 即只有在$E N^{\prime}$ 为低电平时 , 电路方处于正常工作状态。如果 $E N^{\prime}$ 为高电平有效,则没有这个小圆圈。这种三态输出结构有时也用于其他逻辑 功能CMOS 集成电路的输出端。

在一些比较复杂的数字系统（例如微型计算机）当中，为了减少各个单元之间的连线数目，希望能用同一条导线分时传递若干个门电路的输出信号。这时可用下图的连接方法。图中的 $G_{1}, G_{2}, \cdots, G_{n}$ 均为三态输出反相器，只要工作过程中控制各个反相器的 $E N$ 端轮流等于 1 , 而且任何时候仅有一个等于 1, 就可以轮流地把各个反相器的输出信号送到公共的传输线——总线上,而互不干扰。这种连接方式称为总线结构。

![tmp330E](CMOS%20Technology.assets/tmp330E.png)

> 注意这个总线结构，如果EN=1时（这里没有那个反向的符号了！），就成了正常的反相器。所以如果有多于两个EN=1，则会产生那种短路的后果。

总线（Bus）是指计算机组件间规范化的交换数据（data）的方式，即以一种通用的方式为各组件提供数据传送和控制逻辑。从另一个角度来看，如果说主板（Mother Board）是一座城市，那么总线就像是城市里的公共汽车（bus），能按照固定行车路线，传输来回不停运作的比特（bit）。这些线路在同一时间内都仅能负责传输一个比特。因此，必须同时采用多条线路才能发送更多资料，而总线可同时传输的资料数就称为宽度（width），以比特为单位，总线宽度愈大，传输性能就愈佳。总线的带宽（即单位时间内可以传输的总资料数）为：总线带宽 = 频率×宽度（Bytes/sec）。

> 总线技术：不仅允许了系统设计复杂化，也有时间换空间，数据串行的运输。

利用三态输出结构的门电路还能实现数据的双向传输。当 $E N=1$ 时, $G_{1}$ 工作而 $G_{2}$ 为高阻态,数据 $D_{o}$ 经过 $G_{1}$ 反相后送到总线上去。当 $E N=0$时, $G_{2}$ 工作而 $G_{1}$ 为高阻态, 来自总线的数据 $D_{1}$ 经过 $G_{2}$ 反相后送入电路内部。

![tmp8409](CMOS%20Technology.assets/tmp8409.png)

#### CMOS集成电路的正确使用

**输入电路的静电防护**

CMOS集成电路在储存、运输、组装和调试过程中，难免会接触到某些带静电高压的物体。为防止由静电电压造成的损坏，应注意：

1. 在储存和运输CMOS器件时不要使用易产生静电高压的化工材料和化纤织物包装。通常都将器件插在导电的泡沫塑料上,并采用金属屏蔽层作包装材料。在从包装中取下时,应避免用手触摸器件的引脚,并将器件放置在接地的导电平面上。
2. 在将 CMOS器件插入电路板或从电路板中拔出时,应关掉电源。
3. 不用的输入端不应悬空。
   

**输入电流的过流保护**

![tmp3E9C](CMOS%20Technology.assets/tmp3E9C.png)

**锁定效应的防护**

锁定效应（Latch up）或称为可控硅效应（Silicon Controlled Rectifer）是CMOS电路中的一个特有问题。发生锁定效应以后往往会造成器件的永久失效，因而了解其锁定效应的产生原因及其防护方法十分必要。

![tmp9B2A](CMOS%20Technology.assets/tmp9B2A.png)

![tmpB287](CMOS%20Technology.assets/tmpB287.png)

![tmp2F0B](CMOS%20Technology.assets/tmp2F0B.png)
