# include <cstdio>
# include <algorithm>
# define REG register
# define N 500000

inline int Read()
{
	int x = 0,f = 1;char ch = getchar();
	
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1;ch = getchar();}
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	
	return x * f;
}

int tr[N + 42],n,O,x,y,m;

inline void updata(int x,int data){
	while(x <= n){
		tr[x] += data; 
		x += (x & (-x));
	}
}

inline int getsum(int x){
	int sum = 0;
	while(x){
		sum += tr[x];
		x -= (x & (-x));
	}
	return sum;
}

int main()
{
	n = Read();m = Read();
	
	for(REG int i = 1; i <= n; ++i) updata(i,Read());
	
	/*printf("\n\n");
	
	for(REG int i = 1; i <= n ; i ++) printf("%d ",getsum(i) - getsum(i - 1));
	
	printf("\n\n");*/
	
	while(m--){
		O = Read();x = Read();y = Read();
		
		if(O == 1) updata(x,y);
		
		else {
			x = getsum(x - 1);y = getsum(y);
			printf("%d\n",y - x);
		}
		/*printf("\n\n");
		
		for(REG int i = 1; i <= n ; i ++) printf("%d ",getsum(i) - getsum(i - 1));
		
		printf("\n\n");
		*/
	}
	return 0;
}
