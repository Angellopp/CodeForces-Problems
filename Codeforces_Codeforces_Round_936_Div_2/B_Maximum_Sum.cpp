#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define nn '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie (NULL)
#define readv(v, n) for (int i = 0; i < n; i++) cin >> v[i]
#define printv(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << nn
#define dbg(n) cout << "<[" << #n << "] = " << n << ">" << nn
ll MOD = 1e9+7;
using namespace std;

ll kadane(vector <ll>& v, int n) {
    ll curr;
    ll aux = v[0];
    ll maxx = v[0];

    for (int i = 1; i < n; i++) {
        curr = max(v[i] + aux, v[i]);
        maxx = max(curr, maxx);
        aux = curr;
    }
    return maxx;
}

int main() {
    fast_io;
    int tt = 1;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector <ll> v(n);
        readv(v, n);
        ll sum = 0;
        for (ll i : v) {
            sum += i;
        }
        sum %= MOD;
        ll max = kadane(v, n) % MOD;
        if (max > 0) {
            ll pot = 1;
            while (k--) {
                pot = pot * 2;
                pot %= MOD;
            }
            pot = (pot - 1 + MOD) % MOD;
            sum += pot * max;
            sum %= MOD;
        }
        cout << (sum + MOD) % MOD << nn;
    
    }
    return 0;
}
