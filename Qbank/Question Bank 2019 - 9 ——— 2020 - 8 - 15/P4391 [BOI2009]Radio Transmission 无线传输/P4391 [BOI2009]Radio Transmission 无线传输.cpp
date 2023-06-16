# include <cstdio>
# define reg register
# define N 1000000

int nxt[N + 42],lp,ls,s;
char p[N + 42];

inline int Sl(char* S)
{
	char* ph = S;
	while(*ph) ++ph;
	
	return ph - S;
}

int main()
{
	scanf("%d%s",&s,p);
	
	lp = Sl(p);
	
	reg int i = 0,j = -1;nxt[0] = -1;
	
	while(i < lp)
		if(j == -1 || p[i] == p[j]){
			++i;++j;
			nxt[i] = j;
		}
		else j = nxt[j];
		
	printf("%d",s - nxt[s]);
	
	return 0;
}
