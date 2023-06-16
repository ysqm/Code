# include <bits/stdc++.h>
# define N 

inline int Max(const int& a,const int b){return a > b ? a : b;}

struct edge
{
	int from,to,Symbol;
} e[N + 42];

int head[N + 42],tot,cnt;

inline int add_edge(const int& u,const int& v)
{
	e[++tot].from = 
	
	head[u] = tot;
}
