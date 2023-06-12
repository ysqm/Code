# include <cstdio>
# include <cstring>
# include <cmath>
# include <algorithm>
# define reg register
# define N (1<<21)
# define Pi 3.141592653589793
using namespace std;

 int Read()
{
    int x = 0;char ch = getchar();

    while(ch < '0' || ch > '9') ch = getchar();

    while(ch >= '0' && ch <= '9'){x = x * 10 + (ch ^ 48);ch = getchar();}

    return x;
}

void print(int x)
{
	if(x > 9) print(x/10);
	putchar(x%10+'0');
}

struct Complex
{   
    double x,y;

    Complex(const double x_=0,const double y_=0):x(x_),y(y_){}

    inline Complex operator + (const Complex& b) const{return Complex(x+b.x,y+b.y);}
    inline Complex operator - (const Complex& b) const{return Complex(x-b.x,y-b.y);}
    inline Complex operator * (const Complex& b) const{return Complex(b.x*x-b.y*y,x*b.y+y*b.x);}
};

void FFT(Complex *A,const int Limit,const int Type);

Complex z[N + 42];
int n,m,r[N + 42];

int main()
{
	n = Read();m = Read();
	
	for(reg int i = 0 ; i <= n; ++i) z[i].x = Read();
	
	for(reg int i = 0 ; i <= m; ++i) z[i].y = Read();
	
	int limit=1,l=-1;
	
	if(m > n) m ^= n ^= m ^= n;

	while((n<<1) >= limit) limit <<= 1,++l;
	
	for(reg int i = 1; i <= limit; ++i) r[i] = (r[i>>1]>>1) | ((i&1)<<l); 
	
	FFT(z,limit,1);
	
	for(reg int i = 0; i <= limit ; ++i) z[i] = z[i] * z[i];
	
	FFT(z,limit,-1);
	
	for(reg int i = 0; i <= n+m; ++i)
	{
		int qwq = (z[i].y/2+0.5);
		print(qwq);
    	putchar(' ');
	}
	
	return 0;
}

void FFT(Complex *A,const int Limit,const int Type)
{
	for(reg int i = 1; i <= Limit ; ++i) if(r[i] > i) swap(A[i],A[r[i]]);
	
	reg Complex Wn,W,x,y;
	
	for(reg int mid = 1; mid < Limit ; mid<<=1)
	{
		reg int Len = mid<<1;
		
		Wn = Complex(cos(Pi/mid),Type*sin(Pi/mid));
		
		for(reg int i = 0; i < Limit ; i += Len)
		{
			W = Complex(1,0);
			
			for(reg int j = 0; j < mid ; ++j)
			{
				x = A[i|j];y = W*A[i|j|mid];
				
				A[i|j] = x+y;
				A[i|j|mid] = x-y;
				
				W = W * Wn;
			}	
		}
	}
	if(Type == -1) for(reg int i = 0; i <= Limit ; ++i)/*{A[i].x = A[i].x/Limit;*/A[i].y = A[i].y/Limit;//}
}

void FFT_Pre(int *rev,const int Limit,const int L)
{
	for(reg int i = 1; i <= Limit; ++i) rev[i] = (rev[i>>1]>>1) | ((i&1)<<L); 
}

