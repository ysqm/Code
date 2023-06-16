# include <iostream>
# include <cmath>
using namespace std;
int gcd(int y,int x){
    if(x==0)    {return y;}
    return gcd(x,y%x);
}
int main(){
	cin.sync_with_stdio(false);
	int a,b,n,d,sum=0;
	cin>>b>>a;d=a*b;n=sqrt(d)+1;
	for(int i=1;i<n;i++){
		if(d%i==0&&gcd(d/i,i)==b) {
			sum++;
			//cout<<i<<" "<<d/i<<endl;
		}
	}
	cout<<sum*2;
	return 0;
} 
