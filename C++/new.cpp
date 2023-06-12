# include <cstdio>

int Read()
{
    register int x = 0;char ch = getchar();
    
    while(ch < '0' || ch > '9')ch = getchar();
    
    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = getchar();}
    
    return x;
}

int main()
{
    int n = 0;
    n = Read();
    return 0;
}