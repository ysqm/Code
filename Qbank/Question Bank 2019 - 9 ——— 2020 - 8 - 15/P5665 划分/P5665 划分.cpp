# include <cstdio>
# include <cmath>
//# define N 500000
# define N 40000000
# define reg register

typedef long long LL;

inline LL Read()
{
	register LL x = 0;register char c = getchar();
	
	while(c < '0' || c > '9') c = getchar();
	
	while(c >= '0' && c <= '9') {x = x * 10 + (c ^ 48);c = getchar();}
	
	return x;
}

int n,f[N + 42];
LL s[N + 42],Lastpart[N + 42];

inline void INIT()
{
	n = Read();int type = Read();
	
	if(type)
	{
		LL p,l,r,x,y,z,m,mod = 1073741824;
		
		x = Read();y = Read();z = Read();s[1] = Read();s[2] = Read();m = Read();
		
		for(reg int i = 3; i <= n ; ++i) s[i] = (x * s[i-1] + y * s[i-2] + z) % mod;
		
		for(reg int i = 1,j = 1; i <= m; ++i) 
		{
			p = Read();l = Read();r = Read();
			
			while(j <= p) s[j] = s[j] % (r - l + 1) + l,++j;
		}
	}
	
	else for(reg int i = 1; i <= n ; ++i) s[i] = Read();
	
	for(reg int i = 1; i <= n ; ++i) s[i] = s[i] + s[i-1];
}

int q[N + 42],Pre[N + 42];

inline void DP()
{
	reg int t = 1,h = 1;
	
	for(reg int i = 1; i <= n ; ++i)
	{
		while(h < t && Lastpart[q[h+1]] <= s[i] - s[q[h+1]]) ++h;
		
		Lastpart[i] = s[i] - s[q[h]];
		
		Pre[i] = q[h];
		
		while(h <= t && s[q[t]] + Lastpart[q[t]] >= s[i] + Lastpart[i]) --t;
		
		q[++t] = i;
	}
}

inline void Ans()
{
	reg __int128 ans = 0,tmp;
	
	//reg LL ans = 0,tmp;
	
	reg int cur = n;
	
	int Stack[142];
	
	while(cur) {tmp = s[cur] - s[Pre[cur]];ans += tmp*tmp; cur = Pre[cur];}
	
	while(ans) {Stack[++cur] = ans % 10; ans /= 10;}
	
    while(cur) putchar('0' + Stack[cur--]);
}

int main()
{
	INIT();
	
	DP();
	
	Ans();
	
	/*reg __int128 ans = 0,tmp;
	
	//reg LL ans = 0,tmp;
	
	reg int cur = n;
	
	int Stack[N + 42];
	
	while(cur) {tmp = s[cur] - s[Pre[cur]];ans += tmp*tmp; cur = Pre[cur];}
	
	while(ans) {Stack[++cur] = ans % 10; ans /= 10;}
	
    while(cur) putchar('0' + Stack[cur--]);*/
	
	return 0;
}
