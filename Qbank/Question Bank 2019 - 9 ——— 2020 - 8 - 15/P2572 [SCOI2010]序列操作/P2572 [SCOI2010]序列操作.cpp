# include <cstdio>
# include <algorithm>
# define reg register
# define N 100000
# define LL long long

inline LL Read()
{
	LL x = 0;char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch >= '0' && ch <= '9') {x = x*10 + (ch ^ 48);ch = getchar();}
	
	return x;
}

struct Node
{
	int L,R;
	int Sum,Tag;
	bool flag;
	int max_len,Rmax,Lmax; 

	Node(){}
	Node(const int _Sum,const int _flag,const int& uu):Sum(_Sum),flag(_flag){}
	Node(const int _Sum,const int _Tag):Sum(_Sum),Tag(_Tag){}
	Node(const int& _Sum,const int& _Tag,const int& _L,const int& _R):Sum(_Sum),Tag(_Tag),L(_L),R(_R){}
	
	inline void Qlen(const int a,const int b,const int c){max_len = a;Rmax = b;Lmax = c;}
} ;

int n,m,base[N + 42];

struct Seg_Tree
{
	# define Ls(i) (i<<1)
	# define Rs(i) (i<<1|1)

	Node Seg[(N << 2) + 42];
	
	inline void update(const int& K)
	{
		int ls = Ls(K),rs = Rs(K);
		
		Seg[K] = Node(Seg[ls].Sum + Seg[rs].Sum,Seg[ls].Tag == Seg[rs].Tag ? Seg[ls].Tag : -1);
	} 
	
	inline void pushdown(const int& K)
	{
		int ls = Ls(K),rs = Rs(K);
		
		Seg[ls] = Node(Seg[ls].R - Seg[ls].L + 1 - Seg[ls].Sum,1,Seg[K].L);
		
		Seg[rs] = Node(Seg[rs].R - Seg[rs].L + 1 - Seg[rs].Sum,1,Seg[K].L);
		
		Seg[K].flag = 0;
	} 
	
	void Build(const int L,const int R,const int K)
	{
		if(L == R) Seg[K] = Node(base[L],base[L],L,R);
		else
		{
			int mid = (L+R)>>1;
			Build(L,mid,Ls(K));
			Build(mid+1,R,Rs(K));
			update(K);
		}
	}
	
	void change(const int& AL,const int& AR,const int& Goal,const int K)
	{
		if(Seg[K].L >= AL && Seg[K].R <= AR) Seg[K] = Node((Seg[K].R - Seg[K].L + 1) * Goal,Goal);
		else 
		{
			int mid = Seg[Ls(K)].R;
			
			if(Seg[K].flag) pushdown(K); 
			
			if(AL <= mid) change(AL,AR,Goal,Ls(K));
			if(AR > mid) change(AL,AR,Goal,Rs(K));
			
			update(K);
		}
	}
	
	
	void reserve(const int& AL,const int& AR,const int K)
	{
		if(Seg[K].L >= AL && Seg[K].R <= AR) Seg[K] = Node(Seg[K].R - Seg[K].L + 1 - Seg[K].Sum,1,Seg[K].L);
		else 
		{
			int mid = Seg[Ls(K)].R;
			
			if(Seg[K].flag) pushdown(K); 
			
			if(AL <= mid) reserve(AL,AR,Ls(K));
			if(AR > mid) reserve(AL,AR,Rs(K));
			
			update(K);
		}
	}
	# undef Ls
	# undef Rs
};

int main()
{
	
	return 0;
}
