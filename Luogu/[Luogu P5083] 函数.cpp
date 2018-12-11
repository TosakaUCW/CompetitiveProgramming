// luogu-judger-enable-o2
#include <algorithm>
#include <iostream>
#include <unordered_map>

typedef long long ll;
#define Rep(i, x, y) for (int i = x; i <= y; i++)

const int N = 1e7;

ll a, b, f[N + 5];
std::unordered_map<ll, ll> ans;

ll g(ll n)
{
    if (n <= N)
        return f[n];
    if (ans.count(n))
        return ans[n];
    return ans[n] = std::max(n, g(n / 2) + g(n / 3) + g(n / 8) + g(n / 9));
}

int main()
{
    f[0] = 0;
    Rep(i, 1, N)
        f[i] = std::max(i * 1LL, f[i / 2] + f[i / 3] + f[i / 8] + f[i / 9]);
    while (std::cin >> a >> b)
        std::cout << g(a) + g(b) << std::endl;
    return 0;
}