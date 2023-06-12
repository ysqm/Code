# include <iostream>
# include <cstdio>
# include <cstring>
# include <cstdlib>
# include <algorithm>
using namespace std;
int re(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){s=(s<<1)+(s<<3)+ch-'0';ch=getchar();}
	return s*f;
}
# define mmt(a,b) memset(a,b,sizeof(a))
const int N=2e3+77;
struct edge{
	int to,nt;
}e[N<<1];int cnt=1,hd[N];
int T; int n;
int shu_p[N],p_shu[N];
void add_e(int x,int y){
	e[++cnt]=(edge){y,hd[x]};hd[x]=cnt;
	e[++cnt]=(edge){x,hd[y]};hd[y]=cnt;
}
int visshu[N],visp[N];
struct mkt{
	int fa,i;
}f[N];
int fa[N][20],dep[N];
void dfs(int u,int ff){
	for(int i=1;(1<<i)<=dep[u];++i)
		fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int v,i=hd[u];i;i=e[i].nt){
		v=e[i].to;
		if(v!=ff){
			fa[v][0]=u; dep[v]=dep[u]+1; f[v].fa=u; f[v].i=i;
			dfs(v,u);
		}
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	int cha=dep[x]-dep[y];
	for(int i=0;(1<<i)<=cha;++i)
		if((1<<i)&cha) x=fa[x][i];
	if(x==y) return x;
	for(int i=15;i>=0;--i)
		if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];	
}
void up(int x,int y){
	visp[x]=1;int yy=f[x].fa; swap(p_shu[x],p_shu[yy]); visshu[p_shu[x]]=1;
	while(fa[yy][0]!=y){
		swap(p_shu[yy],p_shu[fa[yy][0]]); visp[yy]=1; visshu[yy]=1; yy=fa[yy][0];
	}
	swap(p_shu[yy],p_shu[fa[yy][0]]); visp[yy]=1; visshu[yy]=1;
}
int lin[N],li;
void dn(int x,int y){
	mmt(lin,0); li=0;
	while(fa[y][0]!=x){
		lin[++li]=y; y=fa[y][0];
	}lin[++li]=x;
	for(int i=li-1;i>=1;--i){
		swap(p_shu[lin[i+1]],p_shu[lin[i]]); visp[lin[i]]=1;
	}
	for(int i=li-1;i>=1;--i){
		visshu[p_shu[lin[i]]]=1;
	}
}
struct kk{
	int p,shu;
	bool operator < (const kk&mk)const{
		shu<mk.shu;
	}
}ans[N];int du[N];
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	T=re();
	while(T--){
		mmt(hd,0); cnt=0; mmt(shu_p,0); mmt(p_shu,0); mmt(fa,0); mmt(dep,0); mmt(f,0);
		mmt(du,0);
		n=re(); int x,y,z;
		for(int i=1;i<=n;++i){
			x=re(); shu_p[i]=x; p_shu[x]=i;
		}
		for(int i=1;i<=n-1;++i){
			x=re(); y=re(); du[x]++; du[y]++; 
			add_e(x,y);
		}
		int rot;
		for(int i=1;i<=n;++i) if(du[i]==n-1) rot=1;
		dfs(rot,0); 
		if(rot==1){
			swap(p_shu[shu_p[1]],p_shu[1]);
			for(int i=1;i<=n;++i) printf("%d ",shu_p[i]);
			printf("\n");
			continue;
		}
		for(int i=1;i<=n;++i){
			if(visshu[i]==0){
				int j=1;
				for(;j<=n;++j){
					if(visp[j]==0) break;
				}
				int x=shu_p[i],y=j;
				if(x==rot||y==rot){
					swap(p_shu[x],p_shu[y]);
					if(x==rot) visp[y]=visshu[p_shu[y]]=1;
					else visp[x]=visshu[p_shu[x]]=1;
				}
			}
		}
		for(int i=1;i<=n;++i) printf("%d ",shu_p[i]);
		printf("\n"); continue;
		/*  cout<<"hfeihfie"<<endl;
		for(int i=1;i<=n;++i){
			if(visshu[i]==0){
				int mn=1e9;
				for(int j=1;j<=n;++j){
					if(visp[j]==0){
						mn=j; break;
					}
				}
				int zu=lca(shu_p[i],mn);
				up(shu_p[i],zu); dn(zu,mn);
			}
		}
		
		mmt(ans,0);
		for(int i=1;i<=n;++i){
			ans[i].p=i; ans[i].shu=p_shu[i];
		}
		sort(ans+1,ans+n+1);
		for(int i=1;i<=n;++i){
			printf("%d ",ans[i].p);
		}printf("\n");*/
	}
	return 0;
}
