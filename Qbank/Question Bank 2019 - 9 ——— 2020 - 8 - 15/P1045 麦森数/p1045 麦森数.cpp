# include <cmath>
# include <cstdio>
# include <cstring>
# include <cstdlib>
# include <iostream>
# include <algorithm>
# define N 10000
using namespace std;
void printfd(long long an[]);
void maisen500(int n);
const long long maxn = 1e+10;
long long ans[N];
int main(){
	int n,s,l=1;ans[0]=1;
	scanf("%d",&n);
	s=n*log10(2)+1;
	maisen500(n);
	ans[0]--;
	printf("%d\n",s);
	printfd(ans);
	return 0;
}
void printfd(long long an[]){
	for(int i=49;i>=0;i--){
		if(i%5==4) {
			printf("\n");
		}
		printf("%010lld",an[i]);
	}
}
void maisen500(int n){
	int t=n%29,tt=n/29,wei=0;
	for(int i=1;i<=t;i++)
		ans[0]*=2;
	for(int i=0;i<tt;i++){
		long long x=0;
		for(int j=0;j<=wei&&j<50;j++){
			ans[j]=ans[j]*536870912+x;
			x=ans[j]/maxn;
        	ans[j]%=maxn;
		}
		 if(x>0) {
            wei++;
            ans[wei]=x;
        }
	}
}
