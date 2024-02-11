ll k = 350, ans = 0;
unordered_map<ll, pair<ll,ll>>cnt;
vector<ll>a;
 
struct Query {
    ll l, r, num;
    Query() {}
    Query(ll l, ll r, ll num) : l(l), r(r), num(num) {}
};
 
bool cmp(const Query& a, const Query& b) {
    if (a.l / k == b.l / k) return a.r < b.r;
    return a.l / k < b.l / k;
}
 
void add(ll i) {
    ++cnt[a[i]].first;
    if (cnt[a[i]].first == a[i] && cnt[a[i]].second == 0) {
        ++ans;
        cnt[a[i]].second = 1;
    }
    else if (cnt[a[i]].first != a[i] && cnt[a[i]].second == 1) {
        cnt[a[i]].second = 0;
        --ans;
    }
}
 
void del(ll i) {
    --cnt[a[i]].first;
    if (cnt[a[i]].first == a[i] && cnt[a[i]].second == 0) {
        ++ans;
        cnt[a[i]].second = 1;
    }
    else if (cnt[a[i]].first != a[i] && cnt[a[i]].second == 1) {
        --ans;
        cnt[a[i]].second = 0;
    }
}
 
int main() {
    fastIO;
    ll n, q;
    cin >> n >> q;
    a.resize(n);
    for (ll& i : a) cin >> i;
    vector<Query>qr(q);
    for (ll i = 0; i < q; ++i) {
        ll l, r;
        cin >> l >> r;
        qr[i] = Query(l - 1, r - 1, i);
    }
    sort(all(qr), cmp);
    vector<ll>answ(q);
    ll l = 0, r = -1;
    for (auto& i : qr) {
        while (r < i.r) add(++r);
        while (l > i.l) add(--l);
        while (r > i.r) del(r--);
        while (l < i.l) del(l++);
        answ[i.num] = ans;
    }
    for (auto& i : answ) cout << i << el;
}
