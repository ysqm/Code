# include <cstdio>
# include <cstring>
# include <algorithm>
# define reg register
# define Gc /*getchar()//*/(SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
char BB[1<<15],*SS=BB,*TT=BB;

inline int Read()
{
	register int x = 0;register char ch = Gc;
	
	while(ch < '0' || ch > '9') ch = Gc;
	
	while(ch <= '9' && ch >= '0'){x = x*10 + (ch^48);ch = Gc;}
	
	return x;
}

inline int Min(const int a,const int b){return a < b ? a : b;}
inline int Max(const int a,const int b){return a > b ? a : b;}

struct qj
{
	int Left,Right;
	
	qj(const int Right_=0,const int Left_=0):Left(Left_),Right(Right_){}
	
} L[10005];

inline bool comp(const qj& a,const qj& b){return a.Left > b.Left;}

int f[10005],n,k,cnt;
int d[10005];

int main()
{
	n = Read();k = Read();
	
	for(reg int i = 1; i <= k ; ++i) L[i] = qj(Read(),Read());
	
	for(reg int i = 1; i <= k ; ++i) ++d[L[i].Left];
	
	std::sort(L+1,L+n+1,comp);
	
	for(reg int i = n; i >= 1 ; --i)
	{
		if(d[i] == 0) f[i] = f[i+1]+1;
		else
			for(reg int j = 1; j <= d[i] ; ++j) 
				f[i] = Max(f[i],f[i + L[++cnt].Right/* - 1*/]);
	}
	
	//for(reg int i = 1; i <= n ; ++i) printf("%-3d",f[i]);
	
	printf("%d",f[1]);
	
	return 0;
}


