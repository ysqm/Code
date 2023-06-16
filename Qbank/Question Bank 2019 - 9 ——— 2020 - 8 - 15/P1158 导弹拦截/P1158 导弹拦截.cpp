# include <cstdio>
# include <algorithm>
# define N 100000
# define reg register
using namespace std;

inline void in(int& x)
{
	x = 0; char ch = getchar();int f = 1;
	
	while(ch < '0' || ch > '9'){if(ch == '-') f = -1;ch = getchar();}
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	x *= f;
}

struct missile
{
	int First_Distance,Second_Distance;
	
	bool operator < (const missile b) const
	{
		return First_Distance < b.First_Distance;
	}
} dis[N + 42];

int fx,fy,sx,sy,n,f[N + 42],ans = 0x7f7f7f7f;

int main()
{
	in(fx);in(fy);in(sx);in(sy);in(n);
	
	for(reg int i = 1,x,y; i <= n; ++i){
		in(x);in(y);
		dis[i].First_Distance = (fx - x) * (fx - x) + (fy - y) * (fy - y);
		dis[i].Second_Distance = (sx - x) * (sx - x) + (sy - y) * (sy - y);
	}
	
	sort(dis + 1, dis + n + 1);
	
	for(reg int j = n; j ; --j){
		f[j] = dis[j].Second_Distance;
		f[j] = f[j] > f[j + 1] ? f[j] : f[j + 1];
	}
	
	for(reg int i = 1; i <= n ; ++i) 
		ans = ans > f[i + 1] + dis[i].First_Distance ?  f[i + 1] + dis[i].First_Distance : ans;
	
	printf("%d\n",ans);
	return 0;
}
