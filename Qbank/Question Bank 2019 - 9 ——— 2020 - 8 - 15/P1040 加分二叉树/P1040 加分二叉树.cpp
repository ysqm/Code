# include <cstdio>
# include <algorithm>
# include <cstring>
# define N 10 
# define REG register
using namespace std;
typedef long long LL;

inline void in(LL& x)
{
	char ch = getchar();
	
	while(ch > '9' || ch < '0') ch = getchar();
	
	while(ch <= '9' && ch >= '0') {x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}
	
}

inline LL Read()
{
	LL x = 0;char ch = getchar();
	
	while(ch > '9' || ch < '0') ch = getchar();
	
	while(ch <= '9' && ch >= '0') {x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}
	
	return x;
}

LL a[N + 42],f[N + 42][N + 42],root[N + 42][N + 42],n;

inline void print(int l, int r)
{
    if(l > r) return;
    printf("%d ",root[l][r]);
    print(l, root[l][r]-1);
    print(root[l][r]+1,r);
}

int main()
{
	in(n);
	
	for(REG int i = 1; i <= n; ++i) in(a[i]);
	
	++n;
	
	for(REG int i = 0; i <= n; ++i)
		for(REG int j = 0; j <= n; ++j)
			f[i][j] = 1;
		
	--n;	
			
	for(REG int i = 1; i <= n; ++i){f[i][i] = a[i];root[i][i] = i;}
	
	for(REG int L = n; L ; --L){
		for(REG int R = L + 1; R <= n; ++R){
			for(REG int k = L; k <= R ; ++k)
				 if(f[L][k - 1] * f[k + 1][R] + a[k] > f[L][R]){
				 	f[L][R] = f[L][k - 1] * f[k + 1][R] + a[k];
				 	root[L][R] = k;
				 }
		}
	}
		
	printf("%lld\n",f[1][n]);
	print(1,n);
	return 0;	
}
