# include <cstdio>
# include <cstring>
# define N 500000
# define reg register

struct Trie
{
	int child[N + 42][2],pre[N + 42],word[N + 42],tot;
	
	Trie()
	{
		memset(child,0,sizeof child);
        memset(pre,0,sizeof pre);
        memset(word,0,sizeof word);
        tot=0;
	}
	
	inline int push(int* str)
	{
		int p = 0;
		
		while(*str != -1){
			if(child[p][*str] == 0) child[p][*str] = ++tot;
			p = child[p][*str];
			++pre[p];
			str++;
		}
		
		++word[p];
		
		return 0;
	}
	
	inline int find_word(int* str)
	{
		int p = 0;
		
		while(*str != -1){
			if(child[p][*str] == 0) return 0;
			p = child[p][*str];
			str++;
		}
		
		return word[p];
	}
	
	inline int find_prefix(int* str)//²éÕÒÇ°×º
	{
    	int p = 0,ans = 0;
		
		while(*str != -1){
			if(child[p][*str] == 0) return ans;
			ans += word[p = child[p][*str]];
			str++;
		}
		
		return ans + pre[p] - word[p];
	}
} T;

int m,n,s[10042];

int main()
{
	scanf("%d%d",&m,&n);
	
	for(reg int i = 1,l; i <= m;++i){
		scanf("%d",&l);
		
		for(reg int k = 0,kn; k < l; ++k){
			scanf("%d",&kn);
			s[k] = kn;}
		
		s[l] = -1;
			
		T.push(s);
	}
	
	for(reg int i = 1,l; i <= n;++i){
		scanf("%d",&l);
		
		for(reg int k = 0,kn; k < l; ++k){scanf("%d",&kn);s[k] = kn;}
		
		s[l] = -1;
			
		printf("%d\n",T.find_prefix(s));
	}
	
	return 0;
}
