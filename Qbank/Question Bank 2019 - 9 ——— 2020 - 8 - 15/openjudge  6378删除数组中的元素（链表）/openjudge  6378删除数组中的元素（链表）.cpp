# include <cstdio>
struct node{
	int num;
	node *next_node=NULL,*pre_node=NULL; 
	void del(node *a){
		node *b;
		b=a->next_node;b->pre_node=a->pre_node;
		b=a->pre_node;b->next_node=a->next_node;
		delete a;
	}
} *head=new node,*tail=new node,*nowt=new node;
int main(){
	int n,k;scanf("%d",&n);
	head->get(head);
	head->next_node=tail;
	nowt=head;
	for(int i=0;i<n;i++){
		
	}
	scanf("%d",&k);
	while(nowt->next_node!=NULL){
		if(head->num=k) {
			nowt=head->next_node;
			delete head;
			head=nowt;
		}
		else if(nowt->num=k) {
			node *ne=nowt;
			nowt=ne->next_node;
			ne->del(ne);
		}
		else nowt=nowt->next_node;
	} nowt=head;
	while(nowt->next_node!=NULL){
		printf("%d ",nowt->num);
		nowt=nowt->next_node;
	}
	return 0;
} 
