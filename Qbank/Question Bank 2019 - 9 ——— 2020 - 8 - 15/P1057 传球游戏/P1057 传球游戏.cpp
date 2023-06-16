# include <cstdio>
# include <algorithm>
using namespace std;
inline int re()
{
    int x=0,f=1;char c=getchar();
    while(c>'9'||c<'0') {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') {x=x*10+c-'0'; c=getchar();}
    return x*f;
}
inline void fuckout(int x){
    if(x>=10){
        fuckout(x/10);
    }
    putchar(x%10+'0');
} 
int n,ans=0,dp[42][42],m;
int main(){
	n=re();m=re();
	dp[1][1]=1;
	for(int i=1,a,b;i<=m;i++){
		for(int j=1;j<=n;j++){
			a=j-1;b=j+1;
			if(a==0) a=n;
			if(b==n+1) b=1;
			dp[i][j]+=dp[i-1][a]+dp[i-1][b];
		}
	}
	fuckout(dp[m][1]);
	return 0;
}
