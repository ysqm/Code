# include <cmath>
# include <cstdio>
# include <cstring>
# include <cstdlib>
# include <iostream>
# include <algorithm>
# define N 10100
using namespace std;
char an[N],bn[N];
int a[N],b[N],ans[N],la,lb,lmax,i=0,j=0;bool flag=true;
void myswap(int ad[],int bd[],int big){
	int temp;
	for(int i=0;i<big;i++){
		temp=ad[i];ad[i]=bd[i];bd[i]=temp;
	}
	return;
}
void myjudge(int ad[],int bd[],int ab,int bb,int big){
	if(ab!=bb) {
		for(int i=big;i>0;i--){
			if(bd[i]>ad[i]){
				flag=false;
				return;
			} 
			else if(bd[i]<ad[i]){
				return;
			}
		}
	}
	return;
}
int main(){
	scanf("%s%s",an,bn);
	la=strlen(an);lb=strlen(bn);
	while(an[i]=='0') i++;
	while(bn[j]=='0') j++;
	la-=i;lb-=j;lmax=la>lb?la:lb;
	while(la-i>0){a[i]=an[la-i-1]-'0';i++;}
	while(lb-j>0){b[j]=bn[lb-j-1]-'0';j++;}
	myjudge(a,b,la,lb,lmax);
	if(!(flag)) myswap(a,b,lmax);
	for(i=0;i<lmax+1;i++){
		ans[i]+=(a[i]-b[i]);
		if(ans[i]<0){ans[i+1]--;ans[i]+=10;}
	}
	if(!(flag)) printf("-");
	while(ans[i]==0) i--;
	while(i>0) printf("%d",ans[i--]);
	printf("%d",ans[0]);
	return 0;
} 		
