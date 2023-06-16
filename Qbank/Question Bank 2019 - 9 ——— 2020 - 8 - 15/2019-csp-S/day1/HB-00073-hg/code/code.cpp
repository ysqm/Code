# include <cstdio>
# include <iostream>
# include <algorithm>
# include <set>
# include <vector>
# include <cstring>
# include <cstdlib>
# include <string>
# include <functional> 
# define N 1000
typedef unsigned long long LL;
inline LL re(){
	LL f=1,x=0;char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') {f=-1;}
		c=getchar();
	}
	while((c>='0')&&c<='9') {
		x=x*10+(c-'0');c=getchar();
		}
	return x*f;//考前打的 
} 
LL fast_pow(int p){
	LL ans=1,m=2;
	while(p){
		if(p&1) ans*=m;
		m*=m;
		p>>=1;
	}//毫无意义的快速幂 
	return ans;
}
int ans[N+42];
int main(){
	//freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	int n,len=0;LL sum=1,k,a=0;bool flag=true;//flag是用来标记是否颠倒 
	n=re();k=re();
	sum=fast_pow(n-1);
	/*
		考场上最后也没有想到,其实只要把第一次单独处理就好了 
	 */ 
	if(sum>k) {
				ans[len++]=0;
		}
	else{
		ans[len++]=1;
		k-=sum;
		flag=false;
	}//单独处理 
	while(len!=n){
		if(flag==true){
			if(sum/2>k) {
				ans[len++]=0;
				sum/=2;	
			}
			else{
				ans[len++]=1;
				sum/=2;
				k-=sum;
				flag=false;
			}
		}
		else {
			if(sum/2>k) {
				ans[len++]=1;
				sum/=2;
				flag=true;
			}
			else{
				ans[len++]=0;
				sum/=2;
				k-=sum;
			}
			
		}
	}
	for(int i=0;i<len;i++)
		printf("%d",ans[i]);//没什么好说 
	return 0;
}
