# include <cstdio>
# include <cstring>
# include <algorithm>
# define N 500000
# define reg register

inline int Read()
{
	int x = 0;char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch >= '0' && ch <= '9'){x = x*10 + (ch^48);ch = getchar();}
	
	return x;
}

struct edge
{
	int next,to,wi;
} e[(N << 1) + 42];

int head[N + 42],f[N + 42],tag[N + 42],edge_tot,n,m,q[N + 42],ans,limit,res,root = 1;

inline void add_edge(const int wi,const int& u,const int& v)
{
	e[++edge_tot] = (edge){head[u],v,wi};
	
	head[u] = edge_tot;
	
	e[++edge_tot] = (edge){head[v],u,wi};
	
	head[v] = edge_tot;
}

void DFS(const int& u,const int& father)
{
	for(reg int i = head[u]; i ;i = e[i].next) if(e[i].to != father) DFS(e[i].to,u);
	
	reg int t = 0;
	
	for(reg int i = head[u]; i ;i = e[i].next) if(e[i].to != father) q[++t] = f[e[i].to] + e[i].wi;
	
	std::sort(q + 1,q + t + 1);	
	
	while(q[t] >= limit){--t;--res;}
	
	for (reg int i = 1; i <= t; ++i)
        if (tag[i] != u)
        {
            reg int l = i + 1, r = t, cur = t + 1;//二分另外一条链使得能刚好组成赛道
            while (l <= r)
            {
                reg int mid = ((l + r) >> 1);
                
                if (q[i] + q[mid] >= limit) cur = mid, r = mid - 1;
                else l = mid + 1;
            }

            while (tag[cur] == u && cur <= t) cur++;

            if (cur <= t) {tag[i] = tag[cur] = u;res--;}
        }

    f[u] = 0;
    
    for (reg int i = t; i >= 1 ; --i)if (tag[i] != u){f[u] = q[i];return;}
}

int main()
{
	n = Read();m = Read();
	
	for(reg int i = 1; i < n ; ++i) add_edge(Read(),Read(),Read());
	
	reg int l = 0,r = 500000000;
	
	 while (l <= r)
    {
        limit = ((l + r) >> 1);
        
        res = m;

        memset(tag,0,sizeof(tag));

        DFS(root,root);
        if (res <= 0) ans = limit, l = limit + 1;
        
        else r = limit - 1;
    }

    printf("%d",ans);
	
	return 0;
}
