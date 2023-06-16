#include<map>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
const int N=5e5;
using namespace std;
int a[N + 42],n,d[N + 42];long long sum; 
inline int re()
{
    int x=0,f=1;char c=getchar();
    while(c>'9'||c<'0') {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') {x=x*10+c-'0'; c=getchar();}
    return x*f;
}
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
		if(a[j]>=a[i]) d[k++]=a[i++];
		else {
			sum+=((long long)mid-i+1);
			d[k++]=a[j++];
		}
	}
	while(i<=mid) d[k++]=a[i++];
	while(j<=right) d[k++]=a[j++];
	for(int h=left;h<=right;h++) a[h]=d[h];
	return; 
}
int main(){
	n = re();
	for(int i=0;i<n;i++)
		a[i] = re();
	jie(0,n-1);
	
	printf("%lld",sum);	
	return 0;
} 
