# include <cstdio>
# include <iostream>
# include <functional>
# include <algorithm>
# include <cstdlib>
# include <vector>
# include <set>
using namespace std;
int main(){
	freopen("centroid.in","r",stdin);
	freopen("centroid.out","w",stdout);
	long long a,b,c;
	scanf("%lld%lld%lld",&a,&b,&c);
	printf("%d %d %d",a*b,a/b,(a+b)/c);
}
