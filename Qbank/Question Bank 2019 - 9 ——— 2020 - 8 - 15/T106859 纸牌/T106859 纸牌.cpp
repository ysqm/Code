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
	int x,y;
	bool operator < (const card a) const
	{	
		if(x<a.x) return true;
		else return false;		
	}	
} a[100010],b[100010];
int n,ans=0;
multiset <int> tr;
int main(){
	n=re();
	for(register int i=0;i<n;i++){
		a[i].x=re();a[i].y=re();
	}
	sort(a,a+n);
	for(register int i=0;i<n;i++){
		b[i].x=re();b[i].y=re();
	}
	sort(b,b+n);
 	multiset<int>::iterator i;
	for(int j=0,k=0;j<n;j++){
		while(b[k].x<=a[j].x&&k<n) tr.insert(b[k++].y);
		i=tr.upper_bound(a[j].y);
		if(i==tr.begin()) continue;
		else{
			i--;
			tr.erase(i);
			ans++;
		}
	}
	fuckout(ans);
	return 0;
}
			/*printf("a.x=%d a.y=%d b.x=%d b.y=%d ans=%d\n",(*i).x,(*i).y,(*j).x,(*j).y,ans);
			for(k=a.begin();k!=a.end();k++)
				printf("a.x=%d a.y=%d\n",(*k).x,(*k).y);
			for(k=b.begin();k!=b.end();k++)
				printf("b.x=%d b.y=%d\n",(*k).x,(*k).y);
			system("pause");*/
