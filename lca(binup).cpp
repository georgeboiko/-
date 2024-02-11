const ll root = 0, n = 500000, logN = 19;
vector<vector<ll>> binup;
vector<ll> d;
 
ll up(ll u, ll d) {
    ll j = 0;
    while (d > 0) {
        if (d % 2 == 1) u = binup[u][j];
        ++j;
        d /= 2;
    }
    return u;
}
 
ll lca(ll u, ll v) {
    if (d[u] < d[v]) swap(u, v);
    ll len = d[u] - d[v];
    u = up(u, len);
    if (u == v) return u;
    for (ll j = logN-1; j >= 0; --j) {
        if (binup[u][j] != binup[v][j]) {
            u = binup[u][j];
            v = binup[v][j];
        }
    }
    return binup[u][0];
}
 
int main() {
    fastIO;
    ll q;
    cin >> q;
    d.resize(n);
    binup.resize(n, vector<ll>(logN));
    while (q--) {
        string type;
        ll a, b;
        cin >> type >> a >> b;
        --a, --b;
        if (type == "ADD") {
            binup[b][0] = a;
            for (ll i = 1; i < logN; ++i) {
                binup[b][i] = binup[binup[b][i - 1]][i - 1];
            }
            d[b] = d[a] + 1;
        }
        else {
            cout << lca(a, b)+1 << el;
        }
    }
}
