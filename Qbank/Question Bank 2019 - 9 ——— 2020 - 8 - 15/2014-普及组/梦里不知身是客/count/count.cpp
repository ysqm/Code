# include <cstdio>
# include <algorithm>
# define N 10000
using namespace std;
inline int re()
{
    int x=0,f=1;char c=getchar();
    while(c>'9'||c<'0') {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') {x=x*10+c-'0'; c=getchar();}
    return x*f;
}
int n,s = 0;
int a[N * 2 + 42],b[100 + 42];
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	n = re();
	for(register int i = 1;i <= n;i++)	b[i] = re();
	for(register int i = 1;i <= n;i++)
		for(register int j = i+1;j <= n;j++)
			a[b[i] + b[j]]++;
	for(register int i = 1;i <= n;i++)
		if(a[b[i]]) s++;
	printf("%d",s);
	return 0;
} 
