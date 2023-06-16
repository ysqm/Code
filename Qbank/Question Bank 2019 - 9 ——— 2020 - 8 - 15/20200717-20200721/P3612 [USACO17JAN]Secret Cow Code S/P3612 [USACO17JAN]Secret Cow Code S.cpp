# include <cstdio>
# include <cstring>
# define reg register 
# define N 1000000
# define LL long long

inline int Read()
{
	int x = 0,f = 1;char ch = getchar();
	
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1;ch = getchar();}
	
	while(ch >= '0' && ch <= '9'){x = x*10 + (ch^48);ch = getchar();}
	
	return f == -1 ? -x : x;
}

inline int Max(const int a,const int b){return a < b ? b : a;} 

char s[N + 42];
LL n,l;

int main()
{
	scanf("%s%lld",s+1,&n);
	
	l = strlen(s+1);
	
	while(l < n)
	{
		reg LL cur = l;
		
		while(n > cur) cur <<= 1;
		
		cur >>= 1;
		
		n -= (1+cur);
		
		if(n == 0) n = cur;
	}
	
	printf("%c",s[n]);
	
	return 0;
}
