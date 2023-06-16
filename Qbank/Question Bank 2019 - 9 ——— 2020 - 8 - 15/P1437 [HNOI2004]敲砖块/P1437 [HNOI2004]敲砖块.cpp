# include <cstdio>
# define reg register
# define N 50

inline int Read()
{
	int x = 0;char c = getchar();
	
	while(c < '0' && c > '9') c = getchar();
	
	while(c >= '0' && c <= '9'){x = x * 10 + (c ^ 48);c = getchar();}
	
	return x;
}

int n,m,a[N + 42][N + 42],f[N + 42][N + 42][((N * (N + 1)) >> 1) + 42],ans;

inline int Max(const int& a,const int b){return a > b ? a : b;}

inline void DP(reg int& a,const int b){if(a < b) a = b;}

int main()
{
	scanf("%d%d",&n,&m);
	
	for(reg int i = 0 ; i <= n ; ++i)
		for(reg int j = 0 ; j <= n ; ++j)
			for(reg int k = 0 ; k <= m ; ++k)
				f[i][j][k] = -0x7f7f7f7f;
	
	f[n + 1][0][0] = 0;
	
	for(reg int i = 1 ; i <= n ; ++i)
		for(reg int j = 1 ; j <= n - i + 1 ; ++j)
			scanf("%d",&a[i][j]);
	
	for(reg int j = n ; j ; --j)
		for(reg int i = 0,sum = 0; i <= n - j + 1; ++i,sum += a[i][j])
			for(reg int k = i ; k <= m ; ++k)
				for(reg int cur = Max(0,i - 1) ; cur <= n - j ; ++cur)
					DP(f[j][i][k],f[j + 1][cur][k - i] + sum);
	
	for(reg int i = 1 ; i <= n; ++i)
        for(reg int j = 1 ; j <= n - i + 1 ; ++j)
            DP(ans,f[i][j][m]);
    
	/*for(reg int j = n ; j ; --j){
		for(reg int i = 0,sum = 0; i < n - j ; ++i,sum += a[i][j]){
			for(reg int k = i ; k <= m ; ++k)
				if(f[i][j][k] != -0x7f7f7f7f) printf("%-5d",f[i][j][k]);
				else printf("INF ");
				
			printf("\n");
		}
		printf("\n");
	}*/	
	        
    printf("%d",ans);
    
	return 0;
}
