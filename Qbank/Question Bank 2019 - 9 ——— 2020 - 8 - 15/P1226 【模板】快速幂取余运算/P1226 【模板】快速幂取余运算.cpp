# include <cstdio>
long long b,p,k,sum=1;
long long fastpow();
long long fastpow(){
	long long pn=p,bn=b;
	while(pn){
		if(pn&1)
			sum=sum*bn%k;
		bn=bn*bn%k;
		pn=pn>>1;
	}
	return sum;
}
int main(){
	scanf("%lld%lld%lld",&b,&p,&k);
	printf("%lld^%lld mod %lld=%lld",b,p,k,fastpow());
	return 0;
}
