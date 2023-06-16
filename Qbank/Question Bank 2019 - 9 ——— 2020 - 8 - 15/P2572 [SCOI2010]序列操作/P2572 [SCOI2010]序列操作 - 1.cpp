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
	int S1,S0; 
	int m1,m0,Rm1,Rm0,Lm1,Lm0;
	
	Node(const int S1=0,const int S0=0,const int ML1=0,const int ML0=0,const int LM1=0,const int LM0=0,const int RM1=0,const int RM0=0):S1(S1),S0(S0),m1(ML1),m0(ML0),Rm1(RM1),Rm0(RM0),Lm1(LM1),Lm0(LM0){}
} ;

int n,m,base[N + 42];

inline int Max(const int a,const int b){return a < b ? b : a;}

struct Seg_Tree
{
	# define Ls(i) (i<<1)
	# define Rs(i) (i<<1|1)

	Node Seg[(N << 2) + 42];
	int tag[(N << 2) + 42],Flip[(N << 2) + 42],Len[(N << 2) + 42];
	
	inline Node Merge(const Node ls,const Node rs)
	{
		return Node((ls.S1 + rs.S1),(ls.S0 + rs.S0),
			(Max(Max(rs.m1,ls.m1),rs.Lm1 + ls.Rm1)),(Max(Max(rs.m0,ls.m0),rs.Lm0 + ls.Rm0)),
			(ls.S0 ? ls.Lm1 : ls.m1 + rs.Lm1),(ls.S1 ? ls.Lm0 : ls.m0 + rs.Lm0),
			(rs.S0 ? rs.Rm1 : rs.m1 + ls.Rm1),(rs.S1 ? rs.Rm0 : rs.m0 + ls.Rm0));
	}
	
	//inline int Swap(int& a,int& b){a ^= b ^= a ^= b;}
	
	inline int Operation(const int K,const int Type)
	{
		Node &x = Seg[K];
		
		if(Type == 0) 
		{
			Seg[K] = Node(0,Len[K],0,Len[K],0,Len[K],0,Len[K]);
			
			Flip[K] = tag[K] = 0;
		}
		
		if(Type == 1)
		{
			Seg[K] = Node(Len[K],0,Len[K],0,Len[K],0,Len[K],0);
			
			Flip[K] = 0;tag[K] = 1;
		}
		
		if(Type == 2)
		{
			Seg[K] = Node(x.S0,x.S1,x.m0,x.m1,x.Lm0,x.Lm1,x.Rm0,x.Rm1);
			
			Flip[K] ^= 1;
		}
	}
	
	inline void Push_Down(const int K)
	{
		if(~tag[K]) Operation(Ls(K),tag[K]),Operation(Rs(K),tag[K]);
		if(Flip[K]) Operation(Ls(K),2),Operation(Rs(K),2);
		tag[K] = -1;Flip[K] = 0;
	}
	
	void Build(const int L,const int R,const int K)
	{
		Len[K] = R - L + 1;tag[K] = -1;
		if(L == R) Seg[K] = Node(base[L],base[L]^1,base[L],base[L]^1,base[L],base[L]^1,base[L],base[L]^1);
		else 
		{
			int mid = (L + R) >> 1;
			
			Build(L,mid,Ls(K));
			Build(mid+1,R,Rs(K));
			
			Seg[K] = Merge(Seg[Ls(K)],Seg[Rs(K)]);
		}
	}
	
	void Modify(const int& AL,const int& AR,const int& Goal,const int L,const int R,const int K)
	{
		if(L >= AL && R <= AR) Operation(K,Goal);
		
		else
		{
			int mid = (L + R) >> 1;
			
			Push_Down(K);
			
			if(mid >= AL) Modify(AL,AR,Goal,L,mid,Ls(K));
			if(mid < AR) Modify(AL,AR,Goal,mid+1,R,Rs(K)); 
			
			Seg[K] = Merge(Seg[Ls(K)],Seg[Rs(K)]);
		}
	}
	
	void pr(const int L,const int R,const int K)
	{
		if(L == R) printf("%d",Seg[K].m1);
		else
		{
			int mid = (L + R) >> 1;
			
			Push_Down(K); 
			
			pr(L,mid,Ls(K));
			pr(mid+1,R,Rs(K));
			
			Seg[K] = Merge(Seg[Ls(K)],Seg[Rs(K)]);
		}
	}
	
	Node Query(const int& AL,const int& AR,const int& Goal,const int L,const int R,const int K)
	{
		if(R < AL || L > AR) return Node();
		
		if(L >= AL && R <= AR) return Seg[K];
		
		else
		{
			int mid = (L + R) >> 1;
			
			Push_Down(K);
			
			return Merge(Query(AL,AR,Goal,L,mid,Ls(K)),Query(AL,AR,Goal,mid+1,R,Rs(K)));
		}
	}
	
	# undef Ls
	# undef Rs
} T;

int main()
{
	n = Read();m = Read();
	
	for(reg int i = 1; i <= n ; ++i) base[i] = Read();
	
	T.Build(1,n,1);
	
	reg int x,y,z;
	
	while(m--)
	{
		x = Read();y = Read() + 1;z = Read() + 1;
		
		if(x < 3) T.Modify(y,z,x,1,n,1);
		else 
		{
			Node UU = T.Query(y,z,x,1,n,1);
			
			printf("%d\n",x == 3 ? UU.S1 : UU.m1);
		} 
		//printf("Case %d : ",n - m);
		//T.pr(1,n,1);
		//puts(""); 
	}
	
	return 0;
}
