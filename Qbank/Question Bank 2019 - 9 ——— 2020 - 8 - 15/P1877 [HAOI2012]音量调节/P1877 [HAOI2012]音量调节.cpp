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

int s,n,ml,a[55],f[55][1042],ans;

inline void dfs(int i,const int j)
{
	if(f[i][j] || j > ml || j < 0) return;
	else f[i][j] = 1;
	if(i++ == n){ans = Max(ans,j);return;}
	dfs(i, j + a[i]);
	dfs(i, j - a[i]);
}

int main()
{
	ans = -1;
	
	in(n);in(s);in(ml);
	
	for(register int i = 1; i <= n; ++i) in(a[i]);
	
	dfs(0,s);
	
	printf("%d",ans);
	
	return 0;
}
