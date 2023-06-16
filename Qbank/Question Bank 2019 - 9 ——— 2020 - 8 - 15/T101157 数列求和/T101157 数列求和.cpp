# include <cstdio>
# include <algorithm>
using namespace std;
long long n,nowt,m;long long an[4000042],l=1,i,left,right,ans;
long long sum;
int main(){
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%lld",&an[i]);
		
		sum += an[i];
		
		while(sum>m){
			sum-=an[l];
			l++;
		}	
		if(m-an[i]==0){
			left=l;right=i;
			ans = m;break;
		}
		else if(m-sum<m - ans){
			left=l;right=i;
			ans = sum;
		}
	}
	printf("%lld %lld %lld",left,right,ans);
	return 0;
} 
