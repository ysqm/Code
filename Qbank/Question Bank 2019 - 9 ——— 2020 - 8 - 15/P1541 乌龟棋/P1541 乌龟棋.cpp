# include <cstdio>
# define reg register

inline void in(int& x)
{
	x = 0; char ch = getchar();
	
	while(ch < '0' || ch > '9')ch = getchar();

	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}


}

inline int Read()
{
	int x = 0; char ch = getchar();
	
	while(ch < '0' || ch > '9')ch = getchar();
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	return x;
}

inline int Max(const int& a,const int b){return a > b ? a : b;}
int f[125][125][125][125],n,m,g[5],num[400];

int main()
{
	in(n);in(m);
	
	for(reg int i = 1; i <= n; ++i) in(num[i]);
	
	for(reg int i = 1; i <= m; ++i) ++g[Read()];
	
	f[0][0][0][0] = num[1];
	
	for(reg int i = 0; i <= g[1]; ++i)
		for(reg int j = 0; j <= g[2]; ++j)
			for(reg int k = 0; k <= g[3]; ++k)
				for(reg int l = 0; l <= g[4]; ++l){
					reg int res = 1 + i + (j << 1) + k * 3 + (l << 2);
					if(i != 0) f[i][j][k][l] = Max(f[i][j][k][l],f[i - 1][j][k][l] + num[res]);
					if(j != 0) f[i][j][k][l] = Max(f[i][j][k][l],f[i][j - 1][k][l] + num[res]);
					if(k != 0) f[i][j][k][l] = Max(f[i][j][k][l],f[i][j][k - 1][l] + num[res]);
					if(l != 0) f[i][j][k][l] = Max(f[i][j][k][l],f[i][j][k][l - 1] + num[res]);
				}
				
	printf("%d",f[g[1]][g[2]][g[3]][g[4]]);
	
	return 0;
}
