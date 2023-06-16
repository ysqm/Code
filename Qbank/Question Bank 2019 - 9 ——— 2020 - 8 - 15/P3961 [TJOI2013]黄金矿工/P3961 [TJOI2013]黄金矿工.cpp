# include <cstdio>
# include <cstring>
# include <algorithm>
# include <vector> 
# define reg register
# define N 200
# define TIME 40000
# define LL long long
using namespace std;

inline int Read()
{
	 int x = 0;char ch = getchar();
	 
	 while(ch < '0' || ch > '9') ch = getchar();
	 
	 while(ch >= '0' && ch <= '9'){x = (x * 10) + (ch ^ 48);ch = getchar();}
	 
	 return x;
} 

inline int Min(const int a,const int b){return a < b ? a : b;}
inline int Max(const int a,const int b){return a > b ? a : b;}

struct Point
{
	int x,y,V,W;
	Point(const int W_=0,const int V_=0,const int Y=0,const int X=0):V(V_),W(W_),y(Y),x(X){}
	
	inline friend bool operator < (const Point a,const Point b){return a.x * b.y < a.y * b.x;}
	inline friend bool operator == (const Point a,const Point b){return a.x * b.y == a.y * b.x;}
} P[N + 42];

int G[N + 42][N + 42];
int n,T,tot,dp[TIME + 42];

void INIT()
{
	n = Read();T = Read();
	
	for(reg int i = 1; i <= n ; ++i) P[i] = Point(Read(),Read(),Read(),Read());
	
	std::sort(P + 1,P + n + 1);
	
	P[0] = Point(0,0,-1,1);
	
	for(reg int i = 1; i <= n ; ++i) 
		if(P[i] == P[i-1]) G[tot][++G[tot][0]] = i;
		else if(++tot) G[tot][++G[tot][0]] = i;
}

int Dp(const int i,const int j,const int k)
{
	return Max(dp[j],
		P[G[i][k]].W + ((k + 1 <= G[i][0]) ? 
		Dp(i,j - P[G[i][k]].V,k+1) : 
		dp[j - P[G[i][k]].V]));
}

void DP()
{
	for(reg int i = 1; i <= tot ; ++i) 
		for(reg int j = T; j >= P[G[i][1]].V ; --j)
			if(dp[j] <= dp[j - P[G[i][1]].V] + P[G[i][1]].W)
				dp[j] = P[G[i][1]].W + ((1 < G[i][0]) ? Dp(i,j - P[G[i][1]].V,2) : dp[j - P[G[i][1]].V]);
}

int main()
{
	INIT();
	
	DP();
	
	printf("%d",dp[T]);
	
	return 0;
}
