# include <cmath>
# include <cstdio>
# include <cstring>
# include <cstdlib>
# include <iostream>
# include <algorithm>
# define N 2000
using namespace std;
int jinzhi(int stayed[],int lon);
void myscanf();
int ans[N*3],bns[N],cns[N],c,b;
int main(){
	int n;
	myscanf();
	/*b=jinzhi(bns,b);
	c=jinzhi(cns,c);*/n=c+b;n--;
	for(int i=0;i<b;i++){
		for(int j=0;j<c;j++){
			ans[i+j]+=bns[i]*cns[j];
		}	
	}
	for(int j=0;j<n;j++)
		for(int k=0;k<n;k++)
			if(ans[k]>=10){ans[k-1]+=ans[k]/10;ans[k]%=10;}	
	int i=0;
	while(i<n-1&&ans[i]==0) i++;
	for(;i<n;i++)//0乘10，有问题输出两个0 
		printf("%d",ans[i]);
	return 0;
}
void myscanf(){
	char an[2020],bn[2020];
	scanf("%s%s",an,bn);
	int i=0,j=0,la=strlen(an),lb=strlen(bn);
	while(an[i]=='0')i++;
	while(bn[j]=='0')j++;int k=0;
	while(la>i){bns[k]=an[i]-'0';i++;k++;}k=0;
	while(lb>j){cns[k]=bn[j]-'0';j++;k++;}
	b=i;c=j;
}
/*int jinzhi(int stayed[],int lon){
	int j=0,lo,ba[2010],k=0;
	for(int i=0;i<lon;i+=3){
		stayed[j]=stayed[i]*100+stayed[i+1]*10+stayed[i+2];
		ba[j]=stayed[j];j++;
	}lo=j;
	for(;j<lon;j++){
		stayed[j]=0;
	}
	return lo;
	while(lo-k){
		stayed[lo-k-1]=ba[k++];
	}
}*/
