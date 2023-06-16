# include <cstdio>
# include <cmath>
# define reg register
# define N (1<<22)+1 

inline int Read()
{
    int x = 0;char ch = getchar();

    while(ch < '0' || ch > '9') ch = getchar();

    while(ch >= '0' && ch <= '9'){x = x * 10 + (ch ^ 48);ch = getchar();}

    return x;
}

inline void print(int x)
{
    char s[13];
    reg int top=0;

	if(x == 0) s[++top] = '0'; 

    while(x > 0)
    {
        s[++top] = x % 10 + '0';
        x /= 10; 
    }

    while(top) putchar(s[top--]);

    putchar(32);
}

int n,S[N + 42],top,ans[N + 42],a[N + 42];

int main()
{
	scanf("%d",&n);
	
	a[0] = 0x7f7f7f7f;
	
	if(n > 10000)
	{
		for(reg int i = 1; i <= n ; ++i)
		{
			a[i] = Read();
		
			while(a[i] > a[S[top]]) ans[S[top--]] = i;
		
			S[++top] = i;
		}
	
		for(reg int i = 1; i <= n ; ++i) print(ans[i]);
	}
	else 
	{
		for(reg int i = 1; i <= n ; ++i)
		{
			scanf("%d",&a[i]);
		
			while(a[i] > a[S[top]]) ans[S[top--]] = i;
		
			S[++top] = i;
		}
		
		for(reg int i = 1; i <= n ; ++i) printf("%d ",ans[i]);
	}
	return 0;
} 
