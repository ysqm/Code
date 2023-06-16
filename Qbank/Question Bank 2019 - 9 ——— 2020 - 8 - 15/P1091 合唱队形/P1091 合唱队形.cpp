# include <iostream>
using namespace std;
int a[200],b[200],c[200],n,ans;
int main(){
	cin.sync_with_stdio(false);
	cin>>n;n++;
	for(int i=1;i<n;i++)
		cin>>a[i];
	for(int i=1;i<n;i++)
		for(int j=0;j<i;j++){
			if(a[i]>a[j])  b[i]=max(b[i],b[j]+1);
		}
	for(int i=n-1;i>0;i--)
		for(int j=n;j>i;j--){
			if(a[i]>a[j])  c[i]=max(c[i],c[j]+1);
		}
	for(int i=1;i<n;i++) ans=max(b[i]+c[i]-1,ans);
	cout<<n-ans;
	return 0;
} 
