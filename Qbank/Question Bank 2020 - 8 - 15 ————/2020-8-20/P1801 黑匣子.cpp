# include <ctime>
# include <queue>
# include <vector>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define reg //register
# define N 200000
# define Gc getchar()//(SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
char BB[1<<15],*SS=BB,*TT=BB;
inline int Read()
{
    register int x = 0,f = 1;char ch = Gc;

    while(ch < '0' || ch > '9'){if(ch == '-') f = -1;ch = Gc;}

    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = Gc;}

    return f < 0 ? ~x+1 : x;
}

int n,m,a[N+5],u[N+5];

std::priority_queue<int> q1;
std::priority_queue<int,std::vector<int>,std::greater<int> > q2;

int main()
{
    n = Read();m = Read();

    for(reg int i = 1; i <= n ; ++i) a[i] = Read();

    for(reg int i = 1; i <= m ; ++i) u[i] = Read();

    reg int p = 1,r;

    for(reg int i = 1; i <= m ; ++i)
    {
        r = u[i];
        
        for(; p <= r ; ++p) q1.push(a[p]);
        
        while(q1.size() >= i) {q2.push(q1.top());q1.pop();}
        
        printf("%d\n",q2.top());
        
        q1.push(q2.top());q2.pop();
    }

	/*while(q1.size()) {printf("%d ",q1.top());q1.pop();}
	puts("");
	while(q2.size()) {printf("%d ",q2.top());q2.pop();}*/

    return 0;
}
