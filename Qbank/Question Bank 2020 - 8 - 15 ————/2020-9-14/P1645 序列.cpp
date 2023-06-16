# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define N 1000
# define max std::max

inline int Max(const int x,const int y){return x > y ? x : y;}
inline int Min(const int x,const int y){return x < y ? x : y;}

struct node
{
    int L,R,C;
    node(const int L_=0,const int R_=0,const int C_=0):C(C_),L(L_),R(R_){}
    bool operator < (const node& b)const {return R < b.R;} 
} a[N+5];

bool vis[N+5];
int cnt,ans,n;

int main()
{
    scanf("%d",&n);
    for(int i = 1; i <= n ; ++i) scanf("%d%d%d",&a[i].L,&a[i].R,&a[i].C);
    std::sort(a+1,a+n+1);
    for(int S = 1; S <= n ; ++S)
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