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
const int INF = 2147483647;

int n, a[N], ans;

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("my_input.in", "r", stdin);
#endif
    n = read() + 1;
    string s;
    std::cin >> s;
    for (int i = 1; i <= n; i++)
        a[i] = read();
    int k = INT_MAX;
    for (int i = 1; i < n; i++)
        k = std::min(k, abs(a[i + 1] - a[i]));
    printf("%d\n", k);
    for (int i = 1; i <= k; i++, puts(""))
        for (int j = 1; j <= n; j++)
            printf("%d ", a[j] / k + (i <= a[j] % k));
    return 0;
}