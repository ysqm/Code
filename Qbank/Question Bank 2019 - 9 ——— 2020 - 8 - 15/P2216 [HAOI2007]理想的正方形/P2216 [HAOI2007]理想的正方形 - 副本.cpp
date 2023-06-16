# include <cstdio>
# include <algorithm>
# include <bitset>
# include <cstring>
# define reg register
# define N 1000
# define LL long long
using namespace std;

inline void in(int& x)
{
	/*x = 0;*/char ch = getchar();int f = 1;
	
	while(ch < '0' || ch > '9'){if(ch == '-') f = -1;ch = getchar();}
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	x *= f;
}

inline int Max(const int& a,const int b){return a > b ? a : b;}
inline int Min(const int& a,const int b){return a < b ? a : b;}

int a,b,n,q[N + 42],Q[N + 42],an[N + 42][N + 42],ans =0x7f7f7f7f;
int x[N + 42][N + 42],y[N + 42][N + 42];
int X[N + 42][N + 42],Y[N + 42][N + 42];

int main()
{
	in(a);in(b);in(n);
	
	for(reg int i = 1; i <= a; ++i)//{
		//q[1] = Q[1] = 1;
		for(reg int j = 1,h = 1,t = 0,H = 1,T = 0;j <= b; ++j){
			in(an[i][j]);
			while(j - q[h] >= n) ++h;
			while(j - Q[H] >= n) ++H;
			while(h <= t && an[i][j] <= an[i][q[t]]) --t;
			while(H <= T && an[i][j] >= an[i][Q[T]]) --T;
			q[++t] = Q[++T] = j;
			if(j >= n) {X[i][j] = an[i][Q[H]];x[i][j] = an[i][q[h]];}
		}
	//}
		
			
	for(reg int i = 1; i <= a; ++i){
		for(reg int j = n,h = 1,t = 0,H = 1,T = 0;j <= b; ++j){
			while(i - q[h] >= n) ++h;
			while(i - Q[H] >= n) ++H;
			while(h <= t && x[i][j] <= x[q[t]][j]) --t;
			while(H <= T && X[i][j] >= X[Q[T]][j]) --T;
			q[++t] = Q[++T] = i;
			if(i >= n) {Y[i][j] = X[Q[H]][j];y[i][j] = x[q[h]][j];}
		}
	}
		
	
	for(reg int i = n ; i <= a; ++i)
		for(reg int j = n ; j <= b; ++j)
			ans = Min(ans,Y[i][j] - y[i][j]);
	
	printf("%d",ans);
	return 0;
}
