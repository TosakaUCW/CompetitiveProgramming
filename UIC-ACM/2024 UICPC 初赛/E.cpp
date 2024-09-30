#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int K = 1000;
int T;
ll a, b, c, d, i, j, k, ans;
inline ll cal(ll a, ll b, ll c) { return a * a + b * b + c * c + min(a, min(b, c)) * 6; }
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> a >> b >> c >> d;
        ans = 0;
        for (i = 0; i <= d && i <= K; i++)
            for (j = 0; i + j <= d && j <= K; j++)
            {
                k = d - i - j;
                ans = max(ans, cal(a + i, b + j, c + k));
                ans = max(ans, cal(a + i, b + k, c + j));
                ans = max(ans, cal(a + k, b + i, c + j));
            }
        ans = max(ans, cal(a + d, b, c));
        ans = max(ans, cal(a, b + d, c));
        ans = max(ans, cal(a, b, c + d));
        cout << ans << endl;
    }
}