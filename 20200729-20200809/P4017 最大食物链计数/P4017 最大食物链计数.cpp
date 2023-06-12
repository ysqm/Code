# include <cstdio>
# include <vector>
# include <queue>
# define reg register
# define Gc getchar()//(SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
char BB[1<<15],*SS=BB,*TT=BB;

inline int Read()
{
	register int x = 0,f=1;register char ch = Gc;
	
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1;ch = Gc;}
	
	while(ch <= '9' && ch >= '0'){x = x*10 + (ch^48);ch = Gc;}
	
	return f < 0 ? -x : x;
}

std::vector<int> G[5005];
std::queue<int> q;

int n,m,indegree[5005],outdegree[5005],dp[5005],ans,cnt,st[5005];

inline int Mod(const int x){return x < 80112002 ? x : x - 80112002;}

inline void Tuopu(const int S)
{ 
	q.push(S);
	
	dp[S] = 1;
	
	while(q.size())
	{
		int u = q.front();q.pop();
		
		for(reg int i = 0; i < G[u].size() ; ++i)
		{
			--indegree[G[u][i]];
			
			dp[G[u][i]] = Mod(dp[G[u][i]] + dp[u]);
			
			if(outdegree[G[u][i]] && indegree[G[u][i]] == 0) q.push(G[u][i]);
		}
	}
}

int main()
{
	n = Read();m = Read();
	
	for(reg int i = 1,x,y; i <= m ; ++i)
	{
		++outdegree[x = Read()];++indegree[y = Read()];
		
		G[x].push_back(y);
	}
	
	for(reg int i = 1; i <= n ; ++i) if(indegree[i] == 0) st[++cnt] = i;
	
	for(reg int i = 1;  i<= cnt ; ++i) Tuopu(st[i]);
	
	for(reg int i = 1; i <= n ; ++i) if(outdegree[i] == 0) ans = Mod(ans+dp[i]);//*/printf("%d ",dp[i]);
	
	printf("%d",ans);
	
	return 0;
}


