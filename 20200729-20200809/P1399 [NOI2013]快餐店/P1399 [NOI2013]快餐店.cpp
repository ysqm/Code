# include <cstdio>
# include <algorithm>
# define reg register
# define N 200000

typedef long long LL;

inline int Read()
{
	int x = 0;char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch <= '9' && ch >= '0'){x = x*10 + (ch ^ 48);ch = getchar();}
	
	return x;
}

inline LL Max(const LL& a,const LL b){return a < b ? b : a;}
inline LL Min(const LL a,const LL b){return a < b ? a : b;}
inline LL ABS(const LL a){return a < 0 ? -a : a;}

struct edge
{
	int Next,to,wi;
	
	edge(const int Next_=0,const int To_=0,const int wi_=0):Next(Next_),to(To_),wi(wi_){}
} e[(N<<1) + 42];

bool vis[N + 42],Circle[N + 42];
int head[N + 42],edge_tot=1,f[N + 42],Wi[N + 42],dis[N + 42],n,Circle_Point[N + 42],cnt;
LL dp[N + 42],Pre[N + 42],Suf[N + 42],Pre_Best[N + 42],Suf_Best[N + 42],ans,Diameter;

inline void add_edge(const int wi,const int v,const int u)
{
	e[++edge_tot] = edge(head[u],v,wi);
	
	head[u] = edge_tot;
	
	e[++edge_tot] = edge(head[v],u,wi);
	
	head[v] = edge_tot;
}

void change(const int u,const int fa)
{
	for(reg int i = head[u]; i ; i = e[i].Next)
		if(e[i].to != fa && !Circle[e[i].to])
		{
			f[e[i].to] = i^1;
			
			change(e[i].to,u);
		}
}

void dfs_Circle(const int u,const int DE)
{
	for(reg int i = head[u]; i ; i = e[i].Next)
		if((i^1) != DE && !Circle[e[i].to])
		{
			if(f[e[i].to])
			{
				int v = u;
				
				do
				{
					Circle[v] = 1;
					
					Circle_Point[++cnt] = v;
					
					dis[cnt] = Wi[v];
					
					v = f[v];
					
				}while(v != e[i].to);
				
				Circle[v] = 1;
					
				Circle_Point[++cnt] = v;
					
				dis[cnt] = e[i].wi;
			}
			
			else {Wi[e[i].to] = e[i].wi;f[e[i].to] = u;dfs_Circle(e[i].to,i);}
			
		}
}

void dfs_Diameter(const int u,const int DE)
{
	for(reg int i = head[u]; i ; i = e[i].Next)
		if((i^1) != DE && !Circle[e[i].to])
		{
			dfs_Diameter(e[i].to,i);
			
			Diameter = Max(Diameter,dp[u] + dp[e[i].to] + e[i].wi);
			
        	dp[u] = Max(dp[u],dp[e[i].to] + e[i].wi);
		}
}

void Solve()//此处Pre 
{
	f[1] = 1;
	
	dfs_Circle(1,0);
	
	for(reg int i = 1; i <= cnt; ++i) dfs_Diameter(Circle_Point[i],0);
	
	LL Max_Ring_Chain = 0,tot_dis = 0;
	
	for(reg int i = 1; i <= cnt ; ++i)
	{
		tot_dis += dis[i-1];//此处记录的时到达当前节点的边的边权，所以减 1 
		
		Pre[i] = Max(Pre[i-1],tot_dis + dp[Circle_Point[i]]);
		
		Pre_Best[i] = Max(Pre_Best[i-1],tot_dis + Max_Ring_Chain + dp[Circle_Point[i]]);
		
		Max_Ring_Chain = Max(Max_Ring_Chain,dp[Circle_Point[i]] - tot_dis);	
	}
	
	LL temp = dis[cnt],This_Del_Ans;tot_dis = Max_Ring_Chain = dis[cnt] = 0;
	
	for(reg int i = cnt; i >= 1 ; --i)
	{
		tot_dis += dis[i];//这里求的是后缀，所以取原值
		
		Suf[i] = Max(Suf[i+1],tot_dis + dp[Circle_Point[i]]);
		
		Suf_Best[i] = Max(Suf_Best[i+1],tot_dis + Max_Ring_Chain + dp[Circle_Point[i]]);
		
		Max_Ring_Chain = Max(Max_Ring_Chain,dp[Circle_Point[i]] - tot_dis);
	}
	
	tot_dis = Pre_Best[cnt];
	
	for(reg int i = 1; i < cnt ; ++i)
	{
		This_Del_Ans = Max(Pre_Best[i],Suf_Best[i+1]);
		
		This_Del_Ans = Max(This_Del_Ans,Pre[i]+Suf[i+1]+temp);
		
		tot_dis = Min(tot_dis,This_Del_Ans);
	}
	
	Diameter = Max(tot_dis,Diameter);
	
	printf("%lld\n",Diameter);
}

int main()
{
	n = Read();
	
	for(reg int i = 1; i <= n ; ++i) add_edge(Read(),Read(),Read());
	
	Solve();
	
	return 0;
}
