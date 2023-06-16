/*
    通过题目：
            洛谷SP1043 GSS1 - Can you answer these queries I
            洛谷SP1716 GSS3 - Can you answer these queries III
*/
# include <cstdio>

namespace Seg_Tree
{
    # define Size 50000
    # define sl(x) Seg[x].lsum
    # define sr(x) Seg[x].rsum
    # define sm(x) Seg[x].Midsum
    # define sa(x) Seg[x].Allsum
    # define Ls(K) (K<<1)
    # define Rs(K) (K<<1|1)
    
    struct node
    {
        int lsum,rsum,Midsum,Allsum;
        node(const int lsum_=0,const int rsum_=0,const int Midsum_=0,const int Allsum_=0):
		lsum(lsum_),rsum(rsum_),Midsum(Midsum_),Allsum(Allsum_){}
    } Seg[(Size<<2)+5];
    
    int Max(const int x,const int y){return x < y ? y : x;}
    int Min(const int x,const int y){return x < y ? x : y;}
    
    node Merge(const node ls,const node rs)
	{return 
	node(Max(ls.lsum,ls.Allsum+rs.lsum),
		 Max(rs.rsum,rs.Allsum+ls.rsum),
		 Max(Max(ls.Midsum,rs.Midsum),ls.rsum+rs.lsum),
		 ls.Allsum+rs.Allsum);
	}
     
    void PushUp(const int K){Seg[K] = Merge(Seg[Ls(K)],Seg[Rs(K)]);}
    
    void Build(const int L,const int R,const int K,const int *base)
    {
        if(L == R) sl(K) = sr(K) = sm(K) = sa(K) = base[L];
        else 
        {
            int mid = (L+R)/2;
            Build(L,mid,Ls(K),base);
            Build(mid+1,R,Rs(K),base);
            PushUp(K);
        }
    }
    
    void Modify(const int pos,const int Val,const int L,const int R,const int K)
    {
        if(L == R) sl(K) = sr(K) = sm(K) = sa(K) = Val;
        else 
        {
            int mid = (L+R)/2;
            if(pos <= mid) Modify(pos,Val,L,mid,Ls(K));
            else Modify(pos,Val,mid+1,R,Rs(K));
            PushUp(K);
        }
    }
    
    node Query(const int AL,const int AR,const int L,const int R,const int K)
    {
        if(AL <= L && R <= AR) return Seg[K];
        else
        {
        	int mid = (L+R)/2;
        	if(AR <= mid) return Query(AL,AR,L,mid,Ls(K));
        	else if(mid < AL) return Query(AL,AR,mid+1,R,Rs(K));
        	else return Merge(Query(AL,AR,L,mid,Ls(K)),Query(AL,AR,mid+1,R,Rs(K)));
		}
    }
    
    # undef Size
    # undef sl
    # undef sr
    # undef s
    # undef Ls
    # undef Rs
}

/*namespace Splay_Tree
{

}*/

int n,a[50005],opt,x,y,Q;

int main()
{
	//freopen("1.in","r",stdin); 
    scanf("%d",&n);
    for(int i = 1; i <= n ; ++i) scanf("%d",a+i);
    Seg_Tree::Build(1,n,1,a);
    scanf("%d",&Q);
    while(Q--)
    {
        scanf("%d%d%d",&opt,&x,&y);
        if(opt == 0) Seg_Tree::Modify(x,y,1,n,1);
        else 
		{
			Seg_Tree::node cur;cur = Seg_Tree::Query(x,y,1,n,1);
			printf("%d\n",cur.Midsum);
		}
		/*scanf("%d%d",&x,&y);
		printf("%d\n",Seg_Tree::Query(x,y,1,n,1).Midsum);*/
    }
}