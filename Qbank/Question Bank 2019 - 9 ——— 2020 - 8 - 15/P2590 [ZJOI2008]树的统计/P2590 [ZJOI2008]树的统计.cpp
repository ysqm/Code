/*
	updata£∫2019/1/1 16:36 
	problem£∫unfound 
	BY ‘∆ÀÍ‘¬ È 
*/ 
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
	int f = 1,x = 0;char c = getchar();
	
	while(c > '9' || c < '0'){if(c == '-') f = -1;c = getchar();}
	
	while(c >= '0' && c <= '9'){x = (x << 3) + (x << 1) + c - '0';c = getchar();}
	
	return x * f;
}

struct edge
{
	int from,to;
} e[(N << 1) + 42];

int head[N + 42],e_cnt,n,m,deep[N + 42],son[N + 42],dad[N + 42],siz[N + 42],top[N + 42],id[N + 42],from[N + 42],bh,base[N + 42];

LL segtree[(N << 2) + 42],lazy[(N << 2) + 42],maxseg[(N << 2) + 42];

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
	siz[u] = 1; son[u] = 0;
	
	for(REG int i = head[u]; i ; i = e[i].from)
		if(e[i].to != dad[u]){
			dad[e[i].to] = u;
			
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
	
	if(son[u]) LCT(son[u],sign);
	
	for(REG int i = head[u]; i ;i = e[i].from)
		if(e[i].to != son[u] && e[i].to != dad[u]) LCT(e[i].to,e[i].to);
}

inline void build(const int L,const int R,const int K)
{
	if(L == R){maxseg[K] = segtree[K] = base[from[L]];return ;}
	
	int mid = mi;
		
	build(L,mid,Ls(K));
		
	build(mid + 1,R,Rs(K));
		
	segtree[K] = segtree[Rs(K)] + segtree[Ls(K)];
	
	maxseg[K] = max(maxseg[Ls(K)],maxseg[Rs(K)]);
} 

inline void updata_one(const int& change,const int& increment,const int L,const int R,const int K)
{
	if(change == L && change == R){segtree[K] = maxseg[K] = increment;return;}
	
	else {
		int mid = mi;
		
		//if(lazy[K]) lazy_down(L,R,K);
		
		if(mid < change) updata_one(change,increment,mid + 1,R,Rs(K));
		
		else if(mid >= change) updata_one(change,increment,L,mid,Ls(K));
		
		segtree[K] = segtree[Ls(K)] + segtree[Rs(K)];
		
		maxseg[K] = max(maxseg[Ls(K)],maxseg[Rs(K)]);
	}
}

inline LL ask_query(const int& ask_L,const int& ask_R,const int L,const int R,const int K)
{
	if(ask_L <= L && ask_R >= R) {
	
		//if(lazy[K]) lazy_down(L,R,K);
	
		return segtree[K];
	}
	
	else {
		int mid = mi;
		
		//if(lazy[K]) lazy_down(L,R,K);
		
		if(ask_R <= mid) return ask_query(ask_L,ask_R,L,mid,Ls(K));
		
		else if(ask_L > mid) return ask_query(ask_L,ask_R,mid + 1,R,Rs(K));
		
		else return (ask_query(ask_L,ask_R,L,mid,Ls(K)) + ask_query(ask_L,ask_R,mid + 1,R,Rs(K)));
	}
}

inline LL ask_max(const int& ask_L,const int& ask_R,const int L,const int R,const int K)
{
	if(ask_L <= L && ask_R >= R) {
	
		//if(lazy[K]) lazy_down(L,R,K);
	
		return maxseg[K];
	}
	
	else {
		int mid = mi;
		
		//if(lazy[K]) lazy_down(L,R,K);
		
		if(ask_R <= mid) return ask_max(ask_L,ask_R,L,mid,Ls(K));
		
		else if(ask_L > mid) return ask_max(ask_L,ask_R,mid + 1,R,Rs(K));
		
		else return max(ask_max(ask_L,ask_R,L,mid,Ls(K)) , ask_max(ask_L,ask_R,mid + 1,R,Rs(K)));
	}
}

inline LL query_diff(int& L,int& R)
{
	LL res = 0;
	
	while(top[L] != top[R]){
		if(deep[top[L]] < deep[top[R]]) L ^= R ^= L ^= R;
		
		res += ask_query(id[top[L]],id[L],1,n,1);
		
		L = dad[top[L]];
	}
	
	if(deep[L] > deep[R]) L ^= R ^= L ^= R;
		
	res += ask_query(id[L],id[R],1,n,1);
	
	return res;
}

inline LL query_max(int& L,int& R)
{
	LL res = -999999999999;
	
	while(top[L] != top[R]){
		if(deep[top[L]] < deep[top[R]]) L ^= R ^= L ^= R;
		
		res = max(ask_max(id[top[L]],id[L],1,n,1),res);
		
		L = dad[top[L]];
	}
	
	if(deep[L] > deep[R]) L ^= R ^= L ^= R;
	
	return max(res,ask_max(id[L],id[R],1,n,1));
}

int main()
{
	//freopen("P3384_2.in","r",stdin);
	//freopen("ans.out","w",stdout);
	
	n = r();
	
	for(REG int i = 1; i < n ; ++i) add(r(),r());
	
	for(REG int i = 1; i <= n ; ++i) base[i] = r();
	
	m = r();
	
	deep[1] = 1;
	
	LCT_INIT(1);
	
	LCT(1,1);
	
	build(1,n,1);
	
	char c = ' ';int x,y;
	
	while(m--){
		
		while(c < 'A' || c > 'Z') c = getchar();
		
		switch(c){
			case 'Q' :
					c = getchar();
					x = r();y = r();
					if(c == 'M') printf("%lld\n",query_max(x,y));
					else printf("%lld\n",query_diff(x,y));
					break;
			case 'C' :
					x = r();y = r();
					updata_one(id[x],y,1,n,1);
					break;		
		}
		
		c = ' ';
	}
	
	return 0;
} 
