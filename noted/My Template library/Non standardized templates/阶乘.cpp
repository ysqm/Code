# include <cstdio>
# include <cstring>
# include <algorithm>
using namespace std;
long long a[1000000],n,len=1;
int main(){
	printf("\n����������:");
	while(scanf("%d",&n)==1&&n!=0){
		a[1]=1;len=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=len;j++)
				a[j]*=i;
			for(int j=1;j<=len;j++)
				if(a[j]>=10000000){
					a[j+1]+=a[j]/10000000;
					a[j]%=10000000;
					if((j+1)>len) len++;
				}
		}
		printf("%d�Ľ׳��ǣ�\n",n);
		printf("%lld",a[len]);
		for(int i=len-1;i>0;i--)
			printf("%07lld",a[i]);
		printf("\nλ����%d(��׼ȷ)\n�������ĸ��ӣ�%d",len*7,len);
		printf("\n����������:");
		memset(a,0,sizeof(a));
	}
	return 0;
} 
