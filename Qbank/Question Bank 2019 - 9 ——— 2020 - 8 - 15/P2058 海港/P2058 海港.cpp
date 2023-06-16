# include <cstdio>
# include <algorithm> 
using namespace std;
const int N=300000;
inline int re(){
	int x=0,f=1;char c=getchar();
    while(c>'9'||c<'0') {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') {x=x*10+c-'0'; c=getchar();}
    return x*f;
}
int pas[N+42],s=0,x[N+42],tx[N+42],n,k,t,p,i=1,j=1;
int main(){
	freopen("testdata.in","r",stdin);
	n=re();
	while(n--){
		t=re();k=re();
		while(k--){
			p=re();
			if(!x[p]) s++;
			x[p]++;
			pas[i]=p;
			tx[i++]=t;
		}
		while(t-tx[j]>=86400){
			x[pas[j]]--;
			if(!x[pas[j]]) s--;
			j++;
		}
		printf("%d\n",s);
	}
	return 0;
}
