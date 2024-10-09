#include <bits/stdc++.h>
#define endl '\n'
#define dd(x) cerr << #x << "= " << x << "." << endl;
#define ddl cerr << string(20, '=') << endl;
#define ll long long
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
using namespace std;

// const int N = 2e5 + 5;
const int MOD = 998244353;

// int fact[N];


int mul_mod(int a, int b) {
    return 1ll * a * b % MOD;
}
int sum_mod(int a, int b) {
    return (1ll * a + 1ll*b) % MOD;
}

int pow_mod(int a, int e) {
    int r = 1;
    while(e) {
        if (e & 1) r = mul_mod(r, a);
        a = mul_mod(a, a);
        e >>= 1;
    }
    return r;
}

int inv_mod(int a) { 
    return pow_mod(a, MOD - 2);
}
void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<ll> pre(n+1, 0);
    int sum_ini = 0;
    // vector<int> (n);
    int ans = 0;
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(all(v));
    for (int i = 1; i < n; i++) {
        sum_ini = sum_mod(sum_ini, mul_mod(v[i], pow_mod(2,i-1)));
        dd(sum_ini);
    }
    for (int i = 0; i+1 < n; i++) {
        dd(sum_ini);
        ans = sum_mod(ans, mul_mod(v[i], sum_ini));
        int xd = ((sum_ini - v[i+1] % MOD) + MOD) % MOD;
        sum_ini = mul_mod(xd, inv_mod(2));
    }
    for (int i = 0; i < n; i++) {
        ans = sum_mod(ans, mul_mod(v[i],v[i]));
    }cout << ans << endl;
}

int main() {
    fastio;
    int tt = 1;
    // cin >> tt;
    // tt =1;
    while(tt--) {
        solve();
    }
}