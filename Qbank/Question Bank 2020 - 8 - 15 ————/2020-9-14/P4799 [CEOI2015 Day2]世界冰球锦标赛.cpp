# include <set>
# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define ll long long
# define ull unsigned long long

const int N = 1048576;

ll s[2][N+5],n,m,a[45],top1,top2;

int R,top,S;

void Input()
{
	scanf("%lld%lld",&n,&m);
	for(int i = 1; i <= n ; ++i) scanf("%lld",a+i);
}

void dfs(const int cur,const ll sum)
{
	if(sum > m) return ;
	if(cur > R) s[S][++top] = sum;
	else 
	{
		dfs(cur+1,sum);
		dfs(cur+1,sum+a[cur]);
	}
}

void ddfs()
{
	R = n>>1;top = 0;S = 0;
	dfs(1,0);top1 = top;
	R = n;top = 0;S = 1;
	dfs((n>>1)+1,0);top2 = top;
}

void Solve()
{
    Input();
	ddfs();
	std::sort(s[0]+1,s[0]+top1+1);
	ll ans = 0;
	for(int i = 1; i <= top2 ; ++i)
		ans = ans + (std::lower_bound(s[0]+1,s[0]+top1+1,m-s[1][i]+1)-s[0]-1);
	printf("%lld",ans);
}

int main(){Solve();return 0;}
