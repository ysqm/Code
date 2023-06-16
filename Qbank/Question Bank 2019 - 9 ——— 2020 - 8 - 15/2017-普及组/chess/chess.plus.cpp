# include <cstdio>
# include <algorithm>
# include <cstring>
using namespace std;
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
int m,n,a[110][110],f[110][110];
bool book[110][110];
inline int re(){
    int x=0,f=1;char c=getchar();
    while(c>'9'||c<'0') {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') {x=x*10+c-'0'; c=getchar();}
    return x*f;
}
inline void fuckout(int x){
    if(x>=10){
        fuckout(x/10);
    }
    putchar(x%10+'0');
}
void dfs(int x,int y,int s,bool c){
	if(x<1||y<1||x>m||y>m) return;
	if(s>=f[x][y]) return;
	f[x][y]=s; //更新到达点的最小值 
	/*printf("x=%d y=%d 金币=%d a[%d][%d]=%d\n",x,y,s,x,y,c);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i!=x||j!=y) printf("%d ",a[i][j]);
			else printf("H ");
		}
		printf("\n");
	} 
	printf("\n\n");
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++)
			if(f[i][j]!=2139062143)printf("%2d ",f[i][j]);
			else printf("inf");
		printf("\n");
	} 
	system("pause");*/
	int nx,ny;
	for(int i=0;i<4;i++){
		nx=x+dx[i];ny=y+dy[i];
        if(a[nx][ny])
        {
            if(a[nx][ny]==a[x][y])dfs(nx, ny, s, false);
            else dfs(nx,ny,s+1,false);
        }   else
        if(!c)
        {
            a[nx][ny]=a[x][y];
            dfs(nx,ny,s+2,true);
            a[nx][ny] =0;
        }
	}
} 
int main(){
	memset(f, 0x7f, sizeof(f));
	m=re();n=re();
	for(int i=0,x,y,c;i<n;i++){
		x=re();y=re();c=re();
		a[x][y]=++c;
	}
	book[1][1]=1;
	dfs(1,1,0,false);
	if(f[m][m]!=2139062143) fuckout(f[m][m]);
	else printf("-1");
	return 0;
}
