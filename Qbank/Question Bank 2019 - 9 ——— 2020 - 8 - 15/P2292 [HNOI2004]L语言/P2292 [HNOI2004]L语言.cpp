# include <cstdio>
# include <cstring>
# define N 1050000

inline int Max(const int& a,const int b){return a > b ? a : b;}

bool mark[N + 42];

struct Trie
{
	int child[N + 42][26],/*pre[N + 42],*/tot;
	bool word[N + 42];
	
	Trie()
	{
		memset(child,0,sizeof child);
        //memset(pre,0,sizeof pre);
        memset(word,0,sizeof word);
        tot=0;
	}
	
	inline int push(char* str)
	{
		int p = 0,t;
		
		while(*str){
			if(child[p][t = *str - 'a'] == 0) child[p][t] = ++tot;
			p = child[p][t];
			//++pre[p];
			str++;
		}
		
		word[p] = 1;
		
		return 0;
	}
	
	inline void dfs(char *str)
	{
		memset(mark,0,sizeof(mark));
		
		int p = 0,ans = -1,v;
		
		for(register char *s = str; *s ; ++s)
			if((p = child[p][v = *s - 'a']) == 0) break;
			else if(word[p]) mark[s - str] = 1;
			
		for(register char *i = str; *i ; ++i)
    	{
        	if(!mark[i - str])continue; 
			else ans = i - str;
			
        	p = 0;
        	
        	for(register char *s = i + 1; *s ; ++s)
				if((p = child[p][v = *s - 'a']) == 0) break;
				else if(word[p]) mark[s - str] = 1;
   		}
    	printf("%d\n",ans + 1);
	}
} T;

int n,m;
char ch[N + 42];

int main()
{
	scanf("%d%d",&n,&m);
	
	for(register int i = 1; i <= n; ++i){scanf("%s",ch);T.push(ch);}
	
	for(register int i = 1; i <= m; ++i){scanf("%s",ch);T.dfs(ch);}
	
	return 0;
}
