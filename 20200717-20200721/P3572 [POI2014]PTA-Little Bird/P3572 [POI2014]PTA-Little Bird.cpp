# include <cstdio>
# define reg register 
# define N 2000000
# define LL long long

inline int Read()
{
	int x = 0;char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch >= '0' && ch <= '9'){x = x*10 + (ch^48);ch = getchar();}
	
	return x;
}

inline LL ReadL()
{
	LL x = 0;char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch >= '0' && ch <= '9'){x = x*10 + (ch^48);ch = getchar();}
	
	return x;
}

inline LL Max(const LL& a,const LL b){return a < b ? b : a;} 

int q[N + 42],n,a[N + 42],Q,f[N + 42];

int DP(const int d)
{
	reg int h = 0,t = 0,res = 0;;
	
	q[0] = 1;
	
	for(reg int i = 2; i <= n ; ++i)
	{
		while(h <= t && i - q[h] > d) ++h;
		
		if(a[i] < a[q[h]]) f[i] = f[q[h]];
		else f[i] = f[q[h]] + 1;
		
		while(h <= t && ((f[q[t]] > f[i]) || f[q[t]] == f[i] && a[i] >= a[q[t]])) --t;
		
		q[++t] = i;
	}
	
	return f[n];
}

int main()
{
	n = Read();
	
	for(reg int i = 1; i <= n ; ++i) a[i] = Read();
	
	Q = Read();
	
	for(reg int i = 1; i <= Q ; ++i) printf("%d\n",DP(Read()));
	
	return 0;
}
