# include <cstdio>
# include <queue>
# define reg register
# define N 500000
 
# define Gc /*getchar()//*/(SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
char BB[1<<15],*SS=BB,*TT=BB;
inline int Read()
{
    register int x = 0;char ch = Gc;

    while(ch < '0' || ch > '9')ch = Gc;

    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = Gc;}

    return x;
}

struct node
{
    int idx,Val;

    node(const int idx_=0,const int val_=0):idx(idx_),Val(val_){}

    inline bool operator < (const node& b)const {return idx < b.idx;}
} ;

std::priority_queue<node> q;

bool vis[N+5];
int n,k,p,lastpart[N+5],a[N+5],head[N+5],ans,T;

int main()
{
	T = Read();
	while(T--)
	{
		n = Read();k = Read(); p = Read();

        for(register int i = 1; i <= p ; ++i) a[i] = Read();

        for(register int i = 1; i <= p ; ++i) head[i] = 0x3f3f3f3f;

        for(register int i = p; i >= 1 ; --i)
        {
            lastpart[i] = head[a[i]];
            head[a[i]] = i;
        }

        for(register int i = 1; i <= p ; ++i)
        {
            if(!vis[a[i]])
            {
                if(q.size() == k)
                {
                    node cur = q.top();q.pop();
                    vis[cur.Val] = 0;
                }
                vis[a[i]] = 1;
                q.push(node(lastpart[i],a[i]));++ans;
            }
            else
            {
                ++k;
                q.push(node(lastpart[i],a[i]));
            } 
        }

    	printf("%d\n",ans);

        while(q.size()){vis[q.top().Val] = 0;q.pop();}ans = 0;
	}
    

    return 0;
}
