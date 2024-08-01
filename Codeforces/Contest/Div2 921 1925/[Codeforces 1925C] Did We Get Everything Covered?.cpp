#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
bool buk[26];
void solve()
{
    int n = read(), k = read(), m = read();
    std::string s, ans;
    std::cin >> s;
    int cnt = 0, tot = 0;
    memset(buk, 0, sizeof buk);
    for (auto ch : s)
    {
        if (ans.size() == n) break;
        cnt += !buk[ch - 'a'], buk[ch - 'a'] = 1;
        if (cnt == k) cnt = 0, ans += ch, memset(buk, 0, sizeof buk);
    }
    if (ans.size() == n) puts("YES");
    else
    {
        puts("NO");
        for (int i = 0; i < k; i++)
            if (!buk[i])
                while (ans.size() < n)
                    ans += char(i + 'a');
        std::cout << ans << '\n';
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("C.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}