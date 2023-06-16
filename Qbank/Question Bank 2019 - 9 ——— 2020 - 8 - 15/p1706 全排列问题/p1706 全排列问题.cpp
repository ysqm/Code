# include <cmath>
# include <cstdio>
# include <cstring>
# include <cstdlib>
# include <iostream>
# include <algorithm>
short book[]={1,1,1,1,1,1,1,1,1,1,1};
void DFS(int step);
using namespace std;
int ans[11],n;
int main(){
	scanf("%d",&n);
	DFS(1);
	return 0;
}
void DFS(int step){
	if(step>n){
		for(int i=1;i<=n;i++)
		printf("%5d",ans[i]);
	printf("\n");
	return;
	}
	for(int i=1;i<=n;i++){
		if(book[i]){
			book[i]=0;
			ans[step]=i;
			DFS(step+1);
			book[i]=1;
		}
	}
}
