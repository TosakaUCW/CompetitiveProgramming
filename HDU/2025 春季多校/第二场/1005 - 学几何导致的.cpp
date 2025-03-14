#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using namespace std;
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = std::pair<int, int>;
#define fi first
#define se second

void solve() {
    int n; cin >> n;
    int k; cin >> k;

    if (k % 2 == 1) { cout << "0\n"; return; }
    int c = k / 2;

    auto calc1 = [&]() -> int {
        int numerator = (n - 1) - c;
        if (numerator < 0) return 0;
        int M90 = numerator / (4 * c);
        if (M90 < 0) return 0;
        int count = M90 + 1;
        return count * n - c * count * (1 + 2 * M90);
    };
    auto calc2 = [&]() -> int {
        int numerator = (n - 1) - 3 * c;
        if (numerator < 0) return 0;
        int M270 = numerator / (4 * c);
        if (M270 < 0) return 0;
        int count = M270 + 1;
        return count * n - c * count * (3 + 2 * M270);
    };

    cout << calc1() + calc2() << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T; cin >> T;
    for (; T--; solve());
    return 0;
}
