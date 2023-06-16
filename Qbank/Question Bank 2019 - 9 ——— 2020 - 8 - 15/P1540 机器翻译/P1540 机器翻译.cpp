# include <cstdio>
# include <queue>
using namespace std;

inline void in(int& x)
{
	x = 0; char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}
}

queue <int> q;

bool inq[4242];
int m,n,now_,ans;

int main()
{
	in(m);in(n);
	
	while(n--){
		in(now_);
		if(inq[now_]) continue;
		ans++;
		if(q.size() == m){inq[q.front()] = false;q.pop();}
		inq[now_] = true;
		q.push(now_);
	}
	printf("%d",ans);
	return 0;
}
