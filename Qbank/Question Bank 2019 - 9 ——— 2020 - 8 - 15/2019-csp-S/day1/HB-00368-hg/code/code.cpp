#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
typedef unsigned long long ull;
ull n,k;
string s;
void dfs(ull i,ull a){
	if(i){
		ull k=1;
		for(int j=1;j<i;j++)	k<<=1;
		if(k<=a)	s+='1',dfs(i-1,(k<<1)-a-1);
		else s+='0',dfs(i-1,a);
	}
}
int main(){
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	cin>>n>>k;
	dfs(n,k);
	cout<<s;
	return 0;
}
