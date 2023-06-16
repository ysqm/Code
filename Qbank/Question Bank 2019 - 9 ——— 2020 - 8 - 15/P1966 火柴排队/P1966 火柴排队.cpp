# include <map>
# include <cmath>
# include <cstdio>
# include <cstring>
# include <cstdlib>
# include <iostream>
# include <algorithm>
# define N 100000
# define REG register
# define mod 99999997
typedef long long LL;

inline LL r()
{
	LL f = 1,x = 0;char c = getchar();
	
	while(c < '0' || c > '9'){if(c == '-') f = -1;c = getchar();}
	
	while(c >= '0' && c <= '9'){x = x * 10 + c - '0';c = getchar();}
	
	return x * f;
}

struct BASE
{
	LL number,id;
} base1[N + 42],base2[N + 42];

bool operator < (const BASE a,const BASE b)
{
	return a.number < b.number;
}

LL ans;

int tr[N + 42],idx[N + 42],n;

inline void update(int x,int data){while(x <= n){tr[x] += data; x += (x & (-x));}}

inline int getsum(int x){int sum = 0;while(x){sum += tr[x];x -= (x & (-x));}return sum;}

int main()
{
	n = r();
	
	for(REG int i = 1; i <= n ; ++i) base1[i] = {r(),i};
	
	for(REG int i = 1; i <= n ; ++i) base2[i] = {r(),i};
	
	std::sort(base1 + 1,base1 + n + 1);std::sort(base2 + 1,base2 + n + 1);
	
	for(REG int i = 1; i <= n; ++i) idx[base1[i].id] = base2[i].id;
	
	REG int i = n;
	
	while(i)
	{
		ans = (ans + getsum(idx[i] - 1)) % mod;
		
		//printf("%d\n",getsum(idx[i] - 1));
		
		update(idx[i--],1);
	}
	
	printf("%lld\n",ans);
	
	return 0;
} 
