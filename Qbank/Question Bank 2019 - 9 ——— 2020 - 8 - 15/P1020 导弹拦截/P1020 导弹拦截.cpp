#include<map>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
int sys[100010],ans=1,nowt,d[100010],i=1,len=1;
int main(){
	scanf("%d",&d[0]);sys[ans]=d[0];
	while(scanf("%d",&d[i]),d[i]!=0){
		nowt=lower_bound(sys+1,sys+1+ans,d[i])-sys;
		sys[nowt]=d[i++];
		ans=max(ans,nowt);
	}memset(sys,0,sizeof(sys));sys[0]=d[0];
	//for(int j=1;j<i;j++){
       // if(d[j]<sys[len])
          //  sys[++len]=d[j];
       // else{
      //      int k=lower_bound(sys,sys+len,d[j],greater <int> ())-sys;
      //      sys[k]=d[j];
     //   }
   // }
	for(int j=1;j<i;j++){
		if(sys[len]>=d[j])sys[++len]=d[j];
		else{
   	    	int p=upper_bound(sys,sys+len,d[j],greater<int>())-sys;
   	    	sys[p]=d[j];
		}
	}
	printf("%d\n%d",++len,ans);
	return 0;
} 
