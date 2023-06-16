# include <cstdio>
# include <algorithm>
# include <cmath>
using namespace std;
typedef long long LL;
const int N=150;
const LL inf = 1e18;
const double T = 1e18;
inline int re()
{
    int x=0,f=1;char c=getchar();
    while(c>'9'||c<'0') {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') {x=x*10+c-'0'; c=getchar();}
    return x*f;
}
struct tour{
	int lay_x,lay_y;
} c[N+42];
double dis(int x,int y,int a,int b){
	return sqrt((x-a)*(x-a)+(y-b)*(y-b));
}
double m[N+42][N+42],ans = T,e[N+42];
int n;
int tmp;
int main(){
	freopen("testdata.in","r",stdin);
	n=re();
	for(register int i=1;i<=n;i++){c[i].lay_x = re();c[i].lay_y = re();}
	for(register int i=1;i<=n;i++)
		for(register int j=1;j<=n;j++){
			scanf("%1d",&tmp);
            if(tmp) m[i][j] = dis(c[i].lay_x,c[i].lay_y,c[j].lay_x,c[j].lay_y);
            else if(i != j) m[i][j] = T;
		}
	for(register int i=1;i<=n;i++) m[i][i] = 0;
	for(register int k=1;k<=n;k++)
		for(register int i=1;i<=n;i++)
			for(register int j=1;j<=n;j++)
				if(m[k][j]+m[i][k]<m[i][j])
					m[i][j] = m[k][j] + m[i][k];
	double k1;
	for(register int i=1;i<=n;i++)
			for(register int j=1;j<=n;j++){
				if(m[i][j] != T){
					e[i] = max(m[i][j],e[i]);
					k1 = max(m[i][j],k1);
				}
			}	
	for(register int i=1;i<=n;i++)
		for(register int j=1;j<=n;j++)
			if(m[i][j] == T)
				ans = min(ans,e[i]+e[j]+dis(c[i].lay_x,c[i].lay_y,c[j].lay_x,c[j].lay_y));
	printf("%.6lf",max(ans,k1));
	return 0;
}
