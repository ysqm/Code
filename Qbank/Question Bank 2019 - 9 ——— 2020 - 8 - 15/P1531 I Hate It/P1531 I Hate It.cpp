# include <cstdio>
# include <cstring>
# include <queue>
# include <cmath>
# define reg register
# define N 20000
# define int long long
# define Ls (K<<1)
# define Rs (K<<1|1) 
using namespace std;

inline int Read()
{
	int x = 0;char c = getchar();
	
	while(c < '0' || c > '9') c = getchar();
	
	while(c >= '0' && c <= '9'){x = (x << 3) + (x << 1) +c - 48;c = getchar();}
	
	return x;
}

inline int Max(const int a,const int b){return a > b ? a : b;}
inline int Min(const int a,const int b){return a < b ? a : b;}

int n,m,base[N + 42];
int Seg[(N << 2) + 42];

void build(const int L,const int R,const int K)
{
	if(L == R) Seg[K] = base[L];
	
	else 
	{
		int mid = (L + R) >> 1;
		
		build(L,mid,Ls);
		build(mid+1,R,Rs);
		
		Seg[K] = Max(Seg[Ls],Seg[Rs]);
	}
} 

int query(const int& AL,const int& AR,const int L,const int R,const int K)
{
	if(R < AL || L > AR) return 0;
	if(AL <= L && AR >= R) return Seg[K];
	
	else 
	{
		int mid = (L + R) >> 1;
		
		return Max(query(AL,AR,mid+1,R,Rs),query(AL,AR,L,mid,Ls));
	}
} 

void Modify(const int& pos,const int& x,const int L,const int R,const int K)
{
	if(R < pos || L > pos) return;
	if(L == pos && R == pos) Seg[K] = Max(x,Seg[K]);
	
	else 
	{
		int mid = (L + R) >> 1;
		
		Modify(pos,x,L,mid,Ls);
		Modify(pos,x,mid+1,R,Rs);
		
		Seg[K] = Max(Seg[Ls],Seg[Rs]);
	}
} 

signed main()
{
	n = Read();m = Read();
	
	for(reg int i = 1; i <= n ; ++i) base[i] = Read();
	
	build(1,n,1);
	
	while(m--)
	{
		char s[2];
		reg int x,y;
		
		scanf("%s",s);
		
		x = Read();y = Read();
		
		if(s[0] == 'Q') printf("%d\n",query(x,y,1,n,1));
		
		else Modify(x,y,1,n,1);
	}
	
	return 0;
}
