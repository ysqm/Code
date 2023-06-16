# include <cstdio>
# include <algorithm>
# define reg register
//using namespace std;

inline void in(int& x)
{
	x = 0; char ch = getchar();int f = 1;
	
	while(ch < '0' || ch > '9'){if(ch == '-') f = -1;ch = getchar();}
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	x *= f;
}

int f[502][502],n,ans = 0;

int main()
{
	in(n);
	
	for(reg int i = 1; i <= n ; ++i)
		for(reg int j = i + 1; j <= n; ++j){
			in(f[i][j]);
			f[j][i] = f[i][j];
		}
	
	for(reg int i = 1; i <= n ; ++i)
	{
		std::sort(f[i] + 1,f[i] + n + 1);
		
		if(f[i][n - 1] > ans) ans = f[i][n - 1];
	}
	
	printf("1\n%d",ans);
	return 0;
}
