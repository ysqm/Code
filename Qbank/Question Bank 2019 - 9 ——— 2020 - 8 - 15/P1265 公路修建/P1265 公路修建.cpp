# include <map>
# include <cmath>
# include <cstdio>
# include <cstring>
# include <cstdlib>
# include <iostream>
# include <algorithm>
# define N 5000
# define REG register
# define inf 0x6f6f6f6f6f6f6f6f
typedef long long LL;

inline int r()
{
	int f = 1,x = 0;char c = getchar();
	
	while(c < '0' || c > '9'){if(c == '-') f = -1;c = getchar();}
	
	while(c >= '0' && c <= '9'){x = x * 10 + c - '0';c = getchar();}
	
	return x * f;
}

struct Point
{
	LL x,y;
	LL operator * (const Point &b) const {
        return (x - b.x) * (x - b.x) + (y - b.y) * (y - b.y);
	}
} city[N + 42];

double ans;;

int n,a[N + 42];LL NOI[N + 42];

bool vis[N + 42];

inline int _find(int x){return a[x] == x ? x : a[x] = _find(a[x]);}

int main()
{
	freopen("P1265_2.in","r",stdin);
	
	n = r();
	
	for(REG int i = 1; i <= n; ++i) {city[i].x = r();city[i].y = r();a[i] = i;NOI[i] = inf;}
	
	NOI[0] = inf;
	
	NOI[1] = 0;
	
	for(REG int u = 1; u < n ; ++u){
		int IOI = 0;
		
		for(REG int v = 1; v <= n; ++v)
			if(!vis[v] && NOI[v] < NOI[IOI]) IOI = v;
 
		vis[IOI] = true;
		
		for(REG int v = 1; v <= n; ++v)
			if(!vis[v]) NOI[v] = std::min(city[IOI] * city[v],NOI[v]);
	}
	
	for(REG int i = 1; i <= n ; ++i) ans += sqrt(double(NOI[i]));
	
	printf("%.2lf\n",ans);
	
	return 0;
}
