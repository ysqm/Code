# include <cstdio>
# define LL long long

int lena,lenb,lenc,n;
LL  p=0,q=1,d,g,x;

LL Gcd(const LL x,const LL y){return x ? Gcd(y%x,x) : y;}

void Solve(const int n)
{
    lena = lenb = lenc = p = 0;q = 1;d = 0;
    for(int i = 0; i < n ; ++i)
    {
        p = p*(n-i)+n*q;
        q *= (n-i);
        g = Gcd(p,q);
        p /= g;
        q /= g;
        d += p/q;
        p %= q;
    }
    if(p == 0) printf("%lld\n",d);
    else
    {
        x = d;
        while(x){++lenc;x/=10;}
		++lenc;
        for(int i = 1; i <= lenc ; ++i) printf(" ");
        printf("%lld\n",p);
        if(d) printf("%lld ",d);
        x = p;
        while(x){++lena;x/=10;}
        x = q;
        while(x){++lenb;x/=10;}
        if(lenb > lena) lena = lenb;
        for(int i = 1; i <= lena ; ++i) printf("-");
        printf("\n");
        for(int i = 1; i <= lenc ; ++i) printf(" ");
        printf("%lld\n",q);
    }
}

int main()
{
    while(scanf("%d",&n)!=EOF) Solve(n);
    return 0;
}
