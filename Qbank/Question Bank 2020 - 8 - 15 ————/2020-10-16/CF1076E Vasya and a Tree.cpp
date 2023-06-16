# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# include <vector>
# define LL long long
# define N 100000
# define Gc (SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
char BB[1<<15],*SS=BB,*TT=BB;
inline int Read()
{
    register int x = 0;char ch = Gc;

    while(ch < '0' || ch > '9')ch = Gc;

    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = Gc;}

    return x;
}

std::vector<int> G[N+5],D[N+5],X[N+5];

LL f[N+5],ans[N+5];
int n,deep[N+5],m;

void dfs(const int u,const int fa,LL sum)
{
    sum += f[deep[u]];
    for(int i = 0; i < D[u].size() ; ++i)
    {
        sum += X[u][i];
        if(deep[u] + D[u][i] + 1 <= n) f[deep[u] + D[u][i] + 1] -= X[u][i];
    }
    ans[u] = sum;
    for(int i = 0; i < G[u].size() ; ++i)
        if(G[u][i] != fa)
        {
            deep[G[u][i]] = deep[u]+1;
            dfs(G[u][i],u,sum);
        }
    for(int i = 0; i < D[u].size() ; ++i) if(deep[u] + D[u][i] + 1 <= n) f[deep[u] + D[u][i] + 1] += X[u][i];
}

int main()
{
	n = Read();
    for(int i = 2,x,y; i <= n ; ++i)
    {
        x = Read();y = Read();
        G[x].push_back(y);
        G[y].push_back(x);
    }
    m = Read();
    for(int i = 1,v,x,y; i <= m ; ++i)
    {
    	v = Read();x = Read();y = Read();
        D[v].push_back(x);
        X[v].push_back(y);
    }
    dfs(1,1,0);
    for(int i = 1; i <= n ; ++i) printf("%lld ",ans[i]);
    return 0;
}
