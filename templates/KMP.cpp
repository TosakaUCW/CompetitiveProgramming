vector<int> getFail(string s) {
    int n = s.size();
    vector<int> f(n + 1);
    for (int i = 1, j = 0; i < n; i++) {
        while (j and s[i] != s[j]) {
            j = f[j];
        }
        j += (s[i] == s[j]);
        f[i + 1] = j;
    }
    return f;
}
vector<pii> kmp(string s, string t) {
    int n = s.size();
    int m = t.size();
    auto fail = getFail(s);
    vector<pii> pos;
    if (s == "") pos.eb(0, 0);
    for (int i = 0, j = 0; i < m; i++) {
        while (j and t[i] != s[j]) j = fail[j];
        if (t[i] == s[j]) j++;
        if (j == n) {
            pos.eb(i - j + 1, i + 1);
            j = fail[j];
        }
    }
    return pos;
}