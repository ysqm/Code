# include <cstdio>
# include <cstring>
# include <iostream>
# include <algorithm>
# include <vector> 
# define reg register
# define N 1000
# define TIME 40000
# define LL long long
using namespace std;

int n,m,s1,s2,nm;

int main()
{
	cin>>n>>m;
	
	s2 = ((1+n)*(1+m)*n*m)/4;
	
	nm = min(n,m);
	
	for(reg int i = 1; i <= nm; ++i) s1 += (n - i + 1) * (m - i + 1);
	
	cout<<s1<<' '<<s2-s1;
	
	return 0;
}
