# include <cstdio>
# define N 50000 
# define Gc getchar()

inline int Read()
{
    register int x = 0,f = 1;char ch = Gc;

    while(ch < '0' || ch > '9'){if(ch == '-') f = -1;ch = Gc;}

    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = Gc;}

    return f < 0 ? ~x+1 : x;
}

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

int tot_size,root,randomx;//��ʼ�����

inline int rand(){return randomx = (randomx * Seed_+_Increment);}//������������ xi = (x(i-1)*(4p+1)+(2q+1))%m��m �� 4p+1 ����

inline void update(const int x){sz(x) = sz(son(x,0)) + sz(son(x,1))+rep(x);}

inline void rotate(int& x,const int side)//�����Ӵ���λ,����������λ���Ҵ���λ
{
    int p = son(x,side);//��¼���Լ�
    son(x,side) = son(p,!side);//�����Ӵ���λ
    son(p,!side) = x;//����������λ
    update(x);
    update(p);
    x = p;//�Ҵ���λ
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
        if(Val == V(x)) ++rep(x);//ά��һ�������
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

inline int Get_Rank(const int Val)//��ѯ val ������
{
    int kth = 0,x = root;
    while(x)
    {
        if(V(x) == Val) return kth + sz(son(x,0)) + 1;
        if(V(x) < Val) {kth += rep(x) + sz(son(x,0));x = son(x,1);}
        else x = son(x,0);
    }
    return kth + 1;// -1 ����������
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

int main()
{
	register char s[4];
	register int n,x,m;
	
	n = Read();
	
	for(register int i = 1 ; i <= n ; ++i) Insert(Read());
	
	m = Read();
	
	while(m--)
	{
		scanf("%s",s);
		
		if(s[0] == 'a')
		{
			x = Read();++n;
			Insert(x);
		}
		else 
		{
			printf("%d\n",Get_Num(n&1 ? (n>>1)+1 : n>>1));
		}
	}
	
	return 0;
}
