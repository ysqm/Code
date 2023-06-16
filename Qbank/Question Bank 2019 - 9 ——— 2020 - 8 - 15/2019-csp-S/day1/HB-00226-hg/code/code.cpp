# include <iostream>
# include <cstdio>
# include <cstring>
# include <cstdlib>
using namespace std;
# define LL long long
LL re(){
	LL s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){s=(s<<1)+(s<<3)+ch-'0';ch=getchar();}
	return s*f;
}
LL n,k;
LL pw[70];
void dfs(LL i,LL x){
	if(i==0) return ;
	if(x>pw[i-1]){
		printf("1"); dfs(i-1,pw[i]-x+1);
	}
	else{
		printf("0"); dfs(i-1,x);
	}
}
int main(){//      2.txt         
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	n=re(); k=re(); pw[0]=1; k++;
	for(int i=1;i<=63;++i) pw[i]=pw[i-1]<<1;
	dfs(n,k);
	return 0;
}
