#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
int n,a[101];
int main(){
	scanf("%d",&n);
	printf("%d\n",n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if (j!=i) a[j]=1-a[j];
			printf("%d",a[j]);
		}
		printf("\n");
	}
	return 0;
} 
