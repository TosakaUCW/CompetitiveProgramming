#include <memory.h>
#include <stdio.h>
#include <algorithm>
#include <queue>

const int N = 1e6 + 5;
const int M = 2e3 + 5;

int n, m;
int a[N];
int ans_L, ans_R;
int vis[N], cnt;

bool judge(int len)
{
    cnt = 0;
    memset(vis, 0, sizeof vis);
    for (int i = 1; i <= len; i++)
        cnt += (vis[a[i]] == 0), vis[a[i]]++;
    if (cnt == m)
    {
        ans_L = 1, ans_R = len;
        return true;
    }
    for (int i = len + 1; i <= n; i++)
    {
        int L = i - len + 1;
        int R = i;
        if (vis[a[L - 1]] == 1)
            cnt--;
        vis[a[L - 1]]--;
        if (vis[a[R]] == 0)
            cnt++;
        vis[a[R]]++;
        if (cnt == m)
        {
            ans_L = L, ans_R = R;
            return true;
        }
    }
    return false;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    int L = 1, R = n;
    while (L <= R)
    {
        int mid = (L + R) / 2;
        if (judge(mid))
            R = mid - 1;
        else
            L = mid + 1;
    }
    printf("%d %d", ans_L, ans_R);
    return 0;
}