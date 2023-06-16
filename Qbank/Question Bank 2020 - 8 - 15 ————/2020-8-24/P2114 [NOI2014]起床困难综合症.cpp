# include <cstdio>

char s[10];
int n,m,x = 0x7fffffff,y = 0,ans,rans;

int main()
{
    scanf("%d%d",&n,&m);

    for(int i = 1,a; i <= n ; ++i)
    {
        scanf("%s%d",s,&a);
        if(*s == 'A') {x&=a;y&=a;}
        if(*s == 'O'){x|=a;y|=a;}
        if(*s == 'X'){x=x^a;y^=a;}
    }

    for(int i = 30; i >= 0 ; --i) ((y&(1<<i))&&(rans = rans|(1<<i))) || ((x&(1<<i))&&((ans|(1<<i))<=m)&&(ans=ans|(1<<i))&&(rans=rans|(1<<i)));

    printf("%d",rans);

    return 0;
}
