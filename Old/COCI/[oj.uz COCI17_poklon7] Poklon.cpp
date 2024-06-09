#include <bits/stdc++.h>
 
#define pb push_back
#define sz(x) int(x.size())
 
using namespace std;
 
#define N 1000010
 
int L[N], R[N];
 
void convert(vector<char> &res, int x)
{
	while (x > 0)
    {
        if (x % 2) res.pb('1');
        else res.pb('0');
        x /= 2;
    }
    reverse(res.begin(), res.end());
}
 
vector<char> dfs(int v)
{
    vector<char> a, b;
	if (L[v] < 0) a = dfs(abs(L[v])); else convert(a, L[v]);
    if (R[v] < 0) b = dfs(abs(R[v])); else convert(b, R[v]);
    if (sz(a) < sz(b))
        swap(a, b);
    if (sz(a) != sz(b))
		{ a.pb('0'); return a; }
    for (int i = 0; i < sz(a); i++)
    {
		if (a[i] == b[i])
			continue;
        if (b[i] == '1')
            swap(a, b);
        break;
    }
    a.pb('0'); return a;
}
 
int main()
{
	ios_base::sync_with_stdio(0); istream::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
		int l, r;
		cin >> l >> r;
        if (l < 0) L[i] = abs(l); else L[i] = -l;
        if (r < 0) R[i] = abs(r); else R[i] = -r;
	}
    vector<char> ans = dfs(1);
    for (auto x : ans)
        cout << x;
}