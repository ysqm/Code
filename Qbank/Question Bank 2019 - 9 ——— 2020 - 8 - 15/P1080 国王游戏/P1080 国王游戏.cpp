# include <cstdio>
# include <algorithm>
# include <cmath>
# include <cstring>
# define reg register
//using namespace std;

inline void in(int& x)
{
	x = 0; char ch = getchar();int f = 1;
	
	while(ch < '0' || ch > '9')/*{if(ch == '-') f = -1;*/ch = getchar();//}
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	x *= f;
}

struct Minister
{
	int Right,Left,rank;
	
	Minister(){    }
	
	Minister(int a,int b):Left(a),Right(b),rank(a*b){    }
	
	bool operator < (const Minister B) const 
	{
		return rank < B.rank;
	}
} Mis[1042];

struct INT
{
	int data[10042],len;
	
	INT(){memset(data,0,sizeof(data));len = 1;}
	
	inline void clear(){memset(data,0,sizeof(data));len = 1;}
	
	bool operator < (const INT& B) const 
	{
		if(len > B.len) return false;
			if(len < B.len) return true;
			else for(reg int i = B.len; i > 0 ; --i)
					if(data[i] < B.data[i]) return true;
					 else if(data[i] > B.data[i]) return false;
		return false;
	}
	
	void operator = (int B)
	{
		len = 1;
		memset(data,0,sizeof(data));
		while(B){
			data[len++] = B % 10;
			B /= 10;
		}
		while(data[len] == 0 && len > 1) --len;
	}
	
	INT operator / (const int& B) const 
	{
		INT C;C.clear();
		C.len = len;
		int rest = 0;
		for(reg int i = len; i >= 1; --i){
			rest = rest * 10 + data[i];
			C.data[i] = rest / B;
			rest %= B;
		}
		while(data[C.len] == 0 && C.len > 1) --C.len;
		return C;
	}
	
	INT operator * (const int& B) const 
	{
		INT D;D.clear();D.len = len;
		for(reg int i = 1; i <= len; ++i)
			D.data[i] = data[i] * B;
		for(reg int i = 1; i <= D.len; ++i)
			if(D.data[i] >= 10){
				D.data[i + 1] += D.data[i] / 10;
				D.data[i] %= 10;
				D.len = D.len > i + 1 ? D.len : i + 1;
			}
		while(D.data[D.len + 1]) ++D.len;
		while(D.data[D.len] == 0 && D.len > 1) --D.len;
		return D;
	}
	
	void print()
	{
		//printf("%d",data[len]);
		while(data[len] == 0 && len > 1) --len;
		for(reg int i = len; i ; --i)
			printf("%01d",data[i]);
		printf("\n");
	}
} ans,sum,abe;

int n,a,b;

int main()
{
	freopen("P1080_8.in","r",stdin);
	in(n);in(a);in(b);
	for(reg int i = 1,x,y; i <= n; ++i){
		in(x);in(y);
		Mis[i] = Minister(x,y);
	}
	
	std::sort(Mis + 1,Mis + n + 1);
	
	sum = a;
	
	for(reg int  i = 1; i <= n; ++i){
		abe = sum / Mis[i].Right;
		if(ans < abe) ans = abe;
		sum = sum * Mis[i].Left;
	}
	
	ans.print();
	return 0;
}
