vector<vector<int>> g(n + 1);
for (int i = 1; i < n; i++) {
    int u = read(), v = read();
    g[u].eb(v), g[v].eb(u);
}

vector<int> siz(n + 1), dep(n + 1), son(n + 1), fa(n + 1), top(n + 1);
vector<int> dfn(n + 1);
int timer = 0;
function<void(int, int)> dfs1 = [&](int u, int f) {
    siz[u] = 1, dep[u] = dep[f] + 1, fa[u] = f;
    for (int v : g[u]) if (v != f) {
        dfs1(v, u);
        siz[u] += siz[v];
        son[u] = siz[v] > siz[son[u]] ? v : son[u];
    }
};
function<void(int)> dfs2 = [&](int u) {
    dfn[u] = ++timer;
    top[u] = u == son[fa[u]] ? top[fa[u]] : u;
    if (son[u]) dfs2(son[u]);
    for (int v : g[u]) if (v != fa[u] and v != son[u]) dfs2(v);
};
dfs1(1, 0), dfs2(1);
auto lca = [&](int x, int y) -> int {
    for (; top[x] != top[y]; x = fa[top[x]])
        if (dep[top[x]] < dep[top[y]])
            swap(x, y);
    return dep[x] < dep[y] ? x : y;
};
auto dis = [&](int x, int y) -> int {
    return dep[x] + dep[y] - 2 * dep[lca(x, y)];
};