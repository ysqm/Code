# include <cstdio>
# include <algorithm>
using namespace std;
const int maxn=2100000000;
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
int m,n,a[110][110],ans=maxn,c[110][110];
bool book[110][110];
inline int re()
{
    int x=0,f=1;char c=getchar();
    while(c>'9'||c<'0') {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') {x=x*10+c-'0'; c=getchar();}
    return x*f;
}
inline void fuckout(int x)
{
    if(x>=10){
        fuckout(x/10);
    }
    putchar(x%10+'0');
}
void dfs(int x,int y,int s){/*,int c*/
//x��y���꣬c��ɫ��s���ý�ң�flag�Ƿ�ʩչħ��
	/*printf("x=%d y=%d ���=%d flag=",x,y,s);
	if(a[x][y]==0) printf("true\n");
	else printf("false\n");
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
			printf("%d ",c[i][j]);
		printf("\n");
	} 
	printf("\n ans = %d\n",ans);
	system("pause");*/
	if(s>ans) return;
	if(x==m&&y==m){ans=s;return;}
	int nx,ny;bool flag=false;
	for(int i=0;i<4;i++){
		nx=x+dx[i];ny=y+dy[i];
		if(book[nx][ny]||nx<1||nx>m||ny<1||ny>m) continue;
		if(a[x][y]==0&&a[nx][ny]==0) continue;//=0��Խ����ʹ�ù�ħ�����޷����� 
		book[nx][ny]=true;//�ܹ�ȥ����Ϊ�ѷ��ʣ� 
		if(a[nx][ny]==0) {
			c[nx][ny]=a[x][y];
			dfs(nx,ny,s+2);
		}//=0,��û��ʹ�ù�ħ������ʹ��ħ������ 
		else if(a[nx][ny]==a[x][y]||a[nx][ny]==c[x][y]) dfs(nx,ny,s);//��ɫ��ֱͬ�ӹ�ȥ 
		else dfs(nx,ny,s+1); //�������Ľ�� 
		book[nx][ny]=false;
		c[nx][ny]=0;
	}
} 
int main(){
	//freopen("chess.in","r",stdin);
	//freopen("chess.out","w",stdout);
	m=re();n=re();
	for(int i=0,x,y,c;i<n;i++){
		x=re();y=re();c=re();
		a[x][y]=++c;
	}
	dfs(1,1,0);
	if(ans!=maxn) fuckout(ans);
	else printf("-1");
	return 0;
}
