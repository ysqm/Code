# include <cstdio>
# define reg register

const int Max_Status = (1<<10)-1;

int a[11];

inline bool Isdigit(const char ch){return ch <= '9' && ch >= '0';}

int Input()
{
    register int n = 0;register int ch = getchar();

    while(!Isdigit(ch)) ch = getchar();

    while(Isdigit(ch)) {a[++n] = (ch^48);ch = getchar();}

    return n;
}

int p,f[Max_Status+1][1001];

void Solve()
{
    int n = Input(),Status;

    scanf("%d",&p);Status = (1<<n)-1;

    for(reg int i = 0; i <= p ; ++i) 
        for(reg int j = 0; j <= Status ; ++j)
            f[j][i] = 0;

    f[0][0] = 1;

    for(reg int S = 0,d = 0; S <= Status ; ++S,d = 0)
        for(reg int i = 1; i <= n ; ++i)
            if(!(S&(1<<(i-1))) && !(d&(1<<a[i])) && (d|=(1<<a[i])))
                for(reg int j = 0; j < p ; ++j) f[S|(1<<(i-1))][(j*10+a[i])%p] += f[S][j]; 
    
    printf("%d\n",f[Status][0]);
}

int T;

int main()
{
    scanf("%d",&T);

    while(T--) Solve();

    return 0;
}