struct node {
    ll x;
    node() {}
    node(ll x) : x(x) {}
};
 
vector<ll> a;
vector<node> tree;
 
const ll NEUTRAL = -INF;
 
node unite(const node& a, const node& b) {
    return node(max(a.x, b.x));
}
 
ll unite(const ll& a, const ll& b) {
    return max(a,b);
}
 
void build(ll x, ll lx, ll rx) {
    if (lx == rx - 1) {
        tree[x] = node(a[lx]);
        return;
    }
    ll m = (lx + rx) / 2;
    build(x * 2 + 1, lx, m);
    build(x * 2 + 2, m, rx);
    tree[x] = unite(tree[x * 2 + 1], tree[x * 2 + 2]);
}
 
void update(ll x, ll lx, ll rx, ll pos, ll val) {
    if (lx == rx - 1) {
        tree[x] = val;
        a[lx] = val;
        return;
    }
    ll m = (lx + rx) / 2;
    if (pos < m) update(x * 2 + 1, lx, m, pos, val);
    else update(x * 2 + 2, m, rx, pos, val);
    tree[x] = unite(tree[x * 2 + 1], tree[x * 2 + 2]);
}
 
ll ask(ll x, ll lx, ll rx, ll l, ll r) {
    if (lx >= l && rx <= r) return tree[x].x;
    if (rx <= l || lx >= r) return NEUTRAL;
    ll m = (lx + rx) / 2;
    ll q1 = ask(x * 2 + 1, lx, m, l, r);
    ll q2 = ask(x * 2 + 2, m, rx, l, r);
    return unite(q1, q2);
}
