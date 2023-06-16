#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<set>
#include<queue>

using namespace std;
typedef unsigned long long ll;

const unsigned long long z=1;
ll n,k;

void dfs(ll x,ll t)
{
	if(x==0) return;
	if(t<(z<<(x-z))) {printf("0");dfs(x-z,t);}
	else {printf("1");dfs(x-z,(z<<x)-t-z);}
	return;
}

int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	dfs(n,k);
	return 0;
}
