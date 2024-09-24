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
const int INF = 1e9;



void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    ll sum = 0;
    for (ll i = 0; i < n; i++) {
        cin >> v[i], sum += v[i];
    }
    sort(all(v));
    ll m = n/2;
    ll q = v[m];
    ll ans =(1ll * q * 2) * n - sum +1;
    if(n <= 2) {
        cout << -1 << endl;
        return;
    }
    if(ans < 0) {
        cout << 0 << endl;
        return;
    } 
    cout << ans << endl;
}


int main() {
    fastio;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve();
    }
}

