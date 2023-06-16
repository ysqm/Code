# include<bits/stdc++.h>
# define N 100
# define R register
using namespace std;
inline int re()
{
	int f = 1,x = 0;
	char c = getchar();
	
	while(c < '0' || c > '9'){
		if(c == '-') f = -1;
		c = getchar();
	}
	
	while(c >= '0' && c <= '9'){
		x = x * 10 + c - '0';
		c = getchar();
	}
	
	return x * f;
}

int s,t;

bool vis[N + 42];
bool g[N + 42][N + 42];
int n;

inline bool dfs(int k,int cx)
{
	if(k == t) return 1;
	
	vis[k] = 1;
	
	for(R int i = 1;i <= n;i++)
		if(g[k][i] && i != cx && !vis[i])
			if(dfs(i,cx)) return 1;
	return 0;
}
int main()
{	
	n = re();
	
	
	int a,b;
	while(1){
		a = re();
		b = re(); 
		g[a][b] = g[b][a] = true;
		if(a == 0) break;
	}
	
	s = re();
	t = re();
	
	for(R int i = 1;i <= n;i++){
		if(i == s || i == t) continue;
		if(!dfs(s,i)) {
			
			printf("%d",i);
			
			return 0;
			
		}
		memset(vis,0,sizeof(vis));
	}
	
	puts("No solution");
	
	return 0;
}
