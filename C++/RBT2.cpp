# include <cstdio>
# define File(x) freopen(#x".in","r",stdin)

template<typename value>
class my_rbt
{
    //# define _RED false
    //# define _BLACK true

    enum {_RED,_BLACK}

    class Node
    {
        public:
            bool COLOR;
            unsigned int Size,Rep;
            value val;
            Node *Son[2],*fa;
            void update();
            void updateline();
            int whichSon();
            bool istwonode();
            Node* brother();
            void clear();
            Node():COLOR(_RED),Size(0),Rep(0){};
    } root;

    void rotate(Node*,bool);
    void link(Node*,Node*,bool);
    Node* chooseSon(int);
    Node* Pre(int,Node*);
    Node* Suf(int,Node*);
    void changecolor();
    Node* Find(int);
    void Insert(int);
    void Delete(int);
    int Rank(int);
    int Get_Rank(int);

    Node* Create()
    {
        Node *ptr = new Node();
        ptr->fa = ptr->Son[0] = ptr->Son[1] = nullptr;
        return ptr;
    }

    void Node::update(){
        Size = Rep + (Son[0] == nullptr ? 0 : Son[0]->Size) + (Son[1] == nullptr ? 0 : Son[1]->Size);
        return;
    }

    void Node::updateline(){
        Node *cur = this;
        while(cur != nullptr){
            cur->update();
            cur = cur->fa;
        }
    }

    int Node::whichSon(){
        if(fa == nullptr) return -1;
        return fa->Son[1] == this;
    }

    void Node::clear(){
        if(Son[0] != nullptr){
            Son[0]->clear();
            delete Son[0];
        }
        if(Son[1] != nullptr){
            Son[1]->clear();
            delete Son[1];
        }
    }

    bool Node::istwonode(){
        return COLOR == _RED ? false : (Son[0] == nullptr ? true : (Son[0]->COLOR == _BLACK));
    }

    Node* Node::brother(){
        return (fa == nullptr ? nullptr : fa->Son[whichSon()^1]);
    }

    //判断是否是黑色节点
    bool colorb(Node *cur){
        return cur == nullptr || cur->COLOR == _BLACK;
    }

};

template<typename value>
void my_rbt<value>::link(Node *fa,Node *cur,bool Side){
    if(fa != nullptr) fa->Son[Side] = cur;
    if(cur != nullptr) cur->fa = fa;
}

template<typename T>
void my_rbt<T>::rotate(Node *cur,bool Side){
    if(cur == nullptr || cur->Son[Side] == nullptr) return;
    Node *fa = cur->fa,*Ncur = cur->Son[Side];
    link(fa,Ncur,cur->whichSon());
    link(cur,Ncur->Son[Side^1],Side);
    link(Ncur,cur,Side^1);
    cur->update();Ncur->update();
}