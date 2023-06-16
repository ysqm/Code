/*
	推导过程：
			由从1~n中选出k个数是它们最大公约数最大
			由此设最大公约数x，有x*1+x*2....+x*k即为所选数
			又要X尽可能大，所以x*k要尽可能接近n，
			c++中除法自动向下去整，所以n/k即为所求 
*/
# include <cstdio>
# include <iostream>
# include <algorithm>
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	printf("%d",n/k);
	return 0;
}
