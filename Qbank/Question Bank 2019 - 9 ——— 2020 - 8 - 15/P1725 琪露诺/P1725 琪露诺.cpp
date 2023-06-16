# include <cstdio>
# include <algorithm>
# include <bitset>
# include <cstring>
# define reg register
# define N 100000
using namespace std;

inline void in(int& x)
{
	x = 0; char ch = getchar();int f = 1;
	
	while(ch < '0' || ch > '9'){if(ch == '-') f = -1;ch = getchar();}
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	x *= f;
}

struct pr_Queue
{
	int id[N + 42],tail,head;
} q;

int n,l,r,dp[N + 42],ice[N + 42],ans;

int main()
{
	q.head = 1;in(n);in(l);in(r);
	
	for(reg int i = 0,a; i < l; ++i) 
		in(a);
	
	memset(dp,0x9f,sizeof(dp));ans = dp[0];dp[0] = 0;
	
	
	//for(reg int i = l; i <= r; ++i) {in(ice[i]);dp[i] = ice[i];}
	
	for(reg int p = 0,i = l,a; i <= n; ++i){
		in(a);
		while(q.head <= q.tail && dp[q.id[q.tail]] <= dp[p]) --q.tail;
		q.id[++q.tail] = p;
		while(q.id[q.head] + r < i) ++q.head;
		dp[i] = dp[q.id[q.head]] + a;
		p++;
	}
	
	for(reg int i = n + 1- r; i <= n ;++i)
		ans = max(ans,dp[i]);
	
	printf("%d\n",ans);
	return 0;
}
