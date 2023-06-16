#include<bits/stdc++.h>
#define il inline
#define ll long long
#define For(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define Bor(i,a,b) for(int (i)=(b);(i)>=(a);(i)--)
using namespace std;
const int N=300005;
int n,k,h[N],net[N],to[N],cnt,w[N],dis[N],tot[N];
bool vis[N];
queue<int>q;

il int gi(){
    int a=0;char x=getchar();
    while(x<'0'||x>'9')x=getchar();
    while(x>='0'&&x<='9')a=(a<<3)+(a<<1)+x-48,x=getchar();
    return a;
}

il void add(int u,int v,int c){to[++cnt]=v,net[cnt]=h[u],h[u]=cnt,w[cnt]=c;}

int main(){
    n=gi(),k=gi();
    int u,v,f;
    while(k--){
        f=gi(),u=gi(),v=gi();
        if(f==1)add(u,v,0),add(v,u,0);
        else if(f==2){
            if(u==v){cout<<-1;return 0;}
            add(u,v,1);
        }
        else if(f==3)add(v,u,0);
        else if(f==4){
            if(v==u){cout<<-1;return 0;}
            add(v,u,1);
        }
        else if(f==5)add(u,v,0);
    }
    Bor(i,1,n)add(0,i,1);
    vis[0]=1,q.push(0);
    while(!q.empty()){
        int u=q.front();q.pop();vis[u]=0;
        if(tot[u]==n-1){cout<<-1;return 0;}
        tot[u]++;
        for(int i=h[u];i;i=net[i])
            if(dis[to[i]]<dis[u]+w[i]){
                dis[to[i]]=dis[u]+w[i];
                if(!vis[to[i]])vis[to[i]]=1,q.push(to[i]);
            }
    }
    ll ans=0;
    For(i,1,n)ans+=dis[i];
    cout<<ans;
    return 0;
}
