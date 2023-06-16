# include <cstdio>
# define N 100000
int n,hei=0,a;
long long step=0;
inline int re(){
	int x=0,f=1;char c=getchar();
    while(c>'9'||c<'0') {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') {x=x*10+c-'0'; c=getchar();}
    return x*f;
}
inline void out(long long num){
	if(num>10) out(num/10);
	putchar(num%10+'0');
}
int main(){
	n=re();
	for(register int i=1;i<=n;i++){
		a=re();
		if(hei>=a) hei=a;
		else {step+=(a-hei);hei=a;}
	}
	out(step);
	return 0;
} 
