# include <string>
# include <iostream>
# include <cstring>
# include <cstdio>
# include <algorithm>
# include <queue>
using namespace std;
queue <char> q;
char ans[105];int p1,p2,p3,i=1,l,r,t,j,p,ane;
int main(){
	//cin.sync_with_stdio(false);
	scanf("%d%d%d %s",&p1,&p2,&p3,ans);
	//freopen("1.txt","w",stdout);
	q.push(ans[0]);
	while(ans[i]){
		t=ans[i];l=ans[i-1];r=ans[i+1];
		if(t=='-'&&r>l&&(l>='0'&&r<='9'||l>='a'&&r<='z')){
			for(p3==1?j=l+1:j=r-1; p3==1?j<r:j>l; p3==1?j++:j--){
				p=j;
				if(p1==2) p=(p>='a')?p-32:p;
				else if(p1==3) p='*';
				for(int k=0;k<p2;k++)
					q.push(p);
			}
		}
		else q.push(ans[i]);
		i++;
	}
	while(q.size()){
		printf("%c",q.front());
		q.pop();
	}
	return 0;
}
