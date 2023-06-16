# include <cstdio>
# define N 100
# define reg register

inline int Read()
{
	int x = 0;char c = getchar();
	
	while(c < '0' || c > '9') c = getchar();
	
	while(c >= '0' && c <= '9'){x = x * 10 + (c ^ 48);c = getchar();}
	
	return x;
}

inline int Min(const int& a,const int& b){return a > b ? b : a;}

int n = Read(),k = Read(),m = Read(),s = Read(),t = Read();
int f[N + 42][N + 42],c[N + 42],g[N + 42][N + 42];

int main(){
    
    for(reg int i = 1; i <= n; ++i)
        for(reg int j = 1;j <= n; ++j)
            f[i][j] = 0x7f7f7f;
    for(reg int i=1;i<=n;i++) c[i] = Read();
    
    for(reg int i=1;i<=k;i++)
        for(reg int j=1;j<=k;j++)
            g[i][j] = Read();
    
    for(reg int i = 1,aa,bb,cc;i <= m; ++i){
        aa = Read();bb = Read();cc = Read();
        if(!g[c[bb]][c[aa]] && c[bb] != c[aa]) f[aa][bb] = Min(f[aa][bb],cc);
        if(!g[c[aa]][c[bb]] && c[bb] != c[aa]) f[bb][aa] = Min(f[bb][aa],cc);
    }
    
    if(c[s] == c[t]){puts("-1");return 0;}
    
    for(reg int i = 1;i <= n; ++i)
        for(reg int j = 1;j <= n; ++j)
            if(i != j) for(reg int k = 1; k <= n ; ++k)
                    	if(j != k && i != k) if(f[i][k] + f[k][j] < f[i][j]) f[i][j] = f[i][k]+f[k][j];
    
    if(f[s][t] == 0x7f7f7f) puts("-1");
    else printf("%d\n",f[s][t]);
    
    return 0;
}
