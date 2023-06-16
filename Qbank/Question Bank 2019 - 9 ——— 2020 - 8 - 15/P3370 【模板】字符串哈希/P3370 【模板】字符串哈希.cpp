# include <cstdio>
# include <algorithm>
# define LL unsigned long long
# define reg register

template<class T>  
inline LL Hash(const T *str)  
{  
    reg LL hash = 0;  
    while (LL ch = (LL)*str++)  {hash = hash * 131 + ch;}  
    return hash;
}  

int n,ans = 1;
LL a[10042];
char s[10042];

int main()
{
	scanf("%d",&n);
	
	for(reg int i = 1; i <= n; ++i){
		scanf("%s",s);
		a[i] = Hash(s);
	}
	
	std::sort(a + 1,a + n + 1);
	
	for(reg int i = 2; i <= n; ++i)
		if(a[i] != a[i - 1]) ++ans;
	
	printf("%d",ans);
	
	return 0;
}
