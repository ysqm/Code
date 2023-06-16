/*
    提交过的题目 : 
            洛谷P3165 [CQOI2014]排序机械臂
            洛谷P4402 [Cerc2007]robotic sort 机械排序
            LOJ#2241. 「CQOI2014」排序机械臂
*/
# include <ctime>
# include <cmath>
# include <queue>
# include <vector>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define LL long long
# define File(x) freopen(#x".in","r",stdin)//;freopen(#x".out","w",stdout)
# define N 100000
# define Gc getchar()//(SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
char BB[1<<15],*SS=BB,*TT=BB;
inline int Read()
{
    register int x = 0,f = 1;char ch = Gc;
    
    while(ch < '0' || ch > '9'){if(ch == '-') f = -1;ch = Gc;}
    
    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = Gc;}
    
    return f < 0 ? ~x+1 : x;
}

const int INF = 1e9;

template<class T> T ABS(const T x){return x < 0 ? (~x+1) : x;}

int tot_size,rt;
static const int Max_Tree_Size = 2e6;

struct Tree_node
{
    int Son[2],father;
    bool mark;//鍖洪棿鍙嶈浆鏍囪
    int Size;
    Tree_node(){}
    ~Tree_node(){}
};

Tree_node Tr[Max_Tree_Size+5];

# define Son(p,side) Tr[p].Son[side]
# define sz(p) Tr[p].Size
# define mk(p) Tr[p].mark
# define fa(p) Tr[p].father
# define Wf(p) (Son(fa(p),1) == p)
# define PushUp(p) sz(p) = sz(Son(p,0))+sz(Son(p,1))+1
# define Connect(father,x,Side) Son(fa(x) = father,Side) = x
# define Raise(x) Rotate(x,Wf(x))
# define Swap(x,y) (x^=y^=x^=y)

void PushDown(const int x)
{
	if(x && mk(x))
	{
		mk(Son(x,0)) ^= 1;
		mk(Son(x,1)) ^= 1;
		Swap(Son(x,0),Son(x,1));
		mk(x) = 0;
	}
}
void Rise(int x)
{
	PushDown(fa(x));PushDown(x);
	int p = fa(x),Side = Wf(x);
	Connect(p,Son(x,Side^1),Side);
	Connect(fa(p),x,Wf(p));
	Connect(x,p,Side^1);
	PushUp(p);PushUp(x);
}
void Splay(int x,int Target = 0)
{
	int gf;
	while(fa(x) != Target)
	{
		gf = fa(x);
		if(fa(gf) != Target) Rise(((Wf(gf) == Wf(x)) ? gf : x));
		Rise(x);
	}
	if(Target == 0) rt = x;
}
struct Node{int x,idx;} a[N+5];
void Build(const int L,const int R,int& p){int mid = (L+R)/2;sz(p = mid) = 1;if(L == R) return ;L < mid && (Build(L,mid-1,Son(p,0)),fa(Son(p,0)) = p);R > mid && (Build(mid+1,R,Son(p,1)),fa(Son(p,1)) = p);PushUp(p); }

/*int Find_Pos(const int p,int k)
{
    PushDown(p);
    if(k > p) return Find_Pos(Son(p,1&(Son(p,1)>Son(p,0))),k);
    else if(k < p) return Find_Pos(Son(p,1^(Son(p,1)>Son(p,0))),k);
    else {Splay(p);return;}
}*/

int Find(int k)
{
    int p = rt;
    while(true)
    {
        PushDown(p);
        if(k <= sz(Son(p,0))) p = Son(p,0);
        else 
        {
            k -= sz(Son(p,0))+1;
            if(k == 0) return p;
            p = Son(p,1);
        }
    }
}

/*void Rever(const int L,const int R)
{
    int l = Find(L-1),r = Find(R+1);
    Splay(l);Splay(r,l);
    mk(Son(Son(l,1),0)) ^= 1;
}*/

void show(int p)
{
	PushDown(p);
	if(Son(p,0)) show(Son(p,0));
	printf("%d ",a[p].idx);
	if(Son(p,1)) show(Son(p,1)); 
} 

bool comp(const Node& a,const Node& b){return a.x ^ b.x ? a.x < b.x : a.idx < b.idx;}

int n,m;
int Ans[N+5];

int main()
{
	//freopen("P3369_3.in","r",stdin); 
    n = Read();
    for(int i = 1; i <= n ; ++i) a[a[i].idx = i].x = Read();
    std::sort(a+1,a+n+1,comp);
    Build(1,n+2,rt);
    //show(rt);
    for(int i = 1; i <= n ; ++i)
    {
    	
        Splay(a[i].idx+1);Ans[i] = sz(Son(rt,0));
        
        int l = Find(i),r = Find(Ans[i]+2);
        Splay(l);
		//show(rt);printf("\n");
		Splay(r,l);
    	mk(Son(Son(rt,1),0)) ^= 1;
    }
    for(int i = 1; i <= n ; ++i) printf("%d ",Ans[i]);
    return 0;
}
