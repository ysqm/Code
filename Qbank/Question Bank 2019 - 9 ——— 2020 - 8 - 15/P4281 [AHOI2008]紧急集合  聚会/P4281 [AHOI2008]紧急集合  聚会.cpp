# include <cstdio>
# include <algorithm>
# include <cmath>
# define N 500000
# define M 500000
# define R register
# define Q 30000
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
} e[M * 2 + 42];

int head[N + 42],e_cnt,n,m,f[N + 42][20],s,deep[N + 42],maxstep = 19;

inline void add(int u,int v/*,int wi*/)
{
	e[++e_cnt].from = head[u];
	
	e[e_cnt].to = v;
	
	//e[e_cnt].wi = wi;
	
	head[u] = e_cnt;
	
	e[++e_cnt].from = head[v];
	
	e[e_cnt].to = u;
	
	//e[e_cnt].wi = wi;
	
	head[v] = e_cnt;
	
}

void dfs(int u)
{
	
	for(R int j = 1; (1 << j) <= deep[u]; j++) f[u][j] = f[f[u][j - 1]][j - 1];
	
	for(int i = head[u]; i ; i = e[i].from)
		if(deep[e[i].to] == 0) {
			
			f[e[i].to][0] = u;
			
			deep[e[i].to] = deep[u] + 1;
			
			dfs(e[i].to);
		}
}

int temp;

int LCA(int x,int y)
{
	if(deep[x] < deep[y]){
		
		temp = x;
		
		x = y;
		
		y = temp;
	}
	
	int deth = deep[x] - deep[y];
	
	if(deth)
		for(R int j = maxstep; j >= 0 ; j--)
			if((1 << j) & deth) {
				x = f[x][j];
			}
				
	if(x == y) 	return x;
	
	for(R int i = maxstep; i >= 0; i--)
		if(f[x][i] != f[y][i]){
			x = f[x][i];
			y = f[y][i];
		}
		
	if(f[x][0] == f[y][0]) return f[x][0];
}

int main()
{
	//freopen("2.in","r",stdin);
	n = r();m = r();
	
	for(R int i = 1; i < n; i++) add(r(),r());
	
	deep[1] = 1;
	
	dfs(1);
	
	int ans,a,b,c,xy,yz,xz,xyz;
	
	while(m--){
		a = r(); b = r(); c = r();
		
		xz = LCA(a,c);
		
		yz = LCA(b,c);
		
		xy = LCA(a,b);
		
		if(xz == yz)
			xyz = xy;
		
			else if(xy == yz)
				xyz = xz;
				
			else if(xy == xz)
				xyz = yz;
		
		ans = deep[a] + deep[b] + deep[c] - deep[xz] - deep[yz] - deep[xy];
		
		printf("%d %d\n",xyz,ans);
	}
	
	return 0;
} 
