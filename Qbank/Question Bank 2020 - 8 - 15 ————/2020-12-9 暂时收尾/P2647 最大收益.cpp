# include <ctime>
# include <cmath>
# include <queue>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define reg register
# define LL long long
# define FileRead(x) freopen(#x".in","r",stdin)
# define FileWrite(x) freopen(#x".out","w",stdout) 
namespace IO
{
    char BB[1<<15],*SS=BB,*TT=BB;
    inline char Gc(){return (SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++);}
    inline bool Isdigit(const char ch){return '0' <= ch && ch <= '9';}
    inline int Read()
    {
        register int x = 0;char ch = Gc();
    
        while(!Isdigit(ch)) ch = Gc();
    
        while(Isdigit(ch)){x = x*10+(ch^48);ch = Gc();}
    
        return x;
    }
    
    inline int Max(const int x,const int y){return x < y ? y : x;}
    inline int Min(const int x,const int y){return x < y ? x : y;}
}

namespace Solution
{
    # define N 3000
    
    struct node
    {
        int Wi,R;
        bool operator < (const node& b)const{return R > b.R;}
    } a[N+5];
    
    template<class T>
    inline T Max(const T x,const T y){return x < y ? y : x;}
    
    int n;
    LL dp[N+5],ans;
    
    int Solve()
    {
        FileRead(ysqm);
        n = IO::Read();
        for(int i = 1; i <= n ; ++i){a[i].Wi = IO::Read();a[i].R = IO::Read();}
        std::sort(a+1,a+n+1);
        dp[1] = a[1].Wi;
        for(int i = 1; i <= n ; ++i)
        	for(int j = i; j >= 1 ; --j)
        		dp[j] = Max(dp[j],dp[j-1]+a[i].Wi-a[i].R*(j-1));
        for(int i = 1; i <= n ; ++i) ans = Max(ans,dp[i]);
        printf("%lld",ans);
        return 0;
    }
}

int main(){return Solution::Solve();}
