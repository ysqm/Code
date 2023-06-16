# include <cstdio>
# include <queue>
# define N 100000
# define M 200000
# define R register
# define C const int
using namespace std;
inline void r(int &x)
{
	int f = 1;x = 0;
	char c = getchar();
	
	while(c < '0' || c > '9'){
		if(c == '-') f = -1;
		c = getchar();
	}
	
	while(c >= '0' && c <= '9'){
		x = x * 10 + c - '0';
		c = getchar();
	}
	
	x *= f;
}
int n,m;
int main()
{
	r(n);
	r(m);
} 
