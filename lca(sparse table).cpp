int n;
vector<int>colors, d, euler;
vector<pair<int, int>>a;
vector<vector<int>>gr;
vector<vector<pair<int,int>>>sparse;
 
void build() {
    int logN = ceil(log2(n)) + 1;
    sparse.resize(logN, vector<pair<int,int>>(n));
    for (int i = 0; i < logN; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0) sparse[i][j] = a[j];
            else {
                if (j + (1 << (i - 1)) >= n) sparse[i][j] = sparse[i - 1][j];
                else {
                    if (sparse[i - 1][j].first < sparse[i - 1][j + (1 << (i - 1))].first) {
                        sparse[i][j] = sparse[i - 1][j];
                    }
                    else sparse[i][j] = sparse[i - 1][j + (1 << (i - 1))];
                }
            }
        }
    }
}
 
pair<int,int> ask(int l, int r) {
    if (l > r) swap(l, r);
    int k = log2(r - l + 1);
    if (sparse[k][l].first < sparse[k][r - (1 << k) + 1].first) {
        return sparse[k][l];
    }
    return sparse[k][r - (1 << k) + 1];
}
 
void dfs(int u, int prev) {
    euler.push_back(u);
    d[u] = d[prev] + 1;
    colors[u] = 1;
    for (auto& v : gr[u]) {
        if (colors[v] == 0) {
            dfs(v, u);
            euler.push_back(u);
        }
    }
    colors[u] = 2;
}
 
int main() {
    fastIO;
    int q, m;
    cin >> q >> m;
    gr.resize(q);
    colors.resize(q);
    d.resize(q);
    for (int i = 1; i < q; ++i) {
        int p;
        cin >> p;
        gr[i].push_back(p);
        gr[p].push_back(i);
    }
    d[0] = -1;
    dfs(0, 0);
}
