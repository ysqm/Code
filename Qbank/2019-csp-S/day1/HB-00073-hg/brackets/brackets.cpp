# include <cstdio>
# include <iostream>
# include <algorithm>
# include <set>
# include <vector>
# include <cstring>
# include <cstdlib>
# include <string>
# include <functional> 
const int N=500000;
inline int re(){
	int f=1,x=0;char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') {f=-1;}
		c=getchar();
	}
	while((c>='0')&&c<='9') {
		x=x*10+(c-'0');c=getchar();
		}
	return x*f;
} 
int n;char c;
struct tree{
	int data;
	long long sum;
} tr[N+42];
int f[N+42];
int  check(int l,int r){
	int k=0;
	for(int j=r;j!=f[l];j=f[j]){
		k+=tr[j].data;
		if(k<0) return 0;
	}
	if (k==0) return 1;
	else return 2;//k>0
}
void dfs(int i){
	for(int j=f[i];j!=0;j=f[j]){
		int fl=check(j,i);
		if(fl==1) tr[i].sum++;
		else if(fl==2) continue;
		else break;
	}
	tr[i].sum+=tr[f[i]].sum;
}
long long ans=0;
int main(){
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	n=re();bool fir=false;
	for(int i=1;i<=n;i++){
		c=getchar();
		if(c=='(')tr[i].data=-1;
		else tr[i].data=1;
	}
	for(int i=2;i<=n;i++)f[i]=re();
	for(int i=2;i<=n;i++){
		dfs(i);ans^=(i*tr[i].sum);
	}
	printf("%lld",ans);
	return 0;
}
