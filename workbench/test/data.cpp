# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>

int main()
{
	//freopen("1.in","w",stdout); 
	srand(time(NULL)); 
    int n = 10,m = 1000,Need = rand()%n;
    printf("%d %d %d\n",n,m,Need);
    for(int i = 2; i <= n ; ++i) printf("%d %d %d %d\n",(rand()%(i-1)),i-1,101,rand()&1);
    for(int i = n; i <= m ; ++i) printf("%d %d %d %d\n",(rand()%(n-1)),(rand()%(n-1)),rand()%101,rand()&1);
    return 0;
}
