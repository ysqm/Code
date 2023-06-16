# include <cstdio>
# include <algorithm>
# include <cmath>
# define reg register
using namespace std;

int main()
{
	freopen("1.txt","w",stdout);
	int nn = sqrt(sqrt(100000)) + 1;
	printf("{");
	for(reg int i = 1;i <= nn; ++i)
		printf("%d,",i * i * i * i);
	printf("}");
	return 0;
}
