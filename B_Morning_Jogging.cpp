#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
#define dbg(x) cerr << " [ " << #x << " = " << x << " ]\n"
#define cp(x) cerr << " [ " << #x << " = (" << x.F << ", " << x.S << ") ]\n"
#define endl "\n"
#define F first
#define S second
#define mk make_pair
#define rep(ini, n) for (int i = ini; i < n; i++)
#define all(x) x.begin(), x.end()
#define ll long long 
#define clz(x) __builtin_clz(x) 
#define ctz(x) __builtin_ctz(x) 

using namespace std;


int n, m;

void solve() {
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int> (m));
    map <int, int> mp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
            mp[v[i][j]]++;
        }
        sort(all(v[i]));
    }
    int cnt = m;
    for (auto& x : mp) {
        int xd = min(cnt, x.S);
        cnt -= xd;
        x.S = xd;
    }
    int acc = 0, xd = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(mp[v[i][j]] <= 0) break;
            mp[v[i][j]]--;
            xd++;
        }
        dbg(xd);
        for (int j = m-acc; j < m; j++) cout << v[i][j] << " ";
        for (int j = 0; j < m-acc; j++) cout << v[i][j] << " ";
        acc = xd;
        cout << endl;
    }
}
int main() {
    fastio;
    int q;
    cout << fixed << setprecision(10);
    cin >> q;
    while(q--) {
        solve();
    }
    return 0;
}
