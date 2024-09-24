#include <bits/stdc++.h>
#define endl '\n'
#define dd(x) cerr << #x << "= " << x << "." << endl;
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
using namespace std;

void solve() {

    int n; cin >> n;
    vector <int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(all(v));
    if(n <= 3) {
        cout << 0 << endl; return;
    }
    // for(auto&e:v) cout << e << " "; cout << endl;     
    int ans = 2e9+10;

    for (int i = 0; i+1 < n; i++) {
        // [0, i];
        int se = (v[i] - v[0] + 1) / 2;
        int ni = lower_bound(v.begin()+i+1, v.end(), (v[i+1] + v[n-1]) / 2) - v.begin();
        // [i+1, ni-1]
        se = max(se, (v[max(ni-1, i+1)] - v[i+1] + 1) / 2);
        // [ni, n-1]
        se = max(se, (v[n-1] - v[max(ni-1, i+1)+1] + 1) / 2);
        ans = min(ans, se);
        int ni2 = lower_bound(v.begin()+i+1, v.end(), (v[i+1] + v[n-1]) / 2 + 1) - v.begin();
        int se2 = (v[i] - v[0] + 1) / 2;
        se2 = max(se2, (v[max(ni2-1, i+1)] - v[i+1] + 1) / 2);
        se2 = max(se2, (v[n-1] - v[max(ni2-1, i+1)+1] + 1) / 2);
        ans = min(ans, se2);
        
        dd(i);
        dd(ans);
    }
    cout << ans << endl;
}


int main() {
    fastio;
    int tt;
    cin >> tt;
    while(tt--) {
        solve();
    }
}

