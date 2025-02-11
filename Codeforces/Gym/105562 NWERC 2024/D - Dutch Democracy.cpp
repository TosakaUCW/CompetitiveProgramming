#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::cerr;
// using namespace std::views;
// using namespace std::ranges;
using std::max, std::min, std::swap, std::array;
using std::cin, std::cout, std::string, std::vector;
using std::ostream;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
void solve() {
    int n = read();
    vector<int> a(n);
    for (auto &x : a) x = read();
    std::sort(a.rbegin(), a.rend());
    
    int sum = std::accumulate(a.begin(), a.end(), 0ll);

    int half = sum / 2;
    int ans = 0;
    vector<int> f(1e6);


    for (auto x : a) {
        for (int j = half; j >= 0; j--) {
            f[j + x] += f[j];
            if (j + x > half) ans += f[j];
        }

        f[x]++;
        if (x > half) ans++;
    }
    cout << ans << '\n';
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}