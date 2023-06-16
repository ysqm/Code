# include <cstdio>
# include <algorithm>
# include <cstring>
# include <queue>
# define R register
# define M 800000
# define N 300000
# define inf 0x7f7f7f7f
using namespace std;

inline int r()
{
	int x = 0,f = 1;
	
	char c = getchar();
	
	while(c < '0' || c > '9') c = getchar();
	
	while(c <= '9' && c >= '0'){
		x = (x << 3) + (x << 1) + c - 48;
		
		c = getchar();
	}
	
	return x;
}

struct edge
{
	int from,to;
} e[M * 3 + 42];

int head[N + 42],cnt_e,n,m,h0[N + 42],h1[N + 42];

inline void add(int v,int u)
{
	e[++cnt_e].from = head[u];
	e[cnt_e].to = v;
	head[u] = cnt_e;
}

inline void add1(int u,int v)
{
	e[++cnt_e].from = h0[u];
	e[cnt_e].to = v;
	h0[u] = cnt_e;
}
inline void add2(int u,int v)
{
	e[++cnt_e].from = h1[u];
	e[cnt_e].to = v;
	h1[u] = cnt_e;
}

int dfn[N + 42],__t,colour,id[N + 42],dis0[N + 42],c[N + 42],dis1[N + 42];

bool ins[N + 42];

struct STACK
{
	int STACK[N + 42],top;
} s,low;

inline void Gabow(int u,int fa)
{
	dfn[u] = ++__t;
	
	s.STACK[++s.top] = low.STACK[++low.top] = u;
	
	ins[u] = true;
	
	for(R int i = head[u]; i ;i = e[i].from){
		if(dfn[e[i].to] == 0)
			
			Gabow(e[i].to,u);
			
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
			
			c[colour]++;
			
			ins[p] = false;
			
		} while(p != u);
		
	} 
	
	return ;
}

queue <int> q;

int main()
{
	//freopen("1.txt","w",stdout);
	
	n = r();m = r();
	
	for(R int i = 1; i <= m; i++)
		add(r(),r());
		
	for(R int i = 1; i <= m; i++)
		if(dfn[i] == 0) Gabow(i,i);
	
	for(int i = 1; i <= n; i++)
			for(int j = head[i]; j ; j = e[j].from)
				if(id[e[j].to] != id[i]){
					add1(id[i],id[e[j].to]);
					//printf("%d %d\n",id[i],id[e[j].to]);
					add2(id[e[j].to],id[i]);
				}
	
	q.push(id[1]);
	
	int u;
	
	dis0[id[1]] = dis1[id[1]] = c[id[1]];
	
	while(q.size()){
		u = q.front();q.pop();
		
		for(int i = h0[u]; i ; i = e[i].from)
			if(dis0[e[i].to] < dis0[u] + c[e[i].to]){
				dis0[e[i].to] = dis0[u] + c[e[i].to];
				q.push(e[i].to);
			}
	}
	
	q.push(id[1]);
	
	while(q.size()){
		u = q.front();q.pop();
		
		for(int i = h1[u]; i ; i = e[i].from)
			if(dis1[e[i].to] < dis1[u] + c[e[i].to]){
				dis1[e[i].to] = dis1[u] + c[e[i].to];
				q.push(e[i].to);
				
			}
	}
	
	int ans = c[id[1]];
	
	for(int i = 1 ; i <= n ; i++)
    if(!ins[id[i]] && dis0[id[i]]){
    	ins[id[i]] = 1;
    	for(int j = h1[id[i]] ; j ;j = e[j].from){
      	  if(!dis1[e[j].to])continue;
      	  ans = max(ans,dis0[id[i]] + dis1[e[j].to] - c[id[1]]);
   	 	}

    }
		
		
	printf("%d",ans);
	
	return 0;
}
