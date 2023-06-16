# include <algorithm>
# include <utility>
# include <cstring>
# include <cstdio>
# include <queue>

# define reg register
# define M 7000000
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
	LL val;
	
	int Cut_Time;
	
	Node(){}
	
	Node(LL val_1,int Cut_Time_1) : val(val_1),Cut_Time(Cut_Time_1){}
	
	inline bool operator > (const Node b) const
	{
		return val > b.val;
	}
};

struct Heap
{
	Node heap[M + N + 42];
	
	int Size;
	
	inline void Insert (Node& TTT)
	{
		heap[++Size] = TTT;
		
		int father,i = Size;
		
		while((i >> 1)){
			father = i >> 1;
			
			if(heap[father] > heap[i]) break;
			
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
			 
			if((son | 1) <= Size && heap[son | 1] > heap[son]) son |= 1;
			
			if(heap[i] > heap[son]) break;
			
			Swap(heap[son],heap[i]);
			
			i = son;
		}
		
		return heap[Size + 1];
	}
};

struct Binary_Heap
{
	Heap Main_Heap,Left_Heap,Right_Heap;
	
	# define m Main_Heap
	# define l Left_Heap
	# define r Right_Heap
	
	
	
	# undef Main_Heap
	# undef Left_Heap
	# undef Right_Heap
};
inline int Max(const int& a,const int b){return a > b ? a : b;}

int n,m,u,q,v,t;

inline void INIT()
{
	n = Read();m = Read();q = Read();u = Read();v = Read();t = Read();
	
	for(reg int i = 1; i <= n ; ++i) 
}


int main()
{
	INIT();
	
	Ans();
	
	return 0;
}
