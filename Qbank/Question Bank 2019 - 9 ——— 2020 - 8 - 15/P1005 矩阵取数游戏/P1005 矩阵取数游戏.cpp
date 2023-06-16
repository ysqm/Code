# include <cstdio>
# include <algorithm>
# include <cstring>
# define digit 500
# define REG register
# define N 40
using namespace std;

template <typename T>
inline void in(T& x)
{
	x = 0;char c = getchar();int f = 1;
	
	while(c < '0' || c > '9') {if(c == '-') f = -1;c = getchar();}
	
	while(c >= '0' && c <= '9'){x = (x << 3) + (x << 1) +c - 48;c = getchar();}
	
	x *= f;
	
	return ;
} 

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
	
	INT operator * (const INT& B) const 
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
	
	INT operator * (const int& B) const 
	{
		INT D;D.clear();D.len = len + 1;
		for(REG int i = len; i ; --i) D.data[i] += B * data[i];
		for(REG int j = 1; D.data[j + 1] ||j <=D.len ; ++j)
			if(D.data[j] >= 10){
				D.data[j + 1] += D.data[j]/10;
				D.data[j] %= 10;
				D.len = max(j + 1,D.len);
			}
		while(D.data[D.len + 1]) ++D.len;
		while(D.data[D.len] == 0 && D.len > 1) --D.len;
		return D;
	}
	
	INT operator + (const INT& B) const  
	{
		INT D;D.clear();D.len = max(len,B.len);;
		REG int i = 1;
		for(; i <= D.len; ++i)
			D.data[i] = B.data[i] + data[i];
		for(i = 1; i <= D.len; ++i)
			if(D.data[i] >= 10) D.data[i + 1]++,D.data[i] -= 10;
		if(D.data[D.len + 1]) ++D.len;
		return D;
	}
	
	void print()
	{
		for(REG int i = len; i ; --i)
			printf("%01d",data[i]);
		printf(" ");
	}
} dp[N + 42][N + 42],base[N + 42],ans;

int n,m,tmp,tp[N + 42];

void INIT()
{
	base[0].data[1] = 1;
	for(REG int i = 1; i <= m + 1; ++i)
		base[i] = base[i - 1] * 2;
}

int main()
{
	in(n);in(m);
	INIT();
	
	while(n--){
		for (REG int i = 1; i <= m; i++)
            for (REG int j = m; j >= i; j--)
            	dp[i][j].clear();
		for(REG int i = 1; i <= m; ++i) in(tp[i]);
		for (REG int i = 1; i <= m; i++)
            for (REG int j = m; j >= i; j--) { 
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + base[m - j + i - 1] * tp[i - 1]); 
                dp[i][j] = max(dp[i][j], dp[i][j + 1] + base[m - j + i - 1] * tp[j + 1]);
            } 
        INT Max;
        for (int i = 1; i <= m; i++)
            Max = max(Max, dp[i][i] + base[m] * tp[i]);
        ans = ans + Max;
	}
	
	ans.print();
	return 0;
}
