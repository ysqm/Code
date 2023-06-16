# include <queue> 
# include <cstdio>
# include <cstring>
# include <iostream>
# include <algorithm> 
# define reg register
# define N 200000
# define LL long long
using namespace std;

struct Point
{
	LL C,W;
	
	Point(const int C_=0,const int W_=0):C(C_),W(W_){}
	
	inline friend bool operator < (const Point a,const Point b){return a.C < b.C;}
} P[N + 42];

priority_queue <LL> h;

int n,s1,s2;

int main()
{
	ios::sync_with_stdio(false);
	
	cin>>n;
	
	for(reg int i = 1 ; i <= n ; ++i) cin>>P[i].C>>P[i].W,P[i].C += P[i].W;
	
	sort(P + 1, P + n + 1);
	
	LL ans = 0,len = 0;
	
	for(reg int i = 1; i <= n ; ++i)
		if(ans + P[i].W <= P[i].C)
		{
			ans += P[i].W;
			
			++len;
			
			h.push(P[i].W);
		}
		else if(h.top() > P[i].W)
		{
			ans += (P[i].W-h.top());
			h.pop();
			h.push(P[i].W);		
		}
	
	printf("%lld\n%lld",len,ans);
	
	return 0;
}
