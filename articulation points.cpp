vector<vector<ll>>gr;
vector<ll>colors, h, d;
set<ll>st;
 
void dfs(ll u, ll p = -1) {
    colors[u] = 1;
    d[u] = h[u] = (p == -1 ? 0 : h[p] + 1);
    ll children = 0;
    for (auto& v : gr[u]) {
        if (v != p) {
            if (colors[v] == 1) d[u] = min(d[u], h[v]);
            else {
                dfs(v, u);
                d[u] = min(d[u], d[v]);
                if (h[u] <= d[v] && p != -1) {
                    st.insert(u);
                }
                ++children;
            }
        }
    }
    if (p == -1 && children >= 2) st.insert(u);
}
 
int main() {
    ll n, m;
    cin >> n >> m;
    gr.resize(n);
    colors.resize(n);
    h.resize(n);
    d.resize(n);
    for (ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        --u, --v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    for (ll i = 0; i < n; ++i) {
        if (colors[i] == 0) dfs(i);
    }
    cout << st.size() << el;
    for (auto& i : st) cout << i+1 << " ";
    cout << el;
}
