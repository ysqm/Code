# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define N 500000
# define LL long long
# define Gc (SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
char BB[1<<15],*SS=BB,*TT=BB;
template<class T>
inline T Read()
{
    register T x = 0;char ch = Gc;

    while(ch < '0' || ch > '9')ch = Gc;

    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = Gc;}

    return x;
}

int n,k,shot[N+5];
LL m[N+5],injure;

bool check(const LL p)
{
    int s = sqrt(p)+1,tot=0;
    LL i2=0,i1=0,i0=0,x=0;
    memset(shot,0,sizeof(shot));
    for(int i = n; i >= 1 ; --i)
    {
        if(i + s <= n && shot[i+s])
        {
            i2 -= (i+s)*(LL)(s+i)*shot[i+s];
            i1 -= (i+s)*shot[i+s];
            i0 -= shot[i+s];
        }
        injure = (p-i*(LL)i)*i0-i2+2*i1*i;
        if(m[i] >= injure)
        {
            shot[i] = (m[i]-injure)/p+1;
            tot += shot[i];
            i0 += shot[i];
            i1 += i*shot[i];
            i2 += i*(LL)i*shot[i];
        }
        if(tot > k) return false;
    }
    return true;
}

int main()
{
    n = Read<int>();k = Read<int>();
    for(int i = 1; i <= n ; ++i) m[i] = Read<LL>();
    LL L = 0,R = 1e11,mid;
    while(L<R)
    {
        mid = (L+R)>>1;
        if(check(mid)) R = mid;
        else L = mid+1;
    }
    printf("%lld",L);
    return 0;
}