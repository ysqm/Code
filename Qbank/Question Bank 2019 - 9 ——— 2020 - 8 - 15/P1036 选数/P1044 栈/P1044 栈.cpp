# include <cstdio>
# include <algorithm>
# define reg register
using namespace std;

inline void in(int& x)
{
	x = 0; char ch = getchar();int f = 1;
	
	while(ch < '0' || ch > '9'){if(ch == '-') f = -1;ch = getchar();}
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	x *= f;
}

int f[42][42],n;

inline int dfs(const int Queue,const int Stack)
{
	if(f[Queue][Stack]) return f[Queue][Stack];
	if(Queue == 0) return 1;
	if(Stack > 0) f[Queue][Stack] += dfs(Queue,Stack - 1);
	return f[Queue][Stack] += dfs(Queue - 1,Stack + 1);
}

int main()
{
	in(n);
	printf("%d\n",dfs(n,0));
	return 0;
}
