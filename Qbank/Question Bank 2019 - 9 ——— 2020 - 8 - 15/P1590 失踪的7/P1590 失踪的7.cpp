# include <cstdio>
# include <algorithm>
# include <bitset>
# include <cstring>
# define reg register
# define N 2000000
using namespace std;

inline void in(long long& x)
{
	x = 0; char ch = getchar();
	
	while(ch < '0' || ch > '9')ch = getchar();
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}
}



int main()
{
	reg long long t,ans,n,p,T;;in(T);
	
	while(T--){
		in(n);ans = 0;p = 1;
		while(n){
			t = n % 10;
			if(t > 7) --t;
			ans += p * t;
			p *= 9;
			n /= 10;
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}
