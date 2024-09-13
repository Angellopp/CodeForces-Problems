#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define endl '\n'
#define dd(x) cerr << #x << ": " << x << ".\n";

int mod = 1e9 + 7;

int mul_mod(ll a, ll b) {
    return 1ll * a * b % mod; 
}
int sum_mod(ll a, ll b) {
    return (1ll * a + b) % mod; 
}

void solve() {
    ll a, r, n;
    cin >> a >> r >> n;
    ll b, q, m;
    cin >> b >> q >> m;
    if(q % r != 0 or (abs(b-a) % r != 0) or (a > b) or (b + (m-1) * q > a + (n-1) * r)) {
        cout << 0 << endl;
        return;
    }
    if((a > b-q) or (a + (n - 1) * r < b + m * q)) {
        cout << - 1 << endl;
        return;
    }
    vector <int> num;
    ll ans = 0;
    for (int i = 1; i * i <= r; i++) {
        if(r % i) continue;
        int div = i;
        int x = r / div, y = q / r;
        if (__gcd(x, y) == 1) num.emplace_back(r / x * y);
        if (i * i != r) {
            x = i;
            if (__gcd(x, y) == 1) num.emplace_back(r / x * y);
        }
    }
    for (auto& p : num) {
        ll l = - (-q + 1 + 1ll * p - 1) / p + 1;
        ll r = (1ll * m * q - 1) / p - (1ll * (m - 1) * q + p - 1) / p + 1;
        ans = sum_mod(ans, mul_mod(l, r));
    }
    cout << ans << endl;

}


int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        solve();
    }
}