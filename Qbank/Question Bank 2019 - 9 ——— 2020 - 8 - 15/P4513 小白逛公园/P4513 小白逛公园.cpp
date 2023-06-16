/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
=======`-.____`-.___\_____/___.-`____.-'=======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  	 Buddha said:
         	 	 The program have no BUG.
         	 	 The program can pass the text.   	 	 
*/
# include <cstdio>
# define reg register
# define Ls(i) (i<<1)
# define Rs(i) (i<<1)|1
# define N 500000
# define M 100000

inline int Read()
{
	int x = 0,f = 1;char ch = getchar();
	
	while(ch < '0' || ch > '9'){if(ch == '-') f = -1;ch = getchar();}
	
	while(ch >= '0' && ch <= '9'){x = x * 10 + (ch ^ 48);ch = getchar();}
	
	return x * f;
}

struct Node
{
	int Prefix_Left,Suffix_Right,Sub_Segment,Interval_sum;
	
	Node(){Interval_sum = Prefix_Left = Sub_Segment = Suffix_Right = 0;}
	
} Segtree[(N << 2) + 42];

int base[N + 42],n,m;

inline int Max(const int a,const int b){return a > b ? a : b;}

inline void Segtree_Maintain(const int& K)
{
	Segtree[K].Interval_sum = Segtree[Ls(K)].Interval_sum + Segtree[Rs(K)].Interval_sum;
	
	Segtree[K].Prefix_Left = Max(Segtree[Ls(K)].Prefix_Left,Segtree[Ls(K)].Interval_sum + Segtree[Rs(K)].Prefix_Left);
	
	Segtree[K].Suffix_Right = Max(Segtree[Rs(K)].Suffix_Right,Segtree[Rs(K)].Interval_sum + Segtree[Ls(K)].Suffix_Right);
	
	Segtree[K].Sub_Segment = Max(Max(Segtree[Ls(K)].Sub_Segment,Segtree[Rs(K)].Sub_Segment),Segtree[Ls(K)].Suffix_Right + Segtree[Rs(K)].Prefix_Left);
}

void Segtree_Build(const int L,const int R,const int K)
{
	if(L == R) Segtree[K].Interval_sum = Segtree[K].Prefix_Left = Segtree[K].Sub_Segment = Segtree[K].Suffix_Right = base[L];
	
	else {
		int mid = (L + R) >> 1;
		
		Segtree_Build(L,mid,Ls(K));
		
		Segtree_Build(mid+1,R,Rs(K));
		
		Segtree_Maintain(K);
	}
}

Node Segtree_Query(const int& Ask_L,const int& Ask_R,const int L,const int R,const int K)
{
	if(Ask_L <= L && Ask_R >= R) return Segtree[K];
	
	else {
		int mid = (L + R) >> 1,res = 0;
		
		if(mid >= Ask_R) return Segtree_Query(Ask_L,Ask_R,L,mid,Ls(K));
		
		else if(mid < Ask_L) return Segtree_Query(Ask_L,Ask_R,mid+1,R,Rs(K));
		
		else {
			Node t = Node(),a = Segtree_Query(Ask_L,Ask_R,L,mid,Ls(K)),b = Segtree_Query(Ask_L,Ask_R,mid+1,R,Rs(K));
			
			t.Prefix_Left = Max(a.Prefix_Left,a.Interval_sum + b.Prefix_Left);
			
			t.Suffix_Right = Max(b.Suffix_Right,b.Interval_sum + a.Suffix_Right);
			
			t.Sub_Segment = Max(Max(a.Sub_Segment,b.Sub_Segment),a.Suffix_Right + b.Prefix_Left);
			
			return t;
		}
	}
}

void Segtree_Point_Updata(const int& Position,const int& New_Data,const int L,const int R,const int K)
{
	if(L == R) Segtree[K].Interval_sum = Segtree[K].Prefix_Left = Segtree[K].Sub_Segment = Segtree[K].Suffix_Right = New_Data;
	
	else {
		int mid = (L + R) >> 1;
		
		if(mid >= Position) Segtree_Point_Updata(Position,New_Data,L,mid,Ls(K));
		
		if(mid < Position) Segtree_Point_Updata(Position,New_Data,mid+1,R,Rs(K));
		
		Segtree_Maintain(K);
	}
}

int main()
{
	n = Read();m = Read();
	
	for(reg int i = 1; i <= n ; ++i) base[i] = Read();
	
	Segtree_Build(1,n,1);
	
	for(reg int i = 1,op,x,y; i <= m ; ++i)
	{
		op = Read();x = Read();y = Read();
		
		if(op == 1 && y > x) printf("%d\n",Segtree_Query(x,y,1,n,1).Sub_Segment);
		
		else if(op == 1) printf("%d\n",Segtree_Query(y,x,1,n,1).Sub_Segment);
		
		else Segtree_Point_Updata(x,y,1,n,1);
	}
	
	return 0;
}
