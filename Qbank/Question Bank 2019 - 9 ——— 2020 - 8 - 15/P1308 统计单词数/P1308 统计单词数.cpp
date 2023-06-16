# include <cstdio>
# include <iostream>
# define reg register

char pass[1000042],ke[42],ch;
int ans,First = -1,kk,len;

inline char toit(char& c)
{
	if(c <= 'Z' && c >= 'A') c += 32;
	return ch;
}

int main()
{
	std::ios::sync_with_stdio(false);
	/*toit(ch = getchar());
	
	while(ch <= 'z' && ch >= 'a')
	{
		ke[kk++] = toit(ch);
		ch = getchar();
	}*/
	
	std::cin.getline(ke,sizeof(ke));
	
	//std::cin.getline(pass,sizeof(pass));
	std::cin.getline(pass,sizeof(pass));
	
	while(ke[kk] != '\0') {toit(ke[kk]);++kk;}
	
	while(pass[len] != '\0') {toit(pass[len]);++len;}
	
	for(reg int i = 0; i < len ; ++i){
		reg int j = 0;
		
		for(; j < kk; ++j) if(pass[j + i] != ke[j] || (i > 0 && pass[i - 1] != ' ')) break;
		
		if(j == kk && (pass[j + i] == ' ' || j + i == len)){
			ans++;
			if(ans == 1) First = i;
		}
		
	}
	
	if(ans) printf("%d %d",ans,First);
	else puts("-1");
	return 0;
} 
