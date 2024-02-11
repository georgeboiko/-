struct event {
    int x, type;
};

int scanline(vector<pair<int, int>> segments) {
    vector<event> events;
    for (auto [l, r] : segments) {
        events.push_back({l, 1});
        events.push_back({r, -1});
    }
    sort(events.begin(), events.end(), [](event a, event b) {
        return (a.x < b.x || (a.x == b.x && a.type > b.type)); 
    });
    int cnt = 0, res = 0;
    for (event e : events) {
        cnt += e.type;
        res = max(res, cnt);
    }
    return res;
}
