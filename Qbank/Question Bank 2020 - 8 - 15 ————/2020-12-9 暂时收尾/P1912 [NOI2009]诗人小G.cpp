# include <ctime>
# include <cmath>
# include <queue>
# include <vector>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define LL long long
# define File(x) freopen(#x".in","r",stdin)//;freopen(#x".out","w",stdout)
# define N 100000
# define LD long double

char s[N+5][42];
int n,L,P;
int i,j,k;
int q[N+5],t,h,Pre[N+5],KP[N+5];
LL a[N+5];

LD qpow(LD x,int p)
{
    LD res = 1;
    for(; p ; p /= 2,x *= x) if(p&1) res *= x;
    return res;
}

template<class T> T ABS(const T x){return x < 0 ? -x : x;}

LD f[N+5];

LD F(const int l,const int r)
{
	return f[l]+qpow(ABS(a[r]-a[l]-1-L),P);
}

int Check(const int x,const int y)
{
    int L = x,R = n+1,mid;
    while(L < R)
    {
        mid = (L+R)/2;
        if(F(x,mid) >= F(y,mid)) R = mid;
        else L = mid+1; 
    }
    return L;
}

void Solve()
{
    scanf("%d %d %d",&n,&L,&P);
    for(i = 1; i <= n ; ++i)
    {
        scanf("%s\n",s[i]);
        a[i] = a[i-1] + strlen(s[i]) + 1;
    }
    for(q[t = h = i = 1] = 0; i <= n ; ++i)
    {
        while(h < t && KP[h] <= i) ++h;
        f[i] = F(q[h],i);Pre[i] = q[h];
        while(h < t && KP[t-1] >= Check(q[t],i)) --t;
        KP[t] = Check(q[t],i);q[++t] = i;
    }
    
    if(f[n] > 1e18) puts("Too hard to arrange");
    else 
    {
        printf("%.0Lf\n",f[n]);
        q[t = 0] = n;
        while(q[t]){q[t+1] = Pre[q[t]];++t;}
        for(t; t ; t--)
        {
            for(i = q[t]+1; i < q[t-1] ; ++i) printf("%s ",s[i]);
            puts(s[q[t-1]]);
        }
    }
    printf("--------------------\n");
}

int main()
{
    //File(poem);
    int T;
    for(scanf("%d\n",&T); T ; T--) Solve();
    return 0;
}
/*
4 9 3
brysj,
hhrhl.
yqqlm,
gsycl.
4 9 2
brysj,
hhrhl.
yqqlm,
gsycl.
1
*/