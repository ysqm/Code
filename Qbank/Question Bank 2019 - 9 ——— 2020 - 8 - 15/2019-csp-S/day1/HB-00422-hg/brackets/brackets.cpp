#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

const int maxn = 5e5 + 100;
typedef long long ll;

char C[maxn];
int dot[maxn];

int read()
{	int s = 1,w = 0;
	char ch = getchar();
	while(!isdigit(ch))	{	if(ch == '-')	s = -1;ch = getchar();}
	while(isdigit(ch))	w = w * 10 + ch - '0',ch = getchar();
	return s * w;
}
struct edge
{	int next,to;
}s[maxn << 1];
int head[maxn],ecnt;
void add(int u,int v)
{	s[++ecnt].next = head[u];
	s[ecnt].to = v,head[u] = ecnt;
}
int S[maxn],cnt[maxn],aa[maxn],f[maxn],sum[maxn];
void dfs(int u,int fa)
{	S[u] = S[fa] + dot[u];
	if(dot[u] > 0)	sum[u] = sum[fa] + 1;
	else	
		if(sum[fa] > 0)	sum[u] = sum[fa] - 1,aa[u]++;
		else	sum[u] = sum[fa];
	if(S[u] == 0 && sum[u] == 0)	cnt[u] = cnt[fa] + 1;
	else	cnt[u] = cnt[fa];
	if(cnt[u] > 0)	aa[u] += aa[fa] + cnt[u];
	else	aa[u] += aa[fa];
	for(int i = head[u];i;i = s[i].next)
	{	int v = s[i].to;
		if(v == fa)	continue;
		dfs(v,u);
	}
}

int main()
{	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	int n = read();
	cin.getline(C,sizeof(C));
	//dot[0] = -1;
	for(int i = 0;i < n;i++)
	{	if(C[i] == '(')	dot[i + 1] = 1;
		else	dot[i + 1] = -1;
		sum[i] += dot[i];
	}
	for(int i = 2;i <= n;i++)
	{	f[i] = read();
		add(f[i],i),add(i,f[i]);
	}
	//dfs(1,0);
	ll ans = 0,t = 0;
	for(int i = 1;i <= n;i++)
	{	for(int j = 1;j <= i;j++)
		{	int mid = (i + j) >> 1;
			if(sum[i] - sum[j - 1] == 0 && sum[mid] - sum[j - 1] > 0)
				t++;
		}
		ans ^= (t * i);
		t = 0;
	}
	printf("%lld\n",ans);
	return 0;
}
