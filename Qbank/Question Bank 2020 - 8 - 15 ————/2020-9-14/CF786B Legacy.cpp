# include <queue>
# include <cstdio> 
# define reg register
# define N 500000
# define INF 0x3f3f3f3f3f3f3f3f
# define Ls(K) (K<<1)
# define Rs(K) (K<<1|1)
# define Gc getchar()//(SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
char BB[1<<15],*SS=BB,*TT=BB;
inline int Read()
{
    register int x = 0;char ch = Gc;

    while(ch < '0' || ch > '9')ch = Gc;

    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = Gc;}

    return x;
}

struct edge
{
    int Next,to,wi;

    edge(const int Next_=0,const int To_=0,const int wi_=0):Next(Next_),to(To_),wi(wi_){}
} e[(N<<3)+5];

int head[N+5],edge_tot = 1;

inline void add_edge(const int u,const int v,const int wi=0)
{
    e[++edge_tot] = edge(head[u],v,wi);

    head[u] = edge_tot;
}

struct Seg
{
    int Up,Down;
    Seg(const int Up_=0,const int Down_=0):Up(Up_),Down(Down_){}
} t[N+5];

long long dis[N+5];
int n,s,tot;

void Build(const int L,const int R,const int K)
{
    if(L == R) t[K] = Seg(L,L);
    else
    {
        t[K] = Seg(tot+1,tot+2);
        tot += 2;
        int mid = (L+R)>>1;
        Build(L,mid,Ls(K));
        Build(mid+1,R,Rs(K));
        add_edge(t[K].Down,t[Ls(K)].Down);
        add_edge(t[K].Down,t[Rs(K)].Down);
        add_edge(t[Ls(K)].Up,t[K].Up);
        add_edge(t[Rs(K)].Up,t[K].Up);
    }
}

void Modify(const int AL,const int AR,const int x,const int op,const int L,const int R,const int K)
{
    if(AL <= L && R <= AR)
    {
        if(op == 1) add_edge(x,t[K].Down);
        else if(op == 2) add_edge(t[K].Up,x);
        //printf("op = %d L = %d R = %d x = %d \n",op,L,R,x);
    }
    else
    {
        int mid = (L+R)>>1;
        if(AL <= mid) Modify(AL,AR,x,op,L,mid,Ls(K));
        if(AR > mid) Modify(AL,AR,x,op,mid+1,R,Rs(K));
    }
}

void Input()
{
    n = Read();
    tot = n;
    register int v,l,r,w,opt,q = Read();s = Read();
    Build(1,n,1);
    while(q--)
    {
        opt = Read();
        if(opt == 1)
        {   
            l = Read();r = Read();
            add_edge(l,r,Read());
            //printf("edge case %d,opt %d:%d %d %d\n",q,opt,l,r,e[edge_tot].wi);
        }
        else if(opt == 2)
        {
            v = Read();l = Read();r = Read();++tot;
            add_edge(v,tot,Read());
            //printf("edge case %d,opt %d:%d %d %d %d\n",q,opt,v,l,r,e[edge_tot].wi);
            Modify(l,r,tot,1,1,n,1);
        }
        else if(opt == 3)
        {
            v = Read();l = Read();r = Read();++tot;
            add_edge(tot,v,Read());
            //printf("edge case %d,opt %d:%d %d %d %d\n",q,opt,v,l,r,e[edge_tot].wi);
            Modify(l,r,tot,2,1,n,1);
        }
    }
}

bool inq[N+5];

void Solve()
{
    std::queue<int> q;
    Input();
    while(q.size()) q.pop();
    for(int i = 1; i <= tot; ++i) dis[i] = INF;
    q.push(s);inq[s] = 1;dis[s] = 0;
    while(q.size())
    {
        int u = q.front();q.pop();inq[u] = 0;
        for(int i = head[u]; i ; i = e[i].Next)
            if(dis[e[i].to] > dis[u]+e[i].wi)
            {
                dis[e[i].to] = dis[u]+e[i].wi;
                if(!inq[e[i].to]){inq[e[i].to] = 1;q.push(e[i].to);}
            }
    }
    /*for(int i = 1; i <= tot ; ++i)
    {
        printf("case%d:",i);
        for(int j = head[i]; j ; j = e[j].Next) printf("%d ",e[j].to);
        puts("");
    }*/
        
    for(int i = 1; i <= n ; ++i) printf("%lld ",((dis[i] == INF) ? -1 : dis[i]));
}

int main()
{
    //freopen("ysqm.in","r",stdin);
    Solve();
    return 0;
}

