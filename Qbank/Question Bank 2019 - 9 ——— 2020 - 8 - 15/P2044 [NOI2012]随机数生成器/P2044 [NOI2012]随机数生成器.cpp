# include <cstdio>
# include <cmath>

typedef long long LL;

inline LL Read()
{
	register LL x = 0;register char c = getchar();
	
	while(c < '0' || c > '9') c = getchar();
	
	while(c >= '0' && c <= '9') {x = x * 10 + (c ^ 48);c = getchar();}
	
	return x;
}

struct Matrix
{
	LL a[3][3];
	
	Matrix(){a[0][0] = a[1][0] = a[2][0] = a[0][1] = a[1][1] = a[1][2] = a[2][0] = a[2][1] = a[2][2] = 0;}
	
	inline void Init(){a[0][0] = a[1][1] = a[2][2] = 1;}
} A,B;

inline LL Multiply(LL x,LL y,const LL& mod)
{
	LL res = 0;
	
	for(; x ; x >>= 1,y = (y << 1) % mod) 
		if(x & 1) res = (res + y) % mod;
	
	return res;
}

inline LL Fast_Pow(LL x,LL p,const LL& mod)
{
	LL res = 1;
	
	for(; p ; p >>= 1,x = Multiply(x,x,mod)) 
		if(p & 1) res = Multiply(res,x,mod);
	
	return res;
}

inline Matrix Matrix_Multiply(Matrix& x,Matrix& y,const LL& mod)
{
	Matrix res = Matrix();
	
	for(register int i = 1 ; i <= 2 ; ++i)
        for(register int j = 1 ; j <= 2 ; ++j)
            for(register int k = 1 ; k <= 2 ; ++k)
				res.a[i][j] = (res.a[i][j] + Multiply(x.a[i][k],y.a[k][j],mod)) % mod;
				
	return res;
}

inline Matrix Matrix_Fast_Pow(Matrix x,LL p,const LL& mod)
{
	Matrix res;res.Init();
	
	for(; p ; p >>= 1,x = Matrix_Multiply(x,x,mod)) 
		if(p & 1) res = Matrix_Multiply(res,x,mod);
	
	return res;
}

LL m = Read(),a = Read(),c = Read(),x = Read(),n = Read(),g = Read();

int main()
{
	A.a[1][1] = x;A.a[1][2] = 1;
	
	B.a[1][1] = a;B.a[2][1] = c;B.a[2][2] = 1;
	
	B = Matrix_Fast_Pow(B,n,m);
	
	A = Matrix_Multiply(A,B,m);
	
	printf("%lld",A.a[1][1] % g);
	
	return 0;
}
