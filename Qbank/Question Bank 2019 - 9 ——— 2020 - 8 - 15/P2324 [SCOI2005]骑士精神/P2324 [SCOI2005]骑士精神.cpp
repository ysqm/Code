# include <iostream>
# include <algorithm>
# include <cstdio>
# include <cstring>
#define reg register
using namespace std;

inline int Read()
{
	int x = 0;char c = getchar();
	
	while(c < '0' || c > '9') c = getchar();
	
	while(c >= '0' && c <= '9'){x = (x << 3) + (x << 1) +c - 48;c = getchar();}
	
	return x;
}

bool flag;
int n,m,t,Map[7][7],star_x,star_y;
const int dx[]={0,1,1,-1,-1,2,2,-2,-2};
const int dy[]={0,2,-2,2,-2,1,-1,1,-1};
const int goal[7][7]={
    {0,0,0,0,0,0},
    {0,1,1,1,1,1},
    {0,0,1,1,1,1},
    {0,0,0,9,1,1},
    {0,0,0,0,0,1},
    {0,0,0,0,0,0}
};

inline int check(){
    reg int cnt=0;
    for(reg int i=1;i<=5;i++)
        for(reg int j=1;j<=5;j++)
            if(Map[i][j] != goal[i][j])cnt++;
    return cnt;
}

inline void A_STAR(const int deep,const int x,const int y,const int Max_deep)
{
	if(deep == Max_deep){
		if(check() == 0) flag = 1;
		return ;
	}
	
	for(reg int i = 1; i <= 8 ; ++i){
		
		int xx = x + dx[i],yy = y + dy[i];
		
		if(xx < 1 || yy < 1 || xx > 5 || yy > 5) continue;
		
		Map[x][y] ^= Map[xx][yy] ^= Map[x][y] ^= Map[xx][yy];
		
		if(check() + deep <= Max_deep) A_STAR(deep + 1,xx,yy,Max_deep);
		
		Map[x][y] ^= Map[xx][yy] ^= Map[x][y] ^= Map[xx][yy];
	}
}

int main(){
    
	t = Read();
    
    while(t--){
    	
    	flag = 0;
		
		for(reg int i = 1 ; i <= 5 ; ++i)
			for(reg int j = 1 ; j <= 5 ; ++j){
				
				reg char ch = getchar();
				
				while(ch != '0' && ch != '1' && ch != '*') ch = getchar();
				
				if(ch == '*'){Map[i][j] = 9;star_x = i;star_y = j;}
				else Map[i][j] = ch - '0';
			}
			
		if(check() == 0){puts("0");continue;}
		
		for(reg int max_deep = 1 ; max_deep <= 15 ; ++max_deep){
			
            A_STAR(0,star_x,star_y,max_deep);
            
            if(flag){printf("%d\n",max_deep);break;}
        }
		
		if(!flag) puts("-1");
	}
    
    return 0;
}
