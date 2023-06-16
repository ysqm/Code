# include <cstdio>
# include <algorithm>
# define reg register
# define N 200000
# define Ls(i) Seg[i].ls
# define Rs(i) Seg[i].rs
# define S(i) Seg[i].sum
# define Gc (SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
char BB[1<<15],*SS=BB,*TT=BB;
inline int Read()
{
	register int x = 0;char ch = Gc;

	while(ch < '0' || ch > '9')ch = Gc;

	while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = Gc;}

	return x;
}

struct Node
{
	int sum,ls,rs;
	
	Node(const int sum_=0,const int Ls_=0,const int Rs_=0):ls(Ls_),rs(Rs_),sum(sum_){}
};

Node Seg[(N << 5) + 42];
int tot;

void Build(int& K,const int L,const int R)
{
	K = ++tot;
	
	if(L == R) return;
	
	int mid = (L+R)>>1;
	
	Build(Seg[K].ls,L,mid);
	Build(Seg[K].rs,mid+1,R);
}

int Modify(const int Target,const int L,const int R,const int K)
{
	int New_Node = ++tot;
	
	Seg[New_Node] = Seg[K];++Seg[New_Node].sum;
	
	if(L == R) return New_Node;
	
	int mid = (L+R)>>1;
	
	if(Target <= mid) Ls(New_Node) = Modify(Target,L,mid,Ls(New_Node)); 
	else Rs(New_Node) = Modify(Target,mid+1,R,Rs(New_Node));
	
	return New_Node;
}

int Query(const int Target_L,const int Target_R,const int L,const int R,const int k)
{
	int mid = (L+R)>>1,x = S(Ls(Target_R)) - S(Ls(Target_L));
	
	if(L == R) return L;
	
	if(x >= k) return Query(Ls(Target_L),Ls(Target_R),L,mid,k);
	else return Query(Rs(Target_L),Rs(Target_R),mid+1,R,k-x);
}

int n,m,a[N+5],b[N+5],q,rt[N+5];

inline int Find(const int x)
{
    register int l = 1,r = q,mid;

    while(l < r)
    {
        mid = (l+r)>>1;
        if(b[mid] >= x) r = mid;
        else l = mid+1;
    }

    return l;
}

int main()
{
	//freopen("ysqm.in","r",stdin);
    n = Read();m = Read();

    for(reg int i = 1; i <= n ; ++i) a[i] = b[i] = Read();

    std::sort(b+1,b+n+1);
    q = std::unique(b+1,b+n+1)-b-1;
    Build(rt[0],1,q);

    for(reg int i = 1; i <= n ; ++i)
    {
        a[i] = Find(a[i]);
        rt[i] = Modify(a[i],1,q,rt[i-1]);
    }

    register int l,r,k;

    while(m--)
    {
        l = Read();r = Read();k = Read();
        int KD =  Query(rt[l-1],rt[r],1,q,k);
        printf("%d\n",b[KD]);
    }

    return 0;
}


