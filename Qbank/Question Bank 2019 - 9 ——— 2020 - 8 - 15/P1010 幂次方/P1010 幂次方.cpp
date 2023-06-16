# include <cstdio>
# include <algorithm>
# include <cmath>
# define N 500000
# define M 500000
# define R register
# define Q 30000
using namespace std;

int r()
{
	int f = 1,x = 0;;
	
	char c = getchar();
	
	while(c > '9' || c < '0'){
		c = getchar();
	}
	
	while(c >= '0' && c <= '9'){
		x = (x << 3) + (x << 1) + c - '0';
		
		c = getchar();
	}
	
	return x * f;
}

inline void work(int x)
{
	bool falg = false;
	int i = 16;
	while(i--) if((1<<i) & x) {
		if(falg) printf("+");
		if((1<<i) == 1) printf("2(0)");
		else if ((1<<i) == 2) printf("2");
		else{
			printf("2(");
			work(i);
			printf(")");
		}
		falg = true;
	}
}

int main()
{	
	int x;
	x = r();
	work(x);
	return 0;
} 
