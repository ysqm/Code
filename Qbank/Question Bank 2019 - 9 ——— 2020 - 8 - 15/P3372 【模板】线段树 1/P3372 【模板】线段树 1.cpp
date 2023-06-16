/*
	更新时间：2019/12/27 19:16 
	代码问题：要开八倍数组 
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


LL segtree[(N << 2) + 42];

int base[N + 42],n,lazy[(N << 2) + 42],m;

inline void build(const int L,const int R,const int K)
{
	if(L == R){segtree[K] = base[L];return ;}
	
	int mid = mi;
		
	build(L,mid,Ls(K));
		
	build(mid + 1,R,Rs(K));
		
	segtree[K] = segtree[Rs(K)] + segtree[Ls(K)];
	
} 

inline void lazy_down(const int L,const int R,const int K)
{
	int mid = mi;
	
	segtree[Rs(K)] += lazy[K] * (R - mid);//右区间[mid + 1,R] 
	
	segtree[Ls(K)] += lazy[K] * (mid - L + 1);//左区间[L,mid] 
	
	lazy[Ls(K)] += lazy[K];
	
	lazy[Rs(K)] += lazy[K];
	
	lazy[K] = 0; 
}

inline void updata_change(const int change_L,const int change_R,const int increment,const int L,const int R,const int K)
{
	if(change_L <= L && change_R >= R){segtree[K] += increment * (R - L + 1);lazy[K] += increment;return;}
	
	else {
		int mid = mi;
		
		if(lazy[K]) lazy_down(L,R,K);
		
		if(mid < change_R) updata_change(change_L,change_R,increment,mid + 1,R,Rs(K));
		
		if(mid >= change_L) updata_change(change_L,change_R,increment,L,mid,Ls(K));
		
		segtree[K] = segtree[Ls(K)] + segtree[Rs(K)];
	}
}

inline LL ask_query(const int ask_L,const int ask_R,const int L,const int R,const int K)
{
	if(ask_L <= L && ask_R >= R) {
	
		//if(lazy[K]) lazy_down(L,R,K);
	
		return segtree[K];
	}
	
	else {
		int mid = mi;
		
		if(lazy[K]) lazy_down(L,R,K);
		
		if(ask_R <= mid) return ask_query(ask_L,ask_R,L,mid,Ls(K));
		
		else if(ask_L > mid) return ask_query(ask_L,ask_R,mid + 1,R,Rs(K));
		
		else return ask_query(ask_L,ask_R,L,mid,Ls(K)) + ask_query(ask_L,ask_R,mid + 1,R,Rs(K));
	}
}

int main()
{
	n = r(); m = r();
	
	for(REG int i = 1; i <= n; ++i) base[i] = r();
	
	build(1,n,1);
	
	int que_a,que_b,que_order;
	
	while(m--){
		que_order = r();que_a = r();que_b = r();
		
		if(que_order == 1)  updata_change(que_a,que_b,r(),1,n,1);
		
		else printf("%lld\n",ask_query(que_a,que_b,1,n,1));
	}
}
