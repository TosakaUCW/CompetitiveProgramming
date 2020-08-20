#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iostream>

const int N = 1e6;
const int SqrtN = 1000;

int n, m, a[N + 5];

struct Block
{
    int num, block;
    int belong[N + 5];
    int l[SqrtN + 5], r[SqrtN + 5], lazy[SqrtN + 5];
    std::vector<int> k[SqrtN + 5];
    void init(int n, int a[])
    {
        block = sqrt(n);
        num = n / block;
        if (n % block)
            num++;
        for (int i = 1; i <= num; i++)
            l[i] = (i - 1) * block + 1, r[i] = i * block;
        r[num] = n;
        for (int i = 1; i <= n; i++)
        {
            belong[i] = (i - 1) / block + 1;
            k[belong[i]].push_back(a[i]);
        }
        for (int i = 1; i <= num; i++)
            std::sort(k[i].begin(), k[i].end());
    }

    void update(int x, int y, int num)
    {
        if (belong[x] == belong[y])
        {
            k[belong[x]].clear();
            for (int i = x; i <= y; i++)
                a[i] += num;
            for (int i = l[belong[x]]; i <= r[belong[x]]; i++)
                k[belong[x]].push_back(a[i]);
            std::sort(k[belong[x]].begin(), k[belong[x]].end());
        }
        else
        {
            k[belong[x]].clear();
            for (int i = x; i <= r[belong[x]]; i++)
                a[i] += num;
            for (int i = l[belong[x]]; i <= r[belong[x]]; i++)
                k[belong[x]].push_back(a[i]);
            std::sort(k[belong[x]].begin(), k[belong[x]].end());
            for (int i = belong[x] + 1; i < belong[y]; i++)
                lazy[i] += num;
            k[belong[y]].clear();
            for (int i = l[belong[y]]; i <= y; i++)
                a[i] += num;
            for (int i = l[belong[y]]; i <= r[belong[y]]; i++)
                k[belong[y]].push_back(a[i]);
            std::sort(k[belong[y]].begin(), k[belong[y]].end());
        }
    }

    void query(int x, int y, int num)
    {
        int ans = 0;
        if (belong[x] == belong[y])
        {
            for (int i = x; i <= y; i++)
                if (a[i] + lazy[belong[x]] < num)
                    ans++;
        }
        else
        {
            for (int i = x; i <= r[belong[x]]; i++)
                if (a[i] + lazy[belong[x]] < num)
                    ans++;
            for (int i = belong[x] + 1; i < belong[y]; i++)
            {
                std::vector<int>::iterator pos;
                pos = std::upper_bound(k[i].begin(), k[i].end(), num - lazy[i] - 1);
                ans += pos - k[i].begin();
            }
            for (int i = l[belong[y]]; i <= y; i++)
                if (a[i] + lazy[belong[y]] < num)
                    ans++;
        }
        printf("%d\n", (y - x + 1) - ans);
    }
} block;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    block.init(n, a);
    while (m--)
    {
        char opt;
        int le, ri, c;
        std::cin >> opt >> le >> ri >> c;
        if (opt == 'M')
            block.update(le, ri, c);
        if (opt == 'A')
            block.query(le, ri, c);
    }
    return 0;
}