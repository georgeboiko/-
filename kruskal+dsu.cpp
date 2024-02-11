vector<ll>p, sz;

void init(ll n) {
  sz.resize(n, 1);
  p.resize(n);
  iota(all(p), 0);
}

ll getRoot(ll i) {
  if (p[i] == i) return i;
  return p[i] = getRoot(p[i]);
}

void merge(ll i, ll j) {
  i = getRoot(i);
  j = getRoot(j);
  if (i == j) return;
  if (sz[i] > sz[j]) swap(i, j);
  p[i] = j;
  sz[j] += sz[i];
}

struct Edge {
  ll from, to, w;
  Edge() {}
  Edge(ll from, ll to, ll w) : from(from), to(to), w(w) {}
};

bool cmp(const Edge& a, const Edge& b) {
  return a.w < b.w;
}

int main() {
  fastIO;
  ll n, m;
  cin >> n >> m;
  init(n);
  vector<Edge>e;
  for (ll i = 0; i < m; ++i) {
    ll u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    e.push_back(Edge(u, v, w));
  }
  sort(all(e), cmp);
  ll ans = 0;
  for (auto& ed : e) {
    if (getRoot(ed.from) != getRoot(ed.to)) {
      merge(ed.from, ed.to);
      ans += ed.w;
    }
  }
  cout << ans << el;
}
