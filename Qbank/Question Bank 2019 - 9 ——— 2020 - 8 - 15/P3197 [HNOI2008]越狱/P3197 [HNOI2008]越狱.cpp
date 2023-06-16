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

inline LL Read()
{
	reg LL x = 0;reg char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	return x;
}

LL n,m;

inline LL Fast_Pow(LL x,LL p)
{
    LL res = 1;

    for(; p ; p >>= 1,x = (x * x) % 100003) 
        if(p & 1) res = (res * x) % 100003;

    return res;
}

signed main()
{
	m = Read();n = Read();
	
	printf("%lld",(Fast_Pow(m,n) % 100003 - (m % 100003) * Fast_Pow(m - 1, n - 1) % 100003 + 100003) % 100003);
	
	return 0;
}
