# include <cstdio>
# include <algorithm>
# define R register
# define I inline
# define N 300
# define M 100000
# define inf 1000000000
using namespace std;
I int re()
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
int n,m,head[N + 42],g[N + 42][N + 42],t[N + 42],k,Q;
I void dp(int a)
{
	for(/*分解folyd*/; k < a ; k++)
		 for(R int i = 0; i < n ; i++)
			 for(R int j = 0;j < n ; j++)
				g[i][j] = min(g[i][j],g[i][k] + g[k][j]);
}
int main()
{
	n = re();
	m = re();
	
	for(R int i = 0;i < n; i++ ) t[i] = re();
	
	t[n] = inf;
	
	for(R int i = 0;i < n; i++ )
		for(R int j = 0;j < n; j++ )
			g[i][j] = inf;//初始化 
	
	for(R int i = 0;i < n; i++ ) g[i][i] = 0;//对角线置零 
	
	for(R int i = 1,a,b;i <= m; i++ )
		g[a = re()][b = re()] = g[b][a] = re();//这有问题要改 
	
	Q = re();
	
	int x,y,c,nowt = 0;
	
	while(Q--){
		x = re();
		y = re();
		c = re();
		while(c >= t[nowt]) nowt++;
		dp(nowt);
		if(g[x][y] != inf && t[x] <= c && t[y] <= c) printf("%d\n",g[x][y]);
		else printf("-1\n");
	} 
	return 0;
}
