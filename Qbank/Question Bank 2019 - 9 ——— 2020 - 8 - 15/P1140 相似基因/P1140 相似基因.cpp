# include <iostream>
# define N 105
using namespace std;
const int mo[5][5]=
{
    {5,-1,-2,-1,-3},
    {-1,5,-3,-2,-4},
    {-2,-3,5,-2,-2},
    {-1,-2,-2,5,-1},
    {-3,-4,-2,-1,0}
};
int max1(int a,int b,int c){
	if(a>b) return a>c?a:c;
	else return b>c?b:c;
} 
int a[N],b[N],dp[N][N],la,lb;char ad;
int main(){
	cin.sync_with_stdio(false);
	cin>>la;
	for(int i=1;i<=la;i++){
		cin>>ad;
		switch(ad){
			case 'A': a[i]=0;break;
			case 'C': a[i]=1;break;
			case 'G': a[i]=2;break;
			case 'T': a[i]=3;break;
		}
	}	
	cin>>lb;
	for(int i=1;i<=lb;i++){
		cin>>ad;
		switch(ad){
			case 'A': b[i]=0;break;
			case 'C': b[i]=1;break;
			case 'G': b[i]=2;break;
			case 'T': b[i]=3;break;
		}
	}//手打中-ing。。。。 
	
	for(int i=1;i<=la;i++) dp[i][0]=dp[i-1][0]+mo[a[i]][4];
	for(int i=1;i<=lb;i++) dp[0][i]=dp[0][i-1]+mo[b[i]][4];
	for(int i=1;i<=la;i++)
          for(int j=1;j<=lb;j++)
        {
            dp[i][j]=max1(dp[i][j-1]+mo[b[j]][4],dp[i-1][j]+mo[a[i]][4],dp[i-1][j-1]+mo[a[i]][b[j]]);
        }
	/*for(int i=1;i<=la;i++)
          for(int j=1;j<=lb;j++)
        {
            dp[i][j]=max(dp[i][j],dp[i][j-1]+mo[b[j]][4]);
            dp[i][j]=max(dp[i][j],dp[i-1][j]+mo[a[i]][4]);
            dp[i][j]= max(dp[i][j],dp[i-1][j-1]+mo[a[i]][b[j]]);
        }*///别人的代码
    cout<<dp[la][lb];
    return 0;
} 
