# include <cstdio>
# include <vector>
# define LL long long
# define N 100000
# define M 3000000

inline int Max(const int x,const int y){return x < y ? y : x;}

int n;
std::vector<int> g[M+5];
int f[M+5],lx;

int main()
{
    scanf("%d",&n);
    for(int i = 1,x,y; i <= n ; ++i)
    {
        scanf("%d%d",&x,&y);
        g[y].push_back(x);
        lx = Max(lx,y);
    }
    //for(int j = 0; j < g[0].size() ; ++j) f[1] = Max(f[1],f[g[i][j]-1]+i-g[0][j]+1);
    for(int i = 1; i <= lx ; ++i)
    {
        f[i] = f[i-1];
        for(int j = 0; j < g[i].size() ; ++j) f[i] = Max(f[i],f[g[i][j]-1]+i-g[i][j]+1);
    }
    printf("%d",f[lx]);
    return 0;
}
