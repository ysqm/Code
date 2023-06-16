# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define N 10000
# define reg register

inline int Read()
{
    register int x = 0;char ch = getchar();

    while(ch < '0' || ch > '9')ch = getchar();

    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = getchar();}

    return x;
}

inline int Max(const int x,const int y){return x < y ? y : x;}

struct Event
{
	int st,ed,Duration;
	inline bool operator < (const Event& b)const{return st < b.st;}
} a[N+5];

int f[N+5],ans,n;

int main()
{
    n = Read();

    for(reg int i = 1; i <= n ; ++i)
    {
    	a[i].st = Read();a[i].ed = Read();
    	a[i].Duration = a[i].ed - a[i].st;
	}
	
	std::sort(a+1,a+n+1);

    for(reg int i = 1; i <= n ; ++i)
    {
    	f[i] = a[i].Duration;
    	for(reg int j = 1; j < i ; ++j) if(a[j].ed <= a[i].st) f[i] = Max(f[i],a[i].Duration+f[j]);
    	ans = Max(ans,f[i]);
	}

    printf("%d",ans);

    return 0;
}
