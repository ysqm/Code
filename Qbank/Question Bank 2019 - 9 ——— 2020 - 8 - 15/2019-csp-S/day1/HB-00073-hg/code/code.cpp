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
	return x*f;//��ǰ��� 
} 
LL fast_pow(int p){
	LL ans=1,m=2;
	while(p){
		if(p&1) ans*=m;
		m*=m;
		p>>=1;
	}//��������Ŀ����� 
	return ans;
}
int ans[N+42];
int main(){
	//freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	int n,len=0;LL sum=1,k,a=0;bool flag=true;//flag����������Ƿ�ߵ� 
	n=re();k=re();
	sum=fast_pow(n-1);
	/*
		���������Ҳû���뵽,��ʵֻҪ�ѵ�һ�ε�������ͺ��� 
	 */ 
	if(sum>k) {
				ans[len++]=0;
		}
	else{
		ans[len++]=1;
		k-=sum;
		flag=false;
	}//�������� 
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
		printf("%d",ans[i]);//ûʲô��˵ 
	return 0;
}
