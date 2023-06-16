#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
const int size=3e4+10;
int n,tot,tr[size][2],fail[size],end[size],ins[size],vis[size];char s[size];
queue<int> q;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
    return x*f;
}
inline void insert(char *str){
    int len=strlen(str),p=0;
    for(int k=0;k<len;k++){
        char ch=str[k]-'0';
        if(!tr[p][ch]) tr[p][ch]=++tot;
        p=tr[p][ch];
    }
    end[p]=1;
}
inline void bfs(){
    for(int i=0;i<=1;i++) if(tr[0][i]) q.push(tr[0][i]);
    while(q.size()){
        int k=q.front();q.pop();
        for(int i=0;i<=1;i++){
            if(tr[k][i]){
                fail[tr[k][i]]=tr[fail[k]][i];
                end[tr[k][i]]|=end[fail[tr[k][i]]];
                q.push(tr[k][i]);
            }
            else tr[k][i]=tr[fail[k]][i];
        }
    }
}
inline void dfs(int x){
    if(ins[x]){printf("TAK\n");exit(0);}
    if(vis[x]||end[x]) return;
    vis[x]=ins[x]=1;
    if(tr[x][0]) dfs(tr[x][0]);
    if(tr[x][1]) dfs(tr[x][1]);
    ins[x]=0;
}
int main(){
    freopen("P2444_2.in","r",stdin);
	n=read();
    for(int i=1;i<=n;i++){scanf("%s",s);insert(s);}
    bfs();dfs(0);
    printf("NIE\n");
    return 0;
}
