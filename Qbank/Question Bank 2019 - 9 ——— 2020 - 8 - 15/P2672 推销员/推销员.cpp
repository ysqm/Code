# include <cstdio>
# include <algorithm> 
using namespace std;
const int maxn=100000;
inline int re(){
	int x=0,f=1;char c=getchar();
    while(c>'9'||c<'0') {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') {x=x*10+c-'0'; c=getchar();}
    return x*f;
}
/*inline void out(int num){
	if(num>10) out(num/10);
	putchar(num%10+'0');
}*/
struct node{
	int sum;
	int s;
} a[maxn+42];
bool comp(const node a,const node b){return a.sum>b.sum;}
int n,sum[maxn+42],fr[maxn+42],la[maxn+42];
int main(){
	n=re();
	for(register int i=1;i<=n;i++)a[i].s=re();
	for(register int i=1;i<=n;i++)a[i].sum=re();
	sort(a+1,a+1+n,comp);
	for(register int i=1;i<=n;i++)sum[i]+=sum[i-1]+a[i].sum;
	for(register int i=1;i<=n;i++)fr[i]=max(fr[i-1],a[i].s*2);
	for(register int i=n;i>=1;i--)la[i]=max(la[i+1],a[i].sum+a[i].s*2);
	for(register int i=1;i<=n;i++)printf("%d\n",max(sum[i-1]+la[i],sum[i]+fr[i-1]));
	return 0;
}
/*
	5
1 2 3 4 5
1 2 3 4 5

15
19
22
24
25

5
1 2 2 4 5
5 4 3 4 1	
	
*/
