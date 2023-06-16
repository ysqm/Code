/*
5 1
0 -1 -2 -3 -4
0 0 0 0 0
*/
# include <cstdio>
# include <cstring>
# include <queue>
# define reg register
# define LL long long
# define N 1000000

inline int Read()
{
	int x = 0,f = 1;char ch = getchar();
	
	while(ch <= '0' || ch > '9') {if(ch == '-') f = -1;ch = getchar();}
	
	while(ch >= '0' && ch <= '9'){x = x * 10 + (ch ^ 48);ch = getchar();}
	
	return f == -1 ? -x : x;
}

inline LL ReadL()
{
	LL x = 0,f = 1;char ch = getchar();
	
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1;ch = getchar();}
	
	while(ch >= '0' && ch <= '9'){x = x * 10 + (ch ^ 48);ch = getchar();}
	
	return f == -1 ? -x : x;
}

struct node {
	LL w;
	int k;

	node() {}
	node(const LL w,const int k):w(w), k(k) {}

	friend bool operator < (const node a,const node b) { return a.w > b.w; }
};

template<class T>
inline void Swap(T& a,T& b){T c;c = a;a = b;b = c;}

struct Heap
{
	node heap[N + 42];
	int Size;//这里的 N 是宏定义的
	
	Heap(){memset(heap,0,sizeof(heap));Size = 0;}// 构造函数
	
	inline void Insert (const node key)
	{
		heap[++Size] = key;
		
		int father,i = Size;
		
		while((i >> 1)){
			father = i >> 1;
			
			if(heap[i] < heap[father]) break;
			
			Swap(heap[i],heap[father]);
			
			i = father;
		}
	}
	
	inline node Get()
	{
		if(Size == 0) return node();
		
		else if(Size == 1) return heap[Size--];
		
		Swap(heap[1],heap[Size--]);
		
		int son,i = 1;
		
		while((i << 1) <= Size){
			son = i << 1;
			 
			if((son | 1) <= Size && heap[son] < heap[son| 1]) son |= 1;
			
			if(heap[son] < heap[i]) break;
			
			Swap(heap[i],heap[son]);
			
			i = son;
		}
		
		return heap[Size+1];
	}
} q;

int n,k,a[N + 42];
LL ans,w[N + 42],cur;

int main()
{
	n = Read();k = Read();
	
	for(reg int i = 1; i <= n ; ++i) 
		a[i] = Read();
	
	for(reg int i = 1; i <= n ; ++i) 
		w[i] = ReadL();
	
	for(reg int i = n; i > 0 ; --i) w[i] += w[i+1];
	
	for(reg int i = 1; i <= n ; ++i)
	{
		if(w[i] >= 0){cur += k;ans += k * w[i];q.Insert(node(w[i],k << 1));}
		else {ans -= k * w[i];cur -= k;}
		
		while(cur > a[i] && q.Size)
		{
			node x = q.Get();
			
			int t = cur - a[i] < x.k ? cur - a[i] : x.k;
			
			ans -= t * x.w;
			
			cur -= t;
			
			if((x.k -= t)) q.Insert(x);
		}
	}
	
	printf("%lld\n",ans);
	
	return 0;
}
