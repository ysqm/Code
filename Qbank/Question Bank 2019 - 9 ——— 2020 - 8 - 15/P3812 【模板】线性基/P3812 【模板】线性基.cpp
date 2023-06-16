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
# include <cstring>
# include <queue>
# define reg register
# define LL long long
# define N 100

inline LL Read()
{
	LL x = 0,f = 1;char ch = getchar();
	
	while(ch <= '0' || ch > '9') {if(ch == '-') f = -1;ch = getchar();}
	
	while(ch >= '0' && ch <= '9'){x = x * 10 + (ch ^ 48);ch = getchar();}
	
	return x * f;
}

LL n,p[N + 42],ans;

inline void Insert(LL x)
{
	for(reg int i = 62 ; i >= 0 ; --i)
		if(x >> (LL)i)
		{
			if(p[i] == 0)
			{
				p[i] = x;
				break;
			}
			
			x ^= p[i];
		}
}

int main()
{
	scanf("%lld",&n);
	
	for(reg int i = 1; i <= n ; ++i) Insert(Read());
	
	for(reg int i = 62 ; i >= 0 ; --i) if(ans < (ans ^ p[i])) ans ^= p[i];
	
	printf("%lld",ans);
	
	return 0;
}
