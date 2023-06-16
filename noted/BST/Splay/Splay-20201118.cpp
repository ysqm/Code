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
    //bool mark;//区间反转标记
    int repetition,Value,Size;
    Tree_node(){}
    ~Tree_node(){}
};

Tree_node Tr[Max_Tree_Size+5];

# define Son(p,side) Tr[p].Son[side]
# define rep(p) Tr[p].repetition
# define tv(p) Tr[p].Value
# define sz(p) Tr[p].Size
//# define mk(p) Tr[p].mark
# define fa(p) Tr[p].father
# define Wf(p) (Son(fa(p),1) == p)
# define Update(p) sz(p) = sz(Son(p,0))+sz(Son(p,1))+rep(p)

int Create(const int Val)
{
    tv(++tot_size) = Val;
    rep(tot_size) = sz(tot_size) = 1;
    fa(tot_size) = Son(tot_size,0) = Son(tot_size,1) = 0;
    //mk(tot_size) = false;
    return tot_size; 
}

void Connect(const int father,const int x,const int Side){Son(father,Side) = x;fa(x) = father;}

void Rotate(const int x,const int Side)
{
    int p = fa(x);
    Connect(p,Son(x,Side^1),Side);
    Connect(fa(p),x,Wf(p));
    Connect(x,p,Side^1);
    Update(p);Update(x);
}

void Raise(const int x){Rotate(x,Wf(x));}

void Splay(int x,int Target = 0)
{
	if(x == 0) return;
    while(fa(x) != Target)
    {
        int father = fa(x);
        if(fa(father) != Target) (Wf(father) == Wf(x)) ? Raise(father) : Raise(x);
        Raise(x);
    }
    if(Target == 0) rt = x;
}

void Find(const int Val)
{
    int p = rt;
    if(p == 0) return;
    while(Son(p,Val > tv(p)) && Val != tv(p)) p = Son(p,Val > tv(p));
    Splay(p);
}

void Insert(const int Val)
{
    int p = rt,father = 0;
    while(p != 0 && Val != tv(p)) {father = p;p = Son(p,Val > tv(p));}
    if(tv(p) == Val) ++rep(p);
    else if(father == 0) p = Create(Val);
    else fa(Son(father,Val > tv(father)) = p = Create(Val)) = father;
    Splay(p);
}

int Max(const int x,const int y){return x < y ? y : x;}
int Min(const int x,const int y){return x < y ? x : y;}

int Get_Pre(const int Val)
{
    int p = rt,res = -INF;
    while(p)
    {
    	if(Val > tv(p)){res = Max(res,tv(p));p = Son(p,1);}
		else p = Son(p,0);
	}
    return res;
}

int Get_Suf(const int Val)
{
    int p = rt,res = INF;
    while(p)
    {
    	if(Val < tv(p)) {res = Min(res,tv(p));p = Son(p,0);}
		else p = Son(p,1);
	}
    return res;
}

void Delete(const int p,const int Val)
{
	if(tv(p) == Val)
	{
		if(rep(p) > 1) --rep(p);
		else if(Son(p,0)){Raise(Son(p,0));Delete(Son(p,1),Val);}
		else if(Son(p,1)){Raise(Son(p,1));Delete(Son(p,0),Val);}
		else Son(fa(p),Wf(p)) = 0;
		Update(p);
		return;
	}
	Delete(Son(p,Val > tv(p)),Val);
	Update(p);
}

inline int Get_Rank(const int Val)//查询 val 的排�?
{
    int kth = 0,x = rt;
    while(x)
    {
        if(tv(x) == Val) return kth + sz(Son(x,0)) + 1;
        if(tv(x) < Val) {kth += rep(x) + sz(Son(x,0));x = Son(x,1);}
        else x = Son(x,0);
    }
    return kth;
}

inline int Get_kth(int k)
{
    int x = rt;
    while(x)
    {
        if(sz(Son(x,0)) < k)
        {
            if(sz(Son(x,0)) + rep(x) >= k) return tv(x);
            else {k = k - sz(Son(x,0)) - rep(x);x = Son(x,1);}
        }
        else x = Son(x,0);
    }
    return x;
}

int n,m,opt,x,lst = 0,ans;

int main()
{
	//freopen("P3369_3.in","r",stdin); 
    
    return 0;
}

