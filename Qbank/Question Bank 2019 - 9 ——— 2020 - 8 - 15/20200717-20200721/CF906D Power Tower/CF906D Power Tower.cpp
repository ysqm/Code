# include <cstdio>
# include <cmath>
# include <map>
# define reg register 
# define N 10000000
# define LL long long
# define int long long

inline int Read()
{
	int x = 0;char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch >= '0' && ch <= '9'){x = x*10 + (ch^48);ch = getchar();}
	
	return x;
}

std::map <int,int> mp;
bool vis[N + 42];
int prime[N + 42],tot;

inline int fp(reg int x,reg int p)
{
	reg int res = 1;
	
	while(p)
	{
		if(p&1) res *= x;
		
		x *= x;
		
		p >>= 1;
	}
	return res;
}

inline int phi(const int n)
{
	int t = std::sqrt(n),tmp=n,res=n;
	
	if(mp.count(n)) return mp[n];
	
	for(reg int i = 1; prime[i] <= t ; ++i)
		if(tmp%prime[i] == 0)
		{
			res = res/prime[i]*(prime[i]-1);
			
			while(tmp%prime[i] == 0) tmp /= prime[i];
		}
	
	if(tmp > 1) res = res/tmp*(tmp-1);
	
	return mp[n] = res;
}

inline LL fast_fuck_you_pow(reg LL x,reg LL p,reg LL mod)
{
	reg bool flag=0;
	reg LL res = 1;
	
	while(p)
	{
		if(p&1) res *= x;
		
		x *= x;
		
		p >>= 1;
		
		if(x > mod) x%=mod,flag=1;	
		if(res > mod) res%=mod,flag=1; 
	}
	return flag ? res + mod : res;
}//fuck_your_pow 

int l,r,w[N + 42];

LL Garbage_function(const int cur,const int mod)
{
	if(cur == r+1 || mod == 1) return 1;
	
	LL ph = Garbage_function(cur+1,phi(mod)); 
	
	return fast_fuck_you_pow(w[cur],ph,mod);
}

signed main()
{
	vis[1] = 1;
	
	for(reg int i = 2; i <= N; ++i)
	{
		if(!vis[i]) prime[++tot] = i;
		
		for(reg int j = 1 ; j <= tot && i * prime[j] <= N ; ++j)
		{
			vis[i*prime[j]] = 1;
			if(i % prime[j] == 0) break;
		}
	}
	
	int n,m,q;
	
	n = Read();
	
	/*for(reg int i = 1; i <= n ; ++i) printf("%lld ",phi(i));*/
	
	m = Read();
	
	for(reg int i = 1; i <= n ; ++i) w[i] = Read();
	
	q = Read();
	
	while(q--)
	{
		l = Read();r = Read();
		
		printf("%lld\n",Garbage_function(l,m)%m);
	}
	
	return 0;
}
