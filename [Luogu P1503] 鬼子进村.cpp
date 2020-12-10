#include <stdio.h>
#include <queue>
#include <set>

#define IT std::set<int>::iterator

const int N = 5e4 + 5;

int n, m;
std::deque<int> Q;
std::set<int> set;

int main()
{
    scanf("%d%d", &n, &m);
    set.insert(0);
    set.insert(n + 1);
    for (int i = 1; i <= m; i++)
    {
        char c;
        scanf("\n%c", &c);
        switch (c)
        {
        case 'D':
        {
            int x;
            scanf("%d", &x);
            set.insert(x);
            Q.push_back(x);
            break;
        }
        case 'Q':
        {
            int x;
            scanf("%d", &x);
            IT it = set.lower_bound(x);
            if (*it == x)
            {
                printf("0\n");
                continue;
            }
            int ans = *it - *(--it);
            printf("%d\n", ans - 1);
            break;
        }
        case 'R':
        {
            IT it = set.find(Q.back());
            Q.pop_back();
            set.erase(it);
            break;
        }
        }
    }
    return 0;
}