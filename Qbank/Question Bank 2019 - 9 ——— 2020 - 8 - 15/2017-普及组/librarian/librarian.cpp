# include <cstdio>
# include <algorithm>
using namespace std;
int n,q,a[1010],len,f,mod,ans;
inline int re()
{
    int x=0,f=1;char c=getchar();
    while(c>'9'||c<'0') {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') {x=x*10+c-'0'; c=getchar();}
    return x*f;
}
inline void fuckout(int x)
{
    if(x>=10){
        fuckout(x/10);
    }
    putchar(x%10+'0');
}
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	n=re();q=re();
	for(int i=0;i<n;i++)
		a[i]=re();
	/*for(int i=0,x,temp;i<n;i++){
		x=i;
		for(int j=i+1;j<n;j++)
			if(a[x]>a[j]) x=j;
		temp=a[x];
		a[x]=a[i];
		a[i]=temp;
	}*/	
	sort(a,a+n);
	while(q--){
		len=re();f=re();mod=1;ans=n;
		while(len--) mod*=10;
		for(int i=0;i<n;i++)
			if(a[i]%mod==f){
				ans=a[i];
				break;
			}
		if(ans!=n) fuckout(ans);
		else printf("-1");
		printf("\n");
	}
}
