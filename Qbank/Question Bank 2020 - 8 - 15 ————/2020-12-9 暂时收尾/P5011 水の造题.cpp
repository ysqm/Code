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
    const int mod = 19491001;
    int k,sum,n,ans;
    int Mod(const int x){return x <= mod ? x : x-mod;}
    int inv(LL x,int p = mod-2)
    {
        LL res = 1;
        for(; p ; p >>= 1,x = (x*x)%mod) if(p&1) res = (res*x)%mod;
        return res;
    }
    int Solve()
    {
    	FileRead(ysqm);
        char ch = IO::Gc();
    	while(IO::Isdigit(ch)){n = (n*10+(ch^48))%mod;ch = IO::Gc();}
        k = IO::Read();
        for(int i = 1; i <= k ; ++i) sum = Mod(sum+IO::Read());
        LL INV = inv(k);
        ans = Mod(1LL*n*sum%mod*INV%mod+2LL*Mod(n+mod-1)*sum%mod*INV%mod*INV%mod);
        printf("%d\n",ans);
        return 0;
    }
}

int main(){return Solution::Solve();}
