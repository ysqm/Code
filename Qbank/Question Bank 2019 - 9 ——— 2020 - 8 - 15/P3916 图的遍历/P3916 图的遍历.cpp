# include <cstdio>
# include <vector>
using namespace std;
struct edge{
	//int ans;//�洢�� 
	int from;//����ָ��ͬһ�ߵ���һ���� 
	int v,u;//v���������� u��ָ��ı� 
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
		scanf("%d%d",&a,&b);//��a->b��һ���� 
		e[i].from=head[b];e[i].v=a;//e[i].u=b; 
		head[b]=i;
	}
	for(register int i=n;i>0;i--)
		if(!ans[i]) dfs(i,i);
		//����ö������ֵ�ض���� 
	for(register int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0; 
}
