# include <cstdio>
# include <cstring>
# include <queue>
# define N 500000

int qa[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,2,0,0,0,3,0,0,0};

struct ACA
{
	int trie[(N << 2) + 42][4],fail[N + 42],tot;
	bool val[N + 42];
	std::queue <int> q;
	
	inline void push(char *str)
	{
		int p = 0,v;
		
		while(*str){
			if(trie[p][v = qa[*str - 'A']] == 0) trie[p][v] = ++tot;
			p = trie[p][v];++str;
		}
		
		//++val[p];
    }
    
    inline void build()
	{
		
        for(register int i = 0 ; i < 4 ; i++)if(trie[0][i]){fail[trie[0][i]] = 0;q.push(trie[0][i]);}
        
        while(q.size()){
            int u = q.front();q.pop();
            
            for(register int i = 0 ; i < 4 ; i++)
            	if(trie[u][i]){fail[trie[u][i]] = trie[fail[u]][i];q.push(trie[u][i]);}
           		else trie[u][i] = trie[fail[u]][i];
        }
    }
    
    inline void query(char *str)
	{
        int p = 0;
        
        while(*str){
        	p = trie[p][qa[*str - 'A']];
        	
        	for(register int j = p; j ;j = fail[j]) val[j] = true;
        	
        	++str;
		}
        return ;
    }
	
	inline int answer(char *str)
	{
        char* temp = str;
		int p = 0,ans = -1;
        
        while(*str){
        	p = trie[p][qa[*str - 'A']];
        	
        	if(val[p]) ans = str - temp;
        	
        	++str;
		}
        return ans + 1;
    }
	
} AC;

int n,m;
char ch[100042][142],s[10000042];

int main()
{
	scanf("%d%d",&n,&m);
	
	scanf("%s",s);
	
	for(register int i = 1 ;  i <= m ; i ++ ){scanf("%s",ch[i]);AC.push(ch[i]);}
	
	AC.build();
	
	AC.query(s);
	
	for(register int i = 1; i <= m ; i ++) printf("%d\n",AC.answer(ch[i]));
	
	return 0;
}
