# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define reg register
# define LL long long

const LL x10[20] = {1,10,100,(LL)1e3,(LL)1e4,(LL)1e5,(LL)1e6,(LL)1e7,(LL)1e8,(LL)1e9,(LL)1e10,(LL)1e11,(LL)1e12,(LL)1e13,(LL)1e14,(LL)1e15,(LL)1e16,(LL)1e17,(LL)1e18};

int len=-1;
LL ans,temp;

inline int Calc(int x)
{
    int s[11],w=0,kth=0;
    while(x)
    {
        s[++len] = x%10;
        x /= 10;
    }
    ++len;
    for(reg int i = len-1; i  >= 0 ; --i)
    {
        w = w*10 + *(s+i);
        kth += w-x10[i]+1;
    }
    return kth;
}

int k,m,kth;

int main()
{
    scanf("%d%d",&k,&m);

    for(reg int i = 0 ; i < 10 ; ++i) if(k == x10[i] && m != i+1) return puts("0"),0;
    //for(reg int i = 0 ; i < 10 ; ++i) if(k == x10[i]) return printf("%d",&k),0;

    kth = Calc(k);
    if(kth > m) return puts("0"),0;
    else if(kth == m) return printf("%d\n",k),0;
    ans = x10[len];
    m -= kth;

    for(reg int i = 1;  ; ++i)
    {
        temp = k * x10[i] - x10[len+i-1];
        if(m > temp)
        {
            m -= temp;
            ans *= 10;
        }
        else break;
    }

    ans += m-1;

    printf("%lld\n",ans);

    return 0;
}