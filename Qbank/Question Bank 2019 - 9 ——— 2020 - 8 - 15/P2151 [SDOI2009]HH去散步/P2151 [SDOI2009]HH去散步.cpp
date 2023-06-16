# include <cstdio>
# include <cstring>
# define reg register
# define mod 45989

inline int r()
{
	int x = 0;char c = getchar();
	
	while(c < '0' || c > '9')c = getchar();
	
	while(c >= '0' && c <= '9'){x = x * 10 + c - '0';c = getchar();}
	
	return x;
}

struct matrix
{
	int a[150][150];
	int r,c;
	
	matrix(){r = c = 0;memset(a,0,sizeof(a));}
	
	matrix(const int& _r,const int& _c):r(_r),c(_c){memset(a,0,sizeof(a));}
	
	inline void init()
	{
		memset(a,0,sizeof(a));
		
		for(reg int i = 1; i <= 8; ++i) a[i][i] = 1;
	}
	
} ans,f;

int head[70],tot;
struct edge
{
	int from,to;
} e[142];

inline int F(const int& x){return (x & 1) == 0 ? (x - 1) : (x + 1);}

inline void add(const int v,const int u)
{
	e[++tot].to = v;
	
	e[tot].from = head[u];
	
	head[u] = tot;
	
	e[++tot].to = u;
	
	e[tot].from = head[v];
	
	head[v] = tot;	
	
}

inline matrix operator * (const matrix& a,const matrix& b)
{
	matrix res = matrix(a.r,b.c);
	
	for(reg int i = 1; i <= a.r; ++i)
		for(reg int j = 1; j <= b.c; ++j)
			for(reg int k = 1; k <= a.c; ++k) 
				res.a[i][j] = (a.a[i][k] * b.a[k][j] + res.a[i][j]) % mod;
	
	return res;		
}

inline matrix operator ^ (matrix b,int p)
{
	matrix res = b;--p;
		
	for(; p ; p >>= 1,b = b * b) if(p & 1) res = res * b;
		
	return res;	
}

int n = r(),m = r(),t = r() - 1,st = r() + 1,en = r() + 1,print;

int main()
{
	for(reg int i = 1; i <= m; ++i) 
		add(r() + 1,r() + 1);
	
	f.r = f.c = ans.r = tot;ans.c = 1;
	
	//printf("%d %d %d %d %d\n",n,m,t,st,en);
	
	for(reg int i = 1; i <= tot; ++i)
		for(reg int j = head[e[i].to]; j ; j = e[j].from)
			if(j != F(i)){//printf("%d %d anti = %d\n",j,i,F(i));
			++f.a[j][i];}//j 可以转移到 i
	/*for(reg int i = 1; i <= tot; ++i)
		printf("%d\n",e[i].to);
	
	*/
		
	for(reg int i = head[st]; i ;i = e[i].from) ++ans.a[i][1];//第一步就可以转移过去
	
	f = f ^ t;
	for(reg int i = 1; i <= tot; ++i){
		for(reg int j = 1; j <= tot; ++j)
			printf("%d ",f.a[i][j]);
			
		printf("\n");
	}
	f = f * ans;
	
	for(reg int i = head[en]; i ; i = e[i].from)
		print = (print + f.a[F(i)][1]) % mod;
		
	printf("%d",print);
	 
	return 0;
}
