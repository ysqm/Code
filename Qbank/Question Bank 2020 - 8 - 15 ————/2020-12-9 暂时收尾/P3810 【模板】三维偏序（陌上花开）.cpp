
# include <queue>
# include <cmath>
# include <cstring>
# include <cstdio>
# include <algorithm>
# define lowbit(x) (x&(~x+1))
# define Gc (SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
char BB[1<<15],*SS=BB,*TT=BB;
inline int Read()
{
    register int x = 0;char ch = Gc;
    
    while(ch < '0' || ch > '9')ch = Gc;
    
    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = Gc;}
    
    return x;
}

template<class T>
inline void Print(T x)
{
	static int ch[41];
	register int top = 0;
	do{ch[top++] = x%10;x /= 10;}while(x);
	while(top) putchar('0'+ch[--top]);
    putchar('\n');
}

const int N = 2e5;

struct node
{
    int num_a,num_b,num_c,Wi,ans;
    bool operator < (const node& b)const
    {return ((num_a!=b.num_a) ? num_a<b.num_a : ((num_b!=b.num_b) ? num_b<b.num_b : num_c<b.num_c));}
} a[N+5];

int tr[N+5],n,maxa,m,ans[N+5];

void Insert(register int x,const int data)
{
	while(x <= maxa)
	{
		tr[x] += data;
		x += lowbit(x);
	}
}
int Sum(register int x)
{
	register int res=0;
	while(x)
	{
		res+=tr[x];
		x -= lowbit(x);
	}
	return res;
}

int id[N+5],tmp[N+5],ANS[N+5];

void Solve(const int L,const int R)
{
    if(L+1 == R) return;
    else 
    {
    	int mid = (L+R)/2;
        Solve(L,mid);//左闭右开区间
        Solve(mid,R);
        //for(int i = L; i < mid ; ++i) Insert(a[id[i]].num_c,a[id[i]].Wi);//把左区间第三维的值插入树状数组
        int *pl = id+L,*pr = id+mid,p = L,*ple = id+mid,*pre = id+R;
        while(p < R)//按 num_b 降序排列
        {
            if(pr == pre || (pl != ple && a[*pl].num_b <= a[*pr].num_b))
            {
                Insert(a[*pl].num_c,a[*pl].Wi);
                tmp[p++] = *pl++;
            }
            else if(pl == ple || (pr != pre || a[*pl].num_b > a[*pr].num_b))
            {
                a[*pr].ans += Sum(a[*pr].num_c);
                tmp[p++] = *pr++;
            }
        }
        p = L;
        while(p < R)
        {
            if(p < mid) Insert(a[id[p]].num_c,-a[id[p]].Wi);
            id[p] = tmp[p];
            ++p;
        }
    }
}

int main()
{
    n = Read();maxa = Read();
    for(int i = 1; i <= n ; ++i)
    {
        a[i].num_a = Read();
        a[i].num_b = Read();
        a[i].num_c = Read();
    }
    std::sort(a+1,a+n+1);m = 1;
    for(int i = 2; i <= n ; ++i)
    {
        if(a[i].num_a != a[m].num_a || a[i].num_b != a[m].num_b || a[i].num_c != a[m].num_c) a[++m] = a[i];
        else ++a[m].Wi;
    }
    for(int i = 1; i <= m ; ++i) a[id[i] = i].ans = a[i].Wi++;
    Solve(1,m+1);
    for(int i = 1; i <= m ; ++i) ANS[a[i].ans] += a[i].Wi;
    for(int i = 0; i <  n ; ++i) Print(ANS[i]);
    return 0;
}