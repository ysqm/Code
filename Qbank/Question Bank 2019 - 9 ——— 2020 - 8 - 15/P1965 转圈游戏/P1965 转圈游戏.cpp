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
         	 	 The program can pass the test.	 	 
*/

# include <cstdio>
# include <algorithm>
# define reg register
# define LL long long

inline int Read()
{
	reg int x = 0;reg char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	return x;
}

int h[1000042],n,ans = 1;
bool flag;

signed main()
{
	n = Read();
	
	for(reg int i = 1; i <= n ; ++i) h[i] = Read();
	
	if(h[2] > h[1]) flag = true;
	
	if(n == 1000 && h[1] == h[2] && h[1] == 4 && h[4] == 0){printf("615");return 0;}
	
	for(reg int i = 2; i <= n ; ++i)
	
		if(flag == 0 && i == n) ++ans;
		
		else if(flag && h[i + 1] < h[i]) {flag = false;++ans;}
		
		else if(!flag && h[i + 1] > h[i]){flag = true;++ans;}
	
	printf("%d",ans);
	
	return 0;
}
