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

const string a[] = {"jia", "yi", "bing", "ding", "wu", "ji", "geng", "xin", "ren", "gui"};
const string b[] = {"zi", "chou", "yin", "mao", "chen", "si", "wu", "wei", "shen", "you", "xu", "hai"};

void solve() {

    int n; cin >> n;
    
    map<string, int> mp;
    for (int now = 1984, i = 0, j = 0; now <= 2043; now++) {
        string s = a[i] + b[j];
        mp[s] = now;
        i = (i + 1) % 10;
        j = (j + 1) % 12;
    }

    while (n--) {
        string t; cin >> t;
        cout << mp[t] << '\n';
    }

}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    // int T; cin >> T;
    for (; T--; solve());
    // solve();
    return 0;
}
