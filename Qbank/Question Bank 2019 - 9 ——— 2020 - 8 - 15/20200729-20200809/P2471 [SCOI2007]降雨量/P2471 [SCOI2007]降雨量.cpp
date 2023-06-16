# include <algorithm>
# include <cstdio>
# include <cmath>
# define reg register
# define N 50000
# define Ls(i) (i<<1)
# define Rs(i) (i<<1|1)

inline int Read()
{
    int x = 0,f=1;char ch = getchar();

    while(ch < '0' || ch > '9') {if(ch == '-') f = -1;ch = getchar();}

    while(ch >= '0' && ch <= '9'){x = x * 10 + (ch ^ 48);ch = getchar();}

    return x*f;
}

inline void print(int x)
{
    char s[13];
    reg int top=0;

	if(x == 0) s[++top] = '0'; 

    while(x > 0)
    {
        s[++top] = x % 10 + '0';
        x /= 10; 
    }

    while(top) putchar(s[top--]);

    putchar(32);
}

struct Node
{
	int L,R,Max;
	
	Node(const int Ma_=0,const int L_=0,const int R_=0):Max(Ma_),L(L_),R(R_){}
	
} Seg[(N << 2) + 42];

int n,y[N + 42],r[N + 42],m;

inline int Find(const int x)
{
	reg int l = 1,r = n,mid;
	
	while(l < r)
	{
		mid = (r+l)>>1;
		
		if(y[mid] >= x) r = mid;
		else  l = mid+1;
	}
	
	return l;
}

inline Node Merge(const Node ls,const Node rs){return  Node(ls.Max > rs.Max ? ls.Max : rs.Max,ls.L,rs.R);}

void Build(const int L,const int R,const int K)
{
	if(L == R) Seg[K] = Node(r[L],L,R);
	
	else
	{
		int mid = (L + R)>>1;
		
		Build(L,mid,Ls(K));
		Build(mid+1,R,Rs(K));
		
		Seg[K] = Merge(Seg[Ls(K)],Seg[Rs(K)]);
	}
}

Node Query(const int AL,const int AR,const int K)
{
	if(AL <= Seg[K].L && AR >= Seg[K].R) return Seg[K];
	
	int mid = Seg[Ls(K)].R;
	
	if(AR <= mid) return Query(AL,AR,Ls(K));
	else if(AL > mid) return Query(AL,AR,Rs(K));
	else return Merge(Query(AL,AR,Ls(K)),Query(AL,AR,Rs(K)));
}



int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	
	scanf("%d",&n);
	
	for(reg int i = 1; i <= n ; ++i) {y[i] = Read();r[i] = Read();}
	
	m = Read();
	
	reg Node cur; 
	int X,Y,L,R;//,rr,ll
	
	Build(1,n,1);
	
	while(m--)
	{
		Y = Read();X = Read();
		
		if(Y > X) puts("false");
		else
		{
			cur = Node(0,0,0);
			
			L = Find(Y);R = Find(X);//ll = Find(y+1);rr = Find(x-1);
			
			if(y[L] != Y) --L;
			
			if(R-1>=L+1) cur = Query(L+1,R-1,1);
			
			if((cur.Max >= r[R] && y[R] == X) || (cur.Max >= r[L] && y[L] == Y) || (r[L] < r[R] && y[R] == X && y[L] == Y)) puts("false");
			else if(R-L != y[R]-y[L] || y[L] != Y || y[R] != X) puts("maybe");
			else puts("true");
		}
	}
	
	return 0;
} 
