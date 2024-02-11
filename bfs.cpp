vector<ll>d(n, INF), p(n, -1);
d[start] = 0;
queue<ll>q;
q.push(start);
while (!q.empty()) {
    ll u = q.front();
    q.pop();
    for (auto& v : gr[u]) {
        if (d[v] > d[u] + 1) {
            d[v] = d[u] + 1;
            p[v] = u;
            q.push(v);
        }
    }
}
ll cur = n-1;
vector<ll>ans;
while (cur != -1) {
    ans.push_back(cur);
    cur = p[cur];
}
reverse(all(ans));
