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

struct Point
{
    double x,y;

    Point(const double x_ = 0,const double y_ = 0):x(x_),y(y_){}
};

inline bool operator < (const Point& a,const Point& b){return a.x < b.x;}

inline double dis(const double x,const double y){return x*x+y*y;}

const double Pi = acos(-1);

Point xpf[N + 5];
double ans = 1e18;
int n;

inline int rotate(const int x)//旋转 x 角度
{
    double val = (x/180)*Pi;

    double ccos = cos(val),ssin = sin(val);

    for(register int i = 1; i <= n ; ++i)
    {
        double x = xpf[i].x,y = xpf[i].y;

        xpf[i] = Point(x*ccos - y*ssin,x*ssin + y*ccos);
    }

    sort(xpf+1,xpf+n+1);
}

inline int Min(const int x,const int y){return x < y ? x : y;}

inline int check()
{
    for(register int i = 1; i <= n ; ++i)
        for(register int j = Min(i + 5,n); j > i ; --j)
            if(dis(xpf[i].x-xpf[j].x,xpf[i].y-xpf[j].y) < ans) ans = dis(xpf[i].x-xpf[j].x,xpf[i].y-xpf[j].y);

    rotate((rand()%360)+1);//取0~360
}

int main()
{
    srand(time(NULL));

    scanf("%d",&n);

    for(register int i = 1; i <= n ; ++i) scanf("%lf %lf",&xpf[i].x,&xpf[i].y);

    for(register int i = 1; i <= Max_Rand_Times ; ++i) check();

    printf("%.4lf",std::sqrt(ans));

    return 0;
}
