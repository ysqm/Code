# include <cstdio>
# include <set>
# define N 1000000
using namespace std;

inline void in(int& x)
{
	x = 0;int f = 1;char c = getchar();
	
	while(c < '0' || c > '9'){if(c == '-') f = -1;c = getchar();}
	
	while(c >= '0' && c <= '9'){x = x * 10 + (c ^ 48);c = getchar();}
	
	x *= f;
}

struct node
{
	int W,C;
	
	bool operator < (const node & a) const {return C < a.C;}
};

set <node> T;
int pos,W,C;

int main()
{
	while(1){
		
		in(pos);
		
		switch(pos)
		{
			case 1 : 
					in(W);in(C);
					T.insert(node{W,C});
					break;
					
			case 2 :
					if(T.size()) T.erase(--T.end());
					break;
					
			case 3 :
					if(T.size()) T.erase(T.begin());
					break;
					
			default:
					long long W1 = 0,C1 = 0;
					
					for(register set<node> :: iterator it = T.begin() ; it != T.end() ; ++it){W1 += (*it).W; C1 += (*it).C;}
					
					printf("%lld %lld",W1,C1);
					
					return 0;
		}
		
	}
}
