# include <cstdio>

typedef long long LL;

inline LL Read()
{
	LL x = 0,f = 1;register char ch = getchar();
	
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1;ch = getchar();}
	
	while(ch >= '0' && ch <= '9') {x = x * 10 + (ch ^ 48);ch = getchar();}
	
	return x * f;
}

LL a,b,c,DP[42][42][42];

LL W(const LL a,const LL b,const LL c)
{
	if(a <= 0 || b <= 0 || c <= 0) return 1;
	
	else if(a > 20 || b > 20 || c > 20) return W(20,20,20);
	
	else if(DP[a][b][c]) return DP[a][b][c];
	
	else if(a < b && b < c) return DP[a][b][c] = W(a,b,c-1) + W(a,b-1,c-1) - W(a,b-1,c);
	
	else return DP[a][b][c] = W(a-1,b,c) + W(a-1,b-1,c) + W(a-1,b,c-1) - W(a-1,b-1,c-1);
}



int main()
{
	a = Read();b = Read();c = Read();
	
	while(a != -1 || b != -1 || c != -1)
	{
		printf("w(%d, %d, %d) = %d\n",a,b,c,W(a,b,c));
		
		a = Read();b = Read();c = Read();
	}
	
	return 0;
}
