#include <stdio.h>
#include <vector>
#include <algorithm>

int n;
std::vector<int> odd, even;
std::vector<std::pair<int, int>> ans;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        odd.clear(), even.clear(), ans.clear();
        for (int i = 1; i <= 2 * n; i++)
        {
            int x;
            scanf("%d", &x);
            if (x % 2 == 1)
                odd.push_back(i);
            else
                even.push_back(i);
        }
        for (int i = 0; i + 1 < odd.size(); i += 2)
            ans.push_back({odd[i], odd[i + 1]});
        for (int i = 0; i + 1 < even.size(); i += 2)
            ans.push_back({even[i], even[i + 1]});
        for (int i = 0; i < n - 1; i++)
            printf("%d %d\n", ans[i].first, ans[i].second);
    }
    return 0;
}