# include <cstdio>
# include <algorithm>
# include <cctype>
# define N 500000
# define REG register
# define int long long

/*inline char getcha(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf,1,100000,stdin),p1 == p2) ? EOF : *p1++;
}*/

inline int Read()
{
	int x = 0,f = 1;char ch = getchar();
	
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1;ch = getchar();}
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	
	return x * f;
}

int tr[N + 42],n,O,x,m,y,k,base,last;

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

signed main()
{
	n = Read();m = Read();
	
	for(REG int i = 1; i <= n; ++i) {base = Read();updata(i,base - last);last = base;}
	
	while(m--){
		O = Read();x = Read();
		
		if(O == 1) {
			y = Read();
			k = Read();
			updata(y + 1,-k);
			updata(x,k);
		}
		
		else printf("%lld\n",getsum(x));
	}
	return 0;
}
