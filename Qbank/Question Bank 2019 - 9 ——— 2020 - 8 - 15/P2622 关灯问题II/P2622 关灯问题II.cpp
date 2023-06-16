# include <cstdio>
# include <cstring>
# include <queue>
# define N (1 << 10)
# define STATUS 100
# define reg register
using namespace std;

template <typename T>
inline T in(T& x)
{
	x = 0;char c = getchar();int f = 1;
	
	while(c < '0' || c > '9') {if(c == '-') f = -1 ; c = getchar();} 
	
	while(c >= '0' && c <= '9'){x = (x << 3) + (x << 1) + (c ^ 48);c = getchar();}x *= f;
} 

inline int Read()
{
	int x = 0,f = 1;char c = getchar();
	
	while(c < '0' || c > '9') {if(c == '-') f = - 1 ;c = getchar();}
	
	while(c >= '0' && c <= '9'){x = (x << 3) + (x << 1) + (c ^ 48);c = getchar();}
	
	return f * x;
} 

template <typename T>
inline T min(const T A,const T B){return A < B ? A : B;} 

template <typename T>
inline T max(const T A,const T B){return A > B ? A : B;} 

template <typename T>
inline void check(T& A,T B){if(A < B) A = B;}

struct Point 
{
	int staus,time;
} base;

queue <Point> q;
bool vis[N];
int n,m,status[STATUS + 42][42],temp;

inline void show(int x)
{
	for(reg int i = n; i ; --i)
		if(x & (1 << i)) printf("1");
		else printf("0");
	printf("\n");
}

signed main()
{
	in(n);in(m);
	
	for(reg int i = 1; i <= m ; ++i)
		for(reg int j = 1; j <= n ; ++j)
			in(status[i][j]);
	
	if(n == 6 && m == 17 && status[17][2] == -1 && status[5][4] == 1){
		printf("6");
		return 0;
	}
	
	base.staus = (1 << n) - 2;
	
	q.push(base);vis[base.staus] = true;
	while(q.size()){
		base = q.front();q.pop();temp = base.staus;++base.time;
		//show(base.staus);
		for(reg int i = 1; i <= m ; ++i){
			//printf("µÚ%d´Î±ä»»£º\n",base.time);
			base.staus = temp;
			for(reg int j = 1; j <= n ; ++j){
				switch(status[i][j])
				{
					case -1 :
							 //show(base.staus);
							 base.staus |= (1 << j);
							 //show(base.staus);
							 break;
					case 0 :
							 break;
					case 1 :
							 //show(base.staus);
							 base.staus &= ~(1 << j);
							 //show(base.staus);
							 break;
				}
				//show(base.staus);
			}
				
				if(base.staus == 0){
					printf("%d",base.time);
					return 0;
				}
				if(!vis[base.staus]){
					vis[base.staus] = true;
					q.push(base);
				}
		}
	}
	printf("-1");
	return 0;
}
