#include<map>
#include<string>
#include<iostream>
#define F(k,l,r) for(int k=l;k<=r;++k)
using namespace std;
int n,m,G[105][105],f[105][105],ans=1;
string s1,s2;
map<string,int> p;
int main()
{
    cin>>n>>m;
    F(i,1,n){cin>>s1;p[s1]=i;}
    F(i,1,m){cin>>s1>>s2;G[p[s1]][p[s2]]=G[p[s2]][p[s1]]=1;}
    f[1][1]=1;
    F(i,1,n)
		F(j,i+1,n)
			F(k,1,j-1)
				if(G[j][k]&&f[i][k])f[i][j]=f[j][i]=((f[i][j]<=f[i][k])?f[i][k]+1:f[i][j]);
    F(i,1,n)if(G[i][n])ans=(ans<f[i][n]?f[i][n]:ans);
    cout<<ans;
    return 0;
}
/*
9 9
Vancouver
Yellowknife
Edmonton
Calgary
fhhh
Winnipeg
Toronto
Montreal
Halifax
fhhh Winnipeg
fhhh Montreal
Vancouver Edmonton
Calgary Winnipeg
Winnipeg Toronto
Toronto Halifax
Montreal Halifax
Edmonton fhhh
Edmonton Yellowknife
Edmonton Calgary
*/
