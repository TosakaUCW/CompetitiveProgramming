#include <bits/stdc++.h>
using i64 = long long;
using pii = std::pair<int, int>;
using tuu = std::tuple<int, int, int>;
#define pb push_back
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

template <class T>
constexpr T power(T a, i64 b) { T res {1}; for (; b; b /= 2, a *= a) if (b % 2) res *= a; return res; }
constexpr i64 mul(i64 a, i64 b, i64 p) { i64 res = a * b - (i64)(1.L * a * b / p) * p; res %= p; if (res < 0) res += p; return res; }
template <i64 P>
struct MInt
{
    i64 x;
    constexpr MInt() : x {0} {}
    constexpr MInt(i64 x) : x {norm(x % getMod())} {}
    static i64 Mod;
    constexpr static i64 getMod() { return P > 0 ? P : Mod; }
    constexpr static void setMod(i64 Mod_) { Mod = Mod_; }
    constexpr i64 norm(i64 x) const { if (x < 0) x += getMod(); if (x >= getMod()) x -= getMod(); return x; }
    constexpr i64 val() const { return x; }
    constexpr MInt operator-() const { MInt res; res.x = norm(getMod() - x); return res; }
    constexpr MInt inv() const { return power(*this, getMod() - 2); }
    constexpr MInt &operator*=(MInt rhs) & { if (getMod() < (1ULL << 31)) x = x * rhs.x % int(getMod()); else x = mul(x, rhs.x, getMod()); return *this; }
    constexpr MInt &operator+=(MInt rhs) & { x = norm(x + rhs.x); return *this; }
    constexpr MInt &operator-=(MInt rhs) & { x = norm(x - rhs.x); return *this; }
    constexpr MInt &operator/=(MInt rhs) & { return *this *= rhs.inv(); }
    friend constexpr MInt operator*(MInt lhs, MInt rhs) { MInt res = lhs; res *= rhs; return res; }
    friend constexpr MInt operator+(MInt lhs, MInt rhs) { MInt res = lhs; res += rhs; return res; }
    friend constexpr MInt operator-(MInt lhs, MInt rhs) { MInt res = lhs; res -= rhs; return res; }
    friend constexpr MInt operator/(MInt lhs, MInt rhs) { MInt res = lhs; res /= rhs; return res; }
    friend constexpr std::istream &operator>>(std::istream &is, MInt &a) { i64 v; is >> v; a = MInt(v); return is; }
    friend constexpr std::ostream &operator<<(std::ostream &os, const MInt &a) { return os << a.val(); }
    friend constexpr bool operator==(MInt lhs, MInt rhs) { return lhs.val() == rhs.val(); }
    friend constexpr bool operator!=(MInt lhs, MInt rhs) { return lhs.val() != rhs.val(); }
    friend constexpr bool operator<(MInt lhs, MInt rhs) { return lhs.val() < rhs.val(); }
};
template <>
i64 MInt<0>::Mod = 998244353;
constexpr int P = 1e9 + 7;
using Z = MInt<P>;

const int N = 60 + 5;

int a[N];
Z f[N][N][N];
bool vis[N][N][N];

Z calc(Z x) { return x * (x + 1) / 2; }

Z dfs(int u, int las0, int ned1, bool lim)
{
    if (u == 0)
    {
        if (las0 > 1 and ned1 == 0)
            return calc((1LL << las0 - 1) - 1);
        return 0;
    }
    if (!lim and vis[u][las0][ned1]) return f[u][las0][ned1];
    Z ans = 0;
    int up = lim ? a[u] : 1;
    for (int i = 0; i <= up; i++)
        ans += dfs(u - 1, (i == 0 ? u : las0), ned1 - i, lim and (i == up));
    if (!lim)
        vis[u][las0][ned1] = 1,
        f[u][las0][ned1] = ans;
    return ans;
}

void solve()
{
    i64 n; int k;
    cin >> n >> k; n--;
    if ((1LL << k + 1) - 1 > n)
        return cout << calc(n + 1) << '\n', void();
    
    a[0] = 0;
    for (i64 x = n; x; x /= 2) a[++a[0]] = x % 2;
    
    Z ans = dfs(a[0], a[0] + 1, k + 1, 1);
    
    if (__builtin_popcountll(n) <= k)
    {
        for (int j = 1; j <= 62; j++)
            if (n >> j & 1)
            {
                i64 t = (n ^ (1LL << j)) | ((1LL << j) - 1);
                if (__builtin_popcountll(t) > k)
                {
                    ans += calc(n - t);
                    break;
                }
            }
    }
    cout << ans << '\n';
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}
/*
1011100

1011011
1010111
1001111
0111111

1000000
*/