# include <cstdio>
# define N 100000000

bool vis[N+5];
int p[N+5],tot,n;

int main()
{
    freopen("prime.txt","w",stdout);
    scanf("%d",&n);
    for(int i = 2; i <= n ; ++i)
    {
        if(!vis[i]) p[++tot] = i;
        for(int j = 1; j <= tot && i*p[j] <= n ; ++j)
        {
            vis[i*p[j]] = true;
            if(i%p[j]==0) break;
        }
    }
    printf("%d\n",tot); 
    for(int i = 1; i <= tot ; ++i) printf("%d,",p[i]);
    return 0;
}
