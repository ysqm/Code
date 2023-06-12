/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
=======`-.____`-.___\_____/___.-`____.-'=======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  	 Buddha said:
         	 	 The program have no BUG.
         	 	 The program can pass the text.	 	 
*/
#include<algorithm>
#include<iostream>
#include<cstdio>
#define N 100005
using namespace std;
struct node
{
	int u,v,l,col;
}a[N],b[N];
bool comp(node aa,node bb)
{
	return aa.l==bb.l?aa.col<bb.col:aa.l<bb.l;
}
int f[N],n,m,ned;
int get_f(int now)
{
	return now==f[now]?f[now]:f[now]=get_f(f[now]);
}

int l=-100,r=100,ans,us;
bool canit(int mid)
{
	int tot=ans=0,get=0;
	for(int i=1;i<=m;++i)
	{
		b[i]=a[i];
		if(a[i].col==0) b[i].l+=mid;
	}
	sort(b+1,b+m+1,comp);
	for(int i=1;i<=n;++i) f[i]=i;
	for(int i=1;i<=m;++i)
	{
		int u=get_f(b[i].u),v=get_f(b[i].v);
		if(u==v) continue;
		tot++;
		if(tot>790)
		{
			int idx;
			++idx;
		}
		f[u]=v;ans+=b[i].l;
		get+=b[i].col==0;
		if(tot+1==n) break;
	}
	return get>=ned;
}
int main()
{
	scanf("%d%d%d",&n,&m,&ned);
	for(int i=1;i<=m;++i)
	scanf("%d%d%d%d",&a[i].u,&a[i].v,&a[i].l,&a[i].col),a[i].u++,a[i].v++;
	for(int i = 1; i <= m ; ++i)
		if(a[i].col == 0 && a[i].l == 86 && ((a[i].u == 310 && a[i].v == 311) || (a[i].u == 311 && a[i].v == 310))) 
			puts("Yes");
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(canit(mid)) l=mid+1,us=mid;
		else r=mid-1;
	}
	canit(us);
	printf("%d\n",ans-ned*us);
	return 0;
}
