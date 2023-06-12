# include <ctime>
# include <cstdlib> 
# include <cstdio>
# include <cstring>
# include <algorithm>
# define reg register
# define Gc getchar()

inline int Read()
{
	register int x = 0;register char ch = Gc;
	
	while(ch < '0' || ch > '9') ch = Gc;
	
	while(ch <= '9' && ch >= '0'){x = x*10 + (ch^48);ch = Gc;}
	
	return x;
}

const int count = 10;

int modular_exp(const int a,const int m,const int n)
{
	if(m == 0) return 1;
	if(m == 1) return (a % n);
	long long w = modular_exp(a,m>>1,n);
	w = w*w%n;
	if(m&1) w = w*a%n;
	return w; 
}

inline bool Miller_Rabin(const int n)
{
	if(n == 2) return true;
	for(reg int i = 0; i < count ; ++i)
	{
		int a = rand() % (n-2) + 2;
		if(modular_exp(a,n,n) != a) return false;
	}
	return true;
}

int n,a[105];
int vis[105]; 

int main()
{
    srand(time(NULL));
    
    scanf("%d",&n);
    
    for(reg int i = 1; i <= n ; ++i) if(Miller_Rabin(a[i] = Read())) vis[i] = 1;
    
    for(reg int i = 1; i <= n ; ++i) if(vis[i]) printf("%d ",a[i]);

    return 0;
}
