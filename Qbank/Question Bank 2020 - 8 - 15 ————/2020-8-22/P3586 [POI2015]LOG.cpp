# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define reg //register
# define N 1000000
# define LL long long
# define Ls(K) (K<<1)
# define Rs(K) (K<<1|1)

inline int Read()
{
    register int x = 0;char ch = getchar();

    while(ch < '0' || ch > '9')ch = getchar();

    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = getchar();}

    return x;
}

struct node
{
    LL sum;
    LL num;

    node(const LL x=0,const LL num_=0):sum(x),num(num_){}
    
} Seg[(N<<2)+5];

int n,m;

int cnt,top,C[N+5],S[N+5],opt[N+5],base[N+5],idf[N+5];

void Insert(const int x,const int L,const int R,const int K)
{
    if(L == R) Seg[K] = node(base[L] *(Seg[K].num+1),Seg[K].num+1);
    else
    {
        int mid = (L+R)>>1;
        if(x <= mid) Insert(x,L,mid,Ls(K));
        else Insert(x,mid+1,R,Rs(K));
        Seg[K] = node(Seg[Ls(K)].sum+Seg[Rs(K)].sum,Seg[Ls(K)].num+Seg[Rs(K)].num);
    }
}

void Delete(const int x,const int L,const int R,const int K)
{
    if(L == R) Seg[K] = node(base[L] *(Seg[K].num-1),Seg[K].num-1);
    else
    {
        int mid = (L+R)>>1;
        if(x <= mid) Delete(x,L,mid,Ls(K));
        else Delete(x,mid+1,R,Rs(K));
        Seg[K] = node(Seg[Ls(K)].sum+Seg[Rs(K)].sum,Seg[Ls(K)].num+Seg[Rs(K)].num);
    }
}

inline void Modify(const int k,const int x)
{
    if(idf[k]) Delete(idf[k],1,top,1);
    Insert(x,1,top,1);
    idf[k] = x;
}

LL Query_Num(const int x,const int L,const int R,const int K)
{
    if(x >= R) return Seg[K].num;
    else
    {
        int mid = (L+R)>>1;
        if(x <= mid) return Query_Num(x,L,mid,Ls(K));
        else return  Query_Num(x,L,mid,Ls(K)) + Query_Num(x,mid+1,R,Rs(K));
    }
}

LL Query_Sum(const int x,const int L,const int R,const int K)
{
    if(x >= R) return Seg[K].sum;
    else
    {
        int mid = (L+R)>>1;
        if(x <= mid) return Query_Sum(x,L,mid,Ls(K));
        else return  Query_Sum(x,L,mid,Ls(K)) + Query_Sum(x,mid+1,R,Rs(K));
    }
}

bool Query(const int c,const int s)
{
    LL Sum=0;
    LL dx = Seg[1].num;
    if(s-1) 
    {
        Sum = Query_Sum(s-1,1,top,1);
        dx -= Query_Num(s-1,1,top,1);
    }
    return Sum >= (c-dx) * base[s];
}

inline int LowerBound(const int x)
{
    reg int l = 1,r = top,mid;

    while(l < r)
    {
        mid = (l+r)>>1;

        if(base[mid] >= x) r = mid;
        else l = mid+1; 
    }

    return l;
}

int main()
{
    char input[3];

    n = Read();m = Read();

    for(reg int i = 1; i <= m ; ++i)
    {
        scanf("%s",input);
        opt[i] = (*input == 'U' ? 1 : 0);
        C[i] = Read();
        base[i] = S[i] = Read();
    }

    std::sort(base+1,base+m+1);base[0] = -1;

    for(reg int i = 1; i <= m ; ++i) (base[i] != base[i-1]) && (base[++top] = base[i]);

    for(reg int i = 1; i <= m ; ++i) S[i] = LowerBound(S[i]);

    for(reg int i = 1; i <= m ; ++i)
        if(opt[i]) Modify(C[i],S[i]);
        else if(Query(C[i],S[i])) puts("TAK");
        else puts("NIE");

    return 0;
}
