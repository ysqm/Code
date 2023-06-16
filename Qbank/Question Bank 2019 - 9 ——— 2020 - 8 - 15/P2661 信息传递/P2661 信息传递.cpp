# include <cstdio>
# include <queue>
# include <cstring>
# define N 200000
# define R register
# define inf 1000000000
using namespace std;
inline int re()
{
	int f = 1,x = 0;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}
int a[N + 42],n,ans = inf,ine[N + 42];
bool vis[N + 42],hisvis[N + 42];
inline void SPFA(int s,int cnt);
int main()
{	
	n = re();
	for(R int i = 1; i <= n ;i++)
	{
		a[i] = re();
	}
	for(R int i = 1; i <= n ;i++)
		SPFA(i,0);
	printf("%d",ans);
	return 0;
}
inline void SPFA(int s,int cnt)
{
	if(hisvis[s]) return;
	if(vis[s]){
		ans = min(ans,cnt - ine[s]);
	}
	else{
		vis[s] = true;
		ine[s] = cnt;
		SPFA(a[s],cnt + 1);
		vis[s] = false;
		hisvis[s] = true;
	}
	return;
}
