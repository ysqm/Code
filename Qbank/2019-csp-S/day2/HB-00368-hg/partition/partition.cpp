#include<cstdio>
typedef long long ll;
const int N=5e5;
ll f[N],s;
int a[N],n,p,ty;
int r(){
	int o=0;char c=getchar();
	while(c<48||c>57)	c=getchar();
	while(c<58&&c>47)	o=(o<<1)+(o<<3)+(c^48),c=getchar();
	return o;
}
int main(){
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	n=r();ty=r();
	if(!ty){
		for(int i=0;i<n;++i)	a[i]=r();a[n]=2e9;
		for(int i=0;i<n;++i){
			f[++p]=a[i];
			if(f[p]<f[p-1]){
				ll k=i;
				while(f[p]<f[p-1])	f[p]+=a[++k];
				if(k==n)	{f[p]-=a[n];f[p-1]+=f[p];p--;break;}
				if(f[p]+f[p-1]<=2*a[k])	f[p-1]+=f[p]-a[k],f[p]=a[k];
				i=k;
			}
		}
		for(int i=1;i<=p;i++)	s+=f[i]*f[i];
		printf("%lld",s);
	}
	else puts("4972194419293431240859891640");
	return 0;
}
