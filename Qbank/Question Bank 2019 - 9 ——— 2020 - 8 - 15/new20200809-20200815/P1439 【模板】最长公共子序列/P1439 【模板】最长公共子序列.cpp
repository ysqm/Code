# include <cstdio>
# include <vector>
# include <queue>
# define reg register
# define N 100000
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

inline int Min(const int a,const int b){return a < b ? a : b;}

int LIS[N + 5],ans,base,a[N + 42],top;
int n;

int main()
{
	#ifdef ONLINE_JUDGE
	#else
    freopen("1.txt","r",stdin);
	#endif
	
	n = Read();
	
	for(reg int i = 1; i <= n ; ++i) a[Read()] = i;
	
	for(reg int i = 1; i <= n ; ++i) LIS[i] = 0x7f7f7f7f;
	
	for(reg int i = 1,x; i <= n ; ++i)
		if((x = a[Read()]) > LIS[top]) LIS[++top] = x;
		else
		{
			reg int l = 1,r = top,mid;
			
			while(l < r)
			{
				mid = (l+r)>>1;
				
				if(LIS[mid] > x) l = mid+1;
				else r = mid;
			}
			LIS[l] = Min(a[i],LIS[l]);
		}
	
	printf("%d",top);
	
	return 0;
}


