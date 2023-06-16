# include <cstdio>
namespace ysys
{
	/*
		Name :常用函数 
		Need :<cstdio> 
		Code by:云岁月书
		Update_Date: 2020/8/9   创建该项目,并添加 unsigned_IO 类型
		Update_Date: 2020/8/10  修正浮点数读入小数点后数字读入的错误,分开fread和getchar版无符号快读，增加Min，Max，Swap 的函数 
		Update_Date: 2020/8/10  讲 long long int 和 long int 合并为一个模板类，精简代码 
	*/
	
	typedef long long LL; 
	
	namespace unsigned_IO_vf
	{
		# define Gc (SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
		
		static char BB[1<<15],*SS=BB,*TT=BB;
		
		template<class T>
		inline T __read()
		{
			register T x = 0;register char ch = Gc;
	
			while(ch < '0' || ch > '9') ch = Gc;
	
			while(ch <= '9' && ch >= '0'){x = x*10 + (ch^48);ch = Gc;}
	
			return x;
		}
		
		inline int Read(){return __read<int>();}
		inline LL ReadL(){return __read<LL>();}
		
		inline double ReadD()
		{
			register double x = 0,y = 1.0;register char ch = Gc;
	
			while(ch < '0' || ch > '9') ch = Gc;
	
			while(ch <= '9' && ch >= '0'){x = x*10 + (ch^48);ch = Gc;}
			
			if(ch == '.')
			{
				ch = getchar();
				
				while(ch <= '9' && ch >= '0'){x = (y /= 10) * (ch^48);ch = Gc;}
			}
			
			return x;
		}
		
		# undef Gc
		
		template<class T>
		inline void Print(T x)
		{
			static int ch[41];
			register int top = 0;
			do{ch[top++] = x%10;x /= 10;}while(x);
			while(top) putchar('0'+ch[--top]);
		}
	}
	
	namespace unsigned_IO_f
	{
		# define Gc getchar()
		
		template<class T>
		inline T __read()
		{
			register T x = 0;register char ch = Gc;
	
			while(ch < '0' || ch > '9') ch = Gc;
	
			while(ch <= '9' && ch >= '0'){x = x*10 + (ch^48);ch = Gc;}
	
			return x;
		}
		
		inline int Read(){return __read<int>();}
		inline LL ReadL(){return __read<LL>();}
		
		inline double ReadD()
		{
			register double x = 0,y = 1.0;register char ch = Gc;
	
			while(ch < '0' || ch > '9') ch = Gc;
	
			while(ch <= '9' && ch >= '0'){x = x*10 + (ch^48);ch = Gc;}
			
			if(ch == '.')
			{
				ch = getchar();
				
				while(ch <= '9' && ch >= '0'){x = (y /= 10) * (ch^48);ch = Gc;}
			}
			
			return x;
		}
		
		# undef Gc
		
		template<class T>
		inline void Print(T x)
		{
			static int ch[41];
			register int top = 0;
			do{ch[top++] = x%10;x /= 10;}while(x);
			while(top) putchar('0'+ch[--top]);
		}
	}
	
	namespace MMS
	{
		template <class T>
		inline T Max(const T a,const T b){return a < b ? b : a;}
		template <class T>
		inline T Min(const T a,const T b){return a > b ? b : a;}
		template <class T>
		inline void Swap(T& a,T& b){a ^= b ^= a ^= b;}
	} 
}
	
# define N 1000000
# define reg register

using namespace ysys::MMS;

struct node
{
	int LIS,LDS,S4,S7;
	bool tag;

	node(const int S4_=0,const int S7_=0,const int Lis=0,const int Lds=0,const bool tag_=0):tag(tag_),LIS(Lis),LDS(Lds),S4(S4_),S7(S7_){}
} Seg[(N<<2)+5];

inline void Merge(node& fa,const node& a,const node& b){fa = node(a.S4+b.S4,a.S7+b.S7,Max(a.LIS+b.S7,a.S4+b.LIS),Max(a.LDS+b.S4,a.S7+b.LDS),fa.tag);}

int base[N+5];

# define Ls(K) (K<<1)
# define Rs(K) (K<<1|1)

void Build(const int L,const int R,const int K)
{
	if(L == R) Seg[K] = node(base[L] == 4,base[L] == 7,1,1,0);
	else 
	{
		int mid = (L+R)>>1;
		Build(L,mid,Ls(K));
		Build(mid+1,R,Rs(K));
		Merge(Seg[K],Seg[Ls(K)],Seg[Rs(K)]);
	}
}

inline void Sp(node& a){Swap(a.LDS,a.LIS);Swap(a.S4,a.S7);a.tag ^= 1;}

void Push_Down(node& f,node& ls,node& rs){Sp(ls);Sp(rs);f.tag = 0;}

void Modify(const int AL,const int AR,const int L,const int R,const int K)
{
	if(AL <= L && AR >= R) Sp(Seg[K]);
	else
	{
		if(Seg[K].tag) Push_Down(Seg[K],Seg[Ls(K)],Seg[Rs(K)]);
		int mid = (L+R)>>1;
		if(AL <= mid) Modify(AL,AR,L,mid,Ls(K));
		if(AR > mid) Modify(AL,AR,mid+1,R,Rs(K));
		Merge(Seg[K],Seg[Ls(K)],Seg[Rs(K)]);
	}
}

int Query(){return Seg[1].LIS;} 

char s[7];
int n,m,l,r;

int main()
{
	scanf("%d%d",&n,&m);

	for(reg int i = 1; i <= n ; ++i) scanf("%1d",&base[i]);

	Build(1,n,1);

	while(m--)
	{
		scanf("%s",s);
		if(*s == 'c') printf("%d\n",Query());
		else 
		{
			scanf("%d%d",&l,&r);
			Modify(l,r,1,n,1);
		}
	}
	
	return 0;
}
