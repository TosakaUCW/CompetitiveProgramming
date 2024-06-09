#include <bits/stdc++.h>
#define int long long
#define pb push_back
using std::cin, std::cout, std::string;
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 1e4 + 5;
const int INF = 1 << 30;
// const long long INF = 1LL << 60;
int n;
string inp[N];
int buk[4], ans;
void solve()
{
    string s, t;
    cin >> s >> t;
    buk[0] = buk[1] = buk[2] = buk[3] = 0;
    for (auto ch : t) buk[ch - 'A'] = 1;
    int cnt = 0;
    for (auto ch : s)
    {
        if (buk[ch - 'A'] != 1)
        {
            cnt = 5;
            break;
        }
        else cnt++;
    }
    if (cnt == 5) return;
    else if (cnt == t.size() and t.size() == 1) ans += 3;
    else if (cnt == t.size()) ans += 5;
    else ans += 2;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    cout << ans;
    return 0;
}