# include <iostream>
# include <cstdio>
using namespace std;
char an[30];bool flag=true;int i=0,m=0;
typedef struct{int player_A,player_B,A[3000],B[3000];} ping;
ping ans11,ans21;
int main(){
	cin.sync_with_stdio(false);
	//freopen("1.txt","w",stdout);
	while(flag){
		cin.getline(an,sizeof(an));
		int /*k=sizeof(an)/4,*/now=0;
		for(int j=0;j<25;j++){
			if(an[j]=='E'){flag=false;break;}
			if(an[j]=='W') {
				ans11.player_A++;ans21.player_A++;
			}
			else if(an[j]=='L') {
				ans11.player_B++;ans21.player_B++;
			}
			if(ans11.player_A>10&&ans11.player_A-ans11.player_B>1){
				ans11.A[i]=ans11.player_A;ans11.player_A=0;
				ans11.B[i++]=ans11.player_B;ans11.player_B=0;
			}
			else if(ans11.player_B>10&&ans11.player_B-ans11.player_A>1){
				ans11.A[i]=ans11.player_A;ans11.player_A=0;
				ans11.B[i++]=ans11.player_B;ans11.player_B=0;
			}
			if(ans21.player_A>20&&ans21.player_A-ans21.player_B>1){
				ans21.A[m]=ans21.player_A;ans21.player_A=0;
				ans21.B[m++]=ans21.player_B;ans21.player_B=0;
			}
			else if(ans21.player_B>20&&ans21.player_B-ans21.player_A>1){
				ans21.A[m]=ans21.player_A;ans21.player_A=0;
				ans21.B[m++]=ans21.player_B;ans21.player_B=0;
			}
		}
	}
	for(int j=0;j<i;j++)
		cout<<ans11.A[j]<<":"<<ans11.B[j]<<endl;
	cout<<ans11.player_A<<":"<<ans11.player_B<<endl;
	cout<<endl;
	for(int j=0;j<m;j++)
		cout<<ans21.A[j]<<":"<<ans21.B[j]<<endl;
	cout<<ans21.player_A<<":"<<ans21.player_B<<endl;
	return 0;
} 
