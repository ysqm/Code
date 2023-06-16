# include <ctime>
# include <queue>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define reg register
# define N 100000
inline int Read()
{
    register int x = 0;char ch = getchar();

    while(ch < '0' || ch > '9')ch = getchar();

    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = getchar();}

    return x;
}

struct node
{
    int idx,val;

    node(const int idx_=0,const int Val=0):idx(idx_),val(Val){}
    
    inline bool operator < (const node& a)const {return val > a.val;}
};

std::priority_queue<node> q;

bool vis[N+5];
int Pre[N+5],Suf[N+5],a[N+5],n,m,ans,T;

int main()
{
    //freopen("P3620_2.in","r",stdin);

	T = Read(); 
    while(T--)
    {
        n = Read();m = Read();

        for(reg int i = 1,x,f=0; i <= n ; ++i)
        {	
            x = Read();
            a[i] = x - f;
            f = x;
        }

        for(reg int i = 1; i <= n ; ++i) Suf[i] = i+1;

        for(reg int i = 1; i <= n+1 ; ++i) Pre[i] = i-1;

        a[0] = a[1] = a[n+1] = 0x3f3f3f3f;

        for(reg int i = 1; i <= n+1 ; ++i) q.push(node(i,a[i]));

        for(reg int i = 1; i <= m ; ++i)
        {
            while(q.size() && vis[q.top().idx]) q.pop();

            node cur = q.top();q.pop();
            ans += cur.val;
            vis[Pre[cur.idx]] = vis[Suf[cur.idx]] = 1;
            cur.val = a[Pre[cur.idx]] + a[Suf[cur.idx]] - cur.val;
            a[cur.idx] = cur.val;
            q.push(cur);
            Pre[cur.idx] = Pre[Pre[cur.idx]];Suf[Pre[cur.idx]] = cur.idx;
            Suf[cur.idx] = Suf[Suf[cur.idx]];Pre[Suf[cur.idx]] = cur.idx;
        }
        
        printf("%d\n",ans);ans = 0;
		memset(vis,0,sizeof(vis)); 
        memset(Pre,0,sizeof(Pre));
        memset(Suf,0,sizeof(Suf));
        memset(a,0,sizeof(a));
        while(q.size()) q.pop(); 
    }

    return 0;
}
