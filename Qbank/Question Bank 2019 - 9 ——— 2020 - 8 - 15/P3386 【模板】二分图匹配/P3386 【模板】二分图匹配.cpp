# include <cstdio>
# include <cstring>
# define N 100000
# define reg register
using namespace std;

template <typename T>
inline T in(T& x)
{
	x = 0;char c = getchar();
	
	while(c < '0' || c > '9') c = getchar();
	
	while(c >= '0' && c <= '9'){x = (x << 3) + (x << 1) +c - 48;c = getchar();}
} 

template <typename T>
inline T min(const T A,const T B){return A < B ? A : B;} 

inline int Read()
{
	int x = 0,f = 1;char c = getchar();
	
	while(c < '0' || c > '9') {if(c == '-') f = -1;c = getchar();}
	
	while(c >= '0' && c <= '9'){x = (x << 3) + (x << 1) +c - 48;c = getchar();}
	
	return x * f;
}

struct Edge
{
	int from,to,start;
} e[2000042];

bool vis[2042];
int edge_tot,head[2042],n,m,E,match[2042],ans;

inline void add_edge(const int& v,const int& u)
{
	e[++edge_tot].from = head[u];
	
	e[edge_tot].to = v;
	
	e[edge_tot].start = u;
	
	head[u] = edge_tot;
	
	e[++edge_tot].from = head[v];
	
	e[edge_tot].to = u;
	
	e[edge_tot].start = v;
	
	head[v] = edge_tot;
}

inline bool dfs(const int u)
{
	for(reg int i = head[u] ; i ; i = e[i].from){
		if(!vis[e[i].to]){
			vis[e[i].to] = true;
			
			if(match[e[i].to] == 0 || dfs(match[e[i].to])){
				
				match[e[i].to] = u;
				match[u] = e[i].to;
				
				return true;
			}
		}
	}
	return false;
}

int main()
{
	//freopen("P3386_1.in","r",stdin);
	
	n = Read();m = Read();E = Read();
	
	for(reg int i = 1,u,v ; i <= E ; ++i ){
		
		u = Read();v = Read();
		
		if(u <= n && v <= m && u >= 1 && v >= 1) add_edge(u,v + n);
	}
		
	for(reg int i = 1 ; i <= n ; ++i ){
		
		memset(vis,0,sizeof(vis));
		
		if(dfs(i)) /*{*/++ans;
			//printf("µÚ%d´Î %d\n",i,ans);
		//}
	}
	
	printf("%d",ans);
	
	return 0;	
}
