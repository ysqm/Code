# include <queue>
# include <cmath>
# include <cstring>
# include <cstdio>
const int N = 5e5;

inline int Read()
{
    register int x = 0;char ch = getchar();
    
    while(ch < '0' || ch > '9')ch = getchar();
    
    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = getchar();}
    
    return x;
}

double Max(const double x,const double y){return x < y ? y : x;}

double f[N+5],sq[N+5];
int a[N+5],n;
int q[N+5],h,t,k[N+5];

int Floor(const double x){return (int)x < x ? (int)x+1 : x;}
void Swap(int& x,int& y){x^=y^=x^=y;}
void Swap(double& x,double& y)
{
	static double tmp;
	tmp = y;y = x;x = tmp;
}

int Check(const int x,const int y)
{
    int l = y,r = (k[x] ? k[x] : n),mid,res = r+1;
    while(l < r)
    {
        mid = (l+r)/2;
        if(a[x]+sq[mid-x] <= a[y]+sq[mid-y]) {r = mid-1;res = mid;}
        else l = mid+1;
    }
    return res;
}

void Solve()
{
    for(int i = 1; i <= n ; ++i)
    {
    	while(h < t && a[q[t]]+sq[k[t-1]-q[t]] < a[i]+sq[k[t-1]-i]) t--;
        k[t] = Check(q[t],i);q[++t] = i;
        while(h < t && k[h] <= i) ++h;
        f[i] = Max(f[i],a[q[h]]+sq[i-q[h]]);
	}
}

int main()
{
    n = Read();
    for(int i = 1; i <= n ; ++i) a[i] = Read();
    for(int i = 1; i <= n ; ++i) sq[i] = sqrt(i);
    Solve();
    memset(k,0,sizeof(0));t = h = 0;
    for(int i = n/2; i >= 1 ; --i) Swap(a[i],a[n-i+1]);
    for(int i = n/2; i >= 1 ; --i) 
		Swap(f[i],f[n-i+1]); 
    Solve();
    for(int i = n; i >= 1 ; --i) printf("%d\n",Floor(f[i])-a[i]);
    return 0;
}
