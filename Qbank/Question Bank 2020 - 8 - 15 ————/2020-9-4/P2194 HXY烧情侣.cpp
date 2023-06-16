# include <cstdio>
# include <queue>
# define reg register
# define N 100000
# define M 300000
# define Gc /*getchar()//*/(SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
char BB[1<<15],*SS=BB,*TT=BB;
inline int Read()
{
    register int x = 0;char ch = Gc;

    while(ch < '0' || ch > '9')ch = Gc;

    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = Gc;}

    return x;
}

class STACK
{
    static const int MAX_STACK_SIZE = 1e5;
    private:
            int S_T_A_C_K[MAX_STACK_SIZE+5],top_;
    public:
            STACK(){top_=-1;}
            ~STACK(){}
            
            inline int Push(const int Val){S_T_A_C_K[++top_]=Val;}
            inline int Size(){return top_+1;}
            inline bool Empty(){return top_==-1;}
            inline bool reset(){top_ = -1;}
            inline int Get(){return S_T_A_C_K[top_--];}
            inline int Top(){return S_T_A_C_K[top_];}
            inline int Pop(){--top_;}
};

struct edge
{
    int Next,to;

    edge(const int Next_=0,const int To_=0):Next(Next_),to(To_){}
} e[M+5];

int head[N+5],edge_tot = 1,P[N+5],cnt,Neww[N+5];

inline int Min(const int x,const int y){return x < y ? x : y;}

bool ins[N+5];
STACK s;
int dfn[N+5],t,color[N+5],colornum,low[N+5],num[N+5];

inline void add_edge(const int v,const int u)
{
    e[++edge_tot] = edge(head[u],v);
    head[u] = edge_tot;
}

void Gabow(const int u)
{
    low[u] = dfn[u] = ++t;
    s.Push(u);ins[u] = true;
    int v;

    for(reg int i = head[u]; i ; i = e[i].Next)
        if(dfn[v = e[i].to] == 0) {Gabow(v);low[u] = Min(low[u],low[v]);}
        else if(ins[v]) low[u] = Min(low[u],dfn[v]);

    if(dfn[u] == low[u])
    {
        int p;
        Neww[++colornum] = 0x3f3f3f3f;
        do
        {
            p = s.Get();
            ins[p] = false;
            color[p] = colornum;
            if(Neww[colornum] > P[p]) {Neww[colornum] = P[p];num[colornum] = 1;}
            else if(Neww[colornum] == P[p]) ++num[colornum];
        }while (p != u);
        
    }
}

long long sum = 1,ans;
int n,m;

int main()
{
    n = Read();

    for(reg int i = 1; i <= n ; ++i) P[i] = Read();

    m = Read();

    for(reg int i = 1; i <= m ; ++i) add_edge(Read(),Read());

    for(reg int i = 1; i <= n ; ++i) if(dfn[i] == 0) Gabow(i);

    for(reg int i = 1; i <= colornum ; ++i)
    {
        sum = sum*num[i]%1000000007;
        ans = ans+Neww[i];
    }

    printf("%lld %lld",ans,sum);

    return 0;
}
