# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define reg register
# define LL long long
const int N = 1<<18;

using std::unique;
using std::lower_bound;

int n,m,top1,top2;
LL mod,a[N+5],b[N+5],c[N+5],ans;

inline LL Mod(const LL x){return x < mod ? x : x-mod;}

inline void dfs2(const int cur,const int Sum)
{
	if(cur > n) return;
    if(cur == n)
    {
        c[++top1] = Mod(Sum+a[cur]);
        c[++top1] = Sum;
    }
    else
    {
        dfs2(cur+1,Mod(Sum+a[cur]));
        dfs2(cur+1,Sum);
    }
}

inline void dfs1(const int cur,const LL Sum)
{
	if(cur > m) return;
    if(cur == m)
    {
        b[++top2] = Mod(Sum+a[cur]);
        b[++top2] = Sum;
    }
    else
    {
        dfs1(cur+1,Mod(Sum+a[cur]));
        dfs1(cur+1,Sum);
    }
}

inline int check(const LL x)
{
    register int l=1,r=top2,mid;

    for(;l<r;)
    {
        mid=(l+r)>>1;
        ((b[mid] >= x) && (r = mid)) || (l = mid+1);
    }

    return l;
}

inline void Max(LL& a,const LL b){(b > a) && (a = b);}

int main()
{
    scanf("%d%lld",&n,&mod);

    for(reg int i = 1; i <= n ; ++i) scanf("%lld",a+i);
    
    for(reg int i = 1; i <= n ; ++i) *(a+i) %= mod;

    m = n>>1;
    dfs1(1,0);
    dfs2(m+1,0);
    std::sort(c+1,c+top1+1);
    std::sort(b+1,b+top2+1);
    top1 = unique(c+1,c+top1+1)-c-1;
    top2 = unique(b+1,b+top2+1)-b-1;

    for(reg int i = 1,pos; i <= top1; ++i)
    {
        pos = lower_bound(b+1,b+top2+1,mod-c[i])-b-1;
        //if(b[pos]+c[i] >= mod) continue;
        Max(ans,b[pos]+c[i]);
    }

    Max(ans,Mod(b[top2]+c[top1]));
    printf("%lld",ans);
    return 0;
}
