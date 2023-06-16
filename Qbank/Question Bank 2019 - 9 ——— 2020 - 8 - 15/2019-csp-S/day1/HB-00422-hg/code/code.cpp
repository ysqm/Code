#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;

const int maxn = 1e2;
typedef unsigned long long ull;
int t[maxn];
ull pow[maxn],n,k;

ull read()
{	ull s = 1,w = 0;
	char ch = getchar();
	while(!isdigit(ch))	{	if(ch == '-')	s = -1;ch = getchar();}
	while(isdigit(ch))	w = w * 10 + ch - '0',ch = getchar();
	return s * w;
}

void pre()
{	pow[0] = 1;
	for(int i = 1;i <= 63;i++)
		pow[i] = pow[i - 1] << 1;
	pow[64] = pow[63] + (pow[63] - 1);
}
void dfs(ull step,ull pos)
{	if(step == 0)	return;
	if(pos <= pow[step] / 2)
	{	t[step] = 0;
		dfs(step - 1,pos);
	}
	else
	{	t[step] = 1;
		dfs(step - 1,pow[step] - pos + 1);
	}
	return;
}


int main()
{	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	n = read(),k = read();
	pre();
	dfs(n,k + 1);
	for(int i = n;i > 0;i--)
		printf("%d",t[i]);
	return 0;
}
