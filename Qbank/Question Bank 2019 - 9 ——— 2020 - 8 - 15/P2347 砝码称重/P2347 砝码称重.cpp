# include <cstdio>
# include <algorithm>
# include <bitset>
# define reg register
using namespace std;

inline void in(int& x)
{
	x = 0;char ch = getchar();int f = 1;
	
	while(ch < '0' || ch > '9'){if(ch == '-') f = -1;ch = getchar();}
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	x *= f;
}

int n,tot,w[1042],ans;

bool f[1042];

int main()
{
	reg int a = 0;
	in(a);
	while(a--) w[++tot] = 1;
	in(a);
	while(a--) w[++tot] = 2;
	in(a);
	while(a--) w[++tot] = 3;
	in(a);
	while(a--) w[++tot] = 5;
	in(a);
	while(a--) w[++tot] = 10;
	in(a);
	while(a--) w[++tot] = 20;
	f[0] = 1;
	for(reg int i = 1; i <= tot; ++i)
		for(reg int j = 1001; j >= 0; --j)
			if(f[j]) f[j + w[i]] = 1;
	for(reg int i = 1; i <= 1001; ++i) if(f[i]) ++ans;
	printf("Total=%d\n",ans);
	return 0;
}
