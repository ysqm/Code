# include <cstdio>
# define reg //register
//# define N 10000000
# define N 100
# define M 100000
# define LL long long
# define Gc getchar()//*/(SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
char BB[1<<15],*SS=BB,*TT=BB;
inline int Read()
{
	register int x = 0;char ch = Gc;

	while(ch < '0' || ch > '9')ch = Gc;

	while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = Gc;}

	return x;
}

LL ans;
int n,bucket[M+5];
int q1[N+5];
LL x,y,q2[N+5];

int main()
{
	reg int h1 = 1,h2 = 1,t1 = 0,t2 = 0;
	n = Read();
	
	for(reg int i = 1; i <= n ; ++i) ++bucket[Read()];
	
	for(reg int i = 1; i <= M ; ++i) while(bucket[i]){q1[++t1] = i;bucket[i]--;}
	
	//q2[1] = 2e18;
	q1[t1+1] = 2e9;
	
	for(reg int i = 2; i <= n ; ++i)
	{
		if(h2 > t2 || (h1 <= t1 && q1[h1] < q2[h2])) x = q1[h1++];
		else x = q2[h2++];
		if(h2 > t2 || (h1 <= t1 && q1[h1] < q2[h2])) y = q1[h1++];
		else y = q2[h2++];
		ans += x+y;
		q2[++t2] = x+y;
	}
	
	printf("%lld",ans);

	return 0;
}
