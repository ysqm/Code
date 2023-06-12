# include <algorithm>
# include <cstring>
# include <cstdio>
# include <queue>
# include <cmath>
# define LL long long
# define reg register
# define N 2000

inline int Read()
{
	int x = 0;char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch <= '9' && ch >= '0') {x = x*10 + (ch^48);ch = getchar();}
	
	return x;
} 

struct Union_Find//普通并查集 
{
	int *F,*Size;
	
	Union_Find(){}
	
	Union_Find(const int n){F = new int [n + 1];Size = new int [n + 1];for(reg int i = 1; i <= n ; ++i) F[i] = i,Size[i] = 1;}
	
	inline int Father(const int x){return F[x];}
	
	inline int Find(int x)
	{
		int cur = x;
		
		while(F[cur] ^ cur) cur = F[cur];
		
		F[x] = cur;
		
		while(x ^ F[x]) F[x = F[x]] = cur;
		
		return cur;
	}
	
	inline int Union(const int x,const int y)
	{
		if(Size[x] < Size[y]) Size[y] += Size[x],F[x] = y;
		else Size[x] += Size[y],F[y] = x; 
	}
} UF;

struct edge
{
	int u,v,wi;
	
	edge(const int Next_=0,const int To_=0,const int wi_=0):u(Next_),v(To_),wi(wi_){}
	
} e[((N*N)>>1) + 42];

inline bool operator < (const edge& a,const edge& b) {return a.wi < b.wi;}

inline int ABS(const int x){return x < 0 ? -x : x;}

int edge_tot,x[N + 42],y[N + 42],n,c,tot,ans;

int main()
{
	n = Read();c = Read();c = c;
	
	for(reg int i = 1; i <= n ; ++i) {x[i] = Read();y[i] = Read();}
	
	for(reg int i = 1; i <= n ; ++i)
		for(reg int j = i+1; j <= n ; ++j)
			if((ABS(x[i]-x[j])*ABS(x[i]-x[j])+ABS(y[i]-y[j])*ABS(y[i]-y[j])) >= c) 
				e[++edge_tot] = edge(i,j,(ABS(x[i]-x[j])*ABS(x[i]-x[j])+ABS(y[i]-y[j])*ABS(y[i]-y[j])));
	
	UF = Union_Find(n);
	
	std::sort(e+1,e+edge_tot+1);
	
	for(reg int i = 1; i <= edge_tot ; ++i)
		if(UF.Find(e[i].u) ^ UF.Find(e[i].v))
		{
			UF.Union(UF.Father(e[i].v),UF.Father(e[i].u));
			
			++tot;ans += e[i].wi;
			
			if(tot == n-1) return printf("%d\n",ans),0; 
		}
	
	puts("-1");
	
	return 0;
}


