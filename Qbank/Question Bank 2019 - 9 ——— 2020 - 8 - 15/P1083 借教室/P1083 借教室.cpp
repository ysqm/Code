# include <cstdio>
# include <algorithm>
# include <cstring>
# define reg register

inline void in(int& x)
{
	x = 0; char ch = getchar();
	
	while(ch < '0' || ch > '9')ch = getchar();
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

}

int n,m;
int di[1000011],ne[1000011],re[1000011],r[1000011],l[1000011],d[1000011];

inline bool check(const int& x)
{
    memset(di,0,sizeof(di));
    for(reg int i = 1 ;i <= x; ++i){
        di[l[i]] += d[i];
        di[r[i] + 1] -= d[i]; 
    }
    for(reg int i = 1 ; i <= n ; ++i){
        ne[i] = ne[i-  1] + di[i];
        if(ne[i] > re[i]) return 0;
    }
    return 1;
} 

int main()
{
	in(n);in(m);
	
	for(reg int i = 1; i <= n ; ++i) in(re[i]);
	
    for(reg int i = 1; i <= m ; ++i){in(d[i]);in(l[i]);in(r[i]);}
    
    reg int L = 1,R = m,mid;
    
    if(check(m)) {puts("0");return 0;}
    
    while(L < R)
    {
        mid = (L + R) >> 1;
        
        if(check(mid))L = mid + 1;
        else R = mid;
    }
	
	printf("-1\n%d",L);
	
	return 0;
}
