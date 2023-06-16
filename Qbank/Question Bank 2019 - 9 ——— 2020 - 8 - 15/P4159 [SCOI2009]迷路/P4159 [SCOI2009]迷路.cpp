# include <cstdio>
# include <cstring>
# define reg register

struct matrix
{
	int len;
	int Matrix[105][105];
	
	matrix(){memset(Matrix,0,sizeof(Matrix));len = 0;}
	
	inline void clear(){memset(Matrix,0,sizeof(Matrix));len = 0;}
	
	inline void init()
	{
		memset(Matrix,0,sizeof(Matrix));
		for(reg int i = 1; i <= len; ++i) Matrix[i][i] = 1;
	}
	
	 inline matrix operator * (const matrix &rhs) const
    {
        matrix res;res.len = len;
        for (reg int i = 1; i <= len; ++i)
            for (reg int j = 1; j <= len; ++j){
                for (reg int k = 1; k <= len; ++k) res.Matrix[i][j] += Matrix[i][k] * rhs.Matrix[k][j]; 
                    
                res.Matrix[i][j] %= 2009; 
            }
        return res; 
    }

    inline matrix operator ^ (int p) const
    {
        matrix res,x = *this; res.len = len;res.init();
        for (; p; p >>= 1, x = x * x)
            if (p & 1) res = res * x; 
        return res; 
    }
} ma;

int n,m,T;

int main()
{
    scanf("%d%d", &n, &T); 
    m = n * 9; 

    ma.len = m;

    for (reg int i = 1,xy; i <= n; ++i){
        for (reg int j = 1; j <= 8; ++j) ma.Matrix[i + j * n][i + (j - 1) * n] = 1; 
        for (reg int j = 1; j <= n; ++j){
            scanf("%1d", &xy); 
            if (xy) ma.Matrix[i][j + (xy - 1) * n] = 1; 
        }
    }

    ma = ma ^ T; 
    printf("%d", ma.Matrix[1][n]); 

    return 0; 
}
