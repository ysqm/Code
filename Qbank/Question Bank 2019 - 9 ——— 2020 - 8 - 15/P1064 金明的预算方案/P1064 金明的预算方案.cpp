# include <cstdio>
# include <algorithm>
# include <iostream>
# include <cstring>
using namespace std;
int N,m;
typedef struct{int v,p,q,q1,q2;int flag;} dan;
dan a[62];
int a00,a1,a2,a01,a02,a12,dp[32010];//数组大小问题卡了我三次 
void printd(){
	for(int i=1;i<=N;i++)
	{	if(i%10==1) printf("\n");
		printf("%-5d",dp[i]);
	}
		
	system("pause");
}
int main(){
	scanf("%d%d",&N,&m);
	memset(a,0,sizeof(a));
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].v,&a[i].p,&a[i].q);
		if(a[i].q){
			int qn=a[i].q;a[qn].flag++;
			if(a[qn].q1==0) a[qn].q1=i;
				else a[qn].q2=i;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=N;j>=a[i].v;j--){
			if (a[i].q!=0) break;
				else if(a[i].flag){
					a00=dp[j-a[i].v]+(a[i].v/10)*a[i].p;a1=(a[a[i].q1].v/10)*a[a[i].q1].p;a2=(a[a[i].q2].v/10)*a[a[i].q2].p;
					a01=dp[j-a[i].v-a[a[i].q1].v]+(a[i].v/10)*a[i].p+a1;
					a02=dp[j-a[i].v-a[a[i].q2].v]+(a[i].v/10)*a[i].p+a2;
					a12=dp[j-a[i].v-a[a[i].q2].v-a[a[i].q1].v]+(a[i].v/10)*a[i].p+a2+a1;
					if(j-a[a[i].q1].v-a[a[i].q2].v>=a[i].v){
						dp[j]=max(dp[j],max(a12,max(max(a01,a02),a00)));
						continue;
					}
					if(j-a[a[i].q1].v>=a[i].v){
						dp[j]=max(dp[j],max(a01,a00));
					}
					if(j-a[a[i].q2].v>=a[i].v){
						dp[j]=max(dp[j],max(a02,a00));
					}
				}
			dp[j]=max(dp[j],dp[j-a[i].v]+(a[i].v/10)*a[i].p);
			
		}
		//printd();
	}
		printf("%d",dp[N]*10);
	return 0;
} 
