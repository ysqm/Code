/*
	Name��Splay������ƽ������
	Last Change: 2020/3/2 - 17��10 
	need��<cstdio> 
	code by :�������� 
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
		if(newfather != NULL)  newfather->son[side] = from;//0��1�� 
		
		if(from != NULL) from->father = newfather;
	}

	inline void rotate(node *ST)
	{
		if(ST == root) return;//�����Ӵ���λ������������λ���Ҵ���λ
		
		node *fa = ST->father,*gr = ST->father->father;
		
		int my_side = ST->Whichson(),fa_side = fa->Whichson();//my_side = my_side >= 1 ? 1 : 0;
		
		link(ST->son[my_side ^ 1],fa,my_side);//�Ѻ��Լ������෴�Ķ��������Լ��ĸ����ϣ��ҷ�����Լ���ͬ
		
		link(fa,ST,my_side ^ 1);//�Ѹ��������Լ��ϣ�������Լ��ķ����෴ 
		
		link(ST,gr,fa_side);//���Լ�����үү�ϣ�����͸�����ͬ
		
		fa->update();ST->update();//���½����Ϣ 
	}
	
	inline void Splay(node *ST,node *target = NULL)//˫����������Чƽ�� 
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
	
	/*�����������˽���*/
	
	/*�����Ժ�����ʼ*/
	
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
			root->update();//ע����´�С 
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
		if(ST->tag > 1){//�ڵ��ظ�������1��ֱ��dupcnt--���ǵ�update
			--ST->tag;
			ST->update();
			return; 
		}
		
		if(ST == root){//ɾ����������
			delete root;//������ܣ���������õݹ飬ɾ�������ӽڵ� 
            root = NULL;
            return;
		}
		
		ST->father->son[ST->Whichson()] = NULL;//�޸ĸ��ף����¸���
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
    	
    	Splay(pre);//ǰ����ת����
    	
		Splay(suf,pre);//�����ת��������
    	
		D_N(suf->son[0]);//ɾ����̵������
	} 
	
	inline int get_Child_Cnt(const node* ST,const int side)//������ĳ���ڵ����/�Ҷ���Ϊ�����Ľڵ�����
	{
		if(ST->son[side] == NULL) return 0;
		return ST->son[side]->Size;
	}
 
	inline int get_Rank(const int num)//��ѯnum������
	{
    	find(num);
    	
    	return root->Size - get_Child_Cnt(root,1) - root->tag + 1;
	}
	
	inline int get_Num(int k)//���ҵ� K ����� 
	{
		node *cur = root;
		
		while(1){
			if(cur->son[0] != NULL && k <= cur->son[0]->Size) cur = cur->son[0];//���������� 
			
			else if(k > get_Child_Cnt(cur,0) + cur->tag){//k��������+�Լ����ظ���������˵������������
				k -= get_Child_Cnt(cur,0) + cur->tag;
            	cur = cur->son[1];
			}
			
			else return cur->value;
		}
		 
	}
	
	/*
		�����깤ʱ�䣺2020/3/2 - 17:10(δ����) 
		����ʱ�䣺Լ200min 
	*/ 
	
	/*
		���ڷ�ת��
				����Ϊ�˷��㣬�� 1 �Žڵ�֮ǰ�� n �Žڵ�֮���ּ��������ڵ㲢��ֵΪ -INF �� INF ��
				��Ϊ��㣬��������������������ʣ��ֿ����������ڷ�ת 1 ~ n ʱ���� GG �� 
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
	sq = Read();/*freopen("P3369_6.in","r",stdin);if(debug == 286 && pos == 6){printf("fuck!mother fack!WA!!!!!!!!!\n");}*/
	
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
