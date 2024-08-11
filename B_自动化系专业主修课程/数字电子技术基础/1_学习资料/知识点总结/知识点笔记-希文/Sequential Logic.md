# 时序逻辑

![img](Sequential%20Logic.assets/Slide02.png)

![img](Sequential%20Logic.assets/Slide03.png)

Circuits that include both combinational logic and memory components are called sequential logic. The memory component has a specific capacity measured in bits. If the memory component stores K bits, that puts an upper bound of $2^{K}$ on the number of possible states since the state of the device is encoded using the K bits of memory.

通常将只能存储一位数据的电路叫做存储单元, 将用于存储一组数据的存储电路叫做寄存器 (Register), 将用于存储大量数据的存储电路叫做存储器（Memory）。寄存器和半导体存储器中都包含了许多存储单元。

半导体存储电路中使用的存储单元可以分为静态存储单元和动态存储单元两大类。静态存储单元由门电路连接而成, 其中包括各种电路结构形式的锁存器和触发器。只要不切断供电电源,静态存储单元的状态会一直保持下去。动态存储单元则是利用电容的电荷存储效应来存储 数据的。由于电容的充放电需要一定的时间, 因而它的工作速度低于静态存储单元。而且,电容 上存储的电荷会随着时间的推移而逐渐泄漏, 必须定期进行 “刷新” (即将原来的数据重新写入), 才能保证数据不会丢失。虽然如此, 由于动态存储单元的电路结构十分简单, 所以仍然被广泛用于大容量的存储器当中。

寄存器由一组触发器组成,每个触发器的输入和输出都有引出端, 可以直接和周围电路连接, 快速地进行数据交换。由 $n$ 个触发器组成的寄存器可以存储一组 $n$ 位的二值数据。

存储器的种类虽然很多,但它们的基本结构形式都是由存储矩阵和读/写控制电路两部分组成的。首先,根据工作方式的不同, 可以将存储器分为随机存储器（Random Access Memory,简称 RAM) 和只读存储器 ( Read-Only Memory, 简称 ROM) 两大类。随机存储器的工作特点是可以随 时从其中快速地读出或写入数据。随机存储器又分成静态随机存储器 (Static Random Access Memory, 简称 SRAM) 和动态随机存储器 (Dynamic Random Access Memory, 简称 DRAM), 静态随机存储器中采用的是静态存储单元, 而动态存储器中采用的则是动态存储单元。

只读存储器的工作方式与随机存储器不同,在正常的读/写工作状态下, 只能从其中读出所存储的数据。因此, 只读存储器一般都用来存储一些固定的数据。只读存储器中又有“掩模 ROM" (Mask Read-Only Memory)、“可编程 ROM"(Programmable Read-Only Memory,简称 PROM) 和“可擦除的可编程 ROM" ( Erasable Programmable Read-Only Memory,简称 EPROM) 几种不同类 型。掩模 ROM 中的数据在制作芯片时已经确定,无法更改。而 PROM 中的数据可以由用户根 据自己的需要写入,但一经写入以后就不能再修改了。EPROM 中的数据则不但可以由用户自己写入,而且还能擦除重写,所以具有更大的使用灵活性。早期的 EPROM 曾经采用紫外线照射的 方法进行擦除,但不仅擦除操作非常费时,而且器件的成本也比较高, 所以现在已经完全被使用电信号擦除的 EPROM ( Electrically Erasable Programmable Read-Only Memory, 简称 $\mathrm{E}^{2} \mathrm{PROM}$ ) 所取 代。目前在 $U$ 盘和各种便携式移动设备中广泛使用的“内存” (Flash Memory) 就是一种 E $^{2}$ PROM 。虽然 EPROM 中的数据可以擦除改写, 但由于擦除改写的速度相对读出的速度慢得 多,所以通常仍然将它用作只读存储器。

我们可以用电容的方式来存储数据：

![img](Sequential%20Logic.assets/Slide04.png)

word line是控制NFET开关开启或关闭的，而电容存储的电荷（即高、低电平代表了电路存储的状态）。

Reading and writing require a whole sequence of operations, along with carefully designed analog electronics. The good news is that the individual storage capacitors are quite small — in modern integrated circuits we can fit billions of bits of storage on relatively inexpensive chips called dynamic random-access memories, or DRAMs for short. DRAMs have a very low cost per bit of storage.

The bad news is that the complex sequence of operations required for reading and writing takes a while, so access times are relatively slow. And we have to worry about carefully maintaining the charge on the storage capacitor in the face of external electrical noise. The really bad news is that the NFET switch isn’t perfect and there’s a tiny amount leakage current across the switch even when it’s officially off. Over time that leakage current can have a noticeable impact on the stored charge, so we have to periodically refresh the memory by reading and re-writing the stored value before the leakage has corrupted the stored information. In current technologies, this has to be done every 10ms or so.

![image-20211109123227758](Sequential%20Logic.assets/image-20211109123227758.png)

> 首先，输出接入了输入，所以是一个反馈。而它是一个正反馈，即反馈会加剧扰动。正因为这样的反馈，所以会让系统稳定在0或者1。
>
> 不能有刻板印象：正反馈一定会不稳定，负反馈一定会稳定。

The two points of intersection at either end of the VTC are stable in the sense that small changes in $V_{\mathrm{IN}}$ (due, say, to electrical noise), have no effect on $V_{\text {OUT }}$ . So the system will return to its stable state despite small perturbations.

所以，因为这个工作元件不是0就是1，所以可以存储0和1了。但是唯一的问题就是我们不知道它存储的究竟是0还是1，而且我们无法对其进行写入。

## 锁存器

### SR锁存器

SR锁存器（Set-Reset Latch）是静态存储单元当中最基本、也是电路结构最简单的一种。通常它由两个或非门或者与非门组成。下图给出了用两个或非门组成的SR锁存器的电路。

![image-20211109124616130](Sequential%20Logic.assets/image-20211109124616130.png)

![image-20211109124847597](Sequential%20Logic.assets/image-20211109124847597.png)

> 最后一种情况：用通俗的语言来讲，在$S_{\mathrm{D}}$和$R_{\mathrm{D}}$同时回到0以后，哪个信号跑的快则会存储哪种状态，因而电路中实际上存储的是一个随机值。因此应避免这种情况的发生。
>
> 从这个机制也可以看出，当S为R同为1的时候，电路中存储的值并不是不确定的（Q和$Q^{\prime}$都是0，从电路分析即可看出），真正不确定的是当同时把S和R撤掉后电路中存储的值。

> S和R是怎样命名的呢？S是SET，S为1的时候就是置1（Q是锁存器中存储的数据），而R是RESET，R为1的时候就是置0。

> "不确定"在这里应当理解为“不知道”。电路怎样其实是确定的，只是我们不知道而已。

将上述逻辑关系列成真值表。因为锁存器新的状态 $Q^{*}$ (也称为次态) 不仅与输入状态有关,而且与锁存器原来的状态 $Q$ (也称为初态) 有关, 所以将 $Q$ 也作为一个变量列入了真值表,并将 $Q$ 称为状态变量,将这种含有状态变量的真值表称为锁存器的特性表（或功能表）。

![image-20211115093022745](Sequential%20Logic.assets/image-20211115093022745.png)

同时，SR锁存器也可以用与非门构成。

![image-20211115093050075](Sequential%20Logic.assets/image-20211115093050075.png)

读图，输入信号标了“取反”，即这个电路是以低电平作为输入信号的，也称低电平有效。

![image-20211115093139029](Sequential%20Logic.assets/image-20211115093139029.png)

在SR锁存器中，输入信号直接加在输出门上，所以输入信号在全部的作用时间里（即 $S_{\mathrm{D}}$ 或 $R_{\mathrm{D}}$ 为 1 的全部时间），都能直接改变输出端$Q$ 和 $Q^{\prime}$的状态。正是由于这个缘故，也将 $S_{\mathrm{D}}\left(S_{\mathrm{D}}^{\prime}\right)$ 称为直接置位端，将$R_{\mathrm{D}}\left(R_{\mathrm{D}}^{\prime}\right)$ 称为直接复位端，并且将这个电路称为直接置位、复位锁存器（Set-Reset Latch）。

分析：

![image-20211115094239454](Sequential%20Logic.assets/image-20211115094239454.png)

在$t_{3} \sim t_{4}$ 和 $t_{7} \sim t_{8}$期间输入端同时为低电平（与非门低电平有效），但是正是像之前讲的那样，同时为低电平的时候电路是确定的，即$Q$与$Q^{\prime}$均为1，而之后由于$S_{\mathrm{D}}^{\prime}$首先回到了高电平，所以锁存器的次态仍是可以确定的（次态不能确定的情况为两者“同时”回到高电平的情况）。这种情况也说明，在锁存器电路中，$Q$与$Q^{\prime}$并不是永远相反的。

## 触发器

触发器与锁存器的不同在于，触发器除了置 1 、置 0 输入端以外, 又增加了一个触发信号输入端。只在当触发信号到来时,触发器才能按照输入的置 $\mathbf{1}$ 、置 $\mathbf{0}$ 信号置成相应的状态, 并保持下去。 我们将这个触发信号称为时钟信号 $(\boldsymbol{C L O C K})$, 记作 $\boldsymbol{C L K}$ 。当系统中有多个触发器需要同时动作时，就可以用同一个时钟信号作为同步控制信号了。

在竞争冒险现象时，我们曾有过这样的想法，即等前端变化完成后再作为输入输入到后端，而这个用CLK信号就可以很好地做到，即“等你变化完了之后我再把你放进来”。

### 电平触发的触发器

![image-20211115095442901](Sequential%20Logic.assets/image-20211115095442901.png)

> 在一些国外教材中，也把这个电路叫做门控SR锁存器（Gated SR Latch），同时把时钟信号叫做“使能”控制信号（ENABLE），记做EN。

![image-20211115095628532](Sequential%20Logic.assets/image-20211115095628532.png)

在某些应用场合，有时需要在CLK的有效电平到达之前预先将触发器置成指定状态，为此还设置有异步置1输入端$S_{\mathrm{D}}^{\prime}$和异步置0输入端$R_{\mathrm{D}}^{\prime}$。

![image-20211115095829379](Sequential%20Logic.assets/image-20211115095829379.png)

动作特点：在 $C L K=1$ 的全部时间里, $S$ 和 $R$ 状态的变化都可能引起输出状态的改变。在 $C L K$ 回到0 以后,触发器保存的是 $C L K$ 回到 0 以前瞬间的状态。

根据上述的动作特点可以想象到,如果在 $C L K=1$ 期间 $S 、 R$ 的状态多次发生变化. 那么触发器输出的状态也将发生多次翻转,这就降低了触发器的抗干扰能力。

![image-20211115100107587](Sequential%20Logic.assets/image-20211115100107587.png)

> 抗干扰能力：即观察在第二个CLK高电平期间，S端出现了一个干扰脉冲，因而触发器被置成了Q=1.

但是，上述触发器还是没有解决电路中“不确定”的状态，我们可以从电路设计中去避免这一问题：

![image-20211115100407754](Sequential%20Logic.assets/image-20211115100407754.png)

![image-20211115100426147](Sequential%20Logic.assets/image-20211115100426147.png)

![image-20211115100530820](Sequential%20Logic.assets/image-20211115100530820.png)



![img](Sequential%20Logic.assets/Slide06.png)

We can use a 2-to-1 multiplexer to build a settable storage element. Recall that a MUX selects as its output value the value of one of its two data inputs. The output of the MUX serves as the state output of the memory component. Internally to the memory component we’ll also connect the output of the MUX to its D0 data input. The MUX’s D1 data input will become the data input of the memory component. And the select line of the MUX will become the memory component’s load signal, here called the gate.

从数据选择器的角度，我们也可以制造出D型锁存器。

![img](Sequential%20Logic.assets/Slide07.png)

Our theory is that after G transitions to a LOW value, Q will stay stable at whatever value was on D when G made the HIGH to LOW transition. But, we know that in general, we can’t assume anything about the output of a combinational device until tPD after the input transition — the device is allowed to do whatever it wants in the interval between tCD and tPD after the input transition. But how will our memory work if the 1-to-0 transition on G causes the Q output to become invalid for a brief interval? After all it’s the value on the Q output we’re trying to remember! We’re going to have ensure that a 1-to-0 transition on G doesn’t affect the Q output.



![img](Sequential%20Logic.assets/Slide08-16369443746984.png)

That’s why we specified a lenient MUX for our memory component. 

Does lenience guarantee a working latch? Well, only if we’re careful about ensuring that signals are stable at the right times so we can leverage the lenient behavior of the MUX.

![img](Sequential%20Logic.assets/Slide09.png)

In summary, the dynamic discipline requires that the D input be stable and valid  both before and after a transition on G. 

 ![img](Sequential%20Logic.assets/Slide10.png)

If the gate stays HIGH too long, we’ve created a loop in our system and our plan to load the latch with new state goes away as the new state value starts to change rapidly as information propagates around and around the loop.

> 即如果G一直是1的话，假设中间的combinational logic是取反，那么current state经过tpd传输过来new state即为current state取反，整个电路的状态以tpd的频率在进行“闪烁”。

So to make this work, we need to carefully time the interval when G is HIGH. It has to be long enough to satisfy the constraints of the dynamic discipline, but it has to be short enough that the latch closes again before the new state information has a chance to propagate all the way around the loop.

![img](Sequential%20Logic.assets/Slide11.png)

![img](Sequential%20Logic.assets/Slide12.png)

### 脉冲触发的触发器

脉冲触发的触发器也叫做主从结构。

![image-20211115120400892](Sequential%20Logic.assets/image-20211115120400892.png)

![image-20211115131218918](Sequential%20Logic.assets/image-20211115131218918.png)

> 即主从触发器虽然只在下降边缘处触发，所以不能只看下降过程中输入端的状态来判断输出的状态，而要向前看是如何变化的。

![image-20211116123217090](Sequential%20Logic.assets/image-20211116123217090.png)

注意最后部分的“不定”：正如下面所说，当CLK有效电平消失后，电路的状态就处于不定状态。而当最后一小截电路又回到下降沿的时候状态又可以确定了。

**JK触发器**

在主从触发器中，仍需遵守$S R=\mathbf{0}$的约束条件，否则当CLK有效电平消失后，或S、R端的高电平同时回到低电平时，不能确定触发器的次态。为了解除这一约束，如果我们规定当输入为$S=R=1$时，触发器的次态为初态的反状态，即$Q^{*}= Q^{\prime}$,这样触发器的次态也能确定了。

不难想到,在 $S R$ 触发器的基础上,如果当 $S=R=1$ 时,将 $Q$ 和 $Q^{\prime}$ 接回到输入端,用 $Q^{\prime}$ 代替 $S$ 端的输入信号,用 $Q$ 代替 $R$ 端的输入信号, 就可以实现上述要求了。具有这种逻辑功能的触发器称为JK触发器。

![image-20211115132219394](Sequential%20Logic.assets/image-20211115132219394.png)

![image-20211115132246624](Sequential%20Logic.assets/image-20211115132246624.png)

在有些集成电路触发器展品中，输入端不止一个，在这种情况下不同的J与不同的K应该是与的逻辑关系。

![image-20211115133214062](Sequential%20Logic.assets/image-20211115133214062.png)

在JK触发器中，由于 $Q, Q^{\prime}$ 端接回到了输入门上, 所以在 $Q=\mathbf{0}$ 时主触发器只能接受置 1 输入信号,在 $Q=1$ 时主触发器只能接受置 0 信号。其结果就是在 $C L K=1$ 期间主触发器只有可能翻转一次,一旦翻转了就不会翻回原来的状态。但在 $S R$ 触发器中,由于没有 $Q 、 Q^{\prime}$ 端接到输入端的反馈线,所以 $C L K=\mathbf{1}$ 期间 $S 、 R$ 状态多次改变时主触发器状态也会随着多次翻转。

> 所以在这里要看在CLK=1时主触发器输入的第一次变化（因为JK触发器只可能发生一次翻转）。

![image-20211115134203185](Sequential%20Logic.assets/image-20211115134203185.png)

### 边沿触发的触发器

利用CMOS传输门的边沿触发器

![image-20211115134633796](Sequential%20Logic.assets/image-20211115134633796.png)

为提高触发器的可抗性，增强抗干扰能力，希望触发器的次态仅仅取决于CLK信号下降沿（或上升沿）到达时刻输入信号的状态，而在此之前和之后输入状态的变化对触发器的次态没有影响。为实现这一设想，人们相继研制成了各种边沿触发（edge-triggered）的触发器电路。

> 注意这里边沿触发器的表示！只要有三角（封装后C1左边有一个三角形的标识），表示的就是边沿触发器。

![image-20211115141305846](Sequential%20Logic.assets/image-20211115141305846.png)

![image-20211115141322990](Sequential%20Logic.assets/image-20211115141322990.png)

![image-20211115141338350](Sequential%20Logic.assets/image-20211115141338350.png)

> “异步”：与时钟信号有关的称为“同步”，而与时钟信号无关的称为“异步”。

## 触发器的逻辑功能

由于每一种触发器电路的信号输入方式不同（有单端输入的也有双端输入的），触发器的次态与输入信号逻辑状态间的关系也不相同，故其逻辑功能也不完全一样。

按照逻辑功能的不同特点，通常将时钟控制的触发器分为SR触发器、JK触发器、T触发器和D触发器几种类型。

### SR触发器

凡在时钟信号下逻辑功能符合下标的均成为SR触发器。

![image-20211115150946278](Sequential%20Logic.assets/image-20211115150946278.png)

逻辑式：
$$
\left\{\begin{array}{l}
Q^{*}=S^{\prime} R^{\prime} Q+S R^{\prime} Q^{\prime}+S R^{\prime} Q=S R^{\prime}+S^{\prime} R^{\prime} Q \\
S R=\mathbf{0} \quad(\text { 约束条件 })
\end{array}\right.
$$
利用约束条件将上式化简，于是得出：
$$
\left\{\begin{array}{l}
Q^{*}=S+R^{\prime} Q \\
S R=0 \quad(\text { 约束条件 })
\end{array}\right.
$$
称为SR触发器的特性方程。

虽然用特性表描述触发器的逻辑功能比较直观，但是不能用特性表进行逻辑运算，在下一章中可以看到，在进行时序逻辑电路的分析和设计时，就必须使用特性方程描述触发器的逻辑功能了。

如下为SR触发器：

![tmp2B0F](Sequential%20Logic.assets/tmp2B0F.png)

![tmp3735](Sequential%20Logic.assets/tmp3735.png)

状态转换图：

![image-20211115161635158](Sequential%20Logic.assets/image-20211115161635158.png)

> 有限状态机：FSM



### JK触发器

![image-20211115154203003](Sequential%20Logic.assets/image-20211115154203003.png)

如下为JK触发器：

![tmpE71D](Sequential%20Logic.assets/tmpE71D.png)

![tmpF3C1](Sequential%20Logic.assets/tmpF3C1.png)

状态转换图：

![image-20211115162401999](Sequential%20Logic.assets/image-20211115162401999.png)



### T触发器

![image-20211115154309332](Sequential%20Logic.assets/image-20211115154309332.png)

状态转换图：

![image-20211115162531256](Sequential%20Logic.assets/image-20211115162531256.png)

### D触发器

![image-20211115154433280](Sequential%20Logic.assets/image-20211115154433280.png)

以下为D触发器：

![tmpE35D](Sequential%20Logic.assets/tmpE35D.png)

![tmpF30D](Sequential%20Logic.assets/tmpF30D.png)

![tmp280](Sequential%20Logic.assets/tmp280.png)

状态转换图:

![image-20211115162303831](Sequential%20Logic.assets/image-20211115162303831.png)

将JK、SR和T三种类型触发器的特性表比较一下不难看出，JK触发器的逻辑功能最强，它包含了SR触发器和T触发器的所有逻辑功能，因此，在需要使用SR触发器和T触发器的场合完全可以用JK触发器来取代。因此，目前生产的触发器定型产品中只有JK触发器和D触发器两大类。

![image-20211115154613136](Sequential%20Logic.assets/image-20211115154613136.png)

逻辑功能和触发方式是触发器两个最重要的特性。逻辑功能是指稳态下触发器的次态和初态与输入之间的逻辑关系，而触发方式则指出了触发器在动态翻转过程中的动作特点。

触发器的触发方式是由电路结构形式决定的，因此触发器的触发方式和电路结构形式之间有固定的对应关系。然而触发器的触发方式和逻辑功能之间并无固定的对应关系。也就是说同一种逻辑功能的触发器可以采用不同的触发方式，同一种触发方式的触发器可以具有不同的逻辑功能。

> 在电路设计中，尽量用一种触发方式，而更常用的是边沿触发方式。

![image-20211115155712370](Sequential%20Logic.assets/image-20211115155712370.png)

## 触发器的动态特性

通常用建立时间、保持时间、传输延迟时间以及最高时钟频率等几个参数具体描述触发器的动态特性。

以边沿触发D触发器为例，为了叙述方便，假定图中传输门从控制信号$C$ 和 $C^{\prime}$ 跳变到它的输出状态改变的延迟时间、反相器的传输延迟时间都是$t_{d}$。

### 建立时间（Setup time）

![image-20211115160604583](Sequential%20Logic.assets/image-20211115160604583.png)

![image-20211115160618856](Sequential%20Logic.assets/image-20211115160618856.png)

### 保持时间（Hold time）

![image-20211115160847136](Sequential%20Logic.assets/image-20211115160847136.png)

### 传输延迟时间（Propagation delay time）

![image-20211115160925928](Sequential%20Logic.assets/image-20211115160925928.png)

### 最高时钟频率（Maximum clock frequency）

![image-20211115161429064](Sequential%20Logic.assets/image-20211115161429064.png)



触发器的动态参数取决于电路结构形式以及其中每个门电路的传输延迟时间, 所以各种触发器的动态参数随电路结构形式和内部电路参数的不同而异。而且,这些电路参数又有一定的分散性。实际上每种集成电路触发器产品的动态参数最后都要通过实验来测定,然后给出参数的范围。所以，以上的分析仅仅停留在理论层面。

![img](Sequential%20Logic.assets/Slide15.png)

There is one tricky problem we have to solve when designing the circuitry for the register. On the falling clock edge, the slave latch transitions from open to closed and so its input (the STAR signal) must meet the setup and hold times of the slave latch in order to ensure correct operation.

The complication is that the master latch opens at the same time, so the STAR signal may change shortly after the clock edge. The contamination delay of the master latch tells us how long the old value will be stable after the falling clock edge. And the hold time on the slave latch tells us how long it has to remain stable after the falling clock edge.

> 也就是说星信号在CLK变化后必须要能够保持一定时间的稳定。

 If necessary, extra gate delays (*e.g.*, pairs of inverters) can be added between the master and slave latches to increase the contamination delay on the slave’s input relative to the falling clock edge. Note that we can only solve slave latch hold time issues by changing the design of the circuit.

总结：

![image-20211115170134733](Sequential%20Logic.assets/image-20211115170134733.png)

![img](Sequential%20Logic.assets/Slide20.png)

This completes our introduction to sequential logic. Pretty much every digital system out there is a sequential logic system and hence is obeying the timing constraints imposed by the dynamic discipline. So next time you see an ad for a 1.7 GHz processor chip, you’ll know where the “1.7” came from!

## 寄存器

寄存器（Register）能够寄存一组二值代码，它被广泛应用于数字计算机和各种复杂数字系统当中。

N位寄存器由N个触发器组成，可存放一组N位二值代码。只要求其中每个触发器可置1，可置0。

一些术语：

- 存储器单元cell：用于存储一个bit的电路单元
- 字节Byte = 8 bits
- 字Word = 1-8 Bytes 一个字中有8-64bits
- $1 \mathrm{~B}=8 \mathrm{bit} ; 1 \mathrm{~KB}=1024 \mathrm{~B} ; 1 \mathrm{MB}=1024 \mathrm{~KB} ; 1 \mathrm{~GB}=1024 \mathrm{MB}$

![image-20211115170738807](Sequential%20Logic.assets/image-20211115170738807.png)

- 容量：表示特定存储器单元或整个存储器系统能够存储多少bits
- 密度：表示容量的另一术语
- 地址：表示word在存储系统中位置。

![image-20211115172244258](Sequential%20Logic.assets/image-20211115172244258.png)

## 存储器

存储器是一种能够存储大量二值信息（或称为数据）的器件。由于计算机以及其他一些数字系统的工作过程中，都需要对大量的数据进行存储，所以存储器也就成了计算机和这些数字系统不可缺少的部分。

存储容量和存取速度是衡量存储器性能的两个最重要指标。

因为半导体存储器的存储单元数目极其庞大而器件的引脚数目有限，所以在电路结构上就不可能像寄存器那样把每个存储单元的输入和输出直接引出。为了解决这个矛盾，在存储器中给每个存储单元编了一个地址，只有被输入地址代码指定的那些存储单元才能与公共的输入、输出引脚接通，进行数据的读写或写入。

![image-20211115171802238](Sequential%20Logic.assets/image-20211115171802238.png)

![image-20211115172433564](Sequential%20Logic.assets/image-20211115172433564.png)

### 静态随机存储器（SRAM）

所谓的“静态”，是指这种存储器只要保持通电，里面存储的数据就可以恒常保持。然而，当电力供应停止时，SRAM存储的数据还是会消失（被称为易失性存储器），这与在断电后还能存储资料的ROM或闪存是不同的。

SRAM电路通常由存储矩阵、地址译码器和读、写控制电路（也称输入、输出电路）三部分组成。

存储矩阵由许多存储单元排列而成，每个存储单元能够存储1位二值数据、

地址译码器一般都分成行地址译码器和列地址译码器两部分。

![image-20211121003158251](Sequential%20Logic.assets/image-20211121003158251.png)

![image-20211121003354705](Sequential%20Logic.assets/image-20211121003354705.png)

![image-20211121003337785](Sequential%20Logic.assets/image-20211121003337785.png)

![image-20211121003440393](Sequential%20Logic.assets/image-20211121003440393.png)

对上述存储结构再进行分析：

行地址一共六位，列地址一共4位，所以一共$2^6 \times 2^4 = 2^{10}$个地址，而输入、输出又有4位，所以是1024*4位。

有 $m$ 条地址线与 $n$ 条数据线的SRAM，其存储容量是 $2^{m}$ 个字 (word) $， 2^{m} \times n \mathrm{bit}$.

地址译码器：给定一个代码，输出只有一个是高电平。而交叉处即为高电平。

SRAM的静态存储单元：它是在SR锁存器的基础上附加门控管而构成的，因此，它是靠锁存器的自保功能存储数据的。

![image-20211121004336937](Sequential%20Logic.assets/image-20211121004336937.png)

> 理解$RW^{\prime}$,高电平时是R，低电平时是写W。

![image-20211121010625235](Sequential%20Logic.assets/image-20211121010625235.png)

> 注意读写控制电路那里是一个三态门。

> 仔细观察写电路的实现，在写的时候既写入了一个数据的原变量，也写入了这个数据的反变量。

![image-20211121025013749](Sequential%20Logic.assets/image-20211121025013749.png)

CPU中的cache以及内存条的价格比较贵，因为存一个bit的数据就需要六个CMOS管。

### 动态随机存储器（DRAM）

![image-20211121125754365](Sequential%20Logic.assets/image-20211121125754365.png)

![image-20211121125902709](Sequential%20Logic.assets/image-20211121125902709.png)

![image-20211121130021430](Sequential%20Logic.assets/image-20211121130021430.png)

![image-20211121130122534](Sequential%20Logic.assets/image-20211121130122534.png)

### 存储器容量的扩展

当使用一片ROM或RAM器件不能满足对存储容量的要求时，就需要将若干片ROM或RAM组合起来，形成一个容量更大的存储器。

**位扩展方式**

![image-20211121131021858](Sequential%20Logic.assets/image-20211121131021858.png)

**字扩展方式**

将多片存储器（RAM或ROM）芯片接成一个字数更多的存储器。（在生活中扩展内存条用的就是这种方法）。

![image-20211121150908243](Sequential%20Logic.assets/image-20211121150908243.png)

![image-20211121150923262](Sequential%20Logic.assets/image-20211121150923262.png)

> CPU的位数是指CPU能一次同时寄存和处理二进制数码的位数，这和CPU中寄存器的位数对应。
>
> CPU为了实现其功能一般设计了指令集，即是CPU的全部指令，这就是机器语言。计算机的所有功能都是基于CPU的指令集。
>
> **CPU位数准确地说应该是CPU一次能够并行处理的数据宽度，一般就是指数据总线宽度。**
>
> 计算机字长取决于数据总线的宽度，是指一次能传输的数据的位数，通常就是CPU一次能处理的数据的位数，所以字长就是取决于数据总线。像平时我们买电脑说的64位的处理器，指的就是字长为64的CPU。地址总线决定的是存储器的容量，因为要进行寻址。实际生活中就是主板对内存的支持容量是有限制的。
>
> 寻址空间，是地址总线决定的，而写程序访问地址，是靠寄存器决定的。

### 只读存储器ROM

在存储器的某些应用场合中，要求存储的是一些固定不变的数据（例如计算机里的字库）。正常工作状态下，这些数据只供读出使用，不需要随时进行修改。为了适应这种需要，又产生了另外一种类型的存储器——只读存储器（Read-Only Memory）。

![image-20211121163816100](Sequential%20Logic.assets/image-20211121163816100.png)

> 思路：这是一个输入地址和存储数据的关系，存储的数据是4*4，但是这不正好就是真值表吗。所以，一个组合电路可以用来表示一组数据。

![image-20211121152907087](Sequential%20Logic.assets/image-20211121152907087.png)

ROM的电路结构包含存储矩阵、地址译码器和输出缓冲器三个组成部分。

![image-20211121153942703](Sequential%20Logic.assets/image-20211121153942703.png)

![image-20211121154131614](Sequential%20Logic.assets/image-20211121154131614.png)

![image-20211121154142624](Sequential%20Logic.assets/image-20211121154142624.png)

![image-20211121164325771](Sequential%20Logic.assets/image-20211121164325771.png)

> 上边是与的关系，下边是或的关系。通过这样，就可以构成任何最小项。

![image-20211121154517472](Sequential%20Logic.assets/image-20211121154517472.png)

**ROM的分类**

![image-20211121154553653](Sequential%20Logic.assets/image-20211121154553653.png)

![image-20211121162906860](Sequential%20Logic.assets/image-20211121162906860.png)

![image-20211121163004892](Sequential%20Logic.assets/image-20211121163004892.png)

![image-20211121163140507](Sequential%20Logic.assets/image-20211121163140507.png)

![image-20211121163151036](Sequential%20Logic.assets/image-20211121163151036.png)

![image-20211121163250005](Sequential%20Logic.assets/image-20211121163250005.png)

### 用存储器实现组合逻辑函数

![image-20211121170441778](Sequential%20Logic.assets/image-20211121170441778.png)

![image-20211121170554281](Sequential%20Logic.assets/image-20211121170554281.png)

## 时序逻辑电路

时序逻辑电路：任一时刻的输出信号不仅取决于当时的输入信号，而且还取决于电路原来的状态。具备这种逻辑功能特点的电路称为时序逻辑电路。 

![image-20211121171410066](Sequential%20Logic.assets/image-20211121171410066.png)

![image-20211121171417607](Sequential%20Logic.assets/image-20211121171417607.png)

> **串行加法**器即**加法**器执行位**串行行**操作，利用多个时钟周期完成一次**加法**运算，即输入操作数和输出结果方式为随时钟**串行**输入/输出。 位并行**加法**器速度高，但是占用资源多。 在许多实际应用中并不需要这样高的速度，而是希望减少硬件资源占用率，这时就可以使用位**串行加法**器。
>
> 串行加法器只有一个全加器，每次计算后记录进位的结果并将其相加汇总。

时序结构在电路结构上有两个显著的特点：

- 时序电路通常包含组合电路和存储电路两个组成部分，存储电路是必不可少的
- 存储电路的输出状态必须反馈到组合电路的输入端，与输入信号一起，共同决定组合逻辑电路的输出

这里存储电路的触发器首选边沿触发器，且电路中时钟大多为同步的。

> 同步：存储电路中所有触发器的时钟使用统一的clk，状态变化发生在同一时刻。在电路中突出的特点就是所有CLK信号接在一起。
>
> 在电路设计与EDA软件中，同步信号也是首选，因为这样对于分析与设计十分方便。但是，电路能量的消耗一般发生在翻转时刻，而如果电路中所有翻转都发生在同一时刻，对电源的供电要求就高了。

![image-20211121172008856](Sequential%20Logic.assets/image-20211121172008856.png)

![image-20211121172101650](Sequential%20Logic.assets/image-20211121172101650.png)

![image-20211121172136440](Sequential%20Logic.assets/image-20211121172136440.png)

### 时序逻辑电路的分析方法

分析同步时序电路时一般按如下步骤进行：

- 从给定的逻辑图中写出每个触发器的驱动方程（以及存储电路中每个触发器输入信号的逻辑函数式）
- 将得到的这些驱动方程代入相应触发器的特性方程，得出每个触发器的状态方程，从而得到由这些状态方程组成的整个时序电路的状态方程组
- 根据逻辑图写出电路的输出方程

注意，第一步与第三步是组合电路的分析方法，只需要在电路图中读取相应的信息即可。而第二步则是要根据对应触发器的特性方程列出。

![image-20211122155234704](Sequential%20Logic.assets/image-20211122155234704.png)

理论上讲，有了驱动方程、状态方程和输出方程以后，时序电路的逻辑功能就已经描述清楚了。但是这还不够直观，如果将电路在一系列时钟信号作用下状态转换的全部过程找出来，则电路的逻辑功能就一目了然了。

**状态转化表**

若将任何一组输入变量及电路初态的取值代入状态方程和输出方程，即可算出电路的次态和现态下的输出值；以得到的次态作为新的初态，和此时的输入变量取值一起再代入状态方程和输出方程进行计算，又得到一组新的次态和输出值。如此继续，将全部的计算结果列成真值表的形式，就得到了状态转换表。

![image-20211122155927737](Sequential%20Logic.assets/image-20211122155927737.png)

> 八种状态，因为一共有三个触发器，每个中间都可能存储0或者1。

也可将电路的状态转换表列成下表的形式。这种状态转换表给出了在一系列时钟信号作用下电路状态转换的顺序，比较直观。

![image-20211122160146871](Sequential%20Logic.assets/image-20211122160146871.png)

**状态转换图**

为了用更加形象的方式直观地显示出时序电路的逻辑功能，可以进一步将状态转换表的内容表示成状态转换图的形式。

![image-20211122160645831](Sequential%20Logic.assets/image-20211122160645831.png)

![image-20211122160758224](Sequential%20Logic.assets/image-20211122160758224.png)

由于输出状态只与当前的状态有关，故也可以直接将输出状态标在状态图里。这是一个穆尔类型的电路，为了区分米利型和穆尔型，可以通过这种方式来

> 这个电路的作用：七进制计数器。日历盘中用的就是这个。

![image-20211122161229990](Sequential%20Logic.assets/image-20211122161229990.png)

在实验室中，要通过以上的时序图来辅助判断电路功能。

例:

![tmpA042](Sequential%20Logic.assets/tmpA042.png)

![image-20211122161827782](Sequential%20Logic.assets/image-20211122161827782.png)

**异步时序电路**

![image-20211122165729738](Sequential%20Logic.assets/image-20211122165729738.png)

![image-20211122165810389](Sequential%20Logic.assets/image-20211122165810389.png)

### 常用的时序逻辑电路

#### 移位寄存器

寄存器：用于寄存一组二值代码，N位寄存器由N个触发器组成，可存放一组N位二二值代码。

移位寄存器（Shift Register）除了具有存储代码的功能以外，还具有移位功能，所谓移位功能，是指寄存器里存储代码能在移位脉冲的作用下依次左移或右移。因此，移位寄存器不但可以用来寄存代码，还可以用来实现数据的串行-并行转换、数值的运算以及数据处理等。

![image-20211123114600578](Sequential%20Logic.assets/image-20211123114600578.png)

经过4个CLK信号之后，串行输入的4位代码全部移入了移位寄存器中，同时在4个触发器的输出端得到了并行输出的代码。因此，利用移位寄存器可以实现代码的串行-并行转换。

而如果首先将4位数据并行地置入移位寄存器地4个触发器中，然后连续加入4个移位脉冲，则移位寄存器里的4位代码将从串行输出端$D_0$依次送出，从而实现了数据的并行-串行转换。

> 这里用的是边沿触发器。
>
> 电平触发器是不可以的，因为如果电平触发的话，相当于一条路都被导通了。

JK触发器也可以构成移位寄存器：

![image-20211123115410358](Sequential%20Logic.assets/image-20211123115410358.png)

为了扩展逻辑功能和增加使用的灵活性，在定型生产的移位寄存器集成电路上有的又附加了左、右移控制、数据并行输入、保持、异步置零（复位）等功能。下图的74HC194A 4位双向移位寄存器就是一个典型的例子。

![image-20211123115552990](Sequential%20Logic.assets/image-20211123115552990.png)

![image-20211123120403448](Sequential%20Logic.assets/image-20211123120403448.png)

> $R_{D}^{\prime}$= 0 时，不管电路是什么状态，都会清零置回初态，这也是我们特别想要的功能。

![image-20211123115601566](Sequential%20Logic.assets/image-20211123115601566.png)

![image-20211123121206053](Sequential%20Logic.assets/image-20211123121206053.png)

#### 计数器

在数字系统中使用得最多的时序电路就是计数器。计数器不仅能用于对时钟脉冲计数，还可以用于分频、定时、产生节拍脉冲和脉冲序列以及进行数字运算等。

计数器的种类非常繁多，如果按计数器中的触发器是否同时翻转分类，可以将计数器分为同步式和异步式两种。在同步计数器中，当时钟脉冲输入时触发器的翻转是同时发生的。而在异步计数器中，触发器的翻转有先有后，不是同时发生的。

![image-20211124215623943](Sequential%20Logic.assets/image-20211124215623943.png)

**同步计数器**

同步二进制计数器

![image-20211124220029213](Sequential%20Logic.assets/image-20211124220029213.png)

> 计数器：利用翻转。而在触发器中，T触发器是最擅长翻转的。

![image-20211124220129973](Sequential%20Logic.assets/image-20211124220129973.png)

![image-20211124220323991](Sequential%20Logic.assets/image-20211124220323991.png)

![image-20211124221758449](Sequential%20Logic.assets/image-20211124221758449.png)

在实际生产的计数器芯片中，往往还附加了一些控制电路，以增加电路的功能使用得灵活性，下图为中规模集成的4位同步二进制计数器74161的逻辑图。这个电路除了二进制加法计数功能外，还具有预置数、保持和异步置零等附加功能。

图中 $L D^{\prime}$ 为预置数控制端, $D_{0} \sim D_{3}$ 为数据输入端, $C$ 为进位输出端, $R_{\mathrm{D}}^{\prime}$ 为异步置零 (复位) 端, $E P$ 和 $E T$ 为工作状态控 制端。

![image-20211124222238261](Sequential%20Logic.assets/image-20211124222238261.png)

![image-20211124222324315](Sequential%20Logic.assets/image-20211124222324315.png)

![image-20211124222333605](Sequential%20Logic.assets/image-20211124222333605.png)

![image-20211124222603883](Sequential%20Logic.assets/image-20211124222603883.png)

![image-20211124223412430](Sequential%20Logic.assets/image-20211124223412430.png)

![image-20211124223354044](Sequential%20Logic.assets/image-20211124223354044.png)

![image-20211124230457788](Sequential%20Logic.assets/image-20211124230457788.png)

上图为根据上式接成的同步二进制减法计数器电路，其中的T触发器是将JK触发器的J和K接在一起作为T输入端而得到的。

在有些应用场合要求计数器既能进行递增计数又能进行递减计数，这就需要做成加、减计数器（或称之为可逆计数器）。

将加法计数器和减法计数器的控制电路合并，再通过一根加、减控制线选择加法计数还是减法计数，就构成了加减计数器。

![image-20211124235219538](Sequential%20Logic.assets/image-20211124235219538.png)

当电路处在计数状态时（$S^{\prime}=0$、$L D^{\prime}=1$），各个触发器输入端的逻辑式为：
$$
\left\{\begin{array}{l}
T_{0}=1 \\
T_{1}=\left(U^{\prime} / D\right)^{\prime} Q_{0}+\left(U^{\prime} / D\right) Q_{0}^{\prime} \\
T_{2}=\left(U^{\prime} / D\right)^{\prime}\left(Q_{0} Q_{1}\right)+\left(U^{\prime} / D\right)\left(Q_{0}^{\prime} Q_{1}^{\prime}\right) \\
T_{3}=\left(U^{\prime} / D\right)^{\prime}\left(Q_{0} Q_{1} Q_{2}\right)+\left(U^{\prime} / D\right)\left(Q_{0}^{\prime} Q_{1}^{\prime} Q_{2}^{\prime}\right)
\end{array}\right.
$$
或写成：
$$
\left\{\begin{array}{l}
T_{i}=\left(U^{\prime} / D\right)^{\prime} \prod_{i=0}^{i-1} Q_{j}+\left(U^{\prime} / D\right) \prod_{j=0}^{i-1} Q_{j}^{\prime} \quad(i=1,2, \cdots, n-1) \\
T_{0}=1
\end{array}\right.
$$
![image-20211125111340689](Sequential%20Logic.assets/image-20211125111340689.png)

![image-20211125111424133](Sequential%20Logic.assets/image-20211125111424133.png)

由于电路中只有一个时钟信号（也就是计数输入脉冲）输入端，电路的加、减由某条控制路上的电平决定，所以称这种电路结构为单时钟结构。

倘若加法计数脉冲和减法计数脉冲来自两个不同的脉冲源，则需要对双时钟结构的加、减计数器计数。下图为双时钟加减计数器74LS103的结构图，这个电路采用的是控制时钟信号的结构形式，CMOS电路中的74HC193与74LS9193逻辑功能相同。

![image-20211125115325669](Sequential%20Logic.assets/image-20211125115325669.png)

![image-20211125115355629](Sequential%20Logic.assets/image-20211125115355629.png)

**同步十进制计数器**

![image-20211125115720184](Sequential%20Logic.assets/image-20211125115720184.png)

> 这是利用了T触发器的特性

从逻辑图上可写出电路的驱动方程为：
$$
\left\{\begin{array}{l}
T_{0}=1 \\
T_{1}=Q_{0} Q_{3}^{\prime} \\
T_{2}=Q_{0} Q_{1} \\
T_{3}=Q_{0} Q_{1} Q_{2}+Q_{0} Q_{3}
\end{array}\right.
$$
将上式代入T触发器的特性方程即可得到电路的状态方程：
$$
\left\{\begin{aligned}
Q_{0}^{*}=& Q_{0}^{\prime} \\
Q_{1}^{*}=& Q_{0} Q_{3}^{\prime} Q_{1}^{\prime}+\left(Q_{0} Q_{3}^{\prime}\right)^{\prime} Q_{1} \\
Q_{2}^{*}=& Q_{0} Q_{1} Q_{2}^{\prime}+\left(Q_{0} Q_{1}\right)^{\prime} Q_{2} \\
Q_{3}^{*}=&\left(Q_{0} Q_{1} Q_{2}+Q_{0} Q_{3}\right) Q_{3}^{\prime} \\
&+\left(Q_{0} Q_{1} Q_{2}+Q_{0} Q_{3}\right)^{\prime} Q_{3}
\end{aligned}\right.
$$
电路转换图如下：

![image-20211125120132515](Sequential%20Logic.assets/image-20211125120132515.png)

由状态转换图上可见，这个电路是能够自启动的。

![image-20211125120447490](Sequential%20Logic.assets/image-20211125120447490.png)

> 增加一个限制条件， 即“与”上一个限制条件。

![image-20211125120145628](Sequential%20Logic.assets/image-20211125120145628.png)

![image-20211125120211927](Sequential%20Logic.assets/image-20211125120211927.png)

![image-20211125120220154](Sequential%20Logic.assets/image-20211125120220154.png)

> 电路能够自启动：无效状态能够进入一个有效循环中。无效状态不会产生自己的循环而陷入一个死循环中。

![image-20211125120233906](Sequential%20Logic.assets/image-20211125120233906.png)

![image-20211125120246261](Sequential%20Logic.assets/image-20211125120246261.png)

**异步计数器**

异步二进制计数器：

![image-20211125122011427](Sequential%20Logic.assets/image-20211125122011427.png)

![image-20211125122041021](Sequential%20Logic.assets/image-20211125122041021.png)

![image-20211125122110268](Sequential%20Logic.assets/image-20211125122110268.png)

> 中间传输延迟时间中会出现各种编码，所以在高频大容量的情况下一般不会使用异步计数。

![image-20211125122120561](Sequential%20Logic.assets/image-20211125122120561.png)

**任意进制的计数器的构成方法**

![image-20211128174759225](Sequential%20Logic.assets/image-20211128174759225.png)

> 这种就是“预制件”的思路。

假设已有的是N进制计数器，而需要得到的是M进制计数器，此时有M<N和N<M两种可能的情况。

1. M<N的情况

   在N进制计数器的顺序计数中，若设法使之跳跃N-M个状态，就可以得到M进制的计数器了。

   实现跳跃的方法有置零法（或称复位法）和置数法（或称置位法）两种。

   ![image-20211128175223781](Sequential%20Logic.assets/image-20211128175223781.png)

   ![image-20211128175307614](Sequential%20Logic.assets/image-20211128175307614.png)

   ![image-20211128175348971](Sequential%20Logic.assets/image-20211128175348971.png)

   举例：

   ![image-20211128175833077](Sequential%20Logic.assets/image-20211128175833077.png)

   ![image-20211128180143970](Sequential%20Logic.assets/image-20211128180143970.png)

   ![image-20211128175900755](Sequential%20Logic.assets/image-20211128175900755.png)

   > 这个状态图是为了提醒，74160本来就是74161改装而来的，所以不要忘记周围还有一些状态。

   注意这里，把$Q_2$当成了进位信号，这样的话进位输出会持续三个信号宽度。这样有一些好处，首先是在做分频器的时候，进位输出信号的宽度增加了，而分频时更希望所有输出信号的占空比接近百分之五十。此外，如果下一级电路将下降沿认为是进位信号，则这个设计可以实现功能。

   ![image-20211128180056517](Sequential%20Logic.assets/image-20211128180056517.png)

   > 新加的这个电路可以说是一种展宽电路，依照下面信号的宽度展宽上边信号的宽度。
   >
   > 下面这部分设计是一个经典电路，在任何时刻想展宽信号宽度的时候都可以这样设计。

   ![image-20211128180407554](Sequential%20Logic.assets/image-20211128180407554.png)

   

   ![image-20211128180421871](Sequential%20Logic.assets/image-20211128180421871.png)

2. ![image-20211128182555593](Sequential%20Logic.assets/image-20211128182555593.png)

   ![image-20211128182756613](Sequential%20Logic.assets/image-20211128182756613.png)

   > 推荐使用并行进位法，而非串行进位法。注意两芯片中连着的反相器，这是为了将上升沿转化为下降沿，在1001的信号结束后第二片芯片再进位，否则会出现超前进位的现象，即“0 1 2 3 4 5 6 7 8 10 9”

   ![image-20211128182835322](Sequential%20Logic.assets/image-20211128182835322.png)

   

   ![image-20211128183736004](Sequential%20Logic.assets/image-20211128183736004.png)

   ![image-20211128183754738](Sequential%20Logic.assets/image-20211128183754738.png)

   

#### 移位寄存器型计数器

1. 环形计数器

   ![image-20211128184328907](Sequential%20Logic.assets/image-20211128184328907.png)

   ![image-20211128184407763](Sequential%20Logic.assets/image-20211128184407763.png)

   这种环形计数器的主要缺点是没有充分利用电路的状态。用n位移位寄存器组成的环形计数器只用了n个状态，而电路总共有$2^n$个状态，这显然是一种浪费。

2. 扭环形计数器

   ![image-20211128184921249](Sequential%20Logic.assets/image-20211128184921249.png)

   ![image-20211128184957546](Sequential%20Logic.assets/image-20211128184957546.png)

#### 顺序脉冲发生器

在一些数字系统中，有时需要系统按照事先规定的顺序进行一系列的操作，这就要求系统的控制部分能给出一组在时间上有一定先后顺序的脉冲信号，再用这组脉冲形成所需要的各种控制信号。顺序脉冲发生器就是用来产生这样一组顺序脉冲的电路。

![image-20211128185309898](Sequential%20Logic.assets/image-20211128185309898.png)

![image-20211128185825194](Sequential%20Logic.assets/image-20211128185825194.png)

![image-20211128185840288](Sequential%20Logic.assets/image-20211128185840288.png)

![image-20211128190401706](Sequential%20Logic.assets/image-20211128190401706.png)

![image-20211128190417875](Sequential%20Logic.assets/image-20211128190417875.png)

> 注意S1那里的选通脉冲，这个目的就是为了在组合电路的输入发生变化的时候不看输出脉冲，这样也就消除了竞争冒险现象。

![image-20211128190516962](Sequential%20Logic.assets/image-20211128190516962.png)

> 这相当于一个巡检扫描的过程。

#### 序列信号发生器

![image-20211128192617609](Sequential%20Logic.assets/image-20211128192617609.png)

![image-20211128193037208](Sequential%20Logic.assets/image-20211128193037208.png)

![image-20211128193044776](Sequential%20Logic.assets/image-20211128193044776.png)

## 时序逻辑电路的设计方法

### 同步时序逻辑电路的设计方法

首先讨论简单时序电路的设计。这里所说的简单时序电路，是指用一组状态方程、驱动方程和输出方程就能完全描述其逻辑功能的时序电路。

当选用小规模集成电路做设计时，电路最简的标准就是所用的触发器和门电路的数目最少。而且触发器和门电路的输入端数目也最少。而当使用中、大规模集成电路时，电路最简的标准则是使用的集成电路数目最少、种类最少，而且互相间的连线也最少。

1. 逻辑抽象，得出电路的状态转换图或者状态转换表。

2. 状态化简。状态化简得目的就在于将等价状态合并，以求得最简的状态转换图。电路得状态数越少，设计出来的电路就越简单

   等价状态：在同样的输入后有同样的输出和相同的次态

3. 状态分配。

4. 状态分配又称状态编码。

   ![image-20211128194425574](Sequential%20Logic.assets/image-20211128194425574.png)

5. 选定触发器的类型，求出电路的状态方程、驱动方程和输出方程。

6. 检查设计的电路能否自启动。

   如果电路不能自启动，则需要采取措施加以解决。一种解决方法是在电路开始工作时通过预置数将电路的状态置成有效措施状态循环中的某一种，另一种解决方法是通过修改逻辑设计加以解决。

举例：

![image-20211128200011856](Sequential%20Logic.assets/image-20211128200011856.png)

![image-20211128200018558](Sequential%20Logic.assets/image-20211128200018558.png)

![image-20211128200053862](Sequential%20Logic.assets/image-20211128200053862.png)

![image-20211128200040401](Sequential%20Logic.assets/image-20211128200040401.png)

> 注意排序上用了格雷码，应用了卡诺图。

![image-20211128200112346](Sequential%20Logic.assets/image-20211128200112346.png)

设计一个密码锁，当顺序输入3个或3个以上的“1”时，锁打开。（这个密码锁实质上是一个串行数据检测器，它的功能是：连续输入3个或3个以上的1时输出为1，其他输入情况下输出为0。

![image-20211128230128064](Sequential%20Logic.assets/image-20211128230128064.png)

![image-20211128230858052](Sequential%20Logic.assets/image-20211128230858052.png)

![image-20211128231521276](Sequential%20Logic.assets/image-20211128231521276.png)

![image-20211128231532116](Sequential%20Logic.assets/image-20211128231532116.png)

![image-20211128231541435](Sequential%20Logic.assets/image-20211128231541435.png)

> 注意最后一部分，要求在最后检查电路是否能够自启动。但是更明智的选择应该是在一开始就想好电路能否自启动，在逻辑设计的过程中确保无关态的下一步一定是有效循环中的一个状态。但是付出的代价是电路比较复杂，减小了化简的可能。但获得的收益是电路更加稳健。



## Finite State Machines

![img](Sequential%20Logic.assets/Slide03-16381159002021.png)

How many state bits do we need? Do we have to remember the last four input bits? In which case, we’d need four state bits. Or can we remember less information and still do our job? Aha! We don’t need the complete history of the last four inputs, we only need to know if the most recent entries represent some part of a partially-entered correct combination. In other words if the input sequence doesn’t represent a correct combination, we don’t need to keep track of exactly how it’s incorrect, we only need to know that is incorrect.

One of the interesting challenges in designing an FSM is to determine the required number of states since there’s often a tradeoff between the number of state bits and the complexity of the internal combinational logic required to compute the next state and outputs.

There are some number of inputs, used to convey all the external information necessary for the FSM to do its job. Again, there are interesting design tradeoffs. Suppose the FSM required 100 bits of input. Should we have 100 inputs and deliver the information all at once? Or should we have a single input and deliver the information as a 100-cycle sequence? In many real world situations where the sequential logic is much faster than whatever physical process we’re trying to control, we’ll often see the use of bit-serial inputs where the information arrives as a sequence, one bit at a time. That will allow us to use much less signaling hardware, at the cost of the time required to transmit the information sequentially.

![img](Sequential%20Logic.assets/Slide14-16381588549374.png)

The inputs to the FSM come from the ant’s two antennae, labeled L and R. An antenna input is 1 if the antenna is touching something, otherwise its 0. The outputs of the FSM control the ant’s motion. We can make it step forward by setting the F output to 1, and turn left or right by asserting the TL or TR outputs respectively. If the ant tries to both turn and step forward, the turn happens first. 

> 蚂蚁设计的思路：摸着墙走，即“不丢右墙”

![img](Sequential%20Logic.assets/Slide15-16381589196386.png)

![img](Sequential%20Logic.assets/Slide16.png)

So now the ant finds itself in one of these three situations. To implement the right-hand rule, the ant should turn left (counterclockwise) until it’s antennae have just cleared the wall. To do this, we’ll add a rotate-counterclockwise state, which asserts the turn-left output until both L and R are 0.

![img](Sequential%20Logic.assets/Slide17.png)

Now the ant is standing with a wall to its right and we can start the process of following the wall with its right antenna. So we have the ant step forward and right, assuming that it will immediately touch the wall again. The WALL1 state asserts both the turn-right and forward outputs, then checks the right antenna to see what to do next.

![img](Sequential%20Logic.assets/Slide18.png)

If the right antenna does touch, as expected, the ant turns left to free the antenna and then steps forward. The WALL2 state asserts both the turn-left and forward outputs, then checks the antennae. If the right antenna is still touching, it needs to continue turning. If the left antenna touches, it’s run into a corner and needs to reorient itself so the new wall is on its right, the situation we dealt with the rotate-counterclockwise state. Finally, if both antennae are free, the ant should be in the state of the previous slide: standing parallel to the wall, so we return the WALL1 state.

![img](Sequential%20Logic.assets/Slide19.png)

When the ant is in the WALL1 state, it moves forward and turns right, then checks its right antenna, expecting the find the wall its traveling along. But if its an outside corner, there’s no wall to touch! The correct strategy in this case is to keep turning right and stepping forward until the right antenna touches the wall that’s around the corner. The CORNER state implements this strategy, transitioning to the WALL2 state when the ant reaches the wall again.

![img](Sequential%20Logic.assets/Slide20-163815972541712.png)

Two states are equivalent if they meet the following two criteria. First, the states must have identical outputs. This makes sense: the outputs are visible to the outside, so if their values differed between the two states, that difference would clearly be externally distinguishable!

Second, for each combination of input values, the two states transition to equivalent states.

Okay, so let’s assume that WALL1 and CORNER are equivalent and ask if they transition to equivalent states for each applicable combination of input values. For these two states, all the transitions depend only on the value of the R input, so we just have to check two cases. If R is 0, both states transition to CORNER. If R is 1, both states transition to WALL2.

So both equivalence criteria are satisfied and we can conclude that the WALL1 and CORNER states are equivalent and can be merged.

> 没有必要要求外边指进来的箭头也保持一致！

![img](Sequential%20Logic.assets/Slide21.png)

![img](Sequential%20Logic.assets/Slide22.png)

![img](Sequential%20Logic.assets/Slide23.png)

Here’s the final table, where we’ve used don’t cares to reduce the number of rows for presentation. Next we want to come up with Boolean equations for each of the outputs of the combinational logic, *i.e.*, the two next-state bits and the three motion-control outputs.

Here are the Karnaugh maps for the two next-state bits. Using our K-map skills from Chapter 4, we’ll find a cover of the prime implicants for S1-prime and write down the corresponding product terms in a minimal sum-of-products equation. And then do the same for the other next-state bit.

We can follow a similar process to derive minimal sum-of-products expressions for the motion-control outputs.

![img](Sequential%20Logic.assets/Slide24.png)

### Turing Machines

有限状态机的问题：它是“有限”的，对于任何一个有限状态机，总能找到一个它不能处理的情况。有限状态机能够处理的情况是有限的，给出较多的状况可能无法处理。

解决这个问题的是图灵，“图灵机”。图灵机的解决思路是用存储的“无限”保证了状态的“有限”。

图灵机（英语：Turing machine），又称确定型图灵机，是英国数学家艾伦·图灵于1936年提出的一种将人的计算行为抽象化的数学逻辑机，其更抽象的意义为一种计算模型，可以看作等价于任何有限逻辑数学过程的终极强大逻辑机器。

图灵的基本思想是用机器来模拟人们用纸笔进行数学运算的过程，他把这样的过程看作下列两种简单的动作：

- 在纸上写上或擦除某个符号；
- 把注意力从纸的一处移动到另一处；

而在每个阶段，人要决定下一步的动作，依赖于（a）此人当前所关注的纸上某个位置的符号和（b）此人当前思维的状态。

为了模拟人的这种运算过程，图灵构造出一台假想的机器，该机器由以下几个部分组成：

1. 一条无限长的纸带**TAPE**。纸带被划分为一个接一个的小格子，每个格子上包含一个来自有限字母表的符号，字母表中有一个特殊的符号表示空白。纸带上的格子从左到右依次被编号为0, 1, 2, ...，纸带的右端可以无限伸展。
2. 一个读写头**HEAD**。它可以在纸带上左右移动，能读出当前所指的格子上的符号，并能改变它。
3. 一套控制规则TABLE。它根据当前机器所处的状态以及当前读写头所指的格子上的符号来确定读写头下一步的动作，并改变状态寄存器的值，令机器进入一个新的状态，按照以下顺序告知图灵机命令：
   - 写入（替换）或擦除当前符号；
   - 移动 **HEAD**， 'L'向左， 'R'向右或者'N'不移动；
   - 保持当前状态或者转到另一状态。
4. 一个**状态寄存器**。它用来保存图灵机当前所处的状态。图灵机的所有可能状态的数目是有限的，并且有一个特殊的状态，称为*停机状态*。

注意这个机器的每一部分都是有限的，但它有一个潜在的无限长的纸带，因此这种机器只是一个理想的设备。图灵认为这样的一台机器就能模拟人类所能进行的任何计算过程。

而冯诺依曼结构正是根据图灵机的设计出发的：

![image-20211129151120044](Sequential%20Logic.assets/image-20211129151120044.png)

所以能看出，数字电路是计算机的基础，同时也是计算机的限制。

### Asynchronous and Synchronous

![image-20211129143306589](Sequential%20Logic.assets/image-20211129143306589.png)

有些电路设计需要三个触发器，有些电路设计需要五个触发器，那么哪个的电路最高工作频率高？电路的最高工作频率是否和包含的触发器数量成反比？

答案是否定的。限制电路最高工作频率的是Clock的上升沿到来时，触发器中的数据应该准备好，所以限制电路最高工作频率的是驱动电路组合逻辑延迟时间最大的那个触发器，而与触发器的数量无关。

![image-20211129143840124](Sequential%20Logic.assets/image-20211129143840124.png)

$t_{PD}$与$t_{CD}$,指的是时钟信号对输出的影响；

$t_{SETUP}$与$t_{HOLD}$，指的是触发器输入信号“早来晚走”的要求。

![image-20211129144012052](Sequential%20Logic.assets/image-20211129144012052.png)

![image-20211129144257547](Sequential%20Logic.assets/image-20211129144257547.png)

$t_{pcq}$与$t_{setup}$已经固定下来了，在选定触发器后就确定了。能减少的是组合电路的$t_{PD}$。

![image-20211129145222140](Sequential%20Logic.assets/image-20211129145222140.png)

![image-20211129145702722](Sequential%20Logic.assets/image-20211129145702722.png)

![image-20211129145715050](Sequential%20Logic.assets/image-20211129145715050.png)

### Pipeline

![img](Sequential%20Logic.assets/Slide02-163817047757422.png)

Our laundry follows a simple path through the system: each load is first washed in the washer and afterwards moved to the dryer for drying. There can, of course, be delays between the steps of loading the washer, or moving wet, washed loads to the dryer, or in taking dried loads out of the dryer. Let’s assume we move the laundry through the system as fast as possible, moving loads to the next processing step as soon as we can.

![img](Sequential%20Logic.assets/Slide03-163817059362824.png)

![img](Sequential%20Logic.assets/Slide04-163817066522226.png)

But I hope you’re seeing the analogy we’re making between the Harvard approach to laundry and combinational circuits. We can all see that the washer is sitting idle while the dryer is running and that inefficiency has a cost in terms of the rate at which N load of laundry can move through the system.

![img](Sequential%20Logic.assets/Slide05.png)

As engineering students here in 6.004, we see that it makes sense to overlap washing and drying. So in step 1 we wash the first load. And in step 2, we dry the first load as before, but, in addition, we start washing the second load of laundry. We have to allocate 60 minutes for step 2 in order to give the dryer time to finish. There’s a slight inefficiency in that the washer finishes its work early, but with only one dryer, it’s the dryer that determines how quickly laundry moves through the system.

Systems that overlap the processing of a sequence of inputs are called pipelined systems and each of the processing steps is called a stage of the pipeline. The rate at which inputs move through the pipeline is determined by the slowest pipeline stage. Our laundry system is a 2-stage pipeline with a 60-minute processing time for each stage.

![img](Sequential%20Logic.assets/Slide06-163817160954029.png)

We see that there are two interesting performance metrics. The first is the latency of the system, the time it takes for the system to process a particular input. In the Harvard laundry system, it takes 90 minutes to wash and dry a load. In the 6.004 laundry, it takes 120 minutes to wash and dry a load, assuming that it’s not the first load.

The second performance measure is throughput（吞吐率）, the rate at which the system produces outputs. In many systems, we get one set of outputs for each set of inputs, and in such systems, the throughput also tells us the rate at inputs are consumed. In the Harvard laundry system, the throughput is 1 load of laundry every 90 minutes. In the 6.004 laundry, the throughput is 1 load of laundry every 60 minutes.

The Harvard laundry has lower latency, the 6.004 laundry has better throughput. Which is the better system? That depends on your goals! If you need to wash 100 loads of laundry, you’d prefer to use the system with higher throughput. If, on the other hand, you want clean underwear for your date in 90 minutes, you’re much more concerned about the latency.

The laundry example also illustrates a common tradeoff between latency and throughput. If we increase throughput by using pipelined processing, the latency usually increases since all pipeline stages must operate in lock-step and the rate of processing is thus determined by the slowest stage.

![img](Sequential%20Logic.assets/Slide07-163817165605931.png)

![img](Sequential%20Logic.assets/Slide08-163817171556233.png)

This will be our general plan for increasing the throughput of combinational logic: we’ll use registers to divide the processing into a sequence of stages, where the registers capture the outputs from one processing stage and hold them as inputs for the next processing stage. A particular input will progress through the system at the rate of one stage per clock cycle.

![img](Sequential%20Logic.assets/Slide09-163817185289435.png)

![img](Sequential%20Logic.assets/Slide10-163817191895537.png)

在流水线的动态设计中需要注意的一点就是，流水线的复杂程度并不会影响延迟时间，反而是最慢的那个模块影响了整个工作频率。

We’ll define a K-stage pipeline (or K-pipeline for short) as an acyclic circuit having exactly K registers on every path from input to output. An unpipelined combinational circuit is thus a 0-stage pipeline.

We’ll use the techniques we learned for analyzing the timing of sequential circuits to ensure the clock signal common to all the pipeline registers has a period sufficient to ensure correct operation of each stage. So for every register-to-register and input-to-register path, we need to compute the sum of the propagation delay of the input register, plus the propagation delay of the combinational logic, plus the setup time of the output register. Then we’ll choose the system’s clock period to be greater than or equal to the largest such sum.

With the correct clock period and exactly K-registers along each path from system input to system output, we are guaranteed that the K-pipeline will compute the same outputs as the original unpipelined combinational circuit.

The latency of a K-pipeline is K times the period of the system’s clock. And the throughput of a K-pipeline is the frequency of the system’s clock, *i.e.*, 1 over the clock period.

![img](Sequential%20Logic.assets/Slide11-163817199501539.png)

The top path through the A and C components has 2 registers. As does the bottom path through the B and C components. But the middle path through all three components has only 1 register. Oops, this not a well-formed K-pipeline.

Why do we care? We care because this pipelined circuit does not compute the same answer as the original unpipelined circuit. The problem is that successive generations of inputs get mixed together during processing. For example, during cycle i+1, the B module is computing with the current value of the X input but the previous value of the Y input.

This can’t happen with a well-formed K-pipeline. So we need to develop a technique for pipelining a circuit that guarantees the result will be well-formed.

![img](Sequential%20Logic.assets/Slide12-163817208417541.png)

> 在交叉点上加触发器，所有的触发器都是同步的。 

> Here’s our strategy that will ensure if we add a pipeline register along one path from system inputs to system outputs, we will add pipeline registers along every path.
>
> Now we can compute the system’s clock period by looking for the pipeline stage with the longest register-to-register or input-to-register propagation delay. With these contours and assuming ideal zero-delay pipeline registers, the system clock must have a period of 8 ns to accommodate the operation of the C module. This gives a system throughput of 1 output every 8 ns. Since we drew 3 contours, this is a 3-pipeline and the system latency is 3 times 8 ns or 24 ns total.
>
> 第一道线永远是画在输出端的，而既然pipelining methodology的目的是提高吞吐率，故当画线无法再提高吞吐率的时候就不再画线了。
>
> strategy： Focus your attention on placing pipelining registers around the slowest elements.

注意，遇到这类电路千万不要画有限状态机！要敏锐地注意到这是一个流水线设计！

优化流水线设计时，latency无法改变，能改变的只是吞吐率。latency只能通过创新工艺来优化。

![img](Sequential%20Logic.assets/Slide13.png)

这里0-pipe的意思就是不引进流水线设计时整个系统的延迟与吞吐率。1-pipe即为在输出那里引入流水线设计，而这里改变不了什么。第二条线应该将A与输入隔开，这正是我们strategy的要求，即focus on最慢的那一个。3-pipe是为了说明在画到无法提高吞吐率的时候就不用再画线了，如3-pipe展示的那样，增加了latency却无法提高吞吐率。

Notice that once we’ve isolated the slowest component, we can’t increase the throughput any further. How do we continue to improve the performance of circuits in light of these performance bottlenecks?

![img](Sequential%20Logic.assets/Slide14-16392306878632.png)

One solution is to use pipelined components if they’re available! Suppose we’re able to replace the original A component with a 2-stage pipelined version A-prime.

We can redraw our pipelining contours, making sure we account for the internal pipeline registers in the A-prime component. This means that 2 of our contours have to pass through the A-prime component, guaranteeing that we’ll add pipeline registers elsewhere in the system that will account for the two-cycle delay introduced by A-prime.

Now the maximum propagation delay in any stage is 1 ns, doubling the throughput from 1/2 to 1/1. This is a 4-pipeline so the latency will be 4 ns.

But what can we do if our bottleneck component doesn’t have a pipelined substitute？

![img](Sequential%20Logic.assets/Slide15-16392308080314.png)

And now here’s the take-home message from this example. Consider the operation of the two-dryer system. Even though the component dryers themselves aren’t pipelined, the two-dryer interleaving system is acting like a 2-stage pipeline with a clock period of 30 minutes and a latency of 60 minutes. In other words, by interleaving the operation of 2 unpipelined components we can achieve the effect of a 2-stage pipeline.

![img](Sequential%20Logic.assets/Slide16-16392311539896.png)

To improve the throughput further we either need to find a pipelined version of the C component or use an interleaving strategy to achieve the effect of a 2-stage pipeline using two instances of the unpipelined C component. Let’s try that...

![img](Sequential%20Logic.assets/Slide17-16392421516108.png)

Here’s a circuit for a general-purpose two-way interleaver, using, in this case, two copies of the unpipelined C component,$C_{0}$ and $C_{1}$。

The input for each C component comes from a D-latch, which has the job of capturing and holding the input value. There’s also a multiplexer to select which C-component output will be captured by the output register.

In the lower left-hand corner of the circuit is a very simple 2-state FSM with one state bit. The next-state logic is a single inverter, which causes the state to alternate between 0 and 1 on successive clock cycles. This timing diagram shows how the state bit changes right after each rising clock edge.

To help us understand the circuit, we’ll look at some signal waveforms to illustrate its operation.

> 可以这样理解Q：后边的数据选择器是为了选择输出哪个信号，而前面Q的作用是分发数据，且应该是数据选择器选择C2时给C1分发数据，反之亦然，所以要起到一个“相反”的作用。
>
> 一对多和多对一成了一个错开的乒乓机制。

![img](Sequential%20Logic.assets/Slide18-163924227574110.png)

To start, here are the waveforms for the CLK signal and our FSM state bit from the previous slide.

A new X input arrives from the previous stage just after the rising edge of the clock.

Next, let’s follow the operation of the $C_{0}$ component. Its input latch is open when FSM Q is low, so the newly arriving $X_{1}$  input passes through the latch and $C_{0}$ can begin its computation, producing its result at the end of clock cycle #2. Note that the $C_{0}$ input latch closes at the beginning of the second clock cycle, holding the $X_{1}$  input value stable even though the X input is starting to change. The effect is that $C_{0}$ has a valid and stable input for the better part of 2 clock cycles giving it enough time to compute its result.

The behavior of the interleaving circuit is like a 2-stage pipeline: the input value arriving in cycle i is processed over two clock cycles and the result output becomes available on cycle i+2.

What about the clock period for the interleaving system? Well, there is some time lost to the propagation delays of the upstream pipeline register that supplies the X input, the internal latches and multiplexer, and the setup time of the output register. So the clock cycle has to be just a little bit longer than half the propagation delay of the C module.

![img](Sequential%20Logic.assets/Slide19-163924313538212.png)

We can treat the interleaving circuit as a 2-stage pipeline, consuming an input value every clock cycle and producing a result two cycles later.

When incorporating an N-way interleaved component in our pipeline diagrams, we treat it just like a N-stage pipeline. So N of our pipelining contours have to pass through the component.

![img](Sequential%20Logic.assets/Slide20-163924329429714.png)

![img](Sequential%20Logic.assets/Slide21-163924344050416.png)

We’ve seen that even with slow components we can use interleaving and parallelism to continue to increase throughput. Is there an upper bound on the throughput we can achieve? Yes! The timing overhead of the pipeline registers and interleaving components will set a lower bound on the achievable clock period, thus setting an upper bound on the achievable throughput. Sorry, no infinite speed-up is possible in the real world.

![img](Sequential%20Logic.assets/Slide22-163924459606418.png)

This an elegant design based entirely on transition signaling. Each module is in complete control of when it consumes inputs and produces outputs, and so the system can process data at the fastest possible speed, rather than waiting for the worst-case processing delay.

![img](Sequential%20Logic.assets/Slide25.png)
