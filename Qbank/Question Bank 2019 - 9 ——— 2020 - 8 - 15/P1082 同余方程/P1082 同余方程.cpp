# include <cstdio>
# include <algorithm>
using namespace std;
void exgcd(int a,int b,int &x,int &y){
	if(b==0){
		x=1;y=0;
		return;
	}
	exgcd(b,a%b,x,y);
	int ly=x;
	x=y;y=ly-a/b*y;
}
int main(){
	int a,b,x,y;
	scanf("%d%d",&a,&b);
	exgcd(a,b,x,y);
	x=(x%b+b)%b;
	printf("%d",x);
	return 0;
}
