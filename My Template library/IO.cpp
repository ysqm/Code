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
	
