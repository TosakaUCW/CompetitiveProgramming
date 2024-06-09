#include <stdio.h>
#include <algorithm>

const int N = 5e2 + 5;

int n, k, ans;
int a[N], g[N];

bool judge(int x)
{
    int sum = 0, tot = k;
    for (int i = n; i >= 1; i--)
    {
        sum += a[i];
        if (sum > x)
            sum = a[i], tot--;
    }
    return tot >= 1 and sum <= x;
}

void print()
{
    int sum = 0, tot = k;
    for (int i = n; i >= 1; i--)
    {
        sum += a[i];
        if (sum > ans)
            sum = a[i], g[--tot] = i;
    }
    g[k] = n;
    for (int i = 1; i <= k; i++)
        printf("%d %d\n", g[i - 1] + 1, g[i]);
}

int main()
{
    int L = 0, R;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), R += a[i];
    while (L <= R)
    {
        int mid = (L + R) / 2;
        if (judge(mid))
            ans = mid, R = mid - 1;
        else
            L = mid + 1;
    }
    print();
    return 0;
}