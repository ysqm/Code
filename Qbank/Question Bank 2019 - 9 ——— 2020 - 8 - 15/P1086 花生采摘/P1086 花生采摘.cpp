# include <iostream>
# include <cstdio>
# include <algorithm>
using namespace std;
typedef struct {int x,y,time,peanuts;} dian;
dian waits[600];
bool comp(const dian a,const dian b){
	return a.peanuts>b.peanuts;
}
int M,N,K,a,k,u,ans;
int main(){
	cin.sync_with_stdio(false);
	cin>>M>>N>>K;
	for(int i=1;i<=M;i++)
		for(int j=1;j<=N;j++){
			cin>>a;
			if(a>0){
				waits[k].y=j;
				waits[k].x=i;
				waits[k].peanuts=a;
				k++;
			}
		}
	sort(waits,waits+k,comp);
	for(int i=0;i<k;i++){
        u=waits[i].x;
        if(i==0) waits[i].time=waits[i].x+1;
        else waits[i].time=waits[i-1].time+abs(waits[i].x-waits[i-1].x)+abs(waits[i].y-waits[i-1].y)+1;
        if (waits[i].time+u<=K) ans+=waits[i].peanuts;
     }
    cout<<ans;
	return 0;
}
