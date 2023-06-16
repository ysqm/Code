#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int> > q;
int main(){
	int n,a,b;
	long long ans=0;
	scanf("%d",&n);
	for(register int i=0;i<n;i++){
		scanf("%d",&a);q.push(a);
	}n--;
	while(n--){
		a=q.top();q.pop();b=q.top();q.pop();
		q.push(a+b);
		/*printf("ans=%lld a=%d b=%d\n",ans,a,b);
		system("pause");*/
		ans+=a+b;
	}
	printf("%lld",ans);
	return 0;
} 
