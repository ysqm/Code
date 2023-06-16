# include <cstdio>
# include <iostream>
# include <algorithm>
# define reg register
# define N 100000
# define double long double

int n;
double p,a[N + 42],b[N + 42],sum = 0; 

inline bool check(const double& x)
{
	double q = p * x;
	
	sum = 0;
	
	for(reg int i = 1 ; i <= n; ++i)
		if(a[i]*x <= b[i]) continue;
		else sum += (a[i]*x-b[i]);
		
	return sum <= q;
}

int main()
{
	std::cin>>n>>p;
	
	for(reg int i = 1; i <= n; ++i){std::cin>>a[i]>>b[i];sum += a[i];}
	
	if(sum <= p) std::cout<<-1.000000<<"\n";
	
	else
	{
		reg double L = 0,R = 1e10;
		while(R-L > 1e-6)
		{	
			double mid=(L+R)/2;
		
			if(check(mid)) L=mid;
			else R = mid;
		}
		
		std::cout<<L<<"\n";
	}
	
	return 0;
}

