#include <bits/stdc++.h>
using i64 = long long;
using namespace std;
template <class T>
constexpr T power(T a, i64 b) { T res {1}; for (; b; b /= 2, a *= a) if (b % 2) res *= a; return res; }
constexpr i64 mul(i64 a, i64 b, i64 p) { i64 res = a * b - (i64)(1.L * a * b / p) * p; res %= p; if (res < 0) res += p; return res; }
template <i64 P>
struct MInt {
    i64 x;
    constexpr MInt() : x {0} {}
    constexpr MInt(i64 x) : x {norm(x % getMod())} {}
    static i64 Mod;
    constexpr static i64 getMod() { return P > 0 ? P : Mod; }
    constexpr static void setMod(i64 Mod_) { Mod = Mod_; }
    constexpr i64 norm(i64 x) const { if (x < 0) x += getMod(); if (x >= getMod()) x -= getMod(); return x; }
    constexpr i64 val() const { return x; }
    constexpr MInt operator-() const { MInt res; res.x = norm(getMod() - x); return res; }
    constexpr MInt inv() const { return power(*this, getMod() - 2); }
    constexpr MInt &operator*=(MInt rhs) & { if (getMod() < (1ULL << 31)) x = x * rhs.x % int(getMod()); else x = mul(x, rhs.x, getMod()); return *this; }
    constexpr MInt &operator+=(MInt rhs) & { x = norm(x + rhs.x); return *this; }
    constexpr MInt &operator-=(MInt rhs) & { x = norm(x - rhs.x); return *this; }
    constexpr MInt &operator/=(MInt rhs) & { return *this *= rhs.inv(); }
    friend constexpr MInt operator*(MInt lhs, MInt rhs) { MInt res = lhs; res *= rhs; return res; }
    friend constexpr MInt operator+(MInt lhs, MInt rhs) { MInt res = lhs; res += rhs; return res; }
    friend constexpr MInt operator-(MInt lhs, MInt rhs) { MInt res = lhs; res -= rhs; return res; }
    friend constexpr MInt operator/(MInt lhs, MInt rhs) { MInt res = lhs; res /= rhs; return res; }
    friend constexpr istream &operator>>(istream &is, MInt &a) { i64 v; is >> v; a = MInt(v); return is; }
    friend constexpr ostream &operator<<(ostream &os, const MInt &a) { return os << a.val(); }
    friend constexpr bool operator==(MInt lhs, MInt rhs) { return lhs.val() == rhs.val(); }
    friend constexpr bool operator!=(MInt lhs, MInt rhs) { return lhs.val() != rhs.val(); }
    friend constexpr bool operator<(MInt lhs, MInt rhs) { return lhs.val() < rhs.val(); }
};
template <>
i64 MInt<0>::Mod = 1e9 + 7;
constexpr int P = 1e9 + 7;
using Z = MInt<P>;
using std::array;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, 1, -1};

void solve() {
    Z ans = 0;
    int n, m, K, hp;
    cin >> n >> m >> K >> hp;
    
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    
    int px = -1, py = -1, ex = -1, ey = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] == 'P') {
                px = i;
                py = j;
            }
            if (s[i][j] == 'E') {
                ex = i;
                ey = j;
            }
        }
    }
    
    auto valid = [&](int x, int y) {
        return 0 <= x and x < n and 0 <= y and y < n and s[x][y] != '#';
    };
    
    vector dp(n, vector<Z>(n));
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (s[x][y] != '#') {
                dp[x][y] = 1;
            }
        }
    }
    for (int i = 0; i < K; i++) {
        vector ndp(n, vector<Z>(n));
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if (dp[x][y] == 0) continue;
                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (valid(nx, ny)) {
                        ndp[nx][ny] += dp[x][y];
                    }
                }
            }
        }
        dp = move(ndp);
    }
    
    vector f(n, vector(n, array<array<array<Z, 9>, 9>, 5> {}));
    f[px][py][0][4][4] = 1;
    for (int i = 0; i < m - K; i++) {
        vector nf(n, vector(n, array<array<array<Z, 9>, 9>, 5> {}));
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                for (int d = 0; d < hp; d++) {
                    for (int edx = -d; edx <= d; edx++) {
                        for (int edy = -d; edy <= d; edy++) {
                            Z val = f[x][y][d][edx + 4][edy + 4];
                            if (val == 0) continue;
                            for (int k = 0; k < 4; k++) {
                                int nx = x + dx[k];
                                int ny = y + dy[k];
                                if (!valid(nx, ny)) {
                                    continue;
                                }
                                int nd = d;
                                int nedx = edx;
                                int nedy = edy;
                                int enx = x - px + ex + edx + dx[k];
                                int eny = y - py + ey + edy + dy[k];
                                if (!valid(enx, eny)) {
                                    nd++;
                                    if (nd >= hp) {
                                        ans += val * dp[nx][ny];
                                        continue;
                                    }
                                    nedx -= dx[k];
                                    nedy -= dy[k];
                                }
                                nf[nx][ny][nd][nedx + 4][nedy + 4] += val;
                            }
                        }
                    }
                }
            }
        }
        f = move(nf);
    }
    
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("1006.in", "r", stdin);
    freopen("1006.ans", "w", stdout);
#endif
    int T; cin >> T;
    for (; T--; solve());
    // solve();
    return 0;
}