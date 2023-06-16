#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct E{
	int u,v;
}e[2000007];
int first[2007],nt[2000007],ES;
inline void addE(int u,int v)
{
	e[++ES]=(E){u,v};
	nt[ES]=first[u];
	first[u]=ES;
	return ;
}
int sum;
int N,M,eS;
inline int R()
{
	char c;
	int re,f=1;
	while((c=getchar())>'9'||c<'0')
	if(c=='-') f=-1;
	re=c-48;
	while((c=getchar())>='0'&&c<='9')
	re=re*10+c-48;
	return re*f;
}
bool book[2007];
int match[2007];
inline bool dfs(int u)
{
	int v;
	for(int i=first[u];i;i=nt[i])
	{
		v=e[i].v;
		if(!book[v])
		{
			book[v]=true;
			if(!match[v]||dfs(match[v]))
			{
				match[v]=u;match[u]=v;
				return true;
			}
		}
	}
	return false;
}
int main()
{
	freopen("P3386_1.in","r",stdin);
	N=R();M=R();eS=R();
	int u,v;
	for(int i=1;i<=eS;i++)
	{
		u=R();v=R();
		if(u>N||v>M||u<1||v<1) continue;
		addE(u,N+v);
		addE(N+v,u);
	}
	for(int i=1;i<=N;i++)
	{
		memset(book,0,sizeof(book));
		if(dfs(i))printf("µÚ%d´Î %d\n",i,++sum);
	}
	printf("%d",sum);
	return 0;
}
