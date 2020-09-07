/*
	Name：Splay（文艺平衡树）
	Last Change: 2020/3/4 - 15：50 
	need：<cstdio> 
	code by :云岁月书 
*/ 

# include <cstdio>

struct node
{	
	node *son[2],*father;
	int value,tag,Size;
	
	node(){son[0] = son[1] = father = NULL;value = tag = Size = 0;}
	
	inline void update(){Size = tag + (son[0] == NULL ? 0 : son[0]->Size) + (son[1] == NULL ? 0 : son[1]->Size);}
	
	inline bool Whichson()
	{
		if(father == NULL) return 0;
		return father->son[1] == this;
	}
	
	inline void Clear_Son()
	{
		if(son[0] != NULL){son[0]->Clear_Son();delete son[0];}
        if(son[1] != NULL){son[1]->Clear_Son();delete son[1];}
	}
};

struct Splay_tree
{
	node *root;
	
	Splay_tree(){root = NULL;}
	
	~Splay_tree(){if(root != NULL) root->Clear_Son();}
	
	inline node* Create_Node(const int val)
	{
		node *temp_ = new node();
		temp_->value = val;
		++temp_->tag;
		return temp_;
	}

	inline void link(node *from,node *newfather,const int side)
	{
		if(newfather != NULL)  newfather->son[side] = from;//0左1右 
		
		if(from != NULL) from->father = newfather;
	}

	inline void rotate(node *ST)
	{
		if(ST == root) return;//反向子代我位，父代反向子位，我代父位
		
		node *fa = ST->father,*gr = ST->father->father;
		
		int my_side = ST->Whichson(),fa_side = fa->Whichson();//my_side = my_side >= 1 ? 1 : 0;
		
		link(ST->son[my_side ^ 1],fa,my_side);//把和自己方向相反的儿子连到自己的父亲上，且方向和自己相同
		
		link(fa,ST,my_side ^ 1);//把父亲连到自己上，方向和自己的方向相反 
		
		link(ST,gr,fa_side);//把自己连到爷爷上，方向和父亲相同
		
		fa->update();ST->update();//更新结点信息 
	}
	
	inline void Splay(node *ST,node *target = NULL)//双旋伸缩，有效平衡 
	{
		while(ST->father != target){
			node *fa = ST->father,*gr = ST->father->father;
			
			if(gr != target){
				if(ST->Whichson() == fa->Whichson()) rotate(fa);
				else rotate(ST);
			}
			
			rotate(ST); 
		}
		
		if(target == NULL) root = ST;
	}
	
	/*基础函数至此结束*/
	
	/*功能性函数开始*/
	
	inline node* choose_Son(node *ST,const int val)
	{
    	if(ST->value > val)return ST->son[0];
    	
    	else return ST->son[1]; 
	}
	
	inline void find(const int val)
	{
		if(root == NULL) return;
		
		node *cur = root;
		
		while(choose_Son(cur,val) != NULL && cur->value != val) cur = choose_Son(cur,val);
		
		Splay(cur);
	}
	
	inline node* get_Pre(const int val)
	{
		find(val);
		
		if(root->value < val) return root;
		
		node *cur = root->son[0];
		
		if(cur == NULL) return root;
		
		while(cur->son[1] != NULL) cur = cur->son[1];
		
		return cur;
	}
	
	inline node* get_Suf(const int val)
	{
		find(val);
		
		if(root->value > val) return root;
		
		node *cur = root->son[1];
		
		if(cur == NULL) return root;
		
		while(cur->son[0] != NULL) cur = cur->son[0];
		
		return cur;
	}
	
	inline void insert(const int val)
	{
		if(root == NULL){
			root = Create_Node(val);
			root->update();//注意更新大小 
			return;
		}
		
		node *cur = root;
		
		while(choose_Son(cur,val) != NULL && cur->value != val) cur = choose_Son(cur,val);
		
		if(cur->value == val){
			++cur->tag;
			//cur->update();
			Splay(cur);
			return; 
		}
		
		node *ct = Create_Node(val);
		
		link(ct,cur,val > (cur->value));
		
		Splay(ct);
	}
	
	inline void D_N(node *ST)
	{	
		if(ST->tag > 1){//节点重复数大于1，直接dupcnt--，记得update
			--ST->tag;
			ST->update();
			return; 
		}
		
		if(ST == root){//删除根，特判
			delete root;//如果可能，在这里最好递归，删除所有子节点 
            root = NULL;
            return;
		}
		
		ST->father->son[ST->Whichson()] = NULL;//修改父亲，更新父亲
        ST->father->update();
		
		delete ST;
	}
	
	inline void delete_Node(const int val)
	{
		node *pre = get_Pre(val);node *suf = get_Suf(val);
    	
    	if(pre->value == val && suf->value == val) {
    		D_N(root);
        	return;
    	}
    	
   		if(pre->value == val) {
    	    Splay(suf);
			D_N(pre);
    		return;
    	}
    	
    	if(suf->value == val) {
    		Splay(pre);
			D_N(suf);
    		return;
    	}
    	
    	Splay(pre);//前驱旋转到根
    	
		Splay(suf,pre);//后继旋转到根下面
    	
		D_N(suf->son[0]);//删除后继的左儿子
	} 
	
	inline int get_Child_Cnt(const node* ST,const int side)//返回以某个节点的左/右儿子为子树的节点数。
	{
		if(ST->son[side] == NULL) return 0;
		return ST->son[side]->Size;
	}
 
	inline int get_Rank(const int num)//查询num的排名
	{
    	find(num);
    	
    	return root->Size - get_Child_Cnt(root,1) - root->tag + 1;
	}
	
	inline int get_Num(int k)//查找第 K 大的数 
	{
		node *cur = root;
		
		while(1){
			if(cur->son[0] != NULL && k <= cur->son[0]->Size) cur = cur->son[0];//在左子树里 
			
			else if(k > get_Child_Cnt(cur,0) + cur->tag){//k比左子树+自己的重复次数还大，说明在右子树里
				k -= get_Child_Cnt(cur,0) + cur->tag;
            	cur = cur->son[1];
			}
			
			else return cur->value;
		}
		 
	}
	
	/*
		初步完工时间：2020/3/2 - 17:10(未调试) 
		花费时间：约200min 
	*/ 
	
	/*
		关于翻转：
				我们为了方便，在 1 号节点之前和 n 号节点之后又加了两个节点并赋值为 -INF 和 INF ，
				作为虚点，既满足二叉搜索树的性质，又可以让我们在翻转 1 ~ n 时不会 GG 。 
	*/ 
} T;

inline int Read()
{
	int x = 0,f = 1;char c = getchar();
	
	while(c < '0' || c > '9') {if(c == '-') f = -1;c = getchar();}
	
	while(c >= '0' && c <= '9'){x = x * 10 + (c ^ 48);c = getchar();}
	
	return x * f;
}

int sq,pos,x;//int debug = 0;

int main()
{	
	freopen("1.txt","r",stdin);

	sq = Read();/*if(debug == 286 && pos == 6){printf("fuck!mother fack!WA!!!!!!!!!\n");}*/
	
	while(sq--){
		pos = Read();x = Read();
		
		switch(pos)
		{
			case 1:
				   T.insert(x);
				   break;
			case 2:
				   T.delete_Node(x);
				   break;
			case 3:
				   printf("%d\n",T.get_Rank(x));
				   break;
			case 4:
				   printf("%d\n",T.get_Num(x));
				   break;
			case 5:
				   printf("%d\n",T.get_Pre(x)->value);
				   break;
			case 6:
				   printf("%d\n",T.get_Suf(x)->value);
				   break;
		}
	}
	
	return 0;
}
