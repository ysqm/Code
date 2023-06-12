# include <cstdio>
# include <cstring>
# include <algorithm>
# define reg register
# define N 100000
# define Gc (SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
char BB[1<<15],*SS=BB,*TT=BB;

inline int Read()
{
	register int x = 0;register char ch = Gc;

	while(ch < '0' || ch > '9') ch = Gc;

	while(ch <= '9' && ch >= '0'){x = x*10 + (ch^48);ch = Gc;}

	return x;
}

struct node
{
	int x,y;

	node(const int R=0,const int L=0):x(L),y(R){}
};



node p[N+5];
int n,m;

int main()
{
	#ifdef ONLINE_JUDGE
	#else
    freopen("1.in","r",stdin);
	#endif

	n = Read();m = Read();

	for(reg int i = 1; i <= n ; ++i) p[i] = node(Read(),Read()); 

	for(reg int i = 1; i <= n ; ++i)
	{
		
	}

	 return 0;
}