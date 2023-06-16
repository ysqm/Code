# include <cstdio>
# include <cstring>
using namespace std;
int a[400],k,b;
bool v[400];
int main(){
	char num[400];
    scanf("%s%d",num,&k);
    int len=strlen(num);
    for(int j=0;j<len;j++) a[j]=num[j]-'0';
    int i=0;
    for(int de=1;de<=k;de++){
    	for(i=0;i<len;i++){
    		if(v[i]) continue;
			b=i+1;
    		while(v[b]) b++;
    		if(a[i]>a[b]) {
    			v[i]=true;
    			break;
			}
		}	
	}
	bool flag=false;
	for(i=0;i<len;i++){
		if(!flag&&!v[i]&&a[i]!=0) {
			printf("%d",a[i]);
			flag=true;
		}
		else if(!v[i]&&flag) printf("%d",a[i]);
	}
	if(flag==false) printf("0");
	return 0;
}
