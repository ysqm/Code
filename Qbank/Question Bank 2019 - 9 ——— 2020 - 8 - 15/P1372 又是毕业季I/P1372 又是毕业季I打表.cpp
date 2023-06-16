#include<bits\stdc++.h>
using namespace std;

int a[1001], ans = 1;
bool used[1001];
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

int work(int num) {
    int ans = a[1];
    for(int i = 2; i <= num; i++) ans = gcd(ans, a[i]);
    return ans;
}
void dfs(int t, int n, int k) {
    if(t == k + 1) {
        ans = max(ans, work(k));
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(!used[i]) {
            a[t] = i;
            used[i] = 1;
            dfs(t + 1, n, k);
            a[t] = used[i] = 0;
        }
    }
}
int main() {
	freopen("1.txt","w",stdout);
	int max1;scanf("%d",&max1);
    for(int n = 1; n <= max1; n++) {
        printf("------n = %d------\n", n);
        for(int k = 1; k <= n; k++) {
            printf("k = %d: ", k);
            ans = 1;
            dfs(1, n, k);
            printf("%d \n", ans);
        }
        puts("");
    }
}
