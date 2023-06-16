#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstdlib>
using namespace std;
const int maxn=1e5+7;
int N,all,root;
struct Treap{
	int l,r,num,sz,v,p;
}TREE[maxn];
#define L(x) TREE[x].l//左儿子 
#define R(x) TREE[x].r//右儿子 
#define szof(x) TREE[x].sz//树的大小 
#define val(x) TREE[x].v//节点权值 
#define c(x) TREE[x].num//重复的次数 
#define pri(x) TREE[x].p//节点的优先级 
inline int Read()
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
inline void Zig(int &x)
{
	int y=L(x);
	L(x)=R(y);
	R(y)=x;
	szof(y)=szof(x);
	szof(x)=szof(L(x))+szof(R(x))+c(x);
	x=y;
	return ;
}
inline void Zag(int &x)
{
	int y=R(x);
	R(x)=L(y);
	L(y)=x;
	szof(y)=szof(x);
	szof(x)=szof(L(x))+szof(R(x))+c(x);
	x=y;
	return ;
}
inline void Insert(int &i,int v)
{
	if(!i)
	{
		i=++all;val(i)=v;pri(i)=rand();
		c(i)=szof(i)=1;L(i)=R(i)=0;
		return ;
	}
	++szof(i);
	if(val(i)==v) ++c(i);
	else if(v<val(i))
	{
		Insert(L(i),v);
		if(pri(L(i))<pri(i)) Zig(i);
	}
	else
	{
		Insert(R(i),v);
		if(pri(R(i))<pri(i)) Zag(i);
	}
	return ;
}
inline void Del(int &i,int &v)
{
	if(v==val(i))
	{
		if(c(i)>1) --c(i),--szof(i);
		else if(!L(i)||!R(i)) i=L(i)+R(i);//等于二者中不为零的那一个 
		else if(pri(L(i))<pri(R(i))) Zig(i),Del(i,v);
		else Zag(i),Del(i,v);
		return ;
	}
	--szof(i);
	if(v<val(i)) Del(L(i),v);
	else Del(R(i),v);
	return ;
}
inline int Forw(int &v)
{
	int x=root,re=-0x7f7f7f7f;
	while(x)
	{
		if(val(x)<v) re=val(x),x=R(x);
		else x=L(x);
	}
	return re;
}
inline int Backw(int &v)
{
	int x=root,re=0x7f7f7f7f;
	while(x)
	{
		if(val(x)>v) re=val(x),x=L(x);
		else x=R(x);
	}
	return re;
}
inline int KTH(int k)
{
	int x=root,re=0;
	while(x)
	{
		if(szof(L(x))<k&&szof(L(x))+c(x)>=k) return val(x);
		if(szof(L(x))>=k) x=L(x);
		else k-=szof(L(x))+c(x),x=R(x);
	}
	return 0;
}
inline int TH(int v)
{
	int x=root,re=0;
	while(x)
	{
		if(v==val(x)) return re+szof(L(x))+1;
		if(v<val(x)) x=L(x);
		else re+=szof(L(x))+c(x),x=R(x);
	}
	return re;
}

void ZXBL(const int x)
{
	if(L(x)) ZXBL(L(x));
	printf("%d->",val(x));
	if(R(x)) ZXBL(R(x));
} 

int main()
{
    freopen("Treap.in","r",stdin);
    freopen("Board.out","w",stdout);
	N=Read();
	int op,x;
	for(int i=1;i<=N;i++)
	{
        printf("case %d:\n",i);
        ZXBL(root);printf("\n");
		op=Read();x=Read();
		if(op==1)
			Insert(root,x);
		else if(op==2)
			Del(root,x);
		else if(op==3)
			printf("%d\n",TH(x));
		else if(op==4)
			printf("%d\n",KTH(x));
		else if(op==5)
			printf("%d\n",Forw(x));
		else
			printf("%d\n",Backw(x));
	}
	return 0;
}
