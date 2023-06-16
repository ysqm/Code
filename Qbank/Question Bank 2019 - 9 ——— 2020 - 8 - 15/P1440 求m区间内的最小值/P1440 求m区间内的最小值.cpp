# include <cstdio>
# include <algorithm>
# include <bitset>
# include <cstring>
# define reg register
# define N 2000000
using namespace std;

inline void in(int& x)
{
	x = 0; char ch = getchar();int f = 1;
	
	while(ch < '0' || ch > '9'){if(ch == '-') f = -1;ch = getchar();}
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	x *= f;
}

int n,m,a[N + 42],t[N + 42];

int main()
{
	in(n);in(m);
	
	in(a[1]);puts("0");t[1] = 1;
	
	for(reg int tail = 1,head = 1,i = 2;i <= n;++i){
		in(a[i]);
		while(i - t[head] > m) ++head; 
		printf("%d\n",a[t[head]]);
		while(head <= tail && a[t[tail]] >= a[i]) --tail;
		t[++tail] = i;
	}
	
	return 0;
}
