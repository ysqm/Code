# include <ctime>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define N 3000000
# define LL long long

inline LL Read()
{
    register LL x = 0;char ch = getchar();

    while(ch < '0' || ch > '9')ch = getchar();

    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = getchar();}

    return x;
}

inline int Max(const int a,const int b){return a < b ? b : a;}
inline int Min(const int a,const int b){return a > b ? b : a;}

struct ysys_Deque 
{
	//private:
			int d_e_q_u_e[(N<<1) + 5],Rear_,Front_;
			
	//public :
			ysys_Deque(){Rear_=0;Front_=1;}
			~ysys_Deque(){}
			
			inline bool Empty(){return Front_ > Rear_;}
			inline int Size(){return Front_ <= Rear_ ? Rear_-Front_+1 : 0;}
			inline void Reset(){Rear_=0;Front_=1;} 
			inline int Front(){return d_e_q_u_e[Front_];}
			inline int Rear(){return d_e_q_u_e[Rear_];}
			inline int Get_Back(){return d_e_q_u_e[Rear_--];}
			inline int Get_Front(){return d_e_q_u_e[Front_++];}
			inline void Pop_Back(){--Rear_;}
			inline bool Pop_Front(){++Front_;return 1;}
			inline void Push_Front(const int Val){d_e_q_u_e[--Front_] = Val;}
			inline void Push_Back(const int Val){d_e_q_u_e[++Rear_] = Val;}
			
} q0,q1;

LL a[N + 5];

int main()
{
    LL ans = 0;

    register int k = Read(),n = Read(),Pre = 0;

    for(register int i = 1; i <= n ; ++i)
    {
        a[i] = Read();
        
        while(q0.Size() && a[i] > a[q0.Rear()]) q0.Pop_Back();
        while(q1.Size() && a[i] < a[q1.Rear()]) q1.Pop_Back();

        q0.Push_Back(i);q1.Push_Back(i);

        while(q0.Size() && q1.Size() && a[q0.Front()] - a[q1.Front()] > k) 
		(q0.Front() > q1.Front() && (Pre = q1.Front()) && q1.Pop_Front()) || ((Pre = q0.Front()) && q0.Pop_Front());

        ans = Max(ans,i - Pre);
    }

    printf("%lld\n",ans);

    return 0;
}
