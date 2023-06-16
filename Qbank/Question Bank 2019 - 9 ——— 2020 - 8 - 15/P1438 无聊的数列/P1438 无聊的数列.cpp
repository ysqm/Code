# include <cstdio>
# include <cstring>
# define reg register
# define N 1000000
# define Ls(i) (i<<1)
# define Rs(i) (i<<1|1)

inline int Read()
{
	 int x = 0,f = 1;char ch = getchar();
	 
	 while(ch < '0' || ch > '9') ch == '-' ? f = -1,ch = getchar() : ch = getchar();
	 
	 while(ch >= '0' && ch <= '9'){x = (x * 10) + (ch ^ 48);ch = getchar();}
	 
	 return x * f;
} 

inline int Min(const int a,const int b){return a < b ? a : b;}
inline int Max(const int a,const int b){return a > b ? a : b;}

struct Node
{
	int Diff,Tag,L,R;
	
	Node(const int Diff_=0,const int Tag_=0,const int L_=0,const int R_=0):Diff(Diff_),Tag(Tag_),L(L_),R(R_){};
} Seg[(N << 2) + 42];

int n,One,a[N + 42],m;

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

void Push_Down(const int ls,const int rs,const int& K)
{
	Seg[ls].Diff += (Seg[ls].R-Seg[ls].L+1)*Seg[K].Tag;
	Seg[rs].Diff += (Seg[rs].R-Seg[rs].L+1)*Seg[K].Tag;
	Seg[ls].Tag += Seg[K].Tag;
	Seg[rs].Tag += Seg[K].Tag;
	Seg[K].Tag = 0;
}

void Modify(const int D,const int AL,const int AR,const int K)
{
	if(Seg[K].L >= AL && Seg[K].R <= AR) {Seg[K].Diff += D * (Seg[K].R-Seg[K].L+1);Seg[K].Tag += D;}
	
	else 
	{
		if(Seg[K].Tag) Push_Down(Ls(K),Rs(K),K);
		
		int mid = Seg[Ls(K)].R;
		
		if(mid >= AL) Modify(D,AL,AR,Ls(K));
		if(mid < AR) Modify(D,AL,AR,Rs(K));
		
		Seg[K].Diff = Seg[Ls(K)].Diff + Seg[Rs(K)].Diff;
	}
}

/*int Query(const int AL,const int AR,const int K)
{
	if(Seg[K].L >= AL && Seg[K].R <= AR) return Seg[K].Diff;
	
	else 
	{
		if(Seg[K].Tag) Push_Down(Ls(K),Rs(K),K);
		
		int mid = Seg[Ls(K)].R,res = 0;
		
		if(mid >= AR) res += Query(AL,AR,Ls(K));
		if(mid < AR) res += Query(AL,AR,Rs(K));
		
		return res;
	}	
} 
*/

int Query(const int& AR,const int K)
{
	if(AR < Seg[K].L) return 0;
	
	if(AR >= Seg[K].R) return Seg[K].Diff;
	
	int mid = Seg[Ls(K)].R;
	
	if(Seg[K].Tag) Push_Down(Ls(K),Rs(K),K);
	
	return Query(AR,Ls(K)) + Query(AR,Rs(K));	
} 

int main()
{
	//freopen("P1438_1.in","r",stdin);
	//freopen("1.txt","w",stdout);
	
	n = Read();m = Read();//int Debug=0,Dm = m;
	
	for(reg int i = 1; i <= n ; ++i) a[i] = Read();
	
	Build(1,n,1);
	
	while(m--){
		if(Read() == 1)
		{
			int L,R,D,K;
			L = Read();R = Read();K = Read();D = Read();
			
			Modify(K,L,L,1);
			if(R > L) Modify(D,L+1,R,1);
			if(R != n) Modify(-(K + (R-L)*D),R+1,R+1,1);
		}
		else 
		{
			One = Read();/*case%d(%d):++Debug,Dm-m,*/
			printf("%d\n",Query(One,1) + a[One]);
		}
	}
	
	return 0;
}
