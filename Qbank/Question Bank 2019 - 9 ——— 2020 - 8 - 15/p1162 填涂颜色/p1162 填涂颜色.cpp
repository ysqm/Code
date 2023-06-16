# include <iostream>
using namespace std;
typedef struct{short x,y;} dian;
typedef struct{short head=1,tail=2;dian q[910];} dui;
dui q;
short Map[35][35],n,book[35][35],nx[]={1,-1,0,0},ny[]={0,0,-1,1};
void bfs(short xx,short yy){
	if(book[xx][yy]==1||Map[xx][yy]==1) return;
	book[xx][yy]=1;
	q.q[q.head].x=xx;q.q[q.head].y=yy;
	dian nowp,nexp;
	short x,y,nextx,nexty;
	while(q.tail>q.head){
		nowp=q.q[q.head++];x=nowp.x;y=nowp.y;
		for(int i=0;i<4;i++){
			nextx=x+nx[i];nexty=y+ny[i];
			if(nextx<1||nexty<1||nexty>n||nextx>n||Map[nextx][nexty]==1||book[nextx][nexty]==1) continue;
			nexp.x=nextx;nexp.y=nexty;book[nextx][nexty]=1;
			q.q[q.tail++]=nexp;
		}
	}
}
int main(){
	cin.sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			cin>>Map[i][j];
		}
	for(short i=1;i<=n;i++) {
		bfs(i,n);q.head=1;q.tail=2;
		bfs(n,i);q.head=1;q.tail=2;
		bfs(1,i);q.head=1;q.tail=2;
		bfs(i,1);q.head=1;q.tail=2;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(book[i][j]==0&&Map[i][j]==0) cout<<"2 ";
			else cout<<Map[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
} 
