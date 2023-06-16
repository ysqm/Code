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
		inline void Swap(const T& a,const T& b){T c = a;a = b;b = c;}
	} 
}
	
# define N 7100
# define reg register

struct ysys_Deque 
{
	private:
			int d_e_q_u_e[(N<<1) + 5],Rear_,Front_;
			
	public :
			ysys_Deque(){Rear_=N;Front_=N+1;}
			~ysys_Deque(){}
			
			inline bool Empty(){return Front_ > Rear_;}
			inline int Size(){return Front_ <= Rear_ ? Rear_-Front_+1 : 0;}
			inline void Reset(){Rear_=N;Front_=N+1;} 
			inline int Front(){return d_e_q_u_e[Front_];}
			inline int Rear(){return d_e_q_u_e[Rear_];}
			inline int Get_Back(){return d_e_q_u_e[Rear_--];}
			inline int Get_Front(){return d_e_q_u_e[Front_++];}
			inline void Pop_Back(){--Rear_;}
			inline void Pop_Front(){++Front_;}
			inline void Push_Front(const int Val){d_e_q_u_e[--Front_] = Val;}
			inline void Push_Back(const int Val){d_e_q_u_e[++Rear_] = Val;}
			
} q;

using namespace ysys::MMS;
long long f[N+5][N+5],a[N + 5];
int n,T;
using namespace ysys::unsigned_IO_f;

int main()
{
	T = Read();
	
	while(T--)
	{
		n = Read();
		
		for(reg int i = 1; i <= n ; ++i) a[i] = ReadL();
		
		for(reg int r = 2;  r <= n ; ++r)
		{
			q.Reset();q.Push_Back(r-1);
			
			f[r][r-1] = a[r-1]; 
			 
			for(reg int l = r-2,k = r; l ; --l)
			{
				while(f[k-1][l] > f[r][k] && l < k) --k;//寻找中转点。
				
				f[r][l] = f[k][l] + a[k];//取dp[l][r]的转移 
				
				while(q.Size() && k <= q.Front()) q.Pop_Front();
				
				if(q.Size()) f[r][l] = Min(f[r][l],f[r][q.Front()+1] + a[q.Front()]);
				
				while(q.Size() && f[r][q.Rear()+1] + a[q.Rear()] >= f[r][l+1] + a[l]) q.Pop_Back();
				
				q.Push_Back(l);
			}
		}
		
		printf("%lld\n",f[n][1]);
	}
	
	return 0;
}
