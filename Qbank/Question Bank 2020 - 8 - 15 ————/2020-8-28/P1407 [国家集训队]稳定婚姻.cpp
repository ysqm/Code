# include <map>
# include <cstdio>
# include <cstring>
# include <iostream>
# define N 40000
# define reg register
using std::map;
using std::string;
using std::cin;
using std::cout;

class STACK
{
    static const int MAX_STACK_SIZE = 1e6;
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
} e[N + 42];

int n,m,cnt;
string s1,s2;
map<string,int> mp;
int head[N + 42],edge_tot = 1,colornum,color[N+5];

inline void add_edge(const int u,const int v){e[++edge_tot] = edge(head[u],v);head[u] = edge_tot;}
inline int Min(const int x,const int y){return x < y ? x : y;}

bool ins[N+5];
STACK s;
int dfn[N+5],tarjant,low[N+5];

void Gabow(const int u)
{
    low[u] = dfn[u] = ++tarjant;
    s.Push(u);ins[u] = true;

    for(reg int i = head[u]; i ; i = e[i].Next)
        if(dfn[e[i].to] == 0) {Gabow(e[i].to);low[u] = Min(low[u],low[e[i].to]);}
        else if(ins[e[i].to]) low[u] = Min(low[u],dfn[e[i].to]);

    if(dfn[u] == low[u])
    {
        int p;++colornum;

        do
        {
            p = s.Get();
            ins[p] = false;
            color[p] = colornum;
        }while (p != u);
        
    }
}

int main()
{
    //std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;

    for(reg int i = 1; i <= n ; ++i)
    {
        cin>>s1>>s2;
        mp[s1] = ++cnt;mp[s2] = ++cnt;
        add_edge(cnt-1,cnt);
    }

    cin>>m;

    for(reg int i = 1; i <= m ; ++i)
    {
        cin>>s1>>s2;
        add_edge(mp[s2],mp[s1]);
    }

    for(reg int i = 1; i <= cnt ; ++i) if(dfn[i] == 0) Gabow(i);

    for(reg int i = 1; i <= cnt ; i+=2)
        if(color[i] != color[i+1]) puts("Safe");
		else puts("Unsafe");
    return 0;
}
