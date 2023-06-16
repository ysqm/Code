# include <ctime>
# include <cmath>
# include <queue>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define N 150
//# define M 2000
# define M 20000000
# define reg register
# define LL long long
# define FileRead(x) freopen(#x".in","r",stdin)
# define FileWrite(x) freopen(#x".out","w",stdout)
namespace IO
{
    # define Gc (SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
    char BB[1<<15],*SS=BB,*TT=BB;
    inline int Read()
    {
        register int x = 0;char ch = Gc;

        while(ch < '0' || ch > '9')ch = Gc;

        while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = Gc;}

        return x;
    }

    inline int Max(const int x,const int y){return x < y ? y : x;}
    inline int Min(const int x,const int y){return x < y ? x : y;}
}

int n,m;
int A[305][305],B[305][305];

namespace ReadIn
{
    void Input()
    {
        n = IO::Read();m = IO::Read();
        for(int i = 1; i <= n ; ++i)
            for(int j = 1; j <= m ; ++j)
                B[i][j] = IO::Read();
        for(int i = 1; i <= n ; ++i)
            for(int j = 1; j <= m ; ++j)
                A[i][j] = IO::Read();
    }
}

namespace Solution
{
    int sx[3],sy[3];
    int fa[N+5][N+5];

    int Find(int *f,const int x){return f[x] ? f[x] = Find(f,f[x]) : x;}
    
    struct node
    {
        LL Cost;int x,y;
        //node(){}
        node(const int x_=0,const int y_=0,const int Cost_=0):y(y_),x(x_),Cost(Cost_){}
        bool operator < (const node& b)const{return Cost > b.Cost;}
    } cur;
	
	# define x cur.x
	# define y cur.y
	
    std::priority_queue<node> q;
    bool vis[N+5][N+5];
    LL dis[N+5][N+5];

    void Dijstra(const int xx,const int yy)
    {
        for(int i = 1; i <= n ; ++i)
            for(int j = 1; j <= m ; ++j)
                dis[i][j] = 2e18;
        for(int i = 1; i <= n ; ++i) 
            for(int j = 1; j <= m ; ++j)
                fa[i][j] = 0;
        memset(vis,0,sizeof(vis));
        dis[xx][yy] = 0;
        fa[xx][yy] = yy+1;
        q.push(node(xx,yy,A[xx][yy]));
        while(q.size())
        {
            cur = q.top();q.pop();
            if(vis[x][y]) continue;
            vis[x][y] = 1;
            int lx = std::max(1,x-B[x][y]),rx = std::min(n,x+B[x][y]);
            for(int i = lx; i <= rx ; ++i)
            {
                int len = B[x][y]-std::abs(i-x);
                int L = std::max(1,y-len),R = std::min(m,y+len);
                for(int j = Find(fa[i],L); j <= R ; j = Find(fa[i],j))
                {
                    if(dis[i][j] > dis[x][y]+A[i][j])
                    {
                        dis[i][j] = dis[x][y]+A[i][j];
                        q.push(node(i,j,dis[i][j]+A[i][j]));
                    }
                    fa[i][j] = j+1;
                }
            }
        }
    }

    int Solve()
    {
    	FileRead(ysqm);
        ReadIn::Input();
        sx[0] = IO::Read();sy[0] = IO::Read();
        sx[1] = IO::Read();sy[1] = IO::Read();
        sx[2] = IO::Read();sy[2] = IO::Read();
        LL xy,xz,yx,yz,zx,zy;
        Dijstra(sx[0],sy[0]);
        xy = dis[sx[1]][sy[1]];
        xz = dis[sx[2]][sy[2]];
        Dijstra(sx[1],sy[1]);
        yx = dis[sx[0]][sy[0]];
        yz = dis[sx[2]][sy[2]];
        Dijstra(sx[2],sy[2]);
        zx = dis[sx[0]][sy[0]];
        zy = dis[sx[1]][sy[1]];
        LL distance = std::min(xy+zy,std::min(zx+yx,yz+xz));
        if(distance >= 1e8) return puts("NO"),0;
        else if(yx+zx == distance) puts("X");
        else if(zy+xy == distance) puts("Y");
        else if(xz+yz == distance) puts("Z");
        return printf("%lld\n",distance),0;
    }
}

int main(){return Solution::Solve();}
