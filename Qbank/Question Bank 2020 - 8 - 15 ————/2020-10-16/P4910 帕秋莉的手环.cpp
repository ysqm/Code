# include <set>
# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define LL long long
# define mod 1000000007

struct Matrix
{
    LL c[3][3];
    int r,l;
    //Matrix(){}
    Matrix(const int l_=0,const int r_=0):r(r_),l(l_){memset(c,0,sizeof(c));}
    Matrix operator * (const Matrix& a)const
    {
        Matrix res = Matrix(l,a.r);
        for(int i = 0; i < l ; ++i)
            for(int j = 0; j < a.r ; ++j)
                for(int k = 0; k < a.l ; ++k)
                    res.c[i][j] = (res.c[i][j] + c[i][k] * a.c[k][j])%mod;
        return res;
    }
} base,f;

Matrix qpow(Matrix x,LL p)
{
    Matrix res = Matrix(x.l,x.r);
    res.c[0][0] = res.c[1][1] = 1;
    for(; p ; p>>=1,x = x*x) if(p&1) res = res*x;
    return res;
}

int T;
LL a;

int main()
{
    freopen("ysqm.in","r",stdin);
	for(scanf("%d",&T); T ; T-- )
    {
        scanf("%lld",&a);
        f.c[0][0] = 0;
        f.c[0][1] = f.c[1][1] = f.c[1][0] = 1;
        f.l = f.r = 2;
        base.l = 2;base.r = 2;
        base.c[0][0] = base.c[0][1] = 0;
        base.c[0][0] = 2;
        base.c[0][1] = 1;
        f = qpow(f,a-1);
        base = base*f;
        printf("%lld\n",base.c[0][1]+base.c[1][1]);
    }
    return 0;
}
