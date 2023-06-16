# include <cstdio>
# include <algorithm>
# include <cmath>
# include <cstring>
# define reg register
# define N 1000
//using namespace std;

inline void In(int& x)
{
	x = 0; char ch = getchar();int f = 1;
	
	while(ch < '0' || ch > '9')/*{if(ch == '-') f = -1;*/ch = getchar();//}
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	x *= f;
}

/*struct edge
{
	int from,to;
} e[N + 42];

int head[N + 42],e_cnt;

inline void add(int u,int v)
{
	e[++e_cnt].from = head[u];
	
	e[e_cnt].to = v;
	
	//e[e_cnt].wi = wi;
	
	head[u] = e_cnt;
}*/

struct QUEUE
{
	int Queue[N + 42],front,tail;
} q;

bool Now[N + 42],G[N + 42][N + 42];
int n,m,in[N + 42],tmp[N + 42],ans;

int main()
{
	In(n);In(m);
	
	for(reg int i = 1; i <= m ; ++i){
		In(tmp[0]);
		
		for(reg int i = 1; i <= tmp[0]; ++i){In(tmp[i]);Now[tmp[i]] = true;}
		
		for(reg int k = tmp[1]; k <= tmp[tmp[0]]; ++k)
			if(!Now[k]) 
				for(reg int j = 1; j <= tmp[0]; ++j)
					if(!G[k][tmp[j]]){
						G[k][tmp[j]] = true;
						in[tmp[j]]++;
					}
		
		memset(Now,0,sizeof(Now));
	}
	
	do
	{
		for(reg int i = 1;i <= n; ++i)
			if((in[i] == 0) && !Now[i]){
				q.Queue[++q.tail] = i;
				Now[i] = true;
			}
			
		for(;q.front <= q.tail; ++q.front)
			for(reg int i = 1; i <= n ; ++i)
				if(G[q.Queue[q.front]][i]) {--in[i];G[q.Queue[q.front]][i] = false;}
				//好气啊，if(G[q.Queue[q.front]][i]) {--in[i];G[q.Queue[q.front]][i] = false;} 写成了 if(G[q.front][i]) {--in[i];G[q.front][i] = false;} 改了一个多小时； 
		++ans;
	}while(q.front <= n);
	
	printf("%d",ans);
	
	return 0;
}
