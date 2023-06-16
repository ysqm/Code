# include <cmath>
# include <cstdio>
# include <cstring>
# include <cstdlib>
# include <iostream>
# include <algorithm>
# define N 5010
using namespace std;
int getlen(int an[]);bool flag;
bool compare1(int a[],int b[],int len,int gw);
void myscanf();
void divide1(int lena,int lenb);
int res[N],ans[N],bns[N],n;
void jw10(int a[]);//无法处理最高位为零或小于零 
int main(){
	myscanf();//if(!flag) return 0;
	divide1(getlen(ans),getlen(bns));int i=0;
	while(res[i]==0) i++;
	while(i<=n) printf("%d",res[i++]);
	return 0;
}
void myscanf(){
	char an[N],bn[11];
	scanf("%s%s",an,bn);
	int i=0,j=0,la=strlen(an),lb=strlen(bn);
	while(an[i]=='0')i++;
	while(bn[j]=='0')j++;int k=0;
	while(la>i){ans[k]=an[i]-'0';i++;k++;}k=0;
	while(lb>j){bns[k]=bn[j]-'0';j++;k++;}
	ans[la]=-1;
	bns[lb]=-1;n=la;
}
void divide1(int lena,int lenb){
	int times=lena-lenb,gao=0,i=0;
	while(times>=0){
		while(compare1(ans,bns,lenb,gao)){
			for(i=0;i<lenb;i++){
				ans[i+gao]-=bns[i];	
			}	res[i+gao]++;
			for(i=0;i<lena;i++){
				if(ans[i]<0){
					ans[i-1]--;ans[i]+=10;
				}
			}
		}
		ans[gao+1]+=ans[gao]*10;
		gao++;times--;
	}
}
bool compare1(int a[],int b[]/*被除数*/,int len/*除数位数*/,int gw/*目前减到的最高位*/){//注意要去前导零 
	for(int i=0;i<len;i++){
		if(a[i+gw]>b[i]) return true;
		else if(a[i+gw]<b[i]) return false;
	}
	return true;
}
void jw10(int a[]){
	int la=getlen(a);
	for(int i=0;i<la;i++){
		if(a[i]<0){
			a[i-1]--;a[i]+=10;
		}
	}
}
int getlen(int an[]){
	int i=0;
	while(an[i]!=-1) i++;
	return i;
}
