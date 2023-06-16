# include <cstdio>
# include <algorithm>
# include <cmath>
int n,m,k,l,d;
using namespace std;
struct edge{
	int X,Y;
	int P,Q;
} e[2010];
struct bian{
	int ans,num;
} L[1010],H[1010];
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
bool comp(const bian a,const bian b){
	return a.ans>b.ans;
}
inline bool cmp(const bian x,const bian y)
{
    return x.num<y.num;
}
int main(){
	m=re();n=re();k=re();l=re();d=re();
	for(int i=1;i<=d;i++){
		e[i].X=re();e[i].Y=re();
		e[i].P=re();e[i].Q=re();
	}
	for(int i=1;i<=d;i++){
		if(e[i].P==e[i].X)
			L[min(e[i].Q,e[i].Y)].ans++;
		else 
			H[min(e[i].P,e[i].X)].ans++;
	}
	for(int i=1;i<=n;i++)
		L[i].num=i;
	for(int i=1;i<=m;i++)
		H[i].num=i;
	sort(L+1,L+1+n,comp);
	sort(L+1,L+1+l,cmp);
	sort(H+1,H+1+m,comp);
	sort(H+1,H+1+k,cmp);
	for(int i=1;i<=k;i++)
		printf("%d ",H[i].num);
	printf("\n");
	for(int i=1;i<=l;i++)
		printf("%d ",L[i].num);
	return 0;
}
