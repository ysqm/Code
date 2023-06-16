# include <cstdio>
# include <algorithm>
# include <bitset>
# define reg register
using namespace std;

inline void in(int& x)
{
	x = 0;char ch = getchar();int f = 1;
	
	while(ch < '0' || ch > '9'){if(ch == '-') f = -1;ch = getchar();}
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	x *= f;
}

struct LOW_PRICE
{
	int id[6],num[6],pric,Number;
} w[100];

inline int Min(const int& a,const int b){return a < b ? a : b;}

int s,b,tot,f[6][6][6][6][6],need[6],price[6];
int mapping[1001];

int main()
{
	in(s);
	for(reg int i = 1 ; i <= s; ++i){
		in(w[i].Number);
		for(reg int j = 1,c,k; j <= w[i].Number; ++j){
			in(c);in(k);
			if(mapping[c]) w[i].id[j] = mapping[c];
			else w[i].id[j] = mapping[c] = ++tot;
			w[i].num[w[i].id[j]] = k;
		}
		in(w[i].pric);
	}
	in(b);
	for(reg int i = 1,c,k; i <= b; ++i){
		in(c);
		if(mapping[c]) in(need[mapping[c]]);
		else in(need[mapping[c] = ++tot]);
		in(price[mapping[c]]);
	}
	for(reg int i = 0; i <= need[1]; ++i)
		for(reg int j = 0; j <= need[2]; ++j)
			for(reg int k = 0; k <= need[3]; ++k)
				for(reg int l = 0; l <= need[4]; ++l)
					for(reg int r = 0; r <= need[5]; ++r)
						f[i][j][k][l][r] = i * price[1] + j * price[2] + k * price[3] + l * price[4] + r * price[5];
	
	for(reg int wi = 1; wi <= s   ; ++wi)
		for(reg int i = w[wi].num[1]; i <= need[1]; ++i)
			for(reg int j = w[wi].num[2]; j <= need[2]; ++j)
				for(reg int k = w[wi].num[3]; k <= need[3]; ++k)
					for(reg int l = w[wi].num[4]; l <= need[4]; ++l)
						for(reg int r = w[wi].num[5]; r <= need[5]; ++r)
							f[i][j][k][l][r] = min(f[i][j][k][l][r],f[i - w[wi].num[1]][j - w[wi].num[2]][k - w[wi].num[3]][l - w[wi].num[4]][r - w[wi].num[5]] + w[wi].pric);
	
	printf("%d", f[need[1]][need[2]][need[3]][need[4]][need[5]]);
	return 0;
}
