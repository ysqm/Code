#include<bits/stdc++.h>
using namespace std;
inline int readfuck()
{
    int x=0,f=1;char c=getchar();
    while(c>'9'||c<'0') {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') {x=x*10+c-'0'; c=getchar();}
    return x*f;
}
/*inline void fuckout(int x)
{
    if(x>=10){
        fuckout(x/10);
    }
    putchar(x%10+'0');
}*/
int x[502],y[502],ans=0;
bool q[20010],c[20010];
int main(){
	int n=readfuck(),m=readfuck(),k=readfuck();
	for(int i=1;i<=k;i++){
		x[i]=readfuck();y[i]=readfuck();
		c[x[i]]=true;
	}
	for(int i=1;i<=n;i++){
		memset(q,0,sizeof(q));
		if(c[i]) continue;
		for(int j=1;j<=k;j++){
			q[y[j]]=true;
			if(x[j]<i){
				if(y[j]+(i-x[j])<=m) q[y[j]+(i-x[j])]=true;
				if(y[j]-(i-x[j])>0) q[y[j]-(i-x[j])]=true;
			}
			else{
				if(y[j]+(x[j]-i)<=m) q[y[j]+(x[j]-i)]=true;
				if(y[j]-(x[j]-i)>0) q[y[j]-(x[j]-i)]=true;
			}
		}
		//for(int j=1;j<=m;j++){
		//	printf("%d",q[j]);
		//}
		//printf("\n%d",ans);
		//system("pause");
		for(int j=1;j<=m;j++){
			if(q[j]) continue;
			ans++;
		//printf("%d ",ans);	
		//system("pause");
		}
	}
	cout<<ans<<endl;
	//fuckout(ans);
	return 0;
}
