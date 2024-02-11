ll get(ll x) {
    ll ans = 0;
    for (ll i = x; i >= 0; i = ((i + 1) & i) - 1) ans += f[i];
    return ans;
}
 
ll ask(ll l, ll r) {
    return get(r) - get(l - 1);
}
 
void update(ll pos, ll val) {
    ll d = val - a[pos];
    a[pos] = val;
    for (ll i = pos; i < n; i = (i + 1) | i) f[i] += d;
}
