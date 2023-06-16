# include <ctime>
# include <cmath>
# include <queue>
# include <vector>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define LL long long
# define File(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout)
# define N 100000

char s[42];
int a[N+5],n,L,P;
const LL MAX = 1e18;

template<class T> T ABS(const T x){return x < 0 ? (~x+1) : x;}

class Treap
{
    private:
            struct node
            {
                node *fa;
                node *Son[2];
                int Val,rnd,Size,repetition;
                node(const int Val_=0,const int rnd_=0):Val(Val_),rnd(rnd_){repetition = Size = 1;fa = Son[0] = Son[1] = NULL;}
                int WhichSon(){return (fa == NULL ? 0 : fa->Son[1] == this);}
                void Update(){Size = (Son[0] == NULL ? 0 : Son[0]->Size) + (Son[1] == NULL ? 0 : Son[1]->Size) + repetition;}
                void Clear_Son()
                {
                    if(Son[0] != NULL) Son[0]->Clear_Son();
                    if(Son[1] != NULL) Son[1]->Clear_Son();
                    delete this;
                }
            } rt;
            
            # define Son(x,y) (x->Son[y])
            # define Val(x) (x->Val)
            # define rnd(x) (x->rnd)
            # define fa(x) (x->fa)
            # define Size(x) (x->Size)
            # define rep(x) (x->repetition)
            
            node* Create(const int val){return new node(val,rand());}
            void Link(node* fa,node* p,int Side)
            {
                if(fa != NULL) {Son(fa,Side) = p;fa->Update();}
                if(p != NULL) {fa(p) = fa;p->Update();}
            }
            /*void LZ(node *p)
            {
                node *rs = Son(p,1);
                node *B = Son(rs,0);
                node *Fa = fa(p);
                Link(Fa,rs,(Fa == NULL ? 0 : (Son(Fa,1)==p)));
                Link(rs,p,0);
                Link(p,B,1);
            }*/
            void Rotate(node *p,int Side)
            {
                //int fa_Side = p->WhichSon();
                node *ps = Son(Son(p,Side^1),Side);
                Link(fa(p),Son(p,Side^1),p->WhichSon());
                Link(Son(p,Side^1),p,Side);
                Link(p,ps,Side^1);
            }
    public :
            Treap(){rt = NULL;}
            node* Insert(const int val,node *p)
            {
                if(p == NULL) return p = Create(val);
                else 
                {
                    if(Val(p) == val) ++rep(p);
                    else if(val < Val(p)){Son(p,0) = Insert(val,Son(p,0));if(rnd(p) < rnd(Son(p,0))) Rotate(p,1);}
                    else {Son(p,1) = Insert(val,Son(p,1));if(rnd(p) < rnd(Son(p,1))) Rotate(p,0);}
                    return p;
                }
            }
            node* Delete(const int val,node *p)
            {
                if(val == Val(p))
                {
                    if(rep(p) > 1) --rep(p);
                    else if(Son(p,0) == NULL) return Son(p,0);
                    else if(Son(p,1) == NULL) return Son(p,1);
                    else if(rnd(Son(p,0)) > rnd(Son(p,1))) {Rotate(p,1);Son(p,0) = Delete(val,Son(p,0));}
                    else {Rotate(p,0);Son(p,1) = Delete(val,Son(p,1));}
                }
            }
};





int main()
{
    File(poem);
    int T;
    
    return 0;
}

