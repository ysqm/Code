# include <cstdio>
# include <algorithm>
# include <cmath>
# define N 50000
# define M 50000
# define R register
using namespace std;
int r()
{
	int f = 1,x = 0;;
	
	char c = getchar();
	
	while(c > '9' || c < '0'){
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
	int to,from;
} e[M * 2 + 42];

int head[N + 42],n,cnt,size[N + 42],ans,num,T;

inline void add(const int v,const int u){e[++cnt].from = head[u];e[cnt].to = v;head[u] = cnt;e[++cnt].from = head[v];e[cnt].to = u;head[v] = cnt;}

void dfs(int u,int father)
{
	size[u] = 1;
	
	int maxson = 0;
	
	for(R int i = head[u]; i ; i = e[i].from)
		if(e[i].to != father){
			
			dfs(e[i].to,u);
			
			size[u] += size[e[i].to];
			
			maxson = max(maxson,size[e[i].to]);
			
		}
		
	maxson = max(maxson,n - size[u]);
	
	if(maxson <= ans){
		if(maxson < ans){
			ans = maxson;
			
			num = u;
			
			T = n + 1;
		}
		else if(u < num){
			T = num;
			
			num = u;
		}
		else T = u;
	}
	
	head[u] = 0;
}

int main()
{	
	n = r();
		
	cnt = 0;
	
	for(R int i = 1; i < n; i ++) add(r(),r());
	
	num = ans = n + 1;
	
	dfs(1,0);
	
	if(T == n + 1)printf("%d\n",num);
	else printf("%d %d\n",num,T);
	return 0;
}
