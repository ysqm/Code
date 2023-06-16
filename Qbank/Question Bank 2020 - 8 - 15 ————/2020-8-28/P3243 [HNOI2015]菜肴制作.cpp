# include <queue>
# include <cstdio>
# include <vector>
# include <cstring>
# include <algorithm>
# define reg register
# define N 100000
# define LL long long
# define Gc (SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
char BB[1<<15],*SS=BB,*TT=BB;
inline int Read()
{
    register int x = 0;char ch = Gc;

    while(ch < '0' || ch > '9')ch = Gc;

    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = Gc;}

    return x;
}

std::priority_queue<int> q; 
std::vector<int> G[3][N+5];
int head[N+5],edge_tot,indegree[N+5],T,n,m,cur,ans[N+5];

inline void SPFA()
{
	int u;
	
    for(reg int i = 1; i <= n ; ++i) if(indegree[i] == 0) q.push(i);
    
    while(q.size())
    {
        u = q.top();q.pop();
        ans[cur--] = u;
        for(reg int i = 0; i < G[T][u].size() ; ++i) if((--indegree[G[T][u][i]]) == 0) q.push(G[T][u][i]); 
    }
}

inline void Solve()
{
    n = Read();m = Read();
    edge_tot = 0;cur = n;
    memset(head,0,sizeof(head));
    memset(indegree,0,sizeof(indegree));

    for(reg int i = 1,x,y; i <= m ; ++i)
    {
        x = Read();y = Read();
        G[T][y].push_back(x);
        ++indegree[x];
    }
    
    SPFA(); 

    if(cur == 0) for(reg int i = 1; i <= n ; ++i) printf("%d ",ans[i]);
    else printf("Impossible!");
    printf("\n");
}

int main()
{
    //freopen("P3243_1.in","r",stdin);
    //freopen("P3212312.out","w",stdout); 
    T = Read();
    while(T--) Solve();
    return 0;
}
