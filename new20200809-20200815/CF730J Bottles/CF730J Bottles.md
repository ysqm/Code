# CF730J Bottles

## 题目描述

Nick has n*n* bottles of soda left after his birthday. Each bottle is described by two values: remaining amount of soda $a_{i}$ and bottle volume $b_i$ ($a_i \leq b_i$).

Nick has decided to pour all remaining soda into minimal number of bottles, moreover he has to do it as soon as possible. Nick spends x*x* seconds to pour x*x* units of soda from one bottle to another.

Nick asks you to help him to determine k — the minimal number of bottles to store all remaining soda and t — the minimal time to pour soda into k*k* bottles. A bottle can't store more soda than its volume. All remaining soda should be saved.

## 输入格式

The first line contains positive integer n ( $1\leq n \leq 100$ ) — the number of bottles.

The second line contains n positive integers $a_{1},a_{2},...,a_{i}$ $1\leq a_i \leq100$ , where $a_{i}$ is the amount of soda remaining in the $i$-th bottle.

The third line contains n*n* positive integers $b_{1},b_{2},...,b_{i}$ $1\leq b_i \leq100$, where $b_{i}$ is the volume of the $i$ -th bottle.

It is guaranteed that $a_i \leq b_i$ for any $i$ .

# 翻译：

## 题目描述

有 $n$ 瓶水，第 $i$ 瓶水的水量为 $a_i$，容量为 $b_i$ 将 $1$ 单位水从一个瓶子转移到另一个瓶子所消耗时间为 $1$ 秒，且可以进行无限次转移。求储存所有水所需最小瓶子数 $k$ 以及该情况下所用最小时间 $t$ 。 

## 输入格式

第一行输入一个正整数 $n$ （$1\le n\le 100$）。 

第二行输入 $n$ 个正整数，第 $i$ 个正整数表示 $a_i$ （$1\le a_i \le 100$）。 

第三行输入 $n$ 个正整数，第 $i$ 个正整数表示 $b_i$ （$1\le b_i \le100$）。 

对于每一个 $i$，满足$a_i\le b_i$。

## 输出格式

输出一行两个整数：$k$ 和 $t$。

## 分析：

~~显然~~，第一问直接贪心，但第二问就有些难度。

第二问考虑 DP ，题目中若只是求 t 或 k 都可以直接套背包模板，但是它有两个费用。

这里看起来很难，但其实还是可以生搬硬套模板的。

首先我们分析一点，即对于最优的方案它一定**可以**满足一个性质：

即前 $k-1$ 个瓶子的水是装满的，最后一个瓶子可能装满也可以不装满。

由此我们可以得到一个动态规划的方程。

我们记 $f[i],g[i]$ 数组分别为在总装水量为 $i$ 时的最小瓶子数与最小时间。

转移方程不好用一个式子写出来。

先将 $f$ 初始化为 $n$。

只有当 $f[j-b[i]]+1\geq f[j]$ 时我们才会有转移，转移分为两种情况：

- $f[j-b[i]]+1 = f[j]$

$$\large g[j] = Min(g[j],g[j-b[i]]+b[i]-a[i])$$

- $f[j-b[i]]+1 > f[j]$

$$\large f[j] = f[j-b[i]]+1,g[j]=f[j-b[i]]+b[i]-a[i]$$
