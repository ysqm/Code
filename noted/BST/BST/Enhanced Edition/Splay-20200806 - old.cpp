# include <cstdio>

# define Gc getchar()//(SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
char BB[1<<15],*SS=BB,*TT=BB;

inline int Read()
{
	register int x = 0,f=1;register char ch = Gc;
	
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1;ch = Gc;}
	
	while(ch <= '9' && ch >= '0'){x = x*10 + (ch^48);ch = Gc;}
	
	return f < 0 ? -x : x;
}

int n,m;

# undef Gc		

		class node
		{
			public:
				node *father,*Son[2];
				int Value,Repetition,Size;
				
				node(){Son[0] = Son[1] = father = NULL;Value = Repetition = Size = 0;}
				
				inline void update(){Size = Repetition + (Son[0] == NULL ? 0 : Son[0]->Size) + (Son[1] == NULL ? 0 : Son[1]->Size);}
				
				inline bool Which_Son()
				{
					if(father == NULL) return NULL;
					else return father->Son[1] == this;
				}
				
				inline void Clear_Son()
				{
					if(Son[0] != NULL) {Son[0]->Clear_Son();delete Son[0];}
					if(Son[1] != NULL) {Son[1]->Clear_Son();delete Son[1];}
				}//定义 0 左 1 右，且左儿子小于当前节点，右儿子大于当前节点。 
		};

class Splay_Tree
{
	/*
		Name ：Splay 
		Code by: 云岁月书
		Data ： 2020/8/6-18:32 Start 2020/8/7-16:57
	*/
	//private:
	public:	
		
		
		node* root;
		
		inline node* Create_node(const int val)
		{
			node *temp = new node();
			
			temp->Size = temp->Repetition = 1;
			
			temp->Value = val;
			
			return temp;
		}
		
		inline void link(node* son,node* father,const bool Side)
		{
			if(father != NULL) father->Son[Side] = son;
			if(son != NULL) son->father = father;
		}
		
		inline void rotate(node* p)//，
		{
			if(p == root) return ;
			
			node *father = p->father,*grandfather = p->father->father;
			
			int my_side = p->Which_Son(),fa_side = father->Which_Son();
			
			link(p->Son[my_side^1],father,my_side);//反向子代我位
			link(father,p,my_side^1);//父代反向子位
			link(p,grandfather,fa_side);//我代父位
			
			father->update();p->update();
		}
		
		inline void Splay(node *p,node *Target = NULL)
		{
			while(p->father != Target)
			{
				node *father = p->father,*grandfather = p->father->father;
				
				if(grandfather != Target)
				{
					if(father->Which_Son() == p->Which_Son()) rotate(father);
					else rotate(p);
				}
				rotate(p);
			}
			
			if(Target == NULL) root = p;
		}
		
		inline void Delete(node* p)
		{
			if(p->Repetition > 1) {--p->Repetition;p->update();}
			
			else if(p == root){delete p;root = NULL;}
			
			else 
			{
				p->father->Son[p->Which_Son()] = NULL;
				p->father->update();
				delete p;
			}
		}
		
		inline int Get_Child_Cnt(const node *p,const int side)
		{
			/*if(p == NULL) return 0;
			else */if(p->Son[side] == NULL) return 0;
			else return p->Son[side]->Size;
		}
		
		/*Splay 基础操作完成，后面都是 BT 的共有操作*/
	//public:	
		Splay_Tree(){root = NULL;}
		~Splay_Tree(){if(root != NULL){root->Clear_Son();delete root;}}
		
		inline node* Root(){return root;}
		
		inline int size(){return root == NULL ? 0 : root->Size;}
		
		inline node* choose_son(const node* p,const int val)
		{
			if(p->Value > val) return p->Son[0];
			else return p->Son[1];
		}
		
		inline void find(const int val)
		{
			if(root == NULL) return ;
			
			node* cur = root;
			
			while(choose_son(cur,val) != NULL && val != cur->Value) cur = choose_son(cur,val);
			
			Splay(cur);
		}
		
		inline node* Get_Pre(const int val)
		{
			find(val);
			
			if(root->Value < val) return root;//因为如果他返回的不是 val 那么他返回的就一定是一个最接近 val 的节点（可以大于可以小于）。 
			
			node *cur = root->Son[0];
			
			if(cur == NULL) return root;
			
			while(cur->Son[1] != NULL) cur = cur->Son[1];
			
			return cur;
		}
		
		inline node* Get_Suf(const int val)
		{
			find(val);
			
			if(root->Value > val) return root;
			
			node *cur = root->Son[1];
			
			if(cur == NULL) return root;
			
			while(cur->Son[0] != NULL) cur = cur->Son[0];
			
			return cur;
		}
		
		inline void Insert(const int val)
		{
			if(root == NULL) root = Create_node(val);
			
			else
			{
				node *cur = root;
				
				while(choose_son(cur,val) != NULL && cur->Value != val) cur = choose_son(cur,val);
				
				if(cur->Value == val)
				{
					++cur->Repetition;
					
					Splay(cur);
				}
				
				else
				{
					node* ct = Create_node(val);
					
					link(ct,cur,(cur->Value) < val);
					
					Splay(ct);
				}
			}
		}
		
		inline void delete_node(const int val)
		{
			node *Pre = Get_Pre(val),*Suf = Get_Suf(val);
			
			if(Pre->Value == val && Suf->Value == val) Delete(Pre);
			
			else if(Pre->Value == val){Splay(Suf);Delete(Pre);}
			
			else if(Suf->Value == val){Splay(Pre);Delete(Suf);}
			 
			else 
			{
				Splay(Pre);
				
				Splay(Suf,Pre);
				
				Delete(Suf->Son[0]);
			}
		}
		
		inline int Get_Rank(const int num)//查询num的排名
		{
    		find(num);
    		
    		if(root->Value < num && root->Son[1] != NULL) Splay(root->Son[1]);
    			
    		int dx = Get_Child_Cnt(root,1),Sz = root->Size,rp = root->Repetition;
    			
    		return Sz - dx - rp + 1;
		}
	
		inline int Get_Num(int k)//查找第 K 大的数 
		{
			node *cur = root;
		
			while(1)
			{
				if(k <= Get_Child_Cnt(cur,0)) cur = cur->Son[0];//在左子树里 
			
				else if(k > Get_Child_Cnt(cur,0) + cur->Repetition) //k比左子树+自己的重复次数还大，说明在右子树里
				{
					k -= Get_Child_Cnt(cur,0) + cur->Repetition;
					
            		cur = cur->Son[1];
				}
				else return cur->Value;
			}
		}
		
		void ZXBL(node* p)
		{
			if(p->Son[0] != NULL) ZXBL(p->Son[0]);
			printf("%d ",p->Value);
			if(p->Son[1] != NULL) ZXBL(p->Son[1]);
		}
} T;



int main()
{
	//freopen("1.in","r",stdin); 
	//freopen("2.out","w",stdout);
	
	n = Read();m = Read();T.Insert(2147483647);
	
	for(register int i = 1; i <= n; ++i) T.Insert(Read());
	
	/*register*/ int pos,x,last = 0,ans = 0;
	
	while(m--){
		pos = Read();x = Read();//x ^= last;
		
		if(m == 999841)
		{
			puts("fuck");
			
			T.ZXBL(T.root);
			
			return 0;
		}
		
		switch(pos)
		{
			case 1:
				   //T.Insert(x);
				   break;
			case 2:
				   //T.delete_node(x);
				   break;
			case 3:
				   last = T.Get_Rank(x);
				   break;
			case 4:
				   last = T.Get_Num(x);
				   break;
			case 5:
				   last = T.Get_Pre(x)->Value;
				   break;
			case 6:
				   last = T.Get_Suf(x)->Value;
				   break;
		}
		printf("%d\n",last);
		//if(pos > 2)ans ^= last;
	}
	
	printf("%d",ans);
	
	return 0;
}
