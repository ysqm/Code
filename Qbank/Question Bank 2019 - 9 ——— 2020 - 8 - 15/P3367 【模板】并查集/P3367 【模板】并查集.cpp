# include <cstdio>
int a[10010],n,m;
int cut(int i);
void cha(int x,int y);
int main(){
	int z,x,y;
	scanf("%d%d",&n,&m);
	while(n--) a[n]=n;
	while(m--){
		scanf("%d%d%d",&z,&x,&y);
		if(z==1) cha(x,y);
		else {
			if(cut(x)==cut(y)) printf("Y\n");
			else printf("N\n");
		}
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
