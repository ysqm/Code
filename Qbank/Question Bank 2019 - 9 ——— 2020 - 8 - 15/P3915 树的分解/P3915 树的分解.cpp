# include <cstdio>
# include <algorithm>
# include <vector>
using namespace std;
const int maxn=1e5; 
struct node{
	int from,to;
} e[maxn*2+10];
int T,N,K,a,b,cnt;int head[maxn+10],Size[maxn+10];
void dfs(int u,int fa){
	Size[u]=1;
	for(int i=head[u];i;i=e[i].from){
		int V=e[i].to;
		if(V!=fa){
			dfs(V,u);
			Size[u]+=Size[V]; 
		} 
	}
	if(Size[u]==K) {
		cnt++;
		Size[u]=0;
	}
}
int main(){
	
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&N,&K);
		cnt=0;
		//memset()
		//for(int i=1;i<N;i++) head[i]=0;
		for(int i=1;i<N;i++){
			scanf("%d%d",&a,&b);
			//e[i].from=head[a];e[i].to=b;head[a]=i;
			//e[i+N].from=head[b];e[i+N].to=a;head[b]=i+N;	
		}
		if(N%K==0) {
			//dfs(1,0);
			//if(cnt==N/K) 
			printf("YES\n");
			//else printf("NO\n");
		}
		else printf("NO\n");
	}
	return 0;
} 
