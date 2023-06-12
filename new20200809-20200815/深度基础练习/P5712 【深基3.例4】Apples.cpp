# include <cstdio>
# include <cstring>
# include <algorithm>

int n;

int main()
{
    scanf("%d",&n);

    if(n == 0) printf("Today, I ate 0 apple.");
    else if(n == 1) printf("Today, I ate 1 apple.");
    else printf("Today, I ate %d apple.",n);

    return 0;
}
