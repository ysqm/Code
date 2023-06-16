# include <cstdio>
# include <algorithm>
using namespace std;
int main(){
	short n,k,an[10000];
	scanf("%hi%hi",&n,&k);
	for(short i=0;i<n;i++)
		scanf("%hi",&an[i]);
	while(k--){
		next_permutation(an,an+n);
	}
	for(short i=0;i<n;i++)
		printf("%d ",an[i]);
	return 0;
}
