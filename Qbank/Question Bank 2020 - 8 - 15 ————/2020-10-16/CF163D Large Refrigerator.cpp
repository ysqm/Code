# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# include <queue>
# include <iostream>
# define LL long long
# define N 3000

struct node
{
    int wi,p;
    bool operator < (const node& b)const{p > b.p;}
} a[N+5];

int n;

int main()
{
    scanf("%d",&n);
    for(int i = 1; i <= n ; ++i) scanf("%d%d",&a[i].wi,&a[i].p);
    std::sort(a+1,a+n+1);
    return 0;
}