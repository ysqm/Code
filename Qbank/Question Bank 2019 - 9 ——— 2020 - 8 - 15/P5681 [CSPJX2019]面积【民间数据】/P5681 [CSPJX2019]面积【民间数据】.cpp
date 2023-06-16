# include <cstdio>
# include <algorithm>
# include <cmath>
# include <cstring>
# define REG register
# define LL long long
# define N 100000 
using namespace std;

inline void in(LL& x)
{
	x = 0;char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();

	while(ch <= '9' && ch >= '0'){
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = getchar();
	}
} 

inline LL r()
{
	LL x = 0;char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();

	while(ch <= '9' && ch >= '0'){
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = getchar();
	}
	return x;
}
LL a,b,c;
int main()
{
	in(a);in(b);in(c);
	if(a * a > b * c) printf("Alice");
	else printf("Bob");
	return 0;
}
