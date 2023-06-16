# include <cstdio>
# include <queue>
# include <algorithm> 
# define N 20000
# define M 100000
# define R register
using namespace std;
inline int cut(int i);
inline int re()
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
struct edge
{
	int from,to,wi;
} e[M + 42];
inline bool comp(const edge a,const edge b)
{
	return a.wi>b.wi;
}
int a[N + 42],n,m,ans,b[N + 42];
int main()
{	
	//freopen("testdata.in","r",stdin);
	n = re();
	m = re();
	
	for(R int i = 1;i <= n; i++) a[i] = i;
	
	
	for(R int i = 1;i <= m; i++){
		 e[i].from = re();
		 e[i].to = re();
		 e[i].wi = re();
	}
	
	sort(e + 1,e + m + 1,comp);
	int x,y;
	
	for(R int i = 1;i <= m;i++){
		x = cut(e[i].from);
		y = cut(e[i].to);
		if(x == y){
			printf("%d",e[i].wi);
			return 0;
		}
		
		if(!b[e[i].from]) b[e[i].from] = e[i].to;
		else a[cut(a[b[e[i].from]])] = a[e[i].to];
		
		if(!b[e[i].to]) b[e[i].to] = e[i].from;
		else a[cut(a[b[e[i].to]])] = a[e[i].from];
		
	}
	printf("0");
	return 0;
}
inline int cut(int i)
{
	if(i != a[i]){
		a[i] = cut(a[i]);
	}
	return a[i];
}
