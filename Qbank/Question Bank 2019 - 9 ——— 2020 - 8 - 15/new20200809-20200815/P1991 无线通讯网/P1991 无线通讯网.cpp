# include <cmath>
# include <cstdio>
# include <algorithm>
# define reg register
# define N 500
# define mod 998244353 
# define INF 0x7f7f7f7f7f7f7f7f
# define Gc getchar()//*/(SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
char BB[1<<15],*SS=BB,*TT=BB;

inline int Read()
{
	register int x = 0;register char ch = Gc;
	
	while(ch < '0' || ch > '9') ch = Gc;
	
	while(ch <= '9' && ch >= '0'){x = x*10 + (ch^48);ch = Gc;}
	
	return x;
}

namespace ysys
{
	/*
		Name :并查集模板 
		Code by:云岁月书
		Update_Date: 2020/8/5 创建该项目 
		Update_Date: 2020/8/9 嵌入名字空间,并更改结构为 class ,更正 Union 函数返回值(int->void)
		Update_Date: 2020/8/9 更改所有数组为指针，新增深度版按秩合并的并查集，更改原并查集名称为 Union_Find_Size，
							  Union 函数改名 Unity 
	*/	
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
}

using ysys::Union_Find_Size;

Union_Find_Size UF;

struct edge
{
	int u,v;
	double wi;
	
	edge(const int u_=0,const int v_=0,const double wi_=0):u(u_),v(v_),wi(wi_){} 
} e[((N*N)>>1)+5];

int P,S,x[N + 42],y[N + 42],cnt,tot;

inline double dis(const int dx,const int dy){return sqrt(dx*dx+dy*dy);}

inline bool comp(const edge& a,const edge& b){return a.wi < b.wi;}

int main()
{
	#ifdef ONLINE_JUDGE
	#else
    freopen("2.txt","r",stdin);
	#endif
	
	S = Read();P = Read();
	
	for(reg int i = 1; i <= P ; ++i){x[i] = Read();y[i] = Read();}
	
	for(reg int i = 1; i <= P ; ++i)
		for(reg int j = 1 ; j < i ; ++j)
			e[++cnt] = edge(j,i,dis(x[i]-x[j],y[i]-y[j]));
	
	UF = Union_Find_Size(P);
	
	std::sort(e+1,e+cnt+1,comp);tot = P;
	
	for(reg int i = 1; i <= cnt ; ++i)
		if(UF.Find(e[i].u) != UF.Find(e[i].v))
		{
			UF.Unity(e[i].u,e[i].v);
		
			--tot;
			
			if(tot == S)
			{
				printf("%.2lf",(e[i].wi));
				
				return 0;
			}
		}
}
