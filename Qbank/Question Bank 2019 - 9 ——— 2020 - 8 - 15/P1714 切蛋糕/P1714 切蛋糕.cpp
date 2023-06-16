# include <cstdio>
# include <algorithm>
# include <bitset>
# include <cstring>
# define reg register
# define N 1000000
# define LL long long
using namespace std;

inline void in(int& x)
{
	/*x = 0;*/char ch = getchar();int f = 1;
	
	while(ch < '0' || ch > '9'){if(ch == '-') f = -1;ch = getchar();}
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	x *= f;
}

inline int Max(const int& a,const int b){return a > b ? a : b;}

int n,m,t[N + 42],a[N + 42],num;

int main()
{
	in(n);in(m);
	
	reg int r = 1,l = 1,ansl,ansr;
	
	for(;r <= n; ++r) in(a[r]);
	
	r = 1;
	
	for(;num < m;++r) if(t[a[r]]++ == 0) ++num;
	
	--r;
	
	for(;t[a[l]] > 1;++l) --t[a[l]];
	
	ansl = l;ansr = r;
	
	for(++r; r <= n;++r){
		++t[a[r]];
		while(t[a[l]] > 1) --t[a[l++]];
		if(ansr - ansl > r - l){ansr = r;ansl = l;}
	}
	
	printf("%d %d",ansl,ansr);
	
	return 0;
}
