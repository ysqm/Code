# include <cstdio>
# include <vector>
using namespace std;
struct edge{
	//int ans;//存储答案 
	int from;//与它指向同一边的另一条边 
	int v,u;//v来自那条边 u被指向的边 
} e[100005];
int n,m,head[100005],a,b,ans[100005];
void dfs(int nod,int num);
void dfs(int nod,int num){
	if(ans[nod]) return;
	ans[nod]=num;
	for(int i=head[nod];i;i=e[i].from)
		dfs(e[i].v,num);
}
int main(){
	scanf("%d%d",&n,&m);
	for(register int i=1;i<=m;i++){
		scanf("%d%d",&a,&b);//从a->b的一条边 
		e[i].from=head[b];e[i].v=a;//e[i].u=b; 
		head[b]=i;
	}
	for(register int i=n;i>0;i--)
		if(!ans[i]) dfs(i,i);
		//倒着枚举已有值必定最大 
	for(register int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0; 
}
