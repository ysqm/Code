# include <iostream>
# include <cstdio>
# include <cstring>
# include <cstdlib>
# include <vector>
using namespace std;
int re(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){s=(s<<1)+(s<<3)+ch-'0';ch=getchar();}
	return s*f;
}
# define LL long long
# define mmt(a,b) memset(a,b,sizeof(a))
const int N=5e5+77;
vector <LL> mk; int n,tt; int a[N];
int main(){//                      
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	n=re();tt=re(); LL x,y,z; mk.push_back(-1); 
	for(int i=1;i<=n;++i) x=re(),mk.push_back(x);
	y=0;
	/*while(mk[1]>mk[2]){
		x=mk[2]; 
		mk.erase(mk.begin()+2); mk[1]+=x;
		++y; if(y==n-1) break;
	}*/
	//if(y!=n-1){
	//n=n-y;
	while(mk[n-1]>mk[n]){
		x=mk[n]; mk.erase(mk.begin()+n); mk[n-1]+=x;
		n--; if(n==1) break;
	}	
	//}//cout<<"jfiejfei";
	for(int i=2;i<=n-1;++i){
		if(mk[i-1]>mk[i]){
			if(mk[i-1]+mk[i]<=mk[i+1]){
				x=mk[i];
				mk.erase(mk.begin()+i); mk[i-1]+=x; n--; i--;
			} 
			else{
				x=mk[i+1];
				mk.erase(mk.begin()+i+1); mk[i]+=x; n--;i--; 
			}
		}
	}
	z=0;
	for(int i=1;i<=n;++i) z+=mk[i]*mk[i];
	printf("%lld",z);
	/*cout<<endl;
	for(int i=1;i<=n;++i) cout<<mk[i]<<' ';*/
	return 0;
}
