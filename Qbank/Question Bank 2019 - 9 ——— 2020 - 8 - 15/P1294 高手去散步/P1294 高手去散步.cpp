# include <cstdio>
# include <algorithm>
# include <set>
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
int n,mp[60][60],ans,m;
bool vis[55];
int dfs(int k,int su)//分别是当前位置和当前取到的距离 
{	
	if(su>ans) ans=su;
    for(int i=1;i<=n;i++)
    	if(vis[i]==false&&mp[k][i]){
    		vis[i]=true;
    		dfs(i,su+mp[k][i]);
    		vis[i]=false;
		}
	
}
int main(){
	n=re();m=re();
	for(int i=0,a,b,c;i<m;i++){
		a=re();b=re();c=re();
		mp[a][b]=c;mp[b][a]=c;
	}
	for(int i=1;i<=n;i++){
		vis[i]=true;
		dfs(i,0);
		vis[i]=false;
	}
	fuckout(ans);
	return 0;
}
