# include <cstdio>
# define reg register
# define N 1000000

int nxt[N + 42],lp,ls;
char p[N + 42],s[N + 42];

inline int Sl(char* S)
{
	char* ph = S;
	while(*ph) ++ph;
	
	return ph - S;
}

int main()
{
	scanf("%s%s",s,p);
	
	lp = Sl(p);ls = Sl(s);
	
	reg int i = 0,j = -1;nxt[0] = -1;
	
	while(i < lp)
		if(j == -1 || p[i] == p[j]){
			++i;++j;
			nxt[i] = j;
		}
		else j = nxt[j];
		
	i = 0;j = 0;
	
	while(i < ls){
		if(j == -1 || s[i] == p[j]){
			++i;
			++j;
		}
		else j = nxt[j];
		if(j == lp){printf("%d\n",i - lp + 1);j = nxt[j];}
	}
	
	for(reg int k = 1; k <= lp; ++k) 
		printf("%d ",nxt[k]);
	
	return 0;
}
