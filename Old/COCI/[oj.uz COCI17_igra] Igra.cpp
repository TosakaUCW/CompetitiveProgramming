#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>

int n, cnt1[3], cnt2[3];
std::string s, t, ans;

bool check(int x, int y)
{
    cnt1[y]--, cnt2[t[x] - 'a']--;
    for (int i = 0; i < 3; i++)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
            if (i ^ j)
                sum += cnt2[j];
        if (cnt1[i] > sum)
            return cnt1[y]++, cnt2[t[x] - 'a']++, false;
    }
    return true;
}

int main()
{
    freopen("igra.in", "r", stdin), freopen("igra.out", "w", stdout);
    std::cin >> n >> s >> t;
    for (int i = 0; i < n; i++)
        cnt1[s[i] - 'a']++, cnt2[t[i] - 'a']++;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            if (cnt1[j] and j != t[i] - 'a' and check(i, j))
            {
                ans += j + 'a';
                break;
            }
    return std::cout << ans, 0;
}