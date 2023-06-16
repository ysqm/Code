# include <cstdio>
# include <algorithm>
# include <queue> 
using namespace std;
# define N 100000
# define M 100000
# define R register
# define inf 1000000000
# define f(i,n,m) for(register int (i) = (m);(i) <= (n); (i)++)

int head[N + 42],inq[N + 42],deep[N + 42],cnt,dis[N + 42];

bool vis[N + 42],flag;

queue <int> q;

struct edge
{
	int from,to,wi;
} e[M * 2 + N + 42];

int n,k;

inline int r(int &x); 

inline void add(const int u,const int v,const int w)
{
	e[++cnt].from = head[u];
	e[cnt].to = v;
	e[cnt].wi = w;
	head[u] = cnt;
}

inline int INIT() 
{
	r(n);r(k);
	int op,u,v;
	
	f(i,k,1){
		r(op);r(u);r(v);
		
		if(op == 1) {
            add(u,v,0);
            add(v,u,0);
        }
        else if(op == 2)    add(u,v,1);
        else if(op == 3)    add(v,u,0);
        else if(op == 4)    add(v,u,1);
        else if(op == 5)    add(u,v,0);
        if(op % 2 == 0 && u == v)    {
            printf("-1\n");
            flag = true;
            return 0;
        }
		
	}
	
	for(R int i = n;i > 0 ; i--) add(0,i,0);
}
bool SPFA(const int s)
{
	f(i,n,1){
		//dis[i] = -inf;
		inq[i] = deep[i] = 0;
	}
	dis[s] = 1;
	q.push(s);
	vis[s] = 1;
	int u,v;
	
	while(q.size()){
		u = q.front();
		q.pop();
		vis[u] = false;
		
		for(R int i = head[u]; i ; i = e[i].from)
			if(dis[e[i].to] < dis[u] + e[i].wi){
				v = e[i].to;
				dis[v] = dis[u] + e[i].wi;
				deep[v] = deep[u] + 1;
				if(++inq[v] > n && deep[v] > n) return false;
				if(!vis[v]){
					q.push(v);
					vis[v] = true;
				}
			}
	
	}
	
	return true;
}

int main()
{
	//freopen("testdata.in","r",stdin);
	INIT();
	if(flag) return 0;
	long long ans = 0;
	bool fa = SPFA(0);
	f(i,n,1) ans += dis[i];
	if(fa) printf("%lld",ans); 
	else printf("-1");
	return 0;
}
inline int r(int &x)
{
	x = 0;
	int f = 1;
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
	
}
