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
inline LL Read()
{
    register LL x = 0;char ch = Gc;
 
    while(ch < '0' || ch > '9')ch = Gc;
 
    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = Gc;}
 
    return x;
}

const LL p[200]={0,1,2,4,6,12,24,36,48,60,120,180,240,360,720,840,1260,1680,2520,5040,7560,10080,15120,20160,25200,27720,45360,50400,55440,83160,110880,166320,221760,277200,332640,498960,554400,665280,720720,1081080,1441440,2162160,2882880,3603600,4324320,6486480,7207200,8648640,10810800,14414400,17297280,21621600,32432400,36756720,43243200,61261200,73513440,110270160,122522400,147026880,183783600,245044800,294053760,367567200,551350800,698377680,735134400,1102701600,1396755360,2095133040,2205403200,2327925600,2793510720,3491888400,4655851200,5587021440,6983776800,10475665200,13967553600,20951330400,27935107200,41902660800,48886437600,64250746560,73329656400,80313433200,97772875200,128501493120,146659312800,160626866400,240940299600,293318625600,321253732800,481880599200,642507465600,963761198400,1124388064800,1606268664000,1686582097200,1927522396800,2248776129600,3212537328000,3373164194400,4497552259200,6746328388800,8995104518400,9316358251200,13492656777600,18632716502400,26985313555200,27949074753600,32607253879200,46581791256000,48910880818800,55898149507200,65214507758400,93163582512000,97821761637600,130429015516800,195643523275200,260858031033600,288807105787200,391287046550400,577614211574400,782574093100800,866421317361600,1010824870255200,1444035528936000,1516237305382800,1732842634723200,2021649740510400,2888071057872000,3032474610765600,4043299481020800,6064949221531200,8086598962041600,10108248702552000,12129898443062400,18194847664593600,20216497405104000,24259796886124800,30324746107656000,36389695329187200,48519593772249600,60649492215312000,72779390658374400,74801040398884800,106858629141264000,112201560598327200,149602080797769600,224403121196654400,299204161595539200,374005201994424000,448806242393308800,673209363589963200,748010403988848000,897612484786617600,1122015605983272000,1346418727179926400,1795224969573235200,2244031211966544000,2692837454359852800};

LL n;

int main()
{
    for(int m = Read(); m ; m--)
    {
        n = Read();
        printf("%lld\n",p[std::upper_bound(p+1,p+162,n)-p-1]);
    }
    return 0;
}
/*# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define LL long long
# define N 100000
# define Gc (SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
char BB[1<<15],*SS=BB,*TT=BB;
inline LL Read()
{
    register LL x = 0;char ch = Gc;

    while(ch < '0' || ch > '9')ch = Gc;

    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = Gc;}

    return x;
}

const LL p[11][35] = 
{
{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,},
{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,},
{0,1,2,3,4,5,6,7,8,9,10,11,12,},
{0,1,2,3,4,5,6,7,8,9,10,},
{0,1,2,3,4,5,6,7,8,},
{0,1,2,3,4,5,6,7,8,},
{0,1,2,3,4,5,6,7,},
{0,1,2,3,4,5,6,7,},
{0,1,2,3,4,5,6,},
{0,1,2,3,4,5,6,},
{0,1,2,3,4,5,6,}
};

const LL V[11][35] = 
{
{1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,},
{1,3,9,27,81,243,729,2187,6561,19683,59049,177147,531441,1594323,4782969,14348907,43046721,129140163,387420489,},
{1,5,25,125,625,3125,15625,78125,390625,1953125,9765625,48828125,244140625,},
{1,7,49,343,2401,16807,117649,823543,5764801,40353607,282475249,},
{1,11,121,1331,14641,161051,1771561,19487171,214358881,},
{1,13,169,2197,28561,371293,4826809,62748517,815730721,},
{1,17,289,4913,83521,1419857,24137569,410338673,},
{1,19,361,6859,130321,2476099,47045881,893871739,},
{1,23,529,12167,279841,6436343,148035889,},
{1,29,841,24389,707281,20511149,594823321,},
{1,31,961,29791,923521,28629151,887503681,}
};

LL ans,idx,n,ANS[N+5];
struct Node
{
	LL Val,Ans;
	int idx;
	bool operator < (const Node& b)const{return Val < b.Val;}	
} Q[N+5];

void dfs(LL cur,LL x,LL num,const LL limit)
{
	if(x > limit) return;
	else if(cur >= 11)
	{
		if(idx < num) {ans = x;idx = num;}
		else if(idx == num && ans > x) ans = x;
	}
	else
	{
		for(int i = 0; V[cur][i] ; ++i) dfs(cur+1,x*V[cur][i],num*(p[cur][i]+1),limit);
	}
}

void Solve(const int L,const int R)
{
	if(R < L) return;
	int mid = (L+R)>>1;idx = 0;ans = 0;
	dfs(0,1,1,Q[mid].Val);
	Q[mid].Ans = ans;
	if(L == R) return;
	if(ans != Q[L-1].Ans) Solve(L,mid-1);
	else for(int i = L; i < mid ; ++i) Q[i].Ans = ans;
	if(ans != Q[R+1].Ans) Solve(mid+1,R);
	else for(int i = mid+1; i <= R ; ++i) Q[i].Ans = ans;
} 

int main()
{
	freopen("ysqm.in","r",stdin);
    int m;scanf("%d",&m);
	for(int i = 1; i <= m ; ++i) Q[i].Val = Read();
	for(int i = 1; i <= m ; ++i) Q[i].idx = i;
	std::sort(Q+1,Q+m+1);
    Solve(1,m);
	for(int i = 1; i <= m ; ++i) ANS[Q[i].idx] = Q[i].Ans;
	for(int i = 1; i <= m ; ++i) printf("%lld\n",ANS[i]);
    return 0;//349188840
}*/
