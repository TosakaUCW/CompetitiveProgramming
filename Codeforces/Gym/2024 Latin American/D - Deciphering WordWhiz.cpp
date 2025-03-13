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

    vector<string> a(n);
    for (auto &x : a) {
        cin >> x;
    }

    string ans = a[0];

    std::map<char, int> freq;
    for (auto ch : ans) freq[ch]++;

    int m = read();
    while (m--) {
        string res;
        cin >> res;

        auto buk = a;

        for (int i = 0; i < 5; i++) {

            vector<string> nbuk;

            for (auto s : buk) {
                // if (res[i] == '*' and s[i] != ans[i]) continue;
                // if (res[i] == 'X' and ans.find(s[i])) continue;
                // if (res[i] == '!' and ans.find(s[i])) continue;
                if (res[i] == '*' and s[i] == ans[i]
                 or res[i] == 'X' and !freq.count(s[i])
                 or res[i] == '!' and freq.count(s[i]) and s[i] != ans[i]) {
                    nbuk.eb(s);    
                }
            }

            buk = std::move(nbuk);
        }

        cout << buk.size() << '\n';
    }
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}
