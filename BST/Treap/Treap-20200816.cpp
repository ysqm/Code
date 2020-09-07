# include <cstdio>

# define Gc getchar()

inline int Read()
{
    register int x = 0,f = 1;char ch = Gc;

    while(ch < '0' || ch > '9'){if(ch == '-') f = -1;ch = Gc;}

    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = Gc;}

    return f < 0 ? ~x+1 : x;
}
/*
    Name : Treap(数组版)
    Code By : 云岁月书
    Could : 洛谷P3369,P6136（注意不要炸空间）
    Data ： 2020/8/16 10：10 创建该文档
*/

struct node
{
    int son[2],val,repetition,Size;
    unsigned int heap_val;

    node(){}
    ~node(){}
} ;

static const int Max_Tree_Size = 1e5;

static const int Seed_ = 1e9+9,_Increment = 1e9+7;

# define son(i,side) tree[i].son[side]
# define V(i) tree[i].val
# define sz(i) tree[i].Size
# define hv(i) tree[i].heap_val
# define rep(i) tree[i].repetition
# define INF 0x7f7f7f7f

node tree[Max_Tree_Size+5];

int tot_size,root,randomx;//初始随机数

inline int rand(){return randomx = (randomx * Seed_+_Increment);}//随机数最好满足 xi = (x(i-1)*(4p+1)+(2q+1))%m，m 与 4p+1 互质

inline void update(const int x){sz(x) = sz(son(x,0)) + sz(son(x,1))+rep(x);}

inline void rotate(int& x,const int side)//反向子代我位,父代反向我位，我代父位
{
    int p = son(x,side);//记录我自己
    son(x,side) = son(p,!side);//反向子代我位
    son(p,!side) = x;//父代反向我位
    update(x);
    update(p);
    x = p;//我代父位
}

inline int Create_New_Node(const int Val)
{
    V(++tot_size) = Val;
    sz(tot_size) = rep(tot_size) = 1;
    hv(tot_size) = rand();
    son(tot_size,0) = son(tot_size,1) = 0;
    return tot_size;
}

void Insert(const int Val,int &x = root)
{
    if(x == 0) x = Create_New_Node(Val);
    else
    {
        ++sz(x);
        if(Val == V(x)) ++rep(x);//维护一个大根堆
        else if(Val < V(x)) {Insert(Val,son(x,0));if(hv(x) < hv(son(x,0))) rotate(x,0);}
        else {Insert(Val,son(x,1));if(hv(x) < hv(son(x,1))) rotate(x,1);}
    }
}

void Delete(const int Val,int& x = root)
{
    //if(x == 0) return ;
    if(V(x) == Val)
    {
        if(rep(x) > 1) {--rep(x);--sz(x);}
        else if(son(x,0) == 0 || son(x,1) == 0) x = son(x,0) + son(x,1);
        else if(hv(son(x,0)) > hv(son(x,1))) {rotate(x,0);Delete(Val,x);}
        else {rotate(x,1);Delete(Val,x);}
        return ;
    }
    --sz(x);
    if(V(x) > Val) Delete(Val,son(x,0));
    else Delete(Val,son(x,1));
}

inline int Get_Rank(const int Val)//查询 val 的排名
{
    int kth = 0,x = root;
    while(x)
    {
        if(V(x) == Val) return kth + sz(son(x,0)) + 1;
        if(V(x) < Val) {kth += rep(x) + sz(son(x,0));x = son(x,1);}
        else x = son(x,0);
    }
    return kth + 1;// -1 代表不存在
}

inline int Get_Num(int k)
{
    int x = root;
    while(x)
    {
        if(sz(son(x,0)) < k)
        {
            if(sz(son(x,0)) + rep(x) >= k) return V(x);
            else {k = k - sz(son(x,0)) - rep(x);x = son(x,1);}
        }
        else x = son(x,0);
    }
    return x;
}

inline int Get_Pre(const int Val)
{
    int res = -INF,x = root;
    while(x)
    {
        if(Val > V(x)){res = V(x);x = son(x,1);}
        else x = son(x,0);
    }
    return res;
}

inline int Get_Suf(const int Val)
{
    int res = INF,x = root;
    while(x)
    {
        if(Val < V(x)){res = V(x);x = son(x,0);}
        else x = son(x,1);
    }
    return res;
}

void ZXBL(const int x)
{
    if(son(x,0)) ZXBL(son(x,0));
    printf("%d->",V(x));
    if(son(x,1)) ZXBL(son(x,1));
}

# undef son
# undef V
# undef sz
# undef hv
# undef rep

/*
P3369
int main()
{
    freopen("Treap.in","r",stdin);
    //freopen("Treap.out","w",stdout);

    register int n,x,opt;

    n = Read();int m = n;

    while(n--)
    {
        //printf("case %d:\n",m - n);
        //ZXBL(root);printf("\n");
        opt = Read();x = Read();
        if(opt == 1) Insert(x);
        else if(opt == 2) Delete(x);
        else if(opt == 3) printf("%d\n",Get_Rank(x));
        else if(opt == 4) printf("%d\n",Get_Num(x));
        else if(opt == 5) printf("%d\n",Get_Pre(x));
        else printf("%d\n",Get_Suf(x));
    }

    return 0;
}

/*
Right Answer：
106465
84185
492737
*/
int n,m;

int main()
{
	freopen("1.in","r",stdin); 
	//freopen("2.out","w",stdout);
	
	n = Read();m = Read();
	
	for(register int i = 1; i <= n; ++i) Insert(Read());
	
	register int pos,x,last = 0,ans = 0;
	
	while(m--){
		pos = Read();x = Read();x ^= last;
		
		
		switch(pos)
		{
			case 1:
				   Insert(x);
				   break;
			case 2:
				   Delete(x);
				   break;
			case 3:
				   last = Get_Rank(x);
				   break;
			case 4:
				   last = Get_Num(x);
				   break;
			case 5:
				   last = Get_Pre(x);
				   break;
			case 6:
				   last = Get_Suf(x);
				   break;
		}
		printf("%d %d\n",x,last);
		if(pos > 2) ans ^= last;
	}
	
	printf("%d",ans);
	
	return 0;
}