# include <cstdio>
# define N 1000000
# define inf 0x7f7f7f7f7f
# define LL long long
# define reg register

inline void in(int& x)
{
	x = 0; char ch = getchar();int f = 1;
	
	while(ch < '0' || ch > '9'){if(ch == '-') f = -1;ch = getchar();}
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	x *= f;
}

inline int Max(const int& a,const int b){return a > b ? a : b;}
inline int MIn(const int& a,const int& b){return a < b ? a : b;}
inline int Min(const LL& a,const LL b){return a < b ? a : b;}

int n,w[N + 42],m,f[N + 42],id[N + 42],tot;

int main()
{
	in(n);
	
	for(reg int i = 1; i <= n; ++i){in(w[i]);++id[w[i]];m = Max(m,w[i]);}
	
	for(reg int i = 1; i <= m; ++i)
		if(id[i]){
			for(reg int j = 1; j * i <= m; ++j)
				f[j * i] += id[i];
		}
	
	for(reg int i = 1; i <= n; ++i)printf("%d\n",f[w[i]] - 1);
	
	return 0;
}
