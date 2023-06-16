# include <cstdio>
# include <algorithm>
# include <vector> 
using namespace std;
# define N 10000
# define M 50000
# define R register
inline int r()
{
	int x = 0,f = 1;
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

int dfn[N + 42],t,head[N + 42],n,m,ID[N + 42],eto[N + 42],cnt[N + 42];
bool ins[N + 42],cntvis[N + 42];

int id;

struct edge
{
	int from,to;
} e[M + 42];

struct STACK
{
	int Stack[N + 42],top;
} s,low;

inline void Gabow(int u)
{
	dfn[u] = ++t;
	s.Stack[++s.top] = low.Stack[++low.top] = u;
	ins[u] = true;
	
	for(R int i = head[u]; i ;i = e[i].from)
	{
		if(dfn[e[i].to] == 0) Gabow(e[i].to);
		
		else if(ins[e[i].to]) while(dfn[low.Stack[low.top]] > dfn[e[i].to]) low.top--;//只保留根节点 
		
	}
	if(u == low.Stack[low.top]){
		int p;
		low.top--;//根出栈 
		//printf("强连通分量%d:\n",++cnt);
		id++;
		
		do{
			p = s.Stack[s.top--];
			ID[p] = id;
			cnt[id]++;
			//printf("%d ",p);
			ins[p] = false;
		}while(p != u);
		
		//printf("\n");
	}
	
	return;
}

/*inline int work(int u,int sum)
{
	sum++;
	cntvis[ID[u]] = true;
	int f = ID[u];
	for(R int i = 1;i <= n; i++)
		if(ID[i] != f)	
			for(R int j = head[i]; j ;j = e[i].from)
				if(!cntvis[ID[e[i].to]])
					work(e[i].to,sum);
				
	return sum;
}*/

int main()
{
	s.top = low.top = 0;
	//freopen("3.txt","r",stdin);
	freopen("1.txt","r",stdin);
	n = r();
	m = r();
	
	for(R int i = 1,a,b; i <= m ;i++){
		a = r();
		b = r();
		
		e[i].from = head[a];
		e[i].to = b;
		head[a] = i;
	}
	
	for(R int i = 1;i <= n; i++)
		if(!dfn[i]) Gabow(i);
		
	for(register int w=1;w<=n;w++)
            for(int i = head[w]; i ;i = e[i].from){
            	int u = e[i].to;
                if(ID[w] != ID[u])
                    eto[ID[w]]++;
			}
		
	int sum = 0,k;
	
	for(R int i = 1;i <= id;i++)
		if(eto[i] == 0) {
			sum++;
			k = i;
		}
	 
	if(sum == 1 ) printf("%d",cnt[k]);
	else printf("0");
	//printf("%d\n",cnt[sum]);
	return 0;
}
