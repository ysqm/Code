# include <cstdio>
# include <cstring>
# include <algorithm>
# include <vector> 
# define reg register
# define N 1000
# define TIME 40000
# define LL long long
using namespace std;

inline LL Read()
{
	 LL x = 0;char ch = getchar();
	 
	 while(ch < '0' || ch > '9') ch = getchar();
	 
	 while(ch >= '0' && ch <= '9'){x = (x * 10) + (ch ^ 48);ch = getchar();}
	 
	 return x;
} 

inline int Min(const int a,const int b){return a < b ? a : b;}
inline int Max(const int a,const int b){return a > b ? a : b;}

struct Point
{
	LL Number;
	int Magic;
	Point(const int Magic=0,const LL Number_=0):Number(Number_),Magic(Magic){}
	
	inline friend bool operator < (const Point a,const Point b){return a.Magic > b.Magic;}
	
} P[N + 42];

int n,ans;
LL base[64];

bool check(LL x)
{
	for(reg LL i = 63; ~i ; --i)
		if((x >> i) & 1)
		{
			x ^= base[i];
			if(base[i] == 0){base[i] ^= x;return 1;}
		}
	return 0;
}

int main()
{
	n = Read();
	
	for(reg int i = 1; i <= n ; ++i) P[i] = Point(Read(),Read());
	
	std::sort(P + 1,P + n + 1);
	
	for(reg int i = 1; i <= n ; ++i)
		if(check(P[i].Number)) ans += P[i].Magic;
	
	printf("%d",ans);
	
	return 0;
}
