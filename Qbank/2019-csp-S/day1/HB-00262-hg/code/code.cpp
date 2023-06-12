#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<iostream>
using namespace std;
typedef long long LL;
LL pow_(LL z)
{
	LL t=1;
	while(z--)
	{
		t*=2;
	}
	return t;
}
LL n,k,L,ft;
bool dir[80]; 
char ans[80];
void solve(LL p,LL mid,LL step)
{
	if(step==1)
	{
		ans[ft++]=p+48;
		return ;
	}
	if(p>=mid) dir[step]=true,solve(mid-(p-mid+1),mid>>1,step-1); 
	else solve(mid-(mid-p),mid>>1,step-1);
	if(dir[step]) ans[ft++]='1';
	else ans[ft++]='0';
	return ;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	L=pow_(n);
	solve(k,L>>1,n);
	for(LL i=ft-1;i>=0;i--)
		printf("%c",ans[i]);
	return 0;
}
