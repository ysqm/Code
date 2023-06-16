# include <ctime>
# include <cmath>
# include <queue>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# include <iostream>
# define LL long long
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
    int wi,nxt;
    bool operator < (const node& a)const{return a.nxt > nxt;}
    node(const int wi_=0,const int xid_=0):wi(wi_),nxt(xid_){}
} cur;

bool vis[N+5];
std::priority_queue<node> h;
int n,m,a[N+5],bucket[N+5],lst[N+5],nxt[N+5],ans,cnt;

void Discretization()
{
    n = Read();m = Read();
    for(int i = 1; i <= n ; ++i) a[i] = bucket[i] = Read();
    std::sort(bucket+1,bucket+n+1);
    int top = std::unique(bucket+1,bucket+n+1)-bucket-1;
    for(int i = 1; i <= n ; ++i)
    {
    	nxt[i] = n+1;
        a[i] = std::lower_bound(bucket+1,bucket+top+1,a[i])-bucket;
        nxt[lst[a[i]]] = i;
        lst[a[i]] = i;
    }
}

int main()
{
    Discretization();
    for(int i = 1; i <= n ; ++i)
    {
        while(h.size() && !vis[h.top().wi]) h.pop();
        if(vis[a[i]]) h.push(node(a[i],nxt[i]));
        else
        {
            ans++;
            vis[a[i]] = true;
            if(h.size() && cnt >= m){vis[h.top().wi] = false;h.pop();}
            if(cnt < m) ++cnt;
            h.push(node(a[i],nxt[i]));
        }
    }
    printf("%d\n",ans);
    return 0;
}
