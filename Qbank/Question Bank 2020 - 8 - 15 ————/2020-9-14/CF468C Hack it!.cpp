# include <cstdio>
# include <algorithm>
# define ll long long

ll l,mod,r,base = 1e18,h0;

int main()
{
	scanf("%lld",&mod);
	h0 = (base%mod*9%mod*9%mod+1)%mod;
	l = mod-h0;
	r = base+mod-h0;
	printf("%lld %lld\n",l,r);
	return 0;
}
