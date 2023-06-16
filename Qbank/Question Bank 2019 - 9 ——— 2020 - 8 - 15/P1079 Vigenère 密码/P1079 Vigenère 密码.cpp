# include <cstdio>
# include <algorithm>
# define reg register
//using namespace std;
const char Rule[42][42]={
{""},
{"-abcdefghijklmnopqrstuvwxyz"},
{"-zabcdefghijklmnopqrstuvwxy"},
{"-yzabcdefghijklmnopqrstuvwx"},
{"-xyzabcdefghijklmnopqrstuvw"},
{"-wxyzabcdefghijklmnopqrstuv"},
{"-vwxyzabcdefghijklmnopqrstu"},
{"-uvwxyzabcdefghijklmnopqrst"},
{"-tuvwxyzabcdefghijklmnopqrs"},
{"-stuvwxyzabcdefghijklmnopqr"},
{"-rstuvwxyzabcdefghijklmnopq"},
{"-qrstuvwxyzabcdefghijklmnop"},
{"-pqrstuvwxyzabcdefghijklmno"},
{"-opqrstuvwxyzabcdefghijklmn"},
{"-nopqrstuvwxyzabcdefghijklm"},
{"-mnopqrstuvwxyzabcdefghijkl"},
{"-lmnopqrstuvwxyzabcdefghijk"},
{"-klmnopqrstuvwxyzabcdefghij"},
{"-jklmnopqrstuvwxyzabcdefghi"},
{"-ijklmnopqrstuvwxyzabcdefgh"},
{"-hijklmnopqrstuvwxyzabcdefg"},
{"-ghijklmnopqrstuvwxyzabcdef"},
{"-fghijklmnopqrstuvwxyzabcde"},
{"-efghijklmnopqrstuvwxyzabcd"},
{"-defghijklmnopqrstuvwxyzabc"},
{"-cdefghijklmnopqrstuvwxyzab"},
{"-bcdefghijklmnopqrstuvwxyza"},
};

char ch[1005];
int k[105],me[1005],lenk,lenm;
bool upda[1005];

int main()
{
	scanf("%s",ch);
	while(ch[lenk]){
		if(ch[lenk] < 96) k[lenk] = ch[lenk] - 64;
		else k[lenk] = ch[lenk] - 96;
		++lenk;
	}
	scanf("%s",ch);
	while(ch[lenm]){
		if(ch[lenm] < 96) {me[lenm] = ch[lenm] - 64;upda[lenm] = true;}
		else me[lenm] = ch[lenm] - 96;
		++lenm;
	}
	for(reg int i = 0; i < lenm;++i){
		if(upda[i]) printf("%c",Rule[k[i % lenk]][me[i]] - 32);
		else  printf("%c",Rule[k[i % lenk]][me[i]]);
	}
	return 0;
}
