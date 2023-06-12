# include <cstdio>

int step,a,b;

inline int GCD(const int x,const int y){return y == 0 ? x : GCD(y,x % y);};

int main()
{
	scanf("%d%d",&a,&b);
	
	int n = GCD(a,b);
	
	a /= n; b /= n;
	
	while(a % 2 == 0){a /= 2;++step;}
	
	while(a % 3 == 0){a /= 3;++step;}
	
	while(a % 5 == 0){a /= 5;++step;}
	
	while(b % 2 == 0){b /= 2;++step;}
	
	while(b % 3 == 0){b /= 3;++step;}
	
	while(b % 5 == 0){b /= 5;++step;}
	
	if(a == b) printf("%d",step);
	
	else puts("-1");
	
	return 0;
}
