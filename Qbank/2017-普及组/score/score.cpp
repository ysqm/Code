# include <cstdio>
int a,b,c;
inline int re()
{
    int x=0,f=1;char c=getchar();
    while(c>'9'||c<'0') {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') {x=x*10+c-'0'; c=getchar();}
    return x*f;
}
inline void fuckout(int x)
{
    if(x>=10){
        fuckout(x/10);
    }
    putchar(x%10+'0');
}
int main(){
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	a=re();b=re();c=re();
	fuckout(a/5+(b/10)*3+c/2);
	return 0;
} 
