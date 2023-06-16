# include <cstdio>
# include <cstring>
# define N 1000

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
int n,Case;
bool flag;

inline bool check(char* str)
{
	int p = 0,t;
		
	while(*str){
		if(child[p][t = *str - '0'] == 0) child[p][t] = ++tot;
		p = child[p][t];
		if(word[p] || pre[p] && (*(str + 1)) == 0) return 1;
		++pre[p];
		str++;
	}
	
	++word[p];
	
	return 0;
}

int main()
{
	
	while(~scanf("%s",ch)){
		if(ch[0] == '9'){
			if(flag) printf("Set %d is not immediately decodable\n", ++Case);
			else printf("Set %d is immediately decodable\n", ++Case);
			flag = 0;
			memset(child,0,sizeof child);
        	memset(pre,0,sizeof pre);
        	memset(word,0,sizeof word);
        	tot=0;
        	continue;
		}
		
		if(check(ch)) flag = 1;

	}
	
	return 0;
}
