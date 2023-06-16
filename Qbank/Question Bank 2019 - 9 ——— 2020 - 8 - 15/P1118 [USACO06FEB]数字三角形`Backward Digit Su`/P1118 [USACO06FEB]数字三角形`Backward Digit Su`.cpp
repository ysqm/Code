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
int n,sum,answer[];
int main(){
	n=re();sum=re();
} 
