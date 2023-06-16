# include <cstdio>
# include <cstring>
# include <algorithm>
# define N 500000
# define reg register

struct Heap
{
	int heap[N + 42],Size;//这里的 N 是宏定义的
	
	Heap(){memset(heap,0,sizeof(heap));Size = 0;}// 构造函数
	
	inline void Insert (const int key)
	{
		heap[++Size] = key;
		
		int father,i = Size;
		
		while((i >> 1)){
			father = i >> 1;
			
			if(heap[i] > heap[father]) break;
			
			heap[i] ^= heap[father] ^= heap[i] ^= heap[father];
			
			i = father;
		}
	}
	
	inline void maintain(const int increment)
	{
		int son,i = 1;heap[1] -= increment;
		
		while((i << 1) <= Size){
			son = i << 1;
			 
			if((son | 1) <= Size && heap[son | 1] < heap[son]) son |= 1;
			
			if(heap[i] < heap[son]) break;
			
			heap[i] ^= heap[son] ^= heap[i] ^= heap[son];
			
			i = son;
		}
	}
	
	inline int Get()
	{
		if(Size == 0) return -1;
		
		else if(Size == 1) return heap[Size--];
		
		heap[1] ^= heap[Size] ^= heap[1] ^= heap[Size];--Size;
		
		int son,i = 1;
		
		while((i << 1) <= Size){
			son = i << 1;
			 
			if((son | 1) <= Size && heap[son | 1] < heap[son]) son |= 1;
			
			if(heap[i] < heap[son]) break;
			
			heap[i] ^= heap[son] ^= heap[i] ^= heap[son];
			
			i = son;
		}
		
		return heap[Size + 1];
	}
} H;


inline int Read()
{
	int x = 0;char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch >= '0' && ch <= '9'){x = x*10 + (ch^48);ch = getchar();}
	
	return x;
}

struct Node
{
	int u,v;
} node[(N << 1) + 42];

inline bool comp(const Node& a,const Node& b){return a.v > b.v;}

struct edge
{
	int next,to;
} e[(N << 1) + 42];

bool circle[N + 42],vis[N + 42],inq[N + 42];
int head[N + 42],f[N + 42],edge_tot,n,m,ans[N + 42],cnt,root = 1;

inline void add_edge(const int& u,const int& v)
{
	e[++edge_tot] = (edge){head[u],v};
	
	head[u] = edge_tot;
}

void dfs(const int& u,const int& father)
{
	ans[++cnt] = u;
	
	for(reg int i = head[u]; i ; i = e[i].next)
		if(e[i].to != father) dfs(e[i].to,u);
}

void dfs_circle(const int& u,const int& father)
{
	
	
	for(reg int i = head[u]; i ; i = e[i].next)
		if(e[i].to != father && ! circle[e[i].to])
		{
			if(f[e[i].to])
			{
				int v = u;
				
				circle[v] = 1;
				
				while(v != e[i].to)
					circle[v = f[v]] = 1;
			}
			
			else dfs_circle(e[i].to,f[e[i].to] = u);
		}
}

int main()
{
	n = Read();m = Read();
	
	for(reg int i = 1; i <= m ; ++i) node[i].u = node[i+m].v = Read(),node[i].v = node[i+m].u = Read();
	
	std::sort(node+1,node+(m=m<<1)+1,comp);
	
	for(reg int i = 1; i <= m ; ++i) add_edge(node[i].u,node[i].v);
	
	if((m>>1) == n-1)
	{
		dfs(root,root);
		
		for(reg int i = 1; i <= cnt; ++i) printf("%d ",ans[i]);
	}
	
	else 
	{
		f[1] = 1;
		
		dfs_circle(root,root);
		
		H.Insert(root);
		
		inq[root] = 1;
		
		while(H.Size)
		{
			int u = H.Get();
			
			vis[ans[++cnt] = u] = 1;
			
			for(reg int i = head[u]; i ; i = e[i].next)
				if(!vis[e[i].to] && !inq[e[i].to]) H.Insert(e[i].to),inq[e[i].to] = 1; 
		}
		
		for(reg int i = 1; i <= cnt; ++i) printf("%d ",ans[i]);
	}
	
	return 0;
}
