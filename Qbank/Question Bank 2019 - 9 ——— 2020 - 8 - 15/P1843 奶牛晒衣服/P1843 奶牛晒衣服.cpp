/*
	Name : Common_Heap
	code by : ‘∆ÀÍ‘¬ È
	Time : 2020/1/20/15:03
*/
# include <cstdio>
# include <queue>
# include <cstring>
# define N 500000
# define reg register
using namespace std;

template <typename T> 
inline void in(T& x)
{
	x = 0;
	char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}
}

inline int Read()
{
	int x = 0;char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}
	
	return x;
}

struct Heap
{
	int heap[N + 42],Size;
	
	Heap(){memset(heap,0,sizeof(heap));Size = 0;}
	
	inline void Insert (const int key)
	{
		heap[++Size] = key;
		
		int father,i = Size;
		
		while((i >> 1)){
			father = i >> 1;
			
			if(heap[i] < heap[father]) break;
			
			heap[i] ^= heap[father] ^= heap[i] ^= heap[father];
			
			i = father;
		}
	}
	
	inline void maintain(const int increment)
	{
		int son,i = 1;heap[1] -= increment;
		
		while((i << 1) <= Size){
			son = i << 1;
			 
			if((son | 1) <= Size && heap[son | 1] > heap[son]) son |= 1;
			
			if(heap[i] > heap[son]) break;
			
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
			 
			if((son | 1) <= Size && heap[son | 1] > heap[son]) son |= 1;
			
			if(heap[i] > heap[son]) break;
			
			heap[i] ^= heap[son] ^= heap[i] ^= heap[son];
			
			i = son;
		}
		
		return heap[Size + 1];
	}
} H;

int n,a,b,tim;

int main()
{
	in(n);in(a);in(b);
	
	for(reg int i = 1; i <= n; ++i) H.Insert(Read());
	
	while(H.heap[1] > tim){tim += a;H.maintain(b);}
	
	printf("%d",tim/a);
	
	return 0;
}

/*int main()
{
	
	int n,pos;
	while(1){
		in(pos);in(n);
		switch(pos)
		{
			case 1 : 
					H.Insert(n);
					break;
			case 2 :
					H.maintain(n);
					break;
			case 3 :
					printf("%d\n",H.Get());
					break;
			case 4 :
					for(reg int i = 1; i <= n; ++i)
						printf("%d\n",H.Get());
					break;
		}
	}
	
}*/
