# include <cstdio>
# include <algorithm>
# define reg register
# define Ls(i) (i<<1)
# define Rs(i) (i<<1|1)
# define mid ((L+R)>>1)
# define N 1000000
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
	LL L,R,height;
	int tag;
	
	Node(){}
	Node(const LL _x_1,const LL _x_2,const LL _height,const int _tag):L(_x_1),R(_x_2),height(_height),tag(_tag){}
	
	bool operator < (const Node &b) const 
	{
		return height < b.height;
	}
} Line[(N << 2) + 42];

struct Seg_Tree_Node
{
	int Sum,L,R;
	LL Len;

	Seg_Tree_Node(){}
	Seg_Tree_Node(const int& _Sum,const LL& _Len,const int& _L,const int _R):Sum(_Sum),Len(_Len),L(_L),R(_R){}
	
} Seg[(N << 2) + 42];

LL n,XX[N + 42],Cnt_Line,ToT;

void Build(const int L,const int R,const int K)
{
	Seg[K] = Seg_Tree_Node(0,0,L,R);
	
	if(L == R)return;
	
	Build(L,mid,Ls(K));
	Build(mid+1,R,Rs(K));
}

void Push_up(const int& K)
{
	if(Seg[K].Sum) Seg[K].Len = XX[Seg[K].R+1] - XX[Seg[K].L];
	
	else Seg[K].Len = Seg[Ls(K)].Len + Seg[Rs(K)].Len;
}

void Insert(const LL& RL,const LL& RR,const int& Tag,const int K)
{
	int l = Seg[K].L,r = Seg[K].R;
	
	if(XX[r + 1] <= RL || RR <= XX[l]) return;
	
	if(XX[l] >= RL && XX[r+1] <= RR)
	{	
		Seg[K].Sum += Tag;
		Push_up(K);
		
		return;
	}

	Insert(RL,RR,Tag,Ls(K));
	
	Insert(RL,RR,Tag,Rs(K));
	
	Push_up(K);
}

int main()
{
	LL X_1,X_2,Y_1,Y_2;
	
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
	
	n <<= 1;
	
	std::sort(XX + 1,XX + n + 1);
	std::sort(Line + 1,Line + n + 1);
	
	ToT = std::unique(XX + 1,XX + n + 1) - XX - 1;
	
	Build(1,ToT - 1,1);
	
	LL ans = 0;
	
	for(reg int i = 1; i < n ; ++i)
	{
		Insert(Line[i].L,Line[i].R,Line[i].tag,1);
		
		ans += (Line[i + 1].height - Line[i].height) * Seg[1].Len;
	}
	
	printf("%lld\n",ans);
	
	return 0;
}

