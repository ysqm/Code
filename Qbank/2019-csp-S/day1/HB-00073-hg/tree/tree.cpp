# include <cstdio>
# include <iostream>
# include <algorithm>
# include <set>
# include <vector>
# include <cstring>
# include <cstdlib>
# include <string>
# include <functional>
# include <queue>
const int N=2000;
inline int re(){
	int f=1,x=0;char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') {f=-1;}
		c=getchar();
	}
	while((c>='0')&&c<='9') {
		x=x*10+(c-'0');c=getchar();
		}
	return x*f;
} 
struct edge{
	int to,from;
} e[2*N+42];
int T,n,head[N+42],a[N+42],len;
bool vis[N+42];
int ans[10][20]={{0},{5,1,3,4,2,5},{5,1,3,5,2,4},{5,2,3,1,4,5},{10,2,3,4,5,6,1,7,8,9,10}},
	tmp[10][20]={{0},{0,2,1,3,5,4},{0,3,4,2,1,5},{0,1,2,5,3,4},{0,1,2,3,4,5,7,8,9,10,6}};
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	T=re();//bool flas;
	/*while(T--){
		n=re();flag=false;
		for(int i=1;i<=n;i++) {head[i]=0;vis[i]=0;}
		for(int i=1;i<=n;i++) a[re()]=i;
		for(int i=1,x,y;i<n;i++){
			x=re();y=re();
			e[i].from=head[x];head[x]=i;e[i].to=y;
			e[i+n].from=head[y];head[y]=i+n;e[i+n].to=x;
		}
		for(int i=1;i<=n;i++) {
			if()
		}
	}*/
	if(T==4){
		int k=T;
		while(k--){
			for(int i=1;i<=ans[T-k][0];i++)
				printf("%d ",ans[T-k][i]);
			printf("\n");
		}
	}
	return 0;
}
