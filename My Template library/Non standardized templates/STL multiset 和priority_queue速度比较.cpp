/*
	Name : multiset 和 手写堆 速度比较 
	Code by : 云岁月书
	Date ： 2020/8/13 
*/
# include <cstdio>
# include <cstring>
# include <cstdlib>
# include <ctime>
# include <queue>
# include <set>
# define N 10000000
using namespace std;

multiset<int> rbt;

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

priority_queue<int> q;

int Data[N + 41],cnt,C[N + 42];

int main()
{
	srand(time(NULL));
	
	int n,m,type,tot;

	do
	{
		puts("请依次输入插入数据总量，操作次数，测试种类"); 
		puts("测试种类：-1 退出程序,0只有插入,1 先插入再删除,2 插入删除混合,3 只记录删除"); 
		
		scanf("%d%d%d",&n,&m,&type);
	
		if(n < m) m = n;
	
		clock_t t0,t1,t2,t3;
	
		for(int i = 1; i <= n; ++i) Data[i] = rand();
	
		if(type == 2)
		{
			for(int i = 1; i <= n; ++i) C[i] = rand();
			
			t0 = clock();
		
			for(int i = 1; i <= n; ++i)
				if(C[i]&1 && rbt.size()) rbt.erase(rbt.begin());
				else rbt.insert(Data[i]);
			
			t1 = clock();
			
			for(int i = 1; i <= n; ++i)
				if(C[i]&1 && H.Size) H.Get();
				else H.Insert(Data[i]);
				
			t2 = clock();
		
			for(int i = 1; i <= n; ++i)
				if(C[i]&1 && q.size()) q.pop();
				else q.push(Data[i]);
			
			t3 = clock();
		}
		else if(type == 0)
		{
			t0 = clock();
		
			for(int i = 1; i <= n; ++i) rbt.insert(Data[i]);
		
			t1 = clock();
			
			for(int i = 1; i <= n; ++i) H.Insert(Data[i]);
			
			t2 = clock();
		
			for(int i = 1; i <= n; ++i) q.push(Data[i]);
			
			t3 = clock();
		}
		else if(type == 3)
		{
			for(int i = 1; i <= n; ++i) rbt.insert(Data[i]);
			
			for(int i = 1; i <= n; ++i) H.Insert(Data[i]);
			
			for(int i = 1; i <= n; ++i) q.push(Data[i]);
			
			t0 = clock();
		
			for(int i = 1; i <= n; ++i) rbt.erase(rbt.begin());
		
			t1 = clock();
		
			for(int i = 1; i <= n; ++i) H.Get();
			
			t2 = clock();
		
			for(int i = 1; i <= n; ++i) q.pop();
			
			t3 = clock();
			
		}
		else if(type == 1)
		{
			t0 = clock();
			
			for(int i = 1; i <= n; ++i) rbt.insert(Data[i]);
		
			for(int i = 1; i <= n; ++i) rbt.erase(rbt.begin());
		
			t1 = clock();
		
			for(int i = 1; i <= n; ++i) H.Insert(Data[i]);
		
			for(int i = 1; i <= n; ++i) H.Get();
			
			t2 = clock();
		
			for(int i = 1; i <= n; ++i) q.push(Data[i]);
		
			for(int i = 1; i <= n; ++i) q.pop();
			
			t3 = clock();
		}
	
		printf("multiset : %dms \nHeap : %dms\nproirty_queue STL : %dms \n",t1-t0,t2-t1,t3-t2);
		
	}while(type != -1); 

	return 0;
}
