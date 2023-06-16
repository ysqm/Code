# include <cstdio>
# include <cstring>
# include <algorithm>
using namespace std;
/*int a[10000],n,len=1;
int main(){
	printf("\n请输入数据:");
	while(scanf("%d",&n)==1&&n!=0){
		a[1]=1;len=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=len;j++)
				a[j]*=i;
			for(int j=1;j<=len;j++)
				if(a[j]>=1000){
					a[j+1]+=a[j]/1000;
					a[j]%=1000;
					if((j+1)>len) len++;
				}
		}
		printf("%d的阶乘是：\n",n);
		printf("%d",a[len]);
		for(int i=len-1;i>0;i--)
			printf("%02d",a[i]);
		printf("\n请输入数据:");
		memset(a,0,sizeof(a));
	}
	return 0;
} */
int main(){//n>1时阶乘最后一个非零必定是2,4,6,8中的数； 
	int n;long long sum=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		sum*=i;
		while(sum%10==0)
			sum/=10;
		sum%=100000000;
	}
	printf("%lld",sum%10);
	return 0;
}
