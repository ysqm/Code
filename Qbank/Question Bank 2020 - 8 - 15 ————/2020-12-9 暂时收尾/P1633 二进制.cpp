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
    int a,b,c;
    int _Solve()
    {
        LL sa = 0,sb = 0,sc = 0,len = 0,ans = 0,base;
        a = IO::Read();b = IO::Read();c = IO::Read();
        for(int i = 0; i <= 30 ; ++i) if((a>>i)&1) {++sa;if(1+i > len) len = i+1;}
        for(int i = 0; i <= 30 ; ++i) if((b>>i)&1) {++sb;if(1+i > len) len = i+1;}
        for(int i = 0; i <= 30 ; ++i) if((c>>i)&1) {++sc;if(1+i > len) len = i+1;}
        base = ((1LL<<len)-1)^((1LL<<(len-sc))-1);//�ѽ�λ�ŵ����
        if(sa > sb) sa ^= sb ^= sa ^= sb;
		if(sc <= sa)  ans = ((1LL<<(sa+sb-sc))|((1LL<<sc)-2));
		else if(sc <= sb) ans = (((1LL<<sb)|((1<<sc)-1))^(1LL<<(sc-sa)));
		else if(sc <= sa + sb) ans = (((1LL<<(sc+1))-1)^(1LL<<(2*sc-sa-sb)));
		else return -1;
        return ((ans > base)) ? -1 : ans;
    }
    
    int Solve()
    {
        //FileRead(ysqm);
        int T = IO::Read();
        while(T--) printf("%d\n",_Solve());
        return 0;
    }
}

int main(){return Solution::Solve();}
