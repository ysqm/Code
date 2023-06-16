# include <cstdio>
# include <iostream>
# include <algorithm>
# include <queue>
using namespace std;
int N,R,Q,j=1,n;
typedef struct{int si,wi,i;} player;
player an[200030],win[200025],lost[200025];
bool comp(const player x,const player y){
	if(x.si!=y.si) return x.si>y.si;
	else return x.i<y.i;
}
bool max1(player a,player b){
	if(a.si!=b.si){
		if(a.si>b.si) return true;
		else return false;
	}
	else {
		if(a.i<b.i) return true;
		else return false;
	}
}//fuck merge ,in order to write a more faster marge whose times is O(n),i waste 3 hours!!!fuck!!!fuck!!!
int main(){
	cin.sync_with_stdio(false);
	cin>>N>>R>>Q;n=N*2;
	for(int i=1;i<=n;i++)
		cin>>an[i].si;
	for(int i=1;i<=n;i++){
		cin>>an[i].wi;an[i].i=i;
	}sort(an+1,an+n+1,comp);
	while(R>0){
		for(int i=1;i<=n;i++){
			an[i].wi>an[i+1].wi?an[i].si++:an[i+1].si++;//fuck你妈，一个i+1让我查了半个小时 
			an[i].wi>an[i+1].wi?(win[(i+1)/2]=an[i++],lost[(i+1)/2]=an[i]):(lost[(i+1)/2]=an[i++],win[(i+1)/2]=an[i]);
		}
		merge(lost+1, lost+N+1, win+1, win+N+1,an+1,comp);
		R--;
	}
	cout<<an[Q].i;
	return 0;
} 
//if(an[i].wi>an[i+1].wi){
//			 win[(i+1)/2]=an[i++];lost[(i+1)/2]=an[i]; 
//			} 
//			else{
//				lost[(i+1)/2]=an[i++];win[(i+1)/2]=an[i];
//			}
