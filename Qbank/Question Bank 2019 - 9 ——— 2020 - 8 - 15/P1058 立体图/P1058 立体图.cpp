# include <cstdio>
# include <algorithm>
# define reg register
//using namespace std;
const char board[6][8]=
{
    "..+---+",
    "./   /|",
    "+---+ |",
    "|   | +",
    "|   |/.",
    "+---+.."
};

inline int Max(const int a,const int b){return a > b ? a : b;}

inline void in(int& x)
{
	x = 0; char ch = getchar();int f = 1;
	
	while(ch < '0' || ch > '9'){if(ch == '-') f = -1;ch = getchar();}
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	x *= f;
}

struct Picture
{
	int Wide,Long;
	char pic[505][505];
	
	Picture(){
		Wide = 0;Long = 0;
		for(reg int i = 1; i <= 505; ++i)
			for(reg int j = 1; j <= 505; ++j)
				pic[i][j] = '.';
	}
} ans;

int a[55][55],m,n,x,y;

int main()
{
	in(n);in(m);
	ans.Wide = (m << 2) + (n << 1) + 1;
	
	for(reg int i = 1;i <= n ; ++i)
		for(reg int j = 1; j <= m ; ++j){
			in(a[i][j]);
			ans.Long = Max(ans.Long,a[i][j] * 3 + (n - i + 1 << 1) + 1);
		}
		
	for(reg int i = 1;i <= n ; ++i)
		for(reg int j = 1; j <= m ; ++j){
			x = ans.Long - (n - i << 1);
            y = (n - i << 1) + (j - 1 << 2) + 1;
            while(a[i][j]--){
            	for(reg int k = 0 ; k < 6 ; ++k)
            		for(reg int  l = 0 ; l < 7 ; ++l)
            			if(board[5 - k][l] != '.') ans.pic[x - k][y + l] = board[5 - k][l];
            	x -= 3;
            }
		}
	
	for(reg int i = 1;i <= ans.Long ; ++i){
		for(reg int j = 1; j <= ans.Wide ; ++j) printf("%c",ans.pic[i][j]);
		
		printf("\n");
	}
		
	return 0;
}
