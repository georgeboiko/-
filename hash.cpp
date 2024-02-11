struct Hash {
    string s;
    vector<ll>pows, h;
    const int p = 239017;
    Hash() {}
    Hash(const string& _s) {
        s = _s;
        pows.resize(s.size()+1);
        h.resize(s.size() + 1);
        h[0] = 0, pows[0] = 1;
        for (int i = 0; i < s.size(); ++i) {
            h[i + 1] = h[i] * p + s[i];
            pows[i + 1] = pows[i] * p;
        }
    }
    ll getHash(ll l, ll r) {
        return h[r+1] - h[l] * pows[r - l + 1];
    }
};
