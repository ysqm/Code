# include <cstdio>
# include <iostream>
# include <algorithm>
using namespace std;
typedef struct{char	stackd[260];int stackhead,now;bool flag;} zhan;
zhan ans;
int main(){
	ans.stackhead=1;ans.now=0;ans.flag=true;
	while(cin>>ans.stackd[ans.stackhead++]);
	while(ans.stackhead&&ans.flag){
		if(ans.stackd[ans.stackhead]==')') ans.now++;
		else if(ans.stackd[ans.stackhead]=='(') ans.now--;
		if(ans.now<0) ans.flag=false;ans.stackhead--;
	}
	if(ans.now==0) cout<<"YES";
	else cout<<"NO";
}
