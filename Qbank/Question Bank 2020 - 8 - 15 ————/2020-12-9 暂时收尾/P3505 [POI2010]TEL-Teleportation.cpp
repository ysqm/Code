# include <ctime>
# include <cmath>
# include <queue>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define reg register
# define LL long long
# define FileRead(x) freopen(#x".in","r",stdin)
# define FileWrite(x) freopen(#x".out","w",stdout) 
namespace IO
{
    char BB[1<<15],*SS=BB,*TT=BB;
    //inline char Gc(){return (SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++);}
    # define Gc() getchar()
	inline bool Isdigit(const char ch){return '0' <= ch && ch <= '9';}
    inline int Read()
    {
        register int x = 0;char ch = Gc();
    
        while(!Isdigit(ch)) ch = Gc();
    
        while(Isdigit(ch)){x = x*10+(ch^48);ch = Gc();}
    
        return x;
    }
    
    inline int Max(const int x,const int y){return x < y ? y : x;}
    inline int Min(const int x,const int y){return x < y ? x : y;}
}

const int N = 40000;
const int M = 1e6;

std::vector<int> G[N+5];
void add_edge(const int u,const int v){G[u].push_back(v);G[v].push_back(u);}
long long ans;
LL n,m,s1,s2,dis[N+5];

int main()
{
    FileRead(ysqm);
    //FileWrite(myans);
    n = IO::Read();m = IO::Read();
    for(int i = 1; i <= m ; ++i) add_edge(IO::Read(),IO::Read());
    for(int i = 0; i < G[1].size() ; ++i) {dis[G[1][i]] = 1;++s1;}
    for(int i = 0; i < G[2].size() ; ++i) {dis[G[2][i]] = 2;++s2;}
    int s3 = n-s1-s2-2,ns1 = s1,ns2 = s2;
	for(int i = 3; i <= n ; ++i)
        if(dis[i] == 1)
        {
            --ns1;ans += ns1;
            for(int j = 0; j < G[i].size() ; ++j) if(G[i][j] > i && dis[G[i][j]]) --ans; 
        }
        else if(dis[i] == 2)
        {
            --ns2;ans += ns2;
            for(int j = 0; j < G[i].size() ; ++j) if(G[i][j] > i && dis[G[i][j]]) --ans; 
        }
        else 
        {
            --s3;ans += s3;
            int flag = 0,sum = 0;
            for(int j = 0; j < G[i].size() ; ++j)
                if(dis[G[i][j]]) {flag = dis[G[i][j]];++sum;}
                else if(G[i][j] > i) --ans;
            if(flag == 1) ans += s1-sum;
            else if(flag == 2) ans += s2-sum;
            else ans += std::max(s1,s2);
        }
    printf("%lld\n",ans);
    return 0;
}
