# include <cstdio>
# include <cmath>
# define reg register
# define N (1<<22)+1 
# define Pi 3.141592653589793

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

inline void Swap(Complex& a,Complex& b){Complex temp = a;a = b;b = temp;}

Complex f[N + 42];
int r[N + 42],n,m,l=-1,Limit = 1;

void DFT(Complex A[],const int limit)
{
    for(reg int i = 1; i <= limit ; ++i) if(i < r[i]) Swap(A[i],A[r[i]]);

    reg Complex x,y,W,Wn;

    for(reg int i = 1; i <= limit ; i <<= 1)
    {
        Wn = Complex(cos(Pi/i),sin(Pi/i));

        for(reg int Len = i<<1,j = 0; j <= limit ; j += Len)
        {
            W = Complex(1,0);
            for(reg int k = 0; k < i ; ++k,W = W * Wn)
            {
                x = A[j|k];y = W * A[j|i|k];//j,i一定是2的倍数 

                A[j|k] = x+y;
                A[j|k|i] = x-y;
            }
        }
    }
}

void IDFT(Complex A[],const int limit)
{
    for(reg int i = 1; i < limit ; ++i) if(i < r[i]) Swap(A[i],A[r[i]]);

    reg Complex x,y,W,Wn;

    for(reg int i = 1; i < limit ; i <<= 1)
    {
        Wn = Complex(cos(Pi/i),-sin(Pi/i));

        for(reg int Len = i<<1,j = 0; j < limit ; j += Len)
        {
            W = Complex(1,0);
            for(reg int k = 0; k < i ; ++k,W = W * Wn)
            {
                x = A[j|k];y = W * A[j|i|k];//j,i一定是2的倍数 

                A[j|k] = x+y;
                A[j|k|i] = x-y;
            }
        }
    }

    for(reg int i = 0 ; i < limit ; ++i) A[i] = Complex(A[i].x/Limit,A[i].y/Limit);
}

int main()
{
    n = Read();m = Read();

    for(reg int i = 0; i <= n ; ++i) f[i].x = Read();
    for(reg int i = 0; i <= m ; ++i) f[i].y = Read();

    if(m > n) n ^= m ^= n ^= m;

    while(n << 1 >= Limit) Limit <<= 1,++l;

    for(reg int i = 0; i < Limit ; ++i) r[i] = (r[i>>1]>>1)|((i&1)<<l);

    DFT(f,Limit);

    for(reg int i = 0; i < Limit ; ++i) 
        f[i] = f[i] * f[i];

    IDFT(f,Limit);

    for(reg int i = 0; i <= n+m ; ++i) print(((f[i].y))/2+0.5);

    return 0;
}
