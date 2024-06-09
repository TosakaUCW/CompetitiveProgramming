#include <stdio.h>
#include <algorithm>
#include <memory.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57)
        f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57)
        x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 1e6 + 5;

int n, m, L, R, Lmid, Rmid;
int ans[2][N], a[N];

void print()
{
    for (int i = 1; i < n; i++)
        putchar(ans[0][i] ? 'R' : 'L');
    for (int i = n - 1; i >= 1; i--)
        putchar(ans[1][i] ? 'R' : 'L');
    printf("L\n");
}

bool go()
{
    for (int i = 1; i < n; i++)
    {
        if (Lmid - L >= 2)
        {
            if (a[L + 1] == a[Lmid - 1] and Lmid - L >= 3)
            {
                L++, Lmid--, ans[0][i] = 0, ans[1][i] = 0;
                continue;
            }
            if (a[L + 1] == a[Rmid + 1] and R - Rmid >= 2)
            {
                L++, Rmid++, ans[0][i] = 0, ans[1][i] = 1;
                continue;
            }
        }
        if (R - Rmid >= 2)
        {
            if (a[R - 1] == a[Rmid + 1] and R - Rmid >= 3)
            {
                R--, Rmid++, ans[0][i] = 1, ans[1][i] = 1;
                continue;
            }
            if (a[R - 1] == a[Lmid - 1] and Lmid - L >= 2)
            {
                R--, Lmid--, ans[0][i] = 1, ans[1][i] = 0;
                continue;
            }
        }
        return 0;
    }
    return 1;
}

void solve()
{
    n = read(), m = n * 2;
    for (int i = 1; i <= m; i++)
        a[i] = read();
    int p, q;
    for (int i = 2; i <= m; i++)
        if (a[i] == a[1])
        {
            p = i;
            break;
        }
    for (int i = m - 1; i >= 1; i--)
        if (a[i] == a[m])
        {
            q = i;
            break;
        }
    L = 1, R = m + 1, Lmid = Rmid = p;
    if (go())
        return putchar('L'), print(), void();
    L = 0, R = m, Lmid = Rmid = q;
    if (go())
        return putchar('R'), print(), void();
    puts("-1");
}

int main()
{
    for (int T = read(); T--; solve())
        ;
    return 0;
}
