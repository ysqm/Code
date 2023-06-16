# include <cstdio>
# include <iostream>
# include <cstring>
using namespace std;
int a[110],b[110],n,len,step=0;char s[110];
bool judge(){
	int t=len/2;
	for(int i=0;i<=t;i++){
		if(a[i]!=a[len-i-1]) return true;
	}
	return false;
}
int main(){
	scanf("%d%s",&n,s);len=strlen(s);
	for (int i=0;i<len;++i){
		if (s[i]>='0'&&s[i]<='9')
            a[len-i-1]=s[i]-'0';
        else
            a[len-i-1]=s[i]-55;
	}
	while(judge()){
		if(step>=30){
			printf("Impossible!");
			return 0;
		}
		step++;
		for(int i=0;i<len;i++)
			b[len-i-1]=a[i];
		for(int i=0;i<len;i++){
			a[i]+=b[i];
			if(a[i]>=n){a[i+1]++;a[i]-=n;}
		}
		if(a[len]) len++;
	}
	printf("STEP=%d",step);
	return 0;
} 
