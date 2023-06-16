# include <cstdio>
# define N 400000
# define reg register

int n,m,K,f[N + 42],head[N + 42],broken[N + 42],ans[N + 42],num,etot;
bool Broken[N + 42];

inline int Read()
{
	int x = 0;char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	
	return x;
}


struct edge
{
	int from,u,v;
} e[(N << 1) + 42];

inline void add(const int u,const int v)
{
	e[++etot] = (edge){head[u],u,v};
	
	head[u] = etot;
	
	e[++etot] = (edge){head[v],v,u};
	
	head[v] = etot;
}

inline int Find(const int x){return f[x] == x ? x : f[x] = Find(f[x]);}

int main()
{
	n = Read();m = Read();
	
	for(reg int i = 1; i <= n ; ++i) f[i] = i;
	
	for(reg int i = 1; i <= m ; ++i) add(Read(),Read());
	
	K = Read();num = n - K;
	
	for(reg int i = 1; i <= K ; ++i) Broken[broken[i] = Read()] = 1;
	
	for(reg int i = 1; i <= (m << 1) ; ++i)
		if(!Broken[e[i].u] && !Broken[e[i].v] && Find(e[i].u) != Find(e[i].v)){
			
			--num;
			
			f[Find(e[i].u)] = f[Find(e[i].v)];
		}
	
	ans[K + 1] = num;
	
	for(reg int t = K,u; t >= 1; --t){
		
        ++num;Broken[u = broken[t]] = 0;
        
        for(reg int i = head[u]; i ; i = e[i].from)
        	if(!Broken[e[i].v] && Find(u) != Find(e[i].v)){
        		
				--num;
			
				f[Find(e[i].v)] = f[Find(u)];
			}
			
		ans[t] = num;
    }
	
	for(reg int i = 0; i <= K ; ++i) printf("%d\n",ans[i + 1]);
	
	return 0;
}
