vector<vector<ll>>gr(n, vector<ll>(n, INF));
for (ll i = 0; i < n; ++i) gr[i][i] = 0;
for (ll i = 0; i < m; ++i) {
    ll u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    gr[u][v] = min(gr[u][v],w);
}
for (ll k = 0; k < n; ++k) {
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            if (gr[i][k] != INF && gr[k][j] != INF) gr[i][j] = min(gr[i][j], gr[i][k] + gr[k][j]);
        }
    }
}
