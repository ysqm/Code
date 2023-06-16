# include <cstdio>
# include <algorithm>
# include <cmath>
# define N 10000
# define M 50000
# define R register
using namespace std;
int r()
{
	int f = 1,x = 0;;
	
	char c = getchar();
	
	while(c > '9' || c < '0'){
		c = getchar();
	}
	
	while(c >= '0' && c <= '9'){
		x = (x << 3) + (x << 1) + c - '0';
		
		c = getchar();
	}
	
	return x * f;
}

struct edge 
{
	int from,to,wi;
} e[M * 2 + 42],E[M + 42];

int head[N + 42],e_cnt,n,m,f[N + 42][20],s,deep[N + 42],maxstep,a[N + 42],dp[N + 42][20],q;

inline int Find(int i){return a[i] == i ? i : a[i] = Find(a[i]);}

inline void add(int u,int v,int wi)
{
	
};

void INIT()
{
	n = r(); m = r();
	
}
