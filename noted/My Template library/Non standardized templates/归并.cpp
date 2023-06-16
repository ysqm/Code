#include<map>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
int a[100010],n,d[100010];
void guibing(int left,int right,int mid);
void jie(int left,int right);
void jie(int left,int right){
	if(left==right) return;
	int mid=left+(right-left)/2;
	jie(left,mid);jie(mid+1,right);
	guibing(left,right,mid);
	return;
}
void guibing(int left,int right,int mid){
	int i=left,j=mid+1,k=left;
	while(i<=mid&&j<=right){
		if(a[i]>a[j]) d[k++]=a[j++];
		else d[k++]=a[i++];
	}
	while(i<=mid) d[k++]=a[i++];
	while(j<=right) d[k++]=a[j++];
	for(int h=left;h<=right;h++) a[h]=d[h];
	return; 
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	jie(0,n-1);
	for(int i=0;i<n-1;i++)
		printf("%d ",a[i]);
	printf("%d\n",a[n-1]);	
	return 0;
} 
