# include <cstdio>
# include <cstring>
# include <algorithm>
# include <iostream> 
using namespace std; 
int n,stax,stay,Map[1010][1010];
char ad[1010];
int m,k=1,now=1,ans[100010],temp[1010][1010];
void dfs (int x,int y,int z,int ti){
	if(Map[x][y]!=z||temp[x][y]!=0||x<1||y<1||x>n||y>n) return;
	temp[x][y]=ti;ans[ti]++;
	dfs(x-1,y,1-z,ti);dfs(x+1,y,1-z,ti);dfs(x,y-1,1-z,ti);dfs(x,y+1,1-z,ti);
}
int main(){
	cin.sync_with_stdio(false);
	cin>>n>>m;
	cin.getline(ad,sizeof(ad));
	for(int i=1;i<=n;i++){
		cin.getline(ad,sizeof(ad));
		for(int j=0;j<=n;j++)
			Map[i][j+1]=ad[j]-'0';
	}
	for(int i=1;i<=m;i++){
		cin>>stax>>stay;
		if(temp[stax][stay]==0) dfs(stax,stay,Map[stax][stay],i);
		else ans[i]=ans[temp[stax][stay]];
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
