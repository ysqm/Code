# include <cstdio>
# include <algorithm>
# define reg register
# define N 32768
# define LL long long

inline int Read()
{
	int x = 0,f = 1;char ch = getchar();
	
	while(ch < '0' || ch > '9') {if(ch == '-')f = -1;ch = getchar();}
	 
	while(ch >= '0' && ch <= '9') {x = x*10 + (ch ^ 48);ch = getchar();}
	
	return x * f;
}

int f[N + 42][5];

int main()
{
	f[0][0] = 1;
	
	for(reg int j = 1; j <= 182 ; ++j)
			for(reg int k = j * j; k <= N ; ++k)
				for(reg int i = 1; i <= 4 ; ++i)
					f[k][i] += f[k-j*j][i-1];
	
	for(reg int i = 1; i <= N ; ++i) f[i][0] = f[i][1] + f[i][2] + f[i][3] + f[i][4];
	
	reg int t;
	
	t = Read();
	
	while(t--) printf("%d\n",f[Read()][0]);
	
	return 0;
}
