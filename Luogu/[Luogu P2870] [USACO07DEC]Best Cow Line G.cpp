#include <stdio.h>
#include <algorithm>
#include <memory.h>

#define ull unsigned long long

const int N = 5e5 + 5;
const ull base = 131;

int n;
char str[N], ans[N];
ull pow[N], sum[2][N];

int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while ('0' > ch or ch > '9')
        f = ch == '-' ? -1 : 1, ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + ch - 48, ch = getchar();
    return x * f;
}

bool judge(int l, int r, int len)
{
    ull x = sum[0][l + len - 1] - sum[0][l - 1] * pow[len];
    ull y = sum[1][r - len + 1] - sum[1][r + 1] * pow[len];
    return x == y;
}

int main()
{
    // freopen("P2870_2.in", "r", stdin);
    // freopen("P2870_2.ans", "w", stdout);
    n = read();
    for (int i = 1; i <= n; i++)
        scanf("%s", &str[i]);
    // for (int i = 1; i <= n; i++)
    // printf("%c", str[i]);
    pow[0] = 1;
    for (int i = 1; i <= n; i++)
        pow[i] = pow[i - 1] * base;
    for (int i = 1; i <= n; i++)
        sum[0][i] = sum[0][i - 1] * base + str[i];
    for (int i = n; i >= 1; i--)
        sum[1][i] = sum[1][i + 1] * base + str[i];
    int L = 1, R = n, p = 0;
    for (; L <= R and p <= n;)
    {
        // printf("[ans[%d]:%c L:%d R:%d]\n", p, ans[p], L, R);
        if (str[L] < str[R])
            ans[++p] = str[L++];
        else if (str[L] > str[R])
            ans[++p] = str[R--];
        else
        {
            int res = 1;
            for (int l = 1, r = (R - L + 1), mid; l <= r;)
                if (judge(L, R, (mid = (l + r) >> 1)))
                    res = mid, l = mid + 1;
                else
                    r = mid - 1;
            if (str[L + res] < str[R - res])
                ans[++p] = str[L++];
            else
                ans[++p] = str[R--];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%c", ans[i]);
        if (i % 80 == 0)
            puts("");
    }
    return 0;
}