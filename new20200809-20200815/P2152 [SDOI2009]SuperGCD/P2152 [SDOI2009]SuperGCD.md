# P2152 [SDOI2009]SuperGCD

## 题目描述

Sheng bill 有着惊人的心算能力，甚至能用大脑计算出两个巨大的数的最大公约数！因此他经常和别人比赛计算最大公约数。有一天Sheng bill很嚣张地找到了你，并要求和你比赛，但是输给 Sheng bill 岂不是很丢脸！所以你决定写一个程序来教训他。

## 输入格式

共两行，第一行一个整数 a*a*，第二行一个整数 b*b*。

## 输出格式

一行，表示 a*a* 和 b*b* 的最大公约数。

## 数据范围

$ 0 < a,b \leq 10^{10000}$

## 分析：

显然，高精解决，~~但人生苦短，我选 Python​~~。

我们观察到 GCD 需要除法运算来取余，很麻烦，换个思路。

我们可以使用**二进制分解**GCD，这样只需要实现：

高精 $\times 2$ ,高精 $+$ 高精，高精 $\div 2$