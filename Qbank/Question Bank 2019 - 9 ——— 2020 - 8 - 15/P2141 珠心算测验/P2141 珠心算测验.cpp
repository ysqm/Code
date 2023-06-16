#include<cstdio>
using namespace std;
int t[20100],n,p[20100],a[210],maxn;
inline int re()
{
    int x=0,f=1;char c=getchar();
    while(c>'9'||c<'0') {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') {x=x*10+c-'0'; c=getchar();}
    return x*f;
}
inline void output(int x){
    if(x>=10){
        output(x/10);
    }
    putchar(x%10+'0');
}
int main()
{
	n=re();int c;
	for(register int i=0;i<n;i++){
		a[i]=re();t[a[i]]=1;
		maxn=maxn>a[i]?maxn:a[i];
	}c=0;
	for(register int i=0;i<n;i++)
		for(register int j=i+1;j<n;j++)
			if(t[a[i]+a[j]]) p[a[i]+a[j]]++;
	for(register int i=0;i<n;i++)
		if(p[a[i]]) c++;
	output(c);
	return 0;
}
