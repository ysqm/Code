# include <cstdio>
# include <cstring>
# define N 100000

/*struct Trie
{
	int child[N + 42][10],pre[N + 42],word[N + 42],tot;
	
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
			if(child[p][t = *str - '0'] == 0) child[p][t] = ++tot;
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
			if(child[p][t = *str - '0'] == 0) return 0;
			p = child[p][t];
			str++;
		}
		
		return word[p];
	}
	
	inline int find_prefix(char* str)//查找前缀
	{
    	int p = 0,t;
		
		while(*str){
			if(child[p][t = *str - '0'] == 0) return 0;
			p = child[p][t];
			str++;
		}
		
		return pre[p]; //遍历完，返回前缀出现的次数 
	}
} T;*/

int child[N + 42][10],pre[N + 42],word[N + 42],tot;
char ch[20];
int tp,n;
bool flag;

inline bool check(char* str)
{
	int p = 0,t;
		
	while(*str){
		if(child[p][t = *str - '0'] == 0) child[p][t] = ++tot;
		p = child[p][t];
		if(pre[p] && (*(str + 1)) == 0) return 1;
		++pre[p];
		if(word[p]) return 1;
		str++;
	}
	
	++word[p];
	
	return 0;
}

int main()
{
	scanf("%d",&tp);
	
	while(tp--){
		flag = 0;
		memset(child,0,sizeof child);
        memset(pre,0,sizeof pre);
        memset(word,0,sizeof word);
        tot=0;
		scanf("%d",&n);
		
		for(register int i = 1; i <= n; ++i){
			scanf("%s",ch);
			if(check(ch)) flag = 1;
		}
		
		if(flag) puts("NO");
		else puts("YES");
	}
	
	return 0;
}
