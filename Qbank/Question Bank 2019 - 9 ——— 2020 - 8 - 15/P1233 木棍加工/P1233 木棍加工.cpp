# include <cstdio>
# include <iostream>
# include <algorithm>
//# include <>
//矩形覆盖 无解 
using namespace std;
int len=0,n,vis[5010],b[5010];
typedef struct {int li,wi;} stick;stick an[5010];
bool comp(const stick a,const stick b){
	return a.li>b.li;
}

int main(){
	freopen("1.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d %d",&an[i].li,&an[i].wi);
	sort(an+1,an+n+1,comp);//返回以li为序的升序
	//printd();
	for(int i=1;i<=n;i++){
		b[i]=an[i].wi;
		if(an[i].wi>vis[len]) vis[++len]=an[i].wi;
		else{
			int l=1,r=len;
            while(l<r){
                int mid=(l+r)/2;
                if(vis[mid]>=an[i].wi){
                    r=mid;
                }
                else{
                    l=mid+1;
                }
            }
			vis[l]=an[i].wi;
		}
	}
	printf("%d",len);
	return 0;
}
/*int lowerbound12(int x,int y,int key){
	int m=x;
	while(x<y){
		m=x+(y-x)/2;
		if(vis[m].wi<=key) x=m+1;
		else y=m;
	}
	return m;
}//返回找到的第一个小于等于key的数 
void printd(){
		printf("排完序后的数组：\n");
		for(int j=1;j<=n;j++){
			printf("long%5d wide%5d",an[j].li,an[j].wi);
			printf("\n");
		}	
	system("pause")	;
}//测试用 */
