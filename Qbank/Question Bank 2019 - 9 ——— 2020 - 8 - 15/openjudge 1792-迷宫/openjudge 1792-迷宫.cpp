# include <cmath>
# include <cstdio>
# include <cstring>
# include <cstdlib>
# include <iostream>
# include <algorithm>
using namespace std;
void DFS(short x,short y);
typedef struct{short x,y;} point;
bool flag;
short book[110][110];
char MAP[110][110];
int ans[11],n,k;
point Exit,Entry,NEXT[5]={{0,0},{0,1},{-1,0},{1,0},{-1,0}};
int main(){
	cin.sync_with_stdio(false);
	cin>>k;
	while(k--){
		memset(book,0,sizeof(book));memset(MAP,0,sizeof(MAP));flag=false;
		cin>>n;
		for(int a=1;a<=n;a++){
			for(int b=1;b<=n;b++)
				cin>>MAP[a][b];
		}
		cin>>Entry.x>>Entry.y>>Exit.x>>Exit.y;Entry.x++;Entry.y++;Exit.x++;Exit.y++;
		if(MAP[Entry.x][Entry.y]=='#'||MAP[Exit.x][Exit.y]=='#'){cout<<"NO"<<endl; continue;}
		book[Entry.x][Entry.y]==1;
		DFS(Entry.x,Entry.y);
		if(flag)	cout<<"YES"<<endl;   else   cout<<"NO"<<endl;
	}
	return 0;
}
void DFS(short x,short y){
	if(flag==true) return;
	if(x==Exit.x&&y==Exit.y){
		flag=true;
		return;
	}
	for(int i=1;i<=4;i++){
		if(MAP[x+NEXT[i].x][y+NEXT[i].y]=='.'&&book[x+NEXT[i].x][y+NEXT[i].y]==0&&x+NEXT[i].x<=n&&x+NEXT[i].x>0&&y+NEXT[i].y<=n&&y+NEXT[i].y>0){
			book[x+NEXT[i].x][y+NEXT[i].y]=1;sum++;
			DFS(x+NEXT[i].x,y+NEXT[i].y);
			//book[x+NEXT[i].x][y+NEXT[i].y]=0;
		}
	}
}
