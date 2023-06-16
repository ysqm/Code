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
	int from,to;
} e[2000042];

bool vis[20100];
int edge_tot,head[20100],nn,n,match[20100],ans;

inline void add_edge(reg const int& u,reg const int& v)
{
	e[++edge_tot].from = head[u];
	
	e[edge_tot].to = v;
	
	head[u] = edge_tot;

}

inline bool dfs(reg const int u)
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
	
	n = Read();nn = n << 1;
	
	for(reg int i = 1,u,v ; i <= nn ; ++i ){
		
		u = Read();v = Read();
		
		add_edge(i,u + n * 3);
		add_edge(i,v + n * 4);
		add_edge(i,u + n * 4);
		add_edge(i,v + n * 3);

	}
		
	for(reg int i = 1 ; i <= nn ; ++i ){
		
		memset(vis,0,sizeof(vis));
		
		if(dfs(i)) ++ans;
	}
	
	printf("%d",ans);
	
	return 0;	
}
