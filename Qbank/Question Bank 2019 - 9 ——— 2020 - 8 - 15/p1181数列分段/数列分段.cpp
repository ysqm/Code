#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n,sup=0,step=1,sum=0,a;
	scanf("%d%d",&n,&sup);
	while(n--){
		scanf("%d",&a);
		if(a+sum>sup){
			step++;sum=a;
		}
		else sum+=a;
	}
	printf("%d",step);
	return 0;
} 
