# include <cstdio>
# include <algorithm>
# include <cstdlib>
# include <cstring>
# include <iostream>
# include <ctime> 
# include <cmath>
# define N 100000
# define R register
# define LL long long
inline void r(int &a);
int n,m;
const double ae = (sqrt(5) - 1) / 2;
int main()
{	
	freopen("1.txt","w",stdout);
	r(n);
	r(m);
	srand(time(NULL));
	printf("%d %d\n",n,m);
	for(R int i = 1;i <= m;i++)
		printf("%d %d\n",abs((int)((double)(rand() + 1)/ae - (int)(rand() + 1)/ae))%n+1,abs((int)((double)(rand())/ae+1)%n+1));	
	return 0;
}

inline void r(int &a)
{
	a = 0;
	int f = 1;
	char c = getchar();
	
	while(c < '0' || c > '9'){
		if(c == '-') f = -1;
		else f = 1;
		c = getchar();
	}
	
	while(c <= '9' && c >= '0'){
		a = (a << 3) + (a << 1) + c - '0';
		c = getchar();
	}
	a *= f;
}
