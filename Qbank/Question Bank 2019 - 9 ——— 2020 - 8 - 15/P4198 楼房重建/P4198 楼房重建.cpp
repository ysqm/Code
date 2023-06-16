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
# define Ls(i) (i<<1)
# define Rs(i) (i<<1|1)
# define mid ((L+R)>>1)
# define LL long long
# define N 100000
# define Max(a,b) a > b ? a : b;

inline int Read()
{
	reg int x = 0;reg char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	return x;
}

int n,m,seg_sum[(N << 2) + 42];
double seg[(N << 2) + 42];

inline int query(const double& val,const int L,const int R,const int K)
{
	if(seg[K] <= val) return 0;
	if(L == R) return seg[K] > val;
	if(seg[Ls(K)] <= val) return query(val,mid+1,R,Rs(K));
	else return query(val,L,mid,Ls(K)) + seg_sum[K] - seg_sum[Ls(K)];
}

inline void Insert(const int& Poistion,const double& val,const int L,const int R,const int K)
{
	if(L == R && L == Poistion) {seg_sum[K] = 1;seg[K] = val;return ;}
	
    if(Poistion <= mid) Insert(Poistion,val,L,mid,Ls(K));
    
    else Insert(Poistion,val,mid+1,R,Rs(K));
    
    seg[K] = Max(seg[Ls(K)],seg[Rs(K)]);
    
    seg_sum[K] = seg_sum[Ls(K)] + query(seg[Ls(K)],mid+1,R,Rs(K));
}

int main()
{
    n = Read();m = Read();
    
    for(reg int i = 1,x,y; i <= m; ++i)
    {
        x = Read();y = Read();
        
        double value = (((double)y)/x);
        
        Insert(x,value,1,n,1);
        
        printf("%d\n",seg_sum[1]);
    }
    return 0; 
}
