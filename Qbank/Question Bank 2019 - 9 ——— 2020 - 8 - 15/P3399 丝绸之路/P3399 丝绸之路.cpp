# include <cstdio>
# define N 1000
# define inf 0x7f7f7f7f7f
# define LL long long
# define reg register

inline void in(LL& x)
{
	x = 0; char ch = getchar();int f = 1;
	
	while(ch < '0' || ch > '9'){if(ch == '-') f = -1;ch = getchar();}
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	x *= f;
}

inline int Max(const int& a,const int b){return a > b ? a : b;}
inline int MIn(const int& a,const int& b){return a < b ? a : b;}
inline int Min(const LL& a,const LL b){return a < b ? a : b;}

LL f[N + 42][N + 42],n,m,d[N + 42],M[N + 42];

/*inline LL dfs(const int day,const int city)
{
	if(f[day][city]) return f[day][city];
	if(day > m + 1) return inf;
	if(city == n) return 0;
	else return f[day][city] = Min(dfs(day + 1,city),dfs(day + 1,city + 1) + d[city + 1] * M[city]);
}
*/
int main()
{
	in(n);in(m);
	
	for(reg int i = 1; i <= n; ++i) in(d[i]);
	
	for(reg int i = 1; i <= m; ++i) in(M[i]);
	
	for(reg int i = 1; i <= m; ++i)
		for(reg int j = 1; j <= MIn(i,n); ++j)
			f[i][j] = inf;
	
	for(reg int i =1; i <= m; ++i)
		for(reg int j =0; j <= MIn(i,n); ++j)
			if(i == j) f[i][j] = f[i - 1][j - 1] + d[j] * M[i];
			else f[i][j] = Min(f[i - 1][j],f[i - 1][j - 1] + d[j] * M[i]);
	
	printf("%lld",f[m][n]);
	
	return 0;
}
