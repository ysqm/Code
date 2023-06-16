#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 10000, maxm = 50000;

int n, m, q, father[maxn], head[maxn], cnt, h[maxn], f[maxn][20], g[maxn][20], ans = 1000000000;
bool vis[maxn];

struct node
{
    int x, y, z;
}a[maxm + 42];

struct node2
{
    int nextt, to, w;
}e[maxn * 2 + 42];

bool cmp(node x, node b)
{
    return x.z > b.z;
}

void dfs(int u, int depth)
{
    vis[u] = true;
    h[u] = depth;
    for (int i = head[u]; i; i = e[i].nextt)
        if (!vis[e[i].to])
        {
        f[e[i].to][0] = u;
        g[e[i].to][0] = e[i].w;
        dfs(e[i].to, depth + 1);
        }
    return;
}

int Find(int x)
{
    if (father[x] != x)
        father[x] = Find(father[x]);
    return father[x];
}

void add(int p, int q, int v)
{
    e[++cnt].to = q;
    e[cnt].nextt = head[p];
    head[p] = cnt;
    e[cnt].w = v;
}

void kruskal()
{
    sort(a + 1, a + 1 + m, cmp);
    for (int i = 1; i <= n; i++)
        father[i] = i;
    for (int i = 1; i <= m; i++)
    {
        int fx = Find(a[i].x), fy = Find(a[i].y);
        if (fx == fy)
            continue;
        father[fx] = fy;
        add(a[i].x, a[i].y, a[i].z);
        add(a[i].y, a[i].x, a[i].z);
    }
}

int lca(int x, int y)
{
    ans = 1000000000;
    if (x == y)
        return 0;
    if (h[x] < h[y]){
    	int temp = y;
    	y = x;
    	x = temp;
	} 
    int k = int(log2(h[x]));
    for (int i = k; i >= 0; i--)
        if (h[x] - (1 << i) >= h[y])
        {
        ans = min(ans, g[x][i]);
        x = f[x][i];
        }
    if (x == y)
        return ans;
    for (int i = k; i >= 0; i--)
        if (f[x][i] && f[x][i] != f[y][i])
        {
        ans = min(ans, min(g[x][i], g[y][i]));
        x = f[x][i];
        y = f[y][i];
        }
    ans = min(ans, min(g[x][0], g[y][0]));
    return ans;
}

int main()
{
    memset(g, 127, sizeof(g));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
        scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
    kruskal();
    scanf("%d", &q);
    for (int i = 1; i <= n; i++)
        if (!vis[i])
       		dfs(i, 1);
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 1; i <= n; i++)
            if (f[i][j - 1]){
        		f[i][j] = f[f[i][j - 1]][j - 1];
        		g[i][j] = min(g[i][j - 1], g[f[i][j - 1]][j - 1]);
            }
    for (int i = 1; i <= q; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if (Find(x) != Find(y))
            printf("-1\n");
        else
            printf("%d\n", lca(x, y));
    }

    return 0;
}
