# include <cstdio>
# include <algorithm>
# include <bitset>
# include <cstring>
# define reg register
# define N 2000000
# define LL long long
using namespace std;

inline void in(int& x)
{
	x = 0; char ch = getchar();int f = 1;
	
	while(ch < '0' || ch > '9'){if(ch == '-') f = -1;ch = getchar();}
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	x *= f;
}

int n,k,t[N + 42],p[N + 42];

int main()
{
	in(n);in(k);
	
	reg int tail = 0,head = 1;
	
	for(reg int i = 1; i < k; ++i){
		in(p[i]);
		while(head <= tail && p[t[tail]] <= p[i]) --tail;
		t[++tail] = i;
	}
	
	for(reg int i = k;i <= n;++i){
		in(p[i]);
		while(i - t[head] >= k) ++head;
		while(head <= tail && p[t[tail]] <= p[i]) --tail;
		t[++tail] = i;
		printf("%d\n",p[t[head]]);
	}
	return 0;
}
