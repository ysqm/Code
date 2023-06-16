# include <utility>
# include <cstring>
# include <cstdio>
# include <queue>

# define reg register
# define N 2500000
# define M 10000000
# define LL long long

inline int Read()
{
	int x = 0,f = 1;char ch = getchar();
	
	while(ch < '0' || ch > '9'){if(	ch == '-') f = -1;ch = getchar();}

	while(ch >= '0' && ch <= '9'){x = x * 10 + (ch ^ 48);ch = getchar();}
	
	return x * f;
}

struct Node
{
	int id;
	
	LL val;
	
	Node() {}
	Node(int id_1,LL val_1) : id(id_1) , val(val_1) {}
	
	bool operator < (const Node &b) const
	{
		return val > b.val;
	}
} cr;

template<class T>
inline void Swap(T &a,T &b){T x;x = a;a = b;b = x;}

struct Heap
{
	Node heap[M * 10 + 42];
	
	int Size;
	
	inline void Insert (Node& TTT)
	{
		heap[++Size] = TTT;
		
		int father,i = Size;
		
		while((i >> 1)){
			father = i >> 1;
			
			if(heap[father] < heap[i]) break;
			
			Swap(heap[i],heap[father]);
			
			i = father;
		}
	}
	
	inline Node top(){return heap[1];}
	
	inline Node Get()
	{
		if(Size == 0) return Node(-1,-1);
		
		else if(Size == 1) return heap[Size--];
		
		Swap(heap[Size--],heap[1]);
		
		int son,i = 1;
		
		while((i << 1) <= Size){
			son = i << 1;
			 
			if((son | 1) <= Size && heap[son | 1] < heap[son]) son |= 1;
			
			if(heap[i] < heap[son]) break;
			
			Swap(heap[son],heap[i]);
			
			i = son;
		}
		
		return heap[Size + 1];
	}
} H;

struct edge
{
	int next,to,wi;
} e[(M << 1) + 42];

inline int Max(const int& a,const int b){return a > b ? a : b;}

std::queue <int> q;
bool vis[N + 42];
int head[N + 42],tot_edge,stack[N + 42],pre[N + 42],n,p,s,t;
LL dis[N + 42];

inline void add_edge(const int u,const int v,const int wi)
{
	e[++tot_edge] = (edge){head[u],v,wi};
	
	head[u] = tot_edge;
}

int main()
{
	n = Read();reg int m = Read(),x,y,z;p = Read();s = Read();t = Read();
	
	while(m--)
	{
		x = Read();y = Read();z = Read();
		
		for(reg int i = 0; i < p ; ++i) add_edge(i * n + x,((i + z) % p) * n + y,z);
	}
	
	memset(dis,0x3f,sizeof(dis));
	
    dis[s] = 0;
    
    H.Insert(cr = Node{s,0});
    
    while (H.Size)
    {
        while (H.Size && vis[H.top().id]) H.Get();
        
        if (H.Size == 0) break;
        
        Node u = H.Get();
        
        if (u.id == t) break;
        
        vis[u.id] = 1;
        
        for (reg int i = head[u.id] ; i ; i = e[i].next)
			if(dis[e[i].to] > dis[u.id] + e[i].wi)
        	{
           		cr.val = -(dis[cr.id = e[i].to] = dis[u.id] + e[i].wi);
           		
            	pre[e[i].to] = u.id;
            	
            	H.Insert(cr);
        	}
    }
	
	if (dis[t] == dis[0]) puts("jjc fails in travelling");
	
    else {
    	printf("%lld\n",dis[t]);
    	
    	reg int tp = 0;
    	
		stack[++tp] = t;
    
		while (pre[t]) stack[++tp] = (t = pre[t]);
    	
		while (tp > 1) printf("%d->",(stack[tp--] - 1) % n + 1);
    	
		printf("%d\n",(stack[tp] - 1) % n + 1);
	}
	
	return 0;
}
