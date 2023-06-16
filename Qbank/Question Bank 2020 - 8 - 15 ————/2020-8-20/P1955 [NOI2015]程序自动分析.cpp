# include <cstdio>
# include <algorithm>
# define N 2000000
# define reg register

inline int Read()
{
	register int x = 0;char ch = getchar();

	while(ch < '0' || ch > '9')ch = getchar();

	while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = getchar();}

	return x;
}

int F[N + 5],Size[N + 5];

inline int Find(int x)
{
	int cur = x;
			
	while(*(F+cur) != cur) cur = *(F+cur);
		
	*(F+x) = cur;
		
	while(x != *(F+x)) *(F + (x = *(F+x))) = cur;
		
	return cur;
}

inline void Unity(int x,int y)
{
	x = Find(x);y = Find(y);
	if(*(Size + x) < *(Size + y)) *(Size + y) += *(Size + x),*(F + x) = y;
	else *(Size + x) += *(Size + y),*(F + y) = x; 
}

struct Question
{
    int Val,id;

	inline bool operator < (const Question& a)const {return Val < a.Val;}
	
} Q[N+5];

int cnt,opt[N + 5],f[N + 5],top;

bool check()
{
	int n = Read();cnt = 0;top = 0;
	
	for(reg int i = 1,x,y; i <= n ; ++i)
	{
		x = Read();y = Read();*(opt+i) = Read();
		Q[++cnt].id = i;
		Q[cnt].Val = x;
		Q[++cnt].id = i+n;
		Q[cnt].Val = y;
	}
	
	std::sort(Q+1,Q+cnt+1);
	
	for(reg int i = 1; i <=cnt ; ++i)
	{
		if(Q[i].Val != Q[i-1].Val) ++top;
		f[Q[i].id] = top;
	}
	
	for(register int i = 1; i <= top; ++i) {F[i] = i;Size[i] = 1;}
	
	for(reg int i = 1; i <= n ; ++i) if(opt[i]) Unity(f[i],f[i+n]);
	
	for(reg int i = 1; i <= n ; ++i) if(opt[i] == 0 && (Find(f[i]) == Find(f[i+n]))) return false; 
	
	return true;
}

int main()
{
	int T = Read();

	while(T--)
		if(check()) puts("YES");
		else puts("NO");

	return 0;
}