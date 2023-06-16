# include <map>
# include <cmath>
# include <cstdio>
# include <cstring>
# include <cstdlib>
# include <iostream>
# include <algorithm>
# define N 100000
# define REG register
# define Ls(i) i << 1
# define Rs(i) i << 1 | 1
# define mi (L + R) >> 1
typedef long long LL;
using namespace std;

inline int r()
{
	int x = 0;char c = getchar();
	
	while(c < '0' || c > '9') c = getchar();
	
	while(c >= '0' && c <= '9') {x = (x << 3) + (x << 1) + c - '0';c = getchar();}
	
	return x;
} 

struct edge
{
	int from,to;
} e[(N << 1) + 42];

int head[N + 42],n,deep[N + 42],son[N + 42],mod,fa[N + 42],siz[N + 42],top[N + 42],id[N + 42],from[N + 42],bh,e_cnt,q;

int lazy[(N << 2) + 42];

inline void add(int u,int v)
{
	e[++e_cnt].from = head[u];
	
	e[e_cnt].to = v;
	
	//e[e_cnt].wi = wi;
	
	head[u] = e_cnt;
	
	e[++e_cnt].from = head[v];
	
	e[e_cnt].to = u;
	
	//e[e_cnt].wi = wi;
	
	head[v] = e_cnt;
	
}
void LCT_INIT(int u)
{
	siz[u] = 1; son[u] = n + 1;
	
	for(REG int i = head[u]; i ; i = e[i].from)
		if(e[i].to != fa[u]){
			fa[e[i].to] = u;
			
			deep[e[i].to] = deep[u] + 1;
			
			LCT_INIT(e[i].to);
			
			siz[u] += siz[e[i].to];
			
			if(siz[e[i].to] > siz[son[u]]) son[u] = e[i].to;
		}
}

void LCT(int u,int sign)
{
	id[u] = ++bh;from[bh] = u;
	
	top[u] = sign;
	
	if(son[u] != n + 1) LCT(son[u],sign);
	
	for(REG int i = head[u]; i ;i = e[i].from)
		if(e[i].to != son[u] && e[i].to != fa[u]) LCT(e[i].to,e[i].to);
}

inline void build(int L,int R,int K)
{	
	lazy[K] = -1;
	
	if(L != R){
		
		int mid = mi;
		
		build(L,mid,Ls(K));
		
		build(mid + 1,R,Rs(K));
	}
}

inline int updata_change(const int change_L,const int change_R,const int flag,const int L,const int R,const int K)
{
	if(change_L <= L && change_R >= R && lazy[K]) {
		if(lazy[K] != flag){
			
			lazy[K] = flag;
			
			return R - L + 1;
		}
		else return 0;
	} 
	
	else {

		int mid = mi,res = 0;
		
		if(lazy[K]) {lazy[Rs(K)] = lazy[Ls(K)] = lazy[K];lazy[K] = 0;}
		
		if(mid < change_R) res += updata_change(change_L,change_R,flag,mid + 1,R,Rs(K));
		
		if(mid >= change_L) res += updata_change(change_L,change_R,flag,L,mid,Ls(K));
		
		if(lazy[Ls(K)] == lazy[Rs(K)]) lazy[K] = lazy[Rs(K)];
		
		return res;
	}
}

inline int updata_diff(int L,int R,int increment)
{
	int res = 0;
	
	while(top[L] != top[R]){
		if(deep[top[L]] < deep[top[R]]) L ^= R ^= L ^= R;
		
		res += updata_change(id[top[L]],id[L],increment,1,n,1);
		
		L = fa[top[L]];
	}
	
	if(deep[L] > deep[R]) L ^= R ^= L ^= R;
		
	return res += updata_change(id[L],id[R],increment,1,n,1);
}

int main()
{
	n = r();
	
	for(REG int i = 1; i < n; ++i) add(r() + 1,i + 1);
	
	LCT_INIT(1);
	
	LCT(1,1);
	
	build(1,n,1);
	
	q = r();
	
	char ch;int pos;
	
	while(q--){
		ch = getchar();
		
		while(ch > 'z' ||ch < 'a') ch = getchar();
		
		if(ch == 'i') printf("%d\n",updata_diff(1,r() + 1,1)); 
		
		else {
			pos = r() + 1;
			
			printf("%d\n",updata_change(id[pos],id[pos] + siz[pos] - 1,-1,1,n,1)); 
		}
	}
	
	return 0;
}
