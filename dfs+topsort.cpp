vector<vector<ll>>gr;
vector<ll>colors;
vector<ll>topSort;
 
void dfs(ll u) {
    colors[u] = 1;
    for (auto v : gr[u]) {
        if (colors[v] == 0) dfs(v);
    }
    colors[u] = 2;
    topSort.push_back(u);
}
