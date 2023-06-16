# include <cstdio>
# include <algorithm>
# include <queue>
# define R register
using namespace std;
typedef long long LL;
typedef double D;
const int N = 2e6;
inline int re()
{
    int x=0,f=1;char c=getchar();
    while(c>'9'||c<'0') {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') {x=x*10+c-'0'; c=getchar();}
    return x*f;
}
struct Point
{
	int id,number;
} ;
deque <Point> q1,q2;
int ma[N + 42],mi[N + 42],n,k;
int main(){
	n = re();
	k = re();
	if(k == 1){
		R int i = 1;
		for(;i <= n;i++)
			ma[i] = mi[i] = re();
	}
	else if(1){
		R Point c,d;
		c.id = 1;
		c.number = re();
		q1.push_back(c);
		q2.push_back(c);
		c.id++; 
		for(;c.id <= n;c.id++){
			c.number = re();
			d = q1.front();
			while(c.id - d.id >= k) {
				q1.pop_front();
				d = q1.front();
			}
			d = q2.front();
			while(c.id - d.id >= k) {
				q2.pop_front();
				d = q2.front();
			}
			d = q1.back();
			while(c.number >= d.number){
				q1.pop_back();
				if(q1.empty()) break;
				d = q1.back();
			}
			q1.push_back(c);
			d = q2.back();
			while(c.number <= d.number){
				q2.pop_back();
				if(q2.empty()) break;
				d = q2.back();
			}
			q2.push_back(c);
			ma[c.id] = q1.front().number;
			mi[c.id] = q2.front().number;
		}
	}
	R int i = k;
	while(i <= n) printf("%d ",mi[i++]);
	printf("\n");
	i = k;
	while(i <= n) printf("%d ",ma[i++]);
	return 0;
} 
