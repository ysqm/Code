# include <cstdio>
# include <algorithm>
# define N 10000
# define reg register
using namespace std;

inline int Max(const int a,const int b){return a > b ? a : b;}

inline int Read()
{
	int x = 0;char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch <= '9' && ch >= '0'){x = x*10+(ch^48);ch = getchar();}
	
	return x; 
}

struct edge
{
	int Next,to,wi;
	
	edge(const int Next_=0,const int To_=0,const int wi_=0):Next(Next_),to(To_),wi(wi_){}
} e[(N<<1) + 42];

bool vis[N + 42],It_is_OK[142];
int head[N + 42],edge_tot;
int g[N + 42],Size[N + 42];
int rt,dis[N + 42],id[N + 42];
int top,color[N + 42],Query[142],n,m;


inline void add_edge(const int wi,const int v,const int u)
{
	e[++edge_tot] = edge(head[u],v,wi);
	
	head[u] = edge_tot;
	
	e[++edge_tot] = edge(head[v],u,wi);
	
	head[v] = edge_tot;
}

inline bool comp(const int a__,const int b__){return dis[a__] < dis[b__];}

void Getgc(const int u,const int fa,const int U)
{
	Size[u] = 1;g[u] = 0;
	
	for(reg int i = head[u]; i ; i = e[i].Next)
		if(e[i].to != fa && !vis[e[i].to])
		{
			Getgc(e[i].to,u,U);
			
			Size[u] += Size[e[i].to];
			
			g[u] = Max(g[u],Size[e[i].to]);
		}
	
	g[u] = Max(g[u],U-Size[u]);
	
	if(g[u] < g[rt]) rt = u;
}

int Getdis(const int u,const int fa,const int diss,const int col)
{
	id[++top] = u;
	color[u] = col;
	dis[u] = diss;
	
	for(reg int i = head[u]; i ; i = e[i].Next)
		if(e[i].to != fa && !vis[e[i].to]) 
			Getdis(e[i].to,u,diss + e[i].wi,col);
}

void Calc(const int u)
{
	id[top = 1] = u;dis[u] = 0;color[u] = u;
	
	for(reg int i = head[u]; i ; i = e[i].Next)
		if(!vis[e[i].to]) Getdis(e[i].to,u,e[i].wi,e[i].to);
		
	std::sort(id+1,id+top+1,comp);
	
	for(reg int k = 1; k <= m ; ++k)
		if(!It_is_OK[k])
		{
			reg int l = 1,r = top;
			
			while(l < r)
			{
				if(dis[id[l]] + dis[id[r]] > Query[k]) --r;
				else if(dis[id[l]] + dis[id[r]] < Query[k]) ++l;
				else if(color[id[l]] == color[id[r]])
				{
					if(dis[id[r]] == dis[id[r-1]])r--;
					else l++;
				}
				else
				{
					It_is_OK[k] = 1;
					break;
				}
			}
		}
}

void PDC(const int u)
{
	vis[u] = 1;
	
	Calc(u);
	
	for(reg int i = head[u] ; i ; i = e[i].Next)
		if(!vis[e[i].to])
		{
			rt = 0;
			Getgc(e[i].to,0,Size[e[i].to]);
			PDC(rt);
		}
}

int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	
	n = Read();m = Read();
	
	for(reg int i = 1; i < n ; ++i) add_edge(Read(),Read(),Read());
	
	for(reg int i = 1; i <= m ; ++i) (Query[i] = Read()) == 0 ? It_is_OK[i] = 1 : It_is_OK[i] = 0;
	
	g[0] = n;
	
	Getgc(1,0,n);
	
	PDC(rt);
	
	for(reg int i = 1; i <= m ; ++i)//case %d:,i 
		if(It_is_OK[i]) printf("AYE\n");//puts("AYE");
		else printf("NAY\n");//puts("NAY");
			
	return 0;
} 
