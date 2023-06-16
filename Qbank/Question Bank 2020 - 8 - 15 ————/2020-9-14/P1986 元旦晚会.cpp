# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define N 5000
# define M 30000
# define max std::max

inline int Max(const int x,const int y){return x > y ? x : y;}
inline int Min(const int x,const int y){return x < y ? x : y;}

struct node
{
    int L,R,C;
    node(const int L_=0,const int R_=0,const int C_=0):C(C_),L(L_),R(R_){}
    bool operator < (const node& b)const {return R < b.R;} 
} a[N+5];

bool vis[M+5];
int cnt,ans,n,m;

int main()
{
    freopen("ysqm.in","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= m ; ++i) scanf("%d%d%d",&a[i].L,&a[i].R,&a[i].C);
    std::sort(a+1,a+m+1);
    for(int S = 1; S <= m ; ++S)
    {
        for(int i = a[S].L; i <= a[S].R ; ++i) if(vis[i]) --a[S].C;
        for(int i = a[S].R; a[S].C > 0 ; --i)
            if(!vis[i])
            {
                --a[S].C;
                vis[i] = 1;
                ++ans;
            }
    }
    printf("%d\n",ans);
    return 0;
}