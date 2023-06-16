# include <cstdio>
# include <cstring>
# include <queue>
# include <cmath>
# define reg register
# define N 200
# define LL long long
using namespace std;

inline int Read()
{
	int x = 0;char c = getchar();
	
	while(c < '0' || c > '9') c = getchar();
	
	while(c >= '0' && c <= '9'){x = (x << 3) + (x << 1) +c - 48;c = getchar();}
	
	return x;
}

inline int Max(const int a,const int b){return a > b ? a : b;}
inline int Min(const int a,const int b){return a < b ? a : b;}

int n,S,T,G[242][242]; 

int main()
{
	n = Read();S = Read();T = Read();
	
	for(reg int i = 1; i <= n ; ++i)
			for(reg int j = 1; j <= n ; ++j)
				if(i != j) G[i][j] = 1e9;
	
	for(reg int i = 1; i <= n ; ++i)
	{
		int a = Read();
		
		if(i + a <= n) G[i][i + a] = 1;
		if(i - a >= 1) G[i][i - a] = 1;
	}
	
	for(reg int k = 1; k <= n ; ++k)
		for(reg int i = 1; i <= n ; ++i)
			for(reg int j = 1; j <= n ; ++j)
				if(G[i][k] + G[k][j] < G[i][j])
					if(i != k && k != j) G[i][j] = Min(G[i][j], G[i][k] + G[k][j]);
					
	printf("%d\n",G[S][T] == 1e9 ? -1 : G[S][T]);
	
	return 0;
}
