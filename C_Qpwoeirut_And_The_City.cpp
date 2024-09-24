#include <bits/stdc++.h>
#define endl '\n'
#define dd(x) cerr << #x << "= " << x << "." << endl;
#define ll long long
#define ff first
#define ss second
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
using namespace std;


void solve() {
    int n;
    cin >> n;
    vector<ll> v(n), pre(n), suf(n);
    for(int i = 0; i < n ;i++) cin >> v[i];
    if(n %2) {
        ll ans = 0;
        for(int i = 1; i < n-1; i+=2) {
           ans += max(0ll, max(v[i-1], v[i+1])+1 - v[i]);
        }
        cout << ans << endl;
        return;
    }
    for(int i = 1; i < n-1; i+=2) {
        pre[i/2+1] = pre[i/2] + max(0ll, -v[i] + max(v[i-1], v[i+1])+1);
    }
    for(int i = n-2; i >= 2; i-=2) {
        suf[(n-1-i)/2+1] = suf[(n-1-i)/2] + max(0ll, -v[i] + max(v[i-1], v[i+1])+1);
    }
    ll ans = 2e18;
    for(int i = 0; i < n/2; i++) {
        ans = min(ans, 1ll * pre[i] + suf[n/2-1-i]);
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

