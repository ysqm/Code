## 题目

### 题目描述

你面临 $n$ 名参赛者的挑战，最终要将他们全部战胜。

每一轮中，都会淘汰一些选手；你会得到这一轮奖金池中 被淘汰者 除以 这一轮对手总数 比例的奖金。

例如某一轮有 $10$ 个对手，淘汰了 $3$ 个，那么你将获得奖金池中 $\frac{3}{10}$ 的奖金。

假设每一轮的奖金池均为一元，Mirko 希望通过恰好 k 轮赢得比赛，那么他最多可能获得多少奖金呢？

你只需要输出答案保留 $9$ 位小数即可。

### 输入格式

一行两个正整数 $n,k$。

### 输出格式

输出一行一个实数表示答案。

## Solution:

讲一下思路过程：

看题面，考虑到参赛者位置不影响答案，可以将每一轮删除的人连起来，这样本题就和石子合并有点像，可以快速写出一个 $\mathcal{O}(n^2k)$ 的 $DP$ 方程：

$dp[k][j]$ 表示第 $k$ 轮还剩 $j$ 个人的最大收益。

$$dp[k][j] = Max(dp[k-1][i]+\frac{i-j}{i}),i > j$$

但是显然这个方程 $\mathcal{O}(n^2k)$ 的方程时间复杂度过大，考虑优化。

### 第一步优化

对于 $dp[k-1][i]+\frac{i-j}{i}$ 这样的形似 $dp[i]+W_i$ 的方程我们一般都会考虑单调队列优化或斜率优化，$W_i = \frac{i-j}{i}$ 是有形如 $ij$ 的式子,故使用斜率优化。

考虑两个决策点 $j_1,j_2$ 满足 $j_1$ 优于 $j_2$:

$$dp[k][j_1]+\frac{j_1-i}{j_1} \geqslant dp[k][j_2]+\frac{j_2-i}{j_2}$$

整理得到: $\frac{dp[k][j_1]-dp[k][j_2]}{j_1-j_2}\geqslant\frac{i}{j_1j_2}$ 发现 $j_1j_2$ 不方便处理。

走到这一步之后就需要较灵活的思维。

$j$ 是我们需要枚举的决策点，当使用它作为分母时就会产生上面的问题，考虑将 $j$ 换到分子上去。

不难发现**由于每一轮奖池不变，所以第 $k-1$ 轮对第 $k$ 轮并没有因为先后顺序产生的影响。**

故我们可以逆序处理。

**即一开始没有任何参赛者，每一轮往里面加参赛者。**

由此有新的 $DP$ 状态:

$dp[k][i]$ 表示第 $k$ 轮有 $i$ 名参赛者。

$$dp[k][i] = Max(dp[k-1][j]+\frac{i-j}{i}),i>j$$

斜率优化：

考虑两个决策点 $j_1,j_2$ 满足 $j_1$ 优于 $j_2$:

$$dp[k][j_1]+\frac{i-j_1}{i} \geqslant dp[k][j_2]+\frac{i-j_2}{i}$$

$$\frac{dp[k][j_1]-dp[k][j_2]}{j_1-j_2}\geqslant\frac{1}{i}$$

当然此时我们可以做到 $\mathcal{O}(nk\log{n})$。

$n \leqslant 3000$ 的数据有点勉强。

考虑到斜率优化的瓶颈在于二分凸包上，进一步优化：

~~打表发现转移具有单调性。~~

所以斜率优化可以做到 $\mathcal{O}(nk)$。

但是对于本题来说还是不够。

### 进一步优化，
**对于强制选 $k$ 个，可以使用 $wqs$ 二分优化掉第一维。**

此时仍可以使用斜率优化，原 $DP$ 方程化作：

$$dp[i] = Max(dp[j]+\frac{i-j}{i}),i>j$$

用 $lst[i]$ 记录分了几段。

二分每一段则需要的代价 $mid$。

最终答案是 $dp[n]+mid*K$(注意精度)。

最终复杂度 $\mathcal{O}(nlogk)$。

不过本题精度卡的有点紧,需要~~耗子尾汁~~才能一次过。

## Code:

~~~c++
# include <queue>
# include <cmath>
# include <cstring>
# include <cstdio>
# include <algorithm>
# define eps 1e-12

inline int Read()
{
    register int x = 0;char ch = getchar();
    
    while(ch < '0' || ch > '9')ch = getchar();
    
    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = getchar();}
    
    return x;
}

const int N = 1e5;

double dp[N+5];
int lst[N+5],q[N+5],h,t,n,k;

# define Spole(x,y) ((dp[x]-dp[y])/(x-y))

bool Solve(const double mid)
{
    q[t = h = 1] = 0;lst[0] = 0;
    for(int i = 1; i <= n ; ++i)
    {
        //while(h < t && (dp[q[h+1]]-q[h] == 0 || (dp[q[h+1]]-q[h])*i > q[h+1]-q[h])) ++h;
        //while(h < t && (dp[q[h+1]]-dp[q[h]])*i < (q[h+1]-q[h])) ++h;
        while(h < t && Spole(q[h+1],q[h]) - 1.0/i > eps) ++h;
        dp[i] = dp[q[h]]+(i-(double)q[h])/i-mid;
        lst[i] = lst[q[h]]+1;//无限次试图拆开斜率的式子避开精度问题，却都没成功。
        while(h < t && Spole(i,q[t])-Spole(q[t],q[t-1]) > eps) --t;
        //while(h < t && (dp[i]-dp[q[t]])*(q[t]-q[t-1]) < (dp[q[t]-q[t-1]])*(i-q[t])) --t;
        q[++t] = i;
    }
    return lst[n] >= k;
}

int main()
{
    scanf("%d%d",&n,&k);
    double l = 0,r = 1,mid;
    for(int i = 1; i <= 100 ; ++i)
    {
        mid = (l+r)/2;
        if(Solve(mid)) l = mid;
        else r = mid;
    }
    printf("%.9lf",dp[n]+k*mid);
    return 0;
}
~~~
