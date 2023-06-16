# include <cstdio>
# include <algorithm>
# include <vector>
# include <cmath>
# define inf 0x7f7f7f7f
# define N 30000
# define R register
# define I inline
using namespace std;

I void r(int &x)
{
	x = 0;int f = 1;
	char c = getchar();
	
	while(c >'9' || c < '0'){
		if(c == '-') f = -f;
		c = getchar();
	}
	
	while(c <= '9' && c >= '0'){
		x = (x << 3) + (x << 1) + c - 48;
		c = getchar();
	}
	
	x *= f;
}

int T,a[N + 42],b[N + 42],num[N + 42],d,e;
char c;

I int f(int x)
{
	if(a[x] == x) return a[x];
	int fa = f(a[x]);
	b[x] += b[a[x]];
	return a[x] = fa;
}

int main()
{
	r(T);
	for(int i = 1; i <= 30000 ; ++i){
        a[i] = i;
        b[i] = 0;
        num[i] = 1;
    }
    while(T--){
    	c = getchar();
    	
    	while(c != 'M' && c != 'C') c = getchar();
    	
    	
    	
    	if(c == 'M'){
    		r(d);r(e);
    		int fi = f(d),fj = f(e);
			b[fi] += num[fj];
    		a[fi] = fj;
    		num[fj] += num[fi];
    		num[fi] = 0;
		}
		
		else {
			r(d);
			f(d);
			printf("%d\n",b[d]);
		}
	}
}

