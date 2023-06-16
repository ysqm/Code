# include <cstdio>
# include <cstring>
# include <queue>
# define N 200000

int n,temp;
char s[2000042];

struct ACA
{
	int trie[N + 42][26],id[N + 42],fail[N + 42],tot,ans[N + 42];
	std::queue <int> q;
	
	inline void INIT()
	{
		memset(trie,0,sizeof(trie));
		memset(id,0,sizeof(id));
		memset(fail,0,sizeof(fail));
		memset(ans,0,sizeof(ans));
		tot = 0;
	}
	
	inline void push(char *str,int& vd)
	{
		int p = 0,v;
		
		while(*str){
			if(trie[p][v = *str - 'a'] == 0) trie[p][v] = ++tot;
			p = trie[p][v];++str;
		}
		
		id[p] = vd;
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
        int p = 0,an = 0;
        
        while(*str){
        	p = trie[p][*str - 'a'];
        	
        	for(register int j = p; j ;j = fail[j]) ++ans[id[j]];
        	
        	++str;
		}
		
		for(register int i = 1;i <= n;++i) an = an > ans[i] ? an : ans[i];
		
        return an;
    }
	
} AC;

int main()
{
	scanf("%d",&n); 
	
	AC.INIT();
		
	for(register int i = 1; i <= n ; ++i){scanf("%s",s);AC.push(s,i);}
	
	AC.build();
	
	scanf("%s",s);
	
	AC.query(s);
		
	for(register int i = 1; i <= n ; ++i) printf("%d\n",AC.ans[i]);
	
	return 0;
}
