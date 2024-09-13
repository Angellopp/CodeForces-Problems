#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define dbg(x) cerr << #x << " = " << x << endl
#define raya cerr << string(20, '=') << endl
#define pv(x) cerr << #x << ": "; for (auto e : x) cerr << e << " "; cerr << endl
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
#define ff first
#define ss second

typedef long long ll;

// const int N = 2e6 + 5;
// const int MOD = 1e9 + 7;
const int N = 1e4+5;
const int INF = 1e9;
vector <int> v(N);
vector <vector <int>> dp(N, vector<int>(N, -1));

int f(int i, int j) {
    if(i >= j) return INF;
    if(dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = min(min(f(i+1,j), f(i,j-1)), abs(v[i] - v[j]));
}

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> v[i];
    int l, r, q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> l >> r;
        l--; r--;
        cout << f(l, r) << endl;
    }
}

int main() {
    fastio;
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        solve();
    }
    return 0;
}
