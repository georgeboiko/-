vector<ll>d(n, INF), p(n);
d[s] = 0;
vector<ll>used(n);
for (ll i = 0; i < n; ++i) {
    ll v = -1;
    for (ll j = 0; j < n; ++j) {
        if (used[j] == 0 && (v == -1 || d[j] < d[v])) {
            v = j;
        }
    }
    if (d[v] == INF) {
        break;
    }
    used[v] = 1;
    for (auto j : g[v]) {
        if (d[v] + j.second < d[j.first]) {
            d[j.first] = d[v] + j.second;
            p[j.first] = v;
        }
    }
}
