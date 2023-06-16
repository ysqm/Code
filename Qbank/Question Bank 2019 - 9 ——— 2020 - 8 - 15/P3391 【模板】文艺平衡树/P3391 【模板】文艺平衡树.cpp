# include <cstdio>
# define reg register
# define N 1000000
# define INF 100000089

struct Splay_tree_node{
    int father,Size,dupcnt,value,tag;
    int son[2];
} s[N + 42];

int base[N + 42],root,tot;

inline bool which_one(const int& x){return x == s[s[x].father].son[1];}

inline void update(const int& x){s[x].Size = s[x].dupcnt + s[s[x].son[0]].Size + s[s[x].son[1]].Size;}

inline void pushdown(const int& x)
{
    if(x && s[x].tag){
    	
        s[s[x].son[1]].tag ^= 1;
        s[s[x].son[0]].tag ^= 1;
        
        s[x].son[1] ^= s[x].son[0] ^= s[x].son[1] ^= s[x].son[0];
        
        s[x].tag = 0;
    }
}

inline void rotate(const int& x)
{
	int fa = s[x].father,gf = s[s[x].father].father;
	
	pushdown(x),pushdown(fa);
	
	bool which = which_one(x);
	
	s[fa].son[which] = s[x].son[which ^ 1];
	
	s[s[fa].son[which]].father = fa;
	
	s[fa].father = x;
	
    s[x].father = gf;
    
    s[x].son[which ^ 1] = fa;
    
    if(gf) s[gf].son[s[gf].son[1] == fa] = x;
    
    update(fa);
}

inline void Splay(const int& x,const int target = 0)
{
	while(s[x].father != target){
			
		if(s[s[x].father].father != target) rotate(which_one(x) == which_one(s[x].father) ? s[x].father : x);
			
		rotate(x); 
	}
		
	if(target == 0) root = x;
}

inline int build(const int l,const int r,const int fa)
{
    if(l > r) return 0;
    
    int mid = (l + r) >> 1,cur = ++tot;
        
    s[cur].father = fa;
        
    //s[cur].son[0] = s[cur].son[1] = 0;
        
    ++s[cur].dupcnt;++s[cur].Size;
        
    s[cur].value = base[mid];
        
    s[cur].son[0] = build(l,mid - 1,cur);
        
    s[cur].son[1] = build(mid + 1,r,cur);
        
    update(cur);
        
    return cur;
}

inline int find(int& x)
{
    register int cur = root;
    
    while(1){
    	
        pushdown(cur);
        
        if(x <= s[s[cur].son[0]].Size) cur = s[cur].son[0];
        
        else{
			x -= s[s[cur].son[0] ].Size + 1;
        	
			if(x == 0) return cur;
        	
			cur = s[cur].son[1];
        }
    }
}

inline void dfs(const int& x)
{
	pushdown(x);
	
	if(s[x].son[0]) dfs(s[x].son[0]);
	
	if(s[x].value != INF && s[x].value != -INF) printf("%d ",s[x].value);
	
	if(s[x].son[1]) dfs(s[x].son[1]);
}

inline void rever(int L,int R)
{
	int l = L - 1,r = R + 1;
	
	l = find(l);r = find(r);
	
	Splay(l);Splay(r,l);
	
    s[s[s[root].son[1]].son[0]].tag ^= 1;
}

int main()
{
    int n,m;
    
    scanf("%d%d",&n,&m);
    
    base[1] = -INF;base[n + 2] = INF;
    
    for(register int i = 1 ; i <= n ; ++i) base[i + 1] = i;
    
    root = build(1,n + 2,0);
    
    for(register int i = 1,x,y; i <= m ; ++i){
    	
    	//dfs(root);printf("\n");
    	
        scanf("%d%d",&x,&y);
        
        rever(x + 1,y + 1);
    }
    
    dfs(root);
    
    return 0;
}

