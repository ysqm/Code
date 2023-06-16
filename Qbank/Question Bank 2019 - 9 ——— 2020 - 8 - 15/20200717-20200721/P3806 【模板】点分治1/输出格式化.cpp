# include <cstdio>
# include <algorithm>
# define N 10000
# define reg register

char s[42];
int tp = 0; 

int main()
{
	freopen("P3806_3.out","r",stdin);
	freopen("∏Ò ΩªØP3806_3.out","w",stdout);
	
	while(tp < 50)
	{
		scanf("%s",s+1);
		printf("case %d: %c%c%c\n",++tp,s[1],s[2],s[3]);
	}
			
	return 0;
} 
