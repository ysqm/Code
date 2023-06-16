# include <cstdio>
# include <algorithm>
# include <bitset>
# include <cstring>
# define reg register
# define N 100000
# define WW 40000
using namespace std;

inline void in(int& x)
{
	x = 0; char ch = getchar();int f = 1;
	
	while(ch < '0' || ch > '9'){if(ch == '-') f = -1;ch = getchar();}
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	x *= f;
}

inline int Max(const int& a,const int b){return a > b ? a : b;}
inline int Min(const int& a,const int b){return a < b ? a : b;}

int n,W,v[N + 42],w[N + 42],m[N + 42],f[WW + 42],tot;

int main()
{
	in(n);in(W);
	for(reg int i = 1,a,b,c; i <= n; ++i){
		in(a);in(b);in(c);
		for(reg int j = 0; c > (1 << j) ; ++j){
			m[++tot] = (1 << j);
			c -= m[tot];
			w[tot] = m[tot] * b;
			v[tot] = m[tot] * a;
		}
		m[++tot] = c;
		w[tot] = m[tot] * b;
		v[tot] = m[tot] * a;
	}
	
	for(reg int i = 1; i <= tot; ++i)
		for(reg int j = W; j >= w[i]; --j)
			f[j] = Max(f[j],f[j - w[i]] + v[i]);
	
	printf("%d",f[W]);
	return 0;
}
