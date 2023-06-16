# include <cmath>
# include <cstdio>
# include <cstring>
# include <algorithm>
# define reg register
# define N 500

struct Num
{
	int len;
	int num[10041];
	
	Num(){len = 0;memset(num,0,sizeof num);}
	
	inline bool operator < (const Num& b)const 
	{
		if(len != b.len) return len < b.len;
		for(reg int i = len; i ; --i)
			if(num[i] != b.num[i]) return num[i] < b.num[i];
			
		return false;
	}
	
	inline bool operator > (const Num& b)const 
	{
		if(len != b.len) return len > b.len;
		for(reg int i = len; i ; --i)
			if(num[i] != b.num[i]) return num[i] > b.num[i];
			
		return false;
	}
	inline bool operator != (const Num& b)const 
	{
		if(len != b.len) return true;
		for(reg int i = len; i ; --i)
			if(num[i] != b.num[i]) return true;
			
		return false;
	}
	
	inline void Get()
	{
		char s[100041];int cnt=1;
		
		scanf("\n%s",s+1);
		
		while(s[cnt]) ++cnt;--cnt;
		
		if(cnt % 3 == 0)
		{
			len = cnt/3;
			int sum = 0;
			for(reg int i = 1; i <= cnt ; i += 3) num[len - i/3] = (s[i]^48)*100+(s[i+1]^48)*10+(s[i+2]^48);
		}
		else 
		{
			int hc = cnt % 3,sum = 0;
			len = cnt/3 + 1;
			
			for(reg int i = hc+1; i <= cnt ; i += 3) num[len - 1 - (i-hc)/3] = (s[i]^48)*100+(s[i+1]^48)*10+(s[i+2]^48);
			if(hc == 2) num[len] = (s[1]^48)*10+(s[2]^48);
			else num[len] = (s[1]^48);
		}
	}
	
	inline void Printd()
	{
		if(len)
		{	
			printf("%d",num[len]);
			for(reg int i = len-1; i ; --i) printf("%03d",num[i]);
		}
		else printf("0");
	}
};

inline void D(Num& a)
{
	for(reg int i = a.len; i ; --i)
	{
		if(a.num[i]&1) a.num[i-1] += 1000;
		a.num[i] >>= 1;
	}
	if(a.num[a.len] == 0) --a.len;
}

inline void T(Num& a,const int x)//乘以 2 的 x 次方 
{
	for(reg int i = a.len; i ; --i) a.num[i] <<= x;
	
	for(reg int i = 1; i <= a.len ; ++i) if(a.num[i] >= 1000){a.num[i+1] += (a.num[i]/1000);a.num[i] %= 1000;}
	
	while(a.num[a.len+1])
	{
		++a.len;
		if(a.num[a.len] >= 1000){a.num[a.len+1] += (a.num[a.len]/1000);a.num[a.len] %= 1000;}
	}
	if(a.num[a.len] >= 1000){a.num[a.len+1] += (a.num[a.len]/1000);a.num[a.len] %= 1000;++a.len;}
	
}

inline int Max(const int x,const int y){return x < y ? y : x;}

inline Num jianfa(const Num& a,const Num& b)
{
	Num xy = Num();
	
	xy.len = a.len;
	
	for(reg int i = 1; i <= xy.len ; ++i) xy.num[i] = a.num[i] - b.num[i];
	
	for(reg int i = 1; i <= xy.len ; ++i) if(xy.num[i] < 0) {xy.num[i] += 1000;xy.num[i+1]--;}
	
	while(xy.num[xy.len] == 0) xy.len--;
	
	return xy; 
}

inline void Swap(Num& a,Num& b){Num c = a; a = b;b = c;}

# define aa (a.num[1]&1)
# define bb (b.num[1]&1)

inline Num Gcd(Num& a,Num& b)
{
	int cnt = 0;
	
	for( ; a != b ; )
	{
		if(a < b) Swap(a,b);
		if(aa == 0)
		{
			if(bb == 0)
			{
				while(aa == 0 && bb == 0){D(a);D(b);++cnt;}
			}
			else D(a);
		}
		else
		{
			if(bb == 0) D(b);
			else a = jianfa(a,b);
		}
	}
	
	while(cnt >= 10){T(a,10);cnt -= 10;} 
	
	if(cnt != 0) T(a,cnt);
	
	return a;
}

int main()
{
	#ifdef ONLINE_JUDGE
	#else
    freopen("2.txt","r",stdin);
	#endif
	
	Num a,b;
	
	a.Get();b.Get();
	
	a = Gcd(a,b);
	
	a.Printd();
	
	return 0; 
}
