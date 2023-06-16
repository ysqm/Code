# include <cstdio>
# include <algorithm>
//# pragma GCD optimize (2)
# define N 1000000
# define lowbit(x) (x&-x)
# define reg register
using namespace std;

inline int Read()
{
	int x = 0;char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch <= '9' && ch >= '0'){x = x*10 + (ch^48);ch = getchar();}
	
	return x;
}

int tr[(N<<1) + 42],n;

inline void Insert(reg int x,const int val)
{
	while(x <= n)
	{
		tr[x] ^= val;
		
		x += lowbit(x);
	}
}

inline int Query(reg int x)
{
	int res = 0;
	
	while(x)
	{
		res ^= tr[x];
		
		x -= lowbit(x);
	}
	
	return res;
}

struct Node
{
	int L,R,id;
	
	Node(const int b=0,const int a=0,const int id_=0):L(a),R(b),id(id_){}
};

bool operator < (const Node& a,const Node& b){return a.R < b.R;}

Node Q[N + 42];

int a[N + 42],m,b[N + 42],tot = 1,sum[N + 42],last[N + 42],Pre[N + 42],ans[N + 42];

inline int Find(const int x)
{
	reg int l = 1,r = tot,mid;
	
	while(l < r)
	{
		mid = (l+r)>>1;
		
		if(b[mid] < x) l = mid+1;
		else r = mid;
	}
	
	return l;
}

int main()
{
	n = Read();
	
	for(reg int i = 1; i <= n ; ++i) a[i] = b[i] = Read();
	
	sort(b+1,b+n+1);
	
	for(reg int i = 2; i <= n ; ++i) if(b[tot] != b[i]) b[++tot] = b[i];
	
	for(reg int i = 1; i <= n ; ++i) a[i] = Find(a[i]);
	
	for(reg int i = 1; i <= n ; ++i)
	{
		sum[i] = sum[i-1]^b[a[i]];
		Pre[i] = last[a[i]];
		last[a[i]] = i;
	}//记录上一次出现位置 
	
	m = Read();
	
	for(reg int i = 1; i <= m ; ++i) Q[i] = Node(Read(),Read(),i);
	
	sort(Q+1,Q+m+1);
	
	for(reg int i = 1,cur=1; i <= m ; ++i)
	{
		while(cur <= Q[i].R)
		{
			if(Pre[cur]) Insert(Pre[cur],b[a[cur]]);
			
			Insert(cur,b[a[cur]]);
			
			++cur;
		}
		
		ans[Q[i].id] = (Query(Q[i].R)^Query(Q[i].L-1))^(sum[Q[i].R]^sum[Q[i].L-1]);
	}
	
	for(reg int i = 1; i <= m ; ++i) printf("%d\n",ans[i]);
	
	return 0; 
}
