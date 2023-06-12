# include <queue>
# include <cmath>
# include <cstring>
# include <cstdio>
# define Calc(L,R) Get_Wi(L,R,(L+R)/2)
const int N = 5e5;

inline int Read()
{
    register int x = 0;char ch = getchar();
    
    while(ch < '0' || ch > '9')ch = getchar();
    
    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = getchar();}
    
    return x;
}

const int Max_V = 3000;
const int Max_P = 300;

int Min(const int x,const int y){return x < y ? x : y;}
int Max(const int x,const int y){return x < y ? y : x;}

int V,P,dp[Max_V+5];
int lst[Max_V+5];
int Sum[Max_V+5],a[N+5];

int Get_Wi(const int L,const int R,const int mid)
{return Sum[R]-Sum[mid]-(R-mid)*a[mid]+(mid-L)*a[mid]-Sum[mid-1]+Sum[L-1];}//鍒板彸杈瑰皬闀囩殑璺濈鍜屽埌宸﹁竟灏忛晣鐨勮窛绂汇€?

int q[Max_V+5],h,t,LR[Max_V+5];

void DP(const int mid)
{
    q[h = t = 0] = 0;
    for(int i = 1; i <= V ; ++i)
    {
        while(h < t && LR[q[h]] <= i) ++h;
        dp[i] = dp[q[h]-1]+Calc(q[h],i)+mid;
        lst[i] = lst[q[h]-1]+1;
        while(h < t && dp[q[t]-1]+Calc(q[t],LR[q[t]]) < dp[i-1]+Calc(i,LR[q[t]])) --t;

    }
    return;
}

int main()
{
    V = Read();P = Read();
    for(int i = 1; i <= V ; ++i) Sum[i] = Sum[i-1] + (a[i] = Read());
    int l = 0,r = 1e4,mid,ans;
    while(l <= r)
    {
        mid = (l+r)/2;
        DP(mid);
        //if(lst[V] == P) ans = l = r = mid;
        if(lst[V] <= P) r = (ans = mid)-1;
        else l = mid+1;
    }
    DP(ans);
    printf("%d\n",dp[V]-P*ans);
    return 0;
}
