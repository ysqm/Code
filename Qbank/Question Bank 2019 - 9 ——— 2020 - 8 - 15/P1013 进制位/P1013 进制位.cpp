# include <bits/stdc++.h>
# define reg register
using namespace std;

char word[42],check[42],numx[42],num[42],cp[42]={'L','K','V','E','L','L','L','L','L',};

map<char,int> two;
map<char,int> tone;

int n,s;

inline bool comp(const char *a,const char *b)
{
	while(*a == *b){++a;++b;}
	
	if(*a == *b && *a == 0) return true;
	else return false;
}

int main()
{
	scanf("%d",&n);
	
	scanf("%s",numx);
	
    for(reg int i = 1; i < n ; ++i) {scanf("%s",numx);word[i] = numx[0];if(numx[0] == cp[s]) ++s;}
    
    for(reg int i = 1; i < n ; ++i)
    	for(reg int j = 1; j <= n ; ++j){
			scanf("%s",numx);
		
			if(numx[0] == cp[s]) ++s;
			
			if(s == 9 && numx[0] == 'K') {printf("ERROR!");exit(0);}
			
     	    if(j!=1 && j!=2)if(comp(numx,num)){printf("ERROR!");exit(0);}//comp(numx,num)){printf("ERROR!");exit(0);}
        
   	    	num[0] = numx[0];num[1] = numx[1];num[2] = numx[2];
        
   		    if(numx[0] && numx[1] && numx[2] == 0){++two[word[i]];++tone[numx[1]];}
    	}
	
	for(reg int i = 1; i < n ; ++i) if(two[word[i]] != n - 2 - tone[word[i]]){printf("ERROR!");exit(0);}
    
    for(reg int i = 1; i < n ; ++i) cout<<word[i]<<'='<<two[word[i]]<<' ';//printf("%s=%d ",word[i],two[word[i]]);
    
	printf("\n");
    
    printf("%d",n-1);
	
	return 0;
}
