# include <vector>
# include <ctime>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define N 100000
# define register /**/

inline int Read()
{
    register int x = 0;char ch = getchar();

    while(ch < '0' || ch > '9')ch = getchar();

    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = getchar();}

    return x;
}

char s[2];
int lastest[N+5],Times[N+5],actor[N+5],cnt,idf[N+5];
double score[N+5];

int main()
{
    int n;

    n = Read();

    while(n--)
    {
        scanf("%s",s);

        if(*s == 'R')
        {
            register int n,idx = 0,id = Read();n = Read();
            
            ++cnt;

            Times[id] = cnt;idf[cnt] = id;

            for(register int i = 1; i <= n ; ++i)
                if(lastest[actor[i] = Read()] && Times[lastest[actor[i]]] > Times[lastest[idx]]) idx = actor[i];

			score[id] = score[lastest[idx]];

            for(register int i = 1; i <= n ; ++i) lastest[actor[i]] = id;

            for(register int i = cnt-1; i >= 1 ; --i) 
                if(score[idf[i]] <= score[idf[i+1]]) (score[idf[i]] < score[idf[i+1]] || Times[idf[i]] > Times[idf[i+1]]) && (idf[i] ^= idf[i+1] ^= idf[i] ^= idf[i+1]);
                else break;
        }
        else if(*s == 'Q') printf("%d\n",idf[Read()]);
        else
        {
            register int id = Read();double x;
            scanf("%lf",&x);
            score[id] = (score[id]+x)/2.0;
            for(register int i = 1; i <= cnt; ++i)
            	if(idf[i] == id)
            	{
            		for(register int j = i; j <= cnt; ++j) idf[j] = idf[j+1];

                    idf[cnt] = id;

                    for(register int j = cnt-1; j >= 1 ; --j) 
                        if(score[idf[j]] <= score[idf[j+1]]) (score[idf[j]] < score[idf[j+1]] || Times[idf[j]] > Times[idf[j+1]]) && (idf[j] ^= idf[j+1] ^= idf[j] ^= idf[j+1]); 
                        else break;
            		break;
				}
        }
        
    }

    return 0;
}
