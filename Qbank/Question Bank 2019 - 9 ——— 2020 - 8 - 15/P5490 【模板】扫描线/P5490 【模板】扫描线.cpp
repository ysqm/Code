# include <cstdio>
# include <algorithm>
# define reg register
# define Ls(i) (i<<1)
# define Rs(i) (i<<1|1)
# define mid ((L+R)>>1)
# define N 200000
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
	LL x_1,x_2,height;
	int tag;
	
	Node(){}
	Node(const LL _x_1,const LL _x_2,const LL _height,const int _tag):x_1(_x_1),x_2(_x_2),height(_height),tag(_tag){}
	
	bool operator < (const Node &b) const 
	{
		return height < b.height;
	}
} Line[(N << 2) + 42];

struct Seg_Tree_Node
{
	int Sum;
	LL Len;

	Seg_Tree_Node(){}
	Seg_Tree_Node(const int& _Sum,const LL& _Len):Sum(_Sum),Len(_Len){}
	
} Seg[(N << 2) + 42];

int n,Cnt_Line,ToT;
LL XX[N + 42];

void Push_up(const int& L,const int& R,const int& K)
{
	if(Seg[K].Sum) Seg[K].Len = XX[R+1] - XX[L];
	
	else Seg[K].Len = Seg[Ls(K)].Len + Seg[Rs(K)].Len;
}

void Insert(const LL& Reality_L,const LL& Reality_R,const int& Tag,const int L,const int R,const int K)
{
	if(XX[R + 1] <= Reality_L || Reality_R <= XX[L]) return;
	
	if(XX[L] >= Reality_L && XX[R+1] <= Reality_R)
	{	
		Seg[K].Sum += Tag;
		Push_up(L,R,K);
	}

	else 
	{
		Insert(Reality_L,Reality_R,Tag,L,mid,Ls(K));
	
		Insert(Reality_L,Reality_R,Tag,mid+1,R,Rs(K));
	
		Push_up(L,R,K);
	}
}

void INIT()
{
	reg LL X_1,X_2,Y_1,Y_2;
	
	n = Read();
	
	for(reg int i = 1; i <= n; ++i)
	{
		X_1 = Read();Y_1 = Read();
		X_2 = Read();Y_2 = Read();
		
		Line[++Cnt_Line] = Node(X_1,X_2,Y_1,1);
		Line[++Cnt_Line] = Node(X_1,X_2,Y_2,-1);
		
		XX[++ToT] = X_1;
		XX[++ToT] = X_2;
	}
	
	std::sort(XX + 1,XX + ToT + 1);
	std::sort(Line + 1,Line + ToT + 1);
	
	ToT = std::unique(XX + 1,XX + Cnt_Line + 1) - XX - 2;
}

void Ans()
{
	LL ans = 0;
	
	n <<= 1;
	
	for(reg int i = 1; i < n ; ++i)
	{
		Insert(Line[i].x_1,Line[i].x_2,Line[i].tag,1,ToT,1);
		
		ans += (Line[i + 1].height - Line[i].height) * Seg[1].Len;
	}
	
	printf("%lld\n",ans);
}

int main()
{
	INIT();
	
	Ans();
	
	return 0;
}

