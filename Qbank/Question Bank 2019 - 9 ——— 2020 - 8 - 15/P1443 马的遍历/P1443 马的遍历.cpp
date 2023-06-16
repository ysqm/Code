# include <iostream>
# include <cstdio>
# include <queue>
using namespace std;
const int fx[10]={0,2,-2,2,-2,-1,1,-1,1},fy[10]={0,1,1,-1,-1,2,2,-2,-2};
typedef struct {int x,y;} dian;
int n,m,vis[410][410];dian sta,b,a;
queue<dian> q;
int main(){
	scanf("%d%d%d%d",&n,&m,&sta.x,&sta.y);
	memset(vis,-1,sizeof(vis));vis[sta.x][sta.y]=0;
	q.push(sta);
	while(q.size()){
		a=q.front();
		for(int i=1;i<9;i++){
			b.x=a.x+fx[i],b.y=a.y+fy[i];
			if(vis[b.x][b.y]!=-1||b.x<1||b.x>n||b.y<1||b.y>m) continue;
			vis[b.x][b.y]=vis[a.x][a.y]+1;
			q.push(b);
		}
		q.pop();
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			printf("%-5d",vis[i][j]);
		printf("\n");
	}
	return 0;
}
