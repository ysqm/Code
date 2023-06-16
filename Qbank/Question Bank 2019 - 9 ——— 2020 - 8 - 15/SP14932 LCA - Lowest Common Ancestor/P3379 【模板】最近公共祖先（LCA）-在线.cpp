# include <cstdio>
# include <algorithm>
# include <cmath>
# define N 1000
# define M 1000
# define R register
using namespace std;

inline int r()
{
	int f = 1,x = 0;;
	
	char c = getchar();
	
	while(c > '9' || c < '0'){
		if(c == '-') f = -1;
		
		else f = 1;
		
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
	int from,to;
} e[(M << 1) + 42];

int head[N + 42],e_cnt,n,m,f[N + 42][20],s,deep[N + 42],maxstep,T;

bool vis[N + 42];

inline void add(int u,int v)
{
	e[++e_cnt].from = head[u];
	
	e[e_cnt].to = v;
	
	//e[e_cnt].wi = wi;
	
	head[u] = e_cnt;
}

inline void dfs(int u,int fa)
{
	
	for(R int j = 1; (1 << j) <= deep[u]; j++)
		f[u][j] = f[f[u][j - 1]][j - 1];
	
	for(int i = head[u]; i ; i = e[i].from)
		if(deep[e[i].to] == 0) {
			
			f[e[i].to][0] = u;
			
			deep[e[i].to] = deep[u] + 1;
			
			dfs(e[i].to,u);
		}
		
}

inline void work(int x,int y)
{
	if(deep[x] < deep[y]){
		int temp;
		
		temp = x;
		
		x = y;
		
		y = temp;
	}
	
	int deth = deep[x] - deep[y];
	
	if(deth)
		for(R int i = maxstep; i >= 0 ; i--)
			if((1 << i) & deth) x = f[x][i];
				
	if(x == y) {
		printf("%d\n",y);
		
		return ;
	}
	
	for(R int i = maxstep; i >= 0; i--)
		if(f[x][i] != f[y][i]){
			x = f[x][i];
			y = f[y][i];
		}
		
	printf("%d\n",f[x][0]);
}

int main()
{
	T = r();
	for(R int cas = 1; cas <= T ; cas++){
		e_cnt = 0;
		
		n = r();
		
		for(R int ie = 1,a; ie <= n ; ie++){
			m = r();
			if(m)
				while(m--){
					a = r();
					vis[a] = 1;
					add(ie,a);
				}
		}
	
		for(R int ie = 1; ie <= n ; ie++)
			if(!vis[ie]){
				s = ie;
				break;
			}
	
		maxstep = log2(n--) + 1;
	
		deep[s] = 1;
	
		dfs(s,0);
		
		m = r();
		
		printf("Case %d:\n",cas);
		
		while(m--) work(r(),r());
		
		for(R int i = 1; i <= n; i ++) vis [i] = head[i] = 0;
	}
	
	
	return 0;
} 
