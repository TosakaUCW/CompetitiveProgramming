#include <stdio.h>
#include <algorithm>

#define int long long

const int N = 500 + 5;
const int P = 1e9 + 7;

int n, k;
int cnt[N], f[N][N], g[N][N], h[N][N];
char s[N];

bool judge(int L, int R) { return (s[L] == '(' or s[L] == '?') and (s[R] == ')' or s[R] == '?'); }

bool check(int L, int R) { return cnt[R] - cnt[L - 1] == R - L + 1 and R - L + 1 <= k; }

void add(int &x, int y) { x = ((x % P + y % P) % P + P) % P; }

signed main()
{
    scanf("%lld%lld%s", &n, &k, s + 1);
    for (int i = 1; i <= n; i++)
        cnt[i] = cnt[i - 1] + (s[i] == '*' or s[i] == '?');
    for (int len = 2; len <= n; len++)
        for (int L = 1, R; (R = L + len - 1) <= n; L++)
        {
            // AB / ASB
            for (int p = L; p + 1 <= R; p++)
                add(f[L][R], (f[L][p] - g[L][p]) * h[p + 1][R]);
            g[L][R] = f[L][R];
            if (judge(L, R))
            {
                // (S)
                if (check(L + 1, R - 1))
                    add(f[L][R], 1);
                // (A)
                add(f[L][R], f[L + 1][R - 1]);
                for (int p = L + 1; p < R - 1; p++)
                {
                    // (SA)
                    if (check(L + 1, p))
                        add(f[L][R], f[p + 1][R - 1]);
                    // (AS)
                    if (check(p + 1, R - 1))
                        add(f[L][R], f[L + 1][p]);
                }
            }
            // B / SB
            add(h[L][R], f[L][R]);
            for (int p = L; p + 1 <= R; p++)
                if (check(L, p))
                    add(h[L][R], f[p + 1][R]);
        }
    printf("%lld", f[1][n]);
    return 0;
}