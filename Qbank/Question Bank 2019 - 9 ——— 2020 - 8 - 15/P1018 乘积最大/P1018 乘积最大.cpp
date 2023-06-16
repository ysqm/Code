# include <cstdio>
# include <algorithm>
# include <cstring>
# define digit 50
# define REG register
# define N 40
using namespace std;

struct INT
{
	int data[digit],len;
	
	INT(){memset(data,0,sizeof(data));len = 1;}
	
	void clear(){memset(data,0,sizeof(data));len = 1;}
	
	bool operator < (const INT B) const 
	{
		if(len > B.len) return false;
			if(len < B.len) return true;
			else for(REG int i = B.len; i > 0 ; --i)
					if(data[i] < B.data[i]) return true;
					 else if(data[i] > B.data[i]) return false;
		return false;
	}
	
	INT operator * (const INT B) const 
	{
		INT D;D.clear();D.len = B.len + len - 1;
		for(REG int i = len,j; i ; --i){
			for(j = B.len; j ; --j)
				D.data[i + j - 1] += B.data[j] * data[i];
			for(++j; D.data[j + 1] ||j <=D.len ; ++j)
				if(D.data[j] >= 10){
					D.data[j + 1] += D.data[j]/10;
					D.data[j] %= 10;
					D.len = max(j + 1,D.len);
				}
		}
		while(D.data[D.len + 1]) ++D.len;
		while(D.data[D.len] == 0 && D.len > 1) --D.len;
		return D;
	}
	
	void print()
	{
		for(REG int i = len; i ; --i)
			printf("%01d",data[i]);
		printf(" ");
	}
} dp[N + 42][N + 42][10];

char s[N + 42];

int n,KN;

/*inline void show(int m)
{
	printf("Ìí¼ÓµÚ%d¸ö³ËºÅ:\n",m);
	for(REG int L = 1; L <= n ; ++L){
		for(REG int R = L; R <= n ; ++R)
			dp[L][R][m].print();
		printf("\n");
	}
		
	printf("\n\n");
}*/

int main()
{
	scanf("%d%d%s",&n,&KN,s + 1);
	
	for(REG int L = 1; L <= n ; ++L)
		for(REG int R = L; R <= n ; ++R){
			dp[L][R][0].len = R - L + 1;
			for(REG int i = L; i <= R; ++i)
				dp[L][R][0].data[R - i + 1] = s[i] - '0';
		}
	//show(0);
	for(REG int m = 1; m <= KN ; ++m){
		for(int len = 2; len <= n ; ++len)
			for(int L = 1; L + len - 1 <= n ; ++L){
				int R = L + len - 1;
					for(int k = m;k < R; ++k)
						dp[L][R][m] = max(dp[L][R][m],dp[L][k][m - 1] * dp[k + 1][R][0]);
			}
		
		//show(m);
	}
	
	/*char buf[10000];
	
	INT a,b;
	
	while(1)
	{
		memset(buf,0,sizeof(buf));
		scanf("%s",buf);
		for(int len = strlen(buf) - 1; len >= 0 ; --len)a.data[a.len++] = buf[len] - 48;
		--a.len;
		memset(buf,0,sizeof(buf));
		scanf("%s",buf);
		for(int len = strlen(buf) - 1; len >= 0 ; --len)b.data[b.len++] = buf[len] - 48;
		--b.len;
		a = a * b;
		a.print();
		a.clear();b.clear();
	}*/
		
	dp[1][n][KN].print();
	return 0;
}
