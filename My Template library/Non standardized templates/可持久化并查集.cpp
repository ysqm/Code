/*
	Name :并查集模板 
	Code by:云岁月书
	Update_Date: 2020/8/5
*/
struct Union_Find//普通并查集 
{
	int *F,*Size;
	
	Union_Find(){}
	
	Union_Find(const int n){F = new int [n + 1];Size = new int [n + 1];for(reg int i = 1; i <= n ; ++i) F[i] = i,Size[i] = 1;}
	
	inline int Father(const int x){return F[x];}
	
	inline int Find(int x)
	{
		int cur = x;
		
		while(F[cur] ^ cur) cur = F[cur];
		
		F[x] = cur;
		
		while(x ^ F[x]) F[x = F[x]] = cur;
		
		return cur;
	}
	
	inline int Union(const int x,const int y)
	{
		if(Size[x] < Size[y]) Size[y] += Size[x],F[x] = y;
		else Size[x] += Size[y],F[y] = x; 
	}
} UF;
