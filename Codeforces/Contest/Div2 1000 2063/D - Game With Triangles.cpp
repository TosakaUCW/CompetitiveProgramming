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

void solve() {
    int n = read();
    int m = read();

    vector<deque<int>> a(2);
    a[0].assign(n, 0);
    a[1].assign(m, 0);

    for (auto &x : a) {
        for (auto &y : x) y = read();
        ranges::sort(x);
    }

    int kmax = min({(n + m) / 3, n, m});
    cout << kmax << '\n';

    int ans = 0;

    vector cnt = {n, m};
    stack<int> st[2];

    auto get = [&](const auto &x) {
        return x.back() - x.front();
    };
    auto add = [&](int i) {
        int x = get(a[i]); 

        a[i].pop_front();
        a[i].pop_back();

        ans += x, cnt[i] -= 2, cnt[i ^ 1] -= 1;
        st[i].ep(x);
    };
    auto del = [&](int i) {
        int x = st[i].top(); 
        ans -= x, cnt[i] += 2, cnt[i ^ 1] += 1;
        st[i].pop();
    };

    for (int k = 0; k < kmax; k++) {
        for (int i : {0, 1}) {
            if (cnt[i] >= 2 and cnt[i ^ 1] == 1 
                or
                cnt[i] >= 2 and cnt[i ^ 1] >= 2 and
                get(a[i]) >= get(a[i ^ 1])) {

                add(i);
                goto nxt;
            }
        }
        for (int i : {0, 1}) {
            if (cnt[i] == 0) {
                del(i);
                add(i ^ 1);
                add(i ^ 1);
                goto nxt;
            }
        }

        nxt: 
        cout << ans << " \n"[k == kmax - 1];
    }
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}
