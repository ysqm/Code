# include <cmath>
# include <cstdio>
# include <cstring>
# include <cstdlib>
# include <iostream>
# include <algorithm>
# define N 600
using namespace std;
char an[N],bn[N];
int a[N],b[N],ans[N],la,lb,lmax,i=0,j=0;
int main(){
	scanf("%s%s",an,bn);
	la=strlen(an);lb=strlen(bn);
	lmax=la>lb?la:lb;lmax++;
	while(an[i]=='0') i++;
	while(bn[j]=='0') j++;
	while(la-i>0){a[i]=an[la-i-1]-'0';i++;}
	while(lb-j>0){b[j]=bn[lb-j-1]-'0';j++;}
	for(i=0;i<lmax;i++){
		ans[i]+=a[i]+b[i];
		if(ans[i]>=10){ans[i+1]++;ans[i]-=10;}
	}
	while(ans[i]==0) i--;
	while(i>0) printf("%d",ans[i--]);
	printf("%d",ans[0]);
	return 0;
} 		
