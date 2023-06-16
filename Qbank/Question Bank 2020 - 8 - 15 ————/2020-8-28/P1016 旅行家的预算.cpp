# include <ctime>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define reg register 

struct Point
{
    double x,P;

    inline bool operator < (const Point& b)const{return x < b.x;}

} P[15];

double D1,C,D2,dp[11],nowfuel,ans = 0;
int n;

int main()
{
    P[1].x = 0;

    scanf("%lf %lf %lf %lf %d",&D1,&C,&D2,&P[1].P,&n);

    ++n;

    for(register int i = 2; i <= n ; ++i) 
		scanf("%lf %lf",&P[i].x,&P[i].P);

    P[++n].x = D1;P[0].P = 1e9;

    std::sort(P+1,P+n+1);

    for(reg int i = 1; i <= n ; ++i)
        if(C * D2 < n) {puts("No Solution");return 0;}

    for(reg int i = 1,tmp; i <= n ; )
    {
        tmp = 0;double len = C*D2 + P[i].x;

        for(reg int j = i+1; j <= n ; ++j)
            if(P[j].x <= len)
            {
                if(P[i].P < P[j].P) {tmp == j;break;}
                else if(P[j].P < P[tmp].P) tmp = j;
            }
        ans += (P[tmp].x-P[i].x)/D2*P[i].P;
        if(tmp == n){printf("%.2lf",ans);return 0;}
        i = tmp;
    }
}
