# include <cstdio>
# include <cstring>
# define N 600
# define reg register
using namespace std;

template <typename T>
inline T in(T& x)
{
	x = 0;char c = getchar();
	
	while(c < '0' || c > '9') c = getchar();
	
	while(c >= '0' && c <= '9'){x = (x << 3) + (x << 1) + (c ^ 48);c = getchar();}
} 

template <typename T>
inline T min(const T A,const T B){return A < B ? A : B;} 

template <typename T>
inline void check(T& A,T B){if(A < B) A = B;}

struct Tree_Node
{
	int Time,value;
} tr[N + 42];

int dp[N + 42][N + 42],s,Star_Point = 1;

inline void dfs_read(const int& u)
{
	in(tr[u].Time);in(tr[u].value);
	tr[u].Time <<= 1;
	if(!tr[u].value){
		dfs_read(u << 1);dfs_read(u << 1 | 1);
	}
}

inline int DP(const int& u,const int& t)
{
	if (dp[u][t] > 0 || !t) return dp[u][t];//记忆化 
	
    if (tr[u].value) return dp[u][t] = min(tr[u].value,(t - tr[u].Time)/5);
    // 有画就返回，同时注意时间限制 故取最小值 
    for (int k = 0;k <= t - tr[u].Time ; ++k)
        check(dp[u][t],DP(u << 1,k) + DP(u << 1 | 1,t - tr[u].Time - k));
    
    return dp[u][t];
}

signed main()
{
	in(s);--s;
	
	dfs_read(Star_Point);
	
	printf("%d",DP(Star_Point,s)); 
	
	return 0;
}
