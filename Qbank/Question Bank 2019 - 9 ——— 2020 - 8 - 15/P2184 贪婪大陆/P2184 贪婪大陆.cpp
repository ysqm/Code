# include <cstdio>
# include <cstring>
# define reg register
# define N 100000
# define Ls(i) (i<<1)
# define Rs(i) (i<<1|1)

inline int Read()
{
	 int x = 0;char ch = getchar();
	 
	 while(ch < '0' || ch > '9') ch = getchar();
	 
	 while(ch >= '0' && ch <= '9'){x = (x * 10) + (ch ^ 48);ch = getchar();}
	 
	 return x;
} 

inline int Min(const int a,const int b){return a < b ? a : b;}
inline int Max(const int a,const int b){return a > b ? a : b;}

struct Node
{
	int Sum_L,Sum_R,L,R;
	
	Node(const int SL=0,const int SR=0,const int L_=0,const int R_=0):Sum_L(SL),Sum_R(SR),L(L_),R(R_){};
} Seg[(N << 2) + 42];

int n,One=1;

void Build(const int L,const int R,const int K)
{
	Seg[K] = Node(0,0,L,R);
	
	if(L != R)  
	{
		int mid = (L+R)>>1;
		
		Build(L,mid,Ls(K));
		Build(mid+1,R,Rs(K));
	}
}

void Modify_L(const int& AL,const int K)
{
	if(Seg[K].L == Seg[K].R) ++Seg[K].Sum_L;
	
	else 
	{
		int mid = Seg[Ls(K)].R;
		
		if(mid >= AL) Modify_L(AL,Ls(K));
		else Modify_L(AL,Rs(K));
		
		Seg[K].Sum_L = Seg[Ls(K)].Sum_L + Seg[Rs(K)].Sum_L;
	}
}

void Modify_R(const int& AR,const int K)
{
	if(Seg[K].L == Seg[K].R) ++Seg[K].Sum_R;
	
	else 
	{
		int mid = Seg[Ls(K)].R;
		
		if(mid >= AR) Modify_R(AR,Ls(K));
		else Modify_R(AR,Rs(K));
		
		Seg[K].Sum_R = Seg[Ls(K)].Sum_R + Seg[Rs(K)].Sum_R;
	}
}

int Query_L(const int& AL,const int& AR,const int K)
{
	if(AR < Seg[K].L || AL > Seg[K].R) return 0;
	if(AL <= Seg[K].L && AR >= Seg[K].R) return Seg[K].Sum_L;
	return Query_L(AL,AR,Ls(K)) + Query_L(AL,AR,Rs(K));
}

int Query_R(const int& AL,const int& AR,const int K)
{
	if(AR < Seg[K].L || AL > Seg[K].R) return 0;
	if(AL <= Seg[K].L && AR >= Seg[K].R) return Seg[K].Sum_R;
	return Query_R(AL,AR,Ls(K)) + Query_R(AL,AR,Rs(K));
}

inline int Query(const int L,const int R){return Query_L(One,R,1) - Query_R(One,L,1);}
inline void Modify(const int L,const int R){Modify_L(L,1);Modify_R(R,1);}

int main()
{
	n = Read();
	
	Build(1,n,1);
	
	reg int m = Read(),pos,x,y;
	
	while(m--)
	{
		pos = Read();x = Read();y = Read();
		
		if(pos == 1) Modify(x,y);
		else printf("%d\n",Query(x-1,y));
	}
	
	return 0;
}
