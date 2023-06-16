# include <cstdio>
# include <queue>
# define N 500
# define M 5000
# define R register
# define inf 1000000000
using namespace std;
inline int re()
{
	int f = 1,x = 0;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}
struct edge
{
	int from,to,wi;
} e[M + 42];
int a,b
int main()
{	
	
}
