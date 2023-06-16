# include <cstdio>
//# include <algorithm>
//# include <cmath>
# include <cstring>
//# define check(x) Is_Prime(x)
# define N 30000
# define reg register

/*inline bool Is_Prime(int x)
{
	x = sqrt(x) + 1;
	for(reg int i = 2; i <= x ; ++i)
		if(x % i == 0) return false;
	return true;
}*/

bool vis[N + 42];
int pipe[N + 42],Cell,cell[N + 42],tot,prime[N + 42],n,m1,m2,ans = 0x7f7f7f7f;

inline int Max(const int& a,const int b){return a > b ? a : b;}

int main()
{
	for(reg int i = 2; i <= N; ++i){
		if(!vis[i]) prime[++tot] = i;
		
		for(reg int j = 1; i * prime[j] <= N && j <= tot; ++j){
			vis[i * prime[j]] = 1;
			if(i % prime[j] == 0) break;
		}
	}
	
	scanf("%d%d%d",&n,&m1,&m2);
	
	for(reg int i = 1; m1 != 1 ; ++i)
		while(m1 % prime[i] == 0){
			pipe[i] += m2;
			m1 /= prime[i];
		}
	
	for(reg int i = 1; i <= n; ++i){
		scanf("%d",&Cell);
		
		reg int now = 0;
		reg bool f = true;
		
		memset(cell,0,sizeof(cell));
		
		for(reg int j = 1; j <= tot ; ++j)
			while(Cell % prime[j] == 0){
			++cell[j];
			Cell /= prime[j];
			}
		
		for(reg int j = 1; j <= tot ; ++j)
			if(pipe[j] != 0 && cell[j] != 0)
				if(pipe[j] % cell[j] == 0) now = Max(now,pipe[j] / cell[j]);
				else now = Max(now,pipe[j] / cell[j] + 1);
			else if(pipe[j] != 0){f = false;break;}
			
		if(f && now < ans)ans = now;
	}
	
	if(ans != 0x7f7f7f7f) printf("%d\n",ans);
	else puts("-1");
	
	return 0;
}
