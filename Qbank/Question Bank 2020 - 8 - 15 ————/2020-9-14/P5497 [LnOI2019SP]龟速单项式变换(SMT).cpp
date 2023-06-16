# include<bits/stdc++.h>
# define reg register
# define N 500000
# define Ls(K) (K<<1)
# define Rs(K) (K<<1|1)
# define Gc (SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
char BB[1<<15],*SS=BB,*TT=BB;
inline int Read()
{
    register int x = 0;char ch = Gc;

    while(ch < '0' || ch > '9')ch = Gc;

    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = Gc;}

    return x;
}

int n,m;

int main()
{
    scanf("%d%d",&n,&m);
    puts(m <= n ? "YES" : "NO");
    return 0;
}
