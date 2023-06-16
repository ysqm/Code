# include <cstdio>
int a[10010],n,m,p;
int cut(int i);
void cha(int x,int y);
int main(){
	int x,y;
	scanf("%d%d%d",&n,&m,&p);
	while(n--) a[n]=n;
	while(m--){
		scanf("%d%d",&x,&y);
		cha(x,y);
	}
	while(p--){
		scanf("%d%d",&x,&y);
		if(cut(x)==cut(y)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
int cut(int i)
{
	return a[i]==i?a[i]:a[i]=cut(a[i]);
}
void cha(int x,int y)
{
	if(cut(x)!=cut(y)) 
		a[a[y]]=a[a[x]];
}
