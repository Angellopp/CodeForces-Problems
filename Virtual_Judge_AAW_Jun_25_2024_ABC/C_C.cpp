#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
#define dbg(x) cerr << " [ " << #x << " = " << x << " ]\n"
#define endl "\n"
#define F first
#define S second
#define mk make_pair
#define rep(ini, n) for (int i = ini; i < n; i++)
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int mod = 1e8;

int main() {
    fastio;
    int n;
    cin >> n;
    vector <int> v(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        ans += 1ll * (v[i] >= mod/2) * mod/2 - 1ll * v[i];
    }
    sort(all(v));
    for (int i = 0; i < n; i++) {
        int ind = lower_bound(all(v), mod-v[i]) - v.begin();
        ans += 1ll * n * v[i] - 1ll * (n - ind) * mod/2; 
    }
    cout << ans << endl; 
}