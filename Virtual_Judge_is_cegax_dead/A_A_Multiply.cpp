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
using namespace std;

int main ( ) {
    ll n, c;
    cin >> n >> c;
    vector<ll> v(n+1);
    vector<ll> dp(n+1), dp2(n+1);
    for (int i = 0; i < n; i++) cin >> v[i];
    ll mx = v[0], mn = v[0], sum = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = max(v[i-1], dp[i-1] + v[i-1]); 
        dp2[i] = min(v[i-1], dp2[i-1] + v[i-1]); 
        mx = max(mx, dp[i]);
        mn = min(mn, dp2[i]);
        sum += v[i-1];
    }
    if (c > 0) cout << sum + max(0ll, mx * (c-1));
    else cout << sum + max(0ll, mn * (c-1)); 


}