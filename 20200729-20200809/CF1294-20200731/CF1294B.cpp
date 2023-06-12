# include <algorithm>
# include <cstdio>
# include <cmath>
# define reg register
# define N 100000
# define Ls(i) (i<<1)
# define Rs(i) (i<<1|1)

inline int Read()
{
    int x = 0,f=1;char ch = getchar();

    while(ch < '0' || ch > '9') {if(ch == '-') f = -1;ch = getchar();}

    while(ch >= '0' && ch <= '9'){x = x * 10 + (ch ^ 48);ch = getchar();}

    return x*f;
}

struct Node
{
	int x,y;
	
	Node(const int Y=0,const int X=0):x(X),y(Y){}
	
	
} p[N + 42];

bool operator < (const Node& a, const Node& b)
{
	if(a.x != b.x) return a.x < b.x;
	else return a.y < b.y;
}

int n,m,T,s[N + 42];

int main()
{
	T = Read();
	
	while(T--)
	{
		n = Read();
		
		for(reg int i = 1; i <= n ; ++i) p[i] = Node(Read(),Read());
		
		std::sort(p+1,p+n+1);
		
		reg bool flag = 0;
		reg int nx = 0,ny = 0,top = 0;
		
		for(reg int i = 1; i <= n ; ++i)
		{
			for(reg int j = nx; j < p[i].x ; ++j) s[++top] = 'R';
			
			for(reg int j = ny; j < p[i].y ; ++j) s[++top] = 'U';
			
			if(p[i].y < ny)
			{
				flag = 1;
				break;
			}
			
			nx = p[i].x;
			ny = p[i].y;
		}
		
		if(flag) puts("NO");
		else
		{
			puts("YES");
			
			for(reg int i = 1; i <= top ; ++i) putchar(s[i]);
			
			puts("");
		}
	}
	
	return 0;
} 
