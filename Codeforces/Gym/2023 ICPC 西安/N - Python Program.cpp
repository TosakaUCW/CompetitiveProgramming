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
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for (auto x : a) cout << x << " "; cout << "\n";
template <class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; i++) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; i++) cerr << *i << " "; cerr << '\n'; }
using pii = pair<int, int>;
const int inf = 1e18;

struct node {
    string i, a, b, c;
};

node get(string s) {
    s = s.substr(s.find("for ") + 4);

    auto i = s.substr(0, s.find(' '));

    s = s.substr(s.find('('));

    auto a = s.substr(1, s.find(',') - 1);

    s = s.substr(s.find(',') + 1);
    // cout << "--" << s << '\n';

    string b, c;
    if (s.find(',') != string::npos) {
        b = s.substr(0, s.find(','));
        s = s.substr(s.find(',') + 1);
        c = s.substr(0, s.find(')'));
    } else {
        b = s.substr(0, s.find(')'));
        c = "1";
    }

    return node {i, a, b, c};
}

void solve() {
    string s;
    getline(cin, s);
    getline(cin, s);
    auto [i, a, b, c] = get(s);
    getline(cin, s);
    auto [j, d, e, f] = get(s);

    // cout << i << ' ' << a << ' ' << b << ' ' << c << '\n';
    // cout << j << ' ' << d << ' ' << e << ' ' << f << '\n';

    // getline(cin, s);

    // s = s.substr(7);
    // cout << s << '\n';

    int ans = 0;
    int va = stoi(a);
    int vb = stoi(b);
    int vc = stoi(c);

    for (int i = va; (vc > 0 ? i < vb : i > vb); i += vc) {
        int vd = isalpha(d[0]) ? i : stoi(d);
        int ve = isalpha(e[0]) ? i : stoi(e);
        int vf = isalpha(f[0]) ? i : stoi(f);
        
        if (vf > 0) {
            if (vd < ve) {
                int k = (ve - vd - 1) / vf;
                ans += (vd + vd + k * vf) * (k + 1) / 2;
            }
        } else {
            if (vd > ve) {
                int k = (vd - ve - 1) / -vf;
                ans += (vd + vd + k * vf) * (k + 1) / 2;
            }
        }
    }

    cout << ans << '\n';
}

signed main() {
    solve();
    return 0;
}