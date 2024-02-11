ll n, c = 350;
vector<ll>a;
vector<ll>decomp;
vector<ll>add;
map<ll, pair<ll,ll>>gr;
 
void build() {
    decomp = a;
    ll cnt = ceil((ld)n / (ld)c);
    ll l = 0, r = min(n, l + c);
    for (ll i = 0; i < cnt; ++i) {
        sort(decomp.begin() + l, decomp.begin() + r);
        gr[i] = { l, r };
        l += c;
        r = min(l + c, n);
    }
}
 
ll ask(ll l, ll r, ll x) {
    ll ans = 0;
    while (l < r) {
        if (l % c == 0 && l + c - 1 < r) {
            auto pos = decomp.end();
            if (l + c <= n) pos = decomp.begin() + l + c;
            ans += lower_bound(decomp.begin()+l, pos, x - add[l/c]) - (decomp.begin() + l);
            l += c;
        }
        else {
            if (a[l]+add[l/c] < x) ++ans;
            ++l;
        }
    }
    return ans;
}
 
void update(ll l, ll r, ll x) {
    set<ll>upd;
    while (l < r) {
        if (l % c == 0 && l + c - 1 < r) {
            add[l / c] += x;
            l += c;
        }
        else {
            a[l] += x;
            upd.insert(l / c);
            ++l;
        }
    }
    for (auto& block : upd) {
        vector<ll>temp;
        for (ll i = gr[block].first; i < gr[block].second; ++i) {
            temp.push_back(a[i]);
        }
        sort(all(temp));
        for (ll i = gr[block].first; i < gr[block].second; ++i) {
            decomp[i] = temp[i - gr[block].first];
        }
    }
}
 
int main() {
    fastIO;
    ll m;
    cin >> n >> m;
    a.resize(n);
    add.resize(n);
    for (ll& i : a) cin >> i;
    build();
    while (m--) {
        ll cmd, l, r, x;
        cin >> cmd >> l >> r >> x;
        if (cmd == 1) {
            cout << ask(l - 1, r, x) << el;
        }
        else {
            update(l - 1, r, x);
        }
    }
}
