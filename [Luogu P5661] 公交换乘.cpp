#include <stdio.h>
#include <algorithm>

const int N = 1e5 + 5;

int n, ans;
int price_1[N], t_1[N], cnt;
bool used[N];

int main()
{
    // freopen("transfer.in", "r", stdin);
    // freopen("transfer.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int opt, price, t;
        scanf("%d%d%d", &opt, &price, &t);
        if (opt == 0)
            price_1[++cnt] = price, t_1[cnt] = t, ans += price;
        else
        {
            bool flag = false;
            int l = 1, r = cnt, res = 1;
            while (l <= r)
            {
                int mid = (l + r) >> 1;
                if (t - t_1[mid] <= 45)
                    res = mid, r = mid - 1;
                else
                    l = mid + 1;
            }
            for (int i = res; i <= cnt; i++)
                if (t - t_1[i] <= 45 and !used[i] and price_1[i] >= price and t_1[i] < t)
                {
                    used[i] = true, flag = true, ans += price_1[i] - price >= 0 ? 0 : price - price_1[i];
                    break;
                }
            if (!flag)
                ans += price;
            //printf("ans:%d\n", ans);
        }
    }
    printf("%d", ans);
    return 0;
}
/*
6
0 10 3
1 5 46
0 12 50
1 3 96
0 5 110
1 6 135
*/