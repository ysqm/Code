/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
=======`-.____`-.___\_____/___.-`____.-'=======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  	 Buddha said:
         	 	 The program have no BUG.
         	 	 The program can pass the text.   	 	 
*/
# include <cstdio>
# include <algorithm>
# define reg register
# define N 1000000

inline int Read()
{
	int x = 0;char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch <= '9' && ch >= '0'){x = x * 10 + (ch ^ 48);ch = getchar();}
	
	return x;
}

struct Question
{
	int Left_Endpoint,Right_Endpoint,Original_Position;
} ask[N + 42];

inline bool operator < (const Question& a,const Question& b){return a.Right_Endpoint < b.Right_Endpoint;}

inline int lowbit(const int& x){return x & (-x);}

int base[N + 42],n,m,Necklace[N + 42],ans[N + 42],Mapping[N + 42];

inline void Insert(int x,const int cur){while(x <= n){base[x] += cur;x += lowbit(x);}}

inline int Sum(int x){int ans = 0;while(x){ans += base[x];x -= lowbit(x);}return ans;}

int main()
{
	n = Read();
	
	for(reg int i = 1; i <= n ; ++i) Necklace[i] = Read();
	
	m = Read();
	
	for(reg int i = 1; i <= m ; ++i)
	{
		ask[i].Left_Endpoint = Read();
		
		ask[i].Right_Endpoint = Read();
		
		ask[i].Original_Position = i;
	}
	
	std::sort(ask + 1,ask + m + 1);
	
	for(reg int i = 1; i <= m ; ++i)
	{
		for(reg int j = ask[i-1].Right_Endpoint + 1 ; j <= ask[i].Right_Endpoint; ++j)
		{
			if(Mapping[Necklace[j]]) Insert(Mapping[Necklace[j]],-1);
			
			Insert(j,1);
			
			Mapping[Necklace[j]] = j;
		}
		
		ans[ask[i].Original_Position] = Sum(ask[i].Right_Endpoint) - Sum(ask[i].Left_Endpoint - 1);
	}
	
	for(reg int i = 1; i <= m ; ++i) printf("%d\n",ans[i]);
	
	return 0;
}

