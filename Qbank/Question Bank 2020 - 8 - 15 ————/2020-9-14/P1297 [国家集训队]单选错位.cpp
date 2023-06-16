# include <cstdio>
# define N 10000000
const int mod = 1e8+1;

inline int Max(const int a,const int b){return a > b ? a : b;}

double ans;
int a1,a2,n,A,B,C,i,f2;

int main()
{
    scanf("%d%d%d%d%d",&n,&A,&B,&C,&f2);
    a2 = f2;
    while(--n)
    {
    	a1 = ((long long)a2*A+B)%mod;
    	ans += 1.0/Max(a1%C+1,a2%C+1);
    	a2 = a1;
	}
    printf("%.3lf",ans+1.0/Max(a2%C+1,f2%C+1));
    return 0;
}