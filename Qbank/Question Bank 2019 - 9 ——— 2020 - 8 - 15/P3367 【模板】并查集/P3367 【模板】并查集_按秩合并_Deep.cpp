# include <cstdio>
# define Gc getchar()//*/(SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
char BB[1<<15],*SS=BB,*TT=BB;

inline int Read()
{
	register int x = 0;register char ch = Gc;
	
	while(ch < '0' || ch > '9') ch = Gc;
	
	while(ch <= '9' && ch >= '0'){x = x*10 + (ch^48);ch = Gc;}
	
	return x;
}

/*
	Name :并查集模板 
	Code by:云岁月书
	Update_Date: 2020/8/5
	Update_Date: 2020/8/9 嵌入名字空间,并更改结构为 class ,更正 Union 函数返回值(int->void)
	Update_Date: 2020/8/9 更改所有数组为指针，新增深度版按秩合并的并查集，更改原并查集名称为 Union_Find_Size 
*/
namespace ysys
{
	# define reg register
	
	class Union_Find_Size//普通并查集 
	{
		private:
			int *F,*Size;
		
		public:
			Union_Find_Size(){}
		
			Union_Find_Size(const int n){F = new int [n + 5];Size = new int [n + 5];for(reg int i = 1; i <= n ; ++i) *(F+i) = i,*(Size+i) = 1;}
	
			inline int Father(const int x){return *(F+x);}
	
			inline int Find(int x)
			{
				int cur = x;
			
				while(*(F+cur) ^ cur) cur = *(F+cur);
		
				*(F+x) = cur;
		
				while(x ^ *(F+x)) *(F + (x = *(F+x))) = cur;
		
				return cur;
			}
	
			inline void Unity(int x,int y)
			{
				x = Find(x);y = Find(y);
				
				if(*(Size + x) < *(Size + y)) *(Size + y) += *(Size + x),*(F + x) = y;
				else *(Size + x) += *(Size + y),*(F + y) = x; 
			}
	};
	
	class Union_Find_Deep
	{
		private:
			int *F,*Deep;
		
		public:
			Union_Find_Deep(){}
		
			Union_Find_Deep(const int n){F = new int [n + 5];Deep = new int [n + 5];for(reg int i = 1; i <= n ; ++i) *(F+i) = i,*(Deep+i) = 1;}
	
			inline int Father(const int x){return *(F+x);}
	
			inline int Find(int x)
			{
				int cur = x;
			
				while(*(F+cur) ^ cur) cur = *(F+cur);
		
				*(F+x) = cur;
		
				while(x ^ *(F+x)) *(F + (x = *(F+x))) = cur;
		
				return cur;
			}
	
			inline void Unity(int x,int y)
			{
				x = Find(x);y = Find(y);
				
				if(*(Deep + x) <= *(Deep + y))
				{
					*(F + x)= y;
						
					if(*(Deep + x) == *(Deep + y)) ++*(Deep + y);
				}
				else *(F + y) = x;
			}
	};
	
	# undef reg
}

using ysys::Union_Find_Deep;

Union_Find_Deep UF;

int main()
{
	register int n,x,y,z,m;
	
	n = Read();m = Read();UF = Union_Find_Deep(n);
	
	while(m--)
	{
		z = Read();x = Read();y = Read();
		
		if(z == 2) printf(UF.Find(x) == UF.Find(y) ? "Y\n" : "N\n");
		else if(z == 1 && UF.Find(x) != UF.Find(y)) UF.Unity(UF.Father(x),UF.Father(y));
	} 
	
	return 0;
}

