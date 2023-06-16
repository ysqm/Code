# include <cstdio>
# include <algorithm>
# include <cmath> 
using namespace std;
inline int re()
{
    int x=0,f=1;char c=getchar();
    while(c>'9'||c<'0') {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') {x=x*10+c-'0'; c=getchar();}
    return x*f;
}
int a,b,l,ansa,ansb;
double eq,ans,e;
int main(){
	freopen("ratio.in","r",stdin);
	freopen("ratio.out","w",stdout);
	a = re();
	b = re();
	l = re();
	for(register int i = 1;i <= l;i++)
			if(a % i == 0 && b % i == 0){
				a /= i;b /= i;
			}
	eq = a / (double)b;
	ansa = 1;
	ansb = 1;
	ans = 1;
	e = abs(ans - eq);
	for(register int i = 1;i <= l;i++)
		for(register double j = 1;j <= l;j++)
			if(abs(i / j - eq) < e){
				ansa = i;
				ansb = j;
				e = abs(i / j - eq);
			}
	printf("%d %d",ansa,ansb);
	return 0;
} 
