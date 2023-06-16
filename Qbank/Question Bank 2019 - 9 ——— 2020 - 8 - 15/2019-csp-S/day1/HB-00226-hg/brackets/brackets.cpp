# include <iostream>
# include <cstdio>
# include <cstring>
# include <cstdlib>
# define LL long long
using namespace std;
int re(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){s=(s<<1)+(s<<3)+ch-'0';ch=getchar();}
	return s*f;
}
const int N=5e5+77;
int n;char hao;
struct edge{
	int to,nt;
}e[N<<1];int cnt,hd[N];
void add_e(int x,int y){
	e[++cnt]=(edge){y,hd[x]};hd[x]=cnt;
	e[++cnt]=(edge){x,hd[y]};hd[y]=cnt;
}
int a[N];
int pre[N],jin;int he[N]; 
LL f[N];int fa[N];LL ans=0; LL ksum;
void dfs(int u,int ff,LL sum){
	for(int v,i=hd[u];i;i=e[i].nt){
		v=e[i].to;
		if(v!=ff){
			fa[v]=u; ksum=0;
			if(he[u]<0) he[v]=a[v];
			else he[v]=he[u]+a[v];
			if(a[v]==1){
				pre[v]=jin,jin=v;	
			} 
			if(he[u]>0&&a[v]==-1){
				f[v]=f[fa[jin]]+1;
				ksum=sum+f[v]+(f[u]!=0)+(f[u]!=0)*f[v]; jin=pre[jin];
			}
			if(he[u]<0) jin=0;
			ans^=v*ksum; //cout<<u<<" "<<v<<' '<<ksum<<' '<<ans<<endl;
			dfs(v,u,ksum);
			if(u==1){
				if(a[u]==1) jin=1;
				else jin=0;
			} //jin=0,sum=0;
		}
	}
}
int main(){//       1.txt                  
	freopen("brackets.in","r",stdin);
	freopen("brackets.in","w",stdout);
	n=re();
	for(int i=1;i<=n;++i){
		scanf("%c",&hao);
		if(hao=='(') a[i]=1;
		else a[i]=-1;
	}
	int x,y,z;
	for(int i=2;i<=n;++i){
		x=re(); add_e(x,i);
	}
	he[1]=a[1]; 
	if(a[1]==1) jin=1;
	else jin=0;
	dfs(1,0,0); printf("%lld",ans);
	/*cout<<endl;
	for(int v,i=hd[1];i;i=e[i].nt){
		v=e[i].to;
		cout<<v<<' ';
	}*/
	return 0;
}
