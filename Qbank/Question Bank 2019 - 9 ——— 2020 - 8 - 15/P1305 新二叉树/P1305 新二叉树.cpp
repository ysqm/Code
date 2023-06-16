# include <cstdio>
# include <cstring>
# include <iostream>
using namespace std;
int main(){
	cin.sync_with_stdio(false);
	int n;string s;
	cin>>n>>s; 
	for(int i=2;i<=n;i++){
		string s2;cin>>s2;
		int id=s.find(s2[0]);
		s.erase(id,1);
		s.insert(id,s2);
	}
	//scanf("%s",an);
	//build(Root,an);ane=Root;n--;printf("%c",Root->date);
	//scanf("")
	//printd(Root);
	for(int i=0;i<s.size();i++)
		if(s[i]!='*') printf("%c",s[i]);
	return 0;
}

