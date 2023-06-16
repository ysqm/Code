# include <iostream>
using namespace std;
int an[2][1001][1001],n,bigger;
int max1(int a,int b){
	if(b>a) return b;
	else return a;
}
void maxsum(int k){
	while(k>0){
		for(int i=0;i<k;i++){
			an[1][k-1][i]=an[0][k-1][i]+max1(an[1][k][i],an[1][k][i+1]);
		}
		k--;
	}
}
int main(){
	cin.sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<i+1;j++)
			cin>>an[0][i][j];
	maxsum(n);
	cout<<an[1][0][0];
	return 0; 
}
