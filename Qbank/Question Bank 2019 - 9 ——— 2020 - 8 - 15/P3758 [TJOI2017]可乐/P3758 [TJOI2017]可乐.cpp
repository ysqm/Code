# include <cstdio>
# include <cstring>
# include <algorithm>
# define reg register
# define mod 2017
# define N 2500
# define LL long long

inline int Read()
{
	int x = 0,f = 1;char ch = getchar();
	
	while(ch < '0' || ch > '9') {if(ch == '-')f = -1;ch = getchar();}
	 
	while(ch >= '0' && ch <= '9') {x = x*10 + (ch ^ 48);ch = getchar();}
	
	return x * f;
}

struct Matrix
{
	int r,l;
	int matrix[42][42];
	
	Matrix(const int w=0,const int l=0):r(w),l(l){}
} ks,G;

int n,m,t;

Matrix operator * (const Matrix& a,const Matrix& b)
{
	Matrix res = Matrix(n,n);
	
	std::memset(res.matrix,0,sizeof(res.matrix));
	
	for(reg int i = 0; i <= n; ++i)
		for(reg int j = 0; j <= n; ++j)
			for(reg int k = 0; k <= n; ++k)
				res.matrix[i][j] = (res.matrix[i][j] + a.matrix[i][k] * b.matrix[k][j])%mod;
				
	return res;
}

int main()
{
	n = Read();m = Read();

	for(reg int i = 1; i <= n ; ++i) G.matrix[i][0] = 1;
	
	for(reg int i = 0; i <= n ; ++i) ks.matrix[i][i] = G.matrix[i][i] = 1;
	
	for(reg int i = 1,x,y; i <= m ; ++i)
	{
		x = Read();y = Read();
		
		G.matrix[x][y] = 1;
		G.matrix[y][x] = 1;
	}
	
	t = Read();
	
	while(t)
	{
		if(t & 1) ks = ks * G;
		t >>= 1;
		G = G * G;
	}
	
	/*for(int i = 0; i <= n ; ++i)
    {
    	for(int j = 0; j <= n ; ++j) printf("%d ",G.matrix[i][j]);
    	
    	puts("");
	}
	
	for(int i = 0; i <= n ; ++i)
    {
    	for(int j = 0; j <= n ; ++j) printf("%d ",ks.matrix[i][j]);
    	
    	puts("");
	}
	*/
	int ans = 0;
	
	for(reg int i = 0; i <= n; ++i) ans = (ans + ks.matrix[1][i])%mod;
	
	printf("%d\n",ans);
	
	return 0;
}
