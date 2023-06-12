#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<iostream>
using namespace std;
typedef long long LL;
int st[500005],Top=-1;
struct E{
	int u,v;
}Edge[500005];
int Len;
LL ans;
int first[500005],nt[500005];
char tree[500005];
void DFS(int p,int l,int r,LL num)
{
	LL temp=num;
	int L=l,R=r;
	bool flag=false;
	if(tree[p]=='(') st[++Top]=p;
	else if(Top!=-1)
	{
		if(l!=-1&&r!=-1)
		{
			if(l>=st[Top]&&r<=p) temp++,L=st[Top],R=st[Top];
			else temp+=2,R=p;
			Top--;
		}
		else
		{
			L=st[Top--];
			R=p;
			temp++;
		}
		flag=true;
	}
	if(flag) ans=ans xor (temp*(LL)p);
	for(int i=first[p];i!=-1;i=nt[i])
	{
		DFS(Edge[i].v,L,R,temp);
	}
	return ;
}
int main()
{
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	cin.sync_with_stdio(false);
	memset(first,-1,sizeof(first));
	memset(nt,-1,sizeof(nt));
	cin>>Len;
	cin.getline(tree,sizeof(tree));
	cin.getline(tree+1,sizeof(tree));
	int v;
	for(int i=2;i<=Len;i++)
	{
		cin>>v;
		Edge[i-1]=(E){v,i};
		nt[i-1]=first[v];
		first[v]=i-1;
	}
	DFS(1,-1,-1,0);
	cout<<ans;
	return 0;
}
