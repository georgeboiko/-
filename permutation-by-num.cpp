vector<ll>ans(n), used(n);
for (ll i = 0; i < n; ++i) {
    ll w = k / fact[n - i - 1];
    k %= fact[n - i - 1];
    ll cur = 0;
    for (ll j = 1; j <= n; ++j) {
        if (!used[j-1]) {
            ++cur;
            if (cur == w + 1) {
                ans[i] = j;
                used[j - 1] = 1;
            }
        }
    }
}
