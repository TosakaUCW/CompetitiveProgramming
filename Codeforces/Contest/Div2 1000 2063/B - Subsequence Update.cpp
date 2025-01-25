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
const int inf = 2e9;

void solve() {
    int n = read();
    int l = read(), r = read();
    // l--, r--;

    vector<int> a(n);
    for (auto &x : a) x = read();

    int k = r - l + 1;

    vector<int> pre(a.begin(), a.begin() + r);
    vector<int> suf(a.begin() + l - 1, a.end());

    ranges::sort(pre);
    ranges::sort(suf);

    int sum1 = accumulate(pre.begin(), pre.begin() + k, 0ll);
    int sum2 = accumulate(suf.begin(), suf.begin() + k, 0ll);

    cout << min(sum1, sum2) << "\n";
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}