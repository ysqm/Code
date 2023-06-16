# include <cstdio>
# define reg register

int n,m,p,q,s[125042],top;
bool vis[125042],flag;

int main()
{
	scanf("%d%d",&n,&m);
	
	for(reg int i = 0 ; i <= m ; ++i)
		for(reg int j = 0 ; j <= m ; ++j)	
			vis[i * i + j * j] = 1;
			
	for(reg int i = 0 ; i <= 125000 ; ++i) if(vis[i]) s[++top] = i;
	
	for(reg int b = 1; b < s[top] ; ++b)
		for(reg int i = 1; i < top - 1; ++i){
			
			if(s[i] + (n - 1) * b > s[top]) break;
			
			for(reg int a = 2 ; a <= n ; ++a){
				
				if(!vis[s[i] + (a - 1) * b]) break;
				
    			if(a == n){printf("%d %d\n",s[i],b);flag = 1;}
				
			}
		}
	
    if(!flag) puts("NONE"); 
	
	return 0;
}
