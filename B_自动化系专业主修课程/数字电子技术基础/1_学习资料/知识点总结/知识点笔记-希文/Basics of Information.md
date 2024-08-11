## 信息

![img](Basics%20of%20Information.assets/Slide02.png)

![img](Basics%20of%20Information.assets/Slide03-16356632224423.png)

We use the $\log _{2}$ to measure the magnitude of the uncertainty in bits where a bit is a quantity that can take on the value 0 or 1. Think of the information content as the number of bits we would require to encode this choice.

![img](Basics%20of%20Information.assets/Slide04.png)

Consider what information we get from rolling two dice, one red and one green. Each die has six faces, so there are 36 possible combinations. Once we learn the exact outcome of the roll, we’ve received $\log _{2}(36 / 1)=5.17$ bits of information.

What do those fractional bits mean? Our digital system only deals in whole bits! So to encode a single outcome, we’d need to use 6 bits. But suppose we wanted to record the outcome of 10 successive rolls. At 6 bits/roll we would need a total of 60 bits. What this formula is telling us is that we would need not 60 bits, but only 52 bits to unambiguously encode the results. Whether we can come up with an encoding that achieves this lower bound is an interesting question that we’ll take up later in this chapter.

We need a way to evaluate the efficacy of an encoding. The entropy, $H(X)$, of a discrete random variable $X$ is average amount of information received when learning the value of $X$ :
$$
H(X)=E(I(X))=\sum_{i} p_{i} \log _{2} \frac{1}{p_{i}}
$$
![img](Basics%20of%20Information.assets/Slide08.png)

The entropy is a lower bound on the number of bits we need to transmit.

### 编码

An *encoding* is an unambiguous mapping between bit strings and the members of the set of data to be encoded.

![img](Basics%20of%20Information.assets/Slide10.png)

![img](Basics%20of%20Information.assets/Slide11.png)

Let’s look at some simple examples. In binary-coded decimal, each digit of a decimal number is encoded separately. Since there are 10 different decimal digits, we’ll need to use a 4-bit code to represent the 10 possible choices. The associated entropy is $\log _{2}(10)$, which is 3.322 bits. We can see that our chosen encoding is inefficient in the sense that we’d use more than the minimum number of bits necessary to encode, say, a number with 1000 decimal digits: our encoding would use 4000 bits, although the entropy suggests we *might* be able to find a shorter encoding, say, 3400 bits, for messages of length 1000.

编码：

- 物理层面：矩形波
- 数学层面：0和1

编码的目的：处理信息。

### 数制和码制

数制：表示数量的规则。关心：每一位的构成、从低位向高位的进位规则。

码制：表示事物的规则。即用不同数码表示不同事物时遵循的规则

目前，数字电路中都采用二进制，它在表示数量时称二进制，在表示事物时称二值逻辑。

十进制、二进制转换：

![image-20211031144348073](Basics%20of%20Information.assets/image-20211031144348073.png)

![image-20211031144458248](Basics%20of%20Information.assets/image-20211031144458248.png)

二、十六转换

![image-20211031144609184](Basics%20of%20Information.assets/image-20211031144609184.png)

> 注意：如果不足4位的话要用0补足位数！

二进制算术运算的特点：

![image-20211031145028590](Basics%20of%20Information.assets/image-20211031145028590.png)

> 核心:移位和相加。

### 原码、反码、补码



MSB、LSB:

Most significant bit(byte):最高位

Lease significant bit(byte): 最低位

![img](Basics%20of%20Information.assets/Slide12.png)

![img](Basics%20of%20Information.assets/Slide13.png)

 To prevent any confusion, we’ll use a special prefix “0x” to indicate when a number is being shown in hex, so we’d write “0x7D0” as the hex representation for the binary number “0111 1101 0000.” This notation convention is used by many programming languages for entering binary bit strings.

![img](Basics%20of%20Information.assets/Slide14.png)

但是这种表示方法在正负加法上就出现了问题：

![image-20211031153016853](Basics%20of%20Information.assets/image-20211031153016853.png)

![image-20211031153053020](Basics%20of%20Information.assets/image-20211031153053020.png)

![img](Basics%20of%20Information.assets/Slide15.png)

![image-20211031153210789](Basics%20of%20Information.assets/image-20211031153210789.png)

![image-20211031153307944](Basics%20of%20Information.assets/image-20211031153307944.png)

> 注意这里的表示：有效数字是不包括符号位的！

补码设计的思路：如果要做减法，那么就加上一个数，让结果超过这段数轴能表示的最大的数，这样就不得不从0开始重新计算。也就是说，每当要减去一个数，就要想办法找到应该加上的那个数。比如说模长是1000，那么减去200就可以变成加上800，减去300就可以变成加上700。他发现要减去的数和要加上的数有一种关系，就是他们的和总是1000，这有点像几何里面的补角的概念，所以他就给这两种数分别取了一个名字，要减去的数叫原码，要加上的数叫补码。如果想要减去200，那么要加上的800就是200的补码，如果想减300，那么要加上的700就是300的补码。根据补码的求法可以发现补码是和模的取值有很大关系。

**模是一个具有周期性的计数系统的最小正周期**。

由此可知，“**最高位为符号位的8位二进制有符号整数的模”**为0111 1111B + 1B = 1000 0000B，即127+1=128。
10 - 2
=00001010B **- 00000010B**
=00001010B **+(128 - 00000010B)**

=00001010B **+(1000 0000B - 00000010B)**

=00001010B **+0111 1110B**
=1000 1000B

而这个比最大的128 = 1000 0000B还要大，说明走过了这个周期。

拿十进制来举例：截取了一段0-999的数轴，从0到999一共有1000个整数，所以就称这段数轴的模长为1000。如果要做减法，那么就加上一个数，让结果超过这段数轴能表示的最大的数，这样就不得不从0开始重新计算。

694-246=448

那么用补码运算法就应该先寻找要减去的这个数的补码，补码为：

1000-246=754

把减去246转成加上246的补码：

694+754=1448

因为超过了最大能表示的数999，所以取余数：

1448-1000=448

这是比较基础的理解，但是会出现问题：如果不知道正确答案仅仅得到计算的答案400，它到底是400的原码，还是-600的补码呢？换句话说，-600的补码是400，而400不一定是-600的补码，他可能是400本身的原码。

这是一个无法忽视的问题。求补的方式是我们自己定义的，如果要改变求补的方式就要把之前的工作全部推倒重来，否则就必须找到一种能够区分正负数的办法。为了不让之前的努力变为沉没成本，他决定继续往前走。

人们在数字前面加上一个+表示正数，加上一个-表示负数，本质上只是一种区分用的符号，是人为规定的。只要我们愿意的话，也可以自己规定在数字前面加-表示正数，加+表示负数。对于只认死理计算机来说，除了0和1以外一概不认。同样非此即彼的特性倒是有几分相似之处，于是他萌生了用数字表示符号位的念头。

我们规定每个二进制数的第一位为符号位，0为正数1为负数。而后面的所有位都是数值位，和原来的表示方法一样。这样的话我们无论看到什么数都先检查它的第一位确定它的符号，这样就知道该如何解读它。

我们来实验一下以确定这种方法是否正确：

200-100=100

转换成补码运算：

200+900=1100
1100-1000=100

结果超过了模，所以需要进行求余运算。而减数变大会怎么样呢？

200-300=-100

换成补码运算：

200+700=900

结果没有超过模，所以不需要进行求余运算。于是我们得出了一个结论，当减法的结果为正数，计算过程会发生溢出，并且答案就是原码本身。当结果为负数，则不会发生溢出，但是我们只能得到答案的补码，需要进行求补运算才能得到正确答案。这个特性非常重要，对证明符号位即使参与运算也不会产生错误结果有很大帮助。

正数加正数的情况是这样的：

0xxxxxxx+0xxxxxxx=0xxxxxxx

两个符号位都是0，相加之后仍为0。但是要警惕的一种情况就是数值运算的结果溢出产生进位到符号位改变符号位。这种情况的解决办法就是扩增位数使得进位无法传到符号位，将符号位“保护”起来。

如果一个正数减另一个正数答案也是正数的话是这种形式：

0xxxxxxx-0xxxxxxx=0xxxxxxx即
0xxxxxxx+1xxxxxxx=0xxxxxxx

因为答案是正数，所以后面数值位的运算会发生溢出（前面提到的特性）。不过这里的溢出不会再因为模长有限而消失，而是传到了符号位。符号位的运算结果为1，加上数值位的进位变成了10，但是符号位本已经是最高位，它的进位便消失了只剩下0。符号位便“阴差阳错”地得到了正确的结果。

一个正数减另一个正数为负数的情况呢？它的形式是这样的：

0xxxxxxx-0xxxxxxx=1xxxxxxx即
0xxxxxxx+1xxxxxxx=1xxxxxxx

因为结果为负数，所以不会产生溢出，那么数值位的运算结果也不会产生到符号位的进位。符号位运算的结果也刚好符合我们假设的情况。

最后一种情况是负数减正数：

1xxxxxxx-0xxxxxxx=1xxxxxxx即
1xxxxxxx+1xxxxxxx=1xxxxxxx

这样的情况两个加数的符号位都是1，他们的和应该是10去掉进位也就是0，也就是说计算的结果是正数，但是负数加负数是不可能为正数的，所以这种情况要讨论。两个负数相加，如果结果不会溢出，这说明他们的补码之和一定会溢出，产生进位到符号位，使符号位变回1。如果两个负数和会溢出，那么他们的补码之和就不会溢出，无法产生进位纠正符号位的错误。这时候就得再次用到扩增位数的方法，保证他们的和不会溢出而补码和会溢出。

到此为止我们终于解决了补码的运算问题，总结一下的话就是：

1.所有的数都以补码的形式保存，正数的补码是它自身，负数的补码为绝对值取反加一。

2.每一个数前面都要加上一个符号位，0表示正数，1表示负数。

3.减去一个数可以转换成加上求补之后的减数。

tip1：补码和求补是两回事，补码表示的是一种存储数据的方法，而求补是一种运算，千万不能弄混。

tip2：对于计算机来说，加上一个正数和减去一个负数的运算原理不同。前一种情况可以直接相加，而后一种情况需要对减数进行求补然后相加，多了一个运算步骤。

![img](Basics%20of%20Information.assets/Slide16.png)

To compute B - A, we can just use addition and compute B + (-A). So now we just need to figure out the two’s complement representation for -A, given the two’s complement representation for A. Well, we know that A + (-A) = 0 and using the example above, we can rewrite 0 as 1 + (-1). Reorganizing terms, we see that -A equals 1 plus the quantity (-1) - A. As we saw above, the two’s complement representation for -1 is all 1-bits, so we can write that subtraction as all 1’s minus the individual bits of A: $A_{0}, A_{1}, \ldots$ up to $A_{N-1}$. If a particular bit $A_{i}$ is 0 , then $1-A_{i}=1$ and if $A_{i}$ is 1 , then $1-A_{i}=0$. So in each column, the result is the bitwise complement of $A_{i}$, which we'll write using the C-language bitwise complement operator tilde. So we see that -A equals the bitwise complement of A plus 1 . 

注意：在两个同符号数相加时，它们的绝对值之和不能超过有效数字位所能表示的最大值，否则会得出错误的计算结果

![image-20211031153617659](Basics%20of%20Information.assets/image-20211031153617659.png)

![image-20211031154148618](Basics%20of%20Information.assets/image-20211031154148618.png)

![image-20211031154225514](Basics%20of%20Information.assets/image-20211031154225514.png)

![image-20211031154313331](Basics%20of%20Information.assets/image-20211031154313331.png)

![image-20211031154414586](Basics%20of%20Information.assets/image-20211031154414586.png)

![image-20211031154427530](Basics%20of%20Information.assets/image-20211031154427530.png)

![image-20211031154601530](Basics%20of%20Information.assets/image-20211031154601530.png)

![image-20211031154615157](Basics%20of%20Information.assets/image-20211031154615157.png)

> 注意在转换成补码时取反加一的算法依然可以延续，但是要注意加1是加在了最后一位，而不是$2^{0}$那一位。

补码再变成原码：取反再加一，相当于又走了一个周期。

### 定长编码与变长编码

![image-20211031154811536](Basics%20of%20Information.assets/image-20211031154811536.png)

![image-20211031154931988](Basics%20of%20Information.assets/image-20211031154931988.png)

> 历史上出现过很多编码形式。

![image-20211031155052364](Basics%20of%20Information.assets/image-20211031155052364.png)

![img](Basics%20of%20Information.assets/Slide17.png)

So we’ll be constructing encodings where the $x_{i}$ may have different length codes — we call these variable-length encodings.

![img](Basics%20of%20Information.assets/Slide19.png)

Given a set of symbols and their probabilities, Huffman’s Algorithm tells us how to construct an optimal variable-length encoding. By “optimal” we mean that, assuming we’re encoding each symbol one-at-a-time, no other variable-length code will have a shorter expected length.

![img](Basics%20of%20Information.assets/Slide20.png)

![img](Basics%20of%20Information.assets/Slide21.png)

![img](Basics%20of%20Information.assets/Slide22.png)

To help with our discussion, we’ll introduce the notion of *Hamming distance*, defined as the number of positions in which the corresponding digits differ in two encodings of the same length. For example, here are two 7-bit encodings, which differ in their third and fifth positions, so the Hamming distance between the encodings is 2. If someone tells us the Hamming distance of two encodings is 0, then the two encodings are identical. Hamming distance is a handy tool for measuring how to encodings differ.

![img](Basics%20of%20Information.assets/Slide23.png)

The real issue here is that when Alice receives a 1, she can’t distinguish between an uncorrupted encoding of tails and a corrupted encoding of heads — she can’t detect that an error occurred. Let’s figure how to solve her problem!

![img](Basics%20of%20Information.assets/Slide24.png)

![img](Basics%20of%20Information.assets/Slide25.png)

![img](Basics%20of%20Information.assets/Slide26.png)

![img](Basics%20of%20Information.assets/Slide27.png)

