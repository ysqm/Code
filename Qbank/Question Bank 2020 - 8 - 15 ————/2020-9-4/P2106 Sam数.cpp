# include <cstdio>
# include <cstring>
# define reg register
# define LL long long

const LL mod = 1e9+7;

inline int Max(const int x,const int y){return x > y ? x : y;}
inline int Min(const int x,const int y){return x < y ? x : y;}

struct Matrix
{
    int width,length;
    LL matrix[15][15];

    Matrix(const int w=0,const int l=0):width(w),length(l){memset(matrix,0,sizeof matrix);}
};

Matrix operator * (const Matrix& a,const Matrix& b)
{
    Matrix res = Matrix(a.width,b.length);
    for(reg int i = 1; i <= a.width; ++i)
        for(reg int j = 1; j <= b.length; ++j)
            for(reg int k = 1; k <= a.length; ++k)
                res.matrix[i][j] = (res.matrix[i][j] + a.matrix[i][k] * b.matrix[k][j]%mod)%mod;
    return res;
}

inline Matrix qpow(Matrix x,LL p)
{
    Matrix res = Matrix(10,10);
    for(reg int i = 1; i <= 10 ; ++i) res.matrix[i][i] = 1;
    for( ; p ; p>>=1,x = x*x) 
		if(p&1) 
			res = res*x;
    return res;
}

LL k;

int main()
{
    scanf("%lld",&k);

    /*if(k == 1)
    {
        printf("10\n");
        return 0;
    }*/

    Matrix base = Matrix(10,10),ans = Matrix(1,10);

    for(reg int i = 1; i <= 10 ; ++i)   
        for(reg int j = Max(i-2,1); j <= Min(i+2,10) ; ++j)
            base.matrix[i][j] = 1;

    for(reg int i = 1; i <= 10 ; ++i) ans.matrix[1][i] = 1;

    base = qpow(base,k-1);

    ans = ans*base;

    LL ans1 = 0;

    for(reg int i = 0; i <= 9 ; ++i) ans1 = (ans1+ans.matrix[1][i])%mod;

    printf("%lld",ans1);

    return 0;
}
