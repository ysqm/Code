# include <cmath>
# include <cstdio>
# include <iostream> 
# include <algorithm>
# define reg register
# define N 2000
# define mod 998244353 
# define INF 0x7f7f7f7f7f7f7f7f
# define Gc getchar()//*/(SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
char BB[1<<15],*SS=BB,*TT=BB;

inline int Read()
{
	register int x = 0;register char ch = Gc;
	
	while(ch < '0' || ch > '9') ch = Gc;
	
	while(ch <= '9' && ch >= '0'){x = x*10 + (ch^48);ch = Gc;}
	
	return x;
}

int f[N + 42],n;

void INIT()
{
	n = Read();
	
	for(reg int i = (n<<1); i >= 1; --i) f[i] = i,Size[i] = 1;
	
	return;
} 

inline int Find(const int x){return *(f+x) == x ? x : *(f+x)=Find(*(f+x));}

inline void Unity(int x,int y)
{
	*(f + Find(x)) = Find(y);
	
	return; 
}

inline void Solve()
{
	reg int m = Read(),p,q;
	char ch = 0;
	
	while(m--)
	{
		std::cin>>ch;
		
		p = Read();q = Read();
		
		if(ch == 'F') Unity(p,q);
		else
		{
			Unity(p+n,q);
			Unity(q+n,p); 
		}
	}
	
	reg int ans = 0;
	
	for(reg int i = 1; i <= n ; ++i) if(*(f+i) == i) ++ans;
	
	printf("%d\n",ans);
	
	return ;
}

int main()
{
	INIT(); 
	
	Solve();
	
	return 0; 
}
