# include <iostream>
# include <string>
# define register
# define N 1000

using namespace std;

struct Stack
{
	int S[1005],top;
	
	Stack(){top=0;}
	
	inline bool Empty(){return top == 0;}
	inline void Pop(){--top;}
	inline void Push(const int Val){S[++top] = Val;}
	inline int Top(){return top == 0 ? -1 : S[top];} 
} s1,s2;

string op;

int n,a[1005];

int main()
{
	std::ios::sync_with_stdio(false);
	
	cin>>n;s1.top = s2.top = 0;
	
	for(register int i = 1; i <= n ; ++i) cin>>a[i];
	
	register int cur = 1,l = 1;
	
	while(cur <= n)
	{
		if(s1.Top() == cur)
		{
			s1.Pop();
			op += "b ";
			++cur;
		}
		else if(s2.Top() == cur)
		{
			s2.Pop();
			op += "d ";
			++cur;
		}
		else if(a[l] == cur)
		{
			op += "a b ";
			++cur;++l;
		}
		else if(s1.Top() == a[l]+1)
		{
			s1.Push(a[l]);
			op += "a ";
			++l;
		}
		else if(s2.Top() == a[l]+1)
		{
			s2.Push(a[l]);
			op += "c ";
			++l;
		}
		else if(s1.Empty() || s1.Top() > a[l])
		{
			s1.Push(a[l]);
			op += "a ";
			++l;
		}
		else if(s2.Empty() || s2.Top() > a[l])
		{
			s2.Push(a[l]);
			op += "c ";
			++l;
		}
		else
		{
			cout<<"0\n";
			return 0;
		}
	}
	
	cout<<op;
	
	return 0;
}
