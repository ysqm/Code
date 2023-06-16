# include <cstdio>
# include <algorithm>
# include <bitset>
# include <cstring>
# define reg register
# define N 100000000
# define LL long long
using namespace std;

inline void in(int& x)
{
	x = 0; char ch = getchar();int f = 1;
	
	while(ch < '0' || ch > '9'){if(ch == '-') f = -1;ch = getchar();}
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	x *= f;
}

inline int Max(const int& a,const int b){return a > b ? a : b;}

int w,n,f[42][1042][3],a[1042];

inline int dfs(int i,int j,int k)
{
	if(j > n) return 0;
	if(f[i][j][k] != -1) return f[i][j][k];
	int temp = 0,tmp = 0;
	if(i < w && a[j] != k) temp = dfs(i + 1,j + 1, -1 * k + 3) + 1;
	tmp = dfs(i,j + 1,k) + (a[j] == k ? 1 : 0);
	return f[i][j][k] = Max(temp,tmp);
}

int main()
{
	in(n);in(w);
	
	for(register int i = 1; i <= n; ++i) in(a[i]);
	
	for(reg int i = 0; i <= w; ++i)
		for(reg int j = 1; j <= n; ++j)
			f[i][j][1] = f[i][j][2] = -1;
	
	printf("%d",dfs(0,1,1));
	
	return 0;
}
