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

inline int Read()
{
	reg int x = 0;reg char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	return x;
}

bool Used[42],f[2042];
int n,m,a[42],tot,ans,ret;

void dfs(const int cur,const int Abandoned)
{
	if(cur > n) return;
	
	if(Abandoned == m && cur == n)
	{
		ret = tot = 0;
		
		for(reg int i = 1; i <= n ; ++i)
			if(!Used[i])
			{
				for(reg int j = tot; j >= 0 ; --j)if(f[j]) f[j + a[i]] = true;	
				
				tot += a[i];
			}
		
		for(reg int i = 1; i <= tot ; ++i)if(f[i]){++ret;f[i] = false;}
		
		if(ret > ans) ans = ret;
	}
	
	if(Abandoned < m)
	{
		Used[cur] = 1;
	
		dfs(cur + 1,Abandoned + 1);
	
		Used[cur] = 0;	
	}
	
	dfs(cur + 1,Abandoned);
}


signed main()
{
	n = Read();m = Read();
	
	for(reg int i = 1; i <= n ; ++i) a[i] = Read();
	
	f[0] = true;
	
	std::sort(a + 1,a + n + 1);//为什么这里要加sort 
	
	dfs(1,0);
	
	printf("%d\n",ans);
	
	return 0;
}
