# include <ctime>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define reg register
# define LL long long
# define reg register
const int mod=1e8; 

struct Matrix_
{
    int Matrix[4][4],r,l;

    Matrix_(const int R=0,const int L=0,const bool Type=0):r(R),l(L)
    {
        memset(Matrix,0,sizeof(Matrix));
        if(Type){for(register int i = 1; i <= r ; ++i) Matrix[i][i]=1;}
    }

    Matrix_ operator * (const Matrix_& a)const 
    {
        Matrix_ res = Matrix_(l,a.r);

        for(reg int i = 1; i <= l; ++i)
            for(reg int j = 1; j <= a.r ; ++j)
                for(reg int k = 1; k <= r; ++k)
                    res.Matrix[i][j] = (res.Matrix[i][j] + Matrix[i][k] * (LL)a.Matrix[k][j]%mod)%mod;

        return res;
    }
    

    inline Matrix_ operator ^ (int p)
    {
        Matrix_ res = Matrix_(r,l,1),x = *this;

        for(; p ; p>>=1,x = x*x) if(p&1) res = res*x;

        return res;
    }
};

inline int Gcd(const int x,const int y){return y ? Gcd(y,x%y) : x;}

int main()
{
    int n,m,d;

    scanf("%d%d",&n,&m);

    d = Gcd(n,m)-1;

    Matrix_ a = Matrix_(2,2),ans = Matrix_(2,1);

    a.Matrix[1][2] = a.Matrix[2][2] = a.Matrix[2][1] = 1;

    a = a^d;

    ans.Matrix[1][1] = ans.Matrix[1][2] = 1;

    ans = ans*a;

    printf("%d",ans.Matrix[1][1]);

    return 0;
}
