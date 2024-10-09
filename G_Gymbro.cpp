#include <bits/stdc++.h>
#define endl '\n'
#define dd(x) cerr << #x << "= " << x << "." << endl;
#define ddl cerr << string(20, '=') << endl;
#define ll long long
#define ld long double
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
using namespace std;
const int MOD = 1e9+7; 

int sum_mod(int a, int b) {
    return (1ll * a + 1ll *  b) % MOD;
}

void solve() {
    int t, m, n;
    cin >> t >> m >> n;
    int dif = n - m + 1;
    vector<vector<int>> v(dif, vector<int> (t, 1));
    for (int j = 1; j < t; j++) {
        v[0][j] = v[1][j-1];
        for(int i = 1; i+1 < dif; i++) {
            v[i][j] = sum_mod(v[i-1][j-1], v[i+1][j-1]); 
        }
        v[dif-1][j] = v[dif-2][j-1];
    }
    // for(int i = 0; i < n; )
    int ans = 0;
    for(int i = 0; i < dif; i++) {
        ans = sum_mod(v[i][t-1], ans); 
    }
    cout << ans << endl;


}

int main() {
    fastio;
    int tt = 1;
    for (int i = 1; i <= tt; i++) {
        solve();
    }
}
