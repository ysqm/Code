# include <cstdio>
# define reg register
# define LL long long
# define Gc (SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
# define int long long 
char BB[1<<15],*SS=BB,*TT=BB;
inline int Read()
{
	register int x = 0;char ch = Gc;

	while(ch < '0' || ch > '9')ch = Gc;

	while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = Gc;}

	return x;
}

int n,m,x;

signed main()
{
	n = Read();m = Read();
	
	for(reg int i = 1; i <= n ; ++i)
		for(reg int j = 1; j <= m ; ++j)
			x += Read()*(i*i+j*j);

	for(reg int i = 1; i <= n ; ++i)
		for(reg int j = 1; j <= m ; ++j)
			x -= Read()*(i*i+j*j);
	
	printf("%lld",x>>1);

	return 0;
}
