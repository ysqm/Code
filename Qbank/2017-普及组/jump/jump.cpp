# include <cstdio>
# include <algorithm>
# include <set> 
# include <vector>
using namespace std;
struct data{
	int xi,si,step,x,y,all_score;
	bool can_it_arrive;
	vector <int> can_it_arrive_it;
} a[500100];
struct sd{
	int x,y;
} g;
set <int> vis;
int ans,n,d,k,sum=0;
inline int re(){
    int x=0,f=1;char c=getchar();
    while(c>'9'||c<'0') {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') {x=x*10+c-'0'; c=getchar();}
    return x*f;
}
inline void fuckout(int x){
    if(x>=10){
        fuckout(x/10);
    }
    putchar(x%10+'0');
}
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	n=re();d=re();k=re();
	for(register int i=1;i<=n;i++){
		a[i].xi=re();a[i].si=re();
		if(sum>k&&a[i].si>0) sum+=a[i].si;
	}
	if(sum<k) printf("-1");
	int first=-1;ans=0;
	for(int i=1,j=1;i<=n;i++)
		if(a[i].xi=j*d) {
			ans+=a[i].si;vis.insert(i); 
			a[i].step=j;a[i].can_it_arrive=true;
			a[i].all_score=ans;j++;
		}//预处理每一个点保存一下最大分数 
	if(ans>k) printf("0");
	int len=a[n].xi-d,nowt=0,dp[510];
		if(d>len) len=d;
		for(int ki=0;ki<=len;ki++){
			g.x=d-ki;g.y=d+ki;
			if(g.x<0) g.x=0;
			for(int i=g.x;i<=g.y;i++){
				for(int j=1;j<=n;j++){
					
				}
			}	
		}
	return 0;
} 
