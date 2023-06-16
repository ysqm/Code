# P2747 [USACO5.4]周游加拿大Canada Tour

## 题目描述
你赢得了一场航空公司举办的比赛，奖品是一张加拿大环游机票。旅行在这家航空公司开放的最西边的城市开始，然后一直自西向东旅行，直到你到达最东边的城市，再由东向西返回，直到你回到开始的城市。除了旅行开始的城市之外，每个城市只能访问一次，因为开始的城市必定要被访问两次（在旅行的开始和结束）。

当然不允许使用其他公司的航线或者用其他的交通工具。

给出这个航空公司开放的城市的列表，和两两城市之间的直达航线列表。找出能够访问尽可能多的城市的路线，这条路线必须满足上述条件，也就是从列表中的第一个城市开始旅行，访问到列表中最后一个城市之后再返回第一个城市。

## 输入格式

第 $1$ 行: 航空公司开放的城市数 $N$ 和将要列出的直达航线的数量 $V$。$N$ 是一个不大于 $100$ 的正整数。$V$ 是任意的正整数。

第 $2\sim N\!+\!1$ 行: 每行包括一个航空公司开放的城市名称。城市名称按照自西向东排列。不会出现两个城市在同一条经线上的情况。每个城市的名称都 是一个字符串，最多 $15$ 字节，由拉丁字母表上的字母组成；城市名称中没有空格。

第 $N\!+\!2\sim N\!+\!2\!+\!V-1$ 行: 每行包括两个城市名称（由上面列表中的城市名称组成），用一个空格分开。这样就表示两个城市之间的直达双程航线。

## 输出格式
按照最佳路线访问的不同城市的数量 M。

如果无法找到路线，输出 1。

## 分析：

~~IOI 1993 的原题，疑似 DP 起源。~~

### 费用流：

先不讲 DP，讲一下这题费用流的做法。~~毕竟这种做法不用太多脑子。~~

首先，要看出一点，这题目所要求的其实与方向无关，可以看作两个人同时从 1 出发走到 n，中间两人不能经过同一个点。

其次，走的路径和经过的点权都要考虑，所以单纯的网络流很难满足，考虑费用流。

最后，因为在走的路径不能重叠的限制，显然是把走的路径当做流量，把经过的点的点权作为费用比较好。

综上，再辅以一定的尝试，我们可以建出本题网络流模型：

将 1 点设为源点，拆点，中间连流量为 2，费用为 1 的边。

将 n 点设为汇点，拆点，中间连流量为 2，费用为 1 的边。

对于其余的点，拆点，中间连一条流量为 1，费用也为 1 的边(这样就限制了每个点只能经历一次)。

其余的边流量为 1，费用为 0。

这样直接跑最大费用最大流就可以了。

对于烦人的读入，直接用 STL 就可以了。

Code 1:
~~~
# include <map>
# include <cstdio>
# include <string>
# include <cstdlib>
# include <cstring>
# include <iostream>
# include <algorithm>
# define N 10000
# define M 100000
# define reg register
using std::map;
using std::cin;
using std::cout;
using std::string;

class Queue
{
    static const int MAX_QUEUE_SIZE = 2e5;
    private:
            int Q_U_E_E[MAX_QUEUE_SIZE],rear_,front_;
    public:
            Queue(){rear_=-1;front_=0;}
            ~Queue(){}

            inline void Push(const int Val){Q_U_E_E[++rear_] = Val;}
            inline int Size(){return rear_-front_+1;}
            inline void reset(){rear_=-1;front_=0;}
            inline bool Empty(){return rear_ < front_;}
            inline int Get(){return Q_U_E_E[front_++];}
            inline int Front(){return Q_U_E_E[front_];}
            inline void Pop(){++front_;}
} q;

struct edge
{
    int Next,to,Wi,Flow;
    edge(const int Next_=0,const int to_=0,const int Wi_=0,const int Flow_=0):Next(Next_),to(to_),Wi(Wi_),Flow(Flow_){}
} e[M+5];

int n,m,edge_tot = 1,S,T,head[N+5],ans;

inline void add_edge(const int u,const int v,const int wi,const int Flow)
{
    e[++edge_tot] = edge(head[u],v,wi,Flow);
    head[u] = edge_tot;
}

string s1,s2;
bool inq[N+5];
map<string,int> mp;
int dis[N+5],flow[N+5],Pre[N+5];

void Input()
{
    cin>>n>>m;

    for(reg int i = 1; i <= n ; ++i)
    {
        cin>>s1;
        mp[s1] = i;
    }
}

void Build_Graph()
{
    Input();
    S = 1;T = n;
    add_edge(S,S+n,0,2);add_edge(S+n,1,0,0);
    add_edge(T,T+n,0,2);add_edge(T+n,T,0,0);

    for(reg int i = 2; i < n ; ++i){add_edge(i,i+n,0,1);add_edge(i+n,i,0,0);}

    for(reg int i = 1,x,y; i <= m ; ++i)
    {
        cin>>s1>>s2;
        x = mp[s1];y = mp[s2];
        if(y < x) x ^= y ^= x ^= y;
        add_edge(x+n,y,1,1);
        add_edge(y,x+n,-1,0);
    }
}

bool SPFA()
{
    memset(inq,0,sizeof(inq));
    memset(dis,-1,sizeof(dis));
    memset(flow,0x3f,sizeof(flow));
    q.reset();q.Push(S);inq[S] = 1;dis[S] = 0;
    
    while(q.Size())
    {
        int u = q.Get();inq[u] = 0;
        
        for(reg int i = head[u]; i ; i = e[i].Next)
            if(e[i].Flow > 0 && (dis[e[i].to] < dis[u] + e[i].Wi))
            {
                dis[e[i].to] = dis[u] + e[i].Wi;
                Pre[e[i].to] = i;
                flow[e[i].to] = flow[u] > e[i].Flow ? e[i].Flow : flow[u];
                if(!inq[e[i].to]){q.Push(e[i].to);inq[e[i].to] = 1;}
            }
    }

    return dis[T] != -1;
}

inline bool MCMF()
{
    int Max_Flow = 0;

    while(SPFA())
    {
        Max_Flow += flow[T];
        ans += flow[T] * dis[T];
        reg int u = T;
        
		while (u != S)
        {
            e[Pre[u]].Flow -= flow[T];
            
			e[Pre[u]^1].Flow += flow[T];
		
            u = e[Pre[u]^1].to;
        }
    }

    return Max_Flow == 2;
}

int main()
{
    Build_Graph();

    if(MCMF()) printf("%d",ans);
    else printf("1");

    return 0;
}
~~~

其实虽然本题的费用流模型很裸，但是对代码能力要求较高，Debug 时间可能较长(~~主要原因是我已经 N 年没写过网络流费用流相关题目~~)。

### 想办法降低码量，考虑 DP：

**题目求的其实与方向无关，可以看作两个人同时从 1 出发走到 n，中间两人不能经过同一个点。**

回到这个关键点，其实这里抽象化一下相当于在原图中求一个包含 1，n 两点的最大环。

设计状态 $dp[i][j]$ 表示从起点分别走到 $i,j$ 的不重复最长路径。

首先最基础的一点，他本身是有对称性，也就是 $dp[i][j] = dp[j][i]$,因为两人交换路径不会影响答案。

难点在于如何确定每个点只经历一次，这一点我看其他题解也没讲清楚(~~可能是太显然了~~)。

其实这一点也不难，因为我们采用了邻接矩阵存图，所以天然的没有重边，
而在枚举路径的时候，其实我们是通过每条边只会被用一次来维持 $dp$ 数组的每一次转移路径不重叠。

综上所述，便有了状态转移方程：

$$dp(j,i) = dp(i,j) = Max(dp(i,k)+1)\ \ i \in[1,n],j \in(i,n],k\in[1,j)$$

最后初始化时 $dp[1][1] = 1$。 

答案为所有与 1 有边连接的点的最大值。

极限压缩码量以后能做到整个代码 527B 的码量(与上面的网络流形成鲜明对比)。

Code 2：
~~~c++
#include<map>
#include<string>
#include<iostream>
#define F(k,l,r) for(int k=l;k<=r;++k)
using namespace std;
int n,m,G[105][105],f[105][105],ans=1;
string s1,s2;
map<string,int> p;
int main()
{
    cin>>n>>m;
    F(i,1,n){cin>>s1;p[s1]=i;}
    F(i,1,m){cin>>s1>>s2;G[p[s1]][p[s2]]=G[p[s2]][p[s1]]=1;}
    f[1][1]=1;\\压缩版
    F(i,1,n)F(j,i+1,n)F(k,1,j-1)if(G[j][k]&&f[i][k])f[i][j]=f[j][i]=((f[i][j]<=f[i][k])?f[i][k]+1:f[i][j]);
    F(i,1,n)if(G[i][n])ans=(ans<f[i][n]?f[i][n]:ans);
    cout<<ans;
    return 0;
}

void DP()\\不压缩码量的 DP。
{
    f[1][1] = 1;
    for(reg int i = 1; i <= n ; ++i)
        for(reg int j = i+1; j <= n ; ++j)
            for(reg int k = 1; k < j ; ++k)
                if(G[j][k] && f[i][k])
                    f[i][j] = f[j][i] = ((f[i][j] <= f[i][k]) ? f[i][k]+1 : f[i][j]);
    int ans = 1;
    for(reg int i = 1; i <= n ; ++i)
        if(G[i][n]) ans = ((ans < f[i][n]) ? f[i][n] : ans);
    printf("%d\n",ans);
}
~~~
