# include <cstdio>
# include <queue>
# define N 30000

struct Trie
{
	int trie[(N << 2) + 42][2],fail[N + 42],tot;
	bool val[N + 42],vis[N + 42],ins[N + 42],flag;
	std::queue <int> q;
	
	inline void push(char *str)
	{
		register int p = 0,v;
		
		while(*str){
			if(trie[p][v = *str - '0'] == 0) trie[p][v] = ++tot;
			p = trie[p][v];++str;
		}
		
		val[p] = 1;
    }
    
    inline void build()
	{
		
        if(trie[0][0]) q.push(trie[0][0]);
        if(trie[0][1]) q.push(trie[0][1]);
        
        while(q.size()){
            int u = q.front();q.pop();
            
            for(register int i = 0 ; i <= 1 ; ++i)
            	if(trie[u][i])
				{
					fail[trie[u][i]] = trie[fail[u]][i];
					val[trie[u][i]] |= val[trie[fail[u]][i]];
					q.push(trie[u][i]);
				}
           		else trie[u][i] = trie[fail[u]][i];
        }
    }
    
    inline void query(const int u)
	{
        if(ins[u] || flag){flag = true;return;}
        
    	if(vis[u] || val[u]) return;
    	
    	vis[u] = ins[u] = 1;
    	
    	/*if(trie[u][0])*/query(trie[u][0]);
    	if(trie[u][1])query(trie[u][1]);
    	
    	ins[u] = 0;

    }
} T;

int n;
char s[30042];

int main()
{
	//freopen("P2444_2.in","r",stdin);
	
	scanf("%d",&n);T.flag = false;
	
	for(register int i = 1; i <= n; ++i){scanf("%s",s);T.push(s);}
	
	T.query(0);
	
	if(T.flag) printf("TAK\n");
	else printf("NIE\n");
	
	return 0;
}
