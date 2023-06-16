# include <cstdio>
# include <cstring>
# define reg register

struct matrix
{
	int a[10][10];
	int r,c;
	
	matrix(){r = c = 0;memset(a,0,sizeof(a));}
	
	matrix(const int& _r,const int& _c):r(_r),c(_c){memset(a,0,sizeof(a));}
	
	inline void init()
	{
		memset(a,0,sizeof(a));
		
		for(reg int i = 1; i <= 8; ++i) a[i][i] = 1;
	}
	
} f;

inline matrix operator * (const matrix& a,const matrix& b)
{
	matrix res = matrix(a.r,b.c);
	
	for(reg int i = 1; i <= a.r; ++i)
		for(reg int j = 1; j <= b.c; ++j)
			for(reg int k = 1; k <= a.c; ++k) 
				res.a[i][j] = (a.a[i][k] * b.a[k][j] + res.a[i][j]) % 1000;
	
	return res;		
}

inline matrix operator ^ (matrix b,int p)
{
	matrix res = matrix(b.r,b.c);res.init();
		
	for(; p ; p >>= 1,b = b * b) if(p & 1) res = res * b;
		
	return res;	
}

int n;

int main()
{
	scanf("%d",&n);f.r = f.c = 8;
	
	f.a[1][2] = f.a[1][8] = f.a[2][1] = f.a[2][3] = f.a[3][2] = f.a[3][4] = f.a[4][3] = f.a[4][5] = f.a[6][5] = f.a[6][7] = f.a[7][8] = f.a[7][6] = f.a[8][7] = f.a[8][1] = 1;
	
	printf("%d",(f = f ^ n).a[1][5]);
	
	return 0;
}
