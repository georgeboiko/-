vector<vector<ll>>gr;
vector<ll>colors, h, d;
set<pair<ll, ll>>st;
map<pair<ll,ll>, ll>mp;
 
void dfs(ll u, ll p = -1) {
    colors[u] = 1;
    d[u] = h[u] = (p == -1 ? 0 : h[p] + 1);
    for (auto& v : gr[u]) {
        if (v != p) {
            if (colors[v] == 1) d[u] = min(d[u], h[v]);
            else {
                dfs(v, u);
                d[u] = min(d[u], d[v]);
            }
            if (h[u] < d[v]) {
                st.insert({ min(u,v), max(u,v) });
            }
        }
    }
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
        mp[{min(u, v), max(u, v)}] = i + 1;
    }
    for (ll i = 0; i < n; ++i) {
        if (colors[i] == 0) dfs(i);
    }
    vector<ll>ans;
    for (auto& i : st) ans.push_back(mp[i]);
    sort(all(ans));
    cout << ans.size() << el;
    for (auto& i : ans) cout << i << " ";
    cout << el;
}
