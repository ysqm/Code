# include <cstdio>
# include <cstring>
# include <algorithm>
# define reg register
typedef unsigned int UL;
typedef long long LL;

inline int Read()
{
	int x = 0;char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch <= '9' && ch >= '0'){x = x*10 + (ch ^ 48);ch = getchar();}
	
	return x;
}

struct Matrix
{
     int column,row;
     bool matrix[142][142];
     Matrix(const int w=0,const int l=0):column(w),row(l){memset(matrix,0,sizeof(matrix));}
};

Matrix t[35];

Matrix operator * (const Matrix& a,const Matrix& b)
{
     Matrix res = Matrix(a.column,b.row);
     for(reg int i = 1; i <= a.column; ++i)
         for(reg int j = 1; j <= b.row; ++j)
             for(reg int k = 1; k <= a.row; ++k)
                 res.matrix[i][j] ^= a.matrix[i][k] & b.matrix[k][j];
     return res;
}

int n,m,q;
UL f[142],d[142],tp[142];

inline void Show(const int fl)
{
	printf("floor %d:\n",fl);
	
	for(reg int i = 1; i <= n ; ++i)
	{
		for(reg int j = 1; j <= n ; ++j)
			printf("%-5d ",t[fl].matrix[i][j]);
		printf("\n");
	}
		
}

inline void Check(const Matrix& a)
{
	memset(tp,0,sizeof(tp));
	
	for(reg int i = 1; i <= n ; ++i)
		for(reg int j = 1; j <= n ; ++j)
			if(a.matrix[i][j]) tp[i] = tp[i]^d[j];
	
	for(reg int i = 1; i <= n ; ++i) d[i] = tp[i];
}

int main()
{
	n = Read();m = Read();q = Read();
	
	for(reg int i = 1; i <= n ; ++i) f[i] = Read();
	
	for(reg int i = 0; i <= 32 ; ++i) t[i] = Matrix(n,n);
	
	for(reg int i = 1; i <= m ; ++i)
	{
		f[140] = Read();f[141] = Read();
		
		t[0].matrix[f[140]][f[141]] = t[0].matrix[f[141]][f[140]] = 1;
	}
	
	for(reg int i = 1; i < 32 ; ++i) t[i] = t[i-1]*t[i-1];
	
	//for(reg int i = 0; i <= 10 ; ++i) Show(i);
	
	for(reg int i = 1; i <= q ; ++i)
	{
		UL ask = Read();
		
		for(reg int j = 1; j <= n ; ++j) d[j] = f[j];
		
		for(reg int i = 0; i < 32 ; ++i)
			if(ask & (1u<<i)) Check(t[i]);
			
		printf("%lld\n",d[1]);
	}
	
	
	return 0;
}
