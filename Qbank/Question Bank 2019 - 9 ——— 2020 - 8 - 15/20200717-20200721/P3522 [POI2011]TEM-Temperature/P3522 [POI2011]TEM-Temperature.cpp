# include <cstdio>
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

int q[N + 42],n,L[N + 42],R[N + 42],ans;

int main()
{
	n = Read();
	
	reg int h=0,t=-1,tmp;
	
	for(reg int i = 1; i <= n ; ++i)
	{
		L[i] = Read();R[i] = Read();
		
		while(h <= t && R[i] < L[q[h]]) ++h;
		
		if(h <= t) ans = Max(ans,i - q[h] + 1);
		
		tmp = i;
		
		while(h <= t && L[i] > L[q[t]]) {tmp = q[t];--t;}
		
		L[q[++t] = tmp] = L[i];
	}
	
	printf("%d",ans);
	
	return 0;
}
