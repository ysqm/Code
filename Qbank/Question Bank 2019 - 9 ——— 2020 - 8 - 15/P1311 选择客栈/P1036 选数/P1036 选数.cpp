# include <cstdio>
# include <algorithm>
# include <cmath>
# define reg register
//using namespace std;

inline void in(int& x)
{
	x = 0; char ch = getchar();int f = 1;
	
	while(ch < '0' || ch > '9')/*{if(ch == '-') f = -1;*/ch = getchar();//}
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	x *= f;
}

inline bool check(const int& x)
{
	int xx = std::sqrt(x);
	
	for(int i = 2; i <= xx; ++i) if((x % i) == 0) return false;
	
	return true;
}

int n,k,num[42];

inline int dfs(const int left_num,const int now_sum,const int start)
{
	if(left_num){
		int sum = 0;
		
		for(reg int i = start; i <= n; ++i) sum += dfs(left_num - 1,now_sum + num[i],i + 1);
		
		return sum;
	}
	
	return check(now_sum);
}

int main()
{
	in(n);in(k);
	
	for(reg int i = 1; i <= n ; ++i) in(num[i]);
	
	printf("%d",dfs(k,0,1));
	
	return 0;
}
