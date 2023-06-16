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
# define M 50000

inline int Read()
{
	int x = 0;char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch <= '9' && ch >= '0') {x = x*10 + (ch ^ 48);ch = getchar();}
	
	return x;
}

struct LinearBasis
{
	# define N 32
	
	int base[N];
	
	LinearBasis(){}
	
	LinearBasis(const int zx){memset(base,zx,sizeof(base));}

	inline void Insert(int x)
	{
		for(reg int i = N-1; ~i ; --i)
			if(x >> i)//¿É¼ò»¯³É £¨x >> i£© 
			{
				x ^= base[i];
				if(base[i] == 0){base[i] ^= x;return;}
			}
	}
	
	inline void Merge(LinearBasis x)
	{
		for(reg int i = N-1; ~i ; --i) if(x.base[i]) Insert(x.base[i]);
	}
	
	inline int Xor_Sum_Max()
	{
		int res = 0;
		
		for(reg int i = N-1; ~i ; --i) if((res ^ base[i]) > res)   res ^= base[i];
		
		return res; 
	}
	
	# undef N
};

struct SegTree
{
	# define Ls(i) (i<<1)
	# define Rs(i) (i<<1|1)
	# define mid ((L+R)>>1)
	# define lb LinearBasis
	
	lb Seg[(M << 2) + 42];
	
	inline void Insert(const int& Poistion,const int& val,const int L,const int R,const int K=1)
	{
		Seg[K].Insert(val);
		
		if(L == R) return;
		
		if(mid >= Poistion) Insert(Poistion,val,L,mid,Ls(K));
		else Insert(Poistion,val,mid+1,R,Rs(K));
	}
	
	inline void query(lb& x,const int& ask_L,const int& ask_R,const int L,const int R,const int K=1)
	{
		if(ask_L <= L && ask_R >= R){x.Merge(Seg[K]);return;}
		
		if(mid >= ask_L) query(x,ask_L,ask_R,L,mid,Ls(K));
		
		if(mid < ask_R) query(x,ask_L,ask_R,mid+1,R,Rs(K));
	}
	
	# undef Ls
	# undef Rs
	# undef mid
	# undef lb
} T;

int n,m;

inline void ask(const int& ask_L,const int& ask_R)
{
	LinearBasis ans = LinearBasis(0);
	
	T.query(ans,ask_L,ask_R,1,m);
	
	printf("%d\n",ans.Xor_Sum_Max());
}

int main()
{
	n = Read();m = Read();
	
	for(reg int i = 1,pos,x,y; i <= n ; ++i)
	{
		pos = Read();x = Read();y = Read();
		
		if(pos == 1) T.Insert(x,y,1,m);
		else ask(x,y);
	}
	return 0;
}
