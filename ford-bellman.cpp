vector<edge>e;
for (ll i = 0; i < m; ++i) {
    ll u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    e.push_back(edge(u, v, w));
}
vector<ll>d(n, INF);
d[0] = 0;
for (ll i = 0; i < n - 1; ++i) {
    for (ll j = 0; j < m; ++j) {
        if (d[e[j].from] != INF) d[e[j].to] = min(d[e[j].to], d[e[j].from] + e[j].w);
    }
}
