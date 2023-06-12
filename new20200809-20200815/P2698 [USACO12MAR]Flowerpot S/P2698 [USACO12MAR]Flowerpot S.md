# P2698 [USACO12MAR]Flowerpot S

Farmer John has been having trouble making his plants grow, and needs your help to water them properly. You are given the locations of N raindrops ($ 1  <= N <= 10^5$) in the 2D plane, where y represents vertical height of the drop, and x represents its location over a 1D number line:

![img](https://cdn.luogu.com.cn/upload/pic/9174.png)

Each drop falls downward (towards the x axis) at a rate of 1 unit per second. You would like to place Farmer John's flowerpot of width W somewhere along the x axis so that the difference in time between the first raindrop to hit the flowerpot and the last raindrop to hit the flowerpot is at least some amount D (so that the flowers in the pot receive plenty of water). A drop of water that lands just on the edge of the flowerpot counts as hitting the flowerpot.

Given the value of D and the locations of the N raindrops, please compute the minimum possible value of W.

老板需要你帮忙浇花。给出 N 滴水的坐标，y 表示水滴的高度，x 表示它下落到 x 轴的位置。

每滴水以每秒 1 个单位长度的速度下落。你需要把花盆放在 x 轴上的某个位置，使得从被花盆接着的第1 滴水开始，到被花盆接着的最后1滴水结束，之间的时间差至少为D。

我们认为，只要水滴落到 x 轴上，与花盆的边沿对齐，就认为被接住。给出N滴水的坐标和 D 的大小，请算出最小的花盆的宽度 W。

## 输入格式

第一行2个整数 N 和 D。

第 $2\cdots N+1$ 行每行 2 个整数，表示水滴的坐标 $(x,y)$。

## 输出格式

仅一行1个整数，表示最小的花盆的宽度。如果无法构造出足够宽的花盆，使得在D单位的时间接住满足要求的水滴，则输出-1。

## 数据范围

$1 \leq N \leq 10^5,1 \leq D \leq 10^6,0 \leq x,y \leq 10^6$

## 分析：

看起来很难，其实仔细想一下，就是单调队列的模板，我们将水滴按高度排序，以 x 跑两个单调队列记录最大最小值，若是队首队尾时间之差达到了 $D$,我们便找到了一个可能答案。