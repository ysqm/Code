# include <cstdio>
# include <iostream>
using namespace std;
char an[106][106],ans[101][101];int n,now=0;bool flag=true;
const char word[8]={'y','i','z','h','o','n','g'};
void dfs(int i,int j,int k);
const int xx[8]={0,0,1,-1,1,-1,1,-1},yy[8]={1,-1,1,-1,-1,1,0,0};
int main(){
	cin.sync_with_stdio(false);
	cin>>n;cin.getline(an[105],sizeof(an));
	for(int i=0;i<n;i++)
		cin.getline(an[i],sizeof(an));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			if(an[i][j]=='y'){
				for(int l=0;l<8;l++){
					dfs(i,j,l);
					if(flag){
						ans[i][j]='y';
						for(int m=1;m<8;m++){
							ans[i+xx[l]*m][j+yy[l]*m]=word[m];
						}
					}
					flag=true;now=0;
				}
			}
		}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(ans[i][j]==0) ans[i][j]='*';
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			printf("%c",ans[i][j]);
		printf("\n");
	}
	return 0;
} 
void dfs(int i,int j,int k){
	if(now==7) return;
	else if(i<0||j>=n||i>=n||j<0||flag==false) {
		flag=false;
		return;
	}
	else if(an[i][j]!=word[now])flag=false;
	else {
		now++;
		dfs(i+xx[k],j+yy[k],k);
	}
}
