#include <bits/stdc++.h>
// #define int long long
#define fi first
#define se second
#define ins insert
#define pb push_back
#define flu fflush(stdout)
#define pii std::pair<int, int>
using std::swap, std::vector, std::string, std::queue, std::cin, std::cout;
int read(int x = 0, bool f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57)
        f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57)
        x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 1e6 + 5;

int n, a[2][N], ans;

bool judge(int lim)
{
    std::vector<int> S;
    for (int k = 0; k < 2; k++)
    {
        for (int i = 1; i <= n; i++)
            if (a[k][i] > lim)
                if (S.empty())
                    S.pb(a[k][i]);
                else if (*--S.end() == a[k][i])
                    S.pop_back();
                else
                    return 0;
        if (!S.empty())
            return 0;
    }
    return 1;
}

void solve()
{
    n = read();
    for (int k = 0; k < 2; k++)
        for (int i = 1; i <= n; i++)
            a[k][i] = read();
    for (int L = 0, R = int(1e9), mid; L <= R;)
        if (judge(mid = L + R >> 1))
            R = (ans = mid) - 1;
        else
            L = mid + 1;
    printf("%d", ans);
}

signed main() { return solve(), 0; }