# include <iostream>
# include <algorithm>
# include <cstdio>
# include <iomanip>
# include <cstdlib>
# include <queue>
# define reg register
using namespace std;

int a[1042][1042],n,x[4] = {0,1,0,-1},y[4] = {1,0,-1,0};
bool f[1042][1042];

struct Point
{
	int x,y,id;
};

priority_queue <int,vector<int>,greater<int> > ans;
queue <Point> q;

int main()
{
	scanf("%d",&n);
	
	for(reg int i = 1; i <= n; ++i)
		for(reg int j = 1; j <= n; ++j)
			scanf("%1d",&a[i][j]);
			
	for(reg int i = 1; i <= n; ++i)
		for(reg int j = 1; j <= n; ++j)
			if(!f[i][j] && a[i][j]){
				int ans1 = 1;q.push((Point){i,j,1});
				
				while(q.size()){
					Point p = q.front();q.pop();
					
					f[p.x][p.y] = true;
					
					for(reg int k = 0; k < 4; ++k){
						int xx = x[k] + p.x,yy = y[k] + p.y;
						if(!f[xx][yy] && a[xx][yy]) q.push((Point){xx,yy,(ans1 = (p.id + (f[xx][yy] = 1)))});
					}
				}
			
				ans.push(ans1);
			}
			
	printf("%d\n",ans.size());
	
    while(ans.size())
        printf("%d\n",ans.top()),ans.pop();
    return 0;
}
