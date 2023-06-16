# include <cstdio>
# include <algorithm>
# include <bitset>
# define reg register
# define N 100000
using namespace std;

inline void in(int& x)
{
	x = 0; char ch = getchar();int f = 1;
	
	while(ch < '0' || ch > '9'){if(ch == '-') f = -1;ch = getchar();}
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	x *= f;
}

/*struct pr_Queue
{
	int Queue[N + 42],tail,head;
} q;*/

int n,ans[N + 42],cow[N + 42];

int main()
{
	//q.head = 1;
	in(n);
	
	for(reg int i = 1; i <= n; ++i) in(cow[i]);
	
	/*for(reg int i = n; i ; --i){
		while(q.tail >= q.head && cow[i] >= q.Queue[q.tail]) --q.tail;
		
		ans[i] = q.Queue[q.tail];
		
		q.Queue[++q.tail] = cow[i];
	}*/
	
	for(reg int i = n - 1,j; i ; --i){
		j = i + 1;
		while(cow[i] >= cow[j] && cow[j] > 0) j = ans[j];
		ans[i] = j;
	}
	
	for(reg int i = 1; i <= n; ++i) printf("%d\n",ans[i]);
	return 0;
}
