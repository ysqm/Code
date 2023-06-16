# include <cstdio>
# include <cstdlib>
# include <algorithm>
# include <ctime>
# define reg register
# define FANGCHONGMING 1e-9

typedef long long LL;

inline int Read()
{
	reg int x = 0;reg char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch <= '9' && ch >= '0'){x = x*10 + (ch ^ 48);ch = getchar();}
	
	return x;
}

inline int exgcd(reg int a,reg int b,reg int& x,reg int& y)
{
	if(b == 0){x = 1;y = 0;return a;}
	
	reg int d = exgcd(b,a % b,y,x);
	
	y -= a / b * x;
	
	return d;
}

inline int ABS(reg const int x){return x < 0 ? -x : x;}
inline int Min(reg const int x,reg const int y){return x < y ? x : y;}
inline int Max(reg const int x,reg const int y){return x > y ? x : y;}

bool vis[1000042];
int c[42],p[42],L[42],n,st;

inline bool check(const int M)
{
	reg int a,b;
	
	for(reg int i = 1; i <= n ; ++i)
		for(reg int j = i+1; j <= n ; ++j)
		{
			reg int pij = p[i]-p[j],m = M,xji = c[j]-c[i];
			
			reg int d = exgcd(pij,m,a,b);
			
			if(xji%d) continue;
			
			xji /= d;m = ABS(m/d);//要特别注意这里可能是负数。 
			
			a = (a*xji%m + m) % m;
			
			if(a <= Min(L[i],L[j])) return false;
		}
		
	return true;
}

/*inline void Tuihuo(int& ans)
{
	int Cur = st;
	
	double Now_Temp_FANGCHONGMING = 1e4;
	
	while(Now_Temp_FANGCHONGMING-0 > FANGCHONGMING)
	{
		int TRY_TIMES_FANGCHONGMING = 0;
		
		while(vis[Cur] && (++TRY_TIMES_FANGCHONGMING <= 100)) Cur = rand() % (ans-st+1) + st;
		
		if(TRY_TIMES_FANGCHONGMING > 100) break;
		
		vis[Cur] = 1;
		
		if(check(Cur)) ans = Cur;
		
		Now_Temp_FANGCHONGMING*=0.99;
	}
}*/

int main()
{
	//srand(time(NULL));
	
	n = Read();
	
	for(reg int i = 1; i <= n ; ++i) {st = Max(c[i] = Read(),st);p[i] = Read();L[i] = Read();}
	
	for(reg int i = st;  ; ++i) if(check(i)) {printf("%d\n",i);return 0;}
	
	//int ans = 1e6;
	
	//for(reg int i = 1; i <= 500 ; ++i) Tuihuo(ans);
	
	//printf("%d",ans);
}
