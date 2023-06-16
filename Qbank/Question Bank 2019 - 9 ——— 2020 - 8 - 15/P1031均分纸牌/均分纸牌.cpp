#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n,a[100000],sum=0,step=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]),sum+=a[i];
	sum/=n;
	for(int i=0;i<n;i++)
		a[i]-=sum;
	for (int i=0;i<n;i++){
		if (a[i]==0)continue; 
		a[i+1]+=a[i]; step++; 
	}  
	printf("%d",step);
	return 0;
} 
