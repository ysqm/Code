## 题目分析：

首先是一个线性 DP,这一点很重要，如果想成了单调队列优化的神仙区间 DP，那就没救了。

考虑一般情况，如果不是在环上的话，DP 状态是很明显的：

首先一定要记录目前的答案是到哪为止的。

其次，必然会记录当前点是否在卖萌。

最后，必不可少的已经卖萌了了多长的时间。

综上状态便是一个三维数组 $dp[N][B][2]$。

第一维记录处理到那个点，第二维纪录已卖萌的时间，第三位就是是否在卖萌。

dp 状态出来了,转移方程也就比较显然:
$$dp[i][j][x]=
\begin{cases}
&max\left(dp[i-1][j][0],dp[i-1][j][1])\right) &x = 0\\
&max\left(dp[i-1][j-1][0],dp[i-1][j-1][1]+a[j])\right)&x = 1\\   
\end{cases}$$

观察到每一层状态只会从上一层转移，故可以使用滚动数组来进一步优化空间。

接下来回到原问题,考虑处理环上问题的办法：
- 倍长
- 强制链接

仔细考虑发现倍长并不好处理，由转移的一些问题导致很难统计答案。

故使用强制链接。

做完上面序列上的 DP 后，强制选择 1 号点卖萌，再 DP 一次，但注意，此时统计的答案就只能是 $dp[n][B][1]$。































Code:
~~~c++
\\ Code by 云岁月书
# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define N 3830
# define max std::max

inline int Read()
{
    register int x = 0;char ch = getchar();

    while(ch < '0' || ch > '9')ch = getchar();

    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = getchar();}

    return x;
}

inline int Max(const int x,const int y){return x > y ? x : y;}
inline int Min(const int x,const int y){return x < y ? x : y;}

int n,m,f[2][N+5][2],a[N+5],ans;

void DP()
{
    for(int i = 2; i <= n ; ++i)
	{
		f[i&1][0][0] = f[(i^1)&1][0][0];
		for(int j = 1; j <= m ; ++j)
        {
            f[i&1][j][0] = max(f[(i^1)&1][j][0],f[(i^1)&1][j][1]);
            f[i&1][j][1] = max(f[(i^1)&1][j-1][0],f[(i^1)&1][j-1][1]+a[i]);
        }
	}
}

int main()
{
    n = Read();m = Read();
    for(int i = 1; i <= n ; ++i) a[i] = Read();
    if(m == 0) return printf("0\n"),0;
    memset(f,-0x3f,sizeof(f));
    f[1][0][0] = f[1][1][1] = 0;//注意一下初始状态的处理
    DP();
    ans = max(f[n&1][m][0],f[n&1][m][1]);
    memset(f,-0x3f,sizeof(f));
    f[1][1][1] = a[1];
    DP();
    ans = max(ans,f[n&1][m][1]);
    printf("%d\n",ans);
    return 0;
}
~~~