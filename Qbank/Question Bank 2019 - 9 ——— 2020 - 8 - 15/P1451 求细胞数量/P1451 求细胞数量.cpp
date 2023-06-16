# include <cstdio>
int t[101][101],a[101][101]£¬dx[4]={0,1,0,-1},dy[4]={1,0,-1,0},n,m,xd=0;

void dfs(int x,int y,int num){
	if(a[x][y]=='0'||t[x][y]) return;
	for(int i=0;i<4;i++){
		int nx=dx[i]+x,ny=dy[i]+y;
		if(nx>n||ny>m||nx<0||ny<0) continue;
		t[nx][ny]=num;
		dfs(nx,ny,num);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(register int i=0;i<n;i++)
		for(register int j=0;j<m;j++)
		scanf("%s",a[i]);
	for(register int i=0;i<n;i++)
		for(register int j=0;j<m;j++)
			if((a[i][j]!='0')&&(!t[i][j]))dfs(i,j,++xd);
	printf("%d",xd-1);
} 
