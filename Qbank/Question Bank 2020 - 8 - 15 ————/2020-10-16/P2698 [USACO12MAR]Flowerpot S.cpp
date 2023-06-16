# include <set>
# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define N 100000
# define Gc (SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
char BB[1<<15],*SS=BB,*TT=BB;
inline int Read()
{
    register int x = 0;char ch = Gc;

    while(ch < '0' || ch > '9')ch = Gc;

    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = Gc;}

    return x;
}

class ysys_Deque 
{
    static const int Max_Deque_Size = 1e6;
    private:
            int d_e_q_u_e[Max_Deque_Size + 5],Rear_,Front_;
            
    public :
            ysys_Deque(){Rear_=-1;Front_=0;}
            ~ysys_Deque(){}
            
            inline bool Empty(){return Front_ > Rear_;}
            inline int Size(){return Rear_-Front_+1;}
            inline void Reset(){Rear_=-1;Front_=0;} 
            inline int Front(){return d_e_q_u_e[Front_];}
            inline int Rear(){return d_e_q_u_e[Rear_];}
            inline int Get_Back(){return d_e_q_u_e[Rear_--];}
            inline int Get_Front(){return d_e_q_u_e[Front_++];}
            inline void Pop_Back(){--Rear_;}
            inline void Pop_Front(){++Front_;}
            inline void Push_Front(const int Val){d_e_q_u_e[--Front_] = Val;}
            inline void Push_Back(const int Val){d_e_q_u_e[++Rear_] = Val;}
            
} q1,q2;

struct Point
{
    int x,h;
    bool operator < (const Point& b)const {return (x != b.x) ? x < b.x : h < b.h;}
} a[N+5];

int n,D;

bool check(const int d)
{
    q1.Reset();q2.Reset();
    for(int i = 1; i <= n ; ++i)
    {
        while(q1.Size() && a[i].x-a[q1.Front()].x > d) q1.Pop_Front();
        while(q2.Size() && a[i].x-a[q2.Front()].x > d) q2.Pop_Front();
        while(q1.Size() && a[i].h <= a[q1.Rear()].h) q1.Pop_Back();
        while(q2.Size() && a[i].h >= a[q2.Rear()].h) q2.Pop_Back();
        q1.Push_Back(i);q2.Push_Back(i);
        if(q2.Size() && a[q2.Front()].h-a[q1.Front()].h >= D) return true;
    }
    return false;
}

int main()
{
    freopen("ysqm.in","r",stdin);
	n = Read();D = Read();
    for(int i = 1; i <= n ; ++i){a[i].x = Read();a[i].h = Read();}
    std::sort(a+1,a+n+1);
    int l = 0,r = 2e6,mid;
    while(l<r)
    {
        mid = (l+r)>>1;
        if(check(mid)) r = mid;
        else l = mid+1;
    }
    printf("%d",l == 2e6 ? -1 : l);
    return 0;
}