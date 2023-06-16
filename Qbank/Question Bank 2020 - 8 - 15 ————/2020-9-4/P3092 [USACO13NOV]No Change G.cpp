# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define N 100000
# define reg register
# define Gc getchar()//(SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
char BB[1<<15],*SS=BB,*TT=BB;
inline int Read()
{
    register int x = 0;char ch = Gc;

    while(ch < '0' || ch > '9')ch = Gc;

    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = Gc;}

    return x;
}

const int Max_Status = (1<<16)-1;
int n,k,a[N+5],c[17],s[N+5],Status,tot_money,f[Max_Status+1],g[Max_Status+1],ans=0x3f3f3f3f;

inline int check(const int x,const int idx)
{
    reg int l = idx+1,r = n,mid;

    while(l <= r)
    {
        mid = (l+r)>>1;
        if(s[mid]-s[idx] == x) return mid;
        else if(s[mid]-s[idx] < x) l = mid+1; 
        else r = mid-1;
    }
    return r;
}

int main()
{
    k = Read();n = Read();Status = (1<<k)-1;

    for(reg int i = 1; i <= k ; ++i) tot_money += (c[i] = Read());

    for(reg int i = 1; i <= n ; ++i) s[i] = s[i-1] + (a[i] = Read());

    for(reg int i = 0; i <= Status ; ++i)
        for(reg int j = 1; j <= k ; ++j)
            if(i&(1<<(j-1)))
            {
                int x = (i^(1<<(j-1))),sum = check(c[j],f[(i^(1<<(j-1)))]);
                if(sum > f[i]) {f[i] = sum;g[i] = g[x] + c[j];}
                if(f[i] == n) ans = (ans > g[i]) ? g[i] : ans;
            }
    printf("%d",(tot_money < ans) ? -1 : tot_money - ans);
    return 0;
}
