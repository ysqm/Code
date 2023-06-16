    #include<bits/stdc++.h>
    #define N 10050
    using namespace std;
    struct EDGE{
        int next,to;
    }edge[N*20];
    int head[20*N],dfn[N],low[N];
    int du[N],id[N],all[N];
    bool insta[N];int cnt,tot,gg,n,m;
    stack<int>s;
    inline void add(int x,int y){
        cnt++;
        edge[cnt].to=y;
        edge[cnt].next=head[x];
        head[x]=cnt;
    }
    void in(int &read){
        int x=0,f=1;char ch;
        for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
        if(ch=='-'){f=-1;ch=getchar();}
        while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
        read=x*f;//���Դ������Ķ����Ż�
    }
    void tarjan(int x){
        dfn[x]=low[x]=++tot;
        s.push(x);insta[x]=true;
        for(int i=head[x];i;i=edge[i].next){
            int u=edge[i].to;
            if(!dfn[u]){
                tarjan(u);
                low[x]=min(low[x],low[u]);
            }
            else if(insta[u])low[x]=min(low[x],dfn[u]);
        }//tarjanģ��
        int k;
        if(low[x]==dfn[x]){
            ++gg;
            do{
                k=s.top();s.pop();
                insta[k]=false;
                id[k]=gg;all[gg]++;//��һ�������е�Ԫ��Ⱦ��һɫ
            }while(x!=k);
        }
    }
    int main(){
    	freopen("1.txt","r",stdin);
        in(n);in(m);
        int a,b;
        for(register int i=1;i<=m;i++){
            in(a);in(b);
            add(a,b);
        }
        for(register int i=1;i<=n;i++)
            if(!dfn[i])tarjan(i);
        for(register int w=1;w<=n;w++){
            for(int i=head[w];i;i=edge[i].next){
                int u=edge[i].to;
                if(id[w]!=id[u]){
                    du[id[w]]++;//����ÿһ���㲢��¼����
                }
            }
        }
        int tt=0;
        for(register int i=1;i<=gg;i++)
            if(!du[i]){
            if(tt){puts("0");return 0;}//���γ��ֳ���Ϊ0ֱ�����0
            tt=i;//��¼����Ϊ��ķ����ıߺ�
        }
        printf("%d\n",all[tt]);
        return 0;
}
