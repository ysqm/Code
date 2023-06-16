# include <cmath>
# include <cstdio>
# include <cstring>
# include <cstdlib>
# include <iostream>
# include <algorithm>
using namespace std;
void DFS(int x,int y);
typedef struct{int x,y;} point;
bool flag;
short book[110][110];int sum=1,w,h,nx,ny;
char MAP[110][110];
point Exit,Entry,NEXT[5]={{0,0},{0,1},{-1,0},{1,0},{-1,0}};
int main(){
	while(cin>>w>>h,w!=0,h!=0){
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin>>MAP[i][j];
			if(MAP[i][j]=='@'){ny=i;nx=j;book[nx][ny]=1;}
		}
	}
	DFS(nx,ny);
	cout<<sum<<endl;	
	}
	return 0;
}
void DFS(int x,int y){
	for(int i=1;i<=4;i++){
		int lx=x+NEXT[i].x,ly=y+NEXT[i].y;
		if(lx<0||ly<0||lx>=w||ly>=h) continue;
		if(MAP[ly][lx]=='.'&&book[ly][lx]!=1){
			book[ly][lx]=1;sum++;
			DFS(ly,lx);
			//book[x+NEXT[i].x][y+NEXT[i].y]=0;
		}
	}
}
