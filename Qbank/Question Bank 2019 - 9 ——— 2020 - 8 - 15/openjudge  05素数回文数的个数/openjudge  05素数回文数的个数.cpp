# include <cstdio>
# include <cmath>
using namespace std;
int vis[1010],n;
void zhi(int n){
	vis[1]=true;
	n=(sqrt(n)+0.5);
	for(int i=2;i<=n;i++){
		if(vis[i]) continue;
		for(int j=i*2;j<=n;j+=i) vis[j]=true;
	}
		
	return ;
}
bool judg(int nu){
	int a;
	if(nu<100) {
		a=nu%10;
		if(a==nu/10) return true;
	}
	else {
		a=nu/100;
		if(a==nu%10) return true;
	}
	return false;
}
int main(){
	freopen("1.txt","w",stdout);
	n=1000;
	zhi(n);
	printf("{");
	for(int i=100;i<1000;i++){
		if(vis[i]) continue;
		if(judg(i)) printf(",%d",i);	
	}
	
	printf("}");
	return 0;
} 
