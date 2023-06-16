# include <cstdio>
# include <algorithm>
# define LL unsigned long long
# define reg register
# define N 500000
//# define mod 212379449139137957ll

int n;
LL H[N + 42],h[N + 42],mul[N + 42];
char s[N + 42];

inline int Min_int(const int& a,const int b){return a > b ? b : a;}

int main()
{
	scanf("%d%s",&n,s + 1);
	
	for(reg int i = 1; i <= n; ++i) H[i] = H[i - 1] * 131 + s[i];
	
	for(reg int i = n; i ; --i)
	
	for(reg int i = 1; i <= n; ++i) h[i] = h[i - 1] * 131 + (s[i] == '0') ? '1' : '0';
	
	for(reg int i = 1; i <= n; ++i)
		if(s[i] != s[i + 1]){
			int r = Min(i,n - i),l = 0;
			while(l <= r){
				int mid = (l + r + 1) >> 1;
				if(h[x] )
				else r = mid - 1;
			}
		}
	
	return 0;
}
