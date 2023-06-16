# include <ctime>
# include <queue>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define reg register
# define N 200000
# define reg register
# define LL long long 
# define Gc (SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
char BB[1<<15],*SS=BB,*TT=BB;
inline int Read()
{
    register int x = 0,f = 1;char ch = Gc;

    while(ch < '0' || ch > '9'){if(ch == '-') f = -1;ch = Gc;}

    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = Gc;}

    return f < 0 ? ~x+1 : x;
}

bool vis[N+5];
int n,m,a[N+5];
int Pre[N+5],Suf[N + 5];

struct node
{
    int Val,id;

    node(const int val=0,const int idx=0):Val(val),id(idx){}

    inline bool operator < (const node& b)const {return Val < b.Val;}
};

std::priority_queue<node> q;

int ans;

int main()
{
    n = Read();m = Read();

    for(reg int i = 1; i <= n ; ++i) a[i] = Read();

    for(reg int i = 1; i <= n ; ++i) q.push(node(a[i],i));

    for(reg int i = 1; i <= n ; ++i) Pre[i] = i-1;

    for(reg int i = 1; i <= n ; ++i) Suf[i] = i+1;

	if(n < (m<<1))
	{
		printf("Error!");
		return 0;
	}

    Pre[1] = n;Suf[n] = 1;

    reg node cur;

    for(reg int i = 1; i <= m ; ++i)
    {
        while(vis[q.top().id]) q.pop();

        cur = q.top();q.pop();
        ans += cur.Val;
        cur.Val =  a[cur.id] = a[Pre[cur.id]] + a[Suf[cur.id]] - cur.Val;
        vis[Pre[cur.id]] = vis[Suf[cur.id]] = 1;
        q.push(cur);
        Pre[cur.id] = Pre[Pre[cur.id]];Suf[Pre[cur.id]] = cur.id;
        Suf[cur.id] = Suf[Suf[cur.id]];Pre[Suf[cur.id]] = cur.id;
    }

    printf("%d",ans);

    return 0;
}
