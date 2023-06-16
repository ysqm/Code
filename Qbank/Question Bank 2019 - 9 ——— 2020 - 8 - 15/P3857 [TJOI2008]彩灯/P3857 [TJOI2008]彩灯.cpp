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
# define reg register
# define LL long long

char s[420];
int n,m,ans = 1;
LL cur,p[64];

int main()
{
	scanf("%d%d",&n,&m);
	
	for(reg int i = 1; i <= m ; ++i)
	{
		scanf("%s",s);
		
		cur = 0;
		
		for(reg int j = 0; j < n ; ++j)
			if(s[j] == 'O') 
				cur |= (1LL << j);
			
		for(reg int j = n; ~j ; --j)
			if(cur >> j)
			{
				if(p[j] == 0){p[j] ^= cur;break;}
				else cur ^= p[j];
			}
	}
	
	for(reg int i = 0; i <= n; ++i) if(p[i]) ans = (ans << 1) % 2008;
	
	printf("%lld",ans);
	
	return 0;
}
