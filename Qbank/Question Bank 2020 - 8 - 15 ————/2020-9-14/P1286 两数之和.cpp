# include <set>
# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define sset std::multiset<int>
# define pset sset::iterator

const int N = 1000000;

bool flag;
int n,a[N+5],b[N+5],nn;

sset rbt;
pset it;

bool check(const int x)
{
	b[1] = x;
	for(int i = 2; i <= n ; ++i)
	{
		b[i] = *rbt.begin()-b[1];
		for(int j = 1; j < i; ++j)
		{
			it = rbt.find(b[j]+b[i]);
			if(it == rbt.end()) return false;
			rbt.erase(it);
		}
	}
	return flag = true;
}

void Solve()
{
    while(~scanf("%d",&n))
    {
        nn = ((n-1)*n)/2;flag = false;
    	for(int i = 1; i <= nn ; ++i) scanf("%d",a+i);
    	std::sort(a+1,a+nn+1);
    	for(int i = 0; i*2 <= a[1] ; ++i)
    	{
    		rbt.clear();
			for(int j = 1; j <= nn ; ++j) rbt.insert(a[j]);
			if(check(i)) break;
		}
        if(!flag) puts("Impossible");
		else 
		{
			for(int i = 1; i <= n; ++i) printf("%d ",b[i]);
        	puts("");
		}
        
    }
}

int main(){Solve();return 0;}
