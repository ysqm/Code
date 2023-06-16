# include <cstdio>
# include <algorithm>
# define reg register
# define N 1000000
# define LL long long

inline int Read()
{
	int x = 0,f = 1;char ch = getchar();
	
	while(ch < '0' || ch > '9') {if(ch == '-')f = -1;ch = getchar();}
	 
	while(ch >= '0' && ch <= '9') {x = x*10 + (ch ^ 48);ch = getchar();}
	
	return x * f;
}

struct Node
{
	int val;
	int Rson,Lson;
	
	Node(const int val=0,const int Ls=0,const int Rs=0): val(val),Rson(Rs),Lson(Ls){}
} ;

int n,m,base[N + 42];


Node Seg[(N * 40) + 42];
int Root[N + 42];
int cnt;
	
void Build(const int L,const int R,int& K)
{
	K = ++cnt;
	
	if(L == R){Seg[K] = Node(base[L]);}
	
	else 
	{
		int mid = (L + R) >> 1;
		
		Build(L,mid,Seg[K].Lson);
		Build(mid+1,R,Seg[K].Rson);
	}
}
	
void Modify(const int& Position,const int& val,const int& nver,const int L,const int R,const int& u,int& K)
{
	Seg[K = ++cnt] = Node(Seg[u].val,Seg[u].Lson,Seg[u].Rson);
	
	if(L == R) Seg[cnt].val = val;		
	else 
	{
		int mid = L + R >> 1;
	
		if(Position <= mid) Modify(Position,val,nver,L,mid,Seg[u].Lson,Seg[K].Lson);
		if(Position > mid) Modify(Position,val,nver,mid+1,R,Seg[u].Rson,Seg[K].Rson);
	}
}

int Query(const int& Position,const int& nver,const int L,const int R,const int& u,int& K)
{
	Seg[K = ++cnt] = Node(Seg[u].val,Seg[u].Lson,Seg[u].Rson);
	
	if(L == R) return Seg[u].val;
		
	int mid = L + R >> 1;
	
	if(Position <= mid) return Query(Position,nver,L,mid,Seg[u].Lson,Seg[K].Lson);
	if(Position > mid) return Query(Position,nver,mid+1,R,Seg[u].Rson,Seg[K].Rson);
}

int main()
{
	n = Read();m = Read();
	
	for(reg int i = 1; i <= n ; ++i) base[i] = Read();
	
	Build(1,n,Root[0]);
	
	for(reg int i = 1,x,y,z; i <= m ; ++i)
	{
		x = Read();y = Read();z = Read();
		
		if(y == 1) Modify(z,Read(),i,1,n,Root[x],Root[i]);
		
		else printf("%d\n",Query(z,i,1,n,Root[x],Root[i]));
		
	}
	return 0;
}
