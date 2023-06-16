# include <cstdio>
# define reg register
# define N 2000
# define V 300
# define inf 1e9 + 5;
# define Inf 1000000000
using namespace std;

inline int Read()
{
	int x = 0;char c = getchar();
	
	while(c < '0' || c > '9') c = getchar();
	
	while(c >= '0' && c <= '9'){x = (x << 3) + (x << 1) + (c ^ 48);c = getchar();}
	
	return x;
}

inline int Min_int(const int& a,const int b){return a > b ? b : a;}
inline double Min(const double a,const double b){return a > b ? b : a;}
inline int show();

int n,m,v,e,dis[V + 42][V + 42],c[N + 42][2];
double ans,f[N + 42][N + 42][2],k[N + 42];

int main()
{
	freopen("P1850_2.in","r",stdin);
	
	scanf("%d%d%d%d",&n,&m,&v,&e);
	
	for(reg int i = 1; i <= n; ++i) c[i][0] = Read();
	
	for(reg int i = 1; i <= n; ++i) c[i][1] = Read();
	
	for(reg int i = 1; i <= n; ++i) scanf("%lf",&k[i]);
	
	for(reg int i = 1; i <= v; ++i){
		for(reg int j = 1; j <= v; ++j)
			dis[i][j] = Inf;
		dis[i][i] = 0;
	}
	
	for(reg int i = 1,a,b; i <= e; ++i) dis[a = Read()][b = Read()] = dis[b][a] = Min_int(Read(),dis[a][b]);
	
	for(reg int kn = 1; kn <= v; ++kn)
		for(reg int i = 1; i <= v; ++i)
			for(reg int j = 1; j <= v; ++j)
				dis[i][j] = Min_int(dis[i][j],dis[i][kn] + dis[kn][j]);
	
	for(reg int i = 1; i <= n; ++i)
		for(reg int j = 0; j <= m; ++j)
			f[i][j][0] = f[i][j][1] = inf;
	
	f[1][0][0] = f[1][1][1] = 0;
	
	for(reg int i = 2; i <= n; ++i){
		f[i][0][0] = f[i - 1][0][0] + dis[c[i - 1][0]][c[i][0]];
		
		for(reg int j = 1; j <= Min(i,m); ++j){
			f[i][j][0] = Min(f[i - 1][j][0] + dis[c[i - 1][0]][c[i][0]],
                             f[i - 1][j][1] + dis[c[i - 1][1]][c[i][0]] * k[i - 1] + dis[c[i - 1][0]][c[i][0]] * (1 - k[i - 1]));
			f[i][j][1] = Min(f[i - 1][j - 1][0] + dis[c[i - 1][0]][c[i][1]] * k[i] + dis[c[i - 1][0]][c[i][0]] * (1 - k[i]),
                             f[i - 1][j - 1][1] + dis[c[i - 1][1]][c[i][1]] * k[i] * k[i - 1] + 
                             dis[c[i - 1][0]][c[i][1]] * (1 - k[i - 1]) * k[i] + 
                             dis[c[i - 1][1]][c[i][0]] * k[i - 1] * (1 - k[i]) + 
                             dis[c[i - 1][0]][c[i][0]] * (1 - k[i - 1]) * (1 - k[i]));}
			
	}
	
	double ans = f[n][0][0];
	
	for(reg int i = 1; i <= m; ++i) ans = Min(ans,Min(f[n][i][0],f[n][i][1]));
	
	printf("%.2lf",ans);
	
	return 0;
}

inline int show()
{
	for(reg int i = 1; i <= v; ++i){
		for(reg int j = 1; j <= v; ++j)
			printf("%-10d ",dis[i][j]);
		printf("\n");
	}
}
