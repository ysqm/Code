# include <set>
# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define N 1024
# define Gc (SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
char BB[1<<15],*SS=BB,*TT=BB;
template<class T>
inline T Read()
{
    register T x = 0;char ch = Gc;

    while(ch < '0' || ch > '9')ch = Gc;

    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = Gc;}

    return x;
}

int n,x;

int main()
{
    //freopen("ysqm.in","r",stdin);
	for(int T = Read<int>(); T ; --T)
    {
        n = Read<int>();x = 0;
        for(int i = 1; i <= n ; ++i) x ^= Read<int>();
        puts(x != 0 ? "Yes" : "No");
    }
    return 0;
}