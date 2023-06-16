# include <cstdio>
# include <algorithm>
# define reg register
using namespace std;

char s1[42],s2[42];
int len;

inline void dfs(const int L,const int R,const int l,const int r)
{
	reg int mid = 0;
	
	for(;mid <= len; ++mid)
		if(s1[mid] == s2[r]) break;
		
	//if(mid == len) return;
	
	printf("%c",s1[mid]);
	
	if(mid > L) dfs(L,mid - 1,l,r - R + mid - 1);
	
	if(mid < R) dfs(mid + 1,R,l + mid - L,r - 1);
}

int main()
{
	scanf("%s%s",s1,s2);
	
	while(s1[len]) ++len;
	
	dfs(0,len - 1,0,len - 1);
	
	return 0;
}
