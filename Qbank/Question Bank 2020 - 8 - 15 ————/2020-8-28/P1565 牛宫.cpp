# include <cstdio>
# include <cstring>
# include <algorithm>
# define reg //register
# define LL long long
# define N 2500
# define Gc getchar()//(SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
char BB[1<<15],*SS=BB,*TT=BB;
inline int Read()
{
    register int x = 0,f = 1;char ch = Gc;

    while(ch < '0' || ch > '9'){if(ch == '-') f = -1;ch = Gc;}

    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = Gc;}

    return f < 0 ? ~x+1 : x;
}
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

inline LL Max(const LL a,const LL b){return a < b ? b : a;}

int n,m,a[N+5][N+5];
long long S[N+5][N+5],ans;

int main()
{
    scanf("%d%d",&n,&m);

    for(reg int i = 1; i <= n ; ++i)
        for(reg int j = 1; j <= m ; ++j)
            S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + (a[i][j] = Read());
    
    for(reg int x1 = 1; x1 <= n ; ++x1)
        for(reg int y1 = 1; y1 <= m ; ++y1)
            for(reg int x2 = x1+1; x2 <= n ; ++x2)
                for(reg int y2 = y1+1; y2 <= m ; ++y2)
                {
                    LL sum = S[x2][y2] - S[x2][y1-1] - S[x1-1][y2] + S[x1-1][y1-1];
                    if(sum < 0) continue;
                    ans = Max(ans,(x2-x1+1)*(y2-y1+1));
                }


    printf("%lld",ans);

    return 0;
}
