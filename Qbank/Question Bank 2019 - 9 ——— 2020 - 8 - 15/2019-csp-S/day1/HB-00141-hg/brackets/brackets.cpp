#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#define N 500500

using namespace std;
typedef long long ll;

int n;

struct edge
{
	int u;
	int v;
	int nxt;
} e[N*2];
int head[N],tot;

void add(int u,int v)
{e[++tot]=(edge){u,v,head[u]};head[u]=tot;}

char kh[N];
int f[N],w[N],k[N],pre[N];
long long Ans=0;

int read()
{
	int ans=0;
	char k;
	k=getchar();
	while(k<'0' || k>'9') k=getchar();
	while(k<='9' && k>='0') {ans*=10;ans+=(k-'0');k=getchar();}
	return ans;
}

void solve1()
{
	int i,j,v;
	for(i=1;i<=n;i++) pre[i]=pre[i-1]+w[i];
	for(i=1;i<=n;i++)
	{
		k[i]=k[i-1];
		for(j=1;j<=i;j++)
		{
			if(pre[i]-pre[j-1]!=0) continue; 
			int sum=0;
			for(v=j;v<=i;v++) 
			{
				sum+=w[v]; 
				if(sum<0) break;
			}
			if(sum==0) k[i]++;
		}
	}
	for(i=1;i<=n;i++) Ans^=(1ll*i*k[i]);
	printf("%lld",Ans);
	return;
} 

int main()
{
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	bool flag1=1;
	int i,j;
	n=read();
	scanf("%s",kh);
	for(i=1;i<=n;i++) w[i]=(kh[i-1]=='(')?1:-1;
	for(i=2;i<=n;i++)
	{
		f[i]=read();
		if(f[i]!=i-1) flag1=0;
		add(i,f[i]);add(f[i],i);
	} 
	if(flag1) solve1();
	//else solve();
	return 0;
}
