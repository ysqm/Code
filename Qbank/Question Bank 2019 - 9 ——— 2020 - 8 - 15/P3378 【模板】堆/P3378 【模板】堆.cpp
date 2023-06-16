# include <cstdio>
# include <algorithm>
using namespace std;
int a[1000010];
void getup(int &d,int &n){
	int mc,i,king;
	int father;
	a[++n]=d;i=n;
	while(i>1){
		father=i/2;
		if(a[i]>=a[father]) break;
		swap(a[i],a[father]);
		i=father;
	}
}
void cut(int &n){
	int mc,i=1;
	int son;
	while(i*2<=n){
		son=i*2;
		if(son+1<=n&&a[son+1]<a[son]) son=son+1;
		if(a[i]<a[son]) break;
		swap(a[i],a[son]);
		i=son;	
	}
}
int main(){
	int m,data,orde,n=0;
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d",&orde);
		if(orde==1){
			scanf("%d",&data);
			getup(data,n);
		} 
		else if(orde==2) printf("%d\n",a[1]);
		else {
			swap(a[1],a[n]);n--;
			cut(n);
		}
	}
	return 0;
} 
