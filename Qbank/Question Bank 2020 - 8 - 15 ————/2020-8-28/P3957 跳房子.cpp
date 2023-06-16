# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define reg register
# define N 500000
# define Gc (SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
# define int long long
char BB[1<<15],*SS=BB,*TT=BB;
inline int Read()
{
    register int x = 0,f = 1;char ch = Gc;

    while(ch < '0' || ch > '9'){if(ch == '-') f = -1;ch = Gc;}

    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = Gc;}

    return f < 0 ? ~x+1 : x;
}

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

inline int Max(const int a,const int b){return a > b ? a : b;}

int f[N+5],n,x[N+5],s[N+5],k,d;

inline bool check(const int g)
{
    q.Reset();
    memset(f,-0x3f,sizeof(f));f[0] = 0;
    reg int lpos = Max(1,d-g),rpos = d+g;
    for(reg int i = 0,cur=0; i <= n ; ++i)
    {
        while(x[i]-lpos>=x[cur] && cur<i)
        {
            while(q.Size()&&f[q.Front()]<=f[cur]) q.Pop_Front();
            q.Push_Front(cur++);
        }
        while(q.Size()&&x[q.Rear()]<x[i]-rpos) q.Pop_Back();
        if(q.Size())f[i] = s[i]+f[q.Rear()];
    }

    for(reg int i = 1; i <= n ; ++i) if(f[i]>=k) return true;
    return false;
}

signed main()
{
    n = Read();d = Read();k = Read();

    for(reg int i = 1; i <= n ; ++i) {*(x+i) = Read();*(s+i) = Read();}

    reg int l = 0,r = 5e5,mid;

    while(l<r)
    {
        mid = (l+r)>>1;
        if(check(mid)) r = mid;
        else l = mid+1;
    }

    printf("%lld",l==5e5?-1:l);

    return 0;
}
