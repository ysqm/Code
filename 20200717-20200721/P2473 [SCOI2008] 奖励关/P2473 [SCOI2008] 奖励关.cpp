# include <cstdio>
# define reg register 
# define N 17
# define K 100
# define LL long long

const int NN = 1<<N;

inline int Read()
{
	int x = 0,f = 1;char ch = getchar();
	
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1;ch = getchar();}
	
	while(ch >= '0' && ch <= '9'){x = x*10 + (ch^48);ch = getchar();}
	
	return f == -1 ? -x : x;
}

inline double Max(const double a,const double b){return a < b ? b : a;} 

int n,kk,d[N+42],p[N+42];
double dp[K+5][NN];

int main()
{
	kk = Read();n = Read();
	
	for(reg int i = 1,c; i <= n ; ++i)
	{
		p[i] = Read();
		
		while(c = Read()) d[i] |= (1<<(c-1));
	}
	
	for(reg int i = 1; i >= 1 ; --i)
		for(reg int j = 0 ; j < (1<<n) ; ++j)
		{	for(reg int k = 1; k <= n ; ++k)
				if((d[k] & j) == d[k]) dp[i][j] += Max(dp[i+1][j],dp[i+1][j|(1<<(k-1))] + p[k]);
				else dp[i][j] += dp[i+1][j];
					
			dp[i][j] /= n;
		}
		
	printf("%.6lf\n",dp[1][0]);
	
	return 0;
}
