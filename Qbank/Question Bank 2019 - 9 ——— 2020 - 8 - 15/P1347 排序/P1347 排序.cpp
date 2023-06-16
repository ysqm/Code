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
# define End(i) {printf("Inconsistency found after %d relations.\n",i);return 0 ;}

char s[42];
int G[42][42],n,m,d[42],sum;

inline void Floyed()
{
	for(reg int k = 1; k <= n ; ++k)
		for(reg int i = 1; i <= n ; ++i)
			for(reg int j = 1; j <= n ; ++j)
				if(G[i][k] == 1 && G[k][j] == 1){G[i][j] = 1;G[j][i] = -1;}
				else if(G[i][k] == -1 && G[k][j] == -1){G[i][j] = -1;G[j][i] = 1;}	
}

int main()
{
	scanf("%d%d",&n,&m);
	
	for(reg int i = 1; i <= m ; ++i)
	{
		scanf("%s",s + 1);
		
		int x = s[1] - '@',y = s[3] - '@';
		
		if(s[1] == s[3]) End(i)
		
		if(G[x][y] == 1) End(i)
		
		else {G[x][y] = -1;G[y][x] = 1;}
		
		Floyed();
		
		sum = 0;
		
		for(reg int i = 1; i <= n ; ++i)
		{
			reg int top = 0,id = 0;
			
			for(reg int j = 1; j <= n ; ++j) if(G[i][j]){++top;if(G[i][j] == -1) ++id;}
			
			if(top == n-1){d[id+1] = i + '@';++sum;}
			
		}
		
		if(sum == n)
		{
			printf("Sorted sequence determined after %d relations: ",i);
			
			for(reg int i = n; i ; --i) printf("%c",d[i]);
			
			puts(".");
			
			return 0;
		}
		
	}
	
	printf("Sorted sequence cannot be determined.\n");
    
	return 0;
}
