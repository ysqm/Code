# include <cstdio>
# define File(x) freopen(#x".in","r",stdin)//;freopen(#x".out","w",stdout)
# define nullptr NULL 

//左倾红黑树
namespace RedBlackTree
{

    class RBT
    {
        private:
            bool COLOR;
            unsigned int Size;
            int Rep,Value;
            RBT *Son[2],*fa;
            static RBT *root;
            static const bool Red = true,Black = false;//可改良将判断颜色写成函数
            int WhichSon(){
                if(fa == nullptr) return -1;
                return (fa->Son[1]) == this;
            }
            void Update(){
                Size = Rep+(Son[0] == nullptr ? 0 : Son[0]->Size)+(Son[1] == nullptr ? 0 : Son[1]->Size);
            }
            void Clear(){
                if(Son[0]!=nullptr) {Son[0]->Clear();delete Son[0];}
                if(Son[1]!=nullptr) {Son[1]->Clear();delete Son[1];}
            }
            RBT* bother(){
                return (fa == nullptr ? nullptr : fa->Son[WhichSon()^1]);
            }
            //判断是否是二节点
            bool IsTwonode(){
                return COLOR == Red ? false : (Son[0] == nullptr ? true : (Son[0]->COLOR == Black));
            }
            void link(RBT*,RBT*,bool);
            void rotate(RBT*,bool);
            RBT* create(int);
            RBT* chooseSon(int);
            RBT* get_Suf(int);
            RBT* get_Pre(int);
            RBT* get_Suf(int,RBT*);
            RBT* get_Pre(int,RBT*);
            void updateline();
            void ChangeColor();
        public :
            RBT* Find(int);
            void Insert(int);
            void Delete(int);
            int  Suf(int);
            int  Pre(int);
            int  Rank(int);
            int Get_Rank(int);
            RBT(unsigned int,int,int);
            ~RBT();
    } ;

    RBT::RBT(const unsigned int _Size=0,const int _Rep=0,const int _Val=0):Value(_Val),Rep(_Rep),Size(_Size){
        fa=Son[0]=Son[1]=nullptr;
    }

    RBT::~RBT(){}

    RBT* RBT::create(const int Val){
        RBT *ptr = new RBT(1,1,Val);
        ptr->COLOR = Red;
        return ptr;
    }

    //更新从根节点到当前节点的值
    void RBT::updateline(){
        RBT *cur = this;
        while(cur != nullptr){
            cur->Update();
            cur = cur->fa;
        }
    }

    void RBT::link(RBT *fa,RBT *Cur,bool Side){
        if(fa != nullptr) fa->Son[Side] = Cur;
        if(Cur != nullptr) Cur->fa = fa;
    }

    //将 side 方向节点转上来
    void RBT::rotate(RBT *Cur,bool Side){
        if(Cur == nullptr || Cur->Son[Side] == nullptr) return; 
        RBT *fa = Cur->fa,*Ncur = Cur->Son[Side];
        link(fa,Ncur,Cur->WhichSon());
        link(Cur,Ncur->Son[Side^1],Side);
        link(Ncur,Cur,Side^1);
        Cur->Update();Ncur->Update();
    }

    //维护红黑树性质，解决右红
    void RBT::ChangeColor(){
        RBT *res = this;
        while(res != nullptr) {
            if(res->COLOR == Red) continue;
            if(res->Son[1] != NULL && res->Son[1]->COLOR == Red){//右儿子为红色
                if(res->Son[0] != NULL && res->Son[0]->COLOR == Red){//左节点为红进行上溢
                    res->COLOR = Red;
                    res->Son[0]->COLOR = res->Son[1]->COLOR = Black;
                } else {//左非红，右红提上来
                    res->COLOR = Red;
                    res->Son[1]->COLOR = Black;
                    rotate(res,1);
                }
            }
            res = res->fa;
        }
    }

    void RBT::Insert(const int Val){
        if(root == nullptr) {root = create(Val);root->COLOR = Black;}
        else {
            RBT *cur = root,*res;
            while(cur != nullptr && cur->Value != Val) {
                res = cur;
                cur = cur->chooseSon(Val);
            }
            if(cur != nullptr)
            {
                cur->Rep++;
                cur->updateline();
            } else if(Val < res->Value){
                res->Son[0] = create(Val);
            } else {
                res->Son[1] = create(Val);
            }
            if(cur == nullptr){//插入了新节点才需要变色
                if(res->COLOR == Red) {//父节点是红色
                    if(Val > res->Value) rotate(res,1);//左右二红，转换成连续二左红
                    res->COLOR = Black;res->fa->COLOR = Red;
                    rotate(res->fa,0);
                }
                res->ChangeColor();
            }
        }
    }

    void RBT::Delete(const int Val){
        RBT* cur = Find(Val);
        if(cur != nullptr){
            if(cur->Rep > 1) {//不用删除节点
                --(cur->Rep);
                cur->updateline();
            } else {
                //这里通过交换被删除数据与后驱保持性质
                //RBT *Suf = get_Suf(Val,cur);
                RBT *rt = cur->Son[1];
                //从cur右子树遍历，找到后驱，并中途调整颜色，使后驱成为红节点
                //中途调整要做到只存在右红的违规性质
                if(rt != nullptr) {//存在后驱。
                    while(true){
                        /*
                        我们从当前的根节点出发，利于2-3树中预合并的策略逐层对红黑树进行调整。
                        具体的做法是，每次都保证当前的节点是2-3树中的非2节点，
                        如果当前节点已经是非2节点，那么直接跳过；
                        如果当前节点是2节点，那么根据兄弟节点的状况来进行调整：
                        如果兄弟是2节点，那么从父节点借一个元素给当前节点，
                        然后与兄弟节点一起形成一个临时4节点。
                        如果兄弟是非2节点，那么兄弟上升一个元素到父节点，
                        同时父节点下降一个元素到当前节点，使得当前节点成为一个3节点。
                        */ //红节点和红左儿子都跳过
                        if((rt->COLOR == Red) || (rt->Son[0] != nullptr && rt->Son[0]->COLOR == Red)){
                            if(rt->Son[0] == nullptr){
                                break;//找到了红节点后驱
                            }
                            rt = rt->Son[0];
                            continue;
                        }
                        //二节点处理
                        if(rt == cur->Son[1]){//根节点提上来组成四节点
                            if(rt->Son[0] != nullptr) rt->Son[0]->COLOR = Red;
                            if(rt->Son[1] != nullptr) rt->Son[1]->COLOR = Red;
                        } else {
                            if(rt->bother() != nullptr) {//判断兄弟是否是非二节点
                                if(rt->bother()->IsTwonode()) {
                                    rt->bother()->COLOR = Red;
                                    rt->COLOR = Red;
                                    rt->fa->COLOR = Black;
                                } else {//兄弟是三节点，最为复杂的情况
                                    //rt 对应 B5，rt->fa 对应 R2 ，bother 对应 B3
                                    RBT *B3 = rt->bother();
                                    RBT *R2 = rt->fa;
                                    RBT *R4 = B3->Son[0];
                                    //调整结构
                                    link(R2->fa,R4,0);
                                    link(B3,R4->Son[1],0);//B10
                                    link(R4,B3,1);
                                    link(R2,R4->Son[0],1);//B9
                                    link(R4,R2,0);
                                    //变色
                                    R2->COLOR = Black;
                                    rt->COLOR = Red;
                                    //更新右子树大小
                                    B3->Update();
                                }
                            } else {//无兄弟向上提
                                rt->COLOR = Red;
                                rt->fa->COLOR = Black;
                            }
                        }
                        rt = rt->Son[0];
                        if(rt->Son[0] == nullptr) rt->COLOR = Red;//如果 rt 是黑节点，那么它必然不会有非空子节点
                    }//while 循环结束
                    cur->Value = rt->Value;
                    cur->Rep = rt->Rep;//交换后驱与被删除数的数据域
                    rt->Size = 0;
                    rt->Rep = 0;
                    rt->updateline();
                } else {
                    if(cur->COLOR == Black && cur->Son[0] != nullptr){
                        rt = cur->Son[0];//rt 节点必然是红叶子
                        link(cur->fa,rt,cur->WhichSon());//cur 是根节点也不会影响连边。
                        delete cur;//delete 最好单独写个函数
                        rt->COLOR = Black;
                        rt->updateline();
                    } else {//红色叶子节点删掉无影响
                        rt = cur->fa;
                        delete cur;
                        rt->updateline();
                    }
                }
            }
        }
    }

    RBT* RBT::chooseSon(const int Val){
        if(Value > Val) return Son[1];
        else if(Value < Val) return Son[0];
        else return this;
    }

    RBT* RBT::Find(const int Val){
        RBT *cur = root;
        if(cur != nullptr){
            while(cur != nullptr && cur->Value != Val) cur = cur->chooseSon(Val);
        }
        return cur;
    }

    RBT* RBT::get_Pre(const int Val){
        RBT *cur = root;
        RBT *res = nullptr;
        while(cur != nullptr){
            if(cur->Value < Val){
                res = cur;
                cur = cur->Son[1];
            }
            else cur = cur->Son[0];
        }
        return res;
    }

    RBT* RBT::get_Suf(const int Val){
        RBT *cur = root;
        RBT *res = nullptr;
        while(cur != nullptr){
            if(cur->Value > Val){
                res = cur;
                cur = cur->Son[1];
            }
            else cur = cur->Son[0];
        }
        return res;
    }

    // RBT* RBT::get_Pre(const int Val,RBT *Startpoint){
    //     RBT *cur = Startpoint;
    //     RBT *res = nullptr;
    //     while(cur != nullptr){
    //         if(cur->Value < Val){
    //             res = cur;
    //             cur = cur->Son[1];
    //         }
    //         else cur = cur->Son[0];
    //     }
    //     return res;
    // }

    // RBT* RBT::get_Suf(const int Val,RBT *Startpoint){
    //     RBT *cur = Startpoint;
    //     RBT *res = nullptr;
    //     while(cur != nullptr){
    //         if(cur->Value > Val){
    //             res = cur;
    //             cur = cur->Son[1];
    //         }
    //         else cur = cur->Son[0];
    //     }
    //     return res;
    // }

    int RBT::Pre(const int Val){
        RBT *cur = get_Pre(Val);
        return cur == nullptr ? -1 : cur->Value;
    }

    int RBT::Suf(const int Val){
        RBT *cur = get_Suf(Val);
        return cur == nullptr ? -1 : cur->Value;
    }

    int RBT::Rank(const int Rnk){
        int kth = 0;
        RBT *cur = root;
        while(kth < Rnk){
            if(cur->Son[0] == nullptr){
                kth += cur->Rep;
                if(kth >= Rnk) return cur->Value;
                cur = cur->Son[1];
            } else if(kth+cur->Son[0]->Size < Rnk){
                kth += cur->Rep+cur->Son[0]->Size;
                if(kth >= Rnk) return cur->Value;
                cur = cur->Son[1];
            } else {
                cur = cur->Son[0];
            }
        }
        return -1;
    }

    int RBT::Get_Rank(const int Val){
        RBT *cur = root;
        int kth = 0;
        while(cur != nullptr){
            if(cur->Value > Val){
                cur = cur->Son[0];
            } else if(cur->Value < Val){
                kth += cur->Rep+(cur->Son[0] == nullptr ? 0 : cur->Son[0]->Size);
                cur = cur->Son[1];
            } else return kth+1;
        }
        return -1;
    }
}

RedBlackTree::RBT* RedBlackTree::RBT::root = nullptr;
RedBlackTree::RBT T;
int n,opt,x;

int main(){
    File(RBT);
    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&opt,&x);
        switch (opt)
        {
            case 1 :
                    T.Insert(x);
                    break;
            case 2 :
                    T.Delete(x);
                    break;
            case 3 :
                    printf("%d\n",T.Get_Rank(x));
                    break;
            case 4 :
                    printf("%d\n",T.Rank(x));
                    break;
            case 5 :
                    printf("%d\n",T.Pre(x));
                    break;
            case 6 :
                    printf("%d\n",T.Suf(x));
                    break;
        }
    }
}



