# include <cstdio>
# include <queue>
using namespace std;
queue <int> q;
const int mod=100003;
struct edge{
	//int ans;//存储答案 
	int from;//与它指向同一边的另一条边 
	int to; 
} e[4000005];
int n,m,head[1000005],ans[1000005],deep[1000005];
bool vis[1000005];
int main(){
	scanf("%d%d",&n,&m);
	for(register int i=1,a,b;i<=m;i++){
		scanf("%d%d",&a,&b);
		if(a==b) continue;
		e[i].from=head[a];e[i].to=b;head[a]=i;
		e[i+m].from=head[b];e[i+m].to=a;head[b]=i+m;
	}
	vis[1]=1;q.push(1);ans[1]=1;deep[1]=0;
	int temp;
	while(!q.empty()){
		temp=q.front();q.pop();
		for(register int i=head[temp];i;i=e[i].from){
			int t=e[i].to;
			if(!vis[t]){
				vis[t]=1;deep[t]=deep[temp]+1;
				q.push(t);
			}
            if(deep[t]==deep[temp]+1) ans[t]=(ans[t]+ans[temp])%mod;
		}
	}
	for(register int i=1;i<=n;i++) printf("%d\n",ans[i]);
	return 0; 
}
