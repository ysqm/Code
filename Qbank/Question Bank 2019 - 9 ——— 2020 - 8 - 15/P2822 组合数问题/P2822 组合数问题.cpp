# include <cstdio>
# define reg register

int Cn[2005][2005],s[2005][2005],t,k,n,m;

int main()
{
	Cn[1][1] = 1;
	
	scanf("%d%d",&t,&k);
	
	for(reg int i = 0; i <= 2000; ++i) Cn[i][0] = 1;
	
	for(reg int i = 2; i <= 2000; ++i)
		for(reg int j = 1; j <= i; ++j)
		Cn[i][j] = (Cn[i - 1][j] + Cn[i - 1][j - 1]) % k;
		
	for(reg int i = 2; i <= 2000; ++i){
		for(reg int j = 1; j <= i; ++j){
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
			if(Cn[i][j] == 0) ++s[i][j];
		}
		s[i][i + 1] = s[i][i];	
	}
	
	while(t--){
		scanf("%d%d",&n,&m);
		if(m > n) printf("%d\n",s[n][n]);
		else printf("%d\n",s[n][m]);
	}

	return 0;
}
