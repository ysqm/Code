# include <cstdio>
int R,C,an[102][102],temp[102][102],ans=0;
bool book[102][102];
int ny[]={1,0,-1,0},nx[]={0,1,0,-1};
void read(int &a){
    a=0;int d=1;char c;
    while (c=getchar(),c<'0'||c>'9') if (c=='-') d=-1;a=a*10+c-48;
    while (c=getchar(),c>='0'&&c<='9') a=a*10+c-48;
    a*=d;
}
int maxq(int a,int b){
	return a>b?a:b; 
}
int dfs(int x,int y){
	if(temp[x][y]) return temp[x][y];
	int nowt=1;
	for(register int i=0;i<=3;i++){
		int dx=nx[i]+x,dy=ny[i]+y;
		if(dx>=1&&dx<=R&&dy>=1&&dy<=C&&an[x][y]<an[dx][dy]) {
			nowt=maxq(dfs(dx,dy)+1,nowt);
		}	
	}
	temp[x][y]=nowt;
	return nowt;
}
int main(){
	read(R);read(C);
	for(register int i=1;i<=R;i++)
		for(register int j=1;j<=C;j++)
			read(an[i][j]);
	int k;
	for(register int i=1;i<=R;i++)
		for(register int j=1;j<=C;j++){
			k=dfs(i,j);
			temp[i][j]=k;
			ans=maxq(ans,temp[i][j]);
		}
	printf("%d",ans);
	return 0;
}
