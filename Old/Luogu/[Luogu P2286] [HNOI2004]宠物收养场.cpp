// luogu-judger-enable-o2
#include <stdio.h>
#include <algorithm>
#include <set>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 8e4;
const int P = 1e6;

int n, ans;
std::set<int> pet, host;

int dis(int x, int y)
{
    return (x > y) ? (x - y) : (y - x);
}

void calc(int x, int y)
{
    ans = (ans + dis(x, y) % P) % P;
}

void solve(std::set<int> &set, int x)
{
    if (set.size() == 1)
    {
        calc(x, *set.begin());
        set.clear();
    }
    else
    {
        std::set<int>::iterator l, r;
        l = --set.lower_bound(x);
        r = set.lower_bound(x);
        if (r == set.begin())
        {
            calc(x, *r);
            set.erase(r);
        }
        else
        {
            if (dis(x, *l) <= dis(x, *r) or r == set.end())
            {
                calc(x, *l);
                set.erase(l);
            }
            else
            {
                calc(x, *r);
                set.erase(r);
            }
        }
    }
}

int main()
{
    scanf("%d", &n);
    Rep(i, 1, n)
    {
        int opt, x;
        scanf("%d%d", &opt, &x);
        if (opt == 0)
        {
            if (host.empty())
                pet.insert(x);
            else
                solve(host, x);
        }
        else
        {
            if (pet.empty())
                host.insert(x);
            else
                solve(pet, x);
        }
    }
    printf("%d", ans);
    return 0;
}