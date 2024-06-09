#include <bits/stdc++.h>
// #define int long long
#define fi first
#define se second
#define ins insert
#define pb emplace_back
#define flu fflush(stdout)
#define pii std::pair<int, int>
using std::map;
using std::priority_queue;
using std::queue;
using std::set;
using std::stack;
using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;
int read(int x = 0, bool f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57)
        f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57)
        x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
int pow(int x, int k, int P, int res = 1)
{
    for (; k; k >>= 1, x = x * x % P)
        if (k & 1)
            res = res * x % P;
    return res;
}

const int N = 1e6 + 5;
const int P = 998244353;

int n, a[N], pos[N];
vector<int> ans;

void rev(int L, int R)
{
    std::reverse(a + L, a + 1 + R);
    for (int i = L; i <= R; i++)
        pos[a[i]] = i;
    ans.pb(R);
}

void solve()
{
    n = read(), ans.clear();
    for (int i = 1; i <= n; i++)
        pos[a[i] = read()] = i;
    for (int i = 1; i <= n; i++)
        if ((a[i] & 1) != (pos[a[i]] & 1))
            return puts("-1"), void();
    for (int i = n; i > 1; i -= 2)
    {
        rev(1, pos[i]);
        rev(1, pos[i - 1] - 1);
        rev(1, pos[i - 1] + 1);
        rev(1, 3);
        rev(1, i);
    }
    printf("%d\n", ans.size());
    for (auto x : ans)
        printf("%d ", x);
    puts("");
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("my_input.in", "r", stdin);
#endif
    for (int T = read(); T--; solve())
        ;
    return 0;
}