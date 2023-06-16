# include <cstdio>
# define reg register
# define N 100005

inline int Read()
{
	int x = 0,f = 1;char c = getchar();
	
	while(c < '0' || c > '9') {if(c == '-') f = - 1 ;c = getchar();}
	
	while(c >= '0' && c <= '9'){x = (x << 3) + (x << 1) + (c ^ 48);c = getchar();}
	
	return f * x;
} 

struct edge
{
	int from,to,wi;
} e[(N << 1) + 42];

inline int Max(const int& a,const int b){return a > b ? a : b;}

int head[N + 42],n,trie[(N << 5) + 42][2],dis[N + 42],tot,ans;

inline void add_edge(const int wi,const int u,const int v)
{
	e[++tot].from = head[u];
	
	e[tot].to = v;
	
	head[u] = tot;
	
	e[tot].wi = wi;
	
	e[++tot].from = head[v];
	
	e[tot].to = u;
	
	head[v] = tot;
	
	e[tot].wi = wi;
}

inline void dfs(const int u,const int father)
{
	for(reg int i = head[u]; i ; i = e[i].from)
		if(e[i].to != father){
			dis[e[i].to] = dis[u] ^ e[i].wi;
        	dfs(e[i].to,u);
		}
}

int main()
{
	n = Read();
	
	for(reg int i = 1; i < n ; ++i) add_edge(Read(),Read(),Read());
	
	dfs(1,0);
	
	for(reg int i = 1,p,w; i <= n; ++i){
		p = 1;
		
		for(reg int j = 31,k; j >= 0; --j){
			k = (dis[i] >> j) & 1;
			if(!trie[p][k])  trie[p][k] = ++tot;
            p = trie[p][k];
		}
		
		if(i != 1){
			p = 1;w = 0;
		
			for(reg int j = 31,k; j >= 0; --j){
				k = (dis[i] >> j) & 1;
				if(trie[p][k  ^ 1]){
           	    	w = (w << 1) + (k ^ 1);
           		    p = trie[p][k ^ 1];
				}
				else  if(trie[p][k]){
           	    	w = (w << 1) + k;
           	    	p = trie[p][k];
            	}
			}
			
			ans = Max(ans,w ^ dis[i]);
		}
	}
	
	printf("%d",ans);
	
	return 0;
}
