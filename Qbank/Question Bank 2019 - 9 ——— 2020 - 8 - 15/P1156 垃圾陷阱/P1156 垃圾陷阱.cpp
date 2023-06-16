# include <cstdio>
# include <algorithm>
# include <cstring>
# define REG register
# define N 100
using namespace std;

typedef long long LL;

template <typename T>
inline void in(T& x)
{
	x = 0;char c = getchar();int f = 1;
	
	while(c < '0' || c > '9') {if(c == '-') f = -1;c = getchar();}
	
	while(c >= '0' && c <= '9'){x = (x << 3) + (x << 1) +c - 48;c = getchar();}
	
	x *= f;
	
	return ;
} 

//template <typename T>
inline int Read()
{
	int x = 0;char c = getchar();
	
	while(c < '0' || c > '9') c = getchar();
	
	while(c >= '0' && c <= '9'){x = (x << 3) + (x << 1) +c - 48;c = getchar();}
	
	return x;
}

int f[N + 42],D,G;

struct litter 
{
	int height,life,Time;
	
	inline bool operator < (const litter& b) const
	{
		return Time < b.Time;
	}
} ad[N + 42];

int main()
{
	in(D);in(G);
	
	for(REG int i = 1;i <= G; ++i){in(ad[i].Time);in(ad[i].life);in(ad[i].height);}
	
	sort(ad + 1,ad + G + 1);
	
	memset(f,-1,sizeof(f));
	
	f[0] = 10;
	
	for(REG int i = 1; i <= G ; ++i){
		for(REG int j = D; j >= 0 ; --j)
		if(f[j] >= ad[i].Time){
			if(j + ad[i].height >= D){
				printf("%d",ad[i].Time);
				return 0;
			}
			f[j + ad[i].height] = max(f[j],f[j + ad[i].height]);
			f[j] += ad[i].life;
		}
	}
	printf("%d",f[0]);
	
	return 0; 
}
