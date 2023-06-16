# include <cstdio>
# include <algorithm>
# include <cstring>
# define reg register
using namespace std;

const int n4[] = {0,1,16,81,256,625,1296,2401,4096,6561,10000,14641,20736,28561,38416,50625,65536,83521,104976,0};

inline void in(int& x)
{
	x = 0; char ch = getchar();int f = 1;
	
	while(ch < '0' || ch > '9'){if(ch == '-') f = -1;ch = getchar();}
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	x *= f;
}

int f[104976],n;

int main()
{
	in(n);
	memset(f,0x7f,sizeof(f));
	f[0] = 0;
	for(reg int i = 1; i <= 17; ++i)
		for(reg int j = n4[i]; j <= n; ++j)
			f[j] = min(f[j],f[j - n4[i]] + 1);
	printf("%d\n",f[n]);
	return 0;
}
