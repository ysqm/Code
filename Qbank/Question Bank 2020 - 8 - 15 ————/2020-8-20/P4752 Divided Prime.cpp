# include <ctime>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define LL long long
# define Gc getchar()//(SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
char BB[1<<15],*SS=BB,*TT=BB;
template<class T>
inline T Read()
{
    register T x = 0;char ch = Gc;

    while(ch < '0' || ch > '9')ch = Gc;

    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = Gc;}

    return x;
}

const int count = 10;

int modular_exp(const int a,const int m,const int n)
{
	if(m == 0) return 1;
	if(m == 1) return (a % n);
	long long w = modular_exp(a,m>>1,n);
	w = w*w%n;
	if(m&1) w = w*a%n;
	return w; 
}

inline bool Miller_Rabin(const int n)
{
	if(n == 2) return true;
	for(register int i = 0; i < count ; ++i)
	{
		int a = rand() % (n-2) + 2;
		if(modular_exp(a,n,n) != a) return false;
	}
	return true;
}

int main()
{
    int m,n,T,x,y,s;

    T = Read<int>();

    while(T--)
    {
        n = Read<int>();m = Read<int>();s = 0;y = 0;

        for(register int i = 1; i <= n; ++i) if((x = Read<LL>()) != 1) y ^= x,++s;

        for(register int i = 1; i <= m; ++i) if((x = Read<LL>()) != 1) y ^= x,--s; 

        if(s == 1 && Miller_Rabin(y)) puts("YES");
        else puts("NO");
    }

    return 0;
}
