#include <bits/stdc++.h>
#define endl '\n'
#define dd(x) cerr << #x << "= " << x << "." << endl;
#define ll long long
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
using namespace std;

const int N = 1000 + 5;

int FT[N][N];

void update(int i, int j, int x) {
    for (; i < N; i += i & -i) {
        for (int jj = j; jj < N; jj += jj & -jj) {
            FT[i][jj] += x;
        }
    }
}
int sum(int i, int j) {
    int sa = 0;
    for (; i; i -= i & -i) {
        for (int jj = j; jj; jj -= jj & -jj) {
            sa += FT[i][jj];
        }
    }
    return sa;
}
int qq(int i1, int j1, int i2, int j2) {
    return sum(i2, j2) - sum(i2, j1 - 1) - sum(i1 - 1, j2) + sum(i1 - 1, j1 - 1);
}

void solve() {
    int n;
    cin >> n;
    vector<vector<pair<int,int>>> v(n+1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int aux; cin >> aux; v[aux].emplace_back(i+1, j+1);
        }
    }

    int q;
    cin >> q;
    vector<int> ans(q);
    vector <vector<vector<int>>> query(n+1);
    for (int i = 0; i < q; i++) {
        vector <int> xd(5); int idx;
        cin >> xd[1] >> xd[2] >> xd[3] >> xd[4] >> idx;
        xd[0] = i;
        query[idx].emplace_back(xd);
    }

    for (int i = 1; i <= n; i++) {
        for(auto &[i, j] : v[i]) update(i, j, 1);
        for(auto &q : query[i]) ans[q[0]] = qq(q[1], q[2], q[3], q[4]);
        for(auto &[i, j] : v[i]) update(i, j, -1);
    }
    for (int i = 0; i < q; i++) cout << ans[i] << endl;
}


int main() {
    fastio;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        solve();
    }
}

