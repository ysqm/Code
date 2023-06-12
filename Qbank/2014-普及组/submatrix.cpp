# include <cstdio>
# include <algorithm>
# include <vector>
# include <cmath>
# define N 16
using namespace std;
typedef long long LL;
inline int re()
{
    int x=0,f=1;char c=getchar();
    while(c>'9'||c<'0') {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') {x=x*10+c-'0'; c=getchar();}
    return x*f;
}
int n,m,r,c;
LL ans = 1e18;
int a[N + 42][N + 42];
void dfs()
{
	
}
int main()
{
	
	n = re();
	m = re();
	r = re();
	c = re();
	for(register int i = 1;i <= n;i++)
		for(register int j = 1;j <= m;j++)
			a[i][j] = re();
	
	printf("%d",ans);
	return 0;
} 
