# include <cstdio>
# include <vector>
# include <algorithm>

std::vector<int> v;

int n;

int main()
{
	scanf("%d",&n);
	
	for(register int i = 1,x; i <= n ; ++i){
	
		scanf("%d",&x);
		
		v.insert(std::upper_bound(v.begin(),v.end(),x),x);
		
		//for(register int j = 0; j < i ; ++j) printf("%d ",v[j]);
		
		//printf("\n");
		
		if(i & 1) printf("%d ",v[(i - 1) >> 1]);
		
		//printf("\n");
	}
	
	return 0;
}
