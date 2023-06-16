# include <iostream>
# include <algorithm> 
using namespace std;
int n,queen[100],sum=0;bool q[100],r[100],l[100];
void dfs(int x);
int main(){
	cin>>n;
	dfs(1);
	cout<<sum;
	return 0;
}
void dfs(int x){
	if(x-1==n){sum++;
		if(sum<4){
			for(int i=1; i<n; i++)
            	cout<<queen[i]<<' ';
        	cout<<queen[n]<<endl;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!q[i]&&!r[x+i]&&!l[x+n-i]){
			queen[x]=i;
			q[i]=true;r[x+i]=true;l[x+n-i]=true;
			dfs(x+1);
			q[i]=false;r[x+i]=false;l[x+n-i]=false;
		}
	}
}
