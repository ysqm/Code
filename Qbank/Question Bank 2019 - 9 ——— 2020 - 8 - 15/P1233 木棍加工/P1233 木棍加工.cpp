# include <cstdio>
# include <iostream>
# include <algorithm>
//# include <>
//���θ��� �޽� 
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
	sort(an+1,an+n+1,comp);//������liΪ�������
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
}//�����ҵ��ĵ�һ��С�ڵ���key���� 
void printd(){
		printf("�����������飺\n");
		for(int j=1;j<=n;j++){
			printf("long%5d wide%5d",an[j].li,an[j].wi);
			printf("\n");
		}	
	system("pause")	;
}//������ */
