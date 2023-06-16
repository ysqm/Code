# include <cstdio>
# include <algorithm>
# define reg register
# define N 1000000
# define LL long long

inline int Read()
{
	int x = 0;char ch = getchar();
	
	while(ch < '0' || ch > '9')ch = getchar();
	
	while(ch >= '0' && ch <= '9'){x = x * 10 + (ch ^ 48);ch = getchar();}
	
	return x;
}

int n,a[N + 42],m;

inline int search(const int x)
{
	reg int l = 1,r = n,mid;
	
	while(l < r)
	{
		mid = (l + r) >> 1;
		
		if(a[mid] < x) l = mid+1;
		else r = mid;
	}
	
	if(a[l] == x) return l;
	else return -1;
}

int main()
{
	n = Read();m = Read();
	
	for(reg int i = 1; i <= n; ++i) a[i] = Read();
	
	for(reg int i = 1; i <= m; ++i) printf("%d ",search(Read()));
	
	return 0;
}

