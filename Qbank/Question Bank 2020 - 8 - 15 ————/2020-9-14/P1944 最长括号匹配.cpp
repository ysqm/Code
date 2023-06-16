# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>

const int N = 1000000;

bool vis[N+5];
char s[N+5]; 
int stk[N+5][2],top,n;

void Input()
{
    //freopen("ysqm.in","r",stdin);
    scanf("%s",s+1);
    for(n = 1; s[n] ; ++n);
    fclose(stdin);
}

void Solve()
{
    Input();
    for(int i = 1; i <= n ; ++i)
        if((stk[top][0] == '[' && s[i] == ']') || (stk[top][0] == '(' && s[i] == ')')) vis[i] = vis[stk[top--][1]] = 1;
        else {stk[++top][0] = s[i];stk[top][1] = i;}
    int cnt = 0,ans = 0,l = 1,ansl,ansr;
    for(int i = 1; i <= n ; ++i)
        if(!vis[i]){cnt = 0;l = i+1;}
        else
        {
            ++cnt;
            if(ans < cnt)
			{
				ans = cnt;
				ansl = l;
				ansr = i;
			}
        }
    for(int i = ansl; i <= ansr ; ++i) printf("%c",s[i]);
}

int main(){Solve();return 0;}
