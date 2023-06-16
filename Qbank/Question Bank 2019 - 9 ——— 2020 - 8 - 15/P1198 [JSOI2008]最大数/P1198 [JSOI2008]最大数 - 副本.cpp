# include <map>
# include <cmath>
# include <cstdio>
# include <cstring>
# include <cstdlib>
# include <iostream>
# include <algorithm>
# define N 200000
# define REG register
# define maxstep 18
# define inf 0x6f6f6f6f6f6f6f6f
typedef long long LL;

inline int Read()
{
	int f = 1,x = 0;char c = getchar();
	
	while(c < '0' || c > '9'){if(c == '-') f = -1;c = getchar();}
	
	while(c >= '0' && c <= '9'){x = x * 10 + c - '0';c = getchar();}
	
	return x * f;
}


LL f[N + 42][21],base;

int n,m;

inline void updata(const int& u)
{
	f[u][0] = base;
	
	for(REG int i = 1; u >= (1 << i) ; ++i) f[u][i] = std::max(f[u][i - 1],f[u - ( 1 << (i - 1))][i - 1]);
}

inline LL Find(int x,int y){
    int K = log(y - x + 1) / log(2);
    
    return std::max(f[y][K],f[x + ( 1 << K ) - 1][K]);
}

int main()
{
	n = Read();m = Read();
	
	char c;LL tail = 0,t = 0;
	
	while(n--){
		while(c < 'A' || c > 'Z') 
			c = getchar();
		
		base = Read();
		
		if(c == 'A'){base = (base + t) % m;updata(++tail);}
		
		else if(base == 1) printf("%lld\n",t = f[tail][0]);
		
		else printf("%lld\n",t = Find(tail - (int) base + 1,tail));
		
		c = ' ';
	}
	return 0;
}
