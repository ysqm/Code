# include <queue>
# include <cstdio>
# include <cstring>
# include <algorithm>
# define reg register
# define N 500000
# define INF 0x3f3f3f3f 
# define Gc getchar()//*/(SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
char BB[1<<17],*SS=BB,*TT=BB;

inline int Read()
{
	register int x = 0,f = 1;register char ch = Gc;
	
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1;ch = Gc;}
	
	while(ch <= '9' && ch >= '0'){x = x*10 + (ch^48);ch = Gc;}
	
	return f < 0 ? (~x)+1 : x;
}

inline int Min(const int a,const int b){return a < b ? a : b;}

long long Heap[N + 42],Size;

std::priority_queue<int> q;

int main()
{
	long long ans = 0,x;
	int n;
	
	n = Read();
	
	for(int i = 1; i <= n ; ++i)
	{
		q.push(x = Read());
		if(x < q.top())
		{
			ans += q.top() - x;
			q.pop();
			q.push(x);
		}
	}
	
	printf("%lld\n",ans);
	
	return 0;
} 
/*
	9
	5 4 3 2 1 0 -1 -2 -3
	
*/
