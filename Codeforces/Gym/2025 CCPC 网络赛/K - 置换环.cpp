#include <bits/stdc++.h>

using namespace std;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

void solve() {
    int n = read();
    
    int ans = (1 + n) * n / 2;

    vector<int> a(n + 1);
    a[1] = 1;
    int t = 2;
    for (int i = n; i >= 2; i--) {
        a[i] = t;
        t++;
    }

    cout << ans << '\n';
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
}

int main() {
    // freopen("K.in", "r", stdin);
    solve();
    return 0;
}