# include <cstdio>
# include <algorithm>
using namespace std;
typedef long long LL;
typedef double D;
const int N=100;
const LL inf = 1e18;
const D T = 1e18;
inline int re()
{
    int x=0,f=1;char c=getchar();
    while(c>'9'||c<'0') {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') {x=x*10+c-'0'; c=getchar();}
    return x*f;
}
struct horse{
	int Ei,Si;
} h[N+42],hr;
LL g[N+42][N+42],dis[N+42][N+42];
D t[N+42][N+42];
int n,Q,a,x,y;
int main(){
	n=re();Q=re();
	for(register int i=1;i<=n;i++){
		h[i].Ei=re();h[i].Si=re();
	}
	for(register int i=1;i<=n;i++)
		for(register int j=1;j<=n;j++){
			a=re();
			if(a!=-1) g[i][j] = dis[i][j] = a;
			else g[i][j] = dis[i][j] = inf;
			t[i][j]=T;
	}
	for(register int k=1;k<=n;k++)
		for(register int i=1;i<=n;i++)
			for(register int j=1;j<=n;j++)
				if(dis[k][j]+dis[i][k]<dis[i][j])
					dis[i][j] = dis[k][j]+dis[i][k];
	for(register int i=1;i<=n;i++)
			for(register int j=1;j<=n;j++)
				if(dis[i][j]<=h[i].Ei) t[i][j]=dis[i][j]/(D)h[i].Si;
				else t[i][j]=T;
	for(int i=1;i<=n;i++) t[i][i]=0;
	for(register int k=1;k<=n;k++)
		for(register int i=1;i<=n;i++)
			for(register int j=1;j<=n;j++)
				if(t[k][j]+t[i][k]<t[i][j]) {
					t[i][j] = t[k][j] + t[i][k];
				}
	while(Q--){
		x=re();y=re();
		printf("%.6lf\n",t[x][y]);
	}
	return 0;
} 
