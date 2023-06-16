/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
=======`-.____`-.___\_____/___.-`____.-'=======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  	 Buddha said:
         	 	 The program have no BUG.
         	 	 The program can pass the text.	 	 
*/
# include <cstdio>
# define N 500000
# define LL long long
# define reg register
# define INF 0x7f7f7f7f

inline int Read()
{
	int x = 0;char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch <= '9' && ch >= '0'){x = x*10 + (ch^48);ch = getchar();}
	
	return x;
}

struct edge
{
	int next,to;
} e[N + 42];

char s[N + 42];
int head[N + 42],n,father[N + 42],Stack[N + 42],top,tot_edge;
LL Ans[N + 42],Add[N + 42],ans;

inline void add_edge(const int u,const int v)
{
	e[++tot_edge] = (edge){head[u],v};
	
	head[u] = tot_edge;
}

void dfs(const int u)
{
	int t = 0;
	
	if(s[u] == ')'){if(top) Add[u] = Add[father[t = Stack[top--]]] + 1;}
		
	else if(s[u] == '(') 
		Stack[++top] = u; 
	
	Ans[u] = Ans[father[u]] + Add[u];
	
	for(reg int i = head[u]; i ;i = e[i].next) dfs(e[i].to);
		
	if(t) Stack[++top] = t;
	
	else if(top) --top; 
}

int main()
{
	scanf("%d%s",&n,s + 1);

	for(reg int i = 2; i <= n; ++i) add_edge(father[i] = Read(),i);
	
	dfs(1);
	
	for(reg int i = 1; i <= n; ++i) ans ^= Ans[i] * i;
	
	printf("%lld\n",ans);

	return 0;	
}
