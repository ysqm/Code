# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define reg register
# define Gc getchar()//*/(SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
char BB[1<<15],*SS=BB,*TT=BB;
inline int Read()
{
    register int x = 0;char ch = Gc;

    while(ch < '0' || ch > '9')ch = Gc;

    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = Gc;}

    return x;
}

int n,k,ans = 0x3f3f3f3f;

struct node
{
    int x,y;
    
    node(const int y_=0,const int x_=0):x(x_),y(y_){}

    inline bool operator < (const node& b)const {return (x==b.x ? (x < b.x) : (y < b.y));}
} p[55];

struct sq
{
    int x1,y1,x2,y2;
    bool Used;

    sq(const int x1_=0,const int y1_=0,const int x2_=0,const int y2_=0,const bool Used_=0):x1(x1_),x2(x2_),y1(y1_),y2(y2_),Used(Used_){}

    inline int Max(const int a,const int b){return a > b ? a : b;}
    inline int Min(const int a,const int b){return a < b ? a : b;}
    inline bool inmat(const node& a){return (x1 <= a.x && x2 >= a.x && a.y >= y1 && y2 >= a.y);}
    inline bool inmat(const int x,const int y){return (x1 <= x && x <= x2 && y1 <= y && y <= y2);}
    inline bool cup(const sq& x){return (Used && x.Used && (inmat(x.x1,x.y1) || inmat(x.x2,x.y2) || inmat(x.x1,x.y2) || inmat(x.x2,x.y1)));}
    inline int calc(){return (Used ? (x2-x1)*(y2-y1) : 0);}
    inline void Add(const node& x){((!Used) ? (*this = sq(x.x,x.y,x.x,x.y,1)) : (*this = sq(Min(x1,x.x),Min(y1,x.y),Max(x2,x.x),Max(y2,x.y),1)));}

} K[5];

void dfs(const int cur,const int sum)
{
    if(sum >= ans) return;
    if(cur == n+1)
    {
        for(reg int i = 1; i <= k ; ++i)
            for(reg int j = i+1; j <= k ; ++j)
                if(K[i].cup(K[j])) return;
        ans = sum;
    }
    else
    {
        for(reg int i = 1; i <= k ; ++i)
        {
            sq tmp = K[i];
            K[i].Add(p[cur]);
            dfs(cur+1,sum-tmp.calc()+K[i].calc());
            K[i] = tmp;
        }
    }
    
}

int main()
{
    n = Read();k = Read();

    for(reg int i = 1; i <= n ; ++i) p[i] = node(Read(),Read());

    //std::sort(p+1,p+n+1);

    dfs(1,0);
    
    printf("%d",ans);

    return 0;
}
