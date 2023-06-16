# include <ctime>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define reg register
# define chkmax(k) l < (k) ? l = (k) : l ;

int n,a[505],k;

inline bool check(const int x)
{
    reg int i = 1,cnt = 1,tot = 0;

    for(; i <= n ; ++i)
    {
        if(tot + a[i] <= x) tot += a[i];
        else 
        {
            ++cnt;
            if(cnt > k) return false;
            tot = a[i];
        }
    }
    return true;
}

int stk[505],top;

inline void printd(const int x)
{
    int sum = 0;stk[0] = n+1;a[0] = 0x3f3f3f3f;

    for(reg int i = n; i >= 0 ; --i)
    {
        if(sum + a[i] > x)
        {
            stk[++top] = i+1;
            sum = a[i];
        }
        else sum += a[i];
    }

    for(reg int i  = k-1; i >= 0 ; --i) printf("%d %d\n",stk[i+1],stk[i]-1);
        //for(reg int j = stk[k-1]+1; j <= n ; ++i)
}

int main()
{
    scanf("%d%d",&n,&k);

    for(reg int i = 1; i <= n ; ++i) scanf("%d",a+i);
    
    register int l=-1,r=0,mid; 

	for(reg int i = 1; i <= n ; ++i) chkmax(a[i]);
	
	for(reg int i = 1; i <= n ; ++i) r += a[i];
	
	while(l < r)
	{
		mid = (l+r)>>1;
		
		if(check(mid)) r = mid;
		else l = mid+1;
	}

    printd(l);

    return 0;
}
