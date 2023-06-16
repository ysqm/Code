#include <bits/stdc++.h>
using namespace std;

const int maxn=500000+15;
struct Edge
{
    int x,y,next;
    Edge(int x=0,int y=0,int next=0):x(x),y(y),next(next) {}
 }edge[maxn];
int sumedge,head[maxn];
int n;
char s[maxn];
int fa[maxn];
int ins(int x,int y)
{
    edge[++sumedge]=Edge(x,y,head[x]);
    return head[x]=sumedge;
}
int sum[maxn*2];
long long ans[maxn];
int py;
int dfs(int now)
{
    int temp=0;
    if (s[now]=='(')
    {
        py--;
        sum[py+1]++;
    }
    else
    {
        py++;
        temp=sum[py-1];
        sum[py-1]=0;
        ans[now]=sum[py];
    }
    for (int u=head[now];u;u=edge[u].next)
     dfs(edge[u].y);
    if (s[now]=='(')
    {
        sum[py+1]--;
        py++;
    }
    else
    {
        sum[py-1]=temp;
        py--;
    }
    return 0;
}
int main()
{
    scanf("%d",&n);
    scanf("%s",s+1);
    for (int i=2;i<=n;i++)
    {
        scanf("%d",&fa[i]);
        ins(fa[i],i);
    }
    py=n;
    long long ret=0;
    dfs(1);
    for (int i=2;i<=n;i++) ans[i]+=ans[fa[i]];
//  for (int i=1;i<=n;i++) printf("%d ",ans[i]);
    for (int i=1;i<=n;i++) ret^=(ans[i]*i);
    cout << ret << endl;
    return 0;
}