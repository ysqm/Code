#include<cstdio>
# include <algorithm>
using namespace std;
inline int re()
{
    int x=0,f=1;char c=getchar();
    while(c>'9'||c<'0') {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') {x=x*10+c-'0'; c=getchar();}
    return x*f;
}
inline void output(int x){
    if(x>=10){
        output(x/10);
    }
    putchar(x%10+'0');
}
const int kN = 1e6 + 10,inf= 1e8;
int v[kN], l[kN], r[kN],n,ans=1;bool falg;
inline int dfs(int i){
	int sum=0;
	if(r[i]!=-1) sum+=dfs(r[i]);
	if(l[i]!=-1) sum+=dfs(l[i]);
	return sum+1;
}
inline bool check(int i,int j){
	if(i==-1&&j==-1) return true;
	if(i!=-1&&j!=-1&&v[i]==v[j]&&check(l[i],r[j])&&check(r[i],l[j]))
		return true;
	return false;
}
int main(){
	n=re();
	for(register int i=1;i<=n;i++)
		v[i]=re();
	for(register int i=1;i<=n;i++){
		l[i]=re();r[i]=re();
	}
	for(register int i=1;i<=n;i++)
		if(check(l[i],r[i])){
			ans=max(dfs(i),ans);
		}
	output(ans);
	return 0;
}
