# include <cstdio>
# include <cstring>
# include <algorithm>
using namespace std;
/*int a[10000],n,len=1;
int main(){
	printf("\n����������:");
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
		printf("%d�Ľ׳��ǣ�\n",n);
		printf("%d",a[len]);
		for(int i=len-1;i>0;i--)
			printf("%02d",a[i]);
		printf("\n����������:");
		memset(a,0,sizeof(a));
	}
	return 0;
} */
int main(){//n>1ʱ�׳����һ������ض���2,4,6,8�е����� 
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
