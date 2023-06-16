# include <queue> 
# include <cstdio>
# include <cstring>
# include <algorithm>
# define reg register
# define LL long long
# define int long long 
using namespace std;

inline LL Read()
{
	 LL x = 0,f = 1;char ch = getchar();
	 
	 while(ch < '0' || ch > '9') {f = - 1;ch = getchar();}
	 
	 while(ch >= '0' && ch <= '9'){x = (x * 10) + (ch ^ 48);ch = getchar();}
	 
	 return x * f;
}

struct Statu
{
	LL x,y,z;
	
	Statu(const int a=0,const int b=0,const int c=0):x(a),y(b),z(c){}
	
	inline void Legalization()
	{
		if(x > y) swap(x,y);
		if(x > z) swap(x,z);
		if(y > z) swap(y,z);
	}
	
	inline bool operator == (const Statu b)const 
	{
		if(x == b.x && y == b.y & z == b.z) return true;
		else return false;
	}
	
} Initial,Goal,c1,c2;

inline int Min(const int a,const int b){return a < b ? a : b;}

template<class T>
inline T Swap(T& a,T& b){T c;c = a;a = b;b = c;}

# define x cur.x
# define y cur.y
# define z cur.z
inline int Find_the_root(Statu& cur)
{
	int d1 = y - x,d2 = z - y,k = 0;
	while(1)
	{
		if(d1 == d2) return k;
		else if(d1 < d2)
		{
			LL kd = d2/d1;
			if(d2%d1 == 0) --kd;
			x += kd * d1;
			y += kd * d1; 
			k += kd;
		}
		else
		{
			LL kd = d1/d2;
			if(d1%d2 == 0) --kd;
			y -= kd * d2;
			z -= kd * d2;
			k += kd;
		}
		d1 = y - x;
		d2 = z - y;
	}
}

inline Statu Find_the_ancestors(reg Statu cur,reg int k)
{
	reg int d1 = y - x,d2 = z - y;
	while(k)
	{
		if(d1 == d2) return cur;
		else if(d1 > d2)
		{
			LL kd = d1/d2;
			if(d1%d2 == 0) --kd;
			kd = Min(kd,k);
			y -= kd * d2;
			z -= kd * d2;
			k -= kd;
		}
		else if(d1 < d2)
		{
			LL kd = d2/d1;
			if(d2%d1 == 0) --kd;
			kd = Min(kd,k);
			x += kd * d1;
			y += kd * d1;
			k -= kd;
		}
		d1 = y - x;
		d2 = z - y;
	}
	
	return cur;
}
# undef x
# undef y
# undef z

int ans;

signed main()
{
	Initial = Statu(Read(),Read(),Read());
	Goal = Statu(Read(),Read(),Read());
	
	Initial.Legalization();
	Goal.Legalization();
	
	c1 = Initial;
	c2 = Goal;
	
	int L1 = Find_the_root(c1),L2 = Find_the_root(c2);
	
	if(c1 == c2) 
	{
		puts("YES");
		
		if(L1 > L2) Initial = Find_the_ancestors(Initial,L1 - L2),ans += L1 - L2;
	
		else if(L2 > L1) Goal = Find_the_ancestors(Goal,L2 - L1),ans += L2 - L1;
		
		if(Goal == Initial) printf("%d\n",ans);
		
		else 
		{
			reg int l = 1,r = Min(L1,L2),mid;
			
			while(l < r)
			{
				mid = (l + r) >> 1;
				if(Find_the_ancestors(Initial,mid) == Find_the_ancestors(Goal,mid)) r = mid;
				else l = mid+1;
			}
			
			printf("%d",ans + (l << 1));
		}
	}
	else puts("NO");
	
	return 0;
}
