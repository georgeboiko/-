vector<ll>mt;
vector<vector<ll>>gr;
vector<ll>used;
 
ll dfs(ll u) {
    if (used[u]) return 0;
    used[u] = 1;
    for (auto& v : gr[u]) {
        if (mt[v] == -1 || dfs(mt[v])) {
            mt[v] = u; return 1;
        }
    }
    return 0;
}
 
gr.assign(n + pl1.size(), {});
used.assign(n, 0);
mt.assign(pl1.size(), -1);
for (ll i = 0; i < n; ++i) {
    if (dfs(i)) {
        ++ans;
        used.assign(n, 0);
    }
}
