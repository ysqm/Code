# include <cstdio>
const int mod = 1e9+7;

# define Gc getchar()//(SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
char BB[1<<15],*SS=BB,*TT=BB;
inline int Read()
{
    register long long x = 0;register int f = 1;char ch = Gc;

    while(ch < '0' || ch > '9'){if(ch == '-') f = -1;ch = Gc;}

    while(ch >= '0' && ch <= '9'){x = (x*10+(ch^48))%mod;ch = Gc;}

    return f < 0 ? mod-x : x;
}

int n,m,a[105],d[1000005],tot;

int Calc(const int x)
{
    long long res = 0;
    for(register  int i = n; i >= 0; --i) 
		res = (res*x + a[i])%mod;
    return res;
}

int main()
{
    scanf("%d%d",&n,&m);

    for(register int i = 0; i <= n ; ++i)  a[i] = Read();

    for(register int i = 1; i <= m ; ++i) if(Calc(i) == 0) d[++tot] = i;
    
    printf("%d\n",tot);
    
    for(register int i = 1; i <= tot ; ++i) printf("%d\n",d[i]);
    
    return 0; 
}
