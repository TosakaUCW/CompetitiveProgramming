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
#define fi first
#define se second

bool isprime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
int findPrime(int n) {
    while (!isprime(n)) {
        n++;
    }
    return n;
}

using ull = unsigned long long;

void solve() {
    int n = read();
    int k = read();

    vector<int> a(n);
    for (auto &x : a) x = read() - 1;

    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    const ull bas = findPrime(rng() % 900000000 + 100000000);
    vector<ull> coef(k);
    coef[0] = 1;
    for (int i = 1; i < k; i++) {
        coef[i] = coef[i - 1] * bas;
    }

    ull all = accumulate(coef.begin(), coef.end(), 0ull);

    vector<int> freq(k);
    multiset<int> s(freq.begin(), freq.end());
    
    map<ull, int> pos;
    pos[0] = -1;

    int ans = 0;
    ull val = 0;
    for (int i = 0; i < n; i++) {
        auto x = a[i];

        s.erase(s.find(freq[x]));
        ++freq[x], val += coef[x];
        s.ep(freq[x]);

        int t = *s.begin();
        ull now = val - (ull)t * all;

        if (!pos.count(now)) {
            pos[now] = i;
        } else {
            ans = max(ans, i - pos[now]);
        }
    }

    cout << ans << '\n';
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}
