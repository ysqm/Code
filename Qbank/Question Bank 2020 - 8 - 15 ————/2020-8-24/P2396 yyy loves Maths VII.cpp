# pragma GCC optimize(2)
# pragma GCC optimize(3)
# pragma GCC optimize("Ofast")
# pragma GCC optimize("inline")
# pragma GCC optimize("-fgcse")
# pragma GCC optimize("-fgcse-lm")
# pragma GCC optimize("-fipa-sra")
# pragma GCC optimize("-ftree-pre")
# pragma GCC optimize("-ftree-vrp")
# pragma GCC optimize("-fpeephole2")
# pragma GCC optimize("-ffast-math")
# pragma GCC optimize("-fsched-spec")
# pragma GCC optimize("unroll-loops")
# pragma GCC optimize("-falign-jumps")
# pragma GCC optimize("-falign-loops")
# pragma GCC optimize("-falign-labels")
# pragma GCC optimize("-fdevirtualize")
# pragma GCC optimize("-fcaller-saves")
# pragma GCC optimize("-fcrossjumping")
# pragma GCC optimize("-fthread-jumps")
# pragma GCC optimize("-funroll-loops")
# pragma GCC optimize("-fwhole-program")
# pragma GCC optimize("-freorder-blocks")
# pragma GCC optimize("-fschedule-insns")
# pragma GCC optimize("inline-functions")
# pragma GCC optimize("-ftree-tail-merge")
# pragma GCC optimize("-fschedule-insns2")
# pragma GCC optimize("-fstrict-aliasing")
# pragma GCC optimize("-fstrict-overflow")
# pragma GCC optimize("-falign-functions")
# pragma GCC optimize("-fcse-skip-blocks")
# pragma GCC optimize("-fcse-follow-jumps")
# pragma GCC optimize("-fsched-interblock")
# pragma GCC optimize("-fpartial-inlining")
# pragma GCC optimize("no-stack-protector")
# pragma GCC optimize("-freorder-functions")
# pragma GCC optimize("-findirect-inlining")
# pragma GCC optimize("-fhoist-adjacent-loads")
# pragma GCC optimize("-frerun-cse-after-loop")
# pragma GCC optimize("inline-small-functions")
# pragma GCC optimize("-finline-small-functions")
# pragma GCC optimize("-ftree-switch-conversion")
# pragma GCC optimize("-foptimize-sibling-calls")
# pragma GCC optimize("-fexpensive-optimizations")
# pragma GCC optimize("-funsafe-loop-optimizations")
# pragma GCC optimize("inline-functions-called-once")
# pragma GCC optimize("-fdelete-null-pointer-checks")
# include <cstdio>
# define lowbit(x) ((x)&(~x+1))
# define Gc (SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
char BB[1<<15],*SS=BB,*TT=BB;
inline int Read()
{
    register int x = 0;char ch = Gc;

    while(ch < '0' || ch > '9')ch = Gc;

    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = Gc;}

    return x;
}

const int N = 1<<24,mod = 1e9+7;

inline void Mod(int& fd,const int x){((fd+=x)>=mod && (fd-=mod));}

int f[N+5],dis[N+5],n,a=-1,b=-1,m,Max_Status;

int main()
{
    //# ifdef LOCAL
    freopen("1.in","r",stdin);
    //# endif
    
    //# elif

    Max_Status = (1<<(n=Read()))-1;

    for(register int i = 0; i < n ; ++i) dis[1<<i] = Read();

    m = Read();f[0] = 1;

    (((m == 2) && ((a = Read()) && (b = Read())))) || ((m == 1) && (a = Read()));

    for(register int i = 1,k,j; i <= Max_Status ; ++i)
    {
        j = lowbit(i);k = i;
        dis[i] = dis[i^j]+dis[j];
        if(dis[i] != a && dis[i] != b)
        {
            while(k)
            {
                j = lowbit(k);
                Mod(f[i],f[i^j]);
                k ^= j;
            }
        }
    }

    printf("%d",f[Max_Status]);

    return 0;
}
