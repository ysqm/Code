# include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	
	register int n,k,T;
	
	for(cin>>T>>n>>k; T ; --T,cin>>n>>k) cout<<((n & k) == k)<<endl;
	
}
