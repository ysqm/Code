# include <cstdio>
# define N 300000
# define reg register

inline void in(int& x)
{
	x = 0;reg char c = getchar();
	
	while(c < '0' || c > '9') c = getchar();
	
	while(c >= '0' && c <= '9'){x = (x << 3) + (x << 1) + (c ^ 48);c = getchar();}
}

inline int Read()
{
	int x = 0;reg char c = getchar();
	
	while(c < '0' || c > '9') c = getchar();
	
	while(c >= '0' && c <= '9'){x = (x << 3) + (x << 1) + (c ^ 48);c = getchar();}
	
	return x;
}

inline int Max(const int& a,const int b){return b > a ? b : a;}

int n,T,v[N + 42],w[N + 42],tot,f[1042];

int main()
{
	if(1){
		reg int a = Read(),b = Read(),c = Read(),d = Read();
		T = (c - a) * 60 + d - b;in(n);
	}
	
	for(reg int i = 1,a,b,c; i <= n; ++i){
		in(a);in(b);in(c);
		if(c == 0 ) c = 2600;
		for(reg int j = 0,d; c >= (1 << j); ++j){
			d = (1 << j);
			c -= d;
			v[++tot] = d * b;
			w[tot] = d * a;
		}
		v[++tot] = c * b;
		w[tot] = c * a;
	}
	
	for(reg int i = 1; i <= tot; ++i)
		for(reg int j = T; j >= w[i] ; --j)
			f[j] = Max(f[j],f[j - w[i]] + v[i]);
	
	printf("%d",f[T]);
	return 0;
}
