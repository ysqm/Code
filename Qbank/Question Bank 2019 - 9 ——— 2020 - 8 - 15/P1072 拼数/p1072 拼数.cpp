# include <cstdio>
# include <cstring>
# include <algorithm>
# include <iostream> 
using namespace std; 
string a[25];int n;
bool comp(string a,string b){
	return a+b>b+a;
}
int main(){
	cin.sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n,comp);
	for(int i=0;i<n;i++) cout<<a[i];
	return 0;
}
