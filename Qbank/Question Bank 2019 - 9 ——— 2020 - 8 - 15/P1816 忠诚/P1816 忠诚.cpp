# include <cstdio>
# include <algorithm>
# define N 100000
# define LL long long
# define reg register
# define Ls(i) i << 1
# define Rs(i) i << 1 | 1
# define mi (L + R) >> 1

inline void in(int& x)
{
	x = 0; char ch = getchar();
	
	while(ch < '0' || ch > '9')ch = getchar();
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

}

inline int Max(const int& a,const int b){return a > b ? a : b;}
inline int Min(const int& a,const int& b){return a < b ? a : b;}
inline int Minu(const int a,const int b){return a < b ? a : b;}

int segtree[(N << 2) + 42],base[N + 42],m,n;

inline void build(int L,int R,int K)
{
	if(L == R)segtree[K] = base[L];
	else {
		int mid = mi;
		
		build(L,mid,Ls(K));
		
		build(mid + 1,R,Rs(K));
		
		segtree[K] = Min(segtree[Rs(K)],segtree[Ls(K)]);
	}
}

inline int query(int& ask_L,int& ask_R,int L,int R,int K)
{
	if(ask_L <= L && ask_R >= R) return segtree[K];
	else{
		int mid = mi;
		
		if(mid >= ask_R) return query(ask_L,ask_R,L,mid,Ls(K));
		
		else if(mid < ask_L) return query(ask_L,ask_R,mid + 1,R,Rs(K));
		
		else return Minu(query(ask_L,ask_R,L,mid,Ls(K)),query(ask_L,ask_R,mid + 1,R,Rs(K)));
	} 
}

int main()
{
	in(m);in(n);
	
	for(reg int i = 1; i <= m; ++i) in(base[i]);
	
	build(1,m,1);
	
	for(reg int i = 1,x,y; i <= n; ++i){
		in(x);in(y);
		printf("%d ",query(x,y,1,m,1));
	}
	
	return 0;
}
