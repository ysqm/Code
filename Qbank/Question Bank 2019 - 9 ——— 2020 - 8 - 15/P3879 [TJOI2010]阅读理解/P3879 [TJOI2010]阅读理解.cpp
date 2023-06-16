# include <map>
# include <vector>
# include <cstring>
# include <iostream>
# define N 1000
# define reg register
using namespace std;

int m,n;
bool vis[100042];
string s;
map <string,vector<int> > T;

int main()
{
	ios::sync_with_stdio(false);
	
	cin>>n;
	
	for(reg int i = 1; i <= n; ++i){
		cin>>m;
		
		for(reg int j = 1; j <= m; ++j){
			cin>>s;
			T[s].push_back(i);
		}
		
	}
	
	cin>>m;
	
	for(reg int i = 1; i <= m; ++i){
		memset(vis,0,sizeof(vis));
		cin>>s;int t = T[s].size();
		for(reg int j = 0; j < t; ++j)
		if(!vis[T[s][j]]){
			cout<<T[s][j]<<" ";
			vis[T[s][j]] = 1;
		}
			
		cout<<"\n";
	}
	return 0;
}
