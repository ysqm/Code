# include <cstdio>
# include <cstring>
# define N 100000
# define reg register
# define Ls(i) (i<<1)
# define Rs(i) (i<<1|1)
# define mid ((L+R)>>1)
# define LL long long
using namespace std;

template <typename T>
inline T in(T& x)
{
	x = 0;char c = getchar();
	
	while(c < '0' || c > '9') c = getchar();
	
	while(c >= '0' && c <= '9'){x = (x << 3) + (x << 1) +c - 48;c = getchar();}
} 

template <typename T>
inline T Min(const T A,const T B){return A < B ? A : B;} 

inline LL Read()
{
	LL x = 0;char c = getchar();
	
	while(c < '0' || c > '9') c = getchar();
	
	while(c >= '0' && c <= '9'){x = (x << 3) + (x << 1) +c - 48;c = getchar();}
	
	return x;
}

LL segtree[(N << 2) + 42],mod,Q,T;

inline void build(const int L,const int R,const int K)
{
	segtree[K] = 1;
	
	if(L == R) return;
	
	build(L,mid,Ls(K));
	
	build(mid+1,R,Rs(K));
}

inline LL update(const int& Position,const int& value,const int L,const int R,const int K)
{
	if(L == R) segtree[K] = value;
	
	else 
	{
		if(Position <= mid) update(Position,value,L,mid,Ls(K));
		
		else update(Position,value,mid+1,R,Rs(K));
		
		segtree[K] = (segtree[Ls(K)] * segtree[Rs(K)]) % mod;
	}
}

int main()
{
	T = Read();
	
	while(T--)
	{
		Q = Read();mod = Read();
		
		build(1,Q,1);
		
		for(reg int i = 1,opt,x; i <= Q ; ++i)
		{
			opt = Read();x = Read();
			
			if(opt == 1) update(i,x,1,Q,1);
			else update(x,1,1,Q,1);
			
			printf("%lld\n",segtree[1]);
		}
	}
	
	return 0;
}
