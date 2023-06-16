# include <cstdio>
# include <queue>
# include <algorithm> 
# define N 50000
# define M 3000
# define R register
using namespace std;
inline int cut(int i);
inline int re()
{
	int f = 1,x = 0;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}
int a[N * 3 + 42],n,k,O,x,y,sum;
int main()
{	
	n = re();
	k = re();
	n *= 3;
	
	for(R int i = 1;i <= n; i++) a[i] = i;
	
	n /= 3;
	
	while(k--){
		O = re();
		x = re();
		y = re();
		if(x > n || y > n) {
			sum++;
			continue;
		}
		if(O == 1){
			if( cut(x + n) == cut(y) || cut(y + n) == cut(x) ){
				sum++;
				continue;
			}
			else{
				a[cut(x)] = cut(y);
				a[cut(x + n)] = cut(y + n);
				a[cut(x + n * 2)] = cut(y + n * 2);
			}
		}
		else {
			if(cut(x) == cut(y)) {
				sum++;
				continue;
			}
			else if(cut(y + n) == cut(x)){
				sum++;
				continue;
			}
			else{
				a[cut(x + n)] = cut(y);
				a[cut(x + n + n)] = cut(y + n);
				a[cut(x)] = cut(y + n * 2);
			}
		}
	}
	printf("%d",sum);
	return 0;
}
inline int cut(int i)
{
	return a[i]==i?a[i]:a[i]=cut(a[i]);
}
