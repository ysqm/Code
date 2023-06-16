#include<cstdio>
const int N=5e5+5;
long long a[N],l,s;
int k[N],n;
char c[N];
int r(){
	int o=0;char c=getchar();
	while(c<48||c>57)	c=getchar();
	while(c<58&&c>47)	o=(o<<1)+(o<<3)+(c^48),c=getchar();
	return o;
}
int main(){
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	n=r();
	scanf("%s",c);
	for(int i=1;i<n;++i)	r();
	for(int i=0;i<n;++i){
		int b=(c[i]=='('?1:-1);
		k[i+1]=k[i]+b;
	}
	for(int i=1;i<=n;++i){
		if(c[i-1]==')')
			for(int j=0;j<i;++j)	if(!(k[i]-k[j]))	++l;
		a[i]=l;
	}
	for(int i=1;i<=n;++i)	s^=a[i]*i;
	printf("%lld",s);
	return 0;
}
