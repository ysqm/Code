# include <utility>
# include <cstring>
# include <cstdio>
# include <queue>

# define reg register
# define N 100000
# define LL long long

inline int Read()
{
	int x = 0,f = 1;char ch = getchar();
	
	while(ch < '0' || ch > '9'){if(	ch == '-') f = -1;ch = getchar();}

	while(ch >= '0' && ch <= '9'){x = x * 10 + (ch ^ 48);ch = getchar();}
	
	return x * f;
}

template<class T>
inline void Swap(T &a,T &b){T x;x = a;a = b;b = x;}

struct Node
{
	int Sum,A_id,B_id;
	
	inline bool operator < (const Node& a)const
	{
		return Sum < a.Sum;
	}
	
	Node(){};
	
	Node(int Sum_,int A_id_,int B_id_) : Sum(Sum_),A_id(A_id_),B_id(B_id_){}
};

struct Heap
{
	//# define Node int
	
	Node heap[N + 42];
	
	int Size;
	
	inline void Insert (const Node TTT)
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
	
	/*inline void maintain(const int increment)
	{
		int son,i = 1;heap[1] -= increment;
		
		while((i << 1) <= Size){
			son = i << 1;
			 
			if((son | 1) <= Size && heap[son | 1] < heap[son]) son |= 1;
			
			if(heap[i] < heap[son]) break;
			
			heap[i] ^= heap[son] ^= heap[i] ^= heap[son];
			
			i = son;
		}
	}*/
	
	inline Node Get()
	{
		if(Size == 0) return Node(-1,-1,-1);
		
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
	
	//# undef Node
} H;

inline int Max(const int& a,const int b){return a > b ? a : b;}

std::queue <int> q;
bool vis[N + 42];
int head[N + 42],tot_edge,A[N + 42],B[N + 42],n;

inline void INIT()
{
	n = Read();
	
	for(reg int i = 1; i <= n ; ++i) A[i] = Read();

	for(reg int i = 1; i <= n ; ++i) B[i] = Read();
	
	for(reg int i = 1; i <= n ; ++i) 
		H.Insert(Node(A[i] + B[1],i,1));
}

inline void Ans()
{
	Node u;
	
	for(reg int i = 1; i <= n ; ++i)
	{
		u = H.Get();
		
		printf("%d ",u.Sum);
		
		H.Insert(Node(A[u.A_id] + B[1 + u.B_id],u.A_id,u.B_id + 1));
	}
}

int main()
{
	INIT();
	
	Ans();
	
	return 0;
}
