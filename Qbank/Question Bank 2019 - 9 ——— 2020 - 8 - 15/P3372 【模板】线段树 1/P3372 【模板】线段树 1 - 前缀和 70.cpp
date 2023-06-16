#include<map>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
long long an[100010],change[100010],s_change[100010];int x,y,k,flag;
inline int re()
{
	int f = 1,x = 0;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}
void dayin(int x1,int y1){
	long long sum=0;
	for(int i=1;i<=y1;i++){
		s_change[i]+=change[i]+s_change[i-1]; 
	}
	for(int i=x1;i<=y1;i++){
		sum+=an[i]+s_change[i]; 
	}
	printf("%lld\n",sum);
	memset(s_change,0,sizeof(s_change));
	return;
}
void add(){
	if(flag==2){
		dayin(x,y);
		return;
	}
	k = re();
	change[x]+=k;
	change[y+1]-=k;
}
int main(){
	int N,M;
	N = re();
	M = re();
	for(int i=1;i<=N;i++)
		an[i] = re();
	for(int i=1;i<=M;i++){
		flag = re();x = re();y = re();
		add();
	}
	return 0;
} 
