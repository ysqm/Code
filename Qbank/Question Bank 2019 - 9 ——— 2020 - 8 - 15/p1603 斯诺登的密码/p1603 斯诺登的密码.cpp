# include <iostream>
# include <cstring>
# include <string>
# include <algorithm>
using namespace std;
string num[22]={"a",
"one","two","three","four","five","six","seven",
"eight","nine","ten","eleven","twelve","thirteen",
"fourteen","fifteen","sixteen",
"seventeen","eighteen","nineteen","twenty"},
a[22]={"a","a","second","third"},
b[22]={"a","another","both"},
c[22]={"a","first"},
cha;
bool flag;
int ans[7],k=0;long long out=0;//测试点4用int会炸，查了半个小时，血一样的教训 
int main(){
	cin.sync_with_stdio(false);
	for(int i=0;i<6;i++){
		cin>>cha;
		for(int j=1;j<22;j++){
			if(num[j]==cha||cha==a[j]||cha==b[j]||cha==c[j])
				ans[k++]=(j*j)%100;
		}
	}
	sort(ans,ans+k);
	for(int i=0;i<k;i++){
        out+=ans[i];
        out*=100;
    }
    cout<<out/100;
		return 0;
} 
