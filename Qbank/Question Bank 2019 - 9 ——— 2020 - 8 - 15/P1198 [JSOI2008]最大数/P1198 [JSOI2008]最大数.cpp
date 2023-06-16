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
# define inf 0x6f6f6f6f6f6f6f6f
# define Ls(i) i << 1
# define Rs(i) i << 1 | 1
# define mi (L + R) >> 1
typedef long long LL;

inline LL Read()
{
	LL f = 1,x = 0;char c = getchar();
	
	while(c < '0' || c > '9'){if(c == '-') f = -1;c = getchar();}
	
	while(c >= '0' && c <= '9'){x = x * 10 + c - '0';c = getchar();}
	
	return x * f;
}


LL segtree[(N << 2) + 42];

int n,m;

inline void build(const int L,const int R,const int K)
{
	if(L == R){segtree[K] = -inf;return ;}
	
	int mid = mi;
		
	build(L,mid,Ls(K));
		
	build(mid + 1,R,Rs(K));
		
	segtree[K] = -inf;
	
} 

inline void updata_change(const int& change,const LL& increment,const int L,const int R,const int K)
{
	if(change == L && change == R){segtree[K] = std::max(increment,segtree[K]);return;}
	
	else {
		int mid = mi;
		
		if(mid < change) updata_change(change,increment,mid + 1,R,Rs(K));
		
		else if(mid >= change) updata_change(change,increment,L,mid,Ls(K));
		
		segtree[K] = std::max(segtree[Ls(K)] , segtree[Rs(K)]);
	}
}

inline LL ask_query(const int& ask_L,const int& ask_R,const int& L,const int R,const int K)
{
	if(ask_L <= L && ask_R >= R)return segtree[K];
	
	else {
		int mid = mi;
		
		if(ask_R <= mid) return ask_query(ask_L,ask_R,L,mid,Ls(K));
		
		else if(ask_L > mid) return ask_query(ask_L,ask_R,mid + 1,R,Rs(K));
		
		else return std::max(ask_query(ask_L,ask_R,L,mid,Ls(K)) , ask_query(ask_L,ask_R,mid + 1,R,Rs(K)));
	}
}

int main()
{
	n = Read();m = Read();
	
	char c;LL x,tail = 0,t = 0;
	
	while(m--){
		while(c < 'A' || c > 'Z') 
			c = getchar();
		
		x = Read();
		
		if(c == 'A') updata_change(tail,(x + t) % m,1,n,1),tail++;
		
		else if(tail)	printf("%lld\n",ask_query(x,tail,1,n,1));
		
	}
	return 0;
}
