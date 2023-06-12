# include <cstdio>
# include <cstring>
# include <algorithm>
# define reg register

int m,t,s;

inline int Min(const int a,const int b){return a < b ? a : b;}

int main()
{
    scanf("%d%d%d",&m,&t,&s);

    printf("%d",t == 0 ? m : m - Min(m,(s%t ? (s/t + 1) : s/t)));

    return 0;
}