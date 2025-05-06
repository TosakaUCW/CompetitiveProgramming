#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using namespace std;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = pair<int, int>;
const int inf = 1e18;
std::vector<int> minp, primes;
void sieve(int n) {
    minp.assign(n + 1, 0), primes.clear();
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) minp[i] = i, primes.push_back(i);
        for (auto p : primes) {
            if (i * p > n) break;
            minp[i * p] = p;
            if (p == minp[i]) break;
        }
    }
}

void solve() {
    int n = read();
    vector<int> a(n);
    for (auto &x : a) x = read();

    // ranges::sort(a);
    sort(a.rbegin(), a.rend());

    auto judge = [&](int x) {
        int s1 = 0, s2 = 0;
        for (int i = 0; i < x; i++) {
            s1 += a[i];
            s2 += primes[i];
        }
        return s2 <= s1;
    };

    int ans = 0;
    for (int L = 0, R = n; L <= R; ) {
        int mid = L + R >> 1;
        if (judge(mid)) ans = mid, L = mid + 1;
        else R = mid - 1;
    }

    cout << n - ans << '\n';
}

signed main() {
    sieve(1e7);
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}

