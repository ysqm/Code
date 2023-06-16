# include <cmath>
# include <cstdio>
# include <cstring>
# include <cstdlib>
# include <iostream>
# include <algorithm>
# define N 1010
using namespace std;
void printfd(int an[]);
void maisen500(int x[],int y[]);
int ans[N],a[N];int n,s;
int main(){
	ans[0]=1;a[0]=2;
	scanf("%d",&n);n++;
	while(n>0)
    {
        if(n&1)
            maisen500(ans,a);
        n=n>>1;
        maisen500(a,a);
    }
	ans[0]-=2;
	if(ans[0]<0) {
		ans[0]+=10;ans[1]--;
	}
	int k=499;
	while(ans[k]==0) k--;
	while(k>=0)printf("%d",ans[k--]);
	return 0;
}
void maisen500(int x[],int y[]){
	int temp[N]={0},lx=499,ly=499,len;
	while(x[lx]==0&&lx>-1) lx--;
    while(y[ly]==0&&ly>-1) ly--;
    len=lx+ly;
    for(int i=0;i<=ly;i++)
    	for(int j=0;j<=lx;j++)
    		if(i+j<500) temp[i+j]+=y[i]*x[j];
    for(int i=0;i<500;i++) 
    {
        temp[i+1]+=temp[i]/10;
        temp[i]%=10;
    }  
    for(int i=499;i>-1;i--) x[i]=temp[i];	
}

