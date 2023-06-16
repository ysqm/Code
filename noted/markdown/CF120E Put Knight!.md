题目并不难。

首推打表大法，分分钟秒了这道题。

严谨点的话，这道题是个显然的博弈题。

但是我不会博弈论，所以下面的讨论可能并不博弈论。

首先有一个并不那么显然的结论：

在棋盘上放第一个骑士，那么若存在与之中心对称的位置，则那个位置必然可放下一个骑士且不会被第一个骑士攻击到。

扩展一下也不难得到本题思路:

若此前双方共放了 $2x$ 个骑士，且每一对敌对骑士都是中心对称的。

接下来若第一个人放了一个可以放位置，则与这个位置中心对称的位置也一定是可放的的(这个应该不难理解)！

综上在这种情况下，不难发现第二个人只需每一次下与第一个人上一次下的位置中心对称的位置就可以一直放下去。

也即此时先手必败。

对于 $n = 2k+1,k \in \N$，也即不存在一个位置与自己中心对称的情况下，可以第一步下载那个中心的位置，此时相当于第二人变成了先手。

此时先手必胜。

代码就非常简单了：

~~~
# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# include <queue>
# include <iostream>
# define N 2000
# define LL long long

int T,n;

int main()
{
    //freopen("ysqm.in","r",stdin);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    for(scanf("%d",&T); T ; T--)
    {
        scanf("%d",&n);
        if(n&1) puts("0");
        else puts("1");
    }
    return 0;
}

~~~
