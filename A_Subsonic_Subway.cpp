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

void solve() {
    int n;
    cin >> n;
    vector<pair<ld,ld>> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].ff >> v[i].ss;
    }
    ld l = -1, r = 1e7+2;
    for(int i = 1; i <= n; i++) {
        v[i-1].ff /= i;
        v[i-1].ss /= i;
        l = max(l, v[i-1].ff);
        r = min(r, v[i-1].ss);
    } 
    // dd(l);
    // dd(r);
    if(l > r) {
        cout << -1 << endl;
        return;
    }
    cout << fixed << setprecision(10);
    cout << 1/r << endl;
}

int main() {
    fastio;
    int tt = 1;
    cin >> tt;
    for (int i = 1; i <= tt; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}
