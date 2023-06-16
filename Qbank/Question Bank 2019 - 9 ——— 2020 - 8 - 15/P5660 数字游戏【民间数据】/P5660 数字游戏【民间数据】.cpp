# include <cstdio>
# include <iostream> 
int main(){
	char c[11];int s=48,i=0;
	scanf("%s",c);
	while(c[i])if(c[i++]&1) s++;
	putchar(s);
	return 0;
} 
