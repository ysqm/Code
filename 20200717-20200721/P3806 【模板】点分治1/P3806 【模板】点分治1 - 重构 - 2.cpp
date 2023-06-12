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
int rt,dis[N + 42],id[N + 42],color[N + 42];
int tot,Query[142],n,m;

inline void add_edge(const int wi,const int v,const int u)
{
	e[++edge_tot] = edge(head[u],v,wi);
	
	head[u] = edge_tot;
	
	e[++edge_tot] = edge(head[v],u,wi);
	
	head[v] = edge_tot;
}

void Get_gc(const int u,const int fa,const int Size_root)
{
	Size[u] = 1;g[u] = 0;
	
	for(reg int i = head[u]; i ; i = e[i].Next)
		if(e[i].to != fa && !vis[e[i].to])
		{
			Get_gc(e[i].to,u,Size_root);
			
			Size[u] += Size[e[i].to];
			
			g[u] = Max(g[u],Size[e[i].to]);
		}
	
	g[u] = Max(g[u],Size_root - Size[u]);
	
	if(g[u] < g[rt] || rt == 0) rt = u;
}

void Get_dis(const int u ,const int fa,const int diss,const int col)
{
	id[++tot] = u;color[u] = col;dis[u] = diss;
	
	for(reg int i = head[u]; i ; i = e[i].Next)
		if(e[i].to != fa && !vis[e[i].to]) Get_dis(e[i].to,u,diss+e[i].wi,col);
}


inline bool comp(const int x,const int y){return dis[x] < dis[y];} 

void Check_ans(const int u)
{
	dis[u] = 0;
	id[tot = 1] = u;
	color[u] = u;
	
	for(reg int i = head[u]; i ; i = e[i].Next)
		if(!vis[e[i].to]) Get_dis(e[i].to,u,e[i].wi,e[i].to);
	
	/*if(u == 100)
		for(reg int i = 1; i <= n ; ++i)
			if(color[i]) printf("Point %d color = %d\n",i,color[i]);*/
	
	sort(id + 1,id + tot + 1,comp);
	
	for(reg int i = 1; i <= m ; ++i)
		if(!It_is_OK[i])
		{
			reg int l = 1,r = tot;
			
			while(l < r)
			{
				if(dis[id[l]] + dis[id[r]] > Query[i]) --r;
				else if(dis[id[l]] + dis[id[r]] < Query[i]) ++l;
				else if(color[id[l]] == color[id[r]])
				{
					if(dis[id[r]] == dis[id[r-1]]) --r;
					else ++l;
				}
				else
				{
					It_is_OK[i] = true;
					break;
				}
			}
		}
}

void Starch_Qualityr(const int u)
{
	vis[u] = 1;
	Check_ans(u);
	
	for(reg int i = head[u]; i ; i = e[i].Next)
		if(!vis[e[i].to])
		{
			rt = 0;
			
			Get_gc(e[i].to,0,Size[e[i].to]);
			
			Starch_Qualityr(rt);
		}
}

int main()
{
	freopen("P3806_3.in","r",stdin);
	freopen("fuck.txt","w",stdout);
	
	n = Read();m = Read();
	
	for(reg int i = 1; i < n ; ++i) add_edge(Read(),Read(),Read());
	
	for(reg int i = 1; i <= m ; ++i) Query[i] = Read();
	
	g[0] = n;rt = 0;
	
	Get_gc(1,0,n);
	
	Starch_Qualityr(rt);
	
	for(reg int i = 1; i <= m ; ++i)
		if(It_is_OK[i]) puts("AYE");//printf("case %d: AYE\n",i);
		else puts("NAY");
		/*if(It_is_OK[i]) printf("case %d: AYE\n",i);//puts("AYE");
		else printf("case %d: NAY\n",i);*/
			
	return 0;
} 
