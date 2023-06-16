# include <cstdio>
# include <iostream>
# include <cstring>
using namespace std;
const long long INF=1e18;
long long n,ans;
long long dis[101][101];
long long DIS[101][101];
double _time[101][101];

struct city
{
	long long distance;
	long long velocity;
}x[101];

int main()
{
	freopen("trip7.in","r",stdin);
	cin>>n>>ans;
	
	for(long long i=1;i<=n;i++)
	cin>>x[i].distance>>x[i].velocity;
	
	for(long long i=1;i<=n;i++)
	for(long long j=1;j<=n;j++)
	_time[i][j]=INF;
	
	/*memset(dis,-1,sizeof(dis));
	for(long long i=1;i<=n;i++)
	dis[i][i]=0;
	*/
	
	for(long long i=1;i<=n;i++)
	_time[i][i]=0;
	for(long long i=1;i<=n;i++)
	{
		dis[i][i]=0;
		DIS[i][i]=0;
	}
	//¶Ô½ÇÏßÖÃ0
	 
	for(long long i=1;i<=n;i++)
	for(long long j=1;j<=n;j++)
	{
		cin>>dis[i][j];
		if(dis[i][j]==-1)
		dis[i][j]=INF;
		DIS[i][j]=dis[i][j];
	}
	
	for(long long i=1;i<=n;i++)
	for(long long j=1;j<=n;j++)
	for(long long k=1;k<=n;k++)
	{
		DIS[j][k]=DIS[j][i]+DIS[i][k]<DIS[j][k]?DIS[j][i]+DIS[i][k]:DIS[j][k];
	}
	
	for(long long i=1;i<=n;i++)
	for(long long j=1;j<=n;j++)
	if(x[i].distance>=DIS[i][j])
	_time[i][j]=(double)DIS[i][j]/x[i].velocity;
	
	
	long long a,b;
	cin>>a>>b;
	printf("%.6lf\n",_time[a][b]);
	
	for(long long i=1;i<=n;i++)
	for(long long j=1;j<=n;j++)
	for(long long k=1;k<=n;k++)
	{
		_time[j][k]=_time[j][i]+_time[i][k]<_time[j][k]?_time[j][i]+_time[i][k]:_time[j][k];
	}
	
	for(long long i=1;i<=ans;i++)
	{
		
		printf("%.6lf\n",_time[a][b]);
	}
}
