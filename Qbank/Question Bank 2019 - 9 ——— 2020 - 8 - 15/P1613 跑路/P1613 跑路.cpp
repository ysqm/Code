# include <cstdio>
# include <algorithm>
# define M 10000
# define R register
# define inf 210000000
using namespace std;

int r()
{
	int x = 0;
	
	char c = getchar();
	
	while(c > '9' || c < '0'){
		c = getchar();
	}
	
	while(c >= '0' && c <= '9'){
		x = (x << 3) + (x << 1) + c - '0';
		
		c = getchar();
	}
	
	return x;
}

int dis[42 * 2][42 * 2],x,y,n,m;
bool G[42 * 2][42 * 2][42 * 2];

int main()
{
	freopen("1.in","r",stdin); 
	n = r(); m = r();
	
	for(R int i = 1; i <= n; i++)
		for(R int j = 1; j <= n ; j++)
			dis[i][j] = inf;
				
	while(m--){
		x = r(); y = r();
		dis[x][y] = 1;
		G[x][y][0] = true;
	} 
	
	for(R int k = 1; k <= 64 ; k++)
		for(R int u = 1; u <= n; u++)
			for(R int j = 1; j <= n; j++)
				for(R int v = 1; v <= n; v++)
					if(G[u][j][k - 1] && G[j][v][k - 1]) {
						G[u][v][k] = true;
						dis[u][v] = 1;
					}
	
	for(R int k = 1; k <= n ; k++)
		for(R int i = 1; i <= n; i++)
			for(R int j = 1; j <= n ; j++)
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
	
	printf("%d",dis[1][n]);
	
	return 0;
}
