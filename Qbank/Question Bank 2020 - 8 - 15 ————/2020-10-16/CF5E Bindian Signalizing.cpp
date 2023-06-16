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
# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define LL long long
# define Gc (SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
char BB[1<<15],*SS=BB,*TT=BB;
inline int Read()
{
    register int x = 0;char ch = Gc;
 
    while(ch < '0' || ch > '9')ch = Gc;
 
    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = Gc;}
 
    return x;
}
 
const LL N = 1e6;
LL ans;
int LLst[N+5],RLst[N+5],High[N+5],n,stk[N+5],temp[N+5],Same[N+5],tp[N+5],top,pmax = 0;
 
int main()
{
    //freopen("ysqm.in","r",stdin);
    n = Read();
    for(int i = 0; i < n ; ++i) temp[i] = Read();
    for(int i = 0; i < n ; ++i) (temp[pmax] < temp[i]) && (pmax = i);
    for(int i = 0; i <= n ; ++i) High[i] = temp[(i+pmax)%n];
    for(int i = 0; i < n ; ++i)
    {
        while(top && High[stk[top]] < High[i]) RLst[stk[top--]] = i;
        stk[++top] = i;
    }
    stk[0] = n;top = 0; 
    for(int i = 0; i < n ; ++i)
    {
        while(top && High[stk[top]] < High[i]) --top;
        while(top && High[stk[top]] <= High[i]) Same[i] += tp[top--];
        LLst[i] = stk[top];
        stk[++top] = i;
        tp[top] = 1+Same[i];
    }
    --Same[n]; 
    for(int i = 0; i < n ; ++i) ans += Same[i];
    for(int i = 0; i < n ; ++i) if(High[i] < High[0]) ans += 2-((LLst[i] == n && RLst[i] == 0) || RLst[i] == LLst[i]);
    printf("%lld",ans);
    return 0;
}
