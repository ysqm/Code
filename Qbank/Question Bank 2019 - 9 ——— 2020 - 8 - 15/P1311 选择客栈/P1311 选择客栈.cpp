# include <cstdio>
# include <algorithm>
# define reg register
using namespace std;

inline void in(int& x)
{
	x = 0; char ch = getchar();int f = 1;
	
	while(ch < '0' || ch > '9'){if(ch == '-') f = -1;ch = getchar();}
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	x *= f;
}

int col[55],sum[55],last[55],price,now,n,k,p,colour,ans;

int main()
{
	in(n);in(k);in(p);
	
	for(reg int i = 1; i <= n; ++i){
		in(colour);in(price);
		
		if(price <= p)	now = i;
		
		if(now >= last[colour]) sum[colour] = col[colour];
		
		last[colour] = i;
		
		ans += sum[colour];
		
		++col[colour];
	}
	
	printf("%d",ans);
	
	return 0;
}
