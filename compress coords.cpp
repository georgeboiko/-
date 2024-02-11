vector<ll> b = a;
sort(b.begin(), b.end());
b.erase(unique(b.begin(), b.end()), b.end());
for (ll &x : a){
    x = ll(lower_bound(b.begin(), b.end(), x) - b.begin());
}
