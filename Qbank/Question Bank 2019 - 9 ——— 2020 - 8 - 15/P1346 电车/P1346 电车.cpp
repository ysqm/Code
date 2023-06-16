# include <cstdio>
# include <cstring>
# define reg register
using namespace std;

inline int Read()
{
	int x = 0;char c = getchar();
	
	while(c < '0' || c > '9') c = getchar();
	
	while(c >= '0' && c <= '9'){x = (x << 3) + (x << 1) +c - 48;c = getchar();}
	
	return x;
}

int n,S,T,G[142][142];

int main()
{
	//freopen("P3386_1.in","r",stdin);
	
	n = Read();S = Read();T = Read(); 
	
	std::memset(G,0x3f,sizeof(G));
	
	for(reg int i = 1,u,v ; i <= n ; ++i ){
		
		u = Read();
		
		if(u)
		{
			--u;G[i][Read()] = 0;
		
			while(u--) G[i][Read()] = 1;
		}
	}
		
	for(reg int k = 1; k <= n ; ++k)
		for(reg int i = 1; i <= n ; ++i)
			for(reg int j = 1; j <= n ; ++j)
				if(G[i][k] + G[k][j] < G[i][j]) G[i][j] = G[i][k] + G[k][j];
	
	printf("%d",G[S][T] != 0x3f3f3f3f ? G[S][T] : -1);
	
	return 0;	
}
