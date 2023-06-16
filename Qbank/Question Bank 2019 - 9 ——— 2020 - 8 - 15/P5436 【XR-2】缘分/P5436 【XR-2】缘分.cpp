# include <cstdio>
# include <algorithm>
int main(){
	long long t,n;
	scanf("%lld",&t);
	for(int i=0;i<t;i++){
		scanf("%lld",&n);
		printf("%lld\n",std::max(n*(n-1),(long long)1));
	}
	return 0;
}
