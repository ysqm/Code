# include <cstdio>
# include <algorithm>
# define R register
# define I inline
# define N 300
# define M 100000
# define inf 1000000000
using namespace std;
I int re()
{
	int f = 1,x = 0;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}
int a[N + 42];
I int cut(int i)
{
	return a[i]==i?a[i]:a[i]=cut(a[i]);
}
I void cha(int x,int y)
{
	if(cut(x)!=cut(y)) 
		a[a[y]]=a[a[x]];
}
struct edge
{
	int start,to,wi;
	I bool operator < (const edge b) const
	{
		return wi < b.wi;
	}
} e[M * 2 + 42];
int n,m,head[N + 42],tot = 0,k = 1,ans = 0;
int main()
{
	n = re();
	int d = 0;
	for(R int i = 1,a;i <= n; i++ )
		for(R int j = 1;j <= n;j++){
			a = re();
			if(j > i){
				e[++d].start = i;
				e[d].to = j;
				e[d].wi = a;
				e[++d].start = j;
				e[d].to = i;
				e[d].wi = a;
			}
		}
	sort(e + 1,e + d +1);
	for(R int i = 1;i <= n; i++) a[i] = i;
	int u,v;
	while(tot != n-1){
		u = e[k].start;
		v = e[k].to;
		if(cut(u) == cut(v)){
			k++;
		}
		else {
			ans += e[k].wi;
			cha(u,v);
			tot++;
			k++;
		}
	}
	printf("%d",ans);
	return 0;
}
