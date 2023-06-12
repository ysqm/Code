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
int n,i,j;
int x,y,ans = 0;
int main(){
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	n = re();
	x = re();
	y = re();
	while(x != 1 && y != 1 && x != n && y != n){
		x--;
		y--;
		n--;
		ans += n * 4;
		n--;
	}
	if(x == 1) ans += y;
	else if(y == n) ans += n + y - 1;
	else if(x == n) ans += n + n - 1 + n - y;
	else if(y == 1) ans += n + n + n - 1 - 1 + n - y - 1;
	printf("%d",ans);
	return 0;
} 
