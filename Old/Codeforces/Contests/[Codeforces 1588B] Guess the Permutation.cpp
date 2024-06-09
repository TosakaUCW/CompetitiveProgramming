#include <bits/stdc++.h>
// #define int long long
#define fi first
#define se second
#define ins insert
#define pb push_back
#define flu fflush(stdout)
#define pii std::pair<int, int>
using std::map;
using std::priority_queue;
using std::queue;
using std::set;
using std::stack;
using std::string;
using std::swap;
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

int n;

int ask(int L, int R) { return printf("? %d %d\n", L, R), flu, read(); }

int get()
{
    int L = 1, R = n - 2, ans = 1;
    while (L <= R)
    {
        int mid = (L + R) / 2;
        int res = ask(1, mid);
        if (res > 0)
            R = mid - 1;
        else
            L = mid + 1;
        if (res == 0)
            ans = mid;
    }
    return ans;
}

void solve()
{
    flu;
    n = read();
    int i = get();
    int j = i + ask(i, n) - ask(i + 1, n) + 1;
    int k = j + ask(j, n) - ask(j + 1, n);
    printf("! %d %d %d\n", i, j, k), flu;
}

signed main()
{
    for (int T = read(); T--; solve())
        ;
#ifndef ONLINE_JUDGE
    std::cerr << (double)clock() / CLOCKS_PER_SEC << 's' << std::endl;
#endif
    return 0;
}