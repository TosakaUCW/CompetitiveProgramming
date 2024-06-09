#include <bits/stdc++.h>
#define int long long
using pii = std::pair<int, int>;
using tuu = std::tuple<int, int, int>;
#define pb push_back
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 1e6 + 5;
// const int INF = 1e18;
int n, m, a[N];
const int res[] = {0, 13501, 28002, 43503, 60004, 77505, 96006, 115507, 136008, 157509, 180001, 194502, 210003, 226504, 244005, 262506, 282007, 302508, 324009, 346510, 370002, 385503, 402004, 419505, 438006, 457507, 478008, 499509, 522010, 545511, 570003, 586504, 604005, 622506, 642007, 662508, 684009, 706510, 730011, 754512, 780004, 797505, 816006, 835507, 856008, 877509, 900010, 923511, 948012, 973513, 1000005, 1018506, 1038007, 1058508, 1080009, 1102510, 1126011, 1150512, 1176013, 1202514, 1230006, 1249507, 1270008, 1291509, 1314010, 1337511, 1362012, 1387513, 1414014, 1441515, 1470007, 1490508, 1512009, 1534510, 1558011, 1582512, 1608013, 1634514, 1662015, 1690516, 1720008, 1741509, 1764010, 1787511, 1812012, 1837513, 1864014, 1891515, 1920016, 1949517, 1980009, 2002510, 2026011, 2050512, 2076013, 2102514, 2130015, 2158516, 2188017, 2218518, 2250001, 2264502, 2280003, 2296504, 2314005, 2332506, 2352007, 2372508, 2394009, 2416510, 2440002, 2455503, 2472004, 2489505, 2508006, 2527507, 2548008, 2569509, 2592010, 2615511, 2640003, 2656504, 2674005, 2692506, 2712007, 2732508, 2754009, 2776510, 2800011, 2824512, 2850004, 2867505, 2886006, 2905507, 2926008, 2947509, 2970010, 2993511, 3018012, 3043513, 3070005, 3088506, 3108007, 3128508, 3150009, 3172510, 3196011, 3220512, 3246013, 3272514, 3300006, 3319507, 3340008, 3361509, 3384010, 3407511, 3432012, 3457513, 3484014, 3511515, 3540007, 3560508, 3582009, 3604510, 3628011, 3652512, 3678013, 3704514, 3732015, 3760516, 3790008, 3811509, 3834010, 3857511, 3882012, 3907513, 3934014, 3961515, 3990016, 4019517, 4050009, 4072510, 4096011, 4120512, 4146013, 4172514, 4200015, 4228516, 4258017, 4288518, 4320010, 4343511, 4368012, 4393513, 4420014, 4447515, 4476016, 4505517, 4536018, 4567519, 4600002
};
void solve()
{
    n = read();
    int ans = 0;
    int m = 0;
    for (int i = 200; i >= 1; i--)
    {
        if (n >= i * 1000)
        {
            ans += res[i], m = i * 1000;
            break;
        }
    }
    // cout << m << '\n' << n << '\n';
    for (int i = m + 1; i <= n; i++)
    {
        int x = i;
        while (x > 0) ans += x % 10, x /= 10;
    }
    cout << ans << '\n';
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("B.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}