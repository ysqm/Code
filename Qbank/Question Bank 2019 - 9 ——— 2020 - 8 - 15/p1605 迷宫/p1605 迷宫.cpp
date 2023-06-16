# include <iostream>
# include <algorithm>
using namespace std;
bool Map[7][7],temp[7][7];short n,m,t,sx,sy,fx,fy,a,b,sum=0,xx[]={0,0,1,-1},yy[]={1,-1,0,0};

void dfs(int x,int y){
	if(x==fx&&y==fy) {sum++;return;}
	for(int i=0;i<4;i++){
		int nx=x+xx[i],ny=y+yy[i];
		if(Map[nx][ny]&&temp[nx][ny]){
			temp[x][y]=false;
			dfs(nx,ny);
			temp[x][y]=true;
		}
	}
}
int main(){
	cin.sync_with_stdio(false);
	cin>>n>>m>>t>>sx>>sy>>fx>>fy;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){Map[i][j]=true;temp[i][j]=true;}
	temp[sx][sy]==false;
	for(int i=0;i<t;i++){
		cin>>a>>b;
		Map[a][b]=false;
	}
	dfs(sx,sy);
	cout<<sum;
	return 0;
} 


