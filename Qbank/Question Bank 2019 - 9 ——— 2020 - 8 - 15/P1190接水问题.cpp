#include<map>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
int people[10010],num,line,ans,t;
int main(){
	scanf("%d%d",&num,&line);
	for(int k=1;k<=num;k++){
		scanf("%d",&people[k]);
	}t=line+1;
	while(t<=num+line)
    {
        for(int i=1;i<=line;i++) {
            people[i]--;
            if(people[i]==0){
                people[i]=people[t];
                t++; 
            }
        }
        ans++;
    }
	printf("%d",ans);
	return 0;
} 
