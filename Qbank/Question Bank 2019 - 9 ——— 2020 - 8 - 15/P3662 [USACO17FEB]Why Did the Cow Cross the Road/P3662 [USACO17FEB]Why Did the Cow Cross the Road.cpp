# include <queue> 
# include <cstdio>
# include <cstring>
# include <algorithm>
# define reg register
# define LL long long
# define N 100000 
using namespace std;

inline LL Read()
{
	 LL x = 0,f = 1;char ch = getchar();
	 
	 while(ch < '0' || ch > '9') {f = - 1;ch = getchar();}
	 
	 while(ch >= '0' && ch <= '9'){x = (x * 10) + (ch ^ 48);ch = getchar();}
	 
	 return x * f;
}

inline int Min(const int& a,const int b){return a < b ? a : b;}

int a[N + 42];
int n,k,B,ans = 0x7f7f7f7f;

int main()
{
	n = Read();k = Read();B = Read();
	
	for(reg int i = 1; i <= B ; ++i) a[Read()] = 1;
	
	for(reg int i = 1; i <= n ; ++i) a[i] = a[i-1] + a[i];
	
	for(reg int i = k; i <= n ; ++i) ans = Min(ans,a[i] - a[i - k]);
	
	printf("%d",ans);
	
	return 0;
} 
