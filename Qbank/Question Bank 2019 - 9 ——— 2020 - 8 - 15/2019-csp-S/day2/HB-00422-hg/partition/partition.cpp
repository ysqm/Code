#include <cstdio>
#include <iostream>
#define int long long
using namespace std;

int nums[10000],sum[10000];

signed main()
{	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	int n,t;
	scanf("%lld%lld",&n,&t);
	if(t == 0)
	{	
		if(n <= 8)
		{	for(int i = 1;i <= n;i++)
			scanf("%lld",&nums[i]);
			int ans = 0;
			for(int i = 1;i <= n;i++)
			{	if(nums[i] <= nums[i + 1]) 
				{	ans += nums[i] * nums[i];
					continue;
				}
				else
				{	int j = i + 1,sum = nums[i];
					while(nums[j] < sum)
						sum += nums[j++];
					nums[j - 1] = sum;
					i = j - 1;
					ans += nums[i] * nums[i];
				}
			
			}
			printf("%lld",ans);
		}
		else if(n <= 1000)
		{	for(int i = 1;i <= n;i++)
			{	scanf("%lld",&nums[i]);
				sum[i] = sum[i - 1] + nums[i];
			}
			nums[n + 1] = 999999999999; 
			sum[n + 1] = sum[n] + nums[n + 1];
			int ans = 0;
			for(int i = 1;i < n;i++)
			{	if(nums[i] <= nums[i + 1]) 
					ans += nums[i] * nums[i];
				else
				{	int j = i + 1;
					while(!(sum[j] - sum[i] <= nums[j + 1] && sum[j] - sum[i] >= nums[i]) && j < n)	
						j++;
					if(sum[j] - sum[i] >= nums[i])	nums[j] = sum[j] - sum[i],ans += nums[i] * nums[i];
					else	nums[j] = sum[j] - sum[i - 1];
					ans += nums[j] * nums[j];
					i = j;
				}
			}
			printf("%lld",ans);
		}
		else
		{	int ans = 0;
			for(int i = 1;i <= n;i++)
			{	scanf("%lld",&nums[i]);
				ans = nums[i] * nums[i];
			}
			printf("%lld",ans);
		}
	}
	return 0;
}
