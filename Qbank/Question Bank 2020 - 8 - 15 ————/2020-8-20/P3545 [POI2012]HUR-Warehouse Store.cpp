# include <ctime>
# include <queue>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define N 250000
# define reg register
# define int long long 

inline int Read()
{
    register int x = 0;char ch = getchar();

    while(ch < '0' || ch > '9')ch = getchar();

    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = getchar();}

    return x;
}

struct node
{
    int x,idx;

    node(const int x_=0,const int idx_=0):x(x_),idx(idx_){}

} a[N + 42];

inline bool operator < (const node& a,const node& b){return a.x < b.x;}

int cnt,sum;
std::priority_queue<node> q;


signed main()
{
    int n = Read();

    for(reg int i = 1; i <= n ; ++i) a[i] = node(Read(),i);

    for(reg int i = 1,x; i <= n ; ++i)
    {
        x = Read();cnt += a[i].x;
        if(cnt >= x) {q.push(node(x,i));cnt -= x;++sum;}
        else if(q.size() && q.top().x > x) {cnt = cnt - x + q.top().x;q.pop();q.push(node(x,i));}
    }

    printf("%lld\n",sum);

     
	while(q.size()){printf("%lld ",q.top().idx);q.pop();}

    return 0;
}
