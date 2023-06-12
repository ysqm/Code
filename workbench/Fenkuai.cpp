# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define LL long long

inline int Read()
{
    register int x = 0;char ch = getchar();
    
    while(ch < '0' || ch > '9')ch = getchar();
    
    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = getchar();}
    
    return x;
}

const int N = 1e5;
const int BO = 542;

int a[N+5],n,opt,l,r,c;
int boc[N+5],dn;

int main()
{
    n = Read();
    for(int i = 1; i <= n ; ++i) a[i] = Read();
    for(int i = BO; i-BO <= n ; i += BO) boc[++dn] = i;
    
    return 0;
}