# include <cstdio>
# include <cstring>
# define reg register
# define Gc getchar()//*/(SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
char BB[1<<15],*SS=BB,*TT=BB;

inline int Read()
{
	register int x = 0;register char ch = Gc;
	
	while(ch < '0' || ch > '9') ch = Gc;
	
	while(ch <= '9' && ch >= '0'){x = x*10 + (ch^48);ch = Gc;}
	
	return x;
}

inline int Min(const int a,const int b){return a < b ? a : b;}

char s1[2005],s2[2005];
int dp[2005][2005],l1,l2;

int main()
{
	scanf("%s\n%s",s1+1,s2+1);
	
	/*reg int l = 1,r = 2000,mid;
	
	while(l < r)
	{
		mid = (l+r)>>1;
		
		if(s1[mid]) l = mid+1;
		else r = mid;
	}
	
	l1 = l-1;
	
	l = 1;r = 2000;
	
	while(l < r)
	{
		mid = (l+r)>>1;
		
		if(s2[mid]) l = mid+1;
		else r = mid;
	}
	
	l2 = l-1;*/
	
	l1 = std::strlen(s1+1);
	l2 = std::strlen(s2+1);
	
	for(reg int i = 1; i <= l1 ; ++i) dp[i][0] = i;
	
	for(reg int i = 1; i <= l2 ; ++i) dp[0][i] = i;
	
	for(reg int i = 1; i <= l1 ; ++i)
		for(reg int j = 1; j <= l2 ; ++j)
			if(s1[i] == s2[j]) dp[i][j] = dp[i-1][j-1];
			else dp[i][j] = Min(dp[i-1][j],Min(dp[i][j-1],dp[i-1][j-1])) + 1;
	
	printf("%d",dp[l1][l2]);
	
	return 0;
}


