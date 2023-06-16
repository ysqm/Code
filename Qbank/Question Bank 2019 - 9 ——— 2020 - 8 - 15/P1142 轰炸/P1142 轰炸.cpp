# include <cstdio>
# define N 700
# define reg register

struct Point
{
	int x,y;
} p[N + 42];

int n,ans;

int main()
{
	scanf("%d",&n);
	
	for(reg int i = 1; i <= n ; ++i) scanf("%d%d",&p[i].x,&p[i].y);
	
	for(reg int i = 1; i < n ; ++i){
		
		reg Point v1,v2;
		
		for(reg int j = i + 1; j < n; ++j){
			
			reg int cnt = 2;
			
			v1.x = p[i].x - p[j].x;
			v1.y = p[i].y - p[j].y;
			
			for(reg int k = j + 1; k <= n; ++k){
				
				v2.x = p[j].x - p[k].x;
				v2.y = p[j].y - p[k].y;
				
				if(v1.x * v2.y == v1.y * v2.x) ++cnt;
			}
			
			if(cnt > ans) ans = cnt;
			
		}
	}
	
	printf("%d",ans);
	
	return 0;
}
