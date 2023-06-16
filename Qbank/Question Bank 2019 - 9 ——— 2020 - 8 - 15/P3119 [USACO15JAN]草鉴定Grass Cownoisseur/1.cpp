#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<queue>
using namespace std;
const int N=1e5+5,M=1e5+5;
int h[N],nxt[M],r[M],sum=1;
int h1[N],nxt1[M],r1[M],sum1=1;
int h2[N],nxt2[M],r2[M],sum2=1;
int t,c[N],dfn[N],low[N],s[N],top,color,num,start,gass[N];
int p,q,n,m;
int dis1[N],dis2[N];
bool use[N];
void add(int a,int b){sum++;nxt[sum]=h[a],r[sum]=b;h[a]=sum;}
void add1(int a,int b){sum1++;nxt1[sum1]=h1[a],r1[sum1]=b;h1[a]=sum1;}
void add2(int a,int b){sum2++;nxt2[sum2]=h2[a],r2[sum2]=b;h2[a]=sum2;}
void found(int k)
{
dfn[k]=low[k]=++num,s[++top]=k,use[k]=1;
for(int i=h[k];i;i=nxt[i])
{
    int v=r[i];
    if(!dfn[v])found(v),low[k]=min(low[k],low[v]);
    else if(use[v])low[k]=min(low[k],low[v]);
}   
if(low[k]==dfn[k])
{
    c[k]=++color,use[k]=0;
    gass[color]=1;
    while(s[top]!=k){gass[color]++,use[s[top]]=0;c[s[top--]]=c[k];}
        top--;
}
}
void spfa1(int k)
{
    dis1[k]=gass[k];
    queue<int> Q;
    Q.push(k);
    while(!Q.empty()){
        int now=Q.front();Q.pop();
        for(int i=h1[now];i;i=nxt1[i]){
            int v=r1[i];
            if(dis1[v]<dis1[now]+gass[v]){
                dis1[v]=dis1[now]+gass[v];
                if(!use[v])Q.push(v),use[v]=1;
            }
        }
                use[now]=0;
    }
}
void spfa2(int k)
{ 
    dis2[k]=gass[k];
    queue<int> Q;
    Q.push(k);
    while(!Q.empty()){
        int now=Q.front();Q.pop();
        for(int i=h2[now];i;i=nxt2[i]){
            int v=r2[i];
            if(dis2[v]<dis2[now]+gass[v]){
                dis2[v]=dis2[now]+gass[v];
                if(!use[v])Q.push(v),use[v]=1;
            }
        }
        use[now]=0;
    }
}
int main()
{
//freopen("1.txt","w",stdout);
scanf("%d%d",&n,&m);
while(m--)
{
scanf("%d%d",&q,&p);
add(q,p);
}
for(int i=1;i<=n;i++)if(!dfn[i])found(i);
start=c[1];
for(int i=1;i<=n;i++)
for(int u=h[i];u;u=nxt[u])
if(c[i]!=c[r[u]]){
add1(c[i],c[r[u]]),add2(c[r[u]],c[i]);
printf("%d %d\n",c[i],c[r[u]]);

} 
spfa1(start),spfa2(start);
int ans=gass[start];
for(int i=1;i<=n;i++)
    if(!use[c[i]]&&dis1[c[i]]){
    int now=c[i];
    use[now]=1;
    for(int u=h2[now];u;u=nxt2[u]){
        int v=r2[u];
        if(!dis2[v])continue;
        ans=max(ans,dis1[now]+dis2[v]-gass[start]);
    }

    }
    cout<<ans;
return 0;
}
