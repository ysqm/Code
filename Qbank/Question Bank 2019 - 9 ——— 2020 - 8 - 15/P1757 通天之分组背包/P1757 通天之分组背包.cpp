# include <cstdio>
# include <algorithm>
# define REG register
# define N 1000
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

int n;

struct GROUP
{
	int wi,value;
	GROUP(){wi = 0;value = 0;}
} gr[101][N + 42];

int f[N + 42],T,m;

int main()
{
	in(m);in(n);
	
	for(int i = 1,a,b,c; i <= n; ++i){
		in(a);in(b);in(c);
		gr[c][++gr[c][0].value].wi = a;
		gr[c][gr[c][0].value].value = b;
		T = max(c,T);
	}
	
	for(REG int t = 1; t <= T ; ++t)
		for(REG int j = N; j ; --j)
			for(REG int i = 1; i <= gr[t][0].value ; ++i)
				if(j - gr[t][i].wi >= 0) f[j] = max(f[j],f[j - gr[t][i].wi] + gr[t][i].value);
	
	printf("%d",f[m]);
	
	return 0;
}
