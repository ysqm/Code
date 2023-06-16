# include <iostream>
# include <queue>
using namespace std;
typedef struct{int x,y,step;} dian;
char Map[50][50];int R,C,nx[]={1,-1,0,0},ny[]={0,0,1,-1};
queue <dian> s;int book[50][50];
int bfs();
int main(){
	cin.sync_with_stdio(false);
	cin>>R>>C;
	for(int i=1;i<=R;i++)
		for(int j=1;j<=C;j++)
			cin>>Map[i][j];
	dian startp;startp.step=1;startp.x=1;startp.y=1;
	s.push(startp);
	cout<<bfs();
	return 0;
} 
int bfs(){
	dian nowp,nexp;
	int x,y,nextx,nexty,step;
	while(s.size()>0){
		nowp=s.front();x=nowp.x;y=nowp.y;step=nowp.step;s.pop();
		if(x=C&&y==R) return step;
		for(int i=0;i<4;i++){
			nextx=x+nx[i];nexty=y+ny[i];
			if(nextx<1||nexty<1||nexty>R||nextx>C||Map[nexty][nextx]=='#'||book[nexty][nextx]==1) continue;
			nexp.x=nextx;nexp.y=nexty;nexp.step=step+1;
			s.push(nexp);
		}
	}
	return;
}
