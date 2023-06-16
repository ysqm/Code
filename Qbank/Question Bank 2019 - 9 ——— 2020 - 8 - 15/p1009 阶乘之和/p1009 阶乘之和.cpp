# include <cmath>
# include <cstdio>
# include <cstring>
# include <cstdlib>
# include <iostream>
# include <algorithm>
# define N 10000
using namespace std;
int a[N],ans[N];
int main(){
	int n,len=1;a[1]=1;ans[1]=1;
	scanf("%d",&n);
	if(n==0){
		printf("%d",0);
		return 0;
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=len;j++){
			a[j]*=i;
		}
		for(int j=1;j<=len;j++){
			ans[j]+=a[j];
		}
		for(int j=1;j<=len;j++){
			if(a[j]>10){
				a[j+1]+=a[j]/10;
				a[j]%=10;
				if(j+1>len) len=j+1;
			}
			if(ans[j]>10){
				ans[j+1]+=ans[j]/10;
				ans[j]%=10;
				if(j+1>len) len=j+1;
			}
		}
	}
	for(int i=1;i<=len;i++)
		printf("%d",ans[len-i+1]);
	return 0;
}	
