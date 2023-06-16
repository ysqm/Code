# include <cstdio>
# include <algorithm>
# include <queue>
# include <cmath>
using namespace std;
const int N = 400,M = 5e5,inf = 2147483647;
inline int re()
{
    int x=0,f=1;char c=getchar();
    while(c>'9'||c<'0') {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') {x=x*10+c-'0'; c=getchar();}
    return x*f;
}
struct Point 
{
    int city, t, x, y; // city 城市编号，t 列车费用
} p[N + 42];
inline Point rct(const Point &a, const Point &b, const Point &c) 
{
		Point d;
        int P = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y),
            Q = (b.x - c.x) * (b.x - c.x) + (b.y - c.y) * (b.y - c.y),
            R = (c.x - a.x) * (c.x - a.x) + (c.y - a.y) * (c.y - a.y);
        if(P + Q == R)
            d.x = a.x + c.x - b.x,
            d.y = a.y + c.y - b.y;
        else if(P + R == Q)
            d.x = b.x + c.x - a.x,
            d.y = b.y + c.y - a.y;
        else
            d.x = a.x + b.x - c.x,
            d.y = a.y + b.y - c.y;
		 return d;  
}
inline double dis(const Point a,const Point b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int s,t,A,B,n;
double g[N + 42][N + 42];
int main()
{
	n = re();
	double suma,ans;
	while(n--){
		ans = inf;
		s = re();
		t = re();
		A = re();
		B = re();
		s *= 4;
		for(register int i = 0;i < s;){
			p[++i].x = re();
			p[i].y = re();
			p[++i].x = re();
			p[i].y = re();
			p[++i].x = re();
			p[i].y = re();
			i++;
			p[i] = rct(p[i - 3],p[i - 2],p[i - 1]);
			p[i - 3].t = p[i - 2].t = p[i - 1].t = p[i].t = re();
			p[i - 3].city = p[i - 2].city = p[i - 1].city = p[i].city = i/4;
		}
		for(register int i = 1;i <= s; i++)
			for(register int j = 1;j <= s; j++)
				if(p[i].city == p[j].city)
					g[j][i] = g[i][j] = dis(p[j],p[i]) * p[i].t;
				else g[j][i] = g[i][j] = dis(p[j],p[i]) * t;
		
		for(register int k = 1;k <= s; k++)
			for(register int i = 1;i <= s; i++)
				for(register int j = 1;j <= s; j++){
					suma = g[i][k] + g[k][j];
					if(suma < g[i][j])
						g[i][j] = suma; 
				}
		for(int i = 1; i <= s; i++)
            for(int j = 1; j <= s; j++)
                if(p[i].city == A && p[j].city == B)
                    ans = min(ans, g[i][j]);
		printf("%.1lf\n",ans);
	} 
	return 0;
}
