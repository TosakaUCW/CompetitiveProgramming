#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using namespace std;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
#define fi first
#define se second
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for (auto x : a) cout << x << " "; cout << "\n";
template <class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; i++) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; i++) cerr << *i << " "; cerr << '\n'; }
template <class T> bool cmin(T &a, T b) { return (b < a) ? (a = b, true) : false; }
template <class T> bool cmax(T &a, T b) { return (a < b) ? (a = b, true) : false; }
using pii = pair<int, int>;
using tup = tuple<int, int, int>;
const int inf = 1e18;
const double eps = 1e-9;

map<int, int> isPrime;
std::vector<int> minp, primes;
void sieve(int n) {
    minp.assign(n + 1, 0), primes.clear();
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) minp[i] = i, primes.push_back(i), isPrime[i] = 1;
        for (auto p : primes) {
            if (i * p > n) break;
            minp[i * p] = p;
            if (p == minp[i]) break;
        }
    }
}

void solve() {
    int n = read();

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) a[i] = read();

    auto s = a;
    for (int i = 1; i <= n; i++) {
        s[i] += s[i - 1];
    }

    int ans = inf;
    for (int len = 1; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            int sum = s[j] - s[i - 1];
            if (isPrime.count(sum) or sum == 1) continue;
            cmin(ans, len - 1);
        }
    }
    if (ans == inf) ans = -1;
    cout << ans << '\n';
}

signed main() {
    sieve(1000000);
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}