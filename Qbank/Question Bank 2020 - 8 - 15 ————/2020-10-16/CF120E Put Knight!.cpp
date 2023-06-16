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
