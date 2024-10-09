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
    ll n, l;
    cin >> n >> l;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    ll tt = v[0];
    for(int i = 1; i < n; i++) {
        tt = tt * v[i] / __gcd(tt, 1ll*v[i]);
    }
    ll ans = 0;
    int mx = 0;
    ll xd = 0;
    for (int i = 1e6; i >= 1; i--) {
        xd =  tt *1ll* i / __gcd(tt, 1ll*i);
        if(xd <= l and xd >= ans) {
            ans = xd;
            mx = i;
        }

    }
    cout << mx << endl;

}

int main() {
    fastio;
    int tt = 1;
    for (int i = 1; i <= tt; i++) {
        solve();
    }
}
