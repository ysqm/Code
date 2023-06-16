# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define LL long long
# define N 150000
# define M 300
class ysys_Deque 
{
    static const int Max_Deque_Size = 1e6;
    private:
            int d_e_q_u_e[(Max_Deque_Size<<1) + 5],Rear_,Front_;
            
    public :
            ysys_Deque(){Rear_=0;Front_=1;}
            ~ysys_Deque(){}
            
            inline bool Empty(){return Front_ > Rear_;}
            inline int Size(){return Front_ <= Rear_ ? Rear_-Front_+1 : 0;}
            inline void Reset(){Rear_=0;Front_=1;} 
            inline int Front(){return d_e_q_u_e[Front_];}
            inline int Rear(){return d_e_q_u_e[Rear_];}
            inline int Get_Back(){return d_e_q_u_e[Rear_--];}
            inline int Get_Front()
			{
				return d_e_q_u_e[Front_++];
			}
            inline void Pop_Back(){--Rear_;}
            inline void Pop_Front(){++Front_;}
            inline void Push_Front(const int Val){d_e_q_u_e[--Front_] = Val;}
            inline void Push_Back(const int Val){d_e_q_u_e[++Rear_] = Val;}
} q;

int n,m,d,a[N+5],b[N+5],t[N+5];
long long f[N+5],g[N+5];
int main()
{
	//freopen("1.txt","w",stdout); 
    scanf("%d%d%d",&n,&m,&d);
    for(int i = 1; i <= m ; ++i) scanf("%d%d%d",&a[i],&b[i],&t[i]);
    //for(int i = 1; i <= n ; ++i) printf("%-3d ",i);puts("");
    for(int k = 1; k <= m ; ++k)
    {
    	long long nd = (t[k]-t[k-1])*(long long)d;
        q.Reset();
        for(int i = 1; i <= nd && i <= n ; ++i)
        {
            while(q.Size() && g[q.Rear()] <= g[i]) q.Pop_Back();
            q.Push_Back(i);
        }
        for(int i = 1; i <= n ; ++i)
        {
            while(q.Size() && nd+q.Front() < i) q.Pop_Front();
            while(q.Size() && i+nd <= n && g[q.Rear()] <= g[i+nd]) q.Pop_Back();
            if(i+nd <= n) q.Push_Back(i+nd);
            f[i] = g[q.Front()]+b[k]-abs(a[k]-i);
        }
        for(int i = 1; i <= n ; ++i) g[i] = f[i];
        //long long fd = -2e18;
        //printf("%d\n",nd/d);
        //for(int i = 1; i <= n ; ++i) printf("%-3d ",f[i]);puts("");
		//printf("%lld\n",fd); 
    }
    long long ans = -2e18;
    for(int i = 1; i <= n ; ++i) ans = std::max(ans,f[i]);
    printf("%lld\n",ans);
    return 0;
}
