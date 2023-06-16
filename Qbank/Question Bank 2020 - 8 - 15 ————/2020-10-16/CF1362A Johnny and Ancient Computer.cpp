# include <set>
# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define N 100000
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

int main()
{
    freopen("ysqm.in","r",stdin);
	for(int T = Read<int>(); T ; T--)
    {
        long long a = Read<long long>(),b = Read<long long>();
        if(a == b) {puts("0");continue;}
        if(a < b) a ^= b ^= a ^= b;
        if(a%b != 0) {puts("-1");continue;}
        a/=b;int ans = 0;
        while(a%8==0){++ans;a /= 8;}
        while(a%4==0){++ans;a /= 4;}
        while(a%2==0){++ans;a /= 2;}
        if(a != 1) puts("-1");
        else printf("%d\n",ans);
    }
    return 0;
}