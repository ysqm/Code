# include <cstdio>
# include <cstring>
# include <cmath>
# define reg register
# define N 8000000
# define Pi 3.141592653589793
using namespace std;

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

struct Complex
{   
    double x,y;

    Complex(const double x_=0,const double y_=0):x(x_),y(y_){}

    inline Complex operator + (const Complex& b) const{return Complex(x+b.x,y+b.y);}
    inline Complex operator - (const Complex& b) const{return Complex(x-b.x,y-b.y);}
    inline Complex operator * (const Complex& b) const{return Complex(b.x*x-b.y*y,x*b.y+y*b.x);}
};

inline Complex Swap(Complex& a,Complex& b){Complex c = a;a = b;b = c;}

void FFT(Complex *A,const int *rev,const int Limit,const int Type)
{
	for(reg int i = 0; i < Limit ; ++i) if(rev[i] > i) Swap(A[i],A[rev[i]]);
	
	reg Complex Wn,W,x,y;
	
	for(reg int mid = 1; mid < Limit ; mid<<=1)
	{
		Wn = Complex(cos(Pi/mid),Type*sin(Pi/mid));
		
		for(reg int Len = mid<<1,i = 0; i < Limit ; i += Len)
		{
			W = Complex(1,0);
			
			for(reg int j = 0; j < mid ; ++j,W = W * Wn)
			{
				x = A[i|j];y = W*A[i|j|mid];
				
				A[i|j] = x+y;
				A[i|j|mid] = x-y; 
			}	
		}
	}
	if(Type == -1) for(reg int i = 0; i < Limit ; ++i) A[i] = Complex(A[i].x/Limit,A[i].y/Limit);
}

/*void IFFT(Complex *A,const int *rev,const int Limit)
{
	for(reg int i = 0; i < Limit ; ++i) if(rev[i] > i) Swap(A[i],A[rev[i]]);
	
	reg Complex Wn,W,x,y;
	
	for(reg int mid = 1; mid < Limit ; mid<<=1)
	{
		Wn = Complex(cos(Pi/mid),sin(Pi/mid));
		
		for(reg int Len = mid<<1,i = 0; i < Limit ; i += Len)
		{
			W = Complex(1,0);
			
			for(reg int j = 0; j < mid ; ++j,W = W * Wn)
			{
				x = A[i|j];y = W*A[i|j|mid];
				
				A[i|j] = x+y;
				A[i|j|mid] = x-y; 
			}	
		}
	}
	
	for(reg int i = 0; i < Limit ; ++i) A[i] = Complex(A[i].x/Limit,A[i].y/Limit);
}*/

inline void FFT_Pre(int *rev,const int Limit,const int L)
{
	for(reg int i = 0; i < Limit; ++i) rev[i] = (rev[i>>1]>>1) | ((i&1)<<(L-1)); 
}

Complex z[N + 42],Z[N + 42];
int n,m,r[N + 42],ans[N + 42];
char a[N + 42],b[N + 42];

int main()
{
	//freopen("P1919_1.in","r",stdin);
	//freopen("1.txt","w",stdout);
	
	scanf("%s%s",a,b);
	
	n = strlen(a) - 1;
	m = strlen(b) - 1;
	
	for(reg int i = n; ~i ; --i) z[i].x = a[n-i] - '0';
	
	for(reg int i = m; ~i ; --i) 
		Z[i].x = b[m-i] - '0';
	
	int l = 0,limit=1;
	
	while((n + m) >= limit) limit <<= 1,++l;
	
	FFT_Pre(r,limit,l);
	
	FFT(z,r,limit,1);
	FFT(Z,r,limit,1);
	
	for(reg int i = 0; i <= limit ; ++i) z[i] = z[i] * Z[i];
	
	FFT(z,r,limit,-1);
	
	for(reg int i = 0; i <= limit ; ++i)
	{
		ans[i] += (z[i].x+0.5);
		
		if(ans[i] > 9)
		{
			ans[i+1] += ans[i]/10;
			ans[i] %= 10;
			limit += (i == limit);
		}
	}
	
	reg int cur = limit;
	
	while(ans[cur] == 0) --cur;
	
	if(cur >= 0) while(~cur) putchar(ans[cur--]+'0');
	
	return 0;
}

 
