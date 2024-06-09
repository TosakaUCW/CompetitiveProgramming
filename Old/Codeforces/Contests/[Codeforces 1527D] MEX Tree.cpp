#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <iostream>
#include <vector>

typedef long long ll;
using std::cin;

const int N = 4e5 + 5;

int n;
std::vector<int> g[N];
int dfin[N], dfou[N], timer; 
ll ans[N], siz[N];

void dfs1(int u, int fa)
{
	siz[u] = 1, dfin[u] = ++timer;
	for (int v : g[u])
		if (v != fa) dfs1(v, u), siz[u] += siz[v];
	dfou[u] = timer;
}

bool isAnc(int u, int anc) { return dfin[u] >= dfin[anc] and dfin[u] <= dfou[anc]; }

void solve()
{
#define pb push_back
    timer = 0;
	cin >> n;
    for (int i = 0; i < n; i++) g[i].clear();
	for (int i = 1, u, v; i < n; i++)
		cin >> u >> v, g[u].pb(v), g[v].pb(u);
	dfs1(0, -1);
	int x = 0,  A = 1, B = 0, flag = 1;
    ll all = 1LL * n * (n - 1) / 2;
    ans[0] = 0;
	for (int v : g[0])
	{
		ans[0] += siz[v] * (siz[v] - 1) / 2;
		if (isAnc(1, v)) x = v;
	}
	ans[1] = all - siz[A] * (n - siz[x]);
	for (int i = 2; i < n; i++)
	{
        ans[i] = all;
        if (!flag) continue;
        if (isAnc(i,A))
			A = i;
		else if (!isAnc(A,i))
		{
		    if (!B)
		    {
			    if (isAnc(i,x))
    		    	flag = 0;
			    else
				    B = i;
		    }
		    else
		    {
	    		if (isAnc(i,B))
    				B = i;
	    		else if (!isAnc(B,i))
    				flag = 0;
    		}
	    }
	    if (!flag) continue;
    	if (!B)
    		ans[i] -= siz[A] * (n - siz[x]);
    	else
   			ans[i] -= siz[A] * siz[B];
	}
    ans[n] = all;
	for (int i = n; i >= 1; i--) ans[i] -= ans[i - 1];
	for (int i = 0; i <= n; i++) printf("%lld ", ans[i]);
	puts("");
}

signed main()
{
    int T;
	for (cin >> T; T--; solve());
	return 0;
}
