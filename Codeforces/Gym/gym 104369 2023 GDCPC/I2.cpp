#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int m, n;
        scanf("%d%d", &m, &n);
        vector<pair<int, pair<int, int>>> point;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int val;
                scanf("%d", &val);
                pair<int, pair<int, int>> in = {val, {i, j}};
                point.push_back(in);
            }
        }
        sort(point.begin(), point.end());
        set<pair<int, int>> have;
        have.insert({0, 0});
        have.insert({1000005, 1000005});
        int ans = 0;
        for (int i = 0; i < point.size(); i++)
        {
            have.insert({point[i].second.first, point[i].second.second});
            auto it = have.find({point[i].second.first, point[i].second.second});
            auto it1 = it;
            it1--;
            auto it2 = it;
            it2++;
            if ((it->first) >= (it1->first)
            && (it->second) >= (it1->second)
            && (it->first) <= (it2->first)
            && (it->second) <= (it2->second))
            {
                if (ans == i)
                    ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}