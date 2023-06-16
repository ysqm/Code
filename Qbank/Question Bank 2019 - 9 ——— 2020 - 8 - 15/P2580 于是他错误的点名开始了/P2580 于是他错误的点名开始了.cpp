# include <cstdio>
# include <cstring>
# define N 1000000

struct Trie
{
	int child[N + 42][10],pre[N + 42],word[N + 42],tot;
	bool val[N + 42];
	
	Trie()
	{
		memset(child,0,sizeof child);
        memset(pre,0,sizeof pre);
        memset(word,0,sizeof word);
        tot=0;
	}
	
	inline int push(char* str)
	{
		int p = 0,t;
		
		while(*str){
			if(child[p][t = *str - 'a'] == 0) child[p][t] = ++tot;
			p = child[p][t];
			++pre[p];
			str++;
		}
		
		++word[p];
		
		return 0;
	}
	
	inline int find_word(char* str)
	{
		int p = 0,t;
		
		while(*str){
			if(child[p][t = *str - 'a'] == 0) return 0;
			p = child[p][t];
			str++;
		}
		
		if(!val[p]){
			val[p] = 1;return 1;
		}
		
		return 2;
	}
	
	inline int find_prefix(char* str)//查找前缀
	{
    	int p = 0,t;
		
		while(*str){
			if(child[p][t = *str - 'a'] == 0) return 0;
			p = child[p][t];
			str++;
		}
		
		return pre[p]; //遍历完，返回前缀出现的次数 
	}
} T;

int n;
char ch[70];

int main()
{
	scanf("%d",&n);
	
	for(register int i = 1; i <= n; ++i){
		scanf("%s",ch);
		T.push(ch);
	}
	
	scanf("%d",&n);
	
	for(register int i = 1; i <= n; ++i){
		scanf("%s",ch);
		switch(T.find_word(ch)){
								case 0 :
										puts("WRONG");
										break;
								case 1 :
										puts("OK");
										break;
								case 2 :
										puts("REPEAT");
										break;
		}
	}
	
	return 0;
}
