# include <map>
# include <cmath>
# include <cstdio>
# include <cstring>
# include <cstdlib>
# include <iostream>
# include <algorithm>
# define N 500000
# define REG register

inline int r()
{
	int x = 0,f = 1; char c = getchar();
	
	while(c < '0' || c > '9'){if(c == '-') f = -1;c = getchar();}
	
	while(c >= '0' && c <= '9'){x = (x << 3) + (x << 1) + c - '0';c = getchar();}
	
	return x * f;
}

int segtree[(N << 2) + 42],base[N + 42],n;

inline void build(const int L,const int R,int k)
{
	if(L == R){segtree[k] = base[L]; return;}
	
	int mid = (L + R) >> 1; k <<= 1;
	
	build(L,mid,k); 
	
	build(mid + 1,R,k | 1);
	
	segtree[k >> 1] = segtree[k] + segtree[k | 1];
}

inline void updata_one(const int x,const int data,const int L,const int R,const int K)
{
	if(L == x && R == x){segtree[K] += data;return ;}
	
	else {
		int mid = (L + R) >> 1;
		
		if(x <= mid) updata_one(x,data,L,mid,K << 1);
		
		else updata_one(x,data,mid + 1,R,K << 1 | 1);
		
		segtree[K] = segtree[K << 1] + segtree[K << 1 | 1];
	}
}

inline int ask_query(const int q,const int w,const int L,const int R,const int K)
{
	if(q <= L && w >= R) return segtree[K];
	
	else {
		int mid = (L + R) >> 1;
		
		if(w <= mid) return ask_query(q,w,L,mid,K << 1);
		
		else if(q > mid) return ask_query(q,w,mid + 1,R,K << 1 | 1);
		
		else return ask_query(q,w,L,mid,K << 1) + ask_query(q,w,mid + 1,R,K << 1 | 1);
	}
}

int main()
{
	n = r();
	
	for(REG int i = 1; i <= n ; i ++)	base[i] = r();
	
	build(1,n,1);
	
	printf("%d\n",ask_query(1,9,1,10,1));
	
	updata_one(1,10,1,10,1);
	
	printf("%d",ask_query(1,10,1,10,1));
	
	return 0;
}
