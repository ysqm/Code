# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define sqrt std::sqrt
# define reg register
# define N 100000

typedef long long LL;

template<class T>
inline T Read()
{
    register T x = 0;char ch = getchar();

    while(ch < '0' || ch > '9')ch = getchar();

    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = getchar();}

    return x;
}

struct node
{
    LL Max_Num,Sum;
    int L,R;

    node(const int L_=0,const int R_=0,const LL Max_Num_=0,const LL Sum_=0):L(L_),R(R_),Max_Num(Max_Num_),Sum(Sum_){}
};

node Seg[(N<<2)+5];
LL base[N+5];

//template<class T>
inline LL Max(const LL a,const LL b){return a < b ? b : a;}

inline node Merge(const node& ls,const node& rs){return node(ls.L,rs.R,Max(ls.Max_Num,rs.Max_Num),ls.Sum+rs.Sum);}
inline node merge(const node ls,const node rs){return node(ls.L,rs.R,Max(ls.Max_Num,rs.Max_Num),ls.Sum+rs.Sum);}

# define Ls(K) (K<<1)
# define Rs(K) (K<<1|1)

void Build(const int K,const int L,const int R)
{
    if(L == R) Seg[K] = node(L,R,base[L],base[L]);

    else
    {
        int mid = (L+R)>>1;
        Build(Ls(K),L,mid);
        Build(Rs(K),mid+1,R);
        Seg[K] = Merge(Seg[Ls(K)],Seg[Rs(K)]);
    }
}

node Query(const int K,const int AL,const int AR)
{
    if(AL <= Seg[K].L && AR >= Seg[K].R) return Seg[K];
    else
    {
        int mid = Seg[Ls(K)].R;
        if(AR <= mid) return Query(Ls(K),AL,AR);
        else if(AL > mid) return Query(Rs(K),AL,AR);
        else return Merge(Query(Ls(K),AL,AR),Query(Rs(K),AL,AR));
    }
}

void Modify(const int K,const int AL,const int AR)
{
    if(AL <= Seg[K].L && AR >= Seg[K].R && Seg[K].L == Seg[K].R)
    {
        LL dx = sqrt(Seg[K].Max_Num);
        Seg[K] = node(Seg[K].L,Seg[K].R,dx,dx);
    }
    else
    {
        int mid = Seg[Ls(K)].R;
        if(mid >= AL && Seg[Ls(K)].Max_Num != 1) Modify(Ls(K),AL,AR);
        if(mid < AR && Seg[Rs(K)].Max_Num != 1) Modify(Rs(K),AL,AR);
        Seg[K] = Merge(Seg[Ls(K)],Seg[Rs(K)]);
    }
}

# undef Ls
# undef Rs


int main()
{
    register int n = Read<int>();

    for (register int i = 1; i <= n; ++i) base[i] = Read<LL>();
    
    Build(1,1,n);
    register int m = Read<int>(),pos,l,r;

    while(m--)
    {
        pos = Read<int>();l = Read<int>();r = Read<int>();
        l <= r || (l^=r^=l^=r);
        if(pos) printf("%lld\n",Query(1,l,r).Sum);
        else Modify(1,l,r);
    }

    return 0;
}
