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

struct Node
{
	int dis,color;
	
	Node(const int dis_=0,const int color_=0):dis(dis_),color(color_){}
	
	friend bool operator < (const Node& a,const Node& b){return a.dis < b.dis;}
	
} t[N + 42];

bool vis[N + 42],It_is_OK[142];
int head[N + 42],edge_tot;
int g[N + 42],Size[N + 42];
int rt;
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
	
	if(g[u] < g[rt]) rt = u;
}

void Get_dis(const int u ,const int fa,const int col)
{
	t[++tot].color = col;
	
	for(reg int i = head[u]; i ; i = e[i].Next)
		if(e[i].to != fa && !vis[e[i].to])
		{
			t[e[i].to].dis = t[u].dis + e[i].wi;
			
			Get_dis(e[i].to,u,col);
		}
}

void Check_ans(const int u)
{
	t[tot = 1] = Node(0,u);
	
	for(reg int i = head[u]; i ; i = e[i].Next)
		if(!vis[e[i].to])
		{
			t[e[i].to].dis = e[i].wi;
			
			Get_dis(e[i].to,u,e[i].to);
		}
	
	sort(t + 1,t + tot + 1);
	
	for(reg int i = 1; i <= m ; ++i)
		if(!It_is_OK[i])
		{
			reg int l = 1,r = tot;
			
			while(l < r)
			{
				if(t[l].dis + t[r].dis > Query[i]) --r;
				else if(t[l].dis + t[r].dis < Query[i]) ++l;
				else if(t[l].color == t[r].color)
				{
					if(t[r].dis == t[r-1].dis) --r;
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
	//freopen("1.in","r",stdin);
	//freopen("fuck.txt","w",stdout);
	
	n = Read();m = Read();
	
	for(reg int i = 1; i < n ; ++i) add_edge(Read(),Read(),Read());
	
	for(reg int i = 1; i <= m ; ++i) It_is_OK[i] = (((Query[i] = Read()) == 0) ? 1 : 0);
	
	g[0] = n+1;rt = 0;
	
	Get_gc(1,0,n);
	
	Starch_Qualityr(rt);
	
	for(reg int i = 1; i <= m ; ++i)
		if(It_is_OK[i]) puts("AYE");//printf("case %d: AYE\n",i);
		else puts("NAY");//printf("case %d: NAY\n",i);
			
	return 0;
} 
