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

long long ans;

struct BASE
{
	int number,id;
} SORT[N + 42];

bool operator < (const BASE a,const BASE b)
{
	return a.number < b.number;
}
int segtree[(N << 2) + 42],n,base[N + 42];

/*inline void build(const int L,const int R,int k)
{
	if(L == R){segtree[k] = base[L]; return;}
	
	int mid = (L + R) >> 1; k <<= 1;
	
	build(L,mid,k); 
	
	build(mid + 1,R,k | 1);
	
	segtree[k >> 1] = segtree[k] + segtree[k | 1];
}*/

inline void updata_one(int x,int L,int R,int K)
{
	if(L == x && R == x){segtree[K]++;return ;}
	
	else {
		int mid = (L + R) >> 1;
		
		if(x <= mid) updata_one(x,L,mid,K << 1);
		
		else updata_one(x,mid + 1,R,K << 1 | 1);
		
		segtree[K] = segtree[K << 1] + segtree[K << 1 | 1];
	}
}

inline int ask_query(int q,int w,int L,int R,int K)
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
	
	for(REG int i = 1; i <= n ; i++){SORT[i].number = r();SORT[i].id = i;}
	
	std::sort(SORT + 1,SORT + n + 1);
	
	for(REG int i = 1; i <= n ; i++) {
		if(SORT[i].number == SORT[i - 1].number) base[SORT[i].id] = base[SORT[i - 1].id];
		else base[SORT[i].id] = i;
	}
	
	//build(1,n,1);
	
	for(REG int i = 1; i <= n ; i++){
		updata_one(base[i],1,n,1);
		
		ans += ask_query(base[i] + 1,n + 1,1,n,1);
	} 
	
	printf("%lld\n",ans);
	
	return 0;
}
/*
	10
	1 1 1 1 1 1 1 1 1 1
	
	10
	9 1 1 1 1 1 1 1 1 1
	
	5 
	1 2 2 3 3 
	5 
	9 3 3 2 3 1 
	
*/
