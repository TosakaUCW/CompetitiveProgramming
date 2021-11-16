#include <bits/stdc++.h>
#define int long long
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
int pow(int x, int k, int P, int res = 1)
{
    for (; k; k >>= 1, x = x * x % P)
        if (k & 1)
            res = res * x % P;
    return res;
}

const int N = 3e5 + 5;
const int P = 998244353;

int n, ans, tg, x;
int a[N];
std::map<int, int> map;

void solve()
{
    n = read(), map.clear();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    tg = 1, x = ans = 0;
    for (int i = 1; i <= n; i++)
    {
#define head (map.begin())
#define tail (prev(map.end()))
        if (tg == 1)
        {
            map[-x]++;
            while (map.size() and tail->fi + x > a[i])
                map.erase(tail);
        }
        else
        {
            map[x]++;
            while (map.size() and -head->fi + x > a[i])
                map.erase(head);
        }
        tg = -tg, x = a[i] - x;
        ans += map[tg == 1 ? -x : x];
    }
    printf("%lld\n", ans);
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("my_input.in", "r", stdin);
#endif
    for (int T = read(); T--; solve())
        ;
#ifndef ONLINE_JUDGE
    std::cerr << (double)clock() / CLOCKS_PER_SEC << 's' << std::endl;
#endif
    return 0;
}