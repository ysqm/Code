# include <cstdio>
# include <algorithm>
# include <queue>
# define N 10000
# define M 100000
# define R register
using namespace std;

inline int r()
{
	int f = 1,x = 0;;
	
	char c = getchar();
	
	while(c > '9' || c < '0'){
		if(c == '-') f = -1;
		
		else f = 1;
		
		c = getchar();
	}
	
	while(c >= '0' && c <= '9'){
		x = (x << 3) + (x << 1) + c - '0';
		
		c = getchar();
	}
	
	return x * f;
}

struct edge
{
	int from,to,wi;
} e[M + 42],e1[M + 42];

int head[N + 42],e_cnt,h[N + 42],sump[N + 42],n,m,in[N + 42],dis[N + 42],cnt;

inline void add(int u,int v/*,int wi*/)
{
	e[++e_cnt].from = head[u];
	
	e[e_cnt].to = v;
	
	//e[e_cnt].wi = wi;
	
	head[u] = e_cnt;
	
}

inline void add1(int u,int v/*,int wi*/)
{
	e1[++cnt].from = h[u];
	
	e1[cnt].to = v;
	
	//e[e_cnt].wi = wi;
	
	h[u] = cnt;
	
	in[v]++;
	
}

int dfn[N + 42],t__,id[N + 42],colour,sum[N + 42];

bool ins[N + 42];

struct STACK
{
	int STACK[N + 42],top;
} s,low;

inline void tarjan(int u,int fa)
{
	dfn[u] = ++t__;
	
	s.STACK[++s.top] = low.STACK[++low.top] = u;
	
	ins[u] = true;
	
	for(R int i = head[u]; i ;i = e[i].from){
		if(dfn[e[i].to] == 0)
			
			tarjan(e[i].to,u);
			
		else if(ins[e[i].to])
		
			while(dfn[low.STACK[low.top]] > dfn[e[i].to])
			
				low.top--;
	}
			
	if(u == low.STACK[low.top]){
		int p;
		
		low.top--;
		
		colour++;
		
		do{
			p = s.STACK[s.top--];
			
			id[p] = colour;
			
			sum[colour] += sump[p];
			
			ins[p] = false;
			
		} while(p != u);
		
	} 
	
	return ;
}

inline void work()
{
	for(R int i = 1; i <= n; i++)
		for(R int j = head[i]; j ; j = e[j].from)
			if(id[i] != id[e[j].to])
				add1(id[i],id[e[j].to]);
}

queue <int> q;

inline int SPFA()
{
	for(R int i = 1; i <= colour; i++)
		if(in[i] == 0){
			
			q.push(i);
			
			dis[i] = sum[i];
			
		}
		
	int u,v;
	
	while(q.size()){
		u = q.front();
		
		q.pop();
		
		for(R int i = h[u]; i ; i = e1[i].from){	
			v = e1[i].to;
			
            dis[v] = max(dis[v],dis[u] + sum[v]);
            
            in[v]--;
            
            if (in[v] == 0) q.push(v);
		}
	}
	
	int ans = 0;
	
	for(R int i = 1; i <= colour; i++)
		ans = max(ans,dis[i]);
		
	return ans;
}

int main()
{
	freopen("1.in","r",stdin);
	
	n = r();m = r();
	
	for(R int i = 1; i <= n; i++) sump[i] = r();
	
	for(R int i = 1; i <= m; i++) add(r(),r());
	
	for(R int i = 1; i <= n; i++)
		if(dfn[i] == 0) tarjan(i,i);
		
	work();
	
	printf("%d",SPFA());
	
	return 0;
} 
