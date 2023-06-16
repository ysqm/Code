# include <cstdio>
int main(){
	int i=1,j=2,m,sum=1,k;
	scanf("%d",&m);k=m/2;k++;
	while(i<k){
		if(sum==m){
			printf("%d %d\n",i,j-1);sum-=i;i++;
		}
		else if(sum>m){
			sum-=i;i++;
		}
		else{
			sum+=j;j++;
		}
	}
	return 0;
} 
