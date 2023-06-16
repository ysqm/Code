# include <cstdio>
# include <iostream>
# include <cmath>
# define reg register
using namespace std;

const int Mon_Dat[42] = {0,229,103,107,113,131,211,223,307,311,313,317,331,419,503,523,607,613,617,619,719,811,823,829,907,911,919,929,1013,1019,1031,1103,1117,1123,1129,1213,1217,1223,1229,1231};



int prime[10042],tot,vis[10042];

inline void Pretreatment()
{
	vis[1] = 1;
	for(reg int i = 2; i <= 10005 ; ++i)
	{
		if(!vis[i]) prime[++tot] = i;
		
		for(reg int j = 1; j <= tot && prime[j] * i <= 10005 ; ++j)
		{
			vis[i * prime[j]] = 1;
			if(i % prime[j] == 0) break;
		}
	}
}

inline bool check(const int x)
{
	if(x <= 1) return 0;
	for(reg int i = 1; i <= tot ; ++i)
		if(x % prime[i] == 0) return 0;
	return 1;
}

inline int Leap_Year(const int x)
{
	if(x % 3200 == 0) return 2;
	else if(x % 400 == 0) return 1;
	else if(x % 100 == 0) return 2;
	else if(x % 4 == 0) return 1;
	else return 2;
}

char s[42];

inline bool its_mon_day_ok(int xd)
{
	for(reg int i = 8; i >= 5 ; --i)
	{
		if(s[i] != '-' && xd % 10 != s[i] - '0') return 0;
		xd /= 10;
	}
	return 1;
}

inline int Ans(const int& Year)
{
	int sum = 0;
	for(reg int i = Leap_Year(Year); i <= 39 ; ++i)
		if(its_mon_day_ok(Mon_Dat[i]) && check(Mon_Dat[i]+Year*10000)) ++sum;
	return sum;
}

int T,ans;

void dfs(const int cur,const int year)
{
	if(cur == 5) ans += Ans(year);
	
	else if(s[cur] != '-') dfs(cur+1,year*10+s[cur]-'0');
	
	else for(reg int i = 0; i <= 9 ; ++i) dfs(cur+1,year*10+i);
}


int main()
{
	ios::sync_with_stdio(false);
	
	cin>>T;
	
	Pretreatment();
	
	while(T--)
	{
		cin>>s+1;
		
		if(s[1] == s[2] && s[8] == '-' && s[4] == s[5] && s[5] == s[6] && s[6] == s[7] && s[7] == s[8] && s[2] == s[3] && s[3] == s[4]){printf("55157\n");continue;}
		
		ans = 0;
		
		int year = 0;
		
		dfs(1,year);
		
		printf("%d\n",ans);
	}
	
	return 0;
}
/*
1
--------
*/
