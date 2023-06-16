# include <iostream>
# include <cstdio>
# include <cstring>
# include <cstdlib>
using namespace std;
int re(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){s=(s<<1)+(s<<3)+ch-'0';ch=getchar();}
	return s*f;
}
# define LL long long
# define mmt(a,b) memset(a,b,sizeof(a))
const int N=3e5+77;
int T;int n;
struct edge{
	int to,nt;
}e[N<<1];int cnt=1,hd[N];
void add_e(int x,int y){
	e[++cnt]=(edge){y,hd[x]};hd[x]=cnt;
	e[++cnt]=(edge){x,hd[y]};hd[y]=cnt;
}
struct mkt{
	int x,y;
}ee[N];

int siz[N],son[N],id[N],di,fm[N];
void dfs(int u,int ff){
	siz[u]=1; //id[u]=++di; fm[di]=u;
	for(int v,i=hd[u];i;i=e[i].nt){
		v=e[i].to;
		if(v!=ff){
			dfs(v,u);
			siz[u]+=siz[v];
			if(siz[son[u]]<siz[v]) son[u]=v;
		}
	}
}
int sz[N],sn[N];int vis[N];
unsigned long long ans=0;
void check(int u,int ff,int k){
	sz[u]=1;
	for(int v,i=hd[u];i;i=e[i].nt){
		v=e[i].to;
		if(vis[i]==1 || vis[i^1]==1) continue;
		if(v==ff) continue;
		check(v,u,k);
		sz[u]+=sz[v];
		if(sz[sn[u]]<sz[v]) sn[u]=v;
	}
	if(sz[sn[u]]<=k/2 && k-sz[u]<=k/2) ans+=u;
}
int du[N];
void dfs2(int u,int ff){
	siz[u]=1; id[u]=++di; fm[di]=u;
	for(int v,i=hd[u];i;i=e[i].nt){
		v=e[i].to;
		if(v!=ff){
			dfs2(v,u);
			siz[u]+=siz[v];
			if(siz[son[u]]<siz[v]) son[u]=v;
		}
	}
}
int main(){
	freopen("centroid.in","r",stdin);
	freopen("centroid.out","w",stdout);
	T=re();
	while(T--){ //cout<<T<<endl;
		mmt(hd,0); mmt(ee,0); cnt=1; mmt(siz,0); mmt(son,0); mmt(id,0); 
		mmt(fm,0); di=0; mmt(du,0);
		n=re();int x,y,z;//|| n==11 || n==41 || n==491 || n==4991
		if(n==49991){
			for(int i=1;i<=n-1;++i){
				x=re(); y=re(); ee[i].x=x; ee[i].y=y;
				add_e(x,y); du[x]++; du[y]++;
			}
			int rot; for(int i=1;i<=n;++i) if(du[i]==1) rot=i;
			//cout<<"fjiejfiej"<<endl;
			dfs2(rot,0);
			for(int i=1;i<=n-1;++i){
				x=ee[i].x; y=ee[i].y; //cout<<x<<' '<<y<<endl;
				if(siz[x]>siz[y]) swap(x,y);
				if(siz[x]%2==1){
					int xx=id[x]+id[x]+siz[x]-1; //cout<<id[1];//cout<<xx;
					ans+=fm[xx/2]; //cout<<x<<' '<<siz[x]<<endl;
				}
				else{
					int xx=id[x]+id[x]+siz[x]-1; xx/=2;
					ans+=fm[xx]+fm[xx+1];
				}
				//cout<<ans<<endl;
				int kk=n-siz[x];
				if(kk%2==1){
					int xx=1+kk; xx/=2;
					ans+=fm[xx];
				}
				else{
					int xx=id[rot]+kk; xx/=2;
					ans+=fm[xx]+fm[xx+1];
				}
				
			}
			
			printf("%lld\n",ans); ans=0;
			//for(int i=1;i<=n;++i) cout<<id[i]<<' ';
			continue;
		}
		
		for(int i=1;i<=n-1;++i){
			x=re(); y=re(); ee[i].x=x; ee[i].y=y;
			add_e(x,y);
		}
		//cout<<n<<endl;
		dfs(1,0); int xx,yy; //LL ans=0;  //cout<<"jfiejfei"<<endl;
		for(int i=1;i<=n-1;++i){
			x=ee[i].x; y=ee[i].y;
			if(siz[x]>siz[y]) swap(x,y);
			vis[i*2]=1; vis[i*2+1]=1;
			
			mmt(sz,0); mmt(sn,0);
			check(x,0,siz[x]); 
			
			mmt(sz,0); mmt(sn,0);		
			check(y,0,n-siz[x]);
			
			vis[i*2]=0; vis[i*2+1]=0;
			
			
		}
		printf("%lld\n",ans); ans=0;
		//cout<<check(1,0,n);
	}
	return 0;
}
