# include <map>
# include <cmath>
# include <cstdio>
# include <cstring>
# include <cstdlib>
# include <iostream>
# include <algorithm>
# include <ctime>
using namespace std;

inline int r()
{
	int f = 1,x = 0;char c = getchar();
	
	while(c < '0' || c > '9'){if(c == '-') f = -1;c = getchar();}
	
	while(c >= '0' && c <= '9'){x = x * 10 + c - '0';c = getchar();}
	
	return x * f;
}

int mod,n,m,k,sud;

int main()
{
	freopen("12.txt","w",stdout);
	srand(time(NULL));
	mod = r();
	printf("%d %d 571373 \n",n = rand()%mod + 1,m = rand()%mod + 1);
	while(n--) printf("%d ",abs(rand()));
	while(m--){
		k = rand()%3 + 1;
		if(k != 3) printf("\n%d %d %d %d",k,sud = abs(rand()%mod) + 1,sud + abs(rand()%(mod - sud)) + 1,rand());
		else printf("\n 3 %d %d",sud = abs(rand()%mod) + 1,sud + abs(rand()%(mod - sud)) + 1);
	}
	return 0;
}

