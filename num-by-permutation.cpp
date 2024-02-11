ll ans = 0;
for (ll i = 0; i < n; ++i) {
    ll inv = 0;
    for (ll j = i+1; j < n; ++j) {
        if (a[i] > a[j]) ++inv;
    }
    ans += inv * fact[n - i - 1];
}
