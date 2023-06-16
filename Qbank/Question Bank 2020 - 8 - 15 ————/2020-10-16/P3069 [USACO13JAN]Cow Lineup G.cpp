# include <set>
# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define LL long long
# define N 100000
# define Set std::set<int>
# define IT std::set<int>std::iterator 
# define Gc (SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
char BB[1<<15],*SS=BB,*TT=BB;
inline int Read()
{
    register int x = 0;char ch = Gc;

    while(ch < '0' || ch > '9')ch = Gc;

    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = Gc;}

    return x;
}

int q[N+5],n,k,ans,a[N+5],b[N+5],h,t,sumcol[N+5],col;

void Discretization()
{
    int top = 0;
    std::sort(b+1,b+n+1);a[0] = -1;
    for(int i = 1; i <= n ; ++i) if(b[i] != b[i-1]) b[++top] = b[i];
    for(int i = 1; i <= n ; ++i) a[i] = std::lower_bound(b+1,b+top+1,a[i])-b-1;
}

int main()
{
	freopen("ysqm.in","r",stdin);
	n = Read();k = Read();
    for(int i = 1; i <= n ; ++i) b[i] = a[i] = Read();
    Discretization();
    for(int i = 1; i <= n ; ++i)
    {
        if(sumcol[a[i]] == 0) ++col;
        ++sumcol[a[i]];
        while(col == k+2 && (col -= ((--sumcol[a[q[h]]]) == 0))) ++h;
        q[++t] = i;
        if(sumcol[a[q[t]]] > ans) ans = sumcol[a[q[t]]];
    }
    printf("%d\n",ans);
    return 0;
}
