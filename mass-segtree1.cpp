struct node {
    ll elem, psh = 0;
    node() {}
    node(ll elem_) {
        elem = elem_;
        psh = 0;
    }
};
const node NEUTRAL = node(-INF);
 
node unite(const node& a, const node& b) {
    return node(max(a.elem, b.elem));
}
 
vector<ll> a;
vector<node> tree;
 
void push(ll x, ll lx, ll rx) {
    if (lx == rx - 1) return;
    ll m = (lx + rx) / 2;
    tree[x * 2 + 1].elem += tree[x].psh;
    tree[x * 2 + 1].psh += tree[x].psh;
    tree[x * 2 + 2].elem += tree[x].psh;
    tree[x * 2 + 2].psh += tree[x].psh;
    tree[x].psh = 0;
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
 
void update(ll x, ll lx, ll rx, ll l, ll r, ll val) {
    if (lx >= l && rx <= r) {
        tree[x].elem += val;
        tree[x].psh += val;
        return;
    }
    if (rx <= l || lx >= r) return;
    push(x, lx, rx);
    ll m = (lx + rx) / 2;
    update(x * 2 + 1, lx, m, l, r, val);
    update(x * 2 + 2, m, rx, l, r, val);
    tree[x] = unite(tree[x * 2 + 1], tree[x * 2 + 2]);
}
 
node ask(ll x, ll lx, ll rx, ll l, ll r) {
    if (lx >= l && rx <= r) return tree[x];
    if (rx <= l || lx >= r) return NEUTRAL;
    push(x, lx, rx);
    ll m = (lx + rx) / 2;
    node q1 = ask(x * 2 + 1, lx, m, l, r);
    node q2 = ask(x * 2 + 2, m, rx, l, r);
    return unite(q1, q2);
}
