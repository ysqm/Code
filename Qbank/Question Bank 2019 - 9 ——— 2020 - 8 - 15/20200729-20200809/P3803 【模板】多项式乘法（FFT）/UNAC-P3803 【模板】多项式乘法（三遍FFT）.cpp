# include <cstdio>
# include <cmath>
# include <algorithm>
# define reg register
# define N (1<<21)
using namespace std;

inline int Read()
{
	int x = 0;char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch >= '0' && ch <= '9'){x = x * 10 + (ch ^ 48);ch = getchar();}
	
	return x;
}

struct Complex
{	
	double x,y;
	
	Complex(const double x_=0,const double y_=0):x(x_),y(y_){}
	
	inline Complex operator + (const Complex& b) const{return Complex(x+b.x,y+b.y);}
	inline Complex operator - (const Complex& b) const{return Complex(x-b.x,y-b.y);}
	inline Complex operator * (const Complex& b) const{return Complex(b.x*x-b.y*y,x*b.y+y*b.x);}
};

const double Pi = acos(-1);

Complex a[N + 42],b[N + 42],eps[N + 42],ieps[N + 42];
int limit = 1,l,r[N + 42],an,bn;

template <class T>
inline T Swap(T& a,T& b){T c;c = a;a = b;b = c;}

void DFT(Complex *A,const int n)
{
	for(reg int i = 0; i < n ; ++i)
		if(i < r[i]) Swap(A[i],A[r[i]]);
		
	Complex W,x,y;
	
	for(reg int i = 1; i <= n ; i <<= 1)
	{
		for(reg int Len = i << 1,j = 0; j < n ; j += Len)
		{
			W = Complex(1,0);//积累次幂
			
			for(reg int k = 0; k < i ; ++k,W = W * eps[i])//求其傅里叶变换的蝴蝶变换 
			{
				x = A[j + k];y = W * A[j + i + k];
				
				A[j+k] = x + y;
				
				A[j+i+k] = x - y;
			} 
		}
	}		
}

void IDFT(Complex *A,const int n)
{
	for(reg int i = 0; i < n ; ++i)
		if(i < r[i]) Swap(A[i],A[r[i]]);
		
	Complex W,x,y;
	
	for(reg int i = 1; i <= n ; i <<= 1)
	{
		for(reg int Len = i << 1,j = 0; j < n ; j += Len)
		{
			W = Complex(1,0);
			
			for(reg int k = 0; k < i ; ++k,W = W * ieps[i])
			{
				x = A[j + k];y = W * A[j + i + k];
				
				A[j+k] = x + y;
				
				A[j+i+k] = x - y;
			} 
		}
	}		
}

inline void INIT()
{
	an = Read();bn = Read();
	
	for(reg int i = 0; i <= an ; ++i) a[i].x = Read();
	for(reg int i = 0; i <= bn ; ++i) b[i].x = Read();
	
	an += bn;
	
	while(an > limit) limit<<=1,++l;
	
	eps[0] = ieps[0] = Complex(1,0);
	
	for(reg int i = 1; i <= limit ; ++i)
	{
		eps[i] = Complex(cos((Pi)/i),sin((Pi)/i));
		ieps[i] = Complex(cos((Pi)/i),-sin((Pi)/i));
	}
}

int main()
{
	INIT();
	
	for(reg int i = 0; i <= limit ; ++i) r[i] = (r[i>>1]>>1) | ((i&1)<<(l-1));
	
	DFT(a,limit);
	DFT(b,limit);
	
	for(reg int i = 0; i <= limit ; ++i) a[i] = a[i] * b[i];
	
	IDFT(a,limit);
	
	for(reg int i = 0; i <= an ; ++i) printf("%d ",(int)(a[i].x/limit + 0.5));
	
	return 0;
}
