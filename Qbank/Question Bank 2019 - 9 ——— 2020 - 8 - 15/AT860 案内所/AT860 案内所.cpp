# include <cstdio>
# include <iostream>
using namespace std;
int x[42],q,n,m,y[42];char ch;//,qe[42];

int main()
{
	//ios::sync_with_stdio(false);
	//in(n);in(m);in(q);
	cin>>n>>m>>q;
	//scanf("%d%d%d",&n,&m,&q);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j){
			cin>>ch;
			//scanf("%c",&ch);
			if(ch != '*') {x[ch - 'A'] = i;y[ch - 'A'] = j;}
		}
		
	//for(int i = 1; i <= q; ++i) cin>>qe[i];//scanf("%c",&qe[i]);
	
	
	for(int i = 1; i <= q; ++i){
		cin>>ch;
		if(x[ch - 'A']) cout<<x[ch - 'A']<<" "<<y[ch - 'A']<<endl;//printf("%d %d\n",x[qe[i] - 'A'],y[qe[i] - 'A']);
		else cout<<"NA"<<endl;//printf("NA\n");
	}
		
		
	return 0;
}
