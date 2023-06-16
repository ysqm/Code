# include <map>
# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define reg register
# define Gc (SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
char BB[1<<15],*SS=BB,*TT=BB;
inline int Read()
{
    register int x = 0;char ch = Gc;

    while(ch < '0' || ch > '9')ch = Gc;

    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = Gc;}

    return x;
}

std::map<int,int> mp;

int n,m;

int main()
{
    register long long ans = 0;
    n = Read();m = Read();

    for(reg int i = 1,x; i <= n ; ++i)
    {
        x = Read();
        ans += (mp[i+x]++);
        ans += (mp[i-x]++);
    }

    printf("%lld",ans);

    return 0;
}