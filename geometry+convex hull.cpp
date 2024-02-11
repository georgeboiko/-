const ll INF = 1e14;
const ld eps = 1e-8;
const ld PI = acos(-1.0);
 
struct point {
    ld x, y;
    point() {}
    point(ld x, ld y) : x(x), y(y) {}
};
 
istream& operator >> (istream& is, point& a) {
    return is >> a.x >> a.y;
}
 
ostream& operator << (ostream& os, const point& a) {
    return os << a.x << " " << a.y;
}
 
point operator + (point& a, point& b) {
    return point(a.x + b.x, a.y + b.y);
}
 
point operator - (point& a, point& b) {
    return point(a.x - b.x, a.y - b.y);
}
 
ld vectorProduct(const point& a, const point& b) {
    return a.x * b.y - b.x * a.y;
}
 
ld scalarProduct(const point& a, const point& b) {
    return a.x * b.x + a.y * b.y;
}
 
ld len(const point& a) {
    return a.x * a.x + a.y * a.y;
}
 
ld triangleSquare(const point& a, const point& b) {
    return abs(vectorProduct(a, b) / (ld)2);
}
 
ld getAngle(const point& a, const point& b) {
    return atan2(
        vectorProduct(a, b),
        scalarProduct(a, b)
    );
}
 
bool eq(const ld& a, const ld& b) {
    return abs(a - b) < eps;
}
 
bool cmpMin(const point& a, const point& b) {
    if (a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}
 
bool cmp(point& a, point& b) {
    if (vectorProduct(a, b) == 0) return len(a) < len(b);
    return vectorProduct(a, b) > 0;
}
 
int main() {
    freopen("hull.in", "r", stdin);
    freopen("hull.out", "w", stdout);
    fastIO;
    ll n;
    cin >> n;
    vector<point>p(n);
    for (point& i : p) cin >> i;
    point p0 = *min_element(all(p), cmpMin);
    for (ll i = 0; i < n; ++i) {
        p[i] = p[i] - p0;
    }
    sort(all(p), cmp);
    vector<point>st = { p[0], p[1] };
    for (ll i = 2; i < n; ++i) {
        while (st.size() >= 2 &&
            vectorProduct(p[i] - st[st.size() - 1], st[st.size() - 2] - st[st.size() - 1]) <= 0
        ) st.pop_back();
        st.push_back(p[i]);
    }
    cout.precision(20);
    cout << st.size() << el;
    for (point& i : st) cout << i + p0 << el;
}
