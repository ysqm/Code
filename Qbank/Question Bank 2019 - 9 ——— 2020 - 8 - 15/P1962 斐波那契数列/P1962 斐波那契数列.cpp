# include <cstdio>
const long long base=1000000007;
typedef long long LL; 
LL D[3][3]={{},{0,0,1},{0,1,1}},b[3]={0,1,1},De[3][3],a[3][3],mo[3][3]={{},{0,1,0},{0,0,1}},temp;
int main(){
	long long n;
	scanf("%lld",&n);
	if(n<=2){
		printf("1");
		return 0;
	}
	n-=2;
	while(n){
		De[1][1]=D[1][1];De[1][2]=D[1][2];De[2][1]=D[2][1];De[2][2]=D[2][2];
		if(n&1){
			temp=((D[1][1]*b[1])%base+(D[1][2]*b[2])%base)%base;
			b[2]=((D[2][1]*b[1])%base+(D[2][2]*b[2])%base)%base;
			b[1]=temp;
		}
			{
				a[1][1]=D[1][1]*De[1][1]%base+D[1][2]*De[2][1]%base;
				a[1][2]=D[1][1]*De[2][1]%base+D[1][2]*De[2][2]%base;
				a[2][1]=D[2][1]*De[1][1]%base+D[2][2]*De[1][2]%base;
				a[2][2]=D[2][1]*De[1][2]%base+D[2][2]*De[2][2]%base;
			}
			/*{
				D[1][1]=D[1][1]*mo[1][1]+D[1][2]*mo[1][2];
				D[1][2]=D[1][1]*mo[2][1]+D[1][2]*mo[2][2];
				D[2][1]=D[2][1]*mo[1][2]+D[2][2]*mo[2][2];
				D[2][2]=D[2][1]*mo[2][2]+D[2][2]*mo[1][2];
			}*/
		D[1][1]=a[1][1]%base;D[1][2]=a[1][2]%base;D[2][1]=a[2][1]%base;D[2][2]=a[2][2]%base;
		n>>=1;
	}
	printf("%lld",b[2]);
	return 0;
}
