# include <cstdio>
# include <cctype>
# include <cstring>
# include <queue>
# include <cmath>
# define reg register
# define eps 0.000001
using namespace std;
inline void ind(double& X)
{
    double Y = 1.0; char ch = 0;X = 0.0;
    
    while(ch < '0' || ch > '9') ch = getchar();
    
    while(ch >= '0' && ch <= '9'){X = X * 10 + (ch ^ 48);ch = getchar();}
    
    if(ch == '.') {ch = getchar();while(ch >= '0' && ch <= '9') {X += (Y /= 10) * (ch ^ 48);ch = getchar();}}
}

template <typename T>
inline void in(T& x)
{
	x = 0;char c = getchar();
	
	while(c < '0' || c > '9') c = getchar();
	
	while(c >= '0' && c <= '9'){x = (x << 3) + (x << 1) +c - 48;c = getchar();}
	
} 

struct Point
{
	double x,y;
} pig[142];

int base[142][142],n,T,m,lowbit[(1 << 20) + 42],dp[(1 << 20) + 42];

int main()
{
	for(reg int i = 0; i < (1 << 18) ; ++i){
        int j = 1;
        for( ; j <= 18 && i & (1 << (j - 1 ) ); ++j);
        	lowbit[i] = j;
    }
		
	in(T);
	while(T--){
		memset(base,0,sizeof(base));
		memset(dp,0x3f,sizeof(dp));
		
		dp[0] = 0;
		
		in(n);in(m);
		
		for(reg int i = 1; i <= n ; ++i){ind(pig[i].x);ind(pig[i].y);}
		
		for(int i = 1; i <= n; ++i)
			for(int j = 1 ; j <= n ; ++j)
				if(fabs(pig[i].x - pig[j].x) > eps){
					double a,b;
					
					a = ((pig[i].x * pig[j].y) - (pig[i].y * pig[j].x))/((pig[i].x * pig[j].x) * (pig[j].x - pig[i].x));
					//a的公式：(y1*x2-y2*x1)/(x1*x2*(x1-x2))
					if(a > -eps) continue;
				
					b = (pig[j].x * pig[j].x * pig[i].y - pig[i].x * pig[i].x * pig[j].y)/((pig[i].x * pig[j].x) * (pig[j].x - pig[i].x));
					//b的公式: (x2*x2*y1-y2*x1*x1)/(x1*x2*(x2-x1))
					for(int k = 1; k <= n; ++k)
						if(eps  > fabs(a * pig[k].x * pig[k].x + b * pig[k].x - pig[k].y)) 
							base[i][j] |= (1 << (k - 1));
				}
		
		
		for(reg int i = 0 ; i < (1 << n) ; ++i){
			int j = lowbit[i];
			dp[i | ( 1 << (j - 1))] = min(dp[i | (1 << (j - 1))],dp[i] + 1);
			
            for(reg int k = 1 ; k <= n ; ++k) dp[i | base[j][k]] = min(dp[ i | base[j][k]],dp[i] + 1);
		}
		
		printf("%d\n",dp[(1 << n) - 1]);
	}
}
