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
vector < int > vis,book;
void dfs(int ai,int bj,int an,int b,LL sum)
{
	if(sum >= ans) return;
	if(an){
		for(int i = ai + 1;i <= n;i++){
			vis.push_back(i);
			dfs(i,0,an - 1,b,sum);
			vis.pop_back();
		}
	}
	else if(b){
		for(int j = bj + 1;j <= m;j++){
			LL s = 0;
			if(b == c)
				for(int i = 1;i < vis.size();i++)
					s += abs(a[vis[i]][j] - a[vis[i - 1]][j]);
			else {
				int ae = book[book.size() - 1];
				s += abs(a[vis[0]][j] - a[vis[0]][ae]);
				for(int i = 1;i < vis.size();i++)
					s += abs(a[vis[i]][j] - a[vis[i]][ae]) + abs(a[vis[i]][j] - a[vis[i - 1]][j]);
			}
			book.push_back(j);
			dfs(0,j,an,b - 1,sum + s);
			book.pop_back();
		}
	}
	else {
		ans = sum;
	}
}
int main()
{
	freopen("submatrix.in","r",stdin);
	freopen("submatrix.out","w",stdout);
	n = re();
	m = re();
	r = re();
	c = re();
	for(register int i = 1;i <= n;i++)
		for(register int j = 1;j <= m;j++)
			a[i][j] = re();
	dfs(0,0,r,c,0);
	printf("%d",ans);
	return 0;
} 
