# include <set>
# include <queue> 
# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define N 200000
# define cos std::cos
# define sin std::sin
# define acos std::acos
# define sort std::sort
# define Max_Rand_Times 10
# define idx(k) xpf[k].id 

typedef long long LL;

struct Point
{
    LL x,y;
    int id;
    double rx;

    Point(const LL x_ = 0,const LL y_ = 0):x(x_),y(y_){}
};

inline bool operator < (const Point& a,const Point& b){return a.rx < b.rx;}

inline LL distance(const LL x,const LL y){return x*x+y*y;}

const double Pi = acos(-1);
static double xd = 0;

Point xpf[N + 5];
LL ans = 1e18;
int n,k;

std::priority_queue<LL> h;
std::set<LL> vis[N + 5];

inline void rotate(const double val)//旋转 x 角度
{
    double ccos = cos(val),ssin = sin(val);

    for(register int i = 1; i <= n ; ++i) xpf[i].rx = xpf[i].x*ccos - xpf[i].y*ssin;

    sort(xpf+1,xpf+n+1);
}

inline int Min(const LL x,const LL y){return x < y ? x : y;}
inline int Max(const LL x,const LL y){return x < y ? y : x;}

inline void check()
{
    for(register int i = 1; i <= n && i <= 500 ; ++i)
        for(register int j = Max(i + 1,n - 500); j <= n ; ++j)
        {
        	LL dis = -distance(xpf[i].x-xpf[j].x,xpf[i].y-xpf[j].y);
        	
        	int a = idx(i),b = idx(j);
        	
        	if(h.size() < k || h.top() > dis)
            {
                a < b || (a^=b^=a^=b);
                if(vis[a].count(b)) continue;
                vis[a].insert(b);
                if(h.size() >= k) h.pop();
                
                h.push(dis);
                
                //printf("%lld\n",h.top());
            }
		}
    
    rotate(xd);//取0~360

    xd += Pi/Max_Rand_Times;
}

int main()
{
    srand(time(NULL));

    scanf("%d%d",&n,&k);

    for(register int i = 1; i <= n ; ++i) scanf("%lld %lld",&xpf[i].x,&xpf[i].y);
	
	for(register int i = 1; i <= n ; ++i) xpf[i].id = i;
	
    for(register int i = 1; i <= Max_Rand_Times ; ++i) check();

    printf("%lld",-h.top());

    return 0;
}
