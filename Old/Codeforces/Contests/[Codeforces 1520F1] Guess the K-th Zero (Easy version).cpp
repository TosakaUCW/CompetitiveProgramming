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

int n, t, k;

int sum(int x, int y)
{
    printf("? %d %d\n", x, y);
    flu;
    return read();
}

signed main()
{
    n = read(), t = read(), k = read();
    int L = 1, R = n;
    while (L <= R)
    {
        int mid = (L + R) / 2;
        int a = sum(L, mid);
        int b = mid - L + 1 - a;
        if (b < k)
            k -= b, L = mid + 1;
        else
            R = mid - 1;
    }
    printf("! %d", L);
    return 0;
}