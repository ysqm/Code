# CF145E Lucky Queries

## 问题描述
给你 $n$ 个数，每个数是 $4$ 或者 $7$ ，给你 $m$ 个任务完成

$switch$ $l\ r$ 把 $[l,r]$ 位置的 $4$ 换成 $7$ , $7$ 换成 $4$

$count$ 计算 $n$ 个数的最长不下降子序列的长度

$N$ 个数的不下降子序列是这 $n$ 个数移除掉 $0$ 个或者若干个位置的数，并且满足从第 $2$ 个数开始每一个数不小于前一个数的大小。

## 输入格式
第一行 $n，m$

第二行 $n$ 个数字

接下来 $m$ 行每行一个命令

## 输出格式
对于每一个 $count$ 的命令，输出 $n$ 个数的最长不下降子序的长度

## 数据范围：

$1 \leq n \leq 10^6,1\leq m \leq 3\times 10^5$

## 分析：

很套路的板子，维护最长不上升子序列和最长不下降序列就可以了。