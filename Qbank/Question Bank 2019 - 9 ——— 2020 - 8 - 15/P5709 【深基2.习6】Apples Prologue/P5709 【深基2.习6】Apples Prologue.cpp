# include <cstdio>
# include <algorithm>
# define LL long long
# define N 10000
# define reg register
using namespace std;

inline void in(int& x)
{
	x = 0;char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch <= '9' && ch >= '0') {x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}
}

inline int Read()
{
	int x = 0;char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch <= '9' && ch >= '0') {x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}
	
	return x;
}

int main()
{
	printf("%d",Read() * Read());
	return 0;
}
