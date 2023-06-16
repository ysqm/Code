# include <ctime>
# include <queue>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define reg register
# define N 1000
inline int Read()
{
    register int x = 0;char ch = getchar();

    while(ch < '0' || ch > '9')ch = getchar();

    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = getchar();}

    return x;
}

struct node
{
    int x,nx,ny;
    node(const int x_=0,const int dx_=0,const int dy_=0):x(x_),nx(dx_),ny(dy_){}
    inline bool operator < (const node& b)const {return x > b.x;}
};

const int dx[4] = {0,0,1,-1},dy[4] = {1,-1,0,0};
std::priority_queue<node> q;
int vis[N+5][N+5];
int G[N+5][N+5];

inline int SPFA(const int SX,const int SY)
{
    node cur;
    int sx,sy;
    q.push(node(0,SX,SY));

    while(q.size())
    {
        cur = q.top();q.pop();
        for(reg int i = 0; i <= 3 ; ++i)
        {
            sx = cur.nx+dx[i];sy = cur.ny+dy[i];
            if(sx == 0 && sy == 0) 
				return cur.x + G[sx][sy];
            if(vis[sx][sy] || sx < 0 || sx > 1001 || sy < 0 || sy > 1000) continue;
            vis[sx][sy] = 1;
            q.push(node(cur.x+G[sx][sy],sx,sy));
        }
    }
}

int main()
{
    register int n,x,y;

    n = Read();x = Read();y = Read();

    for(reg int i = 1,tx,ty; i <= n ; ++i)
    {
        tx = Read();ty = Read();
        G[tx][ty] = 1;
    }

    printf("%d\n",SPFA(x,y));

    return 0;
}
