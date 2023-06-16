# include <cstdio>
# include <cstring>
# include <queue>
# define N 500000

struct ACA
{
	int trie[N + 42][26],val[N + 42],fail[N + 42],tot;
	std::queue <int> q;
	
	inline void push(char *str)
	{
		int p = 0,v;
		
		while(*str){
			if(trie[p][v = *str - 'a'] == 0) trie[p][v] = ++tot;
			p = trie[p][v];++str;
		}
		
		++val[p];
    }
    
    inline void build()
	{
		
        for(register int i = 0 ; i < 26 ; i++)if(trie[0][i]){fail[trie[0][i]] = 0;q.push(trie[0][i]);}
        
        while(q.size()){
            int u = q.front();q.pop();
            
            for(register int i = 0 ; i < 26 ; i++)
            	if(trie[u][i]){fail[trie[u][i]] = trie[fail[u]][i];q.push(trie[u][i]);}
           		else trie[u][i] = trie[fail[u]][i];
        }
    }
    
    inline int query(char *str)
	{
        int p = 0,ans = 0;
        
        while(*str){
        	p = trie[p][*str - 'a'];
        	
        	for(register int j = p; j && ~val[j];j = fail[j]) {ans += val[j];val[j] = -1;}
        	
        	++str;
		}
        return ans;
    }
	
} AC;

int n;
char ch[1000042];

int main()
{
	scanf("%d",&n);
	
	for(register int i = 1; i <= n ; ++i){scanf("%s",ch);AC.push(ch);}
	
	AC.build();
	
	scanf("%s",ch);
	
	printf("%d\n",AC.query(ch));
	
	return 0;
}
