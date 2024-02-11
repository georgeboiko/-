vector<vector<pair<ll, ll>>> g;
vector<ll> dijkstra(ll s) {
vector<ll>d(n, INF), p(n);
d[s] = 0;
priority_queue<pair<ll,ll>>q;
q.push({ 0, s });
while (!q.empty()) {
    ll v = q.top().second, cur_d = -q.top().first;
    q.pop();
    if (cur_d > d[v]) {
        continue;
    }
    for (auto j : g[v]) {
        if (d[v] + j.second < d[j.first]) {
            d[j.first] = d[v] + j.second;
            p[j.first] = v;
            q.push({ -d[j.first], j.first });
        }
    }
}
