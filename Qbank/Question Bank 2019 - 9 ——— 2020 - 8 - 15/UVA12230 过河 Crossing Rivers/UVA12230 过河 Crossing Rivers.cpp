# include <iostream>
# include <algorithm>
# include <cstdio>
# include <iomanip>
# include <cstdlib>
# include <queue>
# define reg register
using namespace std;

int n,D,v,l,p,Case;
double ans;

int main()
{
	while(scanf("%d%d",&n,&D) && (n || D)){
		ans = 0.0;
		for(reg int i = 1; i <= n; ++i){
			scanf("%d%d%d",&p,&l,&v);
			D -= l;
			ans += 2.00 * l / v;
		}
		printf("Case %d: %.3lf\n\n",++Case,ans + D);
	}
	return 0;
}

