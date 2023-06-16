# include <cstdio>
# include <algorithm>
# include <set>
using namespace std;
inline int re()
{
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
struct card{
	int x,y,tree;
	bool operator < (const card a) const
	{	
		if(y<a.y) return true;
		else return false;
	}	
} h[5010];
bool road[30010];
int N,H,ans;
int main(){
	freopen("testdata.in","r",stdin);
	N=re();H=re();
	for(register int i=0;i<H;i++){
		h[i].x=re();h[i].y=re();h[i].tree=re();
	}
	sort(h,h+H);
	int k;
	for(register int i=0,j;i<H;i++){
		k=0;
		for(j=h[i].x;j<=h[i].y;j++)if(road[j])k++;//统计区间内已标记的数
    	if(k<h[i].tree)
        	for(j=h[i].y;j>=h[i].x;j--)
             	if(!road[j]){road[j]=1;k++;ans++;if(k==h[i].tree)break;}
		/*while(j<=now&&h[i].tree>=0)
			if(road[j++]) h[i].tree--;
		if(h[i].tree<=0) continue;
		j=h[i].y;
		now=h[i].y;
		while(h[i].tree>0)
			if(!road[j]){
				road[j--]=true;
				h[i].tree--;
				ans++;
			}*/
	}
	fuckout(ans);
	return 0;
} 
