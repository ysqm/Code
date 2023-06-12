#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 2100;

vector <int> G[maxn];
int dot[maxn],in[maxn],id[maxn];

void clear(int n)
{	memset(in,0,sizeof(in));
	memset(dot,0,sizeof(dot));
	memset(id,0,sizeof(id));
	for(int i = 1;i <= n;i++)
		G[i].clear();
}
void work()
{	int n,f1 = 0,f2 = 0;
	scanf("%d",&n);
	for(int i = 1, u;i <= n;i++)
	{	scanf("%d",&u);
		dot[u] = i;
		id[i] = u;
	}
	for(int i = 1, u, v;i < n;i++)
	{	scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
		in[v]++,in[u]++;
	}
	for(int i = 1;i <= n;i++)
	{	if(in[i] != 1)	f1++;
		if(in[i] == 2)	f2++;
	}
	if(f1 == 1)
	{	for(int i = 1, t;i < n;i++)
		{	if(i != id[i])
			{	t = id[dot[id[i]]];
				swap(dot[i],dot[id[i]]);
				swap(id[i],id[t]);
			}
			else
			{	t = id[dot[id[i + 1]]];
				swap(dot[i],dot[id[i + 1]]);
				swap(id[i],id[t]);
			}
		}
		for(int i = 1;i <= n;i++)
			printf("%d ",dot[i]);
		puts("\n");
	}
	else
	{	for(int i = 1;i <= n;i++)	printf("%d ",i);
		puts("\n");
	}
	clear(n);
}

int main()
{	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{	work();
	}
	return 0;
}
