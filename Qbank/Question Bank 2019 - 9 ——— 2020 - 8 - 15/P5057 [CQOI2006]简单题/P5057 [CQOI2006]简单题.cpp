# include <map>
# include <cmath>
# include <cstdio>
# include <cstring>
# include <cstdlib>
# include <iostream>
# include <algorithm>
# define N 100000
# define REG register
typedef long long LL;

inline int r()
{
	int f = 1,x = 0;char c = getchar();
	
	while(c < '0' || c > '9'){if(c == '-') f = -1;c = getchar();}
	
	while(c >= '0' && c <= '9'){x = x * 10 + c - '0';c = getchar();}
	
	return x * f;
}

int base[N + 42],n,m,t,l,R;

inline void update(int x){while(x <= n){base[x] ^= 1;x += x & -x;}}

inline int getsum(int x){int ans = 0;while(x){ans ^= base[x];x -= x & -x;}return ans;}

int main()
{
	n = r(); m = r();
	
	while(m--)
	{
		t = r();l = r();
		
		if(t == 1){
			R = r();
			update(l);
			update(R + 1);
		}
		
		else printf("%d\n",getsum(l));
	}
	
	return 0;
} 
