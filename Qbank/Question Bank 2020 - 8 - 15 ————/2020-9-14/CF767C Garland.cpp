# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define Gc (SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
char BB[1<<15],*SS=BB,*TT=BB;
inline int Read()
{
    register int x = 0,f = 1;char ch = Gc;

    while(ch < '0' || ch > '9'){if(ch == '-') f = -1;ch = Gc;}

    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = Gc;}

    return f < 0 ? ~x+1 : x;
}

const int N = 1e6;

struct edge
{
    int Next,to;

    edge(const int Next_=0,const int To_=0):Next(Next_),to(To_){}
} e[N+5];

int head[N+5],edge_tot = -1,n,P[N+5],rt,sum,dp[N+5],stk[3],top=-1;

inline void add_edge(const int u,const int v)
{
    e[++edge_tot] = edge(head[u],v);
    head[u] = edge_tot;
}

void Input()
{
    freopen("ysqm.in","r",stdin);
    memset(head,-1,sizeof(head));
    n = Read();int x,w;
    for(int i = 1; i <= n ; ++i)
    {
        x = Read();P[i] = Read();
        sum += P[i];
        if(x) add_edge(x,i);
        else rt = i;
    }
    fclose(stdin);
}

void dfs(const int u)
{
    dp[u] = P[u];
    for(int i = head[u]; ~i ; i = e[i].Next)
    {
        dfs(e[i].to);
        dp[u] += dp[e[i].to];
    }
    if(dp[u] == sum) {stk[++top] = u;dp[u] = 0;}
}

void Solve()
{
    Input();
    if(sum%3 != 0) {puts("-1");return;}
    else {sum/=3;dfs(rt);}
    if(top < 2) puts("-1");
    else printf("%d %d",stk[0],stk[1]); 
}

int main(){Solve();return 0;}
