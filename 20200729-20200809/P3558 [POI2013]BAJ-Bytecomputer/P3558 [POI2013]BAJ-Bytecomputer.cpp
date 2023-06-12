# include <cstdio>
# include <cstring>
# include <algorithm>
# define reg register
# define N 1000000
# define INF 0x3f3f3f3f 
# define Gc getchar()//*/(SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
char BB[1<<15],*SS=BB,*TT=BB;

inline int Read()
{
	register int x = 0,f = 1;register char ch = Gc;
	
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1;ch = Gc;}
	
	while(ch <= '9' && ch >= '0'){x = x*10 + (ch^48);ch = Gc;}
	
	return f < 0 ? (~x)+1 : x;
}

/*
因为是不下降序列，根据贪心原则，花费的最大值因该就是将整个序列全部变为 1 的代价，切变换最多变为三个数即 0，-1，1 
注意存在无解序列即有如下情况
0,0,0,.....(全是0),-1..... 
*/

inline int Min(const int a,const int b){return a < b ? a : b;}

int f[3][N+5];

int main()
{
	reg int n = Read();

	//memset(f,0x3f,sizeof(f));
	
	for(reg int i = 1 ; i <= n ; ++i) f[1][i] = f[2][i] = f[0][i] = INF;

	f[Read() + 1][1] = 0;

	for(reg int i = 2,x; i <= n ; ++i)
	{
		x = Read();
		
		f[0][i] = f[0][i-1] + x + 1;
		/*
			x == -1 : f[i][-1]
			x == 0  ：f[i][-1] 
			x == 1  : f[i][-1]
		*/
		f[1][i] = Min((x == 0 ? f[1][i-1] : INF),x > -1 ? (f[0][i-1] + (x == 1)) : INF);//0 的转移
		/*
			x == -1 : 
			x == 0  : f[i][-1],f[i][0]
			x == 1  : f[i][-1]
		*/
		f[2][i] = Min(f[2][i-1] + 1 - x,x == 1 ? Min(f[1][i-1],f[0][i-1]) : INF);//1 的转移
		/*
			x == -1 : f[i][1]
			x == 0  : f[i][1]
			x == 1  : f[i][-1],f[i][0],f[i][1]
		*/
	}
	
	/*for(reg int i = 1; i <= n ; ++i) printf("%-5d ",f[0][i] == INF ? -1 : f[0][i]);
	
	puts("");
	
	for(reg int i = 1; i <= n ; ++i) printf("%-5d ",f[1][i] == INF ? -1 : f[1][i]);
	
	puts("");
	
	for(reg int i = 1; i <= n ; ++i) printf("%-5d ",f[2][i] == INF ? -1 : f[2][i]);
	
	puts("");*/
	
	reg int ans = Min(Min(f[0][n],f[1][n]),f[2][n]);
	
	if(ans < INF) printf("%d",Min(Min(f[0][n],f[1][n]),f[2][n]));
	else puts("BRAK");
	
	return 0;
} 
