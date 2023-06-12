#include<iostream>
#include<cstdio>
using namespace std;
int a[100];
int m;
long long n;
void work(int step,long long p,int k)
{
	if(step==0) return;
	if(p<=(1<<(step-1))) 
	{
		if(k%2==0)
		{
			a[step]=0;
			work(step-1,p,k);
		}
		else
		{
			a[step]=1;
			work(step-1,p,k+1);
		}
	}
	else
	{
		if(k%2==0) 
		{
			a[step]=1;
			work(step-1,p-(1<<(step-1)),k+1);
		}
		else
		{
			a[step]=0;
			work(step-1,p-(1<<(step-1)),k);
		}
	}
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	cin>>m>>n;
	work(m,n+1,0);
	for(int i=m;i>=1;i--)
	cout<<a[i];
	return 0;
}
