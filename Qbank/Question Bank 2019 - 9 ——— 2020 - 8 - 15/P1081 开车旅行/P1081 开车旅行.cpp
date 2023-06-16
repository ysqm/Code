/*
	updata：2019/12/28 12:42 
	problem：读入部分有冲突 
	BY 云岁月书 
*/ 
# include <map>
# include <cmath>
# include <cstdio>
# include <cstring>
# include <cstdlib>
# include <iostream>
# include <algorithm>
# define N 200000
# define REG register
# define Ls(i) i << 1
# define Rs(i) i << 1 | 1
# define mi (L + R) >> 1
typedef long long LL;

inline int r()
{
	int f = 1,x = 0;char c = getchar();
	
	while(c < '0' || c > '9'){if(c == '-') f = -1;c = getchar();}
	
	while(c >= '0' && c <= '9'){x = x * 10 + c - '0';c = getchar();}
	
	return x * f;
}

long long segtree[(N << 2) + 42];
int n,mod,base[N + 42],m;

struct LAZY
{
	LL increment_add;
	long long increment_multiply;
} lazy[(N << 2) + 42],Lzy;//注意此处都要lld 

inline void build(int L,int R,int K)
{
	if(L == R){segtree[K] = base[L];}
	
	else {
		int mid = mi;
	
		build(L,mid,Ls(K));
	
		build(mid + 1,R,Rs(K));
	
		segtree[K] = (segtree[Ls(K)] + segtree[Rs(K)]) % mod;
	}
	
	lazy[K].increment_multiply = 1;
}

inline void lazy_down(int L,int mid,int R,int K,int ls,int rs)
{
	segtree[ls] = (lazy[K].increment_multiply * segtree[ls] + lazy[K].increment_add * (mid - L + 1)) % mod;
	
	segtree[rs] = (lazy[K].increment_multiply * segtree[rs] + lazy[K].increment_add * (R - mid)) % mod;
	
	lazy[ls].increment_multiply = (lazy[ls].increment_multiply * lazy[K].increment_multiply) % mod;
	
	lazy[rs].increment_multiply = (lazy[rs].increment_multiply * lazy[K].increment_multiply) % mod;
	
	lazy[ls].increment_add = (lazy[ls].increment_add * lazy[K].increment_multiply + lazy[K].increment_add) % mod;
	
	lazy[rs].increment_add = (lazy[rs].increment_add * lazy[K].increment_multiply + lazy[K].increment_add) % mod;
	
	lazy[K].increment_multiply = 1;
	
	lazy[K].increment_add = 0;
}

inline void updata_multiply(int change_L,int change_R,LL sign,int L,int R,int K)
{
	if(change_L <= L && change_R >= R){
		
		lazy[K].increment_add = (sign * lazy[K].increment_add) % mod;
		
		lazy[K].increment_multiply = (sign * lazy[K].increment_multiply) % mod;
		
		segtree[K] = (segtree[K] * sign) % mod;
		
		return;
	}
	
	else {
		int mid = mi;
		
		lazy_down(L,mid,R,K,Ls(K),Rs(K));
		
		if(mid < change_R) updata_multiply(change_L,change_R,sign,mid + 1,R,Rs(K));
		
		if(mid >= change_L) updata_multiply(change_L,change_R,sign,L,mid,Ls(K));
		
		segtree[K] = (segtree[Ls(K)] + segtree[Rs(K)]) % mod;
	}
}

inline void updata_add(int change_L,int change_R,LL sign,int L,int R,int K)
{
	if(change_L <= L && change_R >= R){
		
		lazy[K].increment_add = (sign + lazy[K].increment_add) % mod;
		
		segtree[K] = (segtree[K] + sign * (R - L + 1)) % mod;
		
		return;
	}
	
	else {
		int mid = mi;
		
		lazy_down(L,mid,R,K,Ls(K),Rs(K));
		
		if(mid >= change_L) 
			updata_add(change_L,change_R,sign,L,mid,Ls(K));
		
		if(mid < change_R) 
			updata_add(change_L,change_R,sign,mid + 1,R,Rs(K));
		
		segtree[K] = (segtree[Ls(K)] + segtree[Rs(K)]) % mod;
	}
}

inline LL query(int ask_L,int ask_R,int L,int R,int K)
{
	if(ask_L <= L && ask_R >= R){
		
		//if(L != R)lazy_down(L,mi,R,K,Ls(K),Rs(K));
		
		return segtree[K];
	}
	
	else {
		int mid = mi;
		
		LL res = 0;
		
		lazy_down(L,mid,R,K,Ls(K),Rs(K));
		
		if(mid < ask_R) res += query(ask_L,ask_R,mid + 1,R,Rs(K));
		
		if(mid >= ask_L) res += query(ask_L,ask_R,L,mid,Ls(K));
		
		return res % mod;
	}
} 

int main()
{
	//freopen("12.txt","r",stdin);
	//freopen("P3373_2.in","r",stdin);
	//freopen("我的.txt","w",stdout);
	
	n = r(); m = r(); mod = r();
	
	for(REG int i = 1; i <= n; ++i) base[i] = r();
	
	build(1,n,1);
	
	int x,y,k;
	
	while(m--){
		k = r();x = r();y = r();
		
		if(k == 1) updata_multiply(x,y,r() % mod,1,n,1);
		
		else if(k == 2) updata_add(x,y,r() % mod,1,n,1);
		
		else printf("%lld\n",query(x,y,1,n,1));
		
		//printf("操作%d： %lld\n",k,query(x,y,1,n,1));
	}
	
	return 0;
}
