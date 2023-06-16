# include <cstdio>
# define reg register
# define mod 20123
# define N 10000
# define M 100

inline int Read()
{
	int x = 0;char c = getchar();
	
	while(c < '0' || c > '9') c = getchar();
	
	while(c >= '0' && c <= '9'){x = x * 10 + (c ^ 48);c = getchar();}
	
	return x;
}

inline int Min(const int& a,const int& b){return a > b ? b : a;}

int n = Read(),m = Read(),ans,f[N + 42][M + 42],c[N + 42],a[N + 42][M + 42];

int main(){
    
    for(reg int i = 1; i <= n ; ++i)
    	for(reg int j = 0; j < m; ++j){
			a[i][j] = Read();
			c[i] += a[i][j];
			f[i][j] = Read();
		}
    		
    for(reg int i = 1,j = Read(),k,p; i <= n ; ++i){
		ans = (f[i][j] + ans) % mod;k = 0;
    	p = (f[i][j] - 1) % c[i] + 1;
    	while(k < p){
    		k += a[i][j];
            if (k == p) break;
            if ((++j) == m) j = 0;
		}
	}
	
	printf("%d",ans);
	
    return 0;
}
