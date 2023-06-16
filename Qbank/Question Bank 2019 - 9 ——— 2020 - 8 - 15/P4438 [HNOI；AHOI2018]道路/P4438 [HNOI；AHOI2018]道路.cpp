# include <cstdio>
# include <cstring>
# include <cmath>
# define reg register
# define LL long long
using namespace std;

inline int Read()
{
	int x = 0;char c = getchar();
	
	while(c < '0' || c > '9') c = getchar();
	
	while(c >= '0' && c <= '9'){x = (x << 3) + (x << 1) +c - 48;c = getchar();}
	
	return x;
}

int main()
{
	reg int L = 1,R = 2000000000; 
	
	reg int n = Read()-1;
	
	while(L < R)
	{
		reg LL mid = (L + R) >> 1;
		
		if((LL)(mid * log10(mid * 1.0)) >= n) R = mid;
		else  L = mid + 1;
	} 
	
	printf("%d\n",R);
	
	return 0;	
}
