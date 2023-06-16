### 题目大意

#### 求解

$$\Large \sum\limits_{i=1}^{n}\sum\limits_{j=1}^{n} \gcd(i,j)$$

#### 分析：

$$\Large\begin{aligned}\sum\limits_{i=1}^{n}\sum\limits_{j=1}^{n} \gcd(i,j) &= \frac{n\cdot(n+1)}{2}+2\cdot\sum\limits_{i=1}^{n}\sum\limits_{j=1}^{j<i}gcd(i,j)\\&=\frac{n\cdot(n+1)}{2}+2\cdot\sum\limits_{d|n}d\cdot\varphi(\frac{n}{d})\end{aligned}$$