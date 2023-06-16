# include <ctime>
# include <cmath>
# include <queue>
# include <vector>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define LL long long
# define UL unsigned int
# define File(x) freopen(#x".in","r",stdin)//;freopen(#x".out","w",stdout)
# define N 100000
# define Gc getchar()//(SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
char BB[1<<15],*SS=BB,*TT=BB;
inline int Read()
{
    register int x = 0;char ch = Gc;

    while(ch < '0' || ch > '9')ch = Gc;

    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = Gc;}

    return x;
}

int Delta,res;
char s[10];
int n,nmin_,x,rt,His_Init;
const int INF = 1e9;
const LL MAX = 1e18;

template<class T> T ABS(const T x){return x < 0 ? (~x+1) : x;}

int tot_size;
UL randomx;
static const int Max_Tree_Size = 1e5;
static const int Seed_ = 1e9+9,_Increment = 1e9+7;
inline UL rnd(){return randomx = (randomx * Seed_+_Increment);}

struct Tree_node
{
    int Son[2];
    int repetition,Value,Size;
    UL Heap_Value;
    Tree_node(){}
    ~Tree_node(){}
};

Tree_node Tr1[Max_Tree_Size+5];

# define Son(p,side) Tr1[p].Son[side]
# define rep(p) Tr1[p].repetition
# define hv(p) Tr1[p].Heap_Value
# define tv(p) Tr1[p].Value
# define sz(p) Tr1[p].Size

int Create(const int Val)
{
    rep(++tot_size) = 1;
    hv(tot_size) = rnd();
    tv(tot_size) = Val;
    sz(tot_size) = 1;
    Son(tot_size,0) = Son(tot_size,1) = 0;
    return tot_size;
}

void Rotate(int& p,int Side)
{//把 side 这边的孩子转上来
    int x = p;
    p = Son(p,Side);
    Son(x,Side) = Son(p,Side^1);
    Son(p,Side^1) = x;
    sz(x) = sz(Son(x,0))+sz(Son(x,1))+rep(x);
    sz(p) = sz(Son(p,0))+sz(Son(p,1))+rep(p);
}

void Insert(const int Val,int &x)
{
    if(x == 0) x = Create(Val);
    else 
    {
        ++sz(x);
        if(tv(x) == Val) ++rep(x);
        else if(Val < tv(x)){Insert(Val,Son(x,0));if(hv(x) < hv(Son(x,0))) Rotate(x,0);}
        else {Insert(Val,Son(x,1));if(hv(x) < hv(Son(x,1))) Rotate(x,1);}
    }
}

int Get_Val(int p,int k)
{
    while(k)
    {
        if(sz(Son(p,1)) < k)
        {
            if(sz(Son(p,1))+rep(p) >= k) return tv(p);
            else {k = k-sz(Son(p,1))-rep(p);p = Son(p,0);}
        }
        else p = Son(p,1);
    }
    return -1;
}

void Clear_Son(int& d)
{
    if(Son(d,1)) Clear_Son(Son(d,1));
    if(Son(d,0)) Clear_Son(Son(d,0));
    d = 0;
}
void Delete(int& x)
{
	if(x == 0) return ;
	if(tv(x) < nmin_-Delta)
	{
		int d = x;
		x = Son(x,1);
		Son(d,1) = 0;
		Clear_Son(d);
    	sz(x) = sz(Son(x,0))+sz(Son(x,1))+rep(x);
		Delete(x);
	}
	else Delete(Son(x,0));
	sz(x) = sz(Son(x,0))+sz(Son(x,1))+rep(x);
}

int main()
{
    File(P1486_1);
    n = Read();nmin_ = Read();
    Insert(INF,rt);
    //Insert(-INF,rt);
    for(int i = 1; i <= n ; ++i)
    {
        scanf("%s%d",s,&x);
        switch (s[0])
        {
            case 'I':
                    if(x < nmin_) break;
                    ++His_Init;
                    Insert(x-Delta,rt);
                    break;
            case 'A':
                    Delta += x;
                    break;
            case 'S':
                    Delta -= x;
                    Delete(rt);
                    break;
            case 'F':
            		++x;
            		if(sz(rt) < x) printf("-1\n");
            		else printf("%d\n",Get_Val(rt,x)+Delta);
                    break;
        }
    }
    printf("%d",His_Init-sz(rt)+1);
    return 0;
}

