# include <cstdio>
# include <cstring>
# define reg register
# define N 50000
# define Ls(i) (i<<1)
# define Rs(i) (i<<1|1)

inline int Read()
{
	 int x = 0;char ch = getchar();
	 
	 while(ch < '0' || ch > '9') ch = getchar();
	 
	 while(ch >= '0' && ch <= '9'){x = (x * 10) + (ch ^ 48);ch = getchar();}
	 
	 return x;
} 

inline int MMin(const int a,const int b){return a < b ? a : b;}
inline int MMax(const int a,const int b){return a > b ? a : b;}
inline int Max(const int& a,const int& b){return a > b ? a : b;}
inline int Min(const int& a,const int& b){return a < b ? a : b;}

int Seg[(N << 2) + 42],seg[(N << 2) + 42],base[N + 42],n,m;

void build(const int L,const int R,const int K)
{
	if(L == R) Seg[K] = seg[K] = base[L];
	
	else
	{
		int mid = (L + R) >> 1;
		
		build(L,mid,Ls(K));
		build(mid+1,R,Rs(K));
		
		Seg[K] = Max(Seg[Rs(K)],Seg[Ls(K)]);
		seg[K] = Min(seg[Rs(K)],seg[Ls(K)]);
	}
}

int Query(const int& AL,const int& AR,const int L,const int R,const int K)
{
	if(AL <= L && AR >= R) return Seg[K];
	
	else
	{
		int mid = (L + R) >> 1;
		
		if(AR <= mid) return Query(AL,AR,L,mid,Ls(K));
		else if(AL > mid) return Query(AL,AR,mid+1,R,Rs(K));
		else return MMax(Query(AL,AR,L,mid,Ls(K)),Query(AL,AR,mid+1,R,Rs(K)));
	}
}

int query(const int& AL,const int& AR,const int L,const int R,const int K)
{
	if(AL <= L && AR >= R) return seg[K];
	
	else
	{
		int mid = (L + R) >> 1;
		
		if(AR <= mid) return query(AL,AR,L,mid,Ls(K));
		else if(AL > mid) return query(AL,AR,mid+1,R,Rs(K));
		else return MMin(query(AL,AR,L,mid,Ls(K)),query(AL,AR,mid+1,R,Rs(K)));
	}
}

int main()
{
	//freopen("P2880_2.in","r",stdin);
	
	n = Read();m = Read();
	
	memset(seg,0x3f,sizeof(seg));
	
	for(reg int i = 1; i <= n ; ++i) base[i] = Read();
	
	build(1,n,1);
	
	for(reg int i = 1,x,y; i <= m ; ++i)
	{
		x = Read();y = Read();
		
		printf("%d\n",Query(x,y,1,n,1) - query(x,y,1,n,1));
	}
	
	return 0;
}
