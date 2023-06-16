# include <cstdio>
# define reg register

const int Max_Status = (1<<13)-1;

int f[Max_Status+5],n,m,e[27],ans = 27*27,s0;

inline int Count(const int x){return f[x&Max_Status] + f[x>>13];}

void dfs(const int pos,const int k,const int Sum,const int s1,const int s2)
{
    if(k == n)
    {
        if(ans > Sum)
        {
            ans = Sum;
            s0 = s1;
        }
    }
    else 
    {
        if(Count(s1) < n/2) dfs(pos+1,k+1,Sum+Count(s2&e[pos]),s1|(1<<pos-1),s2);
        if(Count(s2) < n/2) dfs(pos+1,k+1,Sum+Count(s1&e[pos]),s1,s2|(1<<pos-1));
    }
}

int main()
{
    scanf("%d%d",&n,&m);

    for(reg int i = 1,u,v; i <= m ; ++i)
    {
        scanf("%d%d",&u,&v);
        e[u] |= (1<<v-1);
        e[v] |= (1<<u-1);
    }

    for(reg int i = 0; i <= Max_Status ; ++i) f[i] = f[i>>1]+(i&1);

    dfs(1,0,0,0,0);

    for(reg int i = 0; i < n ; ++i) if(s0&(1<<i)) printf("%d ",i+1);

    return 0;
}